<?php
// $Id: mostpopular.block.inc,v 1.1 2010/12/09 19:31:15 czingerline Exp $
/*
 * Drupal Most Popular - Showcase the most popular content across your Drupal website and engage your audience.
 * Copyright © 2010 New Signature
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * You can contact New Signature by electronic mail at labs@newsignature.com –or- by U.S. Postal Service at 1100 H St. NW, Suite 940, Washington, DC 20005.
 */
/**
 * @file
 * Defines all the pages, blocks and themes for rendering the most popular
 * data to general users.
 *
 * @author Andrew Marcus
 * @since Dec 30, 2009
 */

/**
 * Renders a full page with a most popular selector and list of items.
 *
 * Calls theme('mostpopular_page', $sid, $iid).
 *
 * @param integer $sid
 *   The service ID of the currently-selected service.
 * @param integer $iid
 *   The interval ID of the currently-selected interval.
 */
function mostpopular_items_page($sid, $iid) {
  return theme('mostpopular_page', $sid, $iid);
}

/**
 * Returns a JSON object containing the items HTML in it's 'data' property.
 *
 * Calls mostpopular_get_items($sid, $iid);
 *
 * @param integer $sid
 *   The service ID of the currently-selected service.
 * @param integer $iid
 *   The interval ID of the currently-selected interval.
 */
function mostpopular_items_ajax($sid, $iid) {
  $items = mostpopular_get_items($sid, $iid);
  drupal_json(array( 'data' => $items ));
  exit;
}

/**
 * Gets a themed list of the most popular items for a given service and interval.
 *
 * Calls theme('mostpopular_items', $items, $service, $interval) to render the
 * list of items.
 *
 * Sends back a cookie so the $sid and $iid are remembered next time the block loads.
 *
 * @param integer $sid
 *   The service ID of the currently-selected service.
 * @param integer $iid
 *   The interval ID of the currently-selected interval.
 */
function mostpopular_get_items($sid = NULL, $iid = NULL) {
  $sid = (int)$sid;
  $iid = (int)$iid;

  if (empty($sid) || empty($iid)) {
    return theme('mostpopular_items_none');
  }

  // Fetch the most popular items
  $items = MostPopularItem::fetch($sid, $iid);

  // Send back a cookie storing these values
  setcookie('mostpopular', "$sid/$iid", strtotime("+1 year"), url(''));

  return theme('mostpopular_items', $items, $sid, $iid);
}

/**
 * Loads the stylesheets for the most popular block.
 *
 * Which stylesheets are loaded depends on the administrator settings.
 */
function _mostpopular_load_stylesheets() {
  switch (variable_get('mostpopular_styling', MOSTPOPULAR_STYLE_FULL)) {
    case MOSTPOPULAR_STYLE_BASIC:
      drupal_add_css(drupal_get_path('module', 'mostpopular') . '/css/mostpopular-basic.css');
      break;

    case MOSTPOPULAR_STYLE_FULL:
      drupal_add_css(drupal_get_path('module', 'mostpopular') . '/css/mostpopular-basic.css');
      drupal_add_css(drupal_get_path('module', 'mostpopular') . '/css/mostpopular-full.css');
      break;
  }
}

/**
 * The main theme function for the most popular page.  This theme loads the
 * basic stylesheet but no javascript.
 *
 * Calls theme('mostpopular_block_services', $service) to render the links to
 * other services.
 *
 * Calls theme('mostpopular_block_intervals', $interval) to render the links to
 * other intervals.
 *
 * Calls mostpopular_get_items($sid, $iid) to get the initial list of most popular
 * items.  This list can subsequently change via AJAX calls from the service or
 * interval links.
 *
 * @param integer $sid
 *   The service ID of the currently-selected service.
 * @param integer $iid
 *   The interval ID of the currently-selected interval.
 *
 * @ingroup themeable
 */
function theme_mostpopular_page($sid, $iid) {
  _mostpopular_load_stylesheets();

  // Print the tabs for services and intervals
  $tpl = '<div id="mostpopular-page" class="mostpopular">';
  $tpl .= theme('mostpopular_services', $sid, $iid);
  $tpl .= theme('mostpopular_intervals', $sid, $iid);

  $tpl .= '<div class="mostpopular--content">';
  $tpl .= mostpopular_get_items($sid, $iid);
  $tpl .= '</div>';
  $tpl .= '</div>';

  return $tpl;
}

/**
 * The main theme function for the most popular block.  This theme loads the
 * javascript helper file and a basic stylesheet.
 *
 * Calls theme('mostpopular_block_services', $service) to render the links to
 * other services.
 *
 * Calls theme('mostpopular_block_intervals', $interval) to render the links to
 * other intervals.
 *
 * Calls mostpopular_get_items($sid, $iid) to get the initial list of most popular
 * items.  This list can subsequently change via AJAX calls from the service or
 * interval links.
 *
 * @param integer $sid
 *   The service ID of the currently-selected service.
 * @param integer $iid
 *   The interval ID of the currently-selected interval.
 *
 * @ingroup themeable
 */
