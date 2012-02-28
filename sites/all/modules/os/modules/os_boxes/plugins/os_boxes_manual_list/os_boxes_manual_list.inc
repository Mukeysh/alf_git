<?php

class os_boxes_manual_list extends os_boxes_default {

  public function options_defaults() {
    return array(
      'nodes' => array(),
    );
  }

  public function options_form() {
    $form = array();
  	vsite_include('nodeautocomplete');
    $form['#after_build'] = array('os_boxes_manual_list_add_externals');

    $form['add'] = array(
      '#type' => 'fieldset',
      '#title' => t('Add New Post'),
      'node_to_add' => vsite_node_autocomplete_element() + array('#field_suffix' => '<input type="button" class="add_new" value="Add" />'),
    );

    // build a normal form
    $form['nodes'] = array(
      '#type' => 'markup',
      '#tree' => TRUE,
      '#pre_render' => array('os_boxes_manual_list_table'),
    );

    $nodes = &$form['nodes'];
    usort($this->options['nodes'], 'element_sort');

    $this->options['nodes']['blank'] = array('nid' => 0, 'title' => '__blank__', 'weight' => 2000000); // blank element for copying purposes
    foreach ($this->options['nodes'] as $k => $v) {
      $n = array(
        '#weight' => $v['weight'],
        'nid' => array(
          '#type' => 'hidden',
          '#default_value' => $v['nid'],
        ),
        'text' => array(
          '#type' => 'markup',
          '#value' => '<span>'.$v['title'].'</span> <a href="#" class="remove" title="Remove Post">Remove</a>',
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
      $nodes[$k] = $n;
    }
    uasort($this->options['nodes'], 'element_sort');

    $form['count'] = array(
      '#type' => 'hidden',
      '#default_value' => count($this->options['nodes'])-1,
      '#process' => array('os_boxes_manual_list_add_new_fields'),
    );

    return $form;
  }

  public function render() {
    $block = parent::render();
    $links = array();
    foreach ($this->options['nodes'] as $n) {
      $l = array(
        'href' => 'node/'.$n['nid'],
        'title' => $n['title'],
      );
      $links[$n['weight']] = $l;
    }
    ksort($links);
    $block['content'] = theme('links', $links);
    return $block;
  }
}

function os_boxes_manual_list_add_externals($form) {
  drupal_add_js(drupal_get_path('module', 'os_boxes').'/theme/js/os_boxes_manual_list.js');
  return $form;
}

function os_boxes_manual_list_table($element) {
  // render the form as a table
  $rows = array();
  uasort($element, 'element_sort');
  foreach (element_children($element) as $c) {
    $rows[] = array(
      'data' => array(
        drupal_render($element[$c]['nid']).drupal_render($element[$c]['text']).drupal_render($element[$c]['title']),
        drupal_render($element[$c]['weight']),
      ),
      'class' => (string)$c!='blank'?'draggable':'',
    );
  }
  $element['#value'] = theme('table', array(), $rows, array('id' => 'manual-nodes-list'));
  drupal_add_tabledrag('manual-nodes-list', 'order', 'sibling', 'field-weight');
  return $element;
}

function os_boxes_manual_list_add_new_fields(&$element, $post, &$form_state, &$form) {
  for ($i=$element['#default_value']; $i < $element['#value']; $i++) {
    $form['options']['nodes'][$i] = $form['options']['nodes']['blank'];
    $form['options']['nodes'][$i] += array(
      '#attributes' => array('id' => $i),
      '#parents' => array('nodes', $i),
      '#array_parents' => array('options', 'nodes', $i),
      '#tree' => TRUE,
      '#post' => $element['#post'],
    );
    form_builder($form['form_id']['#value'], $form['options']['nodes'][$i], $form_state);
  }
  unset($form_state['values']['nodes']['blank']);

  // remove nids that aren't in the post
  foreach ($form_state['values']['nodes'] as $k => $v) {
    if (!isset($form_state['input']['nodes'][$k])) {
      unset($form_state['values']['nodes'][$k]);
    }
  }

  return $element;
}