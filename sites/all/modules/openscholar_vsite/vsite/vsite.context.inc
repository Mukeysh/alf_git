<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function vsite_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vsite-section-public';
  $context->description = 'Active when you are in the public section of a vsite.';
  $context->tag = 'Section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~cp/*' => '~cp/*',
        '~admin/*' => '~admin/*',
      ),
      'options' => array(),
    ),
    'context' => array(
      'values' => array(
        '~vsite-section-cp' => '~vsite-section-cp',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active when you are in the public section of a vsite.');
  t('Section');
  $export['vsite-section-public'] = $context;

  return $export;
}
