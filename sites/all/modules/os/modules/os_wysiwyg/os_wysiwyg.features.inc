<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function os_wysiwyg_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "oembedcore" && $api == "oemedcore_presets") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function os_wysiwyg_imagecache_default_presets() {
  $items = array(
    'inline_default' => array(
      'presetname' => 'inline_default',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '190',
            'height' => '100%',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'inline_larger' => array(
      'presetname' => 'inline_larger',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '600',
            'height' => '100%',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}
