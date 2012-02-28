<?php

/**
 * Implementation of hook_strongarm().
 */
function vsite_taxonomy_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_pattern';
  $strongarm->value = '[space-og-path]/filter_by/[catpath-raw]';

  $export['pathauto_taxonomy_pattern'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_vsite_taxonomy_pattern';
  $strongarm->value = '[space-og-path]/[feature-path]/filter_by/[catpath-raw]';

  $export['pathauto_vsite_taxonomy_pattern'] = $strongarm;
  return $export;
}
