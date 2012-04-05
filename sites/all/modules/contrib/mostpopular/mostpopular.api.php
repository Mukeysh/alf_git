<?php
// $Id: mostpopular.api.php,v 1.1 2010/12/09 19:31:15 czingerline Exp $
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
 * Provides functions for other modules to use to interact with the
 * Most Popular data.
 *
 * @author Andrew Marcus
 * @since Dec 30, 2009
 */

// Load the classes
module_load_include('php', 'mostpopular', 'classes/intervals');
module_load_include('php', 'mostpopular', 'classes/services');
module_load_include('php', 'mostpopular', 'classes/lastrun');
module_load_include('php', 'mostpopular', 'classes/items');

/**
 * Defines hook_mostpopular_service() and provides an empty implementation.
 *
 * @param string $op
 *   The operation to perform.
 *   - list: returns an array containing definitions of each available service.
 *   - refresh: invokes one particular service and returns an array of results.
 *   - throttles: returns a list of the default throttles to use for the given
 *     set of intervals.
 *   - config: returns a form with specific elements for configuring the
 *     service.
 * @param mixed $delta
 *   Identifiers which service to use, if this function defines more than one.
 * @param array $options
 *   Values associated with this $op.
 *   - For 'refresh': $options is an array containing:
 *     - sid: The internal service ID of the running service.
 *     - iid: The internal interval ID of the running interval.
 *     - ts: The timestamp from which to start the search.
 *     - last_run: The timestamp of the last time this service was run
 *       for the particular interval in question.
 *     - max: The maximum number of results to retrieve.
 *   - For 'throttles': $options is an array of strtotime() values representing
 *     the current list of intervals.
 *
 * @return mixed
 *   The return values depends on $op.
 *   - For 'list': returns an array where each delta is a key and each value is
 *     an array containing:
 *     - name: The unique name of the service.
 *     - title: The default title to show users for this service.
 *   - For 'refresh': returns an array of most popular items, where each item is
 *     an array containing:
 *     - title: The page title.
 *     - url: The URL of the page within Drupal.
 *     - count: The number of times the page was accessed.
 *     - nid: If this is a node, the ID of the node.
 *   - For 'config': returns a Form API contribution to the configuration form
 *     for the service.
 *   - For 'throttles': returns an array where the keys are the same interval
 *     IDs provided in the $options array, and the values are strings parseable
 *     by strtotime() which will be applied to the last time the service was run
 *     to see whether it can run again.  These are defaults only; administrators
 *     can adjust these throttles.
 */
function hook_mostpopular_service($op, $delta = 0, $options = array()) {
  switch ($op) {

    // Returns a list of all of the services defined by this module
    case 'list':
      return array(
        'viewed' => array(  // The delta to use
          'name' => t('My Service'), // Unique name for administrators
          'title' => t('Viewed'), // Default name for users
        ),
      );
      break;

    // Connects to some internal or external query to get the list of
    // most popular items.
    case 'refresh':
      switch ($delta) {
        case 'viewed':
          // Get a list of page URLs
          $pages = get_urls();
          foreach ($pages as $page) {
            $url = $page['url'];
            $count = $page['count'];

            /*
             * Optionally, match each returned URL to a node.
             *
             * We typically only care about the most popular nodes, so if
             * a service returns URLs to pages that aren't nodes, we shouldn't
             * include them.  Your service can call this API function to help
             * you out.   However, if you do this, you should make sure you
             * request more than the max number of results from the service,
             * so that you can still end up with the right number even after
             * some of them have been filtered out.
             */
            $obj = mostpopular_match_result_nodes($url, $count);
            if (isset($obj)) {
              $out[] = $obj;
            }

            // Once we've found the max number of results, we're done!
            if (count($out) >= $options['max']) {
              break;
            }
          }
          return $out;
      }
      return FALSE;  // Indicates there are no results

    // Returns a part of the configuration form for this service
    case 'config':
      $form = array();
      $form['auth'] = array(
        '#type' => 'fieldset',
        '#title' => t('Service login credentials'),
        'myservice_username' => array(
          '#type' => 'textfield',
          '#title' => t('User Name'),
          '#default_value' => variable_get('myservice_username', ''),
        ),
        'myservice_password' => array(
          '#type' => 'textfield',
          '#title' => t('Password'),
          '#default_value' => variable_get('myservice_password', ''),
        ),
      );
      return $form;

    // Returns a list of default throttles for this service
    case 'throttles':
      switch ($delta) {
        case 'viewed':
          $out = array();
          foreach ($options as $iid => $ts) {

            // Determine the interval based on the starting timestamp
            if ($ts >= strtotime('-1 day -10 minutes')) { // add a buffer
              $out[$iid] = '1 hour';
            }
            elseif ($ts <= strtotime('-1 year')) {
              $out[$iid] = '1 week';
            }
            else {
              $out[$iid] = '1 day';
            }
          }
          return $out;
      }
   }
}

