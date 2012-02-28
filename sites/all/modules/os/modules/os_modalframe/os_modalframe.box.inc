<?php

/**
 * Implementation of hook_default_box().
 */
function os_modalframe_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'site_info';
  $box->plugin_key = 'os_boxes_modal_siteinfo';
  $box->title = '';
  $box->description = 'Site Info';
  $box->region = 'header_main';
  $box->options = array(
    'visibility' => 'feature',
  );
  $export['site_info'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'site_logo';
  $box->plugin_key = 'os_boxes_modal_sitelogo';
  $box->title = '';
  $box->description = 'Site Logo';
  $box->region = 'header_left';
  $box->options = array(
    'visibility' => 'feature',
  );
  $export['site_logo'] = $box;

  return $export;
}
