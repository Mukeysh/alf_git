<?php

/**
 * @file
 * The class for "CC license" type widgets.
 */

class os_boxes_cclicense extends os_boxes_default {

  var $license;
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['license_type'] = '';
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){

    $this->create_license();

    $form['license_type'] = array(
      '#type' => 'select',
      '#title' => t('License Type'),
      '#options' => creativecommons_get_available_license_list(),
      '#default_value' => $this->options['license_type'],
    	'#attributes' => array('class' => 'creativecommons creativecommons-license-select'),
      '#required' => TRUE,
    );

    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    //@todo
    $this->create_license();
    $this->license->uri = $this->options['license_type'];
    $this->license->fetch();

    $block = parent::render();
    $block['content'] = $this->license->get_html();
    $block['content'] = str_replace(array('This', 'Work', ', ', 'by ', 'is'), array('These', 'Works', '', '', 'are '), $block['content']);
    return $block;
  }

  private function create_license() {
    if (!isset($this->license)) {
      $this->license = new creativecommons_license('');
      $vsite = vsite_get_vsite();
      $this->nid = $vsite->group->nid;
    }
  }

}