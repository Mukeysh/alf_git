<div id="cp-top-admin-menus">
<?php if (!empty($tree_0)): ?>
    <?php foreach ($tree_0 as $links): ?>
      <?php print $links; ?>
    <?php endforeach; ?>
 <?php endif; ?>

<?php if (!empty($tree_1)): ?>
    <span class='close'><?php print t('Close') ?></span>
    <?php foreach ($tree_1 as $links): ?>
      <?php print $links; ?>
    <?php endforeach; ?>
<?php endif; ?>
</div>