<div id="node-<?php print $node->nid; ?>" class="<?php print $node_classes; ?>">
  <div class="node-inner">
        <div class="os-links">
      <?php print $vsite_admin_links; ?>
    </div>
    <?php if (!$page): ?>
      <h3 class="title">
        <a href="<?php print url($node->field_link_href[0]['url'],array('query' => isset($node->field_link_href[0]['query']) ? $node->field_link_href[0]['query'] : NULL, 'fragment' => isset($node->field_person_website[0]['fragment']) ? $node->field_link_href[0]['fragment'] : NULL, 'absolute' => TRUE)); ?>" title="<?php print $title ?>"><?php print $title; ?></a>
      </h3>
    <?php endif; ?>
    <?php if ($unpublished): ?>
      <div class="unpublished"><?php print t('Unpublished'); ?></div>
    <?php endif; ?>
    <?php if ($submitted): ?>
        <p class="submitted"><?php print $submitted; ?></p>
      <?php endif; ?>
     <?php if ($page): ?>
     <?php if ($terms): ?>
       <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
     <?php endif; ?>
     <?php endif; ?>
    <?php if ($content): ?>
    <div class="content">
      <?php print $content; ?>
    </div>
    <?php endif; ?>
    <?php if (!$page): ?>
      <?php if (!$teaser && $terms): ?>
      <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
      <?php endif; ?>
    <?php endif; ?>
    <?php if ($links): ?>
      <div class="links links-inline">
        <?php print $links;?>
      </div>
      <?php endif;?>
  </div> <!-- /node-inner -->
</div> <!-- /node -->