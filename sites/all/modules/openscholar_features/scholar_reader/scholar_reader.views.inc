<?php

/**
 * Implementation of hook_views_plugins().
 */
function scholar_reader_views_plugins() {
  return array(
    'module' => 'scholar_reader',
    'access' => array(
      'scholar_reader' => array(
        'title' => t('Reader feed'),
        'help' => t('Access will be granted based on mystery magic feed logic.'),
        'handler' => 'scholar_reader_plugin_access',
        'path' => drupal_get_path('module', 'scholar_reader') .'/views',
        'uses options' => TRUE,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function scholar_reader_views_handlers() {
  return array(
    'info' => array('path' => drupal_get_path('module', 'scholar_reader') .'/views'),
    'handlers' => array(
      'scholar_reader_handler_field_description' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
