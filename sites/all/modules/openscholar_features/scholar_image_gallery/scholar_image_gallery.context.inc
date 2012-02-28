<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_image_gallery_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-image_gallery';
  $context->description = 'Image Galleries';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'gallery' => 'gallery',
        'image' => 'image',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'images' => 'images',
        'images/*' => 'images/*',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        'scholar_image_gallery:page_1' => 'scholar_image_gallery:page_1',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'photos',
    'block' => array(
      'blocks' => array(
        'boxes-image_gallery_recent_images' => array(
          'module' => 'boxes',
          'delta' => 'image_gallery_recent_images',
          'label' => 'Recent Images',
          'weight' => 20,
          'region' => 'right',
        ),
        'boxes-vsite_taxonomy_fltr_cat' => array(
          'module' => 'boxes',
          'delta' => 'vsite_taxonomy_fltr_cat',
          'label' => 'Filter By Category',
          'weight' => -20,
          'region' => 'right',
        ),
        'boxes-os_addthis' => array(
          'module' => 'boxes',
          'delta' => 'os_addthis',
          'label' => 'AddThis Button',
          'weight' => 50,
          'region' => 'right',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Feature');
  t('Image Galleries');
  $export['openscholar-feature-image_gallery'] = $context;

  return $export;
}
