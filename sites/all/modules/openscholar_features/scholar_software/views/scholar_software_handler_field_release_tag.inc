<?php
// $Id$

/**
 * Field handler to present release tag.
 */
class scholar_software_handler_field_release_tag extends views_handler_field {
  function query() {
    // Do not add this field to query, only add the additional fields.
    $this->add_additional_fields();
  }

  function construct() {
    parent::construct();
    $fields = array(
      0 => array('alias'=> 'major', 'field_name' => 'field_versionmajor'),
      1 => array('alias'=> 'patch', 'field_name' => 'field_versionpatch'),
      2 => array('alias'=> 'extra', 'field_name' => 'field_versionextra'),
    );

    foreach ($fields as $field) {
      $alias = $field['alias'];
      $table = content_views_tablename($field);
      $column = $field['field_name'] .'_value';

      $this->additional_fields[$alias] = array('table' => $table, 'field' => $column);
    }
  }

  function render($values) {
    $major = check_plain($values->{$this->aliases['major']});
    $patch = check_plain($values->{$this->aliases['patch']});
    $extra = check_plain($values->{$this->aliases['extra']});

    $release = "$major.$patch" . (!empty($extra) ? "-$extra" : '');
    return $release;
  }
}
