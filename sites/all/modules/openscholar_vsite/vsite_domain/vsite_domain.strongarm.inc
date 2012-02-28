<?php

/**
 * Implementation of hook_strongarm().
 */
function vsite_domain_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'purl_method_spaces_og';
  $strongarm->value = 'vsite_path';

  $export['purl_method_spaces_og'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'purl_method_vsite_domain';
  $strongarm->value = 'vsite_domain';

  $export['purl_method_vsite_domain'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'purl_types';
  $strongarm->value = array(
    'vsite_domain' => 'vsite_domain',
    'vsite_path' => 'vsite_path',
    'querystring' => 'querystring',
  );

  $export['purl_types'] = $strongarm;
  return $export;
}
