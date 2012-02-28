<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function scholar_announcements_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: features:announcements
  $menu_links['features:announcements'] = array(
    'menu_name' => 'features',
    'link_path' => 'announcements',
    'router_path' => 'announcements',
    'link_title' => 'Announcements',
    'options' => array(
      'attributes' => array(
        'title' => 'Announcements',
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
  t('Announcements');


  return $menu_links;
}
