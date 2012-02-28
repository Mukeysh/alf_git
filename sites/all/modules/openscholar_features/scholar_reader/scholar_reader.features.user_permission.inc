<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_reader_user_default_permissions() {
  $permissions = array();

  // Exported permission: create feed content
  $permissions['create feed content'] = array(
    'name' => 'create feed content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: administer feeds
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own feed content
  $permissions['delete own feed content'] = array(
    'name' => 'delete own feed content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: edit own feed content
  $permissions['edit own feed content'] = array(
    'name' => 'edit own feed content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override feed promote to front page option
  $permissions['override feed promote to front page option'] = array(
    'name' => 'override feed promote to front page option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override feed published option
  $permissions['override feed published option'] = array(
    'name' => 'override feed published option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override feed revision option
  $permissions['override feed revision option'] = array(
    'name' => 'override feed revision option',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: override feed sticky option
  $permissions['override feed sticky option'] = array(
    'name' => 'override feed sticky option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override feed authored on option
  $permissions['override feed authored by option'] = array(
    'name' => 'override feed authored by option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );
  
  // Exported permission: override feed authored on option
  $permissions['override feed authored on option'] = array(
    'name' => 'override feed authored on option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );
  
  return $permissions;
}
