<?php
//$Id: apachesolr_biblio.admin.inc,v 1.1 2009/09/23 12:18:20 robertDouglass Exp $
function apachesolr_biblio_fields_form($form_state) {
  $defaults = apachesolr_biblio_get_fields();
  $form['contributors'] = array(
    '#type' => 'checkbox',
    '#title' => t('Contributors'),
    '#description' => t('Should authors be indexed? This feature is either on or off. No control is given to index some author types and not others.'),
    '#default_value' => $defaults['contributors'],
  );

  $fields = apachesolr_biblio_get_raw_fields();
  $form['configured_flds'] = array('#tree' => 1);
  foreach ($fields as $key => $fld) {
    // If a string contains the word "author", it's
    // a multiple string that gets packed into "contributors".
    // These get handled all at once, basically, so we ignore them.
    if (strpos($fld['name'], 'author')) continue;

    $form['configured_flds'][$key]['display_name'] = array(
      '#type' => 'item',
      '#value' => $fld['name'],
      '#weight' => $fld['weight'],
    );
    $form['configured_flds'][$key]['name'] = array(
      '#type' => 'value',
      '#value' => $fld['name'],
    );
    $form['configured_flds'][$key]['title'] = array(
      '#type' => 'item',
      '#value' => $fld['title'],
      '#weight' => $fld['weight'],
    );
    $options = array();
    if (isset($defaults[$key]['indexed']) && $defaults[$key]['indexed']) {
      $options[] = 'indexed';
    }
    $form['configured_flds'][$key]['checkboxes'] = array(
      '#type' => 'checkboxes',
      '#options' => array('indexed' => ''),
      '#default_value' => $options,
      '#weight' => $fld['weight'],
    );
    $form['configured_flds'][$key]['index_type'] = array(
      '#type' => 'select',
      '#options' => array('string' => t('String'), 'date' => t('Date')),
      '#multiple' => FALSE,
      '#default_value' => (isset($defaults[$key]['index_type']) ? $defaults[$key]['index_type'] : 'string'),
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save')
  );

  return $form;
}

function theme_apachesolr_biblio_fields_form($form) {
  $output  = drupal_render($form['contributors']);

  $conf_table = array();
  foreach (element_children($form['configured_flds']) as $fld) {
    $form['configured_flds'][$fld]['weight']['#attributes']['class'] = 'weight';
    $conf_row = array();
    $conf_row[] = array('data' => drupal_render($form['configured_flds'][$fld]['display_name']));
    $conf_row[] = array('data' => drupal_render($form['configured_flds'][$fld]['title']));
    foreach (element_children($form['configured_flds'][$fld]['checkboxes']) as $oid) {
      if (is_array($form['configured_flds'][$fld]['checkboxes'])) {
        $conf_row[] = array(
          'data' => drupal_render($form['configured_flds'][$fld]['checkboxes'][$oid]),
          'title' => $oid);
      }
    }
    $conf_row[] = array('data' => drupal_render($form['configured_flds'][$fld]['index_type']));
    $conf_table[] = array('data' => $conf_row);
  }

  $header = array(t('Field Name'), t('Title'), t('Index'), t('Data type'));

  $output .= theme('table', $header, $conf_table, array('id' => 'field-table'));
  $output .= drupal_render($form['submit']);
  $output .= drupal_render($form);
  return $output;
}

function apachesolr_biblio_fields_form_submit($form, $form_state) {
  db_query('DELETE FROM {apachesolr_biblio_fields');
  foreach($form_state['values']['configured_flds'] as $fid => $field) {
    $record = new stdClass();
    $record->fid = $fid;
    $record->name = $field['name'];
    $record->index_type = $field['index_type'];
    $record->indexed = ($field['checkboxes']['indexed'] == '0' ? 0 : 1);
    drupal_write_record('apachesolr_biblio_fields', $record);
    variable_set('apachesolr_biblio_index_authors', $form_state['values']['contributors']);
  }
}
