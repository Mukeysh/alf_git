<?php

/**
 * Implementation of hook_default_box().
 */
function scholar_announcements_default_box() {
  $export = array();
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'scholar_announcements_latest';
  $box->plugin_key = 'os_boxes_sv_list';
  $box->title = 'Latest Announcements';
  $box->description = 'Latest Announcements';
  $box->options = array(
    'filter' => 'node:announcement',
    'style' => 'titles',
    'sort' => 'newest',
    'argument' => '',
    'number_of_items' => '6',
    'use_pager' => 0,
    'more' => 1,
    'more_text' => 'more',
    'more_link' => 'announcements',
  );

  $export['scholar_announcements_latest'] = $box;
  return $export;
}
