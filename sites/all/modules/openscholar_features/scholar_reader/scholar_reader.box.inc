<?php

/**
 * Implementation of hook_default_box().
 */
function scholar_reader_default_box() {
  $export = array();
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'scholar_reader-latest_feed_items';
  $box->plugin_key = 'os_boxes_feedreader';
  $box->title = 'Latest Feed Items';
  $box->description = 'Latest Feed Items';
  $box->options = array(
    'visibility' => 'feature',
    'feed' => 'all',
    'number_of_items' => 10,
  );

  $export['scholar_reader-latest_feed_items'] = $box;
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'scholar_reader-feeds_list';
  $box->plugin_key = 'os_boxes_sv_list';
  $box->title = 'List of Feeds';
  $box->description = 'List of Feeds';
  $box->options = array(
    'visibility' => 'feature',
    'filter' => 'node:feed',
    'style' => 'titles',
    'sort' => 'newest',
    'argument' => '',
    'number_of_items' => '6',
    'use_pager' => 0,
    'more' => 1,
    'more_text' => 'more',
    'more_link' => 'feeds',
  );

  $export['scholar_reader-feeds_list'] = $box;
  return $export;
}
