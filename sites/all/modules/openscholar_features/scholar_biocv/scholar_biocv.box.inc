<?php

/**
 * Implementation of hook_default_box().
 */
function scholar_biocv_default_box() {
  $export = array();
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'scholar_biocv_bio';
  $box->plugin_key = 'os_boxes_bio';
  $box->title = ''; //Blank title
  $box->description = 'Bio Post';
  $box->options = array(
    'visibility' => 'feature',
    'nid' => 0,
    'teaser' => 'full',
    'show_title' => 0,
  );

  $export['scholar_biocv_bio'] = $box;
  return $export;
}
