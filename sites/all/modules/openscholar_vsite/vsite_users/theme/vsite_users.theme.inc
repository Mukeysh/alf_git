<?php

/**
 * Content node submission form.
 */
function vsite_users_content_profile_node_form($form) {
  $output = "\n<div class=\"node-form\">\n";

  $buttons = drupal_render($form['buttons']);
  drupal_add_css('<style type="text/css"> .vertical-tabs { display: none; } </style>');

  $vert_tabs = drupal_render($form['vertical_tabs']);

  // Everything else gets rendered here
  // field and the submit buttons.

  $output .= "  <div class=\"standard\">\n";
  $output .= drupal_render($form);
  $output .= "  </div>\n";

  $output .= $buttons;
  $output .= "</div>\n";

  return $output;
}

/**
 * vsite_users_profile should use the cp layout
 *
 * @param $form
 * @return string
 */
function theme_vsite_users_profile_node_form($form) {
  return vsite_users_content_profile_node_form($form);
}

/**
 * Format the output of the groups or "My web sites" section in the Drupal user settings
 *
 * @param unknown_type $my_sites
 * @param unknown_type $member_sites
 */
function theme_vsite_users_list_sites($my_sites, $member_sites) {
  //TODO : Need to add proper markup/ styling

  $plural = count($my_sites) > 1 ? 's' : '';

  if ($plural) {
    $nomysites="pural";
  }
  else {
    $nomysites="single";
  }

  //print sites that I own
  if (!empty($my_sites)) {
    $output = '<p class="nomarg ' . $nomysites . '">' . "My Web Site" . $plural . ':'  . '</p>';
    $output .=  '<ul class="' . $nomysites . '">';
    foreach ($my_sites as $site) {
      $output .=  '<li>';
      $output .=  l($site['name'], $site['url']);  //should have a max of 1
      $output .=  '</li>';
    }
    $output .=  '</ul>';
  }

  else{
  $output .= '';
}

  $plural_sites = count($member_sites) > 1 ? 's' : '';
  if ($plural_sites) {
    $noothersites="pural";
    }
    else {
    $noothersite="single";
    }
    //print sites I am a member of
  if (!empty($member_sites)) {
      $output .= '<p class="nomarg ' . $noothersites . '">' . "Web site" . $plural_sites . " I am a member of:"  .'</p>';
      $output .=  '<ul class="' . $noothersites . '">';
    foreach ($member_sites as $site) {
      $output .=  '<li>';
      $output .=  l($site['name'], $site['url']);
      $output .=  '<li>';
    }
    $output .=  '<ul>';
  }
else{
  $output .= '';
}
  return $output;
}
