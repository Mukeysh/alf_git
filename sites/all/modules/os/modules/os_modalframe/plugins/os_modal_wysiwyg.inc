<?php

class os_modal_wysiwyg extends os_boxes_modalframe {

  protected function config_path() {
    return 'cp/os-modalframe/'.($this->delta?$this->delta:('boxes_add__'.$this->plugin_key));
  }

  public function form_alter(&$form, &$form_state) {
    parent::form_alter($form, $form_state);
    unset($form['submit']['#attributes']);
  }

  public static function submit(&$form, &$form_state) {
    return self::$latest;
  }

  // The following is copied directly from boxes_simple
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    return array(
      'body' => '',
      'format' => FILTER_FORMAT_DEFAULT,
    );
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form() {
    $form = parent::options_form();
    if (filter_access($this->options['format'])) {
      $form['body'] = array(
        '#type' => 'textarea',
        '#title' => t('Box body'),
        '#default_value' => $this->options['body'],
        '#rows' => 6,
        '#description' => t('The content of the block as shown to the user.'),
      );
      $format = filter_formats(filter_resolve_format(FILTER_FORMAT_DEFAULT));
      $form['format'][$format->format] = array('#type' => 'value', '#value' => $format->format);
      $tips = _filter_tips(variable_get('filter_default_format', 1), FALSE);
      $form['format']['format']['guidelines'] = array(
        '#title' => t('Formatting guidelines'),
        '#value' => theme('filter_tips', $tips),
      );
    }
    return $form;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function render() {
    $content = '';
    if (!empty($this->options['body']) && isset($this->options['format'])) {
      $content = check_markup($this->options['body'], $this->options['format'], FALSE);
    }
    $title = isset($this->title) ? check_plain($this->title) : NULL;
    return array(
      'delta' => $this->delta, // Crucial.
      'title' => $title,
      'subject' => $title,
      'content' => $content,
    );
  }
}