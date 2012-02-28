<?php


function googlescholar_meta_settings_form(){ 
  
  $form = array();
  
  $form['googlescholar_meta'] = array(
    '#type' => 'fieldset',
   '#collapsible' => FALSE,
  );
  
  $form['googlescholar_meta']['googlescholar_autoflag'] = array(
    '#type' => 'checkbox',
    //'#options' => array(0,1),
    '#title' => t('Set Google Scholar autoflag setting'),
    '#default_value' => variable_get('googlescholar_autoflag', 0),
    '#description' => t("Selecting this setting will automatically flag publications for Google Scholar when they are created. Meta information specific to Google Scholar service will be placed  with the head section when rendering publication nodes."),
  );
  
  return system_settings_form($form);
}