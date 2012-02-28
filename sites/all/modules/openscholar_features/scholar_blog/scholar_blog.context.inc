<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_blog_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openscholar-feature-blog';
  $context->description = 'Blogs';
  $context->tag = 'Feature';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'blog' => 'blog',
        'blog/*' => 'blog/*',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        'scholar_blog:page_1' => 'scholar_blog:page_1',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'blog',
    'block' => array(
      'blocks' => array(
        'boxes-vsite_taxonomy_fltr_cat' => array(
          'module' => 'boxes',
          'delta' => 'vsite_taxonomy_fltr_cat',
          'label' => 'Filter By Category',
          'weight' => 37,
          'region' => 'right',
        ),
        'boxes-os_addthis' => array(
          'module' => 'boxes',
          'delta' => 'os_addthis',
          'label' => 'AddThis Button',
          'weight' => 38,
          'region' => 'right',
        ),
        'views-scholar_blog-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_blog-block_1',
          'weight' => 39,
          'region' => 'right',
          'status' => '0',
          'label' => 'scholar_blog: Block',
          'type' => 'context_ui',
        ),
        'views-scholar_blog_comments-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_blog_comments-block_1',
          'weight' => 40,
          'region' => 'right',
          'status' => '0',
          'label' => 'scholar_blog_comments: Recent comments',
          'type' => 'context_ui',
        ),
        'scholar_blog-blog_rss' => array(
          'module' => 'boxes',
          'delta' => 'scholar_blog-blog_rss',
          'weight' => 20,
          'region' => 'footer',
          'label' => 'RSS Feed',
        )
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blogs');
  t('Feature');

  $export['openscholar-feature-blog'] = $context;
  return $export;
}
