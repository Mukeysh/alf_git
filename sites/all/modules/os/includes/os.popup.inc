<?php

/**
 * Defines functions to make using popups generally easier
 */

/**
 * Creates a link that will open in a popup of some kind. Allows the user to choose which popup
 * method to use and not worry about how it handles
 *
 * Accepted $type's are ctools, dialog, and modalframe. An invalid type will default to ctools.
 * Each type will load the popup with the respective method:
 * 	ctools:				Ctools's own popup system
 *  dialog:				Dialog's use of jQuery modal
 *  modalframe:		Modalframe will open the link in an iframe.
 *
 * All other parameters are used the same as with ctools_ajax_text_button
 * @see ctools_ajax_text_button
 */
function os_popup_link($type, $text, $dest, $alt, $class) {
  static $added_js = false;
  if ($type == 'modalframe' && (!module_exists('modalframe') && !module_exists('os_modalframe'))) {
    $type = 'ctools';
  }
  if ($type == 'dialog' && !module_exists('dialog')) {
    $type = 'ctools';
  }
  $output = '';
  switch ($type) {
    case 'dialog':
      ctools_include('ajax');
      dialog_add_js();
      if (!$added_js) {
        drupal_add_js(drupal_get_path('module', 'os').'/js/popup.js');
        $added_js = true;
      }

      $output = ctools_ajax_text_button($text, $dest, $alt, $class, 'ctools-use-dialog');
    break;
    case 'modalframe':
      ctools_include('ajax');
      drupal_add_js(drupal_get_path('module', 'os_modalframe').'/theme/os_modalframe_links.js');

      if (strpos($dest, '/modal/') === FALSE) {
        $dest .= '/modal/';
      }
      $output = ctools_ajax_text_button($text, $dest, $alt, $class, "os-popup-modal-link");
      modalframe_parent_js();
    break;
    case 'ctools':
    default:
      ctools_include('ajax');
      ctools_include('modal');
      if (!$added_js) {
        drupal_add_js(drupal_get_path('module', 'os').'/js/popup.js');
        $added_js = true;
      }

      $output = ctools_modal_text_button($text, $dest, $alt, $class);
    break;
  }

  return $output;
}