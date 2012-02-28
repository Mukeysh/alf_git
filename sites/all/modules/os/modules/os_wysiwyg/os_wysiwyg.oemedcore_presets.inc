<?php

/**
 * Implementation of hook_default_oembedcore_preset().
 */
function os_wysiwyg_default_oembedcore_preset() {
  $export = array();

  $preset = new stdClass;
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'default';
  $preset->width = 440;
  $preset->height = 0;
  $preset->conf = array(
    'disable_title' => TRUE,
  );
  $export['default'] = $preset;

  return $export;
}
