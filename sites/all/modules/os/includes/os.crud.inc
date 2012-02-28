<?php

// VSite

/**
 * Add a vsite
 *
 * @param $name the username (site owner)
 * @param $mail the e-mail address of the user creating the site
 * @param $domain the domain name of the site
 * @return the node object if successful
 *
 */
function os_create_vsite($name, $domain, $preset){
  $properties = array(
      'name' => $name,
      'type' => variable_get('scholar_content_type', 'vsite'),
      'promote' => '0',
      'purl' => array(
          'value' => $domain,
          'provider' => 'vsite_og',
          'id' => NULL
      ),
      'spaces_preset_og' => $preset,
      'og_description' => "$domain's web site",
      //now set in nodeapi  'theme' => 'scholar_airstream',  // @todo $preset -> theme_detault
  );
  $vsite = os_create_node($domain, NULL, $properties);
  $vsite = spaces_load('og', $vsite->nid, true);
  return $vsite;
}


// User

/**
 * Add a user.
 *
 * @param $username
 *   User's username name.
 * @param $password
 *   User's plain-text password.
 * @param $email
 *   User's e-mail address.
 * @param $roles
 *   An array of role names to which the user should be assigned.
 *   For example: array('staff', 'moderator')
 * @param $status
 *   User's status. 1 = active, 0 = blocked.
 */
function os_add_user($username, $password, $email, $roles = array(), $status = 1) {
  $role_assignments = array();
  // Translate array of names into rid => name that user_save() is expecting.
  if (!empty($roles)) {
    foreach ($roles as $name) {
      $rid = os_get_rid($name);
      $role_assignments[$rid] = $name;
    }
  }

  return user_save(
    new stdClass(),
    array(
      'name' => $username,
      'pass' => $password,
      'mail' => trim($email),
      'roles' => $role_assignments,
      'status' => $status
    )
  );
}




/**
 * Add a user to a role.
 */
function os_add_user_to_role($uid, $rid) {
  if ($uid <= 0 || $rid <= 0) {
    return FALSE;
  }

  $count = db_result(db_query("SELECT COUNT(uid) FROM {users_roles} WHERE uid = %d AND rid = %d", $uid, $rid));
  if ($count == 0) {
    return db_query("INSERT INTO {users_roles} (uid, rid) VALUES (%d, %d)", $uid, $rid);
  }

  return FALSE;
}

/**
 * Add a role to the roles table.
 */
function os_add_role($name) {
  // Check to see if role already exists. If not, create it.
  $rid = os_get_rid($name);
  if (!$rid) {
    db_query("INSERT INTO {role} (name) VALUES ('%s')", $name);
  }

  return ($rid) ? $rid : os_get_rid($name);
}

/**
 * Get the role ID for the role name.
 */
function os_get_rid($name) {
  static $roles = array();
  if (empty($roles[$name])) {
    $roles[$name] = db_result(db_query_range("SELECT rid FROM {role} WHERE name ='%s'", $name, 0, 1));
  }
  return $roles[$name];
}


/**
 * Add the permission for a certain role.
 */
function os_add_permissions($rid, $perms) {
  // Retrieve the currently set permissions.
  $result = db_query("SELECT p.perm FROM {role} r INNER JOIN {permission} p ON p.rid = r.rid WHERE r.rid = %d ", $rid);
  $existing_perms = array();
  while ($row = db_fetch_object($result)) {
    $existing_perms += explode(', ', $row->perm);
  }
  // If this role already has permissions, merge them with the new permissions being set.
  if (count($existing_perms) > 0) {
    $perms = array_unique(array_merge($perms, (array)$existing_perms));
  }

  // Update the permissions.
  db_query('DELETE FROM {permission} WHERE rid = %d', $rid);
  db_query("INSERT INTO {permission} (rid, perm) VALUES (%d, '%s')", $rid, implode(', ', $perms));
}


// NODE

/**
 * Given an array of custom properties, save a node. This function is
 * written to be self-documenting, as it explicitly lists the properties
 * you can set, and shows the defaults if you don't set them.
 *
 * @param $properties
 *   Optional. An array of properties that describe the node.
 */
