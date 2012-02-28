<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function scholar_book_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: features:documents
  $menu_links['features:documents'] = array(
    'menu_name' => 'features',
    'link_path' => 'documents',
    'router_path' => 'documents',
    'link_title' => 'Documents',
    'options' => array(
      'attributes' => array(
        'title' => 'list of documents',
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
  t('Documents');


  return $menu_links;
}
