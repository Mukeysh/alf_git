<?php

/**
 * @file
 * Features integration for ApacheSolr Biblio module.
 */

/**
 * Implementation of hook_features_export().
 */
function apachesolr_biblio_features_export($data, &$export, $module_name = '') {
  $pipe = array();

  // Add biblio module as a dependency.
  $export['dependencies']['features'] = 'biblio';
  foreach ($data as $fid => $field) {
    if ($solr_field = apachesolr_biblio_get_field(null, $fid)) {
      $export['features']['apachesolr_biblio_field'][$solr_field['name']] = $solr_field['name'];
    }
  } 
  return $pipe;
}

/**
 * Implementation of hook_features_export_options().
 */
function apachesolr_biblio_features_export_options() {
  $options = array();
  // Get all fields.
  $fields = apachesolr_biblio_get_fields();
  unset($fields['contributors']);
  foreach ($fields as $fid => $field) {
    $options[$field['name']] = $field['name'];
  }
  return $options;
}

/**
 * Implementation of hook_features_export_render().
 */
function apachesolr_biblio_features_export_render($module = 'foo', $data, $features_export) {
  module_load_include('inc', 'apachesolr_biblio', '/apachesolr_biblio.export');
  $code = apachesolr_biblio_export_fields($data, $module);
  return array('default_biblio_fields' => $code);
}

/**
 * Implementation of hook_features_revert().
 *
 * @param $module
 *   The name of module for which to revert content.
 */
function apachesolr_biblio_features_revert($module = NULL) {
  drupal_set_message('Module = '.$module);
  // Get default fields from features.
  if (module_hook($module, 'default_biblio_fields')) {
    $default_fields = module_invoke($module, 'default_biblio_fields');

    // Reset fields that are defined in code.
    foreach ($default_fields as $default_field) {
      db_query("UPDATE {apachesolr_biblio_fields} SET name = '%s', index_type = '%s', indexed = %d WHERE fid = %d", $default_field['name'], $default_field['index_type'], $default_field['indexed'], $default_field['fid']);
      if (!db_affected_rows()) {
        db_query("INSERT INTO {apachesolr_biblio_fields} (fid, name, index_type, indexed) VALUES (%d, '%s', '%s', %d)", $default_field['fid'], $default_field['name'], $default_field['index_type'], $default_field['indexed']);
      }
    }
  }
  else {
    return FALSE;
  }
  return TRUE;
}
