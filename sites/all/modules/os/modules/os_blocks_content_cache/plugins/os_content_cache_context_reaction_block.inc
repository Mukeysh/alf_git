<?php

/**
 * Cache blocks based on content changes
 */
class os_content_cache_context_reaction_block extends vsite_context_reaction_block {
	
	protected $cache_default_min_lifespan = -1;
	protected $cache_default_max_lifespan = 43200; //12 Hours

  /**
   * Build a block's content. Largely taken from block_list().
   */
  protected function build_block($block, $reset = FALSE) {
    // We preserve the submission of forms in blocks, by fetching from cache
    // only if the request method is 'GET'.
    $cacheable = $_SERVER['REQUEST_METHOD'] == 'GET' && ($cache_config = $this->get_cache_config($block));
    
    if (!isset($block->content)) {
      $block->content = '';
      // Try fetching the block from cache.
      if ($cacheable && ($cid = $this->get_cache_id($block, $cache_config['granularity']))) {
      	$cutoff = $this->cache_expire($cache_config);
        if (($cache = cache_get($cid, 'cache_block')) && (!$cutoff || $cache->created > $cutoff)) {
          //$cache->data['content'] = "{{CACHED}}".$cache->data['content'];
        	$array = $cache->data;
        }
        else {
          $array = module_invoke($block->module, 'block', 'view', $block->delta);
          $garbage_collection = (intval($cache_config['max_lifespan']) > 2)?$cache_config['max_lifespan']:86400; //Kep in cache max of one day
          cache_set($cid, $array, 'cache_block', time() + $garbage_collection);
        }
      }
      // Otherwise build block.
      else {
        $array = module_invoke($block->module, 'block', 'view', $block->delta);
      }
      if (isset($array) && is_array($array)) {
        foreach ($array as $k => $v) {
          $block->$k = $v;
        }
      }
    }
    if (!empty($block->content)) {
      // Only query for custom block title if block core compatibility is enabled.
      if (!variable_get('context_reaction_block_disable_core', FALSE)) {
        global $user, $theme_key;
        $block->title = db_result(db_query("SELECT title FROM {blocks} WHERE module = '%s' AND delta = '%s' AND theme = '%s'", $block->module, $block->delta, $theme_key));
      }
      // Override default block title if a custom display title is present.
      if (!empty($block->title)) {
        // Check plain here to allow module generated titles to keep any markup.
        $block->subject = $block->title == '<none>' ? '' : check_plain($block->title);
      }
      if (!isset($block->subject)) {
        $block->subject = '';
      }
    }
    return $block;
  }
  
  protected function get_cache_id($block, $additional_granularity = array()){
  	global $theme, $base_root, $user;
  	
    $cid_parts = array();
    
    $vsite = vsite_get_vsite();
    $cid_parts[] = (isset($vsite->group->purl))? $vsite->group->purl:"";

    //common sub-patterns: block identification, theme, language.
    $cid_parts[] = $block->module;
    $cid_parts[] = $block->delta;
    $cid_parts[] = $theme;
    $cid_parts[] = ($user->uid == 1)?1:0; // special caching for admin user.
    
    if(module_exists('vsite_contextual')){
    	//Get the avalible admin links for this block
    	$admin_links = vsite_contextual_get_admin_links('block',$block);
    	
    	//Create a key based on the admin links returned
    	$cid_parts[] = count($admin_links)?md5(serialize($admin_links)):0;
    }
    
    if (module_exists('locale')) {
      global $language;
      $cid_parts[] = $language->language;
    }
    
    foreach ($additional_granularity as $key) {
    	switch ($key){
    		case 'page':
    		  $cid_parts[] = $key."|".$_GET['q'];
    		break;
    		case 'context':
    			$active_feature = vsite_active_feature();
          $cid_parts[] = $key."|".$active_feature;
        break;
    	}
    }
    
  	return implode(':', $cid_parts);
  }
  
  protected function cache_expire($cache_config){
  	$cutoff = 0;

    // Retrieve the latest update time matching the settings on this View.
    $cid = array();
    foreach ($cache_config['keys'] as $key_id => $key_values) {
      if ($plugin = views_content_cache_get_plugin($key_id)) {
        $cid[$key_id] = $plugin->view_key($key_values);
      }
    }
    if (!empty($cid) && $timestamp = views_content_cache_update_get($cid)) {
      $cutoff = $timestamp;
    }

    // If there's a minimum lifetime, enforce it:
    if ($cache_config['min_lifespan'] && $cache_config['min_lifespan'] != -1) {
      $min_lifespan = time() - $cache_config['min_lifespan'];
      $cutoff = min($min_lifespan, $cutoff);
    }

    // Only enforce a maximum lifetime if it's been specifically selected:
    if ($cache_config['max_lifespan']) {
      if ($cache_config['max_lifespan'] != -1) {
        $max_lifespan = time() - $cache_config['max_lifespan'];
        $cutoff = max($max_lifespan, $cutoff);
      }
    }
    
    return $cutoff;
  }
  
  protected function get_cache_config($block){
  	
  	switch ($block->module){
  		case "boxes":
  			//Handle Boxes Cache
  	    $box = boxes_load($block->delta);
        if($box && method_exists($box,'cache_info')){
        	$a_config = $box->cache_info();
        	if(is_array($a_config) && $a_config['type'] == BLOCK_CACHE_CONTENT_CACHE){
        	  //Set Defaults
        	  $a_config += array(
        	    'min_lifespan' => $this->cache_default_min_lifespan,
        	    'max_lifespan' => $this->cache_default_max_lifespan,
        	    'granularity' => array(),
        	  );
        	  
        	  //If the box has been saved don't hold a cache older than that
        	  if(isset($box->changed) && (time() - $box->changed) < $a_config['max_lifespan']){
        	  	$a_config['max_lifespan'] = time() - $box->changed;
        	  }
        	  
	          return $a_config;
        	}
        }
  	  break;
  		default:
  			static $vsite_widgets;
  			if(!isset($vsite_widgets)) $vsite_widgets = vsite_layout_get_widgets();
  			
  			$bid = isset($block->bid)? $block->bid:$block->module."-".$block->delta;
  			$block_info = (object) ((array_key_exists($bid ,$vsite_widgets))? $vsite_widgets[$bid]:array());
  			
  	    if($block_info->cache == BLOCK_CACHE_CONTENT_CACHE && isset($block_info->cache_keys)){
  	    	$a_config = array('keys' => $block_info->cache_keys);
  	    	$a_config['min_lifespan'] = isset($block_info->cache_min_lifespan)?intval($block_info->cache_min_lifespan):$this->cache_default_min_lifespan;
  	    	$a_config['max_lifespan'] = isset($block_info->cache_max_lifespan)?intval($block_info->cache_max_lifespan):$this->cache_default_max_lifespan;
  	    	$a_config['granularity'] = isset($block_info->cache_granularity)?$block_info->cache_granularity:array();
  	    	return $a_config;
  	    }
  		break;
  	}
  	
  	return false;
  }
}
