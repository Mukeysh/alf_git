<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function scholar_classes_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: features:classes
  $menu_links['features:classes'] = array(
    'menu_name' => 'features',
    'link_path' => 'classes',
    'router_path' => 'classes',
    'link_title' => 'Classes',
    'options' => array(
      'attributes' => array(
        'title' => 'list of classes',
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
  t('Classes');


  return $menu_links;
}
