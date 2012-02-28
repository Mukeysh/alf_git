<?php

/**
 * Implementation of hook_strongarm().
 */
function vsite_comments_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_inherit_login';
  $strongarm->value = 1;
  $export['disqus_inherit_login'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_location';
  $strongarm->value = 'content_area';
  $export['disqus_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_nodetypes';
  $strongarm->value = array(
    'link' => 0,
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
  );
  $export['disqus_nodetypes'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_weight';
  $strongarm->value = '50';
  $export['disqus_weight'] = $strongarm;

  return $export;
}
