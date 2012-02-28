<?php

/**
 * Themable function to generate message after user submits
 *  cite_distribute widget selections
 *
 * @param array $modules
 *   List of repositories to which the node was submitted
 * @return string
 *   Returns textual list of the repositories titles.
 */
function theme_citation_distribute_form_msg($modules = NULL){
  $plugins = _citation_distribute_plugins();
  
  if ($modules) {
  	$out = array(); 
  	foreach ($modules as $module) {
  		$out[] = $plugins[$module]['title'];
  	}
  	return 'Submitted citation to: ' . implode(', ', $out);
  } else { 	 
	  return false;
  }
}
