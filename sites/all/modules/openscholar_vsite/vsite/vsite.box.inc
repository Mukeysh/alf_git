<?php

/**
 * Implementation of hook_default_box().
 */
function vsite_default_box() {
  $export = array();
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'os_addthis';
  $box->plugin_key = 'os_boxes_addthis';
  $box->title = '';
  $box->description = 'AddThis Button';
  $box->options = array(
    'visibility' => 'feature',
    'widget_type' => 'buttons',
    'toolbox_services' => 'facebook,twitter,email,linkedin,google_plusone',
  );

  $export['os_addthis'] = $box;
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'vsite_rss';
  $box->plugin_key = 'os_boxes_rss';
  $box->title = '';
  $box->description = 'Site RSS Feed';
  $box->options = array(
    'visibility' => 'feature',
    'content' => 'all',
  );

  $export['vsite_rss'] = $box;
  return $export;
}
