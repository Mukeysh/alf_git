<?php

/**
 * Implementation of hook_default_box().
 */
function scholar_blog_default_box() {
  $export = array();
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'scholar_blog-blog_rss';
  $box->plugin_key = 'os_boxes_rss';
  $box->title = '';
  $box->description = 'Blog RSS';
  $box->options = array(
    'content' => 'blog',
  );

  $export['scholar_blog-blog_rss'] = $box;
  return $export;
}
