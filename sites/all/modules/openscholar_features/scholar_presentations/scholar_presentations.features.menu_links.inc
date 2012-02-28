<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function scholar_presentations_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: features:presentations
  $menu_links['features:presentations'] = array(
    'menu_name' => 'features',
    'link_path' => 'presentations',
    'router_path' => 'presentations',
    'link_title' => 'Presentations',
    'options' => array(
      'attributes' => array(
        'title' => 'List of presentations on my site',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Presentations');


  return $menu_links;
}
