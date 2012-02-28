<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_profiles_ctools_plugin_api() {
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
function scholar_profiles_node_info() {
  $items = array(
    'person' => array(
      'name' => t('Person'),
      'module' => 'features',
      'description' => t('Represents a profile / person'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Short bio'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function scholar_profiles_views_api() {
  return array(
    'api' => '2',
  );
}

/**
 * Implementation of hook_wysiwyg_fields_icons().
 */
function scholar_profiles_wysiwyg_fields_icons() {
  return array(
    drupal_get_path('module', 'scholar_profiles') . '/images/wysiwyg_fields',
  );
}
