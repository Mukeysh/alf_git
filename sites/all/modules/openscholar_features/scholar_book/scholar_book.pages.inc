<?php
function scholar_book_settings() {
  $form['scholar_book_toc_location'] = array(
    '#type' => 'checkbox',
    '#title' => t('Table of content location'),
    '#default_value' => variable_get('scholar_book_toc_location', 0),
    '#description' => t('Check if you want the booklet\'s table of contents in the content area of the page'),
  );
  return system_settings_form($form);
}