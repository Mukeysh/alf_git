<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_front_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-front';
  $context->description = 'Site front page';
  $context->tag = 'Feature';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'context' => array(
      'values' => array(
        '~openscholar-section-sitewide_front' => '~openscholar-section-sitewide_front',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'scholar_front-get_started' => array(
          'module' => 'scholar_front',
          'delta' => 'get_started',
          'weight' => -1,
          'region' => 'admin_area',
          'status' => '0',
          'label' => 'Get Started (admin)',
        ),
        'views-scholar_events_upcoming-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_events_upcoming-block_1',
          'weight' => 20,
          'region' => 'right',
          'status' => '0',
          'label' => 'Upcoming events',
          'type' => 'context_ui',
        ),
        'boxes-scholar_announcements_latest' => array(
          'module' => 'boxes',
          'delta' => 'scholar_announcements_latest',
          'weight' => 21,
          'region' => 'right',
          'status' => '0',
          'label' => 'Latest Announcements',
        ),
        'boxes-scholar_biocv_bio' => array(
          'module' => 'boxes',
          'delta' => 'scholar_biocv_bio',
          'weight' => 0,
          'region' => 'content_top',
          'label' => 'Bio Teaser',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Feature');
  t('Site front page');
  $export['openscholar-feature-front'] = $context;

  return $export;
}
