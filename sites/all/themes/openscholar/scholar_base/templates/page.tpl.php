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
  <?php if ($cp_toolbar) : ?>
  <div id="top">
  	   <?php print $cp_toolbar;?>
  	 </div>
  <?php endif;?>
  <div id="page">
    <div id="page-wrapper">
      <?php if (!empty($header_top)): ?>
      <div id="header-top">
        <div class="wrap">
          <?php print $header_top; ?>
        </div>
      </div><!-- /header-top -->
      <?php endif; ?>
      <?php if ($header_main || $header_left || $header_right) : ?>
      <div id="header">
        <div class="wrap clearfix">
          <div class="hg-container">
            <?php if (!empty($header_main)): ?>
            <div id="header-main" class="column">
              <?php print $header_main; ?>
            </div><!-- /header-main -->
            <?php endif; ?>
            <?php if (!empty($header_left)): ?>
            <div id="header-left" class="column">
              <?php print $header_left; ?>
            </div><!-- /header-left -->
            <?php endif; ?>
            <?php if (!empty($header_right)): ?>
            <div id="header-right" class="column">
              <?php print $header_right; ?>
            </div><!-- /header-right -->
            <?php endif; ?>
          </div><!-- /hg-container -->
        </div><!-- /wrap -->
      </div><!-- /header -->
      <?php endif; ?>
      <?php if (!empty($navbar)): ?>
      <div id="navbar">
        <div class="wrap clearfix">
          <?php print $navbar; ?>
        </div><!--/wrap-->
      </div><!-- /navbar -->
      <?php endif; ?>
      <div id="content-area">
        <div class="wrap clearfix">
          <div class="hg-container">
          <div id="content-main" class="column<?php if (!empty($content_left)){ echo " content-left"; } if (!empty($content_right)){ echo " content-right"; } ?>">
            <?php if (!empty($admin_area) || !empty($context_links)): ?>
            <div id="admin-area">
              <?php if($vsite_section_admin_links):?><!-- TODO make it a block -->
                <?php print $vsite_section_admin_links;?>
              <?php endif; ?>
              <?php if($context_links):?><!-- TODO make ctx links a block -->
                <?php print $context_links;?>
              <?php endif; ?>              
              <?php print $admin_area; ?>
            </div><!-- /admin-area -->
            <?php endif; ?>
            <?php if (!empty($content_top)): ?>
            <div id="content-top">
	            <?php print $content_top; ?>
            </div><!-- /content-top -->
            <?php endif; ?>
            <div id="content">
            <?php if (!empty($title)): ?>
              <h2 class="title<?php if ($tabs) : print ' with-tabs'; endif;?>"><?php print $title; ?></h2>
             <?php endif; ?>
             <?php if (!empty($tabs)): ?>
              <div class="tabs"><?php print $tabs; ?></div>
              <?php endif; ?>
              <?php print $help; ?>
              <?php print $messages; ?>
              <?php print $content; ?>
            </div> <!-- /content -->
            <?php if (!empty($content_left)): ?>
            <div id="content-left">
              <?php print $content_left; ?>
            </div><!-- /content-left -->
            <?php endif; ?>
            <?php if (!empty($content_right)): ?>
            <div id="content-right">
              <?php print $content_right; ?>
            </div><!-- /content-right -->
            <?php endif; ?>
            <?php if (!empty($content_bottom)): ?>
              <div id="content-bottom">
                <?php print $content_bottom; ?>
              </div><!--/content-bottom-->
            <?php endif; ?>
            </div><!-- /content main -->
          <?php if (!empty($left)): ?>
          <div id="sidebar-first" class="sidebar column">
            <?php print $left; ?>
          </div> <!-- /sidebar-first -->
          <?php endif; ?>
          <?php if (!empty($right)): ?>
          <div id="sidebar-second" class="sidebar column">
            <?php print $right; ?>
          </div> <!-- /sidebar-second -->
          <?php endif; ?>
        </div> <!-- / hg-container -->
        </div><!--/wrap-->
      </div> <!-- / content area -->
      <div id="footer">
        <div class="wrap clearfix">
          <?php if ($footer) : ?>
            <?php print $footer; ?>
          <?php endif; ?>
          <?php
            $home_link =  l('Powered by OpenScholar','http://openscholar.harvard.edu', array('attributes' => array('class' => 'poweredby'),'html'=>TRUE));
            $login_link = theme('vsite_login_link',"Login",array('class' => 'footer-login'));
          ?>
          <p class="copy"><?php print $login_link;?> <?php if ($footer_message) { print $footer_message; } ?> <span id="powered-link"><?php print $home_link; ?></span></p><?php if(variable_get('openscholar_reportverinfo', 1)){ ?><img src="http://openscholar.harvard.edu/openscholar_lu/spacer.gif?<?php echo drupal_query_string_encode($openscholar_version_info) ?>" /><?php } ?>
        </div><!-- /wrap -->
      </div> <!-- /#footer -->
    </div><!-- /page-wrapper -->
  </div> <!-- /page -->
  <div id="extradiv"></div>
  <?php if ($closure_region): ?>
  <div id="closure-blocks"><?php print $closure_region; ?></div>
  <?php endif; ?>
  <?php print $closure; ?>
</body>
</html>