<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_pages_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function scholar_pages_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page'),
      'module' => 'features',
      'description' => t('An html page'),
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
 * Implementation of hook_wysiwyg_fields_icons().
 */
function scholar_pages_wysiwyg_fields_icons() {
  return array(
    drupal_get_path('module', 'scholar_pages') . '/images/wysiwyg_fields',
  );
}
