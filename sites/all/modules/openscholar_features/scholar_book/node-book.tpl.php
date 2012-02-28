<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>">
  <?php if ($book_toc) print $book_toc; ?>
  <div class="node-inner">
    <?php print $picture; ?>
    <?php if (!$page): ?>
      <h3 class="title">
        <a href="<?php print $node_url; ?>" title="<?php print $title ?>"><?php print $title; ?></a>
      </h3>
    <?php endif; ?>
    <?php if ($unpublished): ?>
      <div class="unpublished"><?php print t('Unpublished'); ?></div>
    <?php endif; ?>
    <?php if ($submitted or $terms): ?>
      <div class="meta">
        <?php if ($submitted): ?>
          <div class="submitted">
            <?php print $submitted; ?>
          </div>
        <?php endif; ?>
        <?php if ($terms): ?>
          <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
        <?php endif; ?>
      </div>
    <?php endif; ?>
    <div class="content">
      <?php print $content; ?>
    </div>
    <?php print $links; ?>
  </div> <!-- /node-inner -->
</div> <!-- /node -->