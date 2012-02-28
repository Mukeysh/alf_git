<?php

/**
 * @file
 * The base class for OS custom widgets. It defines an "abstract box"
 * to be extended by  "real boxes" like "listings", "feeds", "images" etc.
 *
 * It provides the widget visibility optoins. Users will decide where the
 * widget will be shown (i.e. in the current section / feature or everywhere in
 * the site
 *
 * One idea would be to even remove the widget visiblity options from here and
 * let the higher layers to deal with it
 */


abstract class os_boxes_default extends boxes_box {
  
  /*
   * Define the default region for this box.
   */
  public $region;
  
  /*
   * If this box has been overridden the changed timestamp will be held here
   */
  public $changed;
  
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    return array(
      'visibility' => 'feature',
    );
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form() {
    if (filter_access($this->options['format'])) {
      $form['display_type'] = array(
        '#type' => 'value',
        '#title' => t('Visibility settings'),
        '#default_value' => $this->options['visibility'],
        '#options' => array(
            //@todo *this* should be dynamic (i.e "publications section")
            'page' => t('this page only'), // i.e. node view
            'feature' => t('Show only in *this* section'),
            'all' => t('Show everywhere in my site')),
      );

      return $form;
    }
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    $title = isset($this->title) ? check_plain($this->title) : NULL;
    $block['title'] = $title;
    $block['subject'] = $title;
    $block['delta'] = $this->delta;
    return $block;
  }
    
  /**
   * Custom submit hander to perform post_submit actions
   */
  public static function options_submit(&$form,&$form_state){
  	
  }
  
  /**
   * Custom submit hander to perform post_submit actions
   */
  public static function options_validate(&$form,&$form_state){
    
  }
}
