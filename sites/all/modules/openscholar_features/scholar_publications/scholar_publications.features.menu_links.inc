<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function scholar_publications_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: features:publications
  $menu_links['features:publications'] = array(
    'menu_name' => 'features',
    'link_path' => 'publications',
    'router_path' => 'publications',
    'link_title' => 'Publications',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Publications');


  return $menu_links;
}
