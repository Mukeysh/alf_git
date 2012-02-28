<?php

class os_boxes_follow extends os_boxes_default {

  public function options_defaults() {
    return array(
      'links' => array(),
    );
  }

  public function options_form() {
    $form = array();
    $form['#after_build'] = array('os_boxes_follow_add_externals');

    $domains = os_follow_default_networks();
    $domain_list = array();
    foreach ($domains as $d) {
      $domain_list[] = $d['title'];
    }

    $form['add'] = array(
      '#type' => 'fieldset',
      '#title' => t('Add New Profile'),
      'link_to_add' => array(
        '#type' => 'textfield',
        '#title' => t('Profile URL'),
        '#description' => t('Enter the URL of your profile on a social media site. Accepted sites are: @domains', array('@domains' => implode(', ', $domain_list))),
        '#field_suffix' => '<input type="button" class="add_new" value=" Add " />',
      ),
    );

    // build a normal form
    $form['links'] = array(
      '#type' => 'markup',
      '#tree' => TRUE,
      '#pre_render' => array('os_boxes_follow_table'),
    );

    $links = &$form['links'];
    usort($this->options['links'], 'element_sort');

    $this->options['links']['blank'] = array('title' => '__blank__', 'domain' => '', 'weight' => 2000000); // blank element for copying purposes
    foreach ($this->options['links'] as $k => $v) {
      $n = array(
        '#weight' => $v['weight'],
        'text' => array(
          '#type' => 'markup',
          '#value' => '<span class="follow-icon" style="background-position: -'.$domains[$v['domain']]['offset'].'px 0px">'.$v['title'].'</span> <a href="#" class="remove" title="Remove Link">Remove</a>',
        ),
        'domain' => array(
          '#type' => 'hidden',
          '#default_value' => $v['domain'],
        ),
        'title' => array(
          '#type' => 'hidden',
          '#default_value' => $v['title'],
        ),
        'weight' => array(
          '#type' => 'textfield',
          '#default_value' => $v['weight'],
          '#size' => 3,
          '#attributes' => array(
            'class' => (string)$k!='blank'?'field-weight':'',
          )
        ),
      );
      $links[$k] = $n;
    }

    $form['count'] = array(
      '#type' => 'hidden',
      '#default_value' => count($this->options['links'])-1,
      '#process' => array('os_boxes_follow_add_new_fields'),
    );

    return $form;
  }

  public function render() {
    $block = parent::render();
    $domains = os_follow_default_networks();
    drupal_add_css(drupal_get_path('module', 'os_boxes').'/theme/css/os_follow.css');
    $links = array();
    foreach ($this->options['links'] as $n) {
      $l = array(
        'href' => $n['title'],
        'title' => $n['title'],
        'attributes' => array(
          'class' => 'follow-icon',
          'style' => 'background-position: -'.$domains[$n['domain']]['offset'].'px 0px',
        ),
      );
      $links[$n['weight']] = $l;
    }
    ksort($links);
    $block['content'] = theme('links', $links, array('class' => 'follow-me-links'));
    return $block;
  }
}

/**
 * Adds the neccessary js to the form
 * @param unknown_type $form
 */
function os_boxes_follow_add_externals($form) {
  drupal_add_js(drupal_get_path('module', 'os_boxes').'/theme/js/os_boxes_follow.js');
  drupal_add_css(drupal_get_path('module', 'os_boxes').'/theme/css/os_follow.css');
  $networks = os_follow_default_networks();
  drupal_alter('os_follow_networks', $networks);
  drupal_add_js(array('follow_networks' => $networks), 'setting');

  return $form;
}

/**
 * Renders the list of links as a table.
 * @param unknown_type $element
 */
