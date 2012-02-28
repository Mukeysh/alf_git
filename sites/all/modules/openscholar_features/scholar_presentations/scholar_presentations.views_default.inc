<?php

/**
 * Implementation of hook_views_default_views().
 */
function scholar_presentations_views_default_views() {
  $views = array();

  // Exported view: scholar_presentations
  $view = new view;
  $view->name = 'scholar_presentations';
  $view->description = 'A list of Presentations';
  $view->tag = 'scholarfeature';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
    ),
  ));
  $handler->override_option('sorts', array(
    'sticky' => array(
      'order' => 'DESC',
      'id' => 'sticky',
      'table' => 'node',
      'field' => 'sticky',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'field_presentation_date_value' => array(
      'order' => 'DESC',
      'delta' => -1,
      'id' => 'field_presentation_date_value',
      'table' => 'node_data_field_presentation_date',
      'field' => 'field_presentation_date_value',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'presentation' => 'presentation',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'current' => array(
      'operator' => 'active',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'current',
      'table' => 'spaces',
      'field' => 'current',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'spaces_feature',
    'spaces_feature' => 'scholar_presentations',
    'perm' => 'access content',
  ));
  $handler->override_option('cache', array(
    'type' => 'os_views_content_cache',
    'keys' => array(
      'comment' => array(
        'changed' => 0,
      ),
      'node' => array(
        'presentation' => 'presentation',
        'announcement' => 0,
        'blog' => 0,
        'book' => 0,
        'class' => 0,
        'class_material' => 0,
        'event' => 0,
        'feed_fast' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'gallery' => 0,
        'image' => 0,
        'link' => 0,
        'page' => 0,
        'person' => 0,
        'profile' => 0,
        'biblio' => 0,
        'vsite' => 0,
        'sitewide_page' => 0,
        'scholar_software_project' => 0,
        'scholar_software_release' => 0,
        'vsite_users_profile' => 0,
        'bio' => 0,
        'cv' => 0,
      ),
      'os_og' => array(
        'current' => 'current',
        'user' => 0,
      ),
    ),
    'results_min_lifespan' => '-1',
    'results_max_lifespan' => '-1',
    'output_min_lifespan' => '-1',
    'output_max_lifespan' => '3600',
  ));
  $handler->override_option('title', 'Presentations');
  $handler->override_option('items_per_page', 15);
  $handler->override_option('use_pager', '1');
  $handler->override_option('distinct', 1);
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'relationship' => 'none',
    'build_mode' => 'teaser',
    'links' => 1,
    'comments' => 0,
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'presentations');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Presentations',
    'description' => 'List of presentations on my site',
    'weight' => '0',
    'name' => 'features',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Recent Presentations');
  $handler->override_option('items_per_page', 5);
  $handler->override_option('use_pager', '0');
  $handler->override_option('use_more', 1);
  $handler->override_option('use_more_always', 0);
  $handler->override_option('row_plugin', 'fields');
  $handler->override_option('row_options', array(
    'inline' => array(),
    'separator' => '',
    'hide_empty' => 1,
  ));
  $handler->override_option('block_description', 'Recent Presentations');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  return $views;
}
