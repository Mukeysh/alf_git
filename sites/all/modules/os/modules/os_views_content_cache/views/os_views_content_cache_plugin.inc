<?php
// $Id: os_performance_plugin_cache.inc

/**
 * Simple caching of query results for Views displays in OpenScholar sites.
 */
class os_views_content_cache_plugin extends views_content_cache_plugin_cache {
  
	//Set the max amount if time we let expired data hang out in the cache
	protected $max_output_lifetime = 86400; //1 day
	
	function option_defaults(&$options) {
    $options['results_min_lifespan'] = 0; //Clear Anytime
    $options['results_max_lifespan'] = 0; //Forever
    $options['output_min_lifespan'] = 0; //Clear Anytime
    $options['output_max_lifespan'] = 3600; //One Hour
    $options['keys'] = array();
  }

  function summary_title() {
    return "OpenScholar Content cache";
  }
  
  function get_results_key() {
    global $user;

    if (!isset($this->_results_key)) {

      // This is a fix for the build info not including the actual query run:
      $execute_info = $this->view->build_info;

      $execute_info['query'] = db_rewrite_sql($execute_info['query'], $this->view->base_table, $this->view->base_field, array('view' => &$this->view));
      $execute_info['count_query'] = db_rewrite_sql($execute_info['count_query'], $this->view->base_table, $this->view->base_field, array('view' => &$this->view));
      $replacements = module_invoke_all('views_query_substitutions', $this->view);
      $execute_info['query'] = str_replace(array_keys($replacements), $replacements, $execute_info['query']);
      $execute_info['count_query'] = 'SELECT COUNT(*) FROM (' . str_replace(array_keys($replacements), $replacements, $execute_info['count_query']) . ') count_alias';
      // End generating the execution info.

      $key_data = array(
        'execute_info' => $execute_info,
        'roles' => array_keys($user->roles),
        'super-user' => $user->uid == 1, // special caching for super user.
        'language' => $GLOBALS['language'],
      );
      
      if(isset($this->view->pager)){
      	$key_data['pager_info'] = $this->view->pager; //items per page etc in case this is changed progrmatically/on the fly
      }
      
      foreach (array('exposed_info', 'page', 'sort', 'order') as $key) {
        if (isset($_GET[$key])) {
          $key_data[$key] = $_GET[$key];
        }
      }
      
      //Include the Current Site in the Key if there is one:
      $vsite = vsite_get_vsite();
      $s_site = ($vsite && $vsite->group->purl)? $vsite->group->purl.":":"";
      $execute_key = md5(serialize($key_data));
      
      $this->view->_os_results_key = $execute_key;
      $this->_results_key = $s_site . $this->view->name . ':' . $this->display->id . ':results:' . $execute_key;
    }

    return $this->_results_key;
  }
  

  function get_output_key() {
    global $user;
    if (!isset($this->_output_key)) {
    	
      $key_data = array(
        'result' => $this->view->result,
        'result_key' => $this->view->_os_results_key, //In case the results are same but the params change the look
        'roles' => array_keys($user->roles),
        'super-user' => $user->uid == 1, // special caching for super user.
        'theme' => $GLOBALS['theme'],
        'language' => $GLOBALS['language'],
      );
      
	    if(module_exists('vsite_contextual')){
	      //Get the avalible admin links for this block
	      $admin_links = vsite_contextual_get_admin_links('view',$this->view);
	      
	      //Create a key based on the admin links returned
	      $key_data['admin_links'] = serialize($admin_links);
	    }

      //Include the Current Site in the Key if there is one:
      $vsite = vsite_get_vsite();
      $s_site = ($vsite && $vsite->group->purl)? $vsite->group->purl.":":"";
      
      $this->_output_key = $s_site . $this->view->name . ':' . $this->display->id . ':output:' . md5(serialize($key_data));
    }

    return $this->_output_key;
  }
  
  /**
   * Override of saving data to the cache.
   *
   * Since the output key is based on the result set, we should set a logical expire time here
   */
  function cache_set($type) {
    switch ($type) {
      case 'output':
        $this->gather_headers();
        $this->storage['output'] = $this->view->display_handler->output;
        cache_set($this->get_output_key(), $this->storage, $this->table, (time() + $this->max_output_lifetime));
      break;
      default:
      	parent::cache_set($type);
      break;
    }
  }
}
