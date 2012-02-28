<?php
// $Id$

/**
 * @file
 * Import/Export functionality provided by ApacheSolr Biblio module.
 */

/**
 * Export a field to code.
 *
 * @param $fields
 *   An array of fields, or field name.
 * @param $module
 *   Optional. The name of the module that will be created if exporting to use
 *   in hook_default_biblio_fields().
 */
function apachesolr_biblio_export_fields($fields = array(), $module = '') {
  $output = '$fields = array();'. "\n";
  foreach ($fields as $fid => $field) {
    if (!is_array($field)) {
      // Load the field definition
      $field = apachesolr_biblio_get_field($field);
    }
    if(!empty($field)) {
      $output .= '// Exported field: "'. $field['name'] . '"' . ".\n";
      $output .= '$fields[] = ' . var_export($field, TRUE) . ";\n";
    }
  }
  $output .= 'return $fields;';
  return $output;
}

/**
 * Form to import default ApacheSolr Biblio fields
 */
function apachesolr_biblio_default_fields_import_form() {
  $form = array();

  $form['import'] = array(
    '#title' => t('ApacheSolr Biblio default fields import code'),
    '#type' => 'textarea',
    '#default_value' => '',
    '#rows' => 15,
    '#required' => TRUE,
    '#description' => t('Paste the code from an <a href="@export-url">ApacheSolr Biblio fields export</a> here to import it into you site. Fields imported with the same name will update existing fields. Fields with a new name will be created.', array('@export-url' => url('admin/settings/biblio/solr/export'))),
  );
  $form['submit'] = array(
    '#value' => t('Import'),
    '#type' => 'submit',
  );

  return $form;
}

/**
 * Validate handler; Import default ApacheSolr Biblio fields.
 */
function apachesolr_biblio_default_fields_import_form_validate($form, &$form_state) {
  $fields = array();
  ob_start();
  eval($form_state['values']['import']);
  ob_end_clean();

  if (!isset($fields) || !is_array($fields)) {
    form_set_error('import', t('A valid list of fields could be found in the import code.'));
    return;
  }

  $form_state['fields'] = $fields;
}

/**
 * Submit handler; Import default ApacheSolr Biblio fields.
 */
function apachesolr_biblio_default_fields_import_form_submit($form, &$form_state) {
  foreach ($form_state['fields'] as $default_field) {
    db_query("UPDATE {apachesolr_biblio_fields} SET name = '%s', index_type = '%s', indexed = %d WHERE fid = %d", $default_field['name'], $default_field['index_type'], $default_field['indexed'], $default_field['fid']);
    if (!db_affected_rows()) {
      db_query("INSERT INTO {apachesolr_biblio_fields} (fid, name, index_type, indexed) VALUES (%d, '%s', '%s', %d)", $default_field['fid'], $default_field['name'], $default_field['index_type'], $default_field['indexed']);
      drupal_set_message(t('Field @name has been imported.', array('@name' => $default_field['name'])));
    }
    else {
      drupal_set_message(t('Field @name has been updated.', array('@name' => $default_field['name'])));
    } 
  }
  $form_state['redirect'] = 'admin/settings/biblio/solr';
}

/**
 * Export a field and display it in a form.
 */
function apachesolr_biblio_default_fields_export_form(&$form_state, $field = NULL) {
  $form = array();

  // Convert a field name (if any) to the list of export fields.
  if (is_object($field) || ($field = apachesolr_biblio_get_field($field))) {
    $field = array($field);
  }

  // Display a list of fields to export.
  if (!isset($fields)) {
    if (isset($form_state['values']['fields'])) {
      $fields = array();
      foreach ($form_state['values']['fields'] as $field_name) {
        if ($field_name && $field = apachesolr_biblio_get_field($field_name)) {
          $fields[] = $field;
        }
      }
    }
    else {
      $fields = apachesolr_biblio_get_fields();
      unset($fields['contributors']);
      $options = array();
      foreach($fields as $fid => $field) {
        $options[$fid] = $field['name'];
      }
      $form['fields'] = array(
        '#type' => 'checkboxes',
        '#title' => t('Fields to export'),
        '#options' => drupal_map_assoc($options),
        '#description' => t('Exporting your fields is useful for moving fields from one site to another, or when including your field definitions in a module.'),
      );
      $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Export'),
      );
    }
  }

  if (isset($fields)) {
    $code = apachesolr_biblio_export_fields($fields);

    // Link to the Features page if module is present, otherwise link to the
    // Drupal project page.
    $features_link = module_exists('features') ? url('admin/build/features') : url('http://drupal.org/project/features');

    $form['export'] = array(
      '#type' => 'textarea',
      '#title' => t('ApacheSolr Biblio field exports'),
      '#description' => t('Use the exported code to later <a href="@import-field">import</a> it. Exports can be included in modules using hook_apachesolr_biblio_default_fields() or using the <a href="@features-url">Features</a> module.', array('@import-field' => url('admin/settings/biblio/solr/import'), '@features-url' => $features_link)),
      '#value' => $code,
      '#rows' => 15,
    );
  }

  return $form;
}

/**
 * Submit handler; Rebuild the export form after the list of fields has been set.
 */
function apachesolr_biblio_default_fields_export_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}
