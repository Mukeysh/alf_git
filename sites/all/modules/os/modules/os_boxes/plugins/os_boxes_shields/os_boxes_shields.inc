<?php

/**
 * @file
 * The class for "Shield" type widgets.
 */

class os_boxes_shields extends os_boxes_default {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['shield'] = variable_get('vsite_shields_shield', '');
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){

    //The shield List
    $a_shields = variable_get('vsite_shields_shield_info', array());

    if (count($a_shields)) {
      $shield_options = array();
      $path_prefix = file_create_path().'/vsite_shields/';
      foreach ($a_shields as $fname => $shield)  {
        if (!$shield['hidden']) {
          $shield_obj = new stdClass();
          $shield_obj->filename = $path_prefix.$fname;
          if (file_exists($shield_obj->filename)) {
            $shield_options[$shield_obj->filename] = theme('vsite_shields_theme_shieldpicker', $shield_obj);
          }
        }
      }

      $form['shield'] = array(
        '#prefix' => "<div class='shield_wrapper clear-block'>",
        '#title' => t('Shield'),
        '#type' => 'radios',
        '#options' => $shield_options,
        '#default_value' => $this->options['shield'],
        // use the spaces original value, which should always be set as long as a shield has been uploaded
        '#suffix' => '</div>',
        '#pre_render' => array('os_boxes_shields_prerender'),
      );
    }
    if (empty($shield_options)) {
      $form['shield'] = array(
        '#type' => 'markup',
        '#value' => t('Your site has no shields to display.'),
        '#prefix' => '<div>',
        '#suffix' => '</div>',
      );
    }
  //END Shield List

    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    //@todo
    $block = parent::render();

  	$filename = $this->options['shield']?$this->options['shield']:variable_get('vsite_shields_shield', '');
  	if ($filename && !$this->options['disabled']) {
  	  $block['subject'] = $block['title'] = '';
  	  $block['content'] = '<div id="scholar-shield"><img src="'.url($filename, array('alias' => TRUE)).'" /> </div>';
  	}
    return $block;
  }

}

function os_boxes_shields_prerender($elements) {
  drupal_add_css(drupal_get_path('module', 'vsite_shields') . '/theme/vsite_shields-shield-picker.css');
  drupal_add_js(drupal_get_path('module', 'vsite_shields') . '/theme/vsite_shields-shield-picker.js');
  drupal_add_js(drupal_get_path('module', 'vsite_shields') . '/theme/vsite_shields.greyout.js');

  return $elements;
}