function theme_mostpopular_block($sid, $iid) {
  _mostpopular_load_stylesheets();

  // Load the javascript file
  drupal_add_js(drupal_get_path('module', 'mostpopular') . '/js/fade.js');
  drupal_add_js(drupal_get_path('module', 'mostpopular') . '/js/mostpopular.js');

  // Print the tabs for services and intervals
  $tpl = '<div class="mostpopular mostpopular--widget">';
  $tpl .= theme('mostpopular_services', $sid, $iid);
  $tpl .= theme('mostpopular_intervals', $sid, $iid);

  // Show the content
  $tpl .= '<div class="mostpopular--content">';
  $tpl .= mostpopular_get_items($sid, $iid);
  $tpl .= '</div>';
  $tpl .= '</div>';

  return $tpl;
}

/**
 * Themes a list of links to services.  You can apply styles to
 * class mostpopular-services.
 *
 * Each service button will be created as a link to the service for the current
 * interval.  These links point to HTML pages, and will be rewritten to point to
 * AJAX callbacks when the javascript loads.  This allows for gracefully
 * degradation of the javascript functionality.
 *
 * @param integer $sid
 *   The service ID of the currently-selected service.
 * @param integer $iid
 *   The interval ID of the currently-selected interval.
 *
 * @ingroup themeable
 */
function theme_mostpopular_services($sid, $iid) {
  $services = MostPopularService::fetchEnabled();
  $list = array();
  $list[] = array( 'data' => t('Most:'), 'class' => 'mostpopular--label');

  foreach ($services as $s) {
    // Create a default link (which will be overridden by javascript).
    $link = l($s->title, "mostpopular/items/$s->sid/$iid");

    $a = array('data' => $link);
    if ($s->sid == $sid) {
      $a['class'] = 'selected';
    }
    $list[] = $a;
  }
  return theme('item_list', $list, NULL, 'ul', array('class' => 'mostpopular--services'));
}

/**
 * Themes a list of links to intervals.  You can apply styles to
 * class mostpopular-intervals.
 *
 * Each interval button will be created as a link to the interval for the current
 * service.  These links point to HTML pages, and will be rewritten to point to
 * AJAX callbacks when the javascript loads.  This allows for gracefully
 * degradation of the javascript functionality.
 *
 * @param integer $sid
 *   The service ID of the currently-selected service.
 * @param integer $iid
 *   The interval ID of the currently-selected interval.
 *
 * @ingroup themeable
 */
function theme_mostpopular_intervals($sid, $iid) {
  $intervals = MostPopularInterval::fetchAll();
  $list = array();
  $list[] = array( 'data' => t('Past:'), 'class' => 'mostpopular--label');

  foreach ($intervals as $i) {
    // Create a default link (which will be overridden by javascript).
    $link = l($i->title, "mostpopular/items/$sid/$i->iid");

    $a = array('data' => $link);
    if ($i->iid == $iid) {
      $a['class'] = 'selected';
    }
    $list[] = $a;
  }
  return theme('item_list', $list, NULL, 'ul', array('class' => 'mostpopular--intervals'));
}

/**
 * Themes a list of the most popular items for the given service.
 *
 * Calls theme('mostpopular_item', $item, $sid, $iid) for each list item.
 *
 * @param array<MostPopularItem> $items
 *   A list of most popular items to show.
 * @param integer $sid
 *   The service ID of the currently-selected service.
 * @param integer $iid
 *   The interval ID of the currently-selected interval.
 *
 * @ingroup themeable
 */
function theme_mostpopular_items($items, $sid, $iid) {
  if (empty($items)) {
    return theme('mostpopular_items_none');
  }
  $list = array();
  foreach ($items as $item) {
    $list[] = theme('mostpopular_item', $item, $sid, $iid);
  }
  return theme('item_list', $list, NULL, 'ul', array('class' => 'mostpopular--items'));
}

/**
 * Themes an individual entry in the most popular results.  The $item includes
 * a title, url and a count of the number of times it appears within the interval.
 *
 * By default, this theme function returns HTML of the form:
 *
 * <a href='$item->url'>
 *   <span class='title'>$item->title</span>
 *   <span class='count'>($item->count times)</span>
 * </a>
 *
 * If variable mostpopular_show_count is set to false, the
 *   <span class='count'>...</span> part will not appear.
 *
 * @param MostPopularItem $item
 *   A single most popular item to show.  It will have at least the following:
 *   - title: The title of the page
 *   - url: The URL of the page
 *   - count: The number of times the page was viewed.
 * @param integer $sid
 *   The service ID of the currently-selected service.
 * @param integer $iid
 *   The interval ID of the currently-selected interval.
 *
 * @ingroup themeable
 */
function theme_mostpopular_item($item, $sid, $iid) {
  $text = '<span class="title">' . check_plain($item->title) . '</span>';

  if (variable_get('mostpopular_show_count', 1)) {
    $text .= ' <span class="count">' .
      t("(@count times)", array(
        '@count' => $item->count,
      )) .
      '</span>';
  }

  return l($text, $item->url, array('html' => TRUE ));
}


/**
 * Themes a list with no most popular items.
 *
 * @ingroup themeable
 */
function theme_mostpopular_items_none() {
  return '<p class="mostpopular--no-results">'.t('No results found').'</p>';
}