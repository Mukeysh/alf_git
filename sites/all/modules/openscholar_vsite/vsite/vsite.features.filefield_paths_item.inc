<?php

/**
 * Implementation of hook_filefield_paths_item_default_items().
 */
function vsite_filefield_paths_item_default_items() {
  $settings = array();

  // Exported vsite-field_vsite_logo
  $settings['vsite-field_vsite_logo'] = array(
    'type' => 'vsite',
    'field' => 'field_vsite_logo',
    'filename' => array(
      'value' => '[filefield-onlyname-original].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filepath' => array(
      'value' => '[space-og-path-raw]/files',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filealias' => array(
      'value' => '[space-og-path-raw]/files/[filefield-onlyname-original].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
      'display' => 0,
    ),
  );

  return $settings;
}
