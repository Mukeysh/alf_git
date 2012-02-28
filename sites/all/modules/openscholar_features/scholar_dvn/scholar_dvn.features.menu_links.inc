<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function scholar_dvn_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: features:data
  $menu_links['features:data'] = array(
    'menu_name' => 'features',
    'link_path' => 'data',
    'router_path' => 'data',
    'link_title' => 'data',
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
  t('data');


  return $menu_links;
}
