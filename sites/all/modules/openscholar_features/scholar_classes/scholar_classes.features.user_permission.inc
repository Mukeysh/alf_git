<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_classes_user_default_permissions() {
  $permissions = array();

  // Exported permission: create class content
  $permissions['create class content'] = array(
    'name' => 'create class content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: create class_material content
  $permissions['create class_material content'] = array(
    'name' => 'create class_material content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: delete own class content
  $permissions['delete own class content'] = array(
    'name' => 'delete own class content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: delete own class_material content
  $permissions['delete own class_material content'] = array(
    'name' => 'delete own class_material content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: edit own class content
  $permissions['edit own class content'] = array(
    'name' => 'edit own class content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: edit own class_material content
  $permissions['edit own class_material content'] = array(
    'name' => 'edit own class_material content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override class authored by option
  $permissions['override class authored by option'] = array(
    'name' => 'override class authored by option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override class authored on option
  $permissions['override class authored on option'] = array(
    'name' => 'override class authored on option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override class promote to front page option
  $permissions['override class promote to front page option'] = array(
    'name' => 'override class promote to front page option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override class published option
  $permissions['override class published option'] = array(
    'name' => 'override class published option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override class revision option
  $permissions['override class revision option'] = array(
    'name' => 'override class revision option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override class sticky option
  $permissions['override class sticky option'] = array(
    'name' => 'override class sticky option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override class_material authored by option
  $permissions['override class_material authored by option'] = array(
    'name' => 'override class_material authored by option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override class_material authored on option
  $permissions['override class_material authored on option'] = array(
    'name' => 'override class_material authored on option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override class_material promote to front page option
  $permissions['override class_material promote to front page option'] = array(
    'name' => 'override class_material promote to front page option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override class_material published option
  $permissions['override class_material published option'] = array(
    'name' => 'override class_material published option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override class_material revision option
  $permissions['override class_material revision option'] = array(
    'name' => 'override class_material revision option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override class_material sticky option
  $permissions['override class_material sticky option'] = array(
    'name' => 'override class_material sticky option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  return $permissions;
}
