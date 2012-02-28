<?php

/**
 * @file
 * Template for the menu settings table
 */

$regions = _vsite_menus_get_menus();  // this line is why I needed to copy it

?>
<table id="fields" class="sticky-enabled">
  <tbody>
    <?php $row = 0; ?>
    <?php foreach ($regions as $region => $title): ?>
      <tr class="region region-<?php print $region?>">
        <td colspan="4" class="region"><?php print $title; ?></td>
      </tr>
      <tr class="region-message region-<?php print $region?>-message <?php print !count(element_children($element[$region])) ? 'region-empty' : 'region-populated'; ?>">
        <td colspan="4"><em><?php print ($region!='none')?t('No links in this menu'):t('Drag links here to hide or delete them.'); ?></em></td>
      </tr>
      <?php if (!empty($element[$region])): ?>
        <?php foreach ($element[$region] as $field => $data): ?>
          <?php
            if (substr($field, 0, 1) == '#') {
              continue;
            }
          ?>
        <tr class="draggable <?php print $row % 2 == 0 ? 'odd' : 'even'; ?>">
          <td><?php print drupal_render($data['name']) ?></td>
          <td><?php print drupal_render($data['region']) ?></td>
          <td><?php print drupal_render($data['weight']) ?></td>
        </tr>
        <?php $row++; ?>
        <?php endforeach; ?>
      <?php endif; ?>
    <?php endforeach; ?>
  </tbody>
</table>