/**
 * Clears all of the cached values from services, and resets the last time the
 * service was run to 0.
 *
 * @param integer $sid
 *   The service ID.  If null, all services will be cleared.
 * @param integer $iid
 *   The interval ID.  If null, all intervals will be cleared.
 */
function mostpopular_clear_caches($sid = NULL, $iid = NULL) {
  MostPopularService::clear();
  MostPopularLastRun::clear();
  MostPopularLastRun::resetLastRun($sid, $iid);
  MostPopularItem::reset($sid, $iid);

  drupal_set_message(t('The most popular caches have been cleared for %service and %interval. ' .
    'You should refresh the stats.',
  array(
    '%service' => empty($sid) ? 'all services' : MostPopularService::fetch($sid)->title,
    '%interval' => empty($iid) ? 'all intervals' : MostPopularInterval::fetch($iid)->title,
  )));
}

/**
 * Matches the given URL to a Drupal node, resolving aliases appropriately.
 * The homepage will never be included in this list.
 *
 * The URL can be an internal URL or it can start with one of the configured
 * Drupal base paths, which will be stripped from the URL before the alias is
 * resolved.
 *
 * If the URL corresponds to a node, an array will be returned with properties
 * of that node from the most popular service.
 *
 * @param string $url
 *   A URL to match.  This can be either an internal Drupal URL or it can start
 *   with one of the configured site basepaths.
 * @param integer $count
 *   The number of times this node appears.
 *
 * @return array
 *   If the url corresponds to a node, returns an array containing:
 *     - nid: the nid of the node.
 *     - title: the title of the node, fetched from the node itself.
 *     - url: the internal Drupal path of the node.
 *     - count: the number of times the node was referenced by the service.
 *   Otherwise, returns NULL.
 */
function mostpopular_match_result_nodes($url, $count) {
  $url = trim($url);

  // Strip out the base path from the URL.
  $basepaths = variable_get('mostpopular_basepaths', array());
  foreach ($basepaths as $base) {
    if (stripos($url, $base) === 0) {
      $url = drupal_substr($url, drupal_strlen($base));
      break;
    }
  }
  // Strip off any leading slashes
  if (stripos($url, '/') === 0) {
    $url = drupal_substr($url, 1);
  }

  // If the URL points to an excluded path, ignore it.
  $excludepaths = array_flip(variable_get('mostpopular_exclude_paths', array()));
  if (empty($url) || isset($excludepaths[$url])) {
    return NULL;
  }

  // Get the internal path for the URL alias.
  $path = drupal_get_normal_path($url);

  // If the URL points to an excluded path, ignore it.
  if (isset($excludepaths[$path])) {
    return NULL;
  }

  // Return only the paths that point to nodes.
  if (preg_match('/^\/?node\/(\d+)$/', $path, $matches)) {
    $nid = (int)$matches[1];
    $node = node_load($nid);

    if (!empty($node)) {
      return array(
        'nid' => $nid,
        'title' => $node->title,
        'url' => "node/$nid",
        'count' => $count,
      );
    }
  }
  return NULL;
}

/**
 * Gets the service ID for the service defined by the given module and delta.
 *
 * @param string $module
 *   The module defining the service.
 * @param string $delta
 *   The delta of the service within the module.
 *
 * @return integer
 *   The service ID of the service, or NULL of no matching service could be found.
 */
