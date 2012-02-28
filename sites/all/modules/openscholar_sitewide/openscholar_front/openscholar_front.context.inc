<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function openscholar_front_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-section-sitewide';
  $context->description = 'openscholar sitewide, no vsite context';
  $context->tag = '';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~openscholar-section-*' => '~openscholar-section-*',
        '~vsite-section-*' => '~vsite-section-*',
      ),
    ),
    'path' => array(
      'values' => array(
        '~admin' => '~admin',
      ),
    ),
  );
  $context->reactions = array(
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('openscholar sitewide, no vsite context');

  $export['openscholar-section-sitewide'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-section-sitewide_front';
  $context->description = 'openscholar front context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'welcome' => 'welcome',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'openscholar_front-site_info' => array(
          'module' => 'openscholar_front',
          'delta' => 'site_info',
          'region' => 'header_main',
          'weight' => 0,
        ),
        'openscholar_front-top_links' => array(
          'module' => 'openscholar_front',
          'delta' => 'top_links',
          'region' => 'header_right',
          'weight' => 0,
        ),
        'openscholar_front-site_info' => array(
          'module' => 'openscholar_front',
          'delta' => 'site_info',
          'region' => 'header_main',
          'weight' => 0,
        ),
        'openscholar_front-top_links' => array(
          'module' => 'openscholar_front',
          'delta' => 'top_links',
          'region' => 'header_right',
          'weight' => 0,
        ),
        'openscholar_front-video_info' => array(
          'module' => 'openscholar_front',
          'delta' => 'video_info',
          'region' => 'content_top',
          'weight' => 0,
        ),
        'openscholar_front-site_mission' => array(
          'module' => 'openscholar_front',
          'delta' => 'site_mission',
          'region' => 'content_top',
          'weight' => 1,
        ),
        'views-openscholar_sites-block_2' => array(
          'module' => 'views',
          'delta' => 'openscholar_sites-block_2',
          'region' => 'content_bottom',
          'weight' => 0,
        ),
        'iqss_openscholar_front-stats' => array(
          'module' => 'iqss_openscholar_front',
          'delta' => 'stats',
          'region' => 'footer',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('openscholar front context');

  $export['openscholar-section-sitewide_front'] = $context;
  return $export;
}