function os_save_node($properties = array()) {

  // If name has been passed as a property, convert it to a uid.
  if (isset($properties['name'])) {
    if (!($account = user_load(array('name' => $properties['name'])))) {
      drupal_set_message(t('Failed to load Drupal user %user -- node %title not saved.', array('%name' => $properties['name'], '%title' => $properties['title'])), 'error', FALSE);
      return;
    }
  }

  $default = array(
    'nid' => isset($properties['nid']) ? $properties['nid'] : NULL, // Defaults to NULL, which creates a new node.
    'title' => !empty($properties['title']) ? $properties['title'] : '-- no title--', // Defaults to '-- no title --'.
    'body' => NULL, // Defaults to no body.
    'type' => 'page',
    'teaser' => NULL,
    'log' => '',
    'created' => '',
    'format' => FILTER_FORMAT_DEFAULT,
    'uid' => isset($account) ? $account->uid : 0,

  );
  $node = array_merge($default, $properties);

  $node = (object) $node;
  node_save($node);
  $node = node_load($node->nid, NULL, TRUE);  // force a reloading of the node

  return $node;
}


/**
 * Given a title and body, and an array of custom properties, create
 * a node.
 *
 * @param $title
 *   Optional. The node title.
 * @param $body
 *   Optional. The node body.
 * @param $properties
 *   Optional. An array of properties that describe the node.
 */
function os_create_node($title = NULL, $body = NULL, $properties = array()) {
  $properties['nid'] = NULL; // Force creation of new node.
  $properties['title'] = $title;
  $properties['body'] = $body;
  $node = os_save_node($properties);
  return $node;
}


// FILTERS


/**
 * Set the roles that can be used with the filter.
 *
 * @param $roles
 *   An array of role IDs.
 * @param $format_id
 *   An integer of the format ID.
 */
function os_format_set_roles($roles, $format_id) {
  $roles = implode(',',$roles);
  // Drupal core depends on the list of roles beginning and ending with commas.
  if (!empty($roles)) {
    $roles = ','. $roles .',';
  }
  db_query("UPDATE {filter_formats} SET roles = '%s' WHERE format = %d", $roles, $format_id);
}

/**
 * Add a new input format .
 *
 * @param $name
 *   The human-readable name of the new format.
 * @param $cache
 *   If this format is cacheable.
 * @return
 *   The new format ID.
 */
function os_add_format($name, $cache = 1) {
  db_query("INSERT INTO {filter_formats} (name, roles, cache) VALUES ('%s', '', %d)", $name, $cache);
  return db_last_insert_id('filter_formats', 'format');
}

/**
 * Remove the specified filter from the specified format.
 * @param $format_id
 *   The ID of the format to remove the filter from.
 * @param $module
 *   The module this filter belongs to.
 * @param $delta
 *   The delta of this filter.
 *
 * NOTE: the module name + the delta is what uniquely identifies a filter
 */
function os_remove_filter($format_id, $module, $delta) {
  db_query("DELETE FROM {filters} WHERE format = %d AND module = '%s' AND delta = %d", $format_id, $module, $delta);
}

/**
* Add a filter to an input format. Note: This function is deprecated.
*
* @see os_set_filter()
*/
function os_add_filter($format_id, $module, $delta = 0, $weight = 0) {
  os_set_filter($format_id, $module, $delta, $weight);
}

/**
 * Update an existing a filter or insert a new one if not present.
 *
 * @param $format_id
 *   The ID of the format to add the filter to.
 * @param $module
 *   The module this filter belongs to.
 * @param $delta
 *   The delta of this filter.
 * @param $weight
 *   The weight to be applied to this filter.
 */
function os_set_filter($format_id, $module, $delta = 0, $weight = 0) {
  // if the format-module-delta exists, update
  if (db_result(db_query("SELECT `weight` FROM {filters} WHERE `format` = %d AND `module` = '%s' AND `delta` = %d", $format_id, $module, $delta)) !== FALSE) {
    db_query("UPDATE {filters} SET `weight` = %d WHERE `format` = %d AND `module` = '%s' AND `delta` = %d", $weight, $format_id, $module, $delta);
  }
  // otherwise insert a new record
  else {
    db_query("INSERT INTO {filters} (`format`, `module`, `delta`, `weight`) VALUES (%d, '%s', %d, %d)", $format_id, $module, $delta, $weight);
  }
}