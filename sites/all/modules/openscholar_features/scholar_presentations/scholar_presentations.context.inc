<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_presentations_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-presentations';
  $context->description = 'Presentations';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'presentation' => 'presentation',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'presentations' => 'presentations',
        'presentations/*' => 'presentations/*',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        'scholar_presentations:page_1' => 'scholar_presentations:page_1',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'presentations',
    'block' => array(
      'blocks' => array(
        'views-scholar_presentations-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_presentations-block_1',
          'weight' => 38,
          'region' => 'right',
          'status' => '0',
          'label' => 'Recent Presentations',
          'type' => 'context_ui',
        ),
        'boxes-vsite_taxonomy_fltr_cat' => array(
          'module' => 'boxes',
          'delta' => 'vsite_taxonomy_fltr_cat',
          'label' => 'Filter By Category',
          'weight' => 39,
          'region' => 'right',
        ),
        'boxes-os_addthis' => array(
          'module' => 'boxes',
          'delta' => 'os_addthis',
          'label' => 'AddThis Button',
          'weight' => 40,
          'region' => 'right',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Feature');
  t('Presentations');
  $export['openscholar-feature-presentations'] = $context;

  return $export;
}
