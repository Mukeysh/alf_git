<?php

/**
 * Action: Load a term configuration form.
 *
 * Multistep form.
 */
function radioactivity_rules_action_load_decay_profile_form($settings, &$form, $form_state) {
  $settings += array('decay_profile' => 0);

  // Get existing taxonomy vocabularies.
  $options_raw = radioactivity_get_decay_profiles();
  $options = array();

  foreach ($options_raw as $dpid => $profile) {
    $options[$dpid] = $profile['label'];
  }
  
  $form['settings']['decay_profile'] = array(
    '#type' => 'select',
    '#title' => t('Decay profile'),
    '#options' => $options,
    '#description' => t("Select a decay profile"),
    '#required' => TRUE,
    '#disabled' => empty($options),
  );
  
}
