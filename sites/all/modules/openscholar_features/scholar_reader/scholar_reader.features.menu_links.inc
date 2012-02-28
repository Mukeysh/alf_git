<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function scholar_reader_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: features:reader
  $menu_links['features:reader'] = array(
    'menu_name' => 'features',
    'link_path' => 'reader',
    'router_path' => 'reader',
    'link_title' => 'Feeds',
    'options' => array(
      'attributes' => array(
        'title' => 'Feed reader',
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
  t('Feeds');


  return $menu_links;
}
