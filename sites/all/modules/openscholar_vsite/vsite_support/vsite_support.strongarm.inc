<?php

/**
 * Implementation of hook_strongarm().
 */
function vsite_support_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'contact_form_information';
  $strongarm->value = "<p>Use the form below to send us your comments or report any problems you experienced using your website. We read all feedback carefully and will respond quickly.</p>";

  $export['contact_form_information'] = $strongarm;
  
  return $export;
}
