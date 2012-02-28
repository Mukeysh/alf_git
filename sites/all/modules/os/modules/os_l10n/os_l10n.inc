<?php 

/**
 * @file
 *   openscholar l10n common variables
 */

// os version. This should be defined somewhere else
define('OS_L10N_VERSION', '6.x-1.0');

// This module is specific for os package so we already know some data
//define('OS_L10N_SERVER', 'l10n.local');      //only exists on sagotsky's desktop
define('OS_L10N_SERVER', 'scholar-dev1.iq.harvard.edu');      //only exists on sagotsky's desktop

// This is the default folder to place translation files
define('OS_L10N_DIRECTORY', 'sites/default/files/l10n_packager');

// Location of the l10n_update module we need to know to check requirements
// define('os_L10N_UPDATE', './profiles/os_translation/modules/l10n_update');

// Temporary variables that help with installation
//define('OS_L10N_UPDATE_PATH', '/l10n/status/project/os');

/**
 * wrapper for hook_update_projects_alter
 * sets openscholar modules to use OS's own translation server
 * 
 * we could forgo this if each module included a l10n server in their .info
 */
function _os_update_projects_alter(&$projects) {
  //list of modules that should refer to OS's translation server for translation updates
  $os_modules = array();//'os', 'scholar_announcements');

  foreach($os_modules as $mod) {
    $projects[$mod]['info']['l10n server'] = OS_L10N_SERVER;
  }
  
  //lets ignore everything but OS for now.
 $projects = array_intersect_key($projects, array_flip($os_modules));
}

/**
 * wrapper for hook_l10n_server
 * defines OS's localization server
 */
function _os_l10n_servers() {
  return array(
  	OS_L10N_SERVER => array(
  	  'name' => OS_L10N_SERVER,
    	'server_url' => 'http://'.OS_L10N_SERVER.'/'.OS_L10N_DIRECTORY.'/l10n_server.xml',
  	  'update_url' => 'http://'.OS_L10N_SERVER.'/'.OS_L10N_DIRECTORY.'/%core/%project/%project-%release.%language.po',
  	), 
  );  
}