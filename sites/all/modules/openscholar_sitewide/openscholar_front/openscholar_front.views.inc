<?php
/**
 * Implementation of hook_views_handlers().
 */
function openscholar_front_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'openscholar_front') .'/views',
    ),
    'handlers' => array(
      'openscholar_front_handler_field_node' => array(
        'parent' => 'spaces_handler_field_node',
      ),
      'openscholar_front_handler_field_logo' => array(
        'parent' => 'file_aliases_content_handler_field_multiple',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data_alter().
 */
function openscholar_front_views_data_alter(&$data) {
  // Iterate through Views data and replace instances of
  // spaces_handler_field_node with vsite node handler.
  foreach ($data as $table => $data_table) {
    foreach ($data_table as $field => $data_field) {
      if (isset($data_field['field']['handler']) && $data_field['field']['handler'] === "file_aliases_content_handler_field_multiple") {
        $data[$table][$field]['field']['handler'] = 'openscholar_front_handler_field_logo';
      }
      if (isset($data_field['field']['handler']) && $data_field['field']['handler'] === 'spaces_handler_field_node') {
        $data[$table][$field]['field']['handler'] = 'openscholar_front_handler_field_node';
      }
    }
  }
  
}