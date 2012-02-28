<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function vsite_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => 1);
  }
  elseif ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function vsite_imagecache_default_presets() {
  $items = array(
    'square_35_35' => array(
      'presetname' => 'square_35_35',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '35',
            'height' => '35',
          ),
        ),
      ),
    ),
    'square_50_50' => array(
      'presetname' => 'square_50_50',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '50',
            'height' => '50',
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
function vsite_node_info() {
  $items = array(
    'vsite' => array(
      'name' => t('Scholar site'),
      'module' => 'features',
      'description' => t('Represent a Virtual Web Site'),
      'has_title' => '1',
      'title_label' => t('Site title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function vsite_views_api() {
  return array(
    'api' => '2',
  );
}
