<?php


/**
 * Theme function for contextual popups.
 */
function vsite_preprocess_vsite_admin_links(&$vars) {
  $vars['links'] = theme('links',$vars['links']);
}