function mostpopular_get_sid_for_module($module, $delta) {
  $service = MostPopularService::fetchByModule($module, $delta);
  if (isset($service)) {
    return $service->sid;
  }
  return NULL;
}

/**
 * Gets the last time the given service was run for the given interval.
 * If no interval is specified, gets the most recent time for any interval.
 *
 * @param integer $sid
 *   The service ID.
 * @param integer $iid
 *   The interval ID.
 *
 * @return integer
 *   The timestamp of the last time the service was run.  If it was never run,
 *   returns 0.
 */
function mostpopular_get_last_run($sid, $iid) {
  $run = MostPopularLastRun::fetch($sid, $iid);
  if (isset($run)) {
    return $run->last_run;
  }
  return 0;
}

/**
 * Gets the throttle setting for the given service and interval.
 *
 * @param integer $sid
 *   The service ID.
 * @param integer $iid
 *   The interval ID.
 *
 * @return string
 *   The throttle setting for the given service and interval.  If there is one,
 *   it will be a string parseable by strtotime().  Otherwise, returns NULL.
 */
function mostpopular_get_throttle($sid, $iid) {
  $run = MostPopularLastRun::fetch($sid, $iid);
  if (isset($run)) {
    return $run->throttle;
  }
  return NULL;
}

/* ----------------------------------------------------------------------------
 * Cron jobs to fetch stats
 * --------------------------------------------------------------------------*/
/**
 * Implements hook_cron().
 *
 * Refreshes data from the services periodically.
 */
function mostpopular_cron() {
  $t = mostpopular_refresh();
  watchdog('mostpopular_cron', $t);
}

/**
 * Refreshes data from each service by invoking
 * hook_mostpopular_service('refresh').
 */
function mostpopular_refresh() {
  $services = MostPopularService::fetchEnabled();
  $intervals = MostPopularInterval::fetchAll();
  $max = variable_get('mostpopular_max', 5);
  $t = '';

  foreach ($services as $service) {
    $count = 0;

    $t .= '<div>';
    $t .= t("Refreshing %title", array(
      '%title' => $service->title,
    ));
    $status = array();

    foreach ($intervals as $interval) {

      // Get the last time this service was run
      $run = MostPopularLastRun::fetch($service->sid, $interval->iid);

      // Apply the throttle if one is defined
      if (!$run->canRun()) {
        $status[] = t('%interval: No need to refresh yet', array(
          '%interval' => $interval->title,
        ));
        continue;
      }

      // Invoke the module
      $out = module_invoke($service->module, 'mostpopular_service',
        'refresh', $service->delta, array(
          'sid' => $service->sid,
          'iid' => $interval->iid,
          'ts' => $interval->timestamp(),
          'last_run' => $last_run->last_run,
          'throttle' => $last_run->throttle,
          'max' => $max,
      ));

      // If the module returned any results, save them to the database.
      if ($out !== FALSE) {
        if (count($out) > 0) {

          // Remove the previous results, if there are any
          MostPopularItem::reset($service->sid, $interval->iid);
  
          // Write the new results to the cache table
          foreach ($out as $value) {
            $value['sid'] = $service->sid;
            $value['iid'] = $interval->iid;
  
            $item = new MostPopularItem($value, TRUE);
            $item->save();
          }
          // Since there were items returned, the service is ok.
          $service->updateStatus(MostPopularService::STATUS_OK);
        }

        // Record the last time at which this service was run on this interval
        $run->last_run = time();
        $run->save();

        $status[] = t("%interval: Found %count items", array(
          '%count' => count($out),
          '%interval' => $interval->title,
        ));
      }
      else {
        $status[] = t("%interval: No results", array(
          '%interval' => $interval->title,
        ));
      }
    }
    $t .= theme('item_list', $status);
    $t .= '</div><br/>';
  }
  if (empty($t)) {
    $t .= t("You must first enable services.  Go to !link", array(
      '!link' => l(t('the services tab'), 'admin/settings/mostpopular/services')
    ));
  }
  return $t;
}