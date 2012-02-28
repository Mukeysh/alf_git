<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function openscholar_front_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function openscholar_front_flag_default_flags() {
  $flags = array();
  // Exported flag: "Featured web sites".
  $flags['featured_web_sites'] = array(
    'content_type' => 'node',
    'title' => 'Featured web sites',
    'global' => '1',
    'types' => array(
      '0' => 'vsite',
      '1' => 'project',
    ),
    'flag_short' => 'feature',
    'flag_long' => 'make it featured web site',
    'flag_message' => 'featured',
    'unflag_short' => 'unfeature',
    'unflag_long' => 'remove from featured web site',
    'unflag_message' => 'unfeature',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(),
      'unflag' => array(),
    ),
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'openscholar_front',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function openscholar_front_imagecache_default_presets() {
  $items = array(
    'openscholar_front_logo' => array(
      'presetname' => 'openscholar_front_logo',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '80',
            'height' => '80',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function openscholar_front_node_info() {
  $items = array(
    'sitewide_page' => array(
      'name' => t('Sitewide Page'),
      'module' => 'features',
      'description' => t('A page which can be shown sitewide on an OpenScholar installation, not specific to a vsite.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function openscholar_front_views_api() {
  return array(
    'api' => '2',
  );
}
