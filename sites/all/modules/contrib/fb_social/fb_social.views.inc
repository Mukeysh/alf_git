<?php

/**
 * @file
 * fb_social_like.views.inc
 */

/**
 * Implementation of hook_views_data()
 */
function fb_social_views_data() {
  $data = array();
  
  $data['node']['fb_social'] = array(
    'group' => t('Node'), 
    'field' => array(
      'title' => t('fb social preset'), 
      'help' => t('Provide the fb_social presets as a view field'), 
      'handler' => 'fb_social_handler_field' 
    ) 
  );
  
  $data['users']['fb_social'] = array(
    'group' => t('User'), 
    'field' => array(
      'title' => t('fb social preset'), 
      'help' => t('Provide the fb_social presets as a view field'), 
      'handler' => 'fb_social_handler_field' 
    ) 
  );
  
  return $data;
}

/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */

function fb_social_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'fb_social') . '/plugins/views' 
    ), 
    'handlers' => array(
      'fb_social_handler_field' => array(
        'parent' => 'views_handler_field' 
      ) 
    ) 
  );
}

