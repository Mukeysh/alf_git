<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function scholar_events_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: features:calendar
  $menu_links['features:calendar'] = array(
    'menu_name' => 'features',
    'link_path' => 'calendar',
    'router_path' => 'calendar',
    'link_title' => 'Calendar',
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
  t('Calendar');


  return $menu_links;
}
