<?php

/**
 * Context controller.
 */
class spaces_controller_vsite_menu extends spaces_controller {
  
  /**
   * Split the single vsite_menu object into array of individual plugin values.
   */
  protected function plugin_values($menu_links) {

    //$plugins['menu_name']
    $plugins = array();
    
    //Assign to Menus
    foreach ($menu_links as $key => $link) {
    	$plugins[$link['menu_name']][$key] = $link;
    }
    
    //Sort By Weight
    foreach ($plugins as $s_menu => $a_links) {
    	uasort($plugins[$s_menu], array($this, 'sort_menulink_by_weight'));
    }
    
    return $plugins;
  }

  /**
   * Override of load_space_values().
   *
   * All overrides are retrieved at once for a given space to reduce the number
   * of queries run when a space is active.
   */
  protected function load_space_values($id = NULL) {
    if (!$this->loaded_all['space']) {
      $result = db_query("
        SELECT object_id AS id, value
        FROM {spaces_overrides}
        WHERE type = '%s'
          AND id = '%s'
          AND object_type = '%s'",
        $this->space_type, $this->space_id, $this->controller);
      while ($row = db_fetch_object($result)) {
        $this->values['space'][$row->id] = unserialize($row->value);
      }
      
      //Look at the Defaults to make sure there is nothing to add
      $this->add_missing_defaults($this->values['space']);
      
      $this->loaded_all['space'] = TRUE;
    }
  }
  
  /**
   * Override of load_preset_values().
   *
   * All overrides are retrieved at once for a given space to reduce the number
   * of queries run when a space is active.
   */
  protected function load_preset_values($id = NULL) {
    if (!$this->loaded_all['preset']) {
    	parent::load_preset_values($id);
    	
    	/**
    	 * If a feature list exists in the preset setup the default menu item
    	 * order so that it mirrors the order of the features listed
    	 */
      $preset_name = variable_get("spaces_preset_{$this->space_type}", NULL);
      if ($preset_name && $preset = spaces_preset_load($preset_name)) {
      	
        if (isset($preset->value['variable']) && isset($preset->value['variable']['spaces_features'])) {
        	$order = array_flip(array_keys($preset->value['variable']['spaces_features']));
          $feature_menus = features_get_component_map('menu_links');
          
          foreach ($feature_menus as $s_key => $a_feature) {
	          if(!isset($order[current($a_feature)])) continue;
	        	
	          $n_weight = $order[current($a_feature)] - count($order);
	        	list($menu,$path) = split(":",$s_key,2);
	          if(isset($this->values['preset'][$menu][$s_key])){
	            $this->values['preset'][$menu][$s_key]['weight'] = $n_weight;
	          }elseif (isset($this->values['original'][$menu][$s_key])){
	            $this->values['original'][$menu][$s_key]['weight'] = $n_weight;
	          }
	        }
        }
      }
    	
    	$this->add_missing_defaults($this->values['preset']);
    }
  }

  /**
   * Add in menu links that are in the default but not in the passed array
   *
   * @param array $menu_settings
   * @param boolean $as_hidden
   */
  protected function add_missing_defaults(&$menu_settings, $as_hidden = false){
  	if(!$this->loaded_all['original']) return false;
  	
  	//Look at the Defaults to make sure there is nothing to add
    foreach ($this->values['original'] as $s_menu => $a_menu_links) {
      if(!isset($menu_settings[$s_menu])) continue;
        
      foreach ($a_menu_links as $s_link_key => $a_default_link) {
        if(!isset($menu_settings[$s_menu][$s_link_key])){
        	if($as_hidden) $a_default_link['hidden'] = 1;
          $menu_settings[$s_menu][$s_link_key] = $a_default_link;
        }
      }
    }
  }
  
  /**
   * Override of load_original_values().
   *
   * Note that $id here is menu name, but all menus will be loaded
   */
  protected function load_original_values($id = NULL) {
    if (empty($this->loaded_all['original'])) {
    	
      //Ignore ID and load them all at once to prevent multiple unneeded queries
      module_load_include('inc', 'features', 'features.export');
      $a_menu_links = features_get_default('menu_links');
      
      $this->values['original'] = $this->plugin_values($a_menu_links);
      $this->loaded_all['original'] = TRUE;
    }
  }
  
  /**
   * Override to the wrapper around load_[environment]_values.
   */
  protected function load_values($environment = NULL, $id = NULL) {
    //Load orig first since preset and space depend on it
    $this->load_original_values();
    
    switch ($environment) {
      case 'original':
        break;
      case 'preset':
        $this->load_preset_values($id);
        break;
      case 'space':
        $this->load_space_values($id);
        break;
      default:
        $this->load_preset_values();
        $this->load_space_values();
        break;
    }
  }
  
	/**
	* Custom sort by menu link weight
	*/
	protected function sort_menulink_by_weight($a, $b) {
		$a = (array)$a;
		$b = (array)$b;
		
		if ($a['weight'] == $b['weight']) return 0;
		
		return ($a['weight'] < $b['weight']) ? -1 : 1;
	}
	
  /**
   * Get multiple values from this controller
   *
   * @param $menus
   *   An array of the menus to retrieve.
   *
   * @param $environment
   *   The realm of to fetch the setting for either 'space', 'preset', or
   *   'original'. Optional.
   */
  public function get_multiple($menus, $environment = NULL) {
    
  	$a_all_links = array();
  	
  	foreach ($menus as $id) {
  		$ret = $this->get($id,$environment);
  		$a_all_links = array_merge($a_all_links, $ret);
  	}
  	
    return $a_all_links;
  }
  
  /**
   * Delete a menu item from a menu by menu_item key
   * @param string $menu
   * @param string $link_key
   */
  public function delete_menu_item($menu, $link_key){
  	$a_menu_seting = $this->get( $menu );
  	
  	if(is_array($a_menu_seting) && isset($a_menu_seting[$link_key])){
      unset($a_menu_seting[$link_key]);
      return $this->set( $menu, $a_menu_seting);
  	}
  	
  	return false;
  }
  
  /**
   * Override of set()
   */
  function set($id, $value) {
  	$tmp = array($id => $value);
  	$this->add_missing_defaults($tmp,true);
  	
  	parent::set($id,$tmp[$id]);
  }
}
