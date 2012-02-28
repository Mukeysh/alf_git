<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_software_user_default_permissions() {
  $permissions = array();

  // Exported permission: create scholar_software_project content
  $permissions['create scholar_software_project content'] = array(
    'name' => 'create scholar_software_project content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: create scholar_software_release content
  $permissions['create scholar_software_release content'] = array(
    'name' => 'create scholar_software_release content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: delete own scholar_software_project content
  $permissions['delete own scholar_software_project content'] = array(
    'name' => 'delete own scholar_software_project content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own scholar_software_release content
  $permissions['delete own scholar_software_release content'] = array(
    'name' => 'delete own scholar_software_release content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own scholar_software_project content
  $permissions['edit own scholar_software_project content'] = array(
    'name' => 'edit own scholar_software_project content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: edit own scholar_software_release content
  $permissions['edit own scholar_software_release content'] = array(
    'name' => 'edit own scholar_software_release content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override scholar_software_project authored by option
  $permissions['override scholar_software_project authored by option'] = array(
    'name' => 'override scholar_software_project authored by option',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: override scholar_software_project authored on option
  $permissions['override scholar_software_project authored on option'] = array(
    'name' => 'override scholar_software_project authored on option',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: override scholar_software_project promote to front page option
  $permissions['override scholar_software_project promote to front page option'] = array(
    'name' => 'override scholar_software_project promote to front page option',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: override scholar_software_project published option
  $permissions['override scholar_software_project published option'] = array(
    'name' => 'override scholar_software_project published option',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: override scholar_software_release promote to front page option
  $permissions['override scholar_software_release promote to front page option'] = array(
    'name' => 'override scholar_software_release promote to front page option',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: override scholar_software_release published option
  $permissions['override scholar_software_release published option'] = array(
    'name' => 'override scholar_software_release published option',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: override scholar_software_release revision option
  $permissions['override scholar_software_release revision option'] = array(
    'name' => 'override scholar_software_release revision option',
    'roles' => array(
      '0' => 'administrator',
    ),
  );
  
  // Exported permission: override scholar_software_release authored on option
  $permissions['override scholar_software_release authored by option'] = array(
    'name' => 'override scholar_software_release authored by option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );
  
  // Exported permission: override scholar_software_release authored on option
  $permissions['override scholar_software_release authored on option'] = array(
    'name' => 'override scholar_software_release authored on option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );
  
  // Exported permission: override scholar_software_project authored on option
  $permissions['override scholar_software_project authored by option'] = array(
    'name' => 'override scholar_software_project authored by option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );
  
  // Exported permission: override scholar_software_project authored on option
  $permissions['override scholar_software_project authored on option'] = array(
    'name' => 'override scholar_software_project authored on option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  return $permissions;
}
