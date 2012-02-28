<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function scholar_events_signup_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer all signups
  $permissions['administer all signups'] = array(
    'name' => 'administer all signups',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer signups for own content
  $permissions['administer signups for own content'] = array(
    'name' => 'administer signups for own content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: cancel own signups
  $permissions['cancel own signups'] = array(
    'name' => 'cancel own signups',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'manager',
      '4' => 'scholar admin',
      '5' => 'scholar user',
    ),
  );

  // Exported permission: cancel signups
  $permissions['cancel signups'] = array(
    'name' => 'cancel signups',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
    ),
  );

  // Exported permission: edit own signups
  $permissions['edit own signups'] = array(
    'name' => 'edit own signups',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'manager',
      '3' => 'scholar admin',
      '4' => 'scholar user',
    ),
  );

  // Exported permission: email all signed up users
  $permissions['email all signed up users'] = array(
    'name' => 'email all signed up users',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
    ),
  );

  // Exported permission: email users signed up for own content
  $permissions['email users signed up for own content'] = array(
    'name' => 'email users signed up for own content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
      '3' => 'scholar user',
    ),
  );

  // Exported permission: sign up for content
  $permissions['sign up for content'] = array(
    'name' => 'sign up for content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'manager',
      '4' => 'scholar admin',
      '5' => 'scholar user',
    ),
  );

  // Exported permission: view all signups
  $permissions['view all signups'] = array(
    'name' => 'view all signups',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
      '2' => 'scholar admin',
    ),
  );

  return $permissions;
}
