<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_links_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-links';
  $context->description = 'Links';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        0 => 'link',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'links' => 'links',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        'scholar_links:page_1' => 'scholar_links:page_1',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'links',
    'block' => array(
      'blocks' => array(
        'boxes-vsite_taxonomy_fltr_cat' => array(
          'module' => 'boxes',
          'delta' => 'vsite_taxonomy_fltr_cat',
          'label' => 'Filter By Category',
          'weight' => -20,
          'region' => 'right',
        ),
        'boxes-os_addthis' => array(
          'module' => 'boxes',
          'delta' => 'os_addthis',
          'label' => 'AddThis Button',
          'weight' => 50,
          'region' => 'right',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Feature');
  t('Links');

  $export['openscholar-feature-links'] = $context;
  return $export;
}
