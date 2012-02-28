<?php

/**
 * Implementation of hook_drush_help().
 */
function os_views_content_cache_drush_help($section) {
  switch ($section) {
    case 'drush:clearcache':
      return dt("Clears the cache for os content caches.");
      break;
  }
}

/**
 * Implementation of hook_drush_command().
 */
function os_views_content_cache_drush_command() {
  $items['os-clearcache'] = array(
    'description' => "Clears the cache for os content caches.",
    'arguments' => array(
      'cache' => 'The name of the cache to clear.',
    ),
    'examples' => array(
      'view' => 'Clear the content cache for views',
      'block' => 'Clear the content cache for blocks',
      'all' => 'Clear the content cache for all'
    ),
    'aliases' => array('oscc'),
  );
  return $items;
}

function drush_os_views_content_cache_os_clearcache($arg = 'all') {
	
	if(in_array($arg,array('all','view'))){
    cache_clear_all('*','cache_views_data',TRUE);
	}
	
  if(in_array($arg,array('all','block'))){
    cache_clear_all('*','cache_block',TRUE);
  }
}