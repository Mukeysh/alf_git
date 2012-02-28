<div id="panel-viewer">
  <div id="panel-wrapper">
  <div id="front-panel-1" class="panel">
    <div class="row">
        <div id="activity">
            <?php
            $activity = views_block('view','vsite_activity-block_1');
            print '<h2>' . $activity['subject'] . '</h2>';
            print $activity['content'];
            ?>
        </div>
        <div id="publications">
          <?php
          $publications = views_block('view','scholar_publications-block_2');
          print '<h2>' . $publications['subject'] . '</h2>';
          print $publications['content'];
          ?>
        </div>
        <div id="about-abstract">
          <h2>Create a dynamic feature-full personal web site in seconds. <span class="big-button"><?php print openscholar_front_getyoursitebutton(); ?></span></h2>

          <!--
          <p class="big-button"><?php print openscholar_front_getyoursitebutton(); ?>(Faculty, Grad Students, Visiting Scholars)</p>
          -->
          <ul class="preview-points">
            <li class="first">
              <div class="illustration illust-widget"></div>
              <h3>Great features for academics</h3>

              <p>Manage your CV, bio, publications, blogs, announcements, links, image galleries, events, class materials. Automatically have your publications submitted to indices such as RePEc,
              Computer Science Repository, and Google Scholar.</p>
            </li>
            <li class="second">
              <div class="illustration illust-wrench"></div>
              <h3>Super easy-to-use admin tools</h3>
              <p>Use a web browser on any networked computer in the world to create and edit content, move useful widgets in and out of your site; change menus, categorize your work.</p>
            </li>
            <li class="third">
              <div class="illustration illust-theme"></div>
              <h3>Beautiful themes</h3>
              <p>Instantly change the look of your site with many elegant themes, or import your own custom theme.</p>
            </li>

          <li id="learn-more-toggle">
            <a href="learn-more">
              Learn more about how you can take advantage of <span><?php print variable_get('site_name', ''); ?></span>
             </a></li>
          </ul>
        </div><!--/about-abstract -->
      </div><!--/row -->
    </div><!--/panel -->
  <div id="front-panel-2" class="panel">
    <div class="row">
      <p id="activity-toggle"><a href="welcome">Recent Activity</a></p>
    </div><!--/row -->
    <div class="row row-video">
      <?php
      $video = openscholar_front_block('view','video_info');
      print $video['content'];

      ?>

      <div id="more-info">
        <?php
        $mission = openscholar_front_block('view','site_mission');
        print $mission['content'];
        ?>
      </div>
    </div><!--/row -->
    <div class="row row-features">
      <h2>Features</h2>
      <ul id="features-carousel">
        <li id="feature-academic-content">
          <h3>Create anything related to an academic site.</h3>
          <p>CV, bio, publications, blogs, announcements, links, image galleries, class materials. Easy as using a word processor.</p>
        </li>
        <li id="feature-biblio">
          <h3>Maintain an accurate and  citable bibliography of all your writings.</h3>
          <p>Automatically have your publications submitted to induces such as RePEc, Computer Science Repository, and Google Scholar.</p>
        </li>
        <li id="feature-look-feel">
          <h3>Control the look and feel of your site.</h3>
          <p>Move useful widgets in and out of your site; change menus, and overall look of your site in seconds.</p>
        </li>
        <li id="feature-collaborate">
          <h3>Collaborate with your colleagues.</h3>
          <p>Allow commentary on your work by whomever you select. Manage your Twitter feeds; keep track of colleagues work, publications and blogs.</p>
        </li>

        <li id="smart-publishing">
          <h3>Smart Publishing</h3>
          <p>The built-in content forms and WYSIWYG editor makes it simple to publish. You can begin writing content from almost anywhere on your the site.</p>
        </li>

        <li id="semantic-urls">
          <h3>Semantic URLs</h3>
          <p>All pages are given URLs which correspond to the page's <strong>title</strong>. No need to suffer with nonsensical URLs such as: "hdc.do?keyword=icomon&tabgroupid=icb.tabgroup50611". Increase visibility and optimize the availability of your sites' pages in search engines, such as <em>Google</em> and <em>Yahoo!</em> with semantic URLs.</p>
        </li>

        <li id="categorize">
          <h3>Category Tagging</h3>
          <p>Organize content and enable visitors to find pages quickly with category tagging. The tools for multi-level category tagging come standard.</p>
        </li>

        <li id="pluggable-features">
          <h3>Pluggable Features</h3>
          <p>"Out of the box ready" content features, which provide sections of your site. <strong>Features</strong> can also be set to "private", thus viewable to only members of the site.</p>
        </li>

        <li id="content-aggregation">
          <h3>Content Aggregation</h3>
          <p>Keep the web sites fresh by pulling in content from relevant sources using RSS. <strong>Scholars at Harvard</strong> provides built-in tools for RSS feeds making feeds easy to set up.</p>
        </li>

        <li id="layout-tool">
          <h3>Interactive Layout Tool</h3>
          <p>Design page layouts using a visual "drop-and-drop" blueprint of the site. The Layout Tool provides an easy (and fun!) way to arrange the content presentation on any site. Each site owner can design site-wide default layouts or create unique layouts for different sections of their site.</p>
        </li>

        <li id="sharing">
          <h3>Share With Others</h3>
          <p>Easily share web pages on other social networks such as <strong>Facebook</strong> and <strong>Twitter</strong>. Scholars have the ability to distribute bookmark links to a variety of social network sites quickly and easily.</p>
        </li>

        <li id="analytics">
          <h3>Analytics</h3>
          <p>Just provide your Google Analytics ID and data from your <strong>Scholars at Harvard</strong> site will be sent to your Goggle analytics account automatically.</p>
        </li>

      </ul>
  </div><!--/row -->
    <div class="row row-openscholar">
        <p class="docs"><strong><?php print variable_get('site_name', ''); ?></strong> includes complete <strong>documentation</strong> <?php print l('Go there now.','help/vsitehelp/OpenScholar-Documentation',array('attributes'=>array('target'=>'_blank')));?></p>
        <p class="os-link"><strong><?php print variable_get('site_name', ''); ?></strong> is build on <strong>OpenScholar</strong>, an open-source web-creation tool.  <?php print l('Learn more.','http://openscholar.harvard.edu',array('attributes'=>array('html'=>TRUE, 'target'=>'_blank')));?></p>
        <p class="big-button"><?php print openscholar_front_getyoursitebutton(); ?>(Faculty, Grad Students, Visiting Scholars)</p>

  </div><!--/row -->
 </div><!--/panel -->

</div><!--/panel wrapper -->
</div>
<?php
  //jcarousel_add($selector = '#features-carousel', $options = array(),$skin = 'os_front',$skin_path = $directory . '/carousel.css');
 ?>

<script type="text/javascript">
  $(document).ready(function() {
	  var panel1_height = $('#front-panel-1').height() + 10;
	  //var panel2_height = 1028;
	  $('#content').css({'height': panel1_height});
    $('#learn-more-toggle a').attr("href","#").click(function(event){
    	$('#content').css({
    	  height:"1028px"
    	  });
    	$('#front-panel-2').css('margin-left','0px');
    	$('#panel-wrapper').animate({
    	  marginLeft:"-990"
    	  },300);

    });
    $('#activity-toggle a').attr("href","#").click(function(event){
      $('#panel-wrapper').animate({
        marginLeft:"0"
        },{
        duration: 300,
        complete: function() {
        	$('#front-panel-2').css('margin-left','1000px');
        }
      });
      $('#content').css({
        height:panel1_height
        });
    });

   });
</script>