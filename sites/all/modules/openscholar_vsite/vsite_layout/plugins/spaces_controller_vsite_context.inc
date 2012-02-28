<?php

/**
 * Vsite Context controller.
 */
class spaces_controller_vsite_context extends spaces_controller_context {

  /**
   * Override of load_space_values().
   *
   * All overrides are retrieved at once for a given space to reduce the number
   * of queries run when a space is active.
   *
   * If there are theme specific block settings those are used
   */
  protected function load_space_values($id = NULL) {
    if (!$this->loaded_all['space']) {
      
    	//Allow block settings to be stored by theme
    	$group_node = node_load($this->space_id);
	    if (!empty($group_node->og_theme)) {
		    $custom_theme_key = "reaction:block:".$group_node->og_theme;
		  }
		  
    	$result = db_query("
        SELECT object_id AS id, value
        FROM {spaces_overrides}
        WHERE type = '%s'
          AND id = '%s'
          AND object_type = '%s'",
        $this->space_type, $this->space_id, $this->controller);
      $theme_block_overwrites = array();
      while ($row = db_fetch_object($result)) {
      	list($context, $key) = explode(':', $row->id,2);
      	if($custom_theme_key && $custom_theme_key == $key){
      		//Theme specific context block reactions will overwrite the standard block reactions
      		$theme_block_overwrites[substr($row->id,0, -1 - strlen($group_node->og_theme))] = unserialize($row->value);
      	}
      	
        $this->values['space'][$row->id] = unserialize($row->value);
      }
      
      // Overwrite/Create block settings defaulting to theme block settings
      foreach ($theme_block_overwrites as $s_key => $theme_overwrites) {
      	if(isset($this->values['space'][$s_key])){
      		//There are also standard settings, add the theme settings also
      		$this->values['space'][$s_key]['blocks'] = array_merge($this->values['space'][$s_key]['blocks'],$theme_overwrites['blocks']);
      	}else{
      		//Only the theme settings are avalible, use them
      		$this->values['space'][$s_key] = $theme_overwrites;
      	}
      }
      
      $this->loaded_all['space'] = TRUE;
    }
  }
  
  /**
   * Override of load_preset_values()
   * That allows modifying the preset's block regions based on the current theme
   */
  protected function load_preset_values($id = NULL) {
  	if (!$this->loaded_all['preset']) {
	  	parent::load_preset_values($id);
	  	
	    if (is_array($this->values['preset'])) {
	    	foreach ($this->values['preset'] as $object_id => $value) {
	    		list($context, $action, $type, $theme) = explode(':', $object_id);
	    		if($action = 'reaction' && $type == 'block' && array_key_exists('blocks',$value)){
	    			drupal_alter('vsite_default_blocks',$this->values['preset'][$object_id]['blocks']);
	    		}
	    	}
	    }//Allow the theme and others to alter the default block regions
  	}//Only run alter if loading the presets
  }
  
}
