<?php

/**
 * Implementation of hook_default_box().
 */
function scholar_book_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'scholar_book_current_toc';
  $box->plugin_key = 'os_boxes_curr_toc';
  $box->title = 'Table of Contents';
  $box->description = 'Active Book\'s TOC';
  $box->options = array(
    'visibility' => 'feature',
  );
  $export['scholar_book_current_toc'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'scholar_book_recent_docs';
  $box->plugin_key = 'os_boxes_recent_docs';
  $box->title = 'Recent Documents';
  $box->description = 'Recent Documents';
  $box->options = array(
    'style' => 'titles',
    'number_of_items' => '6',
    'use_pager' => 0,
    'more' => 0,
    'more_text' => '',
    'more_link' => '',
  );
  $export['scholar_book_recent_docs'] = $box;
  return $export;
}
