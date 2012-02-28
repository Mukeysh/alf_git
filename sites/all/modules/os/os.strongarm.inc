<?php

/**
 * Implementation of hook_strongarm().
 */
function os_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_theme';
  $strongarm->value = 'openscholar_default';
  $export['admin_theme'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_admin_theme';
  $strongarm->value = 0;
  $export['node_admin_theme'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'spaces_features';
  $strongarm->value = array(
    'scholar_announcements' => 1,
    'scholar_publications' => 1,
    'scholar_presentations' => 1,
    'scholar_events' => 1,
    'scholar_classes' => 1,
    'scholar_image_gallery' => 1,
    'scholar_blog' => 1,
    'scholar_links' => 1,
    'scholar_software' => 1,
    'vsite' => 1,
  );
  $export['spaces_features'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'openscholar_default';
  $export['theme_default'] = $strongarm;

  return $export;
}
