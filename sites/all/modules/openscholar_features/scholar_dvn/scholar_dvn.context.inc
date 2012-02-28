<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_dvn_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-dvn';
  $context->description = 'Datverse';
  $context->tag = 'Feature';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'data' => 'data',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Datverse Feature Context');

  $export['openscholar-feature-dvn'] = $context;
  return $export;
}
