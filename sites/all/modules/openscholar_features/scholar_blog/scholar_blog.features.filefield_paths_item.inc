<?php

/**
 * Implementation of hook_filefield_paths_item_default_items().
 */
function scholar_blog_filefield_paths_item_default_items() {
  $settings = array();

  // Exported blog-field_os_inline_files
  $settings['blog-field_os_inline_files'] = array(
    'type' => 'blog',
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
  // Exported blog-field_os_inline_image
  $settings['blog-field_os_inline_image'] = array(
    'type' => 'blog',
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
  // Exported blog-upload
  $settings['blog-upload'] = array(
    'type' => 'blog',
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
