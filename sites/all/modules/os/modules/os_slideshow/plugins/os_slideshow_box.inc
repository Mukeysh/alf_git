<?php

/**
 * @file
 * The class for "Slideshow" type widgets.
 */

class os_boxes_slideshow extends os_boxes_default {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['gallery'] = 'all';
    $options['size'] = '480x270';
    $options['effect'] = 'scrollLeft';
    $options['style'] = '';
    $options['number_of_items'] = 10;

    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    // gallery
    $options = array(
      'all' => t('All')
    );
    // for each gallery node, add nid/node_title to the select options
    $view = views_get_view("scholar_image_gallery");
    $view->set_display('page_1'); //block 1 showed all content
    $view->execute();
    foreach ( $view->result as $r ) {
      $options[$r->nid] = $r->node_title;
    }

    $form['gallery'] = array(
      '#type' => 'select',
      '#title' => t('Gallery'),
      '#options' => $options,
      '#default_value' => $this->options['gallery'],
      '#required' => TRUE
    );

    // effect
    module_load_all_includes('views_slideshow.inc');
    $view = views_get_view('os_slideshow');

    if($view){
	    $view->set_display('default');
	    $view->init_style();

	    $function = 'views_slideshow_singleframe_views_slideshow_options_form';
	    $form_element = array();
	    $form_element_state = array();
	    $views_style_plugin = $view->style_plugin;

	    call_user_func_array($function, array(&$form_element, &$form_element_state, &$views_style_plugin));
	    //dpm($form_element);


	    $form['effect'] = $form_element['views_slideshow_singleframe']['effect'];
	    $form['effect']['#default_value'] = $this->options['effect'];
    }

    // size
    $options = array();
    $imagecache_presets = imagecache_presets();
    $tmpstr = 'os_slideshow_';
    foreach ( $imagecache_presets as $name => $presets ) {
      if ($tmpstr == substr($name, 0, strlen($tmpstr))) {
        $options[$name] = substr($name, strlen($tmpstr));
      }

    }

    $form['size'] = array(
      '#type' => 'select',
      '#title' => t('Size'),
      '#options' => $options,
      '#default_value' => $this->options['size']
    );

    //dpm($imagecache_presets);
    // nr of items
    $form['number_of_items'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of items to display'),
      '#default_value' => $this->options['number_of_items']
    );

    $form['style'] = array(
      '#title' => t('Controls Style'),
      '#type' => 'radios',
      '#options' => array('' => 'Dark', '_light' => 'Light'),
      '#default_value' => $this->options['style'],
      '#pre_render' => array('os_slideshow_box_style_thumbs'),
      '#attributes' => array('class' => 'thumbnails'),
    );

    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {

    drupal_add_css(drupal_get_path('module', 'os_slideshow').'/theme/os-slideshow'.$this->options['style'].'.css');

    $view = views_get_view('os_slideshow');
    $view->set_display('default');
    $view->display_handler->set_option('items_per_page', (int)$this->options['number_of_items']);


    $handler = $view -> display_handler;

    // override effect
    $style_opts = $handler -> options['style_options'];
    $style_opts['views_slideshow_singleframe']['effect'] = $this->options['effect'];
    $handler -> override_option('style_options', $style_opts);

    // override size (imagecache preset)
    $fields_opts = $handler -> options['fields'];
    $fields_opts['field_gallery_image_fid']['format'] = $this->options['size'] . '_default';
    $handler -> override_option('fields', $fields_opts);

    if ($this->options['gallery'] != 'all') {
      $view->set_arguments(array($this->options['gallery']));
    }

    $block = parent::render();
    $output = $view->execute_display();
    $id = str_replace('_', '-', $this->options['size']);
    $block['content'] = '<div id="' . $id. '">' .$output . "</div>";
    return $block;
  }

}

function os_slideshow_box_style_thumbs($element) {
  $element['']['#title'] .= theme('image', drupal_get_path('module', 'os_slideshow').'/theme/images/darkThumbnail.png');
  $element['_light']['#title'] .= theme('image', drupal_get_path('module', 'os_slideshow').'/theme/images/lightThumbnail.png');

  return $element;
}