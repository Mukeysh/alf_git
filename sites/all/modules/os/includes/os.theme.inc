<?php

// copied directly from ctools_dropdown
// just replacing an array of links with an already themed string
function theme_ctools_dropdown_content($title, $content, $image, $class) {
  // Provide a unique identifier for every dropdown on the page.
  static $id = 0;
  $id++;

  $class = 'ctools-dropdown-no-js ctools-dropdown' . ($class ? (' ' . $class) : '');

  ctools_add_js('dropdown');
  ctools_add_css('dropdown');

  $output = '';

  $output .= '<div class="' . $class . '" id="ctools-dropdown-content-' . $id . '">';
  $output .= '<div class="ctools-dropdown-link-wrapper">';
  if ($image) {
    $output .= '<a href="#" class="ctools-dropdown-link ctools-dropdown-image-link">' . $title . '</a>';
  }
  else {
    $output .= '<a href="#" class="ctools-dropdown-link ctools-dropdown-text-link">' . check_plain($title) . '</a>';
  }

  $output .= '</div>'; // wrapper
  $output .= '<div class="ctools-dropdown-container-wrapper">';
  $output .= '<div class="ctools-dropdown-container">';
  $output .= $content;
  $output .= '</div>'; // container
  $output .= '</div>'; // container wrapper
  $output .= '</div>'; // dropdown
  return $output;
}