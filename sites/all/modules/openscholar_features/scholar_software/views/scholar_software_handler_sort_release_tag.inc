<?php
// $Id$

/**
 * Sort handler for release tag.
 */
class scholar_software_handler_sort_release_tag extends views_handler_sort {
  /**
   * Called to add the sort to a query.
   */
  function query() {
    $table = 'node_data_field_scholar_software_project';
    $table_alias = $this->query->ensure_table($table, $this->relationship);

    // Order by:
    // 2. versionmajor (2.x before 1.x).
    // 3. versionpatch (2.1 before 2.0).
    // 4. versionextra (2.1-beta1 before 2.1-alpha1).

    $fields = array(
      array('field_name' => 'field_versionmajor'),
      array('field_name' => 'field_versionpatch'),
    );
    foreach ($fields as $field) {
      $column = $field['field_name'] .'_value';
      $this->query->add_orderby($table_alias, $column, $this->options['order']);
    }
    
    $this->query->add_field(NULL, "IF ({$table}.field_versionextra_value IS NULL, 0.5, IF(CAST({$table}.field_versionextra_value as UNSIGNED) != 0,CAST({$table}.field_versionextra_value as UNSIGNED),{$table}.field_versionextra_value))", "{$table}_numeric_extra");
    $this->query->add_orderby(NULL, NULL, $this->options['order'], "{$table}_numeric_extra");
  }
}
