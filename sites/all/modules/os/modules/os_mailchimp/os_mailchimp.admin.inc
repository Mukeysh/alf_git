<?php

/**
 * Implementation of cite_distribute_admin()
 */
function os_mailchimp_admin() {
	$form = array();
  $form['os_mailchimp'] = array(
	  '#type' => 'fieldset',
	  '#title' => t('Configure MailChimp'),
	  '#collapsible' => FALSE,
	  '#collapsed' => FALSE,
    '#description' => t('Settings for sitewide MailChimp box.  Does not override individual boxes.'),
	);

	//module mode 
  $form['os_mailchimp']['os_mailchimp_api'] = array(
	  '#type' => 'textfield',
	  '#title' => t('API Key'),
	  '#required' => TRUE,
	  '#default_value' => variable_get('os_mailchimp_api', ''), 
	  '#description' => t('Your MailChimp API Key.  Leaving this blank will disable automatic subscription'),
   );
   $options = _os_mailchimp_get_lists(variable_get('os_mailchimp_api', ''));
   if ($options) {
    $form['os_mailchimp']['os_mailchimp_list'] = array(
  	  '#type' => 'select',
  	  '#title' => t('Mailing List'),
  	  '#required' => TRUE,
  	  '#default_value' => variable_get('os_mailchimp_list', ''), 
  	  '#description' => t('MailChimp list to subscribe new users to.'),
      '#options' => $options,
     );
   } else {
     $form['os_mailchimp']['api_key_error'] = array(
       '#type' => 'markup',
       '#value' => 'No mailing lists available.  Please check your API key and try again.',
     );
   }
      
   return system_settings_form($form);
}