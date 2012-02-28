<?php
// $Id: os_performance.views.inc,v 1.2.2.1 2010/07/24 13:44:24 darthsteven Exp $

function os_views_content_cache_views_plugins() {
  return array(
    'cache' => array(
      'os_views_content_cache' => array(
        'path' => drupal_get_path('module', 'os_views_content_cache') . '/views',
        'title' => t('OpenScholar Content Based'),
        'help' => t('Advanced content based caching options for views in OpenScholar.'),
        'handler' => 'os_views_content_cache_plugin',
        'uses options' => TRUE,
        'parent' => 'views_content_cache',
      ),
    ),
  );
}
