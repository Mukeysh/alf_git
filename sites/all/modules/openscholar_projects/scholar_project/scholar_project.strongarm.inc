<?php

/**
 * Implementation of hook_strongarm().
 */
function scholar_project_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_project';
  $strongarm->value = 0;
  
  $export['comment_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_project';
  $strongarm->value = FALSE;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'iqss_openscholar_front_stats_enabled';
  $strongarm->value = 'a:6:{s:12:"Publications";b:0;s:6:"Vsites";b:1;s:5:"Nodes";b:1;s:5:"Files";b:1;s:8:"Filesize";b:0;s:5:"Users";b:0;}';
  $export['iqss_openscholar_front_stats_enabled'] = $strongarm;
  
  $export['upload_project'] = $strongarm;
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
  $strongarm->value = 'project';

  $export['openscholar_installation_mode'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scholar_content_type';
  $strongarm->value = 'project';

  $export['scholar_content_type'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_project';
  $strongarm->value = 'group';

  $export['og_content_type_usage_project'] = $strongarm;
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
  $strongarm->value = 'scholar_cayley';
  $export['openscholar_vsite_default_theme'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openscholar_selected_themes';
  $strongarm->value = array( 'scholar_bunchy', 'scholar_cayley', 'scholar_nortony');

  $export['openscholar_selected_themes'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'spaces_default_presets';
  $strongarm->value = array(
    'og' => 'project'
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
  $strongarm->name = 'scholar_home_page_title';
  $strongarm->value = "IQSS Projects Access";

  $export['scholar_home_page_title'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scholar_default_preset';
  $strongarm->value = 'project';

  $export['scholar_default_preset'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_project';
  $strongarm->value = false;

  $export['show_preview_changes_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_project';
  $strongarm->value = false;

  $export['show_diff_inline_project'] = $strongarm;
  return $export;
}
