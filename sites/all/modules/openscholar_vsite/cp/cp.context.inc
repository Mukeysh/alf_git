<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function cp_context_default_contexts() {
  $export = array();
  
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vsite-section-cp';
  $context->description = 'Active when you are in the CP section of a vsite.';
  $context->tag = 'Section';
  
  $group_nodes = features_get_component_map('node');
  foreach ($group_nodes as $node_type => $value) {
  	if(!og_is_group_post_type($node_type)) unset($group_nodes[$node_type]);
  }//When editing any group node post, join the cp context
  
  $context->conditions = array(
    'node' => array(
      'values' => array_keys($group_nodes),
      'options' => array(
        'node_form' => '2',
      ),
    ),
    'path' => array(
      'values' => array(
        'cp' => 'cp',
        'cp/*' => 'cp/*',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cp_0' => array(
          'module' => 'cp',
          'delta' => '0',
          'weight' => 20,
          'region' => 'left',
          'status' => '0',
          'label' => 'CP left menu',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['vsite-section-cp'] = $context;
  
  return $export;
}
