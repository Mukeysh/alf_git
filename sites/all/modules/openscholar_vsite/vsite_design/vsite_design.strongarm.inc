<?php

/**
 * Implementation of hook_strongarm().
 */
function vsite_design_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'purl_method_vsite_theme_preview';
  $strongarm->value = 'querystring';

  $export['purl_method_vsite_theme_preview'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'purl_method_vsite_theme_preview_key';
  $strongarm->value = 't_preview';

  $export['purl_method_vsite_theme_preview_key'] = $strongarm;
  return $export;
}
