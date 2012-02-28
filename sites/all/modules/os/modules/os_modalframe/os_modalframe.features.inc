<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function os_modalframe_imagecache_default_presets() {
  $items = array(
    'os_modal_image_150' => array(
      'presetname' => 'os_modal_image_150',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '150',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'os_modal_image_200' => array(
      'presetname' => 'os_modal_image_200',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '200',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'os_modal_image_300' => array(
      'presetname' => 'os_modal_image_300',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '300',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'os_modal_image_500' => array(
      'presetname' => 'os_modal_image_500',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '500',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'os_modal_image_900' => array(
      'presetname' => 'os_modal_image_900',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '900',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function os_modalframe_node_info() {
  $items = array(
    'modal_image' => array(
      'name' => t('Modal Image'),
      'module' => 'features',
      'description' => t('An Image not attached to a gallery.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Caption'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
