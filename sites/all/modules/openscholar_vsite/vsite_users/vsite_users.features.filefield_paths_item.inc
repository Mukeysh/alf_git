<?php

/**
 * Implementation of hook_filefield_paths_item_default_items().
 */
function vsite_users_filefield_paths_item_default_items() {
  $settings = array();

  // Exported vsite_users_profile-field_user_profile_photo
  $settings['vsite_users_profile-field_user_profile_photo'] = array(
    'type' => 'vsite_users_profile',
    'field' => 'field_user_profile_photo',
    'filename' => array(
      'value' => '[filefield-onlyname-original].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filepath' => array(
      'value' => 'user_profile/[user-id]',
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
