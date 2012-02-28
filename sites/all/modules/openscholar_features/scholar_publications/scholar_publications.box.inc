<?php

/**
 * Implementation of hook_default_box().
 */
function scholar_publications_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'scholar_publications_recent';
  $box->plugin_key = 'os_boxes_pub_typ_list';
  $box->title = 'Recent Publications';
  $box->description = 'Recent Publications';
  $box->options = array(
    'pub_types' => array(),
    'number_of_items' => '6',
    'use_pager' => 0,
    'style' => 'titles',
    'more' => 1,
    'more_text' => 'more',
    'more_link' => 'publications',
    'show_all_types' => 1,
  );
  $export['scholar_publications_recent'] = $box;

  return $export;
}
