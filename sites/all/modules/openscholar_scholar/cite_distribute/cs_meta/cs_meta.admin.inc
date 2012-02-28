<?php

/**
* cs_meta_config()
* 
* @return 	Returns the system settings form for cs_meta 'Configuration' page
*/
function cs_meta_config(){
    
  $form['cs_meta'] = array( 
      '#type' => 'fieldset', 
      '#title' => t('Enter Computer Science Repository Information'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE, 
      ); 
  
  $form['cs_meta']['cs_meta_inst_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Institution Name'),
      '#default_value' => variable_get('cs_meta_inst_name',''),
      '#description' => t('Enter your institution\'s Name'),
      );
      
  $form['cs_meta']['cs_meta_archive_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Archive Root Path'),
      '#required' => TRUE,
      '#default_value' => variable_get('cs_meta_archive_path',''),
      '#description' => t('Enter the absolute path to the root of your cs_meta archive root.
       <br /> For example: /nfs/test/archive' )
  	);
  return system_settings_form($form);
}