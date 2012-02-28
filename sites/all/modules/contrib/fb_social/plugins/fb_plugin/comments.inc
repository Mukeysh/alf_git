<?php
/**
 * @file comments.inc
 * 
 * Main (ctools) plugin file for "comments" plugin type
 */

$plugin = array(
  'title' => t('Comments'), 
  'description' => t('Facebook comments plugin'), 
  'html tag name' => 'comments', 
  
  // hooks 
  'hook_nodeapi_view' => '_fb_social_comments_nodeapi_view', 
  'hook_content_extra_fields' => '_fb_social_comments_content_extra_fields', 
  'hook_preprocess_fb_social_plugin' => '_fb_social_comments_preprocess_fb_social_plugin',
  'hook_link' => '_fb_social_comments_link',  
);

function comments_defaults() {
  return array(
    'numposts' => 10, 
    'width' => 550, 
    'colorscheme' => 'light', 
    'migrated' => 0 
  );
}

function comments_fb_settings($options) {
  
  $form = array();
  
  $form['numposts'] = array(
    '#type' => 'textfield', 
    '#title' => t('Number of posts'), 
    '#description' => t('The maximum number of posts to display. You can set numposts to 0 to not display any comments. (Default value is 10.)') 
  );
  
  $form['width'] = array(
    '#type' => 'textfield', 
    '#title' => t('Width'), 
    '#description' => t('The width of the Comments Box in pixels. (Default value is 550px.)') 
  );
  
  $form['colorscheme'] = array(
    '#type' => 'select', 
    '#title' => t('Color Scheme'), 
    '#description' => t('The color scheme of the plugin'), 
    '#options' => array(
      'dark' => t('dark'), 
      'light' => t('light') 
    ) 
  );
  
  //@todo move this in the fb_social module settings form
  $form['migrated'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Migrate to the new version of facebook comments'), 
    '#description' => t('If you are using the original version of the Facebook Comments box, check and the comments box will automatically switch to the new version') 
  );
  
  $defaults = comments_defaults();
  
  foreach ( $form as $id => $f ) {
    $form[$id]['#default_value'] = isset($options[$id]) ? $options[$id] : $defaults[$id];
  }
  
  return $form;

}

function comments_drupal_settings($options) {
  
  $form = array();
  $form['node_types'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Content types'), 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE 
  );
  $form['node_types']['types'] = array(
    '#type' => 'checkboxes', 
    '#description' => t('Select types that will use the facebook comments plugin'), 
    '#default_value' => isset($options['node_types']['types']) ? array_keys(array_filter($options['node_types']['types'])) : array(), 
    '#options' => node_get_types('names') 
  );
  
  $form['plugin_location'] = array(
    '#type' => 'fieldset', 
    '#title' => t('plugin location and display'), 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE 
  );
  
  $form['plugin_location']['node_view_modes'] = array(
    '#type'=>'checkboxes',
      '#title' => t('View modes'),
      '#description' => t('Select view mode where it will be displayed.'),
      '#options' => array('teaser' => t('Teaser'), 'full' => t('Full node')),
      '#default_value' => (isset($options['plugin_location']['node_view_modes']))? $options['plugin_location']['node_view_modes'] : array('full'),
  );
  
  $form['plugin_comments_count'] = array(
      '#type' => 'fieldset', 
      '#title' => t('Number of comments link'), 
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE 
  );
  
  $form['plugin_comments_count']['count'] = array(
    '#type'=>'checkbox',
      '#title' => t('Show number of comments link in the teaser view'),
      '#description' => t("If checked this will use facebook's Open Graph to get the number of comments for each 
                           node and display in the node links (e.g. '10 comments')."),
      '#default_value' => (isset($options['plugin_comments_count']['count']))? $options['plugin_comments_count']['count'] : 1,
  );
  
  $form['plugin_comments_count']['cache'] = array(
    '#type'=>'textfield',
      '#title' => t('Cache the result for'),
      '#description' => t("To speed up the page rendering time the nr of comments is cached. Enter the ammount of time (in minutes) before the cache is cleared"),
      '#default_value' => (isset($options['plugin_comments_count']['cache']))? $options['plugin_comments_count']['cache'] : 30,
  );
  
  $form['plugin_comments_seo'] = array(
      '#type' => 'fieldset', 
      '#title' => t('SEO'), 
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE 
  );
  
  $form['plugin_comments_seo']['seo'] = array(
    '#type'=>'checkbox',
      '#title' => t('Print comments (hidden) behind the comment box'),
      '#description' => t("The Facebook comments box is rendered in an iframe on the page, and most search engines will not crawl content within an iframe.
                          If checked, it will grab the comments from the graph API and render them behind the comments box"),
      '#default_value' => (isset($options['plugin_comments_seo']['seo']))? $options['plugin_comments_seo']['seo'] : 0,
  );
  
  $form['plugin_comments_seo']['nr_comments'] = array(
    '#type'=>'textfield',
      '#title' => t('Nr of comments to print'),
      '#description' => t("How many comments to grab from facebook"),
      '#default_value' => (isset($options['plugin_comments_seo']['nr_comments']))? $options['plugin_comments_seo']['nr_comments'] : 100,
  );
  
  $form['plugin_comments_seo']['cache_length'] = array(
    '#type'=>'textfield',
      '#title' => t('Cache the result for'),
      '#description' => t("To speed up the page rendering time the comments are cached. Enter the ammount of time (in minutes) before the cache is cleared"),
      '#default_value' => (isset($options['plugin_comments_seo']['cache_length']))? $options['plugin_comments_seo']['cache_length'] : 720,
  );
  
  return $form;
}

function _fb_social_comments_preprocess_fb_social_plugin(&$variables) {
  $options = &$variables['options'];
  $options['href'] = empty($options['href']) ? $url = fb_social_url($_GET['q']) : $options['href'];
}

/**
 * content_extra_fields callback for this plugin
 */
function _fb_social_comments_content_extra_fields($preset, $type_name) {
  $extras = array();
  
  if (fb_social_preset_node_types($preset, $type_name)) {
    $extras['fb_social_' . $preset->plugin_type . '_' . $preset->name] = array(
      'label' => t('Facebook social:  ' . $preset->name . ' plugin'), 
      'description' => t('The "' . $preset->plugin_type . '" plugin field from ' . $preset->name . ' preset'), 
      'weight' => 20 
    );
  }
  
  return $extras;
}

/**
 * nodeapi_view callback for this plugin
 */
function _fb_social_comments_nodeapi_view($preset, &$node, $op, $a3 = NULL, $a4 = NULL) {
  
  // dont disply plugin for unpublished nodes
  if (! ($node->status)) {
    return;
  }
  
  // this plugin is not enabled on this content type
  if (! fb_social_preset_node_types($preset, $node->type)) {
    return;
  }
  
  // we are in a page view but the settings says to display the plugin only in teaser view
  if ($a4 && empty($preset->settings['plugin_location']['node_view_modes']['full'])) {
    return;
  }
  
  // we are in a page view but the settings says to display the plugin only in teaser view
  if ($a3 && empty($preset->settings['plugin_location']['node_view_modes']['teaser'])) {
    return;
  }
  
  $preset->fb_attrs['href'] = fb_social_url('node/' . $node->nid);
  $output = fb_social_preset_view($preset);
  
  $weight = (module_exists('content')) ? content_extra_field_weight($node->type, 'fb_social_comments_' . $preset->name) : 20;
  $node->content['fb_social_comments_' . $preset->name] = array(
      '#weight' => $weight, 
      '#value' => $output 
  );

}

/**
 * Pseudo hook_link for this plugin
 */
function _fb_social_comments_link($preset, $type, $object, $teaser = FALSE) {
  $links = array();
  
  if (! $teaser || ('node' != $type)) {
    return $links;
  }

  if (! fb_social_preset_node_types($preset, $object->type)) {
    return $links;
  }
  
  if (!($preset->settings['plugin_comments_count']['count'])) {
    return $links;
  }
  
  $link_url = fb_social_url('node/' . $object->nid);
  $nr_comments = _fb_social_comments_comments_count($link_url, $preset);
  if ($nr_comments) {
    $link_title = format_plural($nr_comments, '1 comment', '@count comments');
    $links['fb-social-' . $preset->name . 'comments-count'] = array(
        'title' => $link_title, 
        'href' => fb_social_url('node/' . $object->nid), 
        'html' => TRUE 
    );
  }
  
  return $links;
}

/**
 * Get the nr of fb comments given an url (node url)
 */
function _fb_social_comments_comments_count($url, $preset) {
  $cache_key = md5('fb_social_comments_count' . $url);
  $cache_length = $preset->settings['plugin_comments_count']['cache'];
  $nr_comments = 0;
  if ($cache = cache_get($cache_key)) {
    $nr_comments = $cache->data;
  }
  else {
    $req_url = "https://graph.facebook.com/?ids=" . $url;
    $request = drupal_http_request($req_url);
    
    if ($request->code == 200) {
      $result = json_decode($request->data);
      if (isset($result->$url->comments)) {
        $nr_comments = $result -> $url -> comments;
      }
    }
    cache_set($cache_key, $nr_comments, 'cache', REQUEST_TIME + (60 * $cache_length));
  }
  
  return $nr_comments;
}

/**
 * Get comments from facebook using graph api
 */
function _fb_social_comments_seo($url, $nr_comments, $cache_length) {
  $cache_key = md5('fb_social_comments_seo' . $url);
  
  if ($cache = cache_get($cache_key)) {
    $comments = $cache->data;
  }
  else {
    $req_url = "https://graph.facebook.com/comments/?ids=" . $url;
    if ($nr_comments) {
      $req_url .= "&limit=$nr_comments";
    }
    $request = drupal_http_request($req_url);
    
    if ($request->code == 200) {
      $result = json_decode($request->data);
      $comments = _fb_social_comments_seo_view($result->$url->data);
    }
    cache_set($cache_key, $comments, 'cache', REQUEST_TIME + (60 * $cache_length));
  }
  
  return $comments;
}

/**
 * the html representation of comments 
 */
function _fb_social_comments_seo_view($comments) {
  $result = '<ul style="display:none">';
  foreach ($comments as $comment) {
    $result .= '<li>' . fb_social_comments_seo_comment_view($comment);
    if (isset($comment -> comments)){
      $result .= '<ul>';
      foreach ($comment -> comments -> data as $subcomment) {
        $result .= '<li>' . fb_social_comments_seo_comment_view($subcomment) . '</li>';
      }
      $result .= '</ul>';
    }
    $result .= '</li>';
  }

  $result .= '</ul>';
  
  return $result;
}

function fb_social_comments_seo_comment_view($comment) {
  return $comment -> message . ' - by ' . $comment -> from -> name . ' on ' . format_date(strtotime($comment -> created_time));
}

