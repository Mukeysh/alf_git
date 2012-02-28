<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_software_ctools_plugin_api() {
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
function scholar_software_node_info() {
  $items = array(
    'scholar_software_project' => array(
      'name' => t('Software Project'),
      'module' => 'features',
      'description' => t('A software project page. Provides a summary of project information and releases for download.'),
      'has_title' => '1',
      'title_label' => t('Project'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'scholar_software_release' => array(
      'name' => t('Software Release'),
      'module' => 'features',
      'description' => t('A single release package for a given project.'),
      'has_title' => '1',
      'title_label' => t('Release'),
      'has_body' => '1',
      'body_label' => t('Notes'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function scholar_software_views_api() {
  return array(
    'api' => '2',
  );
}

/**
 * Implementation of hook_wysiwyg_fields_icons().
 */
function scholar_software_wysiwyg_fields_icons() {
  return array(
    drupal_get_path('module', 'scholar_software') . '/images/wysiwyg_fields',
  );
}
