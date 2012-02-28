<?php
// $Id;

function formcolumns_ui_front_form($form_state) {
  $form = array();

  $form['add_form'] = array(
    '#type' => 'textfield',
    '#title' => t('Add Form to List'),
    '#description' => t('Enter a path or form_id to add it to list below for editting.'),
    '#maxlength' => 255,
    '#size' => 60,
  );

  $form['submit1'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  $form['container'] = array(
    '#type' => 'markup',
    '#value' => '',
    '#theme' => 'formcolumns_ui_front_form_table',
  );

  // put together a list of all the admin forms available
  //$res = db_query("SELECT form_id FROM {formcolumns_ui_enabled}");
  global $conf;
  $var_names = array_keys($conf);

  $forms = array();
  foreach ($var_names as $v) {
    if (strpos($v, 'formcolumns_setting_') !== FALSE) {
      $forms[] = array(
        'form_id' => $conf[$v]['form_id'],
        'enabled' => $conf[$v]['enabled'],
      );
    }
  }

  //while ($r = db_fetch_array($res)) {
  foreach ($forms as $r) {
    $form['container']['row_'.$r['form_id']]['form_'.$r['form_id']] = array(
      '#type' => 'checkbox',
      '#title' => t($r['form_id']),
      '#default_value' => $r['enabled']?1:0,
      '#theme' => 'formcolumns_ui_enable_checkbox',
    );
    $form['container']['row_'.$r['form_id']]['delete_'.$r['form_id']] = array(
      '#type' => 'checkbox',
      '#title' => t($r['form_id']),
      '#theme' => 'formcolumns_ui_enable_checkbox',
    );
  }
  if (count($form['container']) > 3) {
    $form['submit2'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    );
  }

  return $form;
}

/**
 *
 * Enables or disables selected forms in the database
 * @param array $form
 * @param array $form_state
 */

function formcolumns_ui_front_form_submit($form, &$form_state) {
  foreach ($form['container'] as $key => $field) {
    $frags = explode('_', $key);
    if ($frags[0] != 'row') continue;
    array_shift($frags);
    $key = implode('_', $frags);

    if ($form_state['values']['delete_'.$key]) {
      //db_query("DELETE FROM {formcolumns_ui_enabled} WHERE form_id = '%s'", $key);
      //db_query("DELETE FROM {formcolumns_ui_fields} WHERE form_id = '%s'", $key);
      variable_del('formcolumns_setting_'.$key);
    }
    else {
     //db_query("UPDATE {formcolumns_ui_enabled} SET enabled = %d WHERE form_id = '%s'", $form_state['values']['form_'.$key], $key);
     $temp = variable_get('formcolumns_setting_'.$key, array());
     $temp['enabled'] = $form_state['values']['form_'.$key];
     variable_set('formcolumns_setting_'.$key, $temp);
    }
  }

  if (!empty($form_state['values']['add_form'])) {
    $new_form = $form_state['values']['add_form'];

    $found_form = _formcolumns_ui_form_id_exists($new_form);

    if (!empty($found_form)) {
      // we now have a known existing form_id. insert it.
      // if it's already there, good. Mission accomplished.
      //@db_query("INSERT INTO {formcolumns_ui_enabled} VALUES ('%s', %d, '%s')", $found_form, _formcolumns_ui_is_form_columnized($found_form), _formcolumns_ui_form_parameters($found_form));
      $form_var = array(
        'form_id' => $found_form,
        'enabled' => _formcolumns_ui_is_form_columnized($found_form),
        'params' => _formcolumns_ui_form_parameters($found_form),
      );
      variable_set('formcolumns_setting_'.$found_form, $form_var);
      drupal_set_message(t('Form "@form_id" added to Form Columns', array('@form_id' => $found_form)));
    }
    else {
      drupal_set_message(t('No form found with path "@form_id" or form_id "@form_id"', array('@form_id' =>$form_state['values']['add_form'])), 'error');
    }
  }
}

function formcolumns_ui_config_form($form_state, $form_id) {
  require_once(drupal_get_path('module', 'nodeformcols') . '/nodeformcols.admin.inc');
  $form = array();
  // fields:
  // enabled checkbox
  // default values to use to get form
  // list of regions

  // getting initial parameters and the such
  /*$q = db_query("SELECT form_id, params, page_arguments, enabled FROM {formcolumns_ui_enabled} INNER JOIN {menu_router} WHERE form_id = '%s' AND INSTR(page_arguments, form_id)", $form_id);
  $r = db_fetch_array($q);
  $r['params'] = unserialize($r['params']);
  $r['page_arguments'] = unserialize($r['page_arguments']);
  @array_shift($r['page_arguments']); */

  $r = variable_get('formcolumns_settings_'.$form_id);

  // some initialization if it hasn't been done already
  if (!is_array($r['params'])) {
    $r['params'] = array();
  }

  /*if (!is_array($r['page_arguments'])) {
    $r['page_arguments'] = array();
  }

  foreach ($r['page_arguments'] as $k => $v) {
    if (!isset($r['params'][$k]))
      $r['params'][$k] = '';
  }*/

  // setting #region to 'none' places it out of the columns
  $form['header'] = array(
    '#type' => 'markup',
    '#value' => ucwords(str_replace('_' ,' ', $form_id)),
    '#region' => 'none',
    '#prefix' => '<h2>',
    '#suffix' => '</h2>'
  );

  // tells the form that it's fields will be in columns
  $form['#columns'] = TRUE;

  // building the form

  // puts the enabled field in the right region by default
  $form['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => $r['enabled'],
    '#region' => 'right',
  );

  // and the param fields as well
  if (count($r['params']) > 0) {
    $form['params'] = array(
      '#type' => 'fieldset',
      '#title' => t('Default Parameters'),
      '#value' => '',
      '#region' => 'right',
    );

    foreach ($r['params'] as $key => $param) {
      $form['params'][$key.'_param'] = array(
        '#type' => 'textfield',
        '#title' => t('Parameter #').($key+1),
        '#size' => 60,
        '#default_value' => $r['params'][$key],
      );
    }
  }

  // get the fields in the form
  // as well as their relevant data
  $form_fields = _formcolumns_ui_get_form_fields($form_id, $r['params']);

  // by leaving the #region blank, it is automatically placed in Main
  $form['conf'] = array(
    '#type' => 'markup',
    '#value' => '',
    '#theme' => array('nodeformcols_configuration')
  //  '#theme' => 'formcolumns_config_form_table',
  );

  $options = _formcolumns_regions();
  $options['none'] = 'None';
  foreach ($form_fields as $key => $field) {
    $form['conf'][$field['#region']][$key] = array(
      '#weight' => $field['#weight'],
      $key.'_name' => array(
        '#type' => 'markup',
        '#value' => !empty($field['#title']) ? $field['#title'] : ucwords(str_replace('_', ' ', $key)),
      ),
      $key . '_region' => array(
        '#type' => 'select',
        '#options' => $options,
        '#default_value' => $field['#region'],
        '#attributes' => array(
          'class' => 'field-region-select field-region-'. $field['#region'],
        ),
      ),
      $key . '_weight' => array(
        '#type' => 'textfield',
        '#default_value' => $field['#weight'],
        '#size' => 3,
        '#attributes' => array(
          'class' => 'field-weight field-weight-'. $field['#region'],
        ),
      ),
    );

    if ($field['#collapsible']) {
      $form['conf'][$field['#region']][$key][$key.'_collapsed'] = array(
        '#type' => 'checkbox',
        '#default_value' => $field['#collapsed'],
        '#title' => t('Show Collapsed'),
      );
    }

    if (!_nodeformcols_has_required($field)) {
      $form['conf'][$field['#region']][$key][$key . '_hidden'] = array(
        '#type' => 'checkbox',
        '#title' => t('Hide'),
        '#default_value' => $field['#hidden'],
      );
    }
  }

  $form['column_form_id'] = array(
    '#type' => 'hidden',
    '#value' => $form_id,
  );

  // the submit button goes in the footer region by default
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#region' => 'footer'
  );

  $form['#after_build'][] = '_nodeformcols_configuration_form_after_build';
  //$form['#after_build'][] = '_formcolumns_config_form_after_build';

  return $form;
}

