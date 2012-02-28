<?php

/**
 * Implementation of hook_strongarm().
 */
function vsite_cc_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'creativecommons_available_license_types';
  $strongarm->value = array(
    '' => '',
    'by' => 'by',
    'by-sa' => 'by-sa',
    'by-nd' => 'by-nd',
    'mark' => 'mark',
    'zero' => 'zero',
  );

  $export['creativecommons_available_license_types'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'creativecommons_available_metadata';
  $strongarm->value = array(
    'attributionName' => 'attributionName',
    'attributionURL' => 'attributionURL',
    'morePermissions' => 'morePermissions',
    'title' => 'title',
    'type' => 'type',
    'source' => 'source',
  );

  $export['creativecommons_available_metadata'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'creativecommons_node_types';
  $strongarm->value = array(
    'biblio' => 'biblio',
    'class_material' => 'class_material',
    'image' => 'image',
    'page' => 'page',
    'scholar_software_project' => 'scholar_software_project',
    'scholar_software_release' => 'scholar_software_release',
    'announcement' => 0,
    'blog' => 0,
    'book' => 0,
    'class' => 0,
    'event' => 0,
    'feed' => 0,
    'gallery' => 0,
    'link' => 0,
    'person' => 0,
    'profile' => 0,
    'vsite' => 0,
    'sitewide_page' => 0,
    'vsite_users_profile' => 0,
    'bio' => 0,
    'cv' => 0,
  );

  $export['creativecommons_node_types'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'creativecommons_required_metadata';
  $strongarm->value = array(
    'attributionName' => 0,
    'attributionURL' => 0,
    'morePermissions' => 0,
    'title' => 0,
    'type' => 0,
    'source' => 0,
    'description' => 0,
    'creator' => 0,
    'rights' => 0,
    'date' => 0,
  );

  $export['creativecommons_required_metadata'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'creativecommons_search';
  $strongarm->value = FALSE;

  $export['creativecommons_search'] = $strongarm;
  return $export;
}
