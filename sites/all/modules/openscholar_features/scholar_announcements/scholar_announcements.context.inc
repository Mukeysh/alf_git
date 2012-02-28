<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_announcements_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-announcements';
  $context->description = 'Announcements';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'announcement' => 'announcement',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'scholar_announcements:page_1' => 'scholar_announcements:page_1',
      ),
      'options' => array(),
    ),
    'path' => array(
      'values' => array(
        'announcements' => 'announcements',
        'announcements/*' => 'announcements/*',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'announcements',
    'block' => array(
      'blocks' => array(
        'boxes-scholar_announcements_latest' => array(
          'module' => 'boxes',
          'delta' => 'scholar_announcements_latest',
          'weight' => -21,
          'region' => 'right',
          'label' => 'Latest Announcements',
        ),
        'vsite_taxonomy-0' => array(
          'module' => 'vsite_taxonomy',
          'delta' => '0',
          'weight' => -20,
          'region' => 'right',
          'label' => 'Scholar site categories',
          'type' => 'context_ui',
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
  t('Announcements');
  t('Feature');

  $export['openscholar-feature-announcements'] = $context;
  return $export;
}
