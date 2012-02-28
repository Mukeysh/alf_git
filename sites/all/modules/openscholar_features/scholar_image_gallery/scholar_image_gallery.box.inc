<?php

/**
 * Implementation of hook_default_box().
 */
function scholar_image_gallery_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'image_gallery_recent_images';
  $box->plugin_key = 'os_boxes_gallery';
  $box->title = 'Recent Images';
  $box->description = 'Recent Images';
  $box->options = array(
    'visibility' => 'feature',
    'gallery' => 'all',
    'number_of_items' => '6',
  );
  $export['image_gallery_recent_images'] = $box;

  return $export;
}
