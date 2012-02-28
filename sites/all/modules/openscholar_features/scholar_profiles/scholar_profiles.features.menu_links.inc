<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function scholar_profiles_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: features:people
  $menu_links['features:people'] = array(
    'menu_name' => 'features',
    'link_path' => 'people',
    'router_path' => 'people',
    'link_title' => 'People',
    'options' => array(
      'attributes' => array(
        'title' => 'List of profiles',
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
  t('People');


  return $menu_links;
}
