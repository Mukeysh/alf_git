<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function vsite_taxonomy_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-taxonomy';
  $context->description = 'Taxonomy Term Pages';
  $context->tag = 'Feature';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'taxonomy/term/*' => 'taxonomy/term/*',
      ),
    ),
    'context' => array(
      'values' => array(
        '~openscholar-feature-*' => '~openscholar-feature-*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'vsite_taxonomy-filter_feature' => array(
          'module' => 'vsite_taxonomy',
          'delta' => 'filter_feature',
          'weight' => 0,
          'region' => 'right',
          'status' => '0',
          'label' => 'Categories - Filter categorized content by type',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Feature');
  t('Taxonomy Term Pages');

  $export['openscholar-feature-taxonomy'] = $context;
  return $export;
}
