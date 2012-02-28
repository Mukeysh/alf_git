<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function vsite_layout_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-none';
  $context->description = 'All sections';
  $context->tag = 'Feature';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~openscholar-feature-*' => '~openscholar-feature-*',
        'vsite-section-public' => 'vsite-section-public',
      ),
    ),
    'path' => array(
      'values' => array(
        '~cp/*' => '~cp/*',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = CONTEXT_CONDITION_MODE_AND;

  // Translatables
  // Included for use with string extractors like potx.
  t('All sections');
  t('Feature');
  $export['openscholar-feature-none'] = $context;

  return $export;
}
