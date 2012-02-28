<?php

/**
 * Installation of cite_distribute_admin()
 * @return Administrative settings form for cite distribute module
 */
function cite_distribute_admin(){

  $submodules = cite_distribute_installed_mods();

  $num_submodules = count($submodules);

  //creating an array with the module modes. these will be the options in the drop down menu in this form
  $module_mode_names = array('api'=> 'API Mode', 'batch' => 'Batch Process Mode', 'per_submission' => 'Per Submission Mode');

  $form['cite_distribute'] = array(
  '#type' => 'fieldset',
  '#title' => t('Configure Cite Distribute'),
  '#collapsible' => FALSE,
  '#collapsed' => FALSE,
  );

  $form['cite_distribute']['cite_distribute_module_mode'] = array(
  '#type' => 'select',
  '#title' => t('Select The Mode for this Module'),
  '#options' => $module_mode_names,
  '#required' => TRUE,
  '#default_value' => variable_get('cite_distribute_module_mode',''),
  '#description' => t('<strong>API mode</strong> does nothing by default, but lets the developer decide when to call the module\'s functions.
      <br><strong>Batch mode</strong> is intended to be run by cron will update all meta files at once in a batch process. 
      <br><strong>Per Submission mode (Recommended) </strong> will update or create a meta file whenever content submitted or updated.')
   );

      //checking to see if any submodules are installed
      return system_settings_form($form);
}