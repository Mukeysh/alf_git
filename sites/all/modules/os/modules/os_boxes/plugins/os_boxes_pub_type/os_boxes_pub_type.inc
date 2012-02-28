<?php

/**
 * @file
 * The class for "Publication by Type" type widgets.
 */

class os_boxes_pub_type extends os_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['whitelist'] = array('all');
    $options['display_num'] = 1;

    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    $q = db_query("SELECT tid, name FROM {biblio_types} WHERE tid > 0 AND visible = 1");
    $options = array('all' => 'Select All');
    $value = $this->options['whitelist'];
    $all = in_array('all', $value);
    while ($r = db_fetch_array($q)) {
      $options[$r['tid']] = $r['name'];
      if ($all) $value[] = $r['tid'];
    }

    $form['whitelist'] = array(
      '#type' => 'checkboxes',
      '#options' => $options,
      '#default_value' => $value,
      '#title' => t('Show the following types:'),
      '#attributes' => array('class' => 'pub_type'),
      '#description' => t('Select the types you want to appear in the widget.')
    );

    $form['display_num'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display number of items in category'),
      '#default_value' => $this->options['display_num'],
    );
    drupal_add_js(drupal_get_path('module', 'os_boxes').'/theme/js/selectAll.js');

    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    //@todo
    $block = parent::render();

    $delta = 'publication_types-block_1';
    list($name, $display_id) = explode('-', $delta);
    if ($view = views_get_view($name)) {
      if ($view->access($display_id)) {
        $view->set_display('block_1');
        if (!in_array('all', $this->options['whitelist']) || !$this->options['whitelist']['all']) {
          $filter = array(
            'operator' => 'in',
            'value' => $this->options['whitelist'],
            'group' => '0',
            'exposed' => FALSE,
            'expose' => array(
              'operator' => FALSE,
              'label' => '',
            ),
            'id' => 'tid',
            'table' => 'biblio_types',
            'field' => 'tid',
            'override' => array(
              'button' => 'Use default',
            ),
            'relationship' => 'none',
          );
          $view->set_item('block_1', 'filter', 'tid', $filter);
        }
        
        //Tie this view to this box (this tells the view to call this box's view alter)
        $view->dom_id = "boxes-".$this->delta;
        
        $output = $view->execute_display();
        $view->destroy();
        $block['content'] = $output['content'];
      }
      $view->destroy();
    }

    return $block;
  }

  /**
   * Called from views_pre_view
   *
   * @param view $view
   */
  public function views_alter(&$view, &$display_id, &$args){
  	
  	//Set the display num in the view (the count)
  	$arguments = $view->display_handler->get_option('arguments');
  	$arguments['name']['style_options']['count'] = ($this->options['display_num'])?1:0;
  	$view->display_handler->override_option('arguments', $arguments);
  }
  
  /**
   * Return the cache parameters for this box
   */
  public function cache_info(){

//    //Clear when biblio nodes are saved
//    $cache_key = array(
//      'os_og' => array('current' => 'current'),
//      'node' => array('biblio' => 'biblio'),
//    );
//
//    return array('type' => BLOCK_CACHE_CONTENT_CACHE, 'keys' => $cache_key);

  	return array(); //caching disabled so ajax pager gets init'ed
  }

}