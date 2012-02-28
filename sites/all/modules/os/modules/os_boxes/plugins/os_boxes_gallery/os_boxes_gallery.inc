<?php

/**
 * @file
 * The class for "Gallery" type widgets.
 */

class os_boxes_gallery extends os_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['gallery'] = 'all';
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
   
    // for each gallery node, add nid/node_title to the select options
    $view = views_get_view("scholar_image_gallery");
    $view->set_display('page_1'); //block 1 showed all content
    $view->execute();
    
    if (count($view->result)) {
      foreach($view->result as $r) {
        $options[$r->nid] = $r->node_title;
      }
    } 
    
    $form['gallery'] = array(
      '#type' => 'select',
      '#title' => t('Gallery'),
      '#options' => $options,
      '#required' => TRUE,
      '#default_value' => $this->options['gallery'],
      '#description' => t('Select a gallery to draw the images from')
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
    $view = views_get_view('scholar_image_gallery');
    $view->set_display('block_1');
    $view->display_handler->set_option('items_per_page', (int)$this->options['number_of_items']);
      
    if ($this->options['gallery'] != 'all') {
      $view->set_arguments(array($this->options['gallery']));
    }
      
    $block = parent::render();
    $output = $view->execute_display();
    if(is_array($output) && isset($output['content'])){
      $block['content'] = $output['content'];
    }
    return $block;
  }
  
  /**
   * Return the cache parameters for this box
   */
  public function cache_info(){
    
    //Clear when image,gallery nodes are saved
    $cache_key = array(
      'os_og' => array('current' => 'current'),
      'node' => array('image' => 'image', 'gallery' => 'gallery'),
    );
    
    return array('type' => BLOCK_CACHE_CONTENT_CACHE, 'keys' => $cache_key);
  }

}
