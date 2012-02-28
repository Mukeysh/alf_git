<?php

/**
 * Implementation of hook_strongarm().
 */
function vsite_search_apachesolr_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_cron_limit';
  $strongarm->value = 200;

  $export['apachesolr_cron_limit'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_enabled_facets';
  $strongarm->value = array(
    'apachesolr_search' => array(
      'uid' => 'uid',
      'type' => 'type',
      'created' => 'created',
      'im_vid_314' => 'im_vid_314',
    ),
    'apachesolr_og' => array(
      'im_og_gid' => 'im_og_gid',
    ),
    'apachesolr_biblio' => array(
      'sm_biblio_contributors' => 'sm_biblio_contributors',
      'ss_biblio_publisher' => 'ss_biblio_publisher',
      'ss_biblio_secondary_title' => 'ss_biblio_secondary_title',
      'ss_biblio_type_of_work' => 'ss_biblio_type_of_work',
      'ss_biblio_year' => 'ss_biblio_year',
    ),
  );

  $export['apachesolr_enabled_facets'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_failure';
  $strongarm->value = 'show_error';

  $export['apachesolr_failure'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_mlt_blocks';
  $strongarm->value = array(
    'mlt-001' => array(
      'name' => 'More like this',
      'num_results' => '5',
      'mlt_fl' => array(
        'title' => 'title',
        'taxonomy_names' => 'taxonomy_names',
      ),
      'mlt_mintf' => '1',
      'mlt_mindf' => '1',
      'mlt_minwl' => '3',
      'mlt_maxwl' => '15',
      'mlt_maxqt' => '20',
      'mlt_type_filters' => array(
        0 => 'blog',
        1 => 'announcement',
        2 => 'bio',
        3 => 'cv',
        4 => 'book',
        5 => 'class',
        6 => 'class_material',
        7 => 'event',
        8 => 'gallery',
        9 => 'image',
        10 => 'link',
        11 => 'page',
        12 => 'feed',
        13 => 'scholar_software_project',
        14 => 'scholar_software_release',
        15 => 'vsite',
        16 => 'feature_request',
        17 => 'support_answer',
        18 => 'support_question',
        19 => 'vsite_users_profile',
        20 => 'biblio',
        21 => 'profile',
      ),
      'mlt_custom_filters' => '',
    ),
  );

  $export['apachesolr_mlt_blocks'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_og_groupnode';
  $strongarm->value = 0;

  $export['apachesolr_og_groupnode'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_read_only';
  $strongarm->value = 0;

  $export['apachesolr_read_only'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_rows';
  $strongarm->value = 10;

  $export['apachesolr_rows'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_default_previous';
  $strongarm->value = 1;

  $export['apachesolr_search_default_previous'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_make_default';
  $strongarm->value = 1;

  $export['apachesolr_search_make_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_spellcheck';
  $strongarm->value = 1;

  $export['apachesolr_search_spellcheck'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_taxonomy_links';
  $strongarm->value = 1;

  $export['apachesolr_search_taxonomy_links'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_taxonomy_previous';
  $strongarm->value = 1;

  $export['apachesolr_search_taxonomy_previous'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_set_nodeapi_messages';
  $strongarm->value = 1;

  $export['apachesolr_set_nodeapi_messages'] = $strongarm;
  return $export;
}
