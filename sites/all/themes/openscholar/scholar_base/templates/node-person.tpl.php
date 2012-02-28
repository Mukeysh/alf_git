<?php
// this template is provided by scholar_profiles feature
?>


<div id="node-<?php print $node->nid; ?>" class="<?php print $node_classes; ?>">
  <div class="node-inner">
    <div class="os-links">
      <?php print $vsite_admin_links; ?>
    </div>

    <?php if (!$page): ?>
      <?php if ($node->field_person_photo[0]['filepath']): ?>
      <div class="flL">
        <a href="<?php print $node_url; ?>"><?php print theme('imagecache', 'square_50_50', $node->field_person_photo[0]['filepath'], $title, $title); ?></a>
       </div>
      <?php endif;?>
      <h3 class="title">
        <a href="<?php print $node_url; ?>" title="<?php print $title ?>"><?php print $title; ?></a>
      </h3>
      <?php if ($node->field_person_title[0]['value']): ?>
      <h4><?php print $node->field_person_title[0]['value'];?></h4>
      <?php endif;?>
      <?php endif;?>



 <?php if ($page): ?>
   <?php if ($node->field_person_photo[0]['filepath']): ?>
    <div class="flL">
      <?php print theme('imagecache', 'vsite_design_portrait_logo', $node->field_person_photo[0]['filepath'], $title, $title); ?>
    </div>
  <?php endif;?>
  <?php print drupal_set_title('');?>
  <h2 class="title"><?php print $title; ?></h2>
  <?php if ($node->field_person_title[0]['value']): ?>
  <h3><?php print $node->field_person_title[0]['value'];?></h3>
  <?php endif;?>

  <?php endif; ?>

    <?php if (!$teaser && $terms): ?>
    <p class="terms terms-inline"><?php print t(' in ') . $terms; ?></p>
    <?php endif; ?>

    <div class="content">
    <?php if ($node->field_person_address[0]['value'] || $node->field_person_phone[0]['value'] || $node->field_person_email[0]['value'] || $node->field_person_website[0]['url']):?>
        <?php if ($node->field_person_address[0]['value']):?>
          <p><?php print $node->field_person_address[0]['value'];?></p>
        <?php endif;?>
        <?php if ($node->field_person_phone[0]['value'] || $node->field_person_email[0]['value'] || $node->field_person_website[0]['url']) {
        print '<ul class="inline">';
        if ($node->field_person_phone[0]['value']) {
          print '<li><em>p:</em> ' . $node->field_person_phone[0]['value'] . '</li>' ;
          }
        if ($node->field_person_email[0]['value']) {
          print '<li>' . l('email', 'mailto:' . $node->field_person_email[0]['value']) . '</li>' ;
          }
        if ($node->field_person_website[0]['url']) {
          print '<li>' . l('(Website)',url($node->field_person_website[0]['url'],array('query' => isset($node->field_person_website[0]['query']) ? $node->field_person_website[0]['query'] : NULL, 'fragment' => isset($node->field_person_website[0]['fragment']) ? $node->field_person_website[0]['fragment'] : NULL, 'absolute' => TRUE))) . '</li>';
          }
        print '</ul>';
        }
       ?>
     <?php endif; ?>
     <div class="content-body">
      <?php print $content; ?>
     </div>
   </div>
  <?php print $links; ?>
  </div> <!-- /node-inner -->
</div> <!-- /node -->