<div id="panel-wrapper">
  <div id="front-panel-1" class="panel">
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
        <p>Your mission statement, bios, publications, a blog, image galleries, class materials and more.</p>
      </li>
      <li id="word-out">
        <h3>Get the word out.</h3>
        <p>Create project announcements, resources, links, RSS feeds.</p>
      </li>
      <li id="feature-look-feel">
        <h3>Control the look and feel of your site.</h3>
        <p>Move useful widgets in and out of your site; change menus, and the overall look of your site in seconds.</p>
      </li>
      <li id="feature-events">
      <h3>Manage your events</h3>
      <p>Easily build calendars; highlight upcoming events.</p>
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
        <p>"Out of the box ready" content features, which provide sections of your site. <strong>Features</strong> can also be set to "private", thus viewable to only members of the project.</p>
      </li>

      <li id="content-aggregation">
        <h3>Content Aggregation</h3>
        <p>Keep the web sites fresh by pulling in content from relevant sources using RSS. <strong>Projects at Harvard</strong> provides built-in tools for RSS feeds making feeds easy to set up.</p>
      </li>

      <li id="layout-tool">
        <h3>Interactive Layout Tool</h3>
        <p>Design page layouts using a visual "drop-and-drop" blueprint of the site. The Layout Tool provides an easy (and fun!) way to arrange the content presentation on any site. Each site owner can design site-wide default layouts or create unique layouts for different sections of their site.</p>
      </li>

      <li id="sharing">
        <h3>Share With Others</h3>
        <p>Easily share web pages on other social networks such as <strong>Facebook</strong> and <strong>Twitter</strong>. Project Managers have the ability to distribute bookmark links to a variety of social network sites quickly and easily.</p>
      </li>

      <li id="analytics">
        <h3>Analytics</h3>
        <p>Just provide your Google Analytics ID and data from your <strong>Projects at Harvard</strong> site will be sent to your Goggle analytics account automatically.</p>
      </li>
    </div><!--/row -->
  </div><!--/panel -->
</div><!--/panel wrapper -->

<?php
  jcarousel_add($selector = '#features-carousel', $options = array(),$skin = 'os_front',$skin_path = $directory . '/carousel.css');
 ?>
