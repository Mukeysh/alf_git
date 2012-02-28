<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_reader_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => 1);
  }
  elseif ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "data" && $api == "data_default") {
    return array("version" => 1);
  }
  elseif ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function scholar_reader_node_info() {
  $items = array(
    'feed' => array(
      'name' => t('Feed'),
      'module' => 'features',
      'description' => t('Items from these feeds will be turned into nodes.'),
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
function scholar_reader_views_api() {
  return array(
    'api' => '2',
  );
}
