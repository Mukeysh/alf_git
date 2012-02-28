<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function os_modalframe_user_default_permissions() {
  $permissions = array();

  // Exported permission: create modal_image content
  $permissions['create modal_image content'] = array(
    'name' => 'create modal_image content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: delete own modal_image content
  $permissions['delete own modal_image content'] = array(
    'name' => 'delete own modal_image content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: edit own modal_image content
  $permissions['edit own modal_image content'] = array(
    'name' => 'edit own modal_image content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override modal_image authored by option
  $permissions['override modal_image authored by option'] = array(
    'name' => 'override modal_image authored by option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override modal_image authored on option
  $permissions['override modal_image authored on option'] = array(
    'name' => 'override modal_image authored on option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override modal_image promote to front page option
  $permissions['override modal_image promote to front page option'] = array(
    'name' => 'override modal_image promote to front page option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override modal_image published option
  $permissions['override modal_image published option'] = array(
    'name' => 'override modal_image published option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override modal_image revision option
  $permissions['override modal_image revision option'] = array(
    'name' => 'override modal_image revision option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override modal_image sticky option
  $permissions['override modal_image sticky option'] = array(
    'name' => 'override modal_image sticky option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  return $permissions;
}
