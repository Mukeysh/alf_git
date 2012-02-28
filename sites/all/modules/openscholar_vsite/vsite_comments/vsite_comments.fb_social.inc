<?php

/**
 * Implementation of hook_fb_social_default_presets().
 */
function vsite_comments_fb_social_default_presets() {
  $export = array();

  $fb_social_preset = new stdClass;
  $fb_social_preset->disabled = TRUE; /* Edit this to true to make a default fb_social_preset disabled initially */
  $fb_social_preset->api_version = 1;
  $fb_social_preset->name = 'vsite_comments';
  $fb_social_preset->description = 'Default Vsite Comments Preset';
  $fb_social_preset->plugin_type = 'comments';
  $fb_social_preset->settings = array(
    'node_types' => array(
      'types' => array(
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
        'modal_image' => 0,
        'page' => 0,
        'person' => 0,
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
    ),
    'plugin_location' => array(
      'node_view_modes' => array(
        'full' => 'full',
        'teaser' => 0,
      ),
    ),
    'plugin_comments_count' => array(
      'count' => 1,
      'cache' => '30',
    ),
    'plugin_comments_seo' => array(
      'seo' => 0,
      'nr_comments' => '100',
      'cache_length' => '720',
    ),
    'block' => 0,
  );
  $fb_social_preset->fb_attrs = array(
    'numposts' => '10',
    'width' => '450',
    'colorscheme' => 'light',
    'migrated' => 1,
  );
  $export['vsite_comments'] = $fb_social_preset;

  return $export;
}
