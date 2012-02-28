<?php

function scholar_dvn_settings(){
  $base_url = 'http://dvn.iq.harvard.edu/dvn/dv/';
  $form['scholar_dvn_dvn_alias'] = array(
    '#type' => 'textfield',
    '#title' => t('Dataverse alias'),
    '#default_value' => variable_get('scholar_dvn_dvn_alias', ''),
    '#description' => t('Enter full URL for your dataverse. For example, http://dvn.iq.harvard.edu/dvn/dv/youralias'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
    '#element_validate' => array('scholar_dvn_alias_validate'),
  );

  $form['dvn_next_steps'] = array(
    '#type' => 'markup',
    '#title' => t('Next Steps'),
    '#value' => '<h3>Next Steps: </h3><div class="field-prefix">To complete embedding the Dataverse in this OpenScholar site, go to your Dataverse Options, click Edit Layout Branding and select "Disable customization if Dataverse is embedded in an OpenScholar site</div>'
  );

  return system_settings_form($form);
}

function scholar_dvn_alias_validate($element, &$form_state) {
  if (strpos($form_state['values']['scholar_dvn_dvn_alias'], 'http:') === FALSE) {
    form_set_error('scholar_dvn_dvn_alias', t('DVN must point to a valid URL'));
  }
}