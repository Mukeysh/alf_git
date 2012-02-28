<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function vsite_search_apachesolr_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-search';
  $context->description = 'Search Pages';
  $context->tag = 'Feature';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/apachesolr_search' => 'search/apachesolr_search',
        'search/apachesolr_search/*' => 'search/apachesolr_search/*',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'vsite_search_apachesolr-0' => array(
          'module' => 'vsite_search_apachesolr',
          'delta' => '0',
          'weight' => 44,
          'region' => 'right',
          'status' => '0',
          'label' => 'Categories',
          'type' => 'context_ui',
        ),
        'apachesolr-mlt-001' => array(
          'module' => 'apachesolr',
          'delta' => 'mlt-001',
          'weight' => 45,
          'region' => 'right',
          'status' => '0',
          'label' => 'Apache Solr recommendations: More like this',
          'type' => 'context_ui',
        ),
        'apachesolr_search-currentsearch' => array(
          'module' => 'apachesolr_search',
          'delta' => 'currentsearch',
          'weight' => 46,
          'region' => 'right',
          'status' => '0',
          'label' => 'Apache Solr Search: Current search',
          'type' => 'context_ui',
        ),
        'apachesolr-sort' => array(
          'module' => 'apachesolr',
          'delta' => 'sort',
          'weight' => 47,
          'region' => 'right',
          'status' => '0',
          'label' => 'Apache Solr Core: Sorting',
          'type' => 'context_ui',
        ),
        'apachesolr_search-type' => array(
          'module' => 'apachesolr_search',
          'delta' => 'type',
          'weight' => 48,
          'region' => 'right',
          'status' => '0',
          'label' => 'Node attribute: Filter by content type',
          'type' => 'context_ui',
        ),
        'apachesolr_og-im_og_gid' => array(
          'module' => 'apachesolr_og',
          'delta' => 'im_og_gid',
          'weight' => 49,
          'region' => 'right',
          'status' => '0',
          'label' => 'Apache Solr OG: Filter by Organic Group',
          'type' => 'context_ui',
        ),
        'apachesolr_biblio-ss_biblio_type_of_work' => array(
          'module' => 'apachesolr_biblio',
          'delta' => 'ss_biblio_type_of_work',
          'weight' => 50,
          'region' => 'right',
          'status' => '0',
          'label' => 'Biblio: Filter by Type of Work',
          'type' => 'context_ui',
        ),
        'apachesolr_search-uid' => array(
          'module' => 'apachesolr_search',
          'delta' => 'uid',
          'weight' => 51,
          'region' => 'right',
          'status' => '0',
          'label' => 'Node attribute: Filter by author',
          'type' => 'context_ui',
        ),
        'apachesolr_biblio-sm_biblio_contributors' => array(
          'module' => 'apachesolr_biblio',
          'delta' => 'sm_biblio_contributors',
          'weight' => 52,
          'region' => 'right',
          'status' => '0',
          'label' => 'Biblio: Filter by Citation Contributor',
          'type' => 'context_ui',
        ),
        'apachesolr_biblio-ss_biblio_publisher' => array(
          'module' => 'apachesolr_biblio',
          'delta' => 'ss_biblio_publisher',
          'weight' => 53,
          'region' => 'right',
          'status' => '0',
          'label' => 'Biblio: Filter by Publisher',
          'type' => 'context_ui',
        ),
        'apachesolr_biblio-ss_biblio_secondary_title' => array(
          'module' => 'apachesolr_biblio',
          'delta' => 'ss_biblio_secondary_title',
          'weight' => 54,
          'region' => 'right',
          'status' => '0',
          'label' => 'Biblio: Filter by Secondary Title',
          'type' => 'context_ui',
        ),
        'apachesolr_biblio-ss_biblio_year' => array(
          'module' => 'apachesolr_biblio',
          'delta' => 'ss_biblio_year',
          'weight' => 55,
          'region' => 'right',
          'status' => '0',
          'label' => 'Biblio: Filter by Year of Publication',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Feature');
  t('Search Pages');

  $export['openscholar-feature-search'] = $context;
  return $export;
}
