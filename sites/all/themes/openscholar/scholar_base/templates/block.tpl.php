<div id="block-<?php print $block->module . '-' . $block->delta; ?>" class="<?php print $block_classes; ?>">

  <?php if ($block->subject): ?>
    <h3 class="title"><?php print $block->subject; ?></h3>
  <?php endif; ?>
  <?php if ($vsite_admin_links):?>
  <div class="os-links">
    <?php print $vsite_admin_links; ?>
  </div>
  <div class="os-links-outline"></div>
  <?php endif; ?>
  <div class="content">
    <?php print $block->content; ?>
  </div>

  <?php print $edit_links; ?>

</div> <!-- /block -->
