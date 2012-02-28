<?php
/**
 * template file for theming the theme_picker
 * Note that this is used just for the img, theme name and theme description
 * and not the html radios
 * Variables:
 * ----------
 * $info : the whole theme object  (dpm($info) to see everything
 * $sub_theme : the rendered select element for the subtheme
 *
 */


  $screenshot = t('no screenshoot available');
  if (file_exists($info['screenshot'])) {
    $screenshot = theme('image', $info['screenshot'], t('Screenshot for %theme theme', array('%theme' => $info['name'])), '', array('class' => 'screenshot', 'id' => 'screenshot_' . $info['theme_name']), FALSE);
  }
?>
  <?php echo $screenshot?>
  <div class="theme-info">
    <h3><?php echo $info['name'] ?></h3>
    <?php if ($sub_theme): ?>
<div style="text-align:right;">Flavors  <?php echo $sub_theme ?></div>
  <?php endif; ?>









