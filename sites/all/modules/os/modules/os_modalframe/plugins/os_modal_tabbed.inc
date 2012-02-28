<?php

class os_modal_tabbed extends os_boxes_modalframe {

  protected function config_path() {
    return 'cp/os-modalframe/'.($this->delta?$this->delta:('boxes_add__'.$this->plugin_key));
  }

  public function form_alter(&$form, &$form_state) {
    $this->delta = $form_state['box']->delta;
    parent::form_alter($form, $form_state);
    unset($form['submit']['#attributes']);
  }

  public static function submit(&$form, &$form_state) {
    $vals = &$form_state['values'];

    $qt = array(
      'machine_name' => strtolower(str_replace(' ', '_', $vals['description'])),
      'ajax' => 0,
      'hide_empty_tabs' => 0,
      'title' => $vals['description'],
      'tabs' => array(),
    );

    foreach ($vals['tabs'] as $k => $t) {
      if ($k == 'tab-new' || $t['bid'] == 'os_modal_tabbed-remove') continue;
      $qt['tabs'][$t['weight']] = $t;
    }

    ksort($qt['tabs']);
    reset($qt['tabs']);
    $qt['default_tab'] = key($qt['tabs']);
    $vals['box']['qt_obj'] = $qt;
    $vals['box']['title'] = $vals['title'];
    $vals['box']['description'] = $vals['description'];

    return parent::submit($form, $form_state);
  }

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_form();
    $options['qt_obj'] = array(
      'default_tab' => FALSE,
      'tabs' => array(),
    );
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form() {
    $form = parent::options_form();

    $widgets = vsite_layout_get_widgets();
    //vsite_layout_ui_check_for_disabled_widgets($widgets);

    // filter out factories
    $options = array('os_modal_tabbed-remove' => t('No Widget'));
    foreach ($widgets as $wgt => $info) {
      if ($info['factory']) {
        unset($widgets[$wgt]);
      }
      else {
        $options[$wgt] = $info['label'];
      }
    }

    $qt = (array)$this->options['qt_obj'];
    $existing = $qt['tabs'];
    if (!count($existing)) {
      $existing[] = array(
        'type' => 'block',
        'title' => t('First Tab'),
        'weight' => 0,
        'delta' => 'os_modal_tabbed-remove',
      );
    }
    $new_tab = array(
      'type' => 'block',
      'title' => 'New Tab',
      'weight' => '200000 new',  // special case
      'delta' => 'os_modal_tabbed-remove',
    );
    $tabs_data = array_merge($existing, array('new' => $new_tab));

    $links = array();

    $form['tabs'] = array(
      '#prefix' => '<div id="tabs">',
      '#suffix' => '</div>',
      '#tree' => TRUE,
      '#description' => t('Drag the tabs to reorder them. Whichever tab is on the left will be the open tab when a user visits the page.'),
    );
    foreach ($tabs_data as $k => $t) {
      $id = 'tab-'.$k;
      $links[$t['weight']] = array(
        'href' => '',
        'fragment' => $id,
        'external' => TRUE,
        'title' => $t['title'],
      );

      $form['tabs'][$id] = array(
        '#type' => 'fieldset',
        '#attributes' => array('id' => $id, 'class' => 'panel'),
        '#weight' => 1,
        'bid' => array(
          '#type' => 'select',
          '#title' => t('Widget to Display in this Tab'),
          '#options' => $options,
          '#default_value' => $t['bid'],
          '#description' => t('Choose which widget to display in this tab. Select \'No Widget\' to remove this tab.'),
          '#attributes' => array('class' => 'tab-delta'),
        ),
        'title' => array(
          '#title' => t('Title of the Tab'),
          '#type' => 'textfield',
          '#default_value' => $t['title'],
          '#attributes' => array('class' => 'tab-title'), // for js
        ),
        'weight' => array(
          '#type' => 'hidden',
          '#default_value' => $t['weight'],
          '#attributes' => array('class' => 'tab-weight'),  // for js
        ),
        'type' => array(
          '#type' => 'value',
          '#value' => 'block',
        ),
      );
    }

    ksort($links);
    $form['tabs']['links'] = array(
      '#pre_render' => array('os_modal_tabbed_links_prerender'),
      '#value' => $links,
      '#weight' => 0,
    );

    // stores the number of real tabs
    // as soon as user picks a widget, this is incremented with js
    $form['tab_count'] = array(
      '#type' => 'hidden',
      '#default_value' => count($existing),
      '#process' => array('os_modal_tabbed_add_new_tabs'),
    );

    $form['#after_build'][] = 'os_modal_tabbed_add_form_externals';

    return $form;
  }

  /**
   * Implementation of render().
   */
  public function render() {
      $block = parent::render();

      $plugin = context_get_plugin('reaction', 'block');
      $qt = $this->options['qt_obj'];
      foreach ($qt['tabs'] as $k => &$t) {
        if ($b = $plugin->get_block($t['bid'])) {
          $b->subject = '';
          if (empty($b->content)) {
            unset($qt['tabs'][$k]);
          }
          else {
            $t['rendered'] = theme('block', $b);
          }
        }
        else {
          unset($qt['tabs'][$k]);
        }
      }
      $block['content'] = theme('quicktabs', (array)$qt);
      drupal_add_js(drupal_get_path('module', 'os_modalframe').'/theme/os_modal_tabbed_display.js');

      return $block;
  }
}

/**
 * Includes the necessary js and css
 */
function os_modal_tabbed_add_form_externals($form, &$form_state) {
  drupal_add_css(drupal_get_path('module', 'os_modalframe').'/theme/os_modal_tabbed.css');
  drupal_add_js(drupal_get_path('module', 'os_modalframe').'/theme/os_modal_tabbed_form.js');

  return $form;
}

/**
 * Runs the links through theme().
 * We do it here because $box->options_form gets called in an access function
 */
function os_modal_tabbed_links_prerender($elements) {
  $elements['#value'] = theme('links', $elements['#value']);
  return $elements;
}

/**
 * After submission, the form has no idea how many tabs were added through js
 * I find out here and add new form elements for each new one.
 * This form element is placed before tabs so that the new elements go
 * through the builder properly. Removing a tab is handled in the submit.
 * Removing a tab and adding a new one should handle the same as editting an existing
 */
function os_modal_tabbed_add_new_tabs(&$element, $post, &$form_state, &$form) {
  for ($i=$element['#default_value']; $i < $post['tab_count']; $i++) {
    $new_tab = 'tab-'.$i;
    $form['options']['tabs'][$new_tab] = $form['options']['tabs']['tab-new'];
    $form['options']['tabs'][$new_tab] += array(
      '#attributes' => array('id' => $i),
      '#parents' => array('tabs', $new_tab),
      '#array_parents' => array('options', 'tabs', $new_tab),
      '#tree' => TRUE,
      '#post' => $element['#post'],
    );
    form_builder($form['form_id']['#value'], $form['options']['tabs'][$new_tab], $form_state);
  }
  return $element;
}