function os_boxes_follow_table($element) {
  // render the form as a table
  $rows = array();
  uasort($element, 'element_sort');
  foreach (element_children($element) as $c) {
    $rows[] = array(
      'data' => array(
        drupal_render($element[$c]['text']).drupal_render($element[$c]['title']).drupal_render($element[$c]['domain']),
        drupal_render($element[$c]['weight']),
      ),
      'class' => (string)$c!='blank'?'draggable':'',
    );
  }
  $element['#value'] = theme('table', array(), $rows, array('id' => 'follow-links-list'));
  drupal_add_tabledrag('follow-links-list', 'order', 'sibling', 'field-weight');
  return $element;
}

/**
 * Adds new elements to the form array so their values appear in form_state
 *
 * When we get this form back, it will have some fields added through js that weren't there
 * before. In here, we rebuild that section of the form array, and pass it through form builder
 * so form_state[values] is populated with our new fields
 * @param unknown_type $element
 * @param unknown_type $post
 * @param unknown_type $form_state
 * @param unknown_type $form
 */
function os_boxes_follow_add_new_fields(&$element, $post, &$form_state, &$form) {
  for ($i=$element['#default_value']; $i < $element['#value']; $i++) {
    $form['options']['links'][$i] = $form['options']['links']['blank'];
    $form['options']['links'][$i] += array(
      '#attributes' => array('id' => $i),
      '#parents' => array('links', $i),
      '#array_parents' => array('options', 'links', $i),
      '#tree' => TRUE,
      '#post' => $element['#post'],
    );
    form_builder($form['form_id']['#value'], $form['options']['links'][$i], $form_state);
  }
  unset($form_state['values']['links']['blank']);

  // remove nids that aren't in the post
  foreach ($form_state['values']['links'] as $k => $v) {
    if (!isset($form_state['input']['links'][$k])) {
      unset($form_state['values']['links'][$k]);
    }
  }

  return $element;
}

/**
 * Retrieves the default networks available.
 * Copied from Follow module
 *
 * @return
 *   An associative array, keyed by the machine name. The values are an array
 *   including title of the network, along with the domain to be used for
 *   input validation of the network.
 */
function os_follow_default_networks() {
  $networks = array(
    'facebook'  => array(
      'title' => t('Facebook'),
      'domain' => 'facebook.com',
      'offset' => 1056,
    ),
    'virb'      => array(
      'title' => t('Virb'),
      'domain' => 'virb.com',
      'offset' => 3232,
    ),
    'myspace'   => array(
      'title' => t('MySpace'),
      'domain' => 'myspace.com',
      'offset' => 2208,
    ),
    'twitter'   => array(
      'title' => t('Twitter'),
      'domain' => 'twitter.com',
      'offset' => 3104
    ),
    'picasa'    => array(
      'title' => t('Picasa'),
      'domain' => 'picasaweb.google.com',
      'offset' => 2368,
    ),
    'flickr'    => array(
      'title' => t('Flickr'),
      'domain' => 'flickr.com',
      'offset' => 1152,
    ),
    'youtube'   => array(
      'title' => t('YouTube'),
      'domain' => 'youtube.com',
      'offset' => 3520,
    ),
    'vimeo'     => array(
      'title' => t('Vimeo'),
      'domain' => 'vimeo.com',
      'offset' => 3200,
    ),
    'bliptv'    => array(
      'title' => t('blip.tv'),
      'domain' => 'blip.tv',
      'offset' => 352,
    ),
    'lastfm'    => array(
      'title' => t('last.fm'),
      'domain' => 'last.fm',
      'offset' => 1920
    ),
    'linkedin'  => array(
      'title' => t('LinkedIn'),
      'domain' => 'linkedin.com',
      'offset' => 1952,
    ),
    'delicious' => array(
      'title' => t('Delicious'),
      'domain' => 'delicious.com',
      'offset' => 704,
    ),
    'tumblr'    => array(
      'title' => t('Tumblr'),
      'domain' => 'tumblr.com',
      'offset' => 3072,
    ),
  );

  return $networks;
}