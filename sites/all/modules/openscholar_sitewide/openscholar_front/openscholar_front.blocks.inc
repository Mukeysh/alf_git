<?php
/*
 * Block Implementations for the front page
 */

function _openscholar_front_block_top_links(){
  $block = array();
  $block['subject'] = t('');
  $block['content'] = openscholar_front_getyoursitebutton();
  return $block;
}

function _openscholar_front_block_site_info(){
  $block = array();
  $block['subject'] = t('');
  $front_page = url();
  $site_title = variable_get('site_name', 'OpenScholar');
  //print_r($front_page);
  //$block['content'] = '<h1>' . l(variable_get('site_name', 'OpenScholar'),$front_page) . '</h1>';
    $block['content'] = '<h1>' . '<a href="'. check_url($front_page) .'" title="'. $site_title .'">' .$site_title  .' </a></h1>';

  return $block;
}

function _openscholar_front_block_video_info(){
  $block = array();
  $block['subject'] = t('');
  $block['content'] =     '<div id="video-link">
    <object width="638" height="359"><param name="allowfullscreen" value="true" /><param name="allowscriptaccess" value="always" /><param name="movie" value="http://vimeo.com/moogaloop.swf?clip_id=9887585&amp;server=vimeo.com&amp;show_title=0&amp;show_byline=0&amp;show_portrait=0&amp;color=00ADEF&amp;fullscreen=1" /><embed wmode="opaque" src="http://vimeo.com/moogaloop.swf?clip_id=9887585&amp;server=vimeo.com&amp;show_title=0&amp;show_byline=0&amp;show_portrait=0&amp;color=00ADEF&amp;fullscreen=1" type="application/x-shockwave-flash" allowfullscreen="true" allowscriptaccess="always" width="638" height="359"></embed></object>
    </div>';
  return $block;
}

function _openscholar_front_block_site_mission() {
  $block = array();
  if (variable_get('site_mission', false)) {
    $block['subject'] = t('');
    $block['content'] =  variable_get('site_mission', false);
  }
  return $block;
}
