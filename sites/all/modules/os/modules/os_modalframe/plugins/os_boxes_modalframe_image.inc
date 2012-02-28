<?php

class os_boxes_modalframe_image extends os_boxes_modalframe {

  protected function config_path() {
    if ($this->options['nid']) {
      return 'node/'.$this->options['nid'].'/edit';
    }
    else {
      return 'node/add/modal-image';
    }
  }

  public function options_defaults() {
    $options = parent::options_defaults();
    $options['nid'] = 0;
    return $options;
  }

  public function render() {
    $node = node_load($this->options['nid']);

    $block = parent::render();
    $img = content_format('field_modal_image', $node->field_modal_image[0], 'os_modal_image_'.$node->field_modal_image_size[0]['value'].'_default', $node);
    if (empty($node->field_link_from_image[0]['url'])) {
      $block['content'] = $img;
    }
    else {
      $out = content_format('field_link_from_image', $node->field_link_from_image[0], 'default', $node);
      $block['content'] = str_replace('[os_modalframe_image_src]', $img, $out);
    }

    $block['content'] .= check_markup($node->body, $node->format, FALSE);

    return $block;
  }

  public function form_alter(&$form, &$form_state) {
    if ($form['#id'] = 'node-form' && $form['form_id']['#value'] = 'modal_image_node_form') {

      // hide unnecessary fields
      $whitelist = array('title', 'body_field', 'field_modal_image', 'field_modal_image_size', 'field_link_from_image', 'buttons');
      module_load_include('inc', 'spaces_og', 'spaces_og.pages');
      foreach (element_children($form) as $child) {
        if ($form[$child]['#type'] != 'value' && $form[$child]['#type'] != 'hidden') {
          if (!in_array($child, $whitelist)) {
            _spaces_og_make_hidden($form[$child]);
          }
        }
      }

      $form['title']['#title'] = t('Widget Name');
      $form['title']['#description'] = t('This name will only appear in your Control Panel.');

      $form['body_field']['body']['#rows'] = 5;
      $form['body_field']['body']['#description'] = t('Enter a caption to appear underneath your image.');

      $form['widget_title'] = array(
        '#type' => 'textfield',
        '#default_value' => $this->title,
        '#title' => t('Widget Title'),
        '#description' => t('The title of the widget as shown to the user.'),
        '#weight' => -4,
      );

      if (isset($form['buttons'])) {
        $form['buttons']['#type'] = 'markup';
        $form['buttons']['preview']['#access'] = false;
        $form['buttons']['delete']['#access'] = false;
        $form['buttons']['preview_changes']['#access'] = false;
      }
      parent::form_alter($form, $form_state);
    }
  }

  static public function submit($form, $form_state) {

    $form_state['values']['box']['nid'] = $form_state['nid'];
    $form_state['values']['box']['title'] = $form_state['values']['widget_title'];
    $form_state['values']['box']['description'] = $form_state['values']['title'];
    return parent::submit($form, $form_state);
  }
}