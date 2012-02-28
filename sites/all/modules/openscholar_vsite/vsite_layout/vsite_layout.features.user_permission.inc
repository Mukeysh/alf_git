<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function vsite_layout_user_default_permissions() {
  $permissions = array();

  // Exported permission: reset layout to defaults
  $permissions['reset layout to defaults'] = array(
    'name' => 'reset layout to defaults',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  return $permissions;
}
