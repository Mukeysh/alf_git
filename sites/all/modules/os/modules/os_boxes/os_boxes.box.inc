<?php

/**
 * Implementation of hook_default_box().
 */
function os_boxes_default_box() {
  $export = array();
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'shield_default';
  $box->plugin_key = 'os_boxes_shields';
  $box->region = 'header_right';
  $box->title = '';
  $box->description = 'Shield';
  $box->options = array(
    'visibility' => 'feature',
  );

  $export['shield_default'] = $box;
  return $export;
}
