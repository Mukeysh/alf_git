<?php

/**
 * Implementation of hook_filefield_paths_item_default_items().
 */
function os_modalframe_filefield_paths_item_default_items() {
  $settings = array();

  // Exported modal_image-field_modal_image
  $settings['modal_image-field_modal_image'] = array(
    'type' => 'modal_image',
    'field' => 'field_modal_image',
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
      'display' => 1,
    ),
  );

  return $settings;
}
