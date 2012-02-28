<?php

/**
 * Implementation of hook_strongarm().
 */
function scholar_strongarm() {
  $export = array();
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_register';
  $strongarm->value = 0;

  $export['user_register'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openscholar_installation_mode';
  $strongarm->value = 'scholar';

  $export['openscholar_installation_mode'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scholar_create_multiple_sites';
  $strongarm->value = 1;

  $export['scholar_create_multiple_sites'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openscholar_vsite_default_theme';
  $strongarm->value = 'scholar_airstream';

  $export['openscholar_vsite_default_theme'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openscholar_selected_themes';
  $strongarm->value = array('scholar_airstream', 'scholar_redhead', 'scholar_cayley');

  $export['openscholar_selected_themes'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'spaces_default_presets';
  $strongarm->value  = array(
    'og' => 'scholar'
  );

  $export['spaces_default_presets'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'spaces_disabled_presets';
  $strongarm->value = array(
    'og' => array(
      'private' => 1,
      'controlled' => 1,
      'public' => 1
    )
  );

  $export['spaces_disabled_presets'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scholar_default_preset';
  $strongarm->value = 'scholar';

  $export['scholar_default_preset'] = $strongarm;
  return $export;
}
