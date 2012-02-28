<?php

/**
 * Allows cache to be cleared when certain config changes are made to vsites
 * @author rbrandon
 *
 */
class views_content_cache_key_vsite_config extends views_content_cache_key {
  function options_form($value) {
    return array(
      '#title' => t('Vsite Config Changes'),
      '#description' => t('Checks for new or updated config changes of the following types'),
      '#type' => 'checkboxes',
      '#options' => os_views_content_cache_vsite_config_forms(),
      '#default_value' => $value,
    );
  }

  function content_key($object, $object_type) {
  	
    if ($object_type === 'form_id' && is_string($object) && array_key_exists($object, os_views_content_cache_vsite_config_forms())) {
      return $object;
    }
    
  }
  
}
