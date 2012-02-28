<?php

/**
 * Theme the radio elements for the control panel
 *
 * @param fieldset $element
 * @return string html
 */
function theme_vsite_menus_radios($element) {

  $content = "";
  foreach ($element as $key => $item) {
    if (substr($key, 0, 1) == '#') continue;
    if (!strlen($content)) {
      $content .= "<table id='menu_sort_table' class='max-width-a'>";
      $content .= "<tr><th>Link Name</th><th></th><th>Menu Setting</th>";
      $content .= "<th></th></tr>";
    }

    if (array_key_exists('customizer', $item)) {
      foreach (element_children($item['customizer']) as $key) {
        unset($item['customizer'][$key]['#title'], $item['customizer'][$key]['title']['#title']); //Don't show titles
      }
      $item['menu']['#title'] = drupal_render($item['customizer']);
    }
    $content .= "<tr class='draggable'><td>{$item['menu']['#title']}</td>";
    unset($item['menu']['#title']); //Already rendered

    $content .= "<td>" . drupal_render($item['weight']) . "</td>";
    $content .= "<td>" . drupal_render($item['menu']) . "</td>";
    $content .= "<td>" . drupal_render($item['delete']) . "</td>";
    $content .= "</tr>";
  }
  $content .= "</table>";

  drupal_add_tabledrag('menu_sort_table', 'order', 'sibling', 'element-weight');

  return $content;
}
