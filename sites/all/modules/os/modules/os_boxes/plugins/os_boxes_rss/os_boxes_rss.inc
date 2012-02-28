<?php

/**
 * @file
 * The class for "RSS" type widgets.
 */

class os_boxes_rss extends os_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['content'] = 'all';
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){

    vsite_include('vsiteapi');
    $types = vsite_content_types();
    $form['content'] = array(
      '#type' => 'select',
      '#title' => t('Content Types to Display'),
      '#default_value' => $this->options['content'],
      '#options' => array(
        'all' => t('All')
      ) + array_filter($types),
    );

    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    //@todo
    $block = parent::render();

    $arg = '';
    if ($this->options['content'] != 'all') {
      $arg = '/'.$this->options['content'];
    }
    if ($image = theme('image', 'misc/feed.png', t('Syndicate content'), 'RSS')) {
      $block['content'] = l($image.' Subscribe', 'feed'.$arg, array('html' => TRUE, 'attributes' => array('class' => 'feed-icon')));
    }

    return $block;
  }

}