<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_publications_user_default_permissions() {
  $permissions = array();

  // Exported permission: access biblio content
  $permissions['access biblio content'] = array(
    'name' => 'access biblio content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'manager',
      '4' => 'scholar admin',
      '5' => 'scholar user',
    ),
  );

  // Exported permission: create biblio
  $permissions['create biblio'] = array(
    'name' => 'create biblio',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: edit own biblio entries
  $permissions['edit own biblio entries'] = array(
    'name' => 'edit own biblio entries',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: import from file
  $permissions['import from file'] = array(
    'name' => 'import from file',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
    ),
  );

  // Exported permission: override biblio authored by option
  $permissions['override biblio authored by option'] = array(
    'name' => 'override biblio authored by option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override biblio authored on option
  $permissions['override biblio authored on option'] = array(
    'name' => 'override biblio authored on option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override biblio promote to front page option
  $permissions['override biblio promote to front page option'] = array(
    'name' => 'override biblio promote to front page option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override biblio published option
  $permissions['override biblio published option'] = array(
    'name' => 'override biblio published option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override biblio revision option
  $permissions['override biblio revision option'] = array(
    'name' => 'override biblio revision option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: override biblio sticky option
  $permissions['override biblio sticky option'] = array(
    'name' => 'override biblio sticky option',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: show download links
  $permissions['show download links'] = array(
    'name' => 'show download links',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'manager',
      '4' => 'scholar admin',
      '5' => 'scholar user',
    ),
  );

  // Exported permission: show export links
  $permissions['show export links'] = array(
    'name' => 'show export links',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'manager',
      '4' => 'scholar admin',
      '5' => 'scholar user',
    ),
  );

  // Exported permission: show filter tab
  $permissions['show filter tab'] = array(
    'name' => 'show filter tab',
    'roles' => array(),
  );

  // Exported permission: show own download links
  $permissions['show own download links'] = array(
    'name' => 'show own download links',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'manager',
      '4' => 'scholar admin',
      '5' => 'scholar user',
    ),
  );

  // Exported permission: show sort links
  $permissions['show sort links'] = array(
    'name' => 'show sort links',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'manager',
      '4' => 'scholar admin',
      '5' => 'scholar user',
    ),
  );

  // Exported permission: view full text
  $permissions['view full text'] = array(
    'name' => 'view full text',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'manager',
      '4' => 'scholar admin',
      '5' => 'scholar user',
    ),
  );

  return $permissions;
}