function formcolumns_ui_config_form_submit($form, &$form_state) {

  //$q = db_query("SELECT * FROM {formcolumns_ui_enabled} WHERE form_id = %d", $form_state['values']['column_form_id']);
  //$res = db_fetch_array($q);
  //$res['params'] = unserialize($res['params']);

  $res = variable_get('formcolumns_settings_'.$form_state['values']['column_form_id'], array());

  // runs through each form value

  // each field has one of 4 parameters.
  // the pattern is fieldname_attribute
  // we assume the attribute wont have a _, but the fieldname can have as many as it likes
  // once we know it's an attribute, stick it in the _fields database

  // if its a param, we update the params in the _enabled database
  $res['enabled'] = 0;
  foreach ($form_state['values'] as $field => $value) {
    $frags = explode('_', $field);
    $type = array_pop($frags);
    $field = implode('_', $frags);
    if ($type == 'region' || $type == 'collapsed' || $type == 'hidden' || $type == 'weight') {

      $res['columns'][$field][$type] = $value;
      /*$region = '';
      $collapsed = $hidden = $weight = 0;
      $$type = $value;

      if ($type == 'region') {
        $str = "'%s'";
      }
      else {
        $str = '%d';
      }
      db_query("UPDATE {formcolumns_ui_fields} SET %s = $str WHERE form_id = '%s' AND name = '%s'", $type, $value, $form_state['values']['column_form_id'], $field);
      if (db_affected_rows() <= 0) {
        db_query("INSERT INTO {formcolumns_ui_fields} VALUES ('%s', '%s', '%s', %d, %d, %d)", $form_state['values']['column_form_id'], $field, $region, (int)$weight, (int)$collapsed, (int)$hidden);
      }*/
    }
    elseif ($type == 'param') {
      $res['params'][(int)$field] = $value;
    }
    elseif ($type == 'enabled') {
      $res['enabled'] = 1;
    }
  }

  //db_query("UPDATE {formcolumns_ui_enabled} SET enabled = %d, params = '%s' WHERE form_id = '%s'", $form_state['values']['enabled'], $res['params']?serialize($res['params']):'', $form_state['values']['column_form_id']);
  variable_set('formcolumns_settings_'.$form_state['values']['column_form_id'], $res);
}

