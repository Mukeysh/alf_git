<?php

/**
 * @file
 * Extends "Simpleview" list to include os caching params that simpleviews should not care about.
 */

class os_boxes_simpleview_list extends spaces_simpleviews_post_list {
  
  /*
   * Define the default region for this box.
   */
  public $region;
  
  /*
   * If this box has been overridden the changed timestamp will be held here
   */
  public $changed;
  
  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    
  	//Get the regular options form
    $form = parent::options_form();
    
    $valid_types = $this->filter_disabled_types(array_keys($form['filter']['#options']));
    
    //Remove form items for disabled features
    $form['filter']['#options'] = array_intersect_key($form['filter']['#options'],array_flip($valid_types));

    return $form;
  }
  
  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    $block = array();
    
  	if($this->options['filter'] && !$this->filter_disabled_types($this->options['filter'])){
  		return $block;
  	}

    return parent::render();
  }
  
  /**
   * Return the cache parameters for this box
   */
  public function cache_info(){
    
    //Clear when og is saved
    $cache_key = array(
      'os_og' => array('current' => 'current'),
    );
    
    //Restrict based on simpleview filters for node clears
    $filter = $this->options['filter'];
    if (strstr($filter, 'node') !== FALSE && $type = end(explode(':', $filter))) {
      $cache_key['node'] = array($type => $type);
    }
    
    return array('type' => BLOCK_CACHE_CONTENT_CACHE, 'keys' => $cache_key);
  }
  
  /**
   * Does this box only use node types that have been disabled?
   */
  public function access(){
    if($this->options['filter'] && !$this->filter_disabled_types($this->options['filter'])){
      return false;
    }else{
    	return true;
    }
  }
  
  /**
   * Either one type or an array of types to validate
   * @param mixed $a_types
   */
  protected function filter_disabled_types($a_types){
  	vsite_include('vsiteapi');
  	$avalible_types = array_keys(vsite_content_types(array(2, 1)));
  	
  	if(!is_array($a_types) && is_string($a_types)){
  		//Check and see if the passed type is valid
  	  list($type,$name) = explode(":",$a_types);
      if($type == "node" && !in_array($name,$avalible_types)){
        return false;
      }
  		return $a_types;
  		
  	}elseif (is_array($a_types)) {
  	  //Remove types that are not valid
	    foreach ($a_types as $type_key) {
	      list($type,$name) = explode(":",$type_key);
	      if($type == "node" && !in_array($name,$avalible_types)){
	        unset($a_types[$type_key]);
	      }
	    }
  	}
    
    return $a_types;
  }
  
}