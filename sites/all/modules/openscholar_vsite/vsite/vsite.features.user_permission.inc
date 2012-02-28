<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function vsite_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer addthis
  $permissions['administer addthis'] = array(
    'name' => 'administer addthis',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: create openscholar site on behalf of others
  $permissions['create openscholar site on behalf of others'] = array(
    'name' => 'create openscholar site on behalf of others',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
    ),
  );

  // Exported permission: create own openscholar site
  $permissions['create own openscholar site'] = array(
    'name' => 'create own openscholar site',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'scholar user',
    ),
  );
  
  // Exported permission: view addthis
  $permissions['view addthis'] = array(
    'name' => 'view addthis',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'scholar admin',
      '3' => 'scholar user',
      '4' => 'administrator',
      '5' => 'manager',
    ),
  );

  return $permissions;
}
