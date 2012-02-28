<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_classes_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-classes';
  $context->description = 'Classes and Class Materials';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'class' => 'class',
        'class_material' => 'class_material',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'classes' => 'classes',
        'classes/*' => 'classes/*',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        'scholar_classes:page_1' => 'scholar_classes:page_1',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'classes',
    'block' => array(
      'blocks' => array(
        'boxes-os_addthis' => array(
          'module' => 'boxes',
          'delta' => 'os_addthis',
          'label' => 'AddThis Button',
          'weight' => 37,
          'region' => 'right',
        ),
        'boxes-scholar_book_current_toc' => array(
          'module' => 'boxes',
          'delta' => 'scholar_book_current_toc',
          'weight' => 38,
          'region' => 'right',
          'label' => 'Table of Contents',
          'tags' => array('Content','Book'),
        ),
        'boxes-vsite_taxonomy_fltr_cat' => array(
          'module' => 'boxes',
          'delta' => 'vsite_taxonomy_fltr_cat',
          'label' => 'Filter By Category',
          'weight' => 39,
          'region' => 'right',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Classes and Class Materials');
  t('Feature');

  $export['openscholar-feature-classes'] = $context;
  return $export;
}
