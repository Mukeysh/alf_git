<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function scholar_blog_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: features:blog
  $menu_links['features:blog'] = array(
    'menu_name' => 'features',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
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
  t('Blog');


  return $menu_links;
}
