<?php

/**
 * Implementation of hook_default_box().
 */
function scholar_presentations_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'scholar_presentations_recent';
  $box->plugin_key = 'os_boxes_present_list';
  $box->title = 'Recent Presentations';
  $box->description = 'Recent Presentations';
  $box->options = array(
    'number_of_items' => '6',
    'use_pager' => 0,
    'style' => 'titles',
    'more' => 1,
    'more_text' => 'more',
    'more_link' => 'presentations',
  );
  $export['scholar_presentations_recent'] = $box;

  return $export;
}
