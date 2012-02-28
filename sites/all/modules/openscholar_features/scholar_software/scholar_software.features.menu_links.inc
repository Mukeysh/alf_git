<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function scholar_software_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: features:software
  $menu_links['features:software'] = array(
    'menu_name' => 'features',
    'link_path' => 'software',
    'router_path' => 'software',
    'link_title' => 'Software',
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
  t('Software');


  return $menu_links;
}