/*
 * Not Used
function _formcolumns_config_form_after_build($form) {
  $regions = _formcolumns_regions();
  foreach ($regions as $region => $title) {
    if (is_array($form[$region])) {
      uasort($form[$region], "element_sort");
    }
  //  drupal_add_tabledrag('fields', 'match', 'sibling', 'field-region-select', 'field-region-'. $region, NULL, FALSE);
  //  drupal_add_tabledrag('fields', 'order', 'sibling', 'field-weight', 'field-weight-'. $region);
  }
  return $form;
} */

/**
 *
 * Theme function for the front page of formcolumns
 * Arranges the list of forms into a table
 * @param unknown_type $container
 */

function theme_formcolumns_ui_front_form_table($container) {
  $header = array(t('Name'), t('Enabled'), t('Remove'), t('Edit'));

  $rows = array();
  foreach ($container as $field_name => $field) {
    $frags = explode('_', $field_name);
    if ($frags[0] != 'row') continue;
    array_shift($frags);
    $field_name = implode('_', $frags);

    $row = array();
    $row[] = ucwords(str_replace('_',' ',$field['form_'.$field_name]['#title']));
    $row[] = drupal_render($field['form_'.$field_name]);
    $row[] = drupal_render($field['delete_'.$field_name]);
    $row[] = l('Edit Form', 'admin/settings/forms/'.$field_name);

    $rows[] = $row;
  }

  return theme_table($header, $rows);
}

/**
 * Just unsets the title for the checkbox.
 * @param unknown_type $field
 */

function theme_formcolumns_ui_enable_checkbox($field) {
  unset($field['#title']);

  return theme('checkbox', $field);
}

/**
 * Theme hook for formcolumns_config_form's table
 * @param unknown_type $container

Not used
function theme_formcolumns_config_form_table($container) {

  $headers = array(t('Field'), t('Region'));

  $rows = array();
  foreach ($container as $field_name => $field) {
    if (substr($field_name, 0, 1) == '#') continue;
    $row = array();
    $row[] = ucwords(str_replace(array('_', 'field'), ' ',$field_name));
    $row[] = drupal_render($field);

    $rows[] = $row;
  }

  return theme_table($headers, $rows);
}
*/

/**
 * Helper function
 * gets the form for us
 * stores the form in a var in
 * @param unknown_type $form_id
 * @param unknown_type $parameters
 */
function _formcolumns_ui_get_form($form_id, $parameters = array()) {
  static $form = array();

  if (strpos($form_id, 'node_type_form_') !== FALSE) {
    $type = str_replace('node_type_form_', '', $form_id);
    $form_id = 'node_type_form';

    $q = db_query("SELECT page_arguments FROM {menu_router} WHERE page_arguments LIKE '%%node_type_form%%' AND page_arguments LIKE '%%\"%s\"%%'", $type);
    $r = db_fetch_array($q);
    $parameters = unserialize($r['page_arguments']);
    array_shift($parameters);
  }

  if ($form['form_id']['#value'] == $form_id) {
    return $form;
  }
  if (!is_array($parameters)) {
    $parameters = array();
  }

  $form_state = array(
      'storage' => NULL,
      'submitted' => FALSE,
  );

  if (strpos($form_id, 'node_form') !== FALSE) {
    module_load_include('inc', 'node', 'node.pages');

    $type = str_replace('_node_form', '', $form_id);
    $node = array('uid' => $user->uid, 'name' => (isset($user->name) ? $user->name : ''), 'type' => $type, 'language' => '');
    array_unshift($parameters, $node);
  }
  elseif (!function_exists($form_id)) {
    $q = db_query("SELECT file FROM {menu_router} WHERE page_arguments LIKE '%%%s%%'", $form_id);
    $r = db_fetch_array($q);
    if ($r['file']) {
      include_once($r['file']);
    }
  }

  array_unshift($parameters, $form_id, $form_state);
  $form = call_user_func_array('drupal_retrieve_form', $parameters);
  drupal_prepare_form($form_id, $form, $form_state);
  drupal_get_messages();    // clear any messages that got put up for whatever reason (I.E. Spaces warning cause we're not in a space)

  return $form;
}

