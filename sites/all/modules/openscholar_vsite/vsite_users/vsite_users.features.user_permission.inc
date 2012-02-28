<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function vsite_users_user_default_permissions() {
  $permissions = array();

  // Exported permission: create url aliases
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: create vsite_users_profile content
  $permissions['create vsite_users_profile content'] = array(
    'name' => 'create vsite_users_profile content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: delete own vsite_users_profile content
  $permissions['delete own vsite_users_profile content'] = array(
    'name' => 'delete own vsite_users_profile content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: edit own vsite_users_profile content
  $permissions['edit own vsite_users_profile content'] = array(
    'name' => 'edit own vsite_users_profile content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  return $permissions;
}
