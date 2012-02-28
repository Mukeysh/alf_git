<?php

/*
 * @file
 * Hooks and implementations for Features
 */

/**
 * Implementation of hook_features_export_options.
 */
function form_columns_config_features_export_options() {
  $options = array();
   $q = db_query("SELECT form_id FROM {formcolumns_enabled} WHERE enabled = 1");

  while ($r = db_fetch_array($q)) {
    $options[$r['form_id']] = ucwords(str_replace('_', ' ', $r['form_id']));
  }
  return $options;
}

/**
 * Implementation of hook_features_export
 */
function form_columns_config_features_export($data, &$export, $module_name) {
  $export['dependencies']['formcolumns'] = 'formcolumns';

  foreach ($data as $component) {
    $export['features']['form_columns_config'][$component] = $component;
  }

  return array();
}

/**
 * Implementation of hook_features_export_render.
 */
function form_columns_config_features_export_render($module_name, $data, $export = NULL) {
  $code = array();
  $code[] = '  $form_column_configs = array();';
  $code[] = '';
  foreach ($data as $form_id) {
    $item = _form_columns_config_get_data($form_id);
    if (isset($item[$form_id])) {
      $code[] = '  $form_column_configs[] = '.features_var_export($item,'  ').';';
    }
  }
  $code[] = '  return $form_column_configs;';
  $code = implode("\n", $code);
  return array('form_columns_config_features_default_settings' => $code);
}

/**
 * Gets the form config into an array
 * @param unknown_type $name
 */
function _form_columns_config_get_data($form_id) {
  $form = array();
  $q = db_query("SELECT * FROM {formcolumns_fields} INNER JOIN {formcolumns_enabled} USING(form_id) WHERE form_id = '%s'", $form_id);
  while ($r = db_fetch_array($q)) {
    $form[$r['form_id']][$r['name']]['region'] = $r['region'];
    $form[$r['form_id']][$r['name']]['weight'] = $r['weight'];
    $form[$r['form_id']][$r['name']]['collapsed'] = $r['collapsed'];
    $form[$r['form_id']][$r['name']]['hidden'] = $r['hidden'];
    $form[$r['form_id']]['#enabled'] = $r['enabled'];
  }

  return $form;
}

/**
 * Implementation of hook_features_rebuild().
 */
function form_columns_config_features_rebuild($module) {
  if (module_exists('formcolumns_ui')) {
    $items = module_invoke($module, 'form_columns_config_features_default_settings');
    foreach ($items as $idx => $item) {
      $saved = _form_columns_config_set_data($item);
    }
  }
}

/**
 * Puts the form config data into the database
 */
function _form_columns_config_set_data($item) {
  $form_id = key($item);
  if(!@db_query("INSERT INTO {formcolumns_enabled} SET form_id = '%s', enabled = %d", $form_id, $item[$form_id]['#enabled'])) {
    db_query("UPDATE {formcolumns_enabled} SET enabled = %d WHERE form_id = '%s'", $item[$form_id]['#enabled'], $form_id);
  }
  foreach ($item[$form_id] as $field_name => $data) {
    if ($field_name != '#') {
      if(!@db_query("INSERT INTO {formcolumns_fields} SET form_id = '%s', name = '%s', region = '%s', weight = %d, collapsed = %d, hidden = %d", $form_id, $field_name, $data['region'], $data['weight'], $data['collapsed'], $data['hidden'])) {
        db_query("UPDATE {formcolumns_fields} SET region = '%s', weight = %d, collapsed = %d, hidden = %d WHERE form_id = '%s' AND name = '%s'", $data['region'], $data['weight'], $data['collapsed'], $data['hidden'], $form_id, $field_name);
      }
    }
  }
}

/**
 * Implementation of hook_features_revert.
 */
function form_columns_config_features_revert($module) {
  form_columns_config_features_rebuild($module);
}