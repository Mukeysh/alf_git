<?php

/**
 * Implementation of hook_views_default_views().
 */
function scholar_profiles_views_default_views() {
  $views = array();

  // Exported view: scholar_profiles
  $view = new view;
  $view->name = 'scholar_profiles';
  $view->description = 'List of vsite profiles';
  $view->tag = 'scholarfeature';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('sorts', array(
    'sticky' => array(
      'order' => 'DESC',
      'id' => 'sticky',
      'table' => 'node',
      'field' => 'sticky',
      'relationship' => 'none',
    ),
    'field_person_lastname_value' => array(
      'id' => 'field_person_lastname_value',
      'table' => 'node_data_field_person_lastname',
      'field' => 'field_person_lastname_value',
    ),
    'field_person_firstname_value' => array(
      'id' => 'field_person_firstname_value',
      'table' => 'node_data_field_person_firstname',
      'field' => 'field_person_firstname_value',
    ),
  ));
  $handler->override_option('filters', array(
    'current' => array(
      'operator' => 'all',
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
        'person' => 'person',
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
  ));
  $handler->override_option('access', array(
    'type' => 'spaces_feature',
    'spaces_feature' => 'scholar_profiles',
    'perm' => 'access content',
  ));
  $handler->override_option('cache', array(
    'type' => 'os_views_content_cache',
    'keys' => array(
      'comment' => array(
        'changed' => 0,
      ),
      'node' => array(
        'person' => 'person',
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
        'presentation' => 0,
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
  $handler->override_option('title', 'Directory');
  $handler->override_option('items_per_page', 15);
  $handler->override_option('use_pager', '1');
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'relationship' => 'none',
    'build_mode' => 'teaser',
    'links' => 1,
    'comments' => 0,
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'people');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'People',
    'description' => 'List of profiles',
    'weight' => '0',
    'name' => 'features',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => 'Directory',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));

  $views[$view->name] = $view;

  return $views;
}
