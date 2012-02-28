<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function os_wysiwyg_fields_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_wysiwyg_fields_icons().
 */
function os_wysiwyg_fields_wysiwyg_fields_icons() {
  return array(
    drupal_get_path('module', 'os_wysiwyg_fields') . '/images/wysiwyg_fields',
  );
}
