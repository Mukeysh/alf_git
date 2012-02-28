<?php

function vsite_ga_settings_form(){
  $form = array();

  $form['vsite_ga_google_analytics_id'] = array(
  '#type' => 'textfield',
  '#title' => t('Enter your Google Analytics ID'),
  '#size' => 20,
  '#maxlength' => 255,
  '#default_value' => variable_get('vsite_ga_google_analytics_id', ''),
  '#description' => t("Entering your ID this will enable the sending of your OpenScholar sitewide page and visitor data to your Google Analytics account. Go to the <a href=\"http://www.google.com/analytics/\">Google Analytics site</a> to set one up. Your ID will be in the format UA-XXXXXXX-XX."),
  '#element_validate' => array('vsite_ga_analytics_id_validate')
  );

  return system_settings_form($form);
}