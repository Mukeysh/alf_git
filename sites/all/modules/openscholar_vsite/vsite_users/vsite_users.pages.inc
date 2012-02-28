<?php
function vsite_users_members() {
  //drupal_add_css(drupal_get_path('module', 'vsite_users') . '/theme/vsite_users.css');
  $site = vsite_get_vsite();
  $arg = $site->group->nid;
  ctools_include('ajax');
  ctools_include('modal');
  drupal_add_js('misc/autocomplete.js');
  ctools_add_js('dependent');
  ctools_modal_add_js();

  $output = ctools_modal_text_button('Add a user to your site', 'cp/users/add', 'add a user', 'context-button');
  $output = theme('item_list', array(
    $output
  ), $title = NULL, $type = 'ul', $attributes = array(
    "class" => "context-links"
  ));

  $output .= views_page('og_members', 'default', $arg);
  return $output;
}

/**
 * Some function are used to render the user edit page
 */
require_once(drupal_get_path('module', 'user') .'/user.pages.inc');

/**
 * callback function for user edit popup form
 */
function vsite_users_edit_user($account) {
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();

  drupal_add_js('misc/jquery.form.js');
  drupal_add_js('misc/ahah.js');

  $form_state = array(
    're_render' => TRUE,
    'ajax' => TRUE,
  );

  // pass all arguments needed
  $form_state['args'] = array($account, 'account');

  $output = ctools_modal_form_wrapper('user_profile_form', $form_state);

  if (empty($output)) {
    $output = array();
    drupal_get_messages();
    drupal_set_message(t('The changes to the user account have been saved.'));
    $output[] = ctools_ajax_command_reload();
  }

  ctools_ajax_render($output);
}

/**
 * callback function for our popup user add
 */
function vsite_users_add_user() {
  ctools_include('ajax');
  ctools_include('modal');

  $form_state = array(
    're_render' => FALSE,
    'ajax' => TRUE,
  );

  // pass all arguments needed by the callback function (ctools thing)
  $form_state['args'] = array(NULL);

  $output = ctools_modal_form_wrapper('ucreate_user_form', $form_state);

  if (empty($output)) {
    $output = array();
    $output[] = ctools_modal_command_dismiss();  //close the modal pop-up
    $output[] = ctools_ajax_command_reload();  //reload the parent window to display the confirmation message
  }
  else {
    //$output[0]['output'] = "<div style='wdith:550px;float:left;'>".$output[0]['output']."</div><div id='user_lookup' style='float:left;'>This is for good</div>";
  }

  ctools_ajax_render($output);
}



/**
 * callback function for our user lookup
 */
function vsite_users_lookup_user($string = '') {
  $a_profile_content_types = content_profile_get_types();
  $a_info = content_types();
  $s_join_statement = "";
  $s_field = "CONCAT(name,' (',mail,')')";
  $a_join_where = array();
  $n_num_param = 1;

  $matches = array();
  if ($string) {

    foreach ($a_profile_content_types as $s_type => $info) {
      if (!array_key_exists('vsite_users_last_name', $a_info[$s_type]['fields'])) continue;

      $s_join_statement .= " LEFT JOIN node n ON n.uid = users.uid ";
      $table_info = content_database_info($a_info[$s_type]['fields']['vsite_users_last_name']);
      $s_table = $table_info['table'];
      $s_join_statement .= " LEFT JOIN {$s_table} {$s_table} ON {$s_table}.nid = n.nid ";

      foreach (array('vsite_users_last_name', 'vsite_users_first_name') as $fld) {
        $n_num_param++;
        $a_join_where[] = 'LOWER(' . $s_table . "." . $a_info[$s_type]['fields'][$fld]['field_name'] . "_value) LIKE LOWER('%s%%')";
      }

      $s_field = 'IF(' . $s_table . "." . $a_info[$s_type]['fields']['vsite_users_last_name']['field_name'] . '_value IS NULL, CONCAT(name,\' (\',mail,\')\'),CONCAT(' . $s_table . "." . $a_info[$s_type]['fields']['vsite_users_first_name']['field_name'] . '_value," ",' . $s_table . "." . $a_info[$s_type]['fields']['vsite_users_last_name']['field_name'] . '_value," (",mail,")")) as name ';
      break;
    }
    $n_num_param++;
    $a_join_where[] = "LOWER(mail) LIKE LOWER('%s%%')";

    $s_where = count($a_join_where)? " OR " . join(" OR ", $a_join_where):"";

    $result = db_query_range("SELECT name as id, {$s_field} FROM {users} users {$s_join_statement} WHERE LOWER(name) LIKE LOWER('%s%%') " . $s_where, split("@@", str_repeat($string . "@@", $n_num_param)), 0, 10);
    while ($user = db_fetch_object($result)) {
      $matches[$user->id] = check_plain($user->name);
    }
  }

    static $vsite, $group, $admin;
    $admin = db_result(db_query("SELECT name FROM {users} WHERE uid = %d", 1));
    if (!is_object($vsite)) $vsite= vsite_get_vsite();
    //existing members should be excluded from select list
    if (!is_array($group)) {
      $group[$admin] = $admin; //admin is not group a member but should also be excluded from select list
      $result = db_query("SELECT ou.nid, u.name as name FROM {og_uid} ou RIGHT JOIN {users} u USING (uid) HAVING ou.nid = %d", $vsite -> group -> nid);
      while ($members = db_fetch_object($result)) {
        $group[$members -> name] = $members -> name;
      }
    }
    //filter out users who are already in the group
    $filtered_matches = array_diff_key($matches, $group);
    drupal_json($filtered_matches);
}
