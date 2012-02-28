<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_events_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-events';
  $context->description = 'Calendar and Events';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'calendar' => 'calendar',
        'calendar/*' => 'calendar/*',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        'scholar_events:page_1' => 'scholar_events:page_1',
        'scholar_events_upcoming:page_1' => 'scholar_events_upcoming:page_1',
        'scholar_events_upcoming:page_2' => 'scholar_events_upcoming:page_2',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'calendar',
    'block' => array(
      'blocks' => array(
        'boxes-vsite_taxonomy_fltr_cat' => array(
          'module' => 'boxes',
          'delta' => 'vsite_taxonomy_fltr_cat',
          'label' => 'Filter By Category',
          'weight' => 20,
          'region' => 'right',
        ),
        'boxes-os_addthis' => array(
          'module' => 'boxes',
          'delta' => 'os_addthis',
          'label' => 'AddThis Button',
          'weight' => 21,
          'region' => 'right',
        ),
        'scholar_events-mini' => array(
          'module' => 'scholar_events',
          'delta' => 'mini',
          'weight' => 22,
          'region' => 'right',
          'status' => '0',
          'label' => 'Mini Calendar - A small calendar used to display your sites upcoming events',
          'type' => 'context_ui',
        ),
        'views-scholar_events_upcoming-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_events_upcoming-block_1',
          'weight' => 23,
          'region' => 'right',
          'status' => '0',
          'label' => 'Upcoming events',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Calendar and Events');
  t('Feature');
  $export['openscholar-feature-events'] = $context;

  return $export;
}
