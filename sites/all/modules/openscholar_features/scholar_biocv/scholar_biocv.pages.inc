<?php

/**
 * Biocv settings form
 */
function scholar_biocv_settings(){
  $form['scholar_biocv_use_pdf_as_cv'] = array(
    '#type' => 'checkbox',
    '#weight' => - 10,
    '#title' => t('Use PDF upload as your CV'),
    '#default_value' => variable_get('scholar_biocv_use_pdf_as_cv', 0),
    '#description' => t('When this is checked the pdf you upload will be displayed on the cv section of your site.')
  );
  
  return system_settings_form($form);
}