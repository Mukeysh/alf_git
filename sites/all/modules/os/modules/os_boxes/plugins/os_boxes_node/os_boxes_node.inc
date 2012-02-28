<?php

/**
 * @file
 * The class for "Node" type widgets.
 */

class os_boxes_node extends os_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();
    $options['nid'] = 0;
    $options['teaser'] = 'teaser';
    $options['show_title'] = 1;

    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){

    //@todo just for vsite for now but it can be used outside os
  	vsite_include('nodeautocomplete');
  	$default_nid = $this->options['nid'];

    if (is_string($default_nid)) {
      $default_nid = _vsite_node_autocomplete_title_to_nid($default_nid);
    }//Convert to nid;

    $form['nid'] = vsite_node_autocomplete_element($title = NULL);
    $form['nid']['#default_value'] = ((int)$default_nid != 0)?_vsite_node_autocomplete_nid_to_title($default_nid):"";
    $form['nid']['#description'] .= '<br />'.l('Edit Post', 'node/'.$default_nid.'/edit', array('attributes' => array('class' => 'edit-node', 'target' => '_blank')));
    $form['nid']['#pre_render'][] = 'os_boxes_node_autocomplete_prerender';
    $form += parent::options_form();

    $form['teaser'] = array(
      '#type' =>  'radios',
      '#title' => 'Display Mode',
      '#default_value' => $this->options['teaser'],
      '#options' => array('teaser'=>'Teaser Only', 'full'=>'Full Post'),
      '#description' => 'Display entire post in this widget or just the teaser.',
    );

    $form['show_title'] = array(
      '#type' =>  'checkbox',
      '#title' => 'Display title of this post',
      '#default_value' => $this->options['show_title'],
    );

    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {

    $block = parent::render();

    if (($vsite = vsite_get_vsite()) == FALSE) {
      return $block;
    }

    $nid = $this->options['nid'];
    //nid is saved as "title [nid:$NID]".  extract the number.
    vsite_include('nodeautocomplete');
    if (is_string($nid)) {
      $nid = _vsite_node_autocomplete_title_to_nid($nid);
    }

    if((int)$nid != 0){
      $node = node_load($nid);
    }//valid nid?

    if($node){
      $teaser = ($this->options['teaser'] == 'teaser') ? TRUE : FALSE;

      if(isset($this->options['show_title']) && !$this->options['show_title']){
      	$node->title = '';//Hide the nide title
      }

      $output = node_view($node, $teaser, FALSE, FALSE);
      $block['content'] = $output;
    }

    return $block;
  }

  /**
   * Return the cache parameters for this box
   */
  public function cache_info(){

  	//Clear any time the site is saved
    $cache_key = array(
      'os_og' => array('current' => 'current'),
    );

    return array('type' => BLOCK_CACHE_CONTENT_CACHE, 'keys' => $cache_key);
  }

}

function os_boxes_node_autocomplete_prerender($element) {
  drupal_add_js(drupal_get_path('module', 'os_boxes').'/theme/js/os_boxes_node.js');
  return $element;
}