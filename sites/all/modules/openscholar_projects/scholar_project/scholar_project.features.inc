<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_project_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function scholar_project_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project Web Site'),
      'module' => 'features',
      'description' => t('Represents a Project Web Site'),
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
