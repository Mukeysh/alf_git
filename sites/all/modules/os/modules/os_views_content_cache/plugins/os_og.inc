<?php

/**
 * Extension of the og key to handle vsite_config as well
 * @author rbrandon
 */
class views_content_cache_key_os_og extends views_content_cache_key_og {
  
  function options_form($value) {
    return array(
      '#title' => t('OS Extended Organic Groups'),
      '#description' => t('Handles Organic Groups with additional features for OS sites'),
      '#type' => 'checkboxes',
      '#options' => array(
        'current' => t('Current vsite'),
        'user' => t("Member's groups")
      ),
      '#default_value' => $value,
    );
  }
  
  function content_key($object, $object_type) {
    
    if ($object_type === 'form_id' && is_string($object) && array_key_exists($object, os_views_content_cache_vsite_config_forms())){
    	
    	$vsite = vsite_get_vsite();
    	if($vsite){
        return $vsite->id;
    	}
    }
    
    return parent::content_key($object,$object_type);
  }
  
}
