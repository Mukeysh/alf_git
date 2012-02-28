<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
<head>
	<!-- Enable IE9 Standards mode -->
<meta http-equiv="X-UA-Compatible" content="IE=9" >
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $body_classes; ?>">
  <div id="top">
   <?php print $cp_toolbar;?>
  </div>
  <div id="main-content">
  <?php if ($left) : ?>
  <div id="cp-sidemenu">
    <div class="frame">
      <div class="innerframe">
      <?php print $left;?>
      </div>
    </div>
  </div><!-- /cp-sidemenu -->
  <?php endif;?>
  <div id="cp-content" class="clearfix">
    <div class="frame">
      <div class="innerframe">
       <?php
         $menu_item = menu_get_item();
  //             if($context_links && !$node && $menu_item['page_callback'] != 'node_add') print $context_links; //If we have context links and are not editing/viewing a node in CP
       ?>
        <?php //main tabs ($tabs) comes in the block on the left ?>
        <?php if (!empty($title) && ($node || $menu_item['page_callback'] == 'node_add')){ ?>
          <h2 class="title<?php if ($tabs) : print ' with-tabs'; endif;?>"><?php print $title; ?></h2>
         <?php }//Only show the title on Node Pages for now ?>
        <?php if (!empty($tabs2)){ ?>
        <div class="tabs"><?php print $tabs2; ?></div>
        <?php }; ?>
        <?php print $help; ?>
        <?php print $messages; ?>
        <?php print $content; ?>
        <?php if (!empty($feed_icons)){ ?>
        <div class="feed-icons"><?php print $feed_icons; ?></div>
        <?php }; ?>
      </div>
    </div>
  </div> <!-- /cp-content -->
  <?php if ($right) : ?>
  <div id="sidebar-second">
    <div class="frame">
      <div class="innerframe">
      <?php print $right;?>
      </div>
    </div>
  </div><!-- /sidebar-right -->
  <?php endif; ?>
  </div> <!-- / main-content -->
  <div id="footer">
    <h3>OpenScholar <span>IQSS, Harvard University</span></h3>
    <ul>
      <li><?php print l('Documentation', 'help/vsitehelp/OpenScholar-Documentation');?></li>
      <li><?php print l('Feedback', 'cp/support/contact');?></li>
      <li class="last">Version <?php print $openscholar_version_info['openscholar_version'];?></li>
    </ul>
    <?php if ($footer_message){ ?>
        <div id="footer-message"><?php print $footer_message; ?></div>
    <?php }; ?>
    <?php if ($footer){ ?>
      <?php print $footer; ?>
    <?php }; ?>
  </div> <!-- /#footer -->
  <?php if ($closure_region){ ?>
    <div id="closure-blocks"><?php print $closure_region; ?></div>
  <?php }; ?>
   <!--[if lte IE 7]>
  <div id="ie-warning"><p>The control panel does not currently support Internet Explorer 7 or lower. You should update your browser to version 8 or use one of the recommended browsers. Recommended browsers are current versions of <a href="http://www.getfirefox.com">Firefox</a>, <a href="http://www.apple.com/safari">Safari</a>, or <a href="http://www.google.com/chrome">Chrome</a></p></div>
  <![endif]-->
  <?php print $closure; ?>
</body>
</html>
