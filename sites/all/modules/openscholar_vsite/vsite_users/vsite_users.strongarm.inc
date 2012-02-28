<?php

/**
 * Implementation of hook_strongarm().
 */
function vsite_users_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_vsite_users_profile';
  $strongarm->value = '[vsite_users_first_name-raw] [vsite_users_last_name-raw]';

  $export['ant_pattern_vsite_users_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_vsite_users_profile';
  $strongarm->value = 0;

  $export['ant_php_vsite_users_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_vsite_users_profile';
  $strongarm->value = 1;

  $export['ant_vsite_users_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_vsite_users_profile';
  $strongarm->value = 0;

  $export['comment_vsite_users_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_vsite_users_profile';
  $strongarm->value = 1;

  $export['content_profile_use_vsite_users_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_vsite_users_profile';
  $strongarm->value = array(
    'weight' => 0,
    'user_display' => 'full',
    'edit_link' => 0,
    'edit_tab' => 'sub',
    'add_link' => 0,
    'registration_use' => 1,
    'admin_user_create_use' => 1,
    'registration_hide' => array(
      0 => 'other',
    ),
  );

  $export['content_profile_vsite_users_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_vsite_users_profile';
  $strongarm->value = FALSE;

  $export['show_diff_inline_vsite_users_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_vsite_users_profile';
  $strongarm->value = FALSE;

  $export['show_preview_changes_vsite_users_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ucreate_default_roles';
  $strongarm->value = array(
    4 => 4,
  );

  $export['ucreate_default_roles'] = $strongarm;
  return $export;
}
