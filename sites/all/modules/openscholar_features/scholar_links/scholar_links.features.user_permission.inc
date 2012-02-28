<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_links_user_default_permissions() {
  $permissions = array();

  // Exported permission: create link content
  $permissions['create link content'] = array(
    'name' => 'create link content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: delete own link content
  $permissions['delete own link content'] = array(
    'name' => 'delete own link content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: edit own link content
  $permissions['edit own link content'] = array(
    'name' => 'edit own link content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override link authored by option
  $permissions['override link authored by option'] = array(
    'name' => 'override link authored by option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override link authored on option
  $permissions['override link authored on option'] = array(
    'name' => 'override link authored on option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override link promote to front page option
  $permissions['override link promote to front page option'] = array(
    'name' => 'override link promote to front page option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override link published option
  $permissions['override link published option'] = array(
    'name' => 'override link published option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override link revision option
  $permissions['override link revision option'] = array(
    'name' => 'override link revision option',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: override link sticky option
  $permissions['override link sticky option'] = array(
    'name' => 'override link sticky option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  return $permissions;
}
