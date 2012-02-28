<?php

/**
 * Implementation of hook_filefield_paths_item_default_items().
 */
function scholar_software_filefield_paths_item_default_items() {
  $settings = array();

  // Exported scholar_software_project-field_os_inline_files
  $settings['scholar_software_project-field_os_inline_files'] = array(
    'type' => 'scholar_software_project',
    'field' => 'field_os_inline_files',
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
  // Exported scholar_software_project-field_os_inline_image
  $settings['scholar_software_project-field_os_inline_image'] = array(
    'type' => 'scholar_software_project',
    'field' => 'field_os_inline_image',
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
  // Exported scholar_software_project-field_scholar_software_logo
  $settings['scholar_software_project-field_scholar_software_logo'] = array(
    'type' => 'scholar_software_project',
    'field' => 'field_scholar_software_logo',
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
    'filealias' => FALSE,
  );
  // Exported scholar_software_project-upload
  $settings['scholar_software_project-upload'] = array(
    'type' => 'scholar_software_project',
    'field' => 'upload',
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
  // Exported scholar_software_release-field_os_inline_files
  $settings['scholar_software_release-field_os_inline_files'] = array(
    'type' => 'scholar_software_release',
    'field' => 'field_os_inline_files',
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
  // Exported scholar_software_release-field_os_inline_image
  $settings['scholar_software_release-field_os_inline_image'] = array(
    'type' => 'scholar_software_release',
    'field' => 'field_os_inline_image',
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
  // Exported scholar_software_release-field_scholar_software_file
  $settings['scholar_software_release-field_scholar_software_file'] = array(
    'type' => 'scholar_software_release',
    'field' => 'field_scholar_software_file',
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
  // Exported scholar_software_release-upload
  $settings['scholar_software_release-upload'] = array(
    'type' => 'scholar_software_release',
    'field' => 'upload',
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
