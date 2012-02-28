<?php

/**
 * Themable function to generate message after user submits
 *  cite_distribute widget selections
 *
 * @param unknown_type $modules
 * @return unknown
 */
function theme_cite_distribute_form_msg($modules = NULL){
  //determine whether to add 's' to text if multiple citatations submitted
  $s = count($modules) > 1 ? 's' : '';

  if($modules){
    $output_r = '';
    $output = 'Submitted citatation' .  $s . ' to: ';
    foreach ($modules as $module){
      //getting information about the module
      //$info = module_invoke($module, 'cite_distribute_register');
      //$output_r .=  ' '. $info[0]['repository'] . ',';
      $output_r .= $module;
    }
    $output .= substr($output_r, 0, -1);
    return $output;
  }
  return false;
}