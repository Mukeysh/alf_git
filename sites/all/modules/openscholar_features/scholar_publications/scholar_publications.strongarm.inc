<?php

/**
 * Implementation of hook_strongarm().
 */
function scholar_publications_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'better_formats_allowed_biblio';
  $strongarm->value = array(
    0 => 1,
    1 => 2,
    2 => 3,
  );
  $export['better_formats_allowed_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_base';
  $strongarm->value = 'publications';
  $export['biblio_base'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_contributors_numberofauthors';
  $strongarm->value = 100;
  $export['biblio_contributors_numberofauthors'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_sort_tabs';
  $strongarm->value = array(
    'author' => 'author',
    'title' => 'title',
    'type' => 'type',
    'year' => 'year',
  );
  $export['biblio_sort_tabs'] = $strongarm;
  
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_year_text_10000';
  $strongarm->value = 'Forthcoming';
  $export['biblio_year_text_10000'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_biblio';
  $strongarm->value = '0';
  $export['comment_anonymous_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_biblio';
  $strongarm->value = '0';
  $export['comment_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_biblio';
  $strongarm->value = '3';
  $export['comment_controls_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_biblio';
  $strongarm->value = '4';
  $export['comment_default_mode_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_biblio';
  $strongarm->value = '1';
  $export['comment_default_order_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_biblio';
  $strongarm->value = '50';
  $export['comment_default_per_page_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_biblio';
  $strongarm->value = '0';
  $export['comment_form_location_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_biblio';
  $strongarm->value = '0';
  $export['comment_preview_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_biblio';
  $strongarm->value = '1';
  $export['comment_subject_field_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_biblio';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '0',
    'revision_information' => '20',
    'author' => '20',
    'options' => '25',
    'comment_settings' => '30',
    'menu' => '-2',
    'taxonomy' => '-3',
    'book' => '10',
    'path' => '30',
    'attachments' => '30',
    'creativecommons' => '100',
    'og_nodeapi' => '0',
  );
  $export['content_extra_weights_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_biblio_field_os_inline_image';
  $strongarm->value = 0;
  $export['ffp_biblio_field_os_inline_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_biblio_upload';
  $strongarm->value = 0;
  $export['ffp_biblio_upload'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_biblio';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_biblio_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '-46',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => array(
      'region' => 'right',
      'weight' => '7',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'revision_information' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'comment_settings' => array(
      'region' => 'right',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'path' => array(
      'region' => 'right',
      'weight' => '8',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'options' => array(
      'region' => 'right',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'author' => array(
      'region' => 'right',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'buttons' => array(
      'region' => 'main',
      'weight' => '17',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'nid' => array(
      'region' => 'main',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'vid' => array(
      'region' => 'main',
      'weight' => '7',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'uid' => array(
      'region' => 'main',
      'weight' => '8',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'created' => array(
      'region' => 'main',
      'weight' => '9',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'type' => array(
      'region' => 'main',
      'weight' => '-45',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'language' => array(
      'region' => 'main',
      'weight' => '10',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'changed' => array(
      'region' => 'main',
      'weight' => '11',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'biblio_doi_lookup' => array(
      'region' => 'main',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'DOI Lookup',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'biblio_cut_paste' => array(
      'region' => 'main',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Paste',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'biblio_type' => array(
      'region' => 'main',
      'weight' => '-45',
      'has_required' => TRUE,
      'title' => 'Publication Type',
    ),
    'book' => array(
      'region' => 'right',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'taxonomy' => array(
      'region' => 'right',
      'weight' => '0',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'attachments' => array(
      'region' => 'main',
      'weight' => '12',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'field_biblio_extra' => array(
      'region' => 'main',
      'weight' => '13',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'field_biblio_image' => array(
      'region' => 'main',
      'weight' => '16',
      'has_required' => FALSE,
      'title' => 'Book Cover',
      'hidden' => 0,
    ),
    'og_initial_groups' => array(
      'region' => 'main',
      'weight' => '14',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'og_nodeapi' => array(
      'region' => 'main',
      'weight' => '15',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'cite_distribute_selections' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'submit_type' => array(
      'region' => 'main',
      'weight' => '-45',
      'has_required' => FALSE,
      'title' => 'Select Publication Type',
      'hidden' => 0,
    ),
  );
  $export['nodeformscols_field_placements_biblio_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_biblio';
  $strongarm->value = 'group_post_standard';
  $export['og_content_type_usage_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_biblio_pattern';
  $strongarm->value = '[space-og-path]/publications/[title-raw]';
  $export['pathauto_node_biblio_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_biblio';
  $strongarm->value = 0;
  $export['show_diff_inline_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_biblio';
  $strongarm->value = 0;
  $export['show_preview_changes_biblio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_biblio';
  $strongarm->value = '1';
  $export['upload_biblio'] = $strongarm;

  return $export;
}
