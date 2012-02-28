<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function os_slideshow_imagecache_default_presets() {
  $items = array(
    'os_slideshow_480x270' => array(
      'presetname' => 'os_slideshow_480x270',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '480',
            'height' => '270',
          ),
        ),
      ),
    ),
    'os_slideshow_640x360' => array(
      'presetname' => 'os_slideshow_640x360',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '640',
            'height' => '360',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function os_slideshow_views_api() {
  return array(
    'api' => '2',
  );
}
