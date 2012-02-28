<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_biocv_ctools_plugin_api() {
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
 * Implementation of hook_node_info().
 */
function scholar_biocv_node_info() {
  $items = array(
    'bio' => array(
      'name' => t('bio'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Bio'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'cv' => array(
      'name' => t('cv'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('cv'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_wysiwyg_fields_icons().
 */
function scholar_biocv_wysiwyg_fields_icons() {
  return array(
    drupal_get_path('module', 'scholar_biocv') . '/images/wysiwyg_fields',
  );
}
