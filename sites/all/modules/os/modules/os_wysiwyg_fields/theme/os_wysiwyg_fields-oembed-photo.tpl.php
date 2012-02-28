<?php
// $Id$
/**
 * @file
 * Template file for oembed data of the photo type
 * Differs from default in that there's no div wrapper.
 */
?>
  <?php if (!empty($title)): ?>
    <?php print l($title, $original_url, array('absolute' => TRUE, 'attributes' => array('class' => 'oembed-title'))); ?>
  <?php endif; ?>
  <?php print l(theme('image', $embed->url, '', '', NULL, FALSE), $original_url, array('html' => TRUE, 'absolute' => TRUE, 'attributes' => array('class' => 'oembed-photo oembed-content'))); ?>

