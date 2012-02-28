<?php


/**
 * hook_vsite_vocabulary_default
 * provides vocabulary definitions to be created when 
 * a vsite is created
 */
function scholar_links_vsite_vocabulary_default(){

  return array (
    0 => array (
    'name' => 'Links categories',
    'content_types' => 'link',
    'properties' => array ('tags' => 1),
    'terms' => array (
      0 => array (
    	'name' => 'Statistics',
    	'desription' => 'Statistics',
    	'properties' => array ()
      ),
      1 => array (
    	'name' => 'Political Economy',
    	'desription' => 'Political Economy',
    	'properties' => array ()
      ),
      2 => array (
    	'name' => 'Data',
    	'desription' => 'Data',
    	'properties' => array ()
      ),
      3 => array (
    	'name' => 'Economics',
    	'desription' => 'Economics',
    	'properties' => array ()
      ),
      4 => array (
    	'name' => 'Goverment',
    	'desription' => 'Economics',
    	'properties' => array ()
      )
    )
  )
 );

}
