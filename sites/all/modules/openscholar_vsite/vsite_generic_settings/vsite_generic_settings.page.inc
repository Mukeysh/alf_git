<?php

function vsite_generic_settings_get_settings($reset = FALSE) {
  static $settings;

  if (!isset($settings) || $reset) {
    $settings = module_invoke_all('vsite_generic_settings');
  }

  return $settings;
}

function vsite_generic_settings_form($form_state) {
  $form = array(
  	'#title' => "Other Settings",
    '#validate' => array(),
    '#submit' => array(),
  );

  $a_settings = vsite_generic_settings_get_settings();
  foreach ($a_settings as $s_key => $setting) {
    if (!isset($setting['form'])) continue;

    if (isset($setting['group'])) {
      $id = $setting['group']['#id'];
      $elem = isset($form[$id])?$form[$id]:array('#type' => 'fieldset') + $setting['group'];
      $elem[$s_key] = $setting['form'];
      $form[$id] = $elem;
    }
    else {
      $form[$s_key] = $setting['form'];
    }

    if (is_array($setting['validate'])) {
      $form['#validate'] = array_merge($form['validate'], $setting['validate']);
    }
    if (is_array($setting['submit'])) {
      $form['#submit'] = array_merge($form['#submit'], $setting['submit']);
    }
    if (is_array($setting['css'])) {
      foreach ($setting['css'] as $file) {
        drupal_add_css($file);
      }
    }
    if (is_array($setting['js'])) {
      foreach ($setting['js'] as $file) {
        drupal_add_js($file);
      }
    }
  }

  // aggregates the access values for every element
  // if even one element is accessible, the group is accessed
  foreach (element_children($form) as $elem) {
    $children = element_children($form[$elem]);
    if (!count($children)) {
      $form[$elem]['#access'] = false;
    }
    else {
      foreach ($children as $elem2) {
        $elem2 = $form[$elem][$elem2];
        $elem2['#access'] = !isset($elem2['#access']) || $elem2['#access'];
        $form[$elem]['#access'] = $form[$elem]['#access'] || $elem2['#access'];
      }
    }
  }

  return system_settings_form($form);
}

