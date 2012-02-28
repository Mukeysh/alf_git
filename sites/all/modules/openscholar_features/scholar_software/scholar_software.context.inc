<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_software_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-software';
  $context->description = 'Software and Software Releases';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'scholar_software_project' => 'scholar_software_project',
        'scholar_software_release' => 'scholar_software_release',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'software' => 'software',
        'software/*' => 'software/*',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        'scholar_software_projects:page_1' => 'scholar_software_projects:page_1',
        'scholar_software_releases:page_1' => 'scholar_software_releases:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'software',
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
        'views-scholar_software_releases-block_3' => array(
          'module' => 'views',
          'delta' => 'scholar_software_releases-block_3',
          'weight' => 20,
          'region' => 'right',
          'status' => '0',
          'label' => 'Software Releases',
          'type' => 'context_ui',
        ),
        'views-scholar_software_releases-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_software_releases-block_1',
          'weight' => 20,
          'region' => FALSE,
          'status' => '0',
          'label' => 'Recommended Software Releases',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Feature');
  t('Software and Software Releases');

  $export['openscholar-feature-software'] = $context;
  return $export;
}
