<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_blog_user_default_permissions() {
  $permissions = array();

  // Exported permission: create blog content
  $permissions['create blog content'] = array(
    'name' => 'create blog content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: delete own blog content
  $permissions['delete own blog content'] = array(
    'name' => 'delete own blog content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
    ),
  );

  // Exported permission: override blog authored by option
  $permissions['override blog authored by option'] = array(
    'name' => 'override blog authored by option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override blog authored on option
  $permissions['override blog authored on option'] = array(
    'name' => 'override blog authored on option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override blog promote to front page option
  $permissions['override blog promote to front page option'] = array(
    'name' => 'override blog promote to front page option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override blog published option
  $permissions['override blog published option'] = array(
    'name' => 'override blog published option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override blog revision option
  $permissions['override blog revision option'] = array(
    'name' => 'override blog revision option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override blog sticky option
  $permissions['override blog sticky option'] = array(
    'name' => 'override blog sticky option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  return $permissions;
}
