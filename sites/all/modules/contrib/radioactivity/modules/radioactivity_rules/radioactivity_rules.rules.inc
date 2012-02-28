<?php

/**
* Implementation of hook_rules_data_type_info().
*/
function radioactivity_rules_rules_data_type_info() {
  return array(
    'decay_profile' => array(
      'label' => 'radioactivity decay profile',
      'class' => 'rules_data_type_decay_profile',
      'savable' => FALSE,
      'identifiable' => TRUE,
      'module' => 'Radioactivity',
      'token type' => 'radioactivity',
    ),
  );
}




class rules_data_type_decay_profile extends rules_data_type {

  function load($id) {
    $profiles = radioactivity_get_decay_profiles();
    $row = $profiles[$id];
    $row['id'] = $id;
    return $row;
  }

  function get_identifier() {
    $row = &$this->get();
    return $row['id'];
  }
  
}
