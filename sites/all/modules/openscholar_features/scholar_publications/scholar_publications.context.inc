<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_publications_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-publications';
  $context->description = 'Publications';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'biblio' => 'biblio',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'publications' => 'publications',
        'publications/*' => 'publications/*',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        'publication_types:page_1' => 'publication_types:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'publications',
    'block' => array(
      'blocks' => array(
        'boxes-vsite_taxonomy_fltr_cat' => array(
          'module' => 'boxes',
          'delta' => 'vsite_taxonomy_fltr_cat',
          'label' => 'Filter By Category',
          'weight' => 20,
          'region' => 'right',
        ),
        'boxes-scholar_publications_recent' => array(
          'module' => 'boxes',
          'delta' => 'scholar_publications_recent',
          'weight' => 21,
          'region' => 'right',
          'label' => 'Recent publications',
        ),
        'boxes-os_addthis' => array(
          'module' => 'boxes',
          'delta' => 'os_addthis',
          'label' => 'AddThis Button',
          'weight' => 22,
          'region' => 'right',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Feature');
  t('Publications');
  $export['openscholar-feature-publications'] = $context;

  return $export;
}