/**
 * Helper function
 * Determines if the form id exists or not
 * @param unknown_type $new_form
 */
function _formcolumns_ui_form_id_exists($new_form) {

  $found_form = '';
  if (strpos($new_form, 'node_form') === FALSE && strpos($new_form, 'node_type_form') === FALSE) {
    $closest = '';
    $lev = 500;
    // check to make sure it's a valid path or form_id
    $q = db_query("SELECT path, page_arguments FROM {menu_router} WHERE ( path LIKE '%%%s%%' OR page_arguments LIKE '%%%s%%' )", $new_form, $new_form);
    while ($r = db_fetch_array($q)) {
      $r['page_arguments'] = unserialize($r['page_arguments']);
      if ($r['page_arguments'][0] == $new_form) {
        // we found it in page arguments. add it
        $found_form = $new_form;
        break;
      }
      else {
        // we found it's path. we have to find the closest path match and use that
        $dist = levenshtein($new_form, $r['path']);
        if ($dist == 0) {
          $found_form = $r['page_arguments'][0];
          $lev = 0;
          break;
        }
        elseif ($dist < $lev) {
          $found_form = $r['page_arguments'][0];
          $lev = $dist;
        }
      }
    }
  }

  $form_id = !empty($found_form)?$found_form:$new_form;
  @array_shift($r['page_arguments']);

  $form = _formcolumns_ui_get_form($form_id, $r['page_arguments']);

  return count($form) > 1?$form_id:FALSE;
}

function _formcolumns_ui_unique_form_id($form_id) {
  $form = _formcolumns_ui_get_form($form_id);

  if ($form_id == 'node_type_form') {
    return $form_id.'_'.$form['#parameters'][2]->type;
  }
  return $form_id;
}

function _formcolumns_ui_is_form_columnized($form_id) {
  $form = _formcolumns_ui_get_form($form_id);
  return isset($form['#columns']) && $form['#columns'];
}

function _formcolumns_ui_form_parameters($form_id) {
  $form = _formcolumns_ui_get_form($form_id);
  $parameters = $form['#parameters'];
  @array_shift($parameters);
  @array_shift($parameters);
  return $parameters;
}

/**
 * Gets a flat array of all the fields we want
 * to position.
 * @param unknown_type $form_id
 * @param unknown_type $parameters
 * @param unknown_type $file
 */

function _formcolumns_ui_get_form_fields($form_id, $parameters) {
  if (empty($form_id)) return array();

  // put together args for drupal_retrieve_form
  // it takes form_id, form_state, then the contents of $parameters

  $form = _formcolumns_ui_get_form($form_id, $parameters);

  if (isset($form['#pre_render'])) {
    foreach ($form['#pre_render'] as $function) {
      if (function_exists($function)) {
        $form = $function($form);
      }
    }
  }

  // we have the form
  // filter the top level # parameters out
  // also, any hiddens, values, and tokens

  // while we're at it, look for the field in the database and use its
  // region if its there

  $fields = array();
  $data = variable_get('formcolumns_settings_'.$form_id, array('columns' => array()));
  foreach ($form as $key => $field) {
    // filtering
    if (substr($key, 0, 1) == '#' || substr($key, 0, 8) == 'section_' ||
      $field['#type']=='value' || $field['#type']=='hidden'|| $field['#type']=='token') {
      continue;
    }

    // so we don't bother remembering anything that vertical tabs is gonna make us forget anyway
    if (isset($form['vertical_tabs']['#attached']['js'][0]['data']['verticalTabs'][$key])) continue;

    // Ensure a weight so that we don't have to worry about it later
    $field['#weight'] = isset($field['#weight']) ? (int)$field['#weight'] : 0;

    if (!$field['#region']) {
      // set default region
      $field['#region'] = 'main';
    }
    // check the database - get settings from there if it exists
    //$q = db_query("SELECT region, weight, collapsed, hidden FROM {formcolumns_ui_fields} WHERE form_id = '%s' AND name = '%s' ORDER BY form_id ASC", $form_id, $key);
    //while($r = db_fetch_array($q)) {
    $r = $data['columns'][$key];
      if ($r['region']) {
        $field['#region'] = $r['region'];
      }
      if ($field['#type'] == 'fieldset' && $field['#collapsible']) $field['#collapsed'] = $r['collapsed']?$r['collapsed']:$field['#collapsed'];
      $field['#hidden'] = $r['hidden'];


      $field['#weight'] = $r['weight'];

   // }

    $fields[$key] = $field;
  }

  return $fields;
}