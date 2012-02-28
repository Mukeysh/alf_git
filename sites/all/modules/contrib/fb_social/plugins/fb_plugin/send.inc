<?php
/**
 * @file send.inc
 * 
 * Main (ctools) plugin file for "send" plugin type
 */

$plugin = array(
    'title' => t('send'), 
    'description' => t('Facebook send plugin'), 
    'html tag name' => 'send', 
    
    // hooks 
    'hook_preprocess_fb_social_plugin' => '_fb_social_send_preprocess_fb_social_plugin', 
    'hook_nodeapi_view' => '_fb_social_send_nodeapi_view', 
    'hook_field_extra_fields' => '_fb_social_send_field_extra_fields', 
    'hook_link' => '_fb_social_send_link' 
);

function send_defaults() {
  return array(
    'font' => '', 
    'colorscheme' => 'light' 
  );
}

function send_fb_settings($options) {
  
  $form = array();
  
  $form['font'] = array(
    '#type' => 'select', 
    '#title' => t('Font'), 
    '#description' => t('The font of the plugin'), 
    '#options' => array(
      'arial' => t('arial'), 
      'lucida grande' => t('lucida grande'), 
      'segoe ui' => t('segoe ui'), 
      'tahoma' => t('tahoma'), 
      'trebuchet ms' => t('trebuchet ms'), 
      'verdana' => t('verdana') 
    ) 
  );
  
  $form['colorscheme'] = array(
    '#type' => 'select', 
    '#title' => t('Color'), 
    '#description' => t('The color scheme of the plugin'), 
    '#options' => array(
      'dark' => t('dark'), 
      'light' => t('light') 
    ) 
  );
  
  $defaults = send_defaults();
  
  foreach ( $form as $id => $f ) {
    $form[$id]['#default_value'] = isset($options[$id]) ? $options[$id] : $defaults[$id];
  }
  
  return $form;

}

function send_drupal_settings($options) {
  
  $form = array();
  $form['node_types'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Content types'), 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE 
  );
  $form['node_types']['types'] = array(
    '#type' => 'checkboxes', 
    '#description' => t('Select types that will use the facebook send plugin'), 
    '#default_value' => isset($options['node_types']['types']) ? array_keys(array_filter($options['node_types']['types'])) : array(), 
    '#options' => node_get_types('names') 
  );
  
  $form['plugin_location'] = array(
    '#type' => 'fieldset', 
    '#title' => t('plugin location and display'), 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE 
  );
  $form['plugin_location']['location'] = array(
    '#type' => 'radios', 
    '#title' => t('plugin location'), 
    '#default_value' => isset($options['plugin_location']['location']) ? $options['plugin_location']['location'] : 0, 
    '#options' => array(
      t('Node links'), 
      t('Node content') 
    ), 
    '#description' => t('The plugin can be printed in the "links" are of the node or as part of the node content') 
  );
  
  $form['plugin_location']['node_view_modes'] = array(
    '#type'=>'checkboxes',
      '#title' => t('View modes'),
      '#description' => t('Select view mode where it will be displayed.'),
      '#options' => array('teaser' => t('Teaser'), 'full' => t('Full node')),
      '#default_value' => (isset($options['plugin_location']['node_view_modes']))? $options['plugin_location']['node_view_modes'] : array('full'),
  );
  return $form;

}

function _fb_social_send_preprocess_fb_social_plugin(&$variables) {
  $options = &$variables['options'];
  $options['href'] = empty($options['href']) ? $url = fb_social_url($_GET['q']) : $options['href'];
}

/**
 * content_extra_fields callback for this plugin
 */
function _fb_social_send_content_extra_fields($preset, $type_name) {
  $extras = array();
  if (fb_social_preset_node_types($preset, $type_name) && $preset->settings['plugin_location']['location']) {
    $extras['fb_social_' . $preset->plugin_type . '_' . $preset->name] = array(
      'label' => t('Facebook social:  ' . $preset->name . ' plugin'), 
      'description' => t('The "' . $preset->plugin_type . '" plugin field from ' . $preset->name . ' preset'), 
      'weight' => 15 
    );
  }
  return $extras;
}

/**
 * nodeapi_view callback for this plugin
 */
function _fb_social_send_nodeapi_view($preset, &$node, $op, $a3 = NULL, $a4 = NULL) {
  // dont disply plugin for unpublished nodes
  if (! ($node->status)) {
    return;
  }
  
  // this plugin is not enabled on this content type
  if (! fb_social_preset_node_types($preset, $node->type)) {
    return;
  }
  
  // or when it's not supposed to be displayed in the node content area
  if (! $preset->settings['plugin_location']['location']) {
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
  
  // all good ...
  $preset->fb_attrs['href'] = fb_social_url('node/' . $node->nid);
  $output = fb_social_preset_view($preset);
  
  $weight = (module_exists('content')) ? content_extra_field_weight($node->type, 'fb_social_send_' . $preset->name) : 10;
  $node->content['fb_social_send_' . $preset->name] = array(
      '#weight' => $weight, 
      '#value' => $output 
  );

}

/**
 * Pseudo hook_link for this plugin
 */
function _fb_social_send_link($preset, $type, $object, $teaser = FALSE) {
  
  $links = array();
  
  //only nodes are supported / dont like unpublished nodes
  if (('node' != $type) || (! $object->status)) {
    return $links;
  }
  
  // if no plugin on teasers continue
  if ($teaser && empty($preset->settings['plugin_location']['node_view_modes']['teaser'])) {
    return $links;
  }
  
  // if no plugin on teasers continue
  if (!$teaser && empty($preset->settings['plugin_location']['node_view_modes']['full'])) {
    return $links;
  }
  
  // plugin is not to be displayed in the node links. continue
  if ($preset->settings['plugin_location']['location']) {
    return $links;
  }
  
  // good to go
  $links = array();
  if (fb_social_preset_node_types($preset, $object->type)) {
    $preset->fb_attrs['href'] = fb_social_url('node/' . $object->nid);
    $link_title = fb_social_preset_view($preset);
    $links['fb-social-send-' . $preset->name] = array(
      'title' => $link_title, 
      'html' => TRUE 
    );
  }
  
  return $links;

}

