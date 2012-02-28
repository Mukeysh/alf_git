<?php

/**
 * Implementation of hook_default_box().
 */
function vsite_taxonomy_default_box() {
  $export = array();
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'vsite_taxonomy_fltr_cat';
  $box->plugin_key = 'vsite_taxonomy_fbt';
  $box->title = '';
  $box->description = 'Filter by Category';
  $box->options = array(
    'visibility' => 'feature',
    'number_of_items' => '0',
    'behavior' => 'contextual',
    'show_empty_terms' => 0,
    'show_term_descriptions' => 0,
    'show_vocabulary_name' => 1,
    'vocabulary' => array(), //Empty array is the same as selecting all avalible vocabs
  );

  $export['vsite_taxonomy_fltr_cat'] = $box;
  return $export;
}
