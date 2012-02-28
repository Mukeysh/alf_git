<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function vsite_news_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer activity
  $permissions['administer activity'] = array(
    'name' => 'administer activity',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  return $permissions;
}
