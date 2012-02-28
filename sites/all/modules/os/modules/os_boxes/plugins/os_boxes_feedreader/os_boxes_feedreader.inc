<?php

/**
 * @file
 * The class for "CC license" type widgets.
 */

class os_boxes_feedreader extends os_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['feed'] = 'all';
    $options['number_of_items'] = 10;
    
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    
    $options = array(
      'all' => t('All')
    );
    // for each feed node, add nid/node_title to the select options
    $view = views_get_view("scholar_reader");
    $view->set_display('block_1');
    $view->execute();
    
    if (count($view->result)) {
      foreach ( $view->result as $r ) {
        $options[$r->nid] = $r -> node_title;
      }
    }
 
    $form['feed'] = array(
      '#type' => 'select',
      '#title' => t('Feed'),
      '#options' => $options,
      '#required' => TRUE,
      '#default_value' => $this->options['feed'],
      '#description' => t('Select the feed to draw items from')
    );
    
    $form['number_of_items'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of items to display'),
      '#default_value' => $this->options['number_of_items']
    );
    
    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    //@todo
    $view = views_get_view('scholar_reader');
    $view->set_display('block_2');
    $view->display_handler->set_option('items_per_page', $this->options['number_of_items']);
      
    if ($this->options['feed'] != 'all') {
      $view->set_arguments(array($this->options['feed']));
    }
    
    $block = parent::render();
    $output = $view->execute_display();
    $block['content'] = $output['content'];
    return $block;
  }
  
  /**
   * Return the cache parameters for this box
   */
  public function cache_info(){
    
    //Clear when feed,feed_item nodes are saved
    $cache_key = array(
      'os_og' => array('current' => 'current'),
      'node' => array('feed' => 'feed', 'feed_item' => 'feed_item'),
    );
    
    return array('type' => BLOCK_CACHE_CONTENT_CACHE, 'keys' => $cache_key);
  }

}