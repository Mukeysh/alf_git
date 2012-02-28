<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_announcements_user_default_permissions() {
  $permissions = array();

  // Exported permission: create announcement content
  $permissions['create announcement content'] = array(
    'name' => 'create announcement content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: delete own announcement content
  $permissions['delete own announcement content'] = array(
    'name' => 'delete own announcement content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own announcement content
  $permissions['edit own announcement content'] = array(
    'name' => 'edit own announcement content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
    ),
  );

  // Exported permission: override announcement authored by option
  $permissions['override announcement authored by option'] = array(
    'name' => 'override announcement authored by option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override announcement authored on option
  $permissions['override announcement authored on option'] = array(
    'name' => 'override announcement authored on option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override announcement promote to front page option
  $permissions['override announcement promote to front page option'] = array(
    'name' => 'override announcement promote to front page option',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: override announcement published option
  $permissions['override announcement published option'] = array(
    'name' => 'override announcement published option',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: override announcement revision option
  $permissions['override announcement revision option'] = array(
    'name' => 'override announcement revision option',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: override announcement sticky option
  $permissions['override announcement sticky option'] = array(
    'name' => 'override announcement sticky option',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  return $permissions;
}
