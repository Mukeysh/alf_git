<div id="node-<?php print $node->nid; ?>" class="<?php print $node_classes; ?>">
  <div class="node-inner">
    <div class="os-links">
      <?php print $vsite_admin_links; ?>
    </div>
    <?php if (!$page): ?>
      <span class="title"><a href="<?php print $node_url; ?>" title="<?php print $title ?>"><?php print $title; ?></a><?php if ($node->field_presentation_location[0]['value']) { print ', '; }?></span>
      <?php if ($node->field_presentation_location[0]['value']):?>
      <span class="location"><?php print $node->field_presentation_location[0]['value']; if ($node->field_presentation_date[0]['value']) { print ', '; } ?></span>
      <?php endif; ?>
      <?php if ($node->field_presentation_date[0]['value']) {
        print $node->field_presentation_date[0]['view'];
          if ($node->field_presentation_file[0]['fid']) {
          print ': ';
          }
        }
      ?>
      <?php if ($node->field_presentation_file[0]['fid']) {
        foreach ($node->field_presentation_file as $file) {
          print $file['view'];
          }
        }
      ?>
     <?php endif; ?>
    <?php if ($page): ?>
      <?php if ($unpublished): ?>
      <div class="unpublished"><?php print t('Unpublished'); ?></div>
      <?php endif; ?>
      <?php if ($terms): ?>
      <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
      <?php endif; ?>
      <?php endif;?>
      <div class="content">
        <?php print $content; ?>
      </div>
      <?php if ($links): ?>
      <div class="links links-inline">
        <?php print $links;?>
      </div>
      <?php endif;?>
  </div> <!-- /node-inner -->
</div> <!-- /node -->