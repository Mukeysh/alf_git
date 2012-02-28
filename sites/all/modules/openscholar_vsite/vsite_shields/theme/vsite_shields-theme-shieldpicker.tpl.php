<?php
/**
 * template file for theming the logo picker
 * Note that this is used just for the img
 * and not the html radios
 * Variables:
 * ----------
 * $file : the whole file object  (dpm(file) to see everything
 *
 */


  $shield = t('no preview available');
  if (file_exists($file->filename)) {
    $shield = theme('imagecache', 'vsite_shields_default_shield', $file->filename);
  }
  print '<div class="item-shield-picker">'. $shield .'</div>';
