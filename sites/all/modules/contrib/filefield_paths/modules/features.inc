<?php
/**
 * @file additional routines to add 'Features' exportable support to this
 * module.
 *
 * Per-field filefield_path preferences can be selected to be packaged within a
 * feature bundle.
 *
 * This will happen automatically when using features to export a content type,
 * or an individual field, or can be chosen to be packaged on its own.
 *
 * @author dman dan@coders.co.nz 2010-11
 *
 * (An experiment with getting features more widely supported)
 */

/**
 * Implementation of hook_features_export_options().
 *
 * List all filefield_paths config settings currently available for export. This
 * adds each of the configurations to the features UI where they can be chosen
 * for bundling.
 *
 * This UI may be entirely unneccessary if we only ever export as a part of
 * something else (individual fields settings), but it's here for completeness.
 *
 * @return array A keyed array of items, suitable for use with a FormAPI select
 * or checkboxes element.
 *
 **/
function filefield_paths_item_features_export_options() {
  $options = array();
  $sql = db_rewrite_sql("SELECT * FROM {filefield_paths}");
  $result = db_query($sql);
  while ($row = db_fetch_array($result)) {
    // Generate the unique keys that can identify the row
    // "{node_type}-{field}" eg "story-field_illustration"
    $key = "{$row['type']}-{$row['field']}";
    $options[$key] = $key;
  }
  return $options;
}


/**
 * Implementation of hook_features_export().
 *
 * Process the export array for a given component.
 *
 * Normally, we will be adding this as a child in the pipe of
 * content_features_export, so that when a filefield instance is exported, this
 * setting was published along with it.
 */
function filefield_paths_item_features_export($data, &$export, $module_name = '') {
  $export['dependencies']['filefield_paths'] = 'filefield_paths';

  foreach ($data as $identifier) {
    if ($wrapper = filefield_paths_item_load($identifier)) {
      $export['features']['filefield_paths_item'][$identifier] = $identifier;
      if ($wrapper['filename']['transliterate'] || $wrapper['filepath']['transliterate']) {
        $export['dependencies']['transliteration'] = 'transliteration';
      }
      if ($wrapper['filename']['pathauto'] || $wrapper['filepath']['pathauto']) {
        $export['dependencies']['pathauto'] = 'pathauto';
      }
      if (module_exists('strongarm')) {
        $pipe = array();
        $variable_map = features_get_default_map('variable');
        $variable_name = 'ffp_' . $wrapper['type'] . '_' . $wrapper['field'];
        $pipe['variable'][] = $variable_name;
      }
    }
  }
  return $pipe;
}

/**
 * Attach our own export routine as a piped export that happens below any cck
 * filefield path that is getting exported.
 *
 * The component name for cck fields is 'content'
 *
 * HOOK_features_pipe_COMPONENT_alter()
 *
 * This captures each cck field export, and adds ourself to the dependencies and
 * exports when that field is exported.
 */
function filefield_paths_features_pipe_content_alter(&$pipe, $data, $export) {
  foreach ($data as $field_identifier) {

    // CCK field export is exporting a field named $field_identifier.
    // If that is a filefield, we should attach ourselves as a subprocess (pipe).
    // .. actually, don't need to check the field type,
    // just see if we have some filefield_path
    // settings that use the same $field_identifier key!

    if (filefield_paths_item_load($field_identifier)) {
      // So add this setting as a piped child of the filed when it gets exported.
      $pipe['filefield_paths_item'][$field_identifier] = $field_identifier;
    }
  }
}

/**
 * Implementation of hook_features_export_render()
 *
 * Return the PHP code that represents a dump of the settings listed as $data
 */
function filefield_paths_item_features_export_render($module, $data) {
  $code = array();
  $code[] = '  $settings = array();';
  $code[] = '';

  $translatables = array();
  foreach ($data as $item_id) {
    $item = filefield_paths_item_load($item_id);
    if (empty($item)) {
      watchdog('filefield_paths', "When trying to prepare the export code, failed to retrieve the filefield path settings '%item_id'. Odd.", array('%item_id' => $item_id), WATCHDOG_WARNING);
      continue;
    }
    $code[] = "  // Exported {$item_id}";
    $export = features_var_export($item, '  ');
    $code[] = "  \$settings['{$item_id}'] = {$export};";
  }

  $code[] = '';
  $code[] = '  return $settings;';
  $code = implode("\n", $code);
  return array('filefield_paths_item_default_items' => $code);
}

/**
 * Implementation of hook_features_export_revert().
 */
function filefield_paths_item_features_revert($module) {
  filefield_paths_item_features_rebuild($module);
}

/**
 * Create/recreate the items based on the data array. Data should contain a
 * number of filefield_paths_item definitions.
 *
 * Implementation of hook_features_export_rebuild().
 *
 * Data just need to be put straight into the database as rows.
 */
function filefield_paths_item_features_rebuild($module) {
  if ($defaults = features_get_default('filefield_paths_item', $module)) {
    foreach ($defaults as $filefield_paths_id => $filefield_paths_item) {
      // Delete any previous settings for this item.
      if (filefield_paths_item_load($filefield_paths_id)) {
        filefield_paths_item_delete($filefield_paths_id);
      }
      drupal_write_record('filefield_paths', $filefield_paths_item);
    }
  }
}
