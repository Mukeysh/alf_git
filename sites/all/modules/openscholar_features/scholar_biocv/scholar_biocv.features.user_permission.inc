<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_biocv_user_default_permissions() {
  $permissions = array();

  // Exported permission: create bio content
  $permissions['create bio content'] = array(
    'name' => 'create bio content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: create cv content
  $permissions['create cv content'] = array(
    'name' => 'create cv content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: delete own bio content
  $permissions['delete own bio content'] = array(
    'name' => 'delete own bio content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: delete own cv content
  $permissions['delete own cv content'] = array(
    'name' => 'delete own cv content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: edit own bio content
  $permissions['edit own bio content'] = array(
    'name' => 'edit own bio content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: edit own cv content
  $permissions['edit own cv content'] = array(
    'name' => 'edit own cv content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override bio revision option
  $permissions['override bio revision option'] = array(
    'name' => 'override bio revision option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override bio sticky option
  $permissions['override bio sticky option'] = array(
    'name' => 'override bio sticky option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override cv revision option
  $permissions['override cv revision option'] = array(
    'name' => 'override cv revision option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override cv sticky option
  $permissions['override cv sticky option'] = array(
    'name' => 'override cv sticky option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  return $permissions;
}
