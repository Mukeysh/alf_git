<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function scholar_biocv_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: features:biocv
  $menu_links['features:biocv'] = array(
    'menu_name' => 'features',
    'link_path' => 'biocv',
    'router_path' => 'biocv',
    'link_title' => 'Bio',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Bio');


  return $menu_links;
}
