<?php
// $Id: mostpopular.admin.inc,v 1.1 2010/12/09 19:31:15 czingerline Exp $
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
 * Defines all the administration forms for the Most Popular module.
 *
 * @author Andrew Marcus
 * @since Dec 22, 2009
 */

/* ----------------------------------------------------------------------------
 * Settings Form
 * --------------------------------------------------------------------------*/
function mostpopular_settings_form() {
  $form = array();
  $form['mostpopular_max'] = array(
    '#type' => 'textfield',
    '#title' => t('Max Results'),
    '#description' => t('The maximum number of results to show in the Most Popular block'),
    '#size' => 2,
    '#default_value' => variable_get('mostpopular_max', 5),
  );
  $form['block'] = array(
    '#type' => 'fieldset',
    '#collapsible' => true,
    '#title' => t('Block settings'),
    '#description' => t('Configure the look and feel of the Most Popular block.'),
  );
  $form['block']['mostpopular_show_count'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show item counts'),
    '#description' => t('Should the number of times each item appears be displayed in the Most Popular block?'),
    '#default_value' => variable_get('mostpopular_show_count', TRUE),
  );
  $form['block']['mostpopular_styling'] = array(
    '#type' => 'radios',
    '#title' => t('Stylesheet'),
    '#description' => '<p>' . t(
"Choose how much styling to apply to the Most Popular block.
You can add additional styling in your own theme.") . '</p>' .
      '<p>' . t(
"For help, look at the <a href='@basic'>basic stylesheet</a>, which turns the
service and interval links into tabs, and the <a href='@full'>full stylesheet</a>,
which adds fonts, colors, formatting, and layouts.", array(
        '@basic' => url(drupal_get_path('module', 'mostpopular') . '/css/mostpopular-basic.css'),
        '@full' => url(drupal_get_path('module', 'mostpopular') . '/css/mostpopular-full.css'),
      )) . '</p>' .
      '<p>' . t(
"When creating your own styles for the Most Popular block, we recommend you
start with our full stylesheet and override it using drupal_set_css().") . '</p>',

    '#options' => array(
      MOSTPOPULAR_STYLE_NONE => t('No styling'),
      MOSTPOPULAR_STYLE_BASIC => t('Basic styling'),
      MOSTPOPULAR_STYLE_FULL => t('Full styling'),
    ),
    '#default_value' => variable_get('mostpopular_styling', MOSTPOPULAR_STYLE_FULL),
  );

  // Add a fieldset for configuring Drupal paths
  $form['paths'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#title' => t('Drupal Paths'),
  );

  // Get the configured base paths
  $site_base = url('', array('absolute' => TRUE));
  $path_base = url('');
  $basepaths = variable_get('mostpopular_basepaths', array($site_base, $path_base));

  $form['paths']['mostpopular_basepaths'] = array(
    '#type' => 'textarea',
    '#rows' => 6,
    '#title' => t('Base Paths'),
    '#default_value' => implode("\n", $basepaths),
    '#description' => t(
"<p>These base URLs will be stripped from the beginning of any full page URLs returned
by the various services. This allows the most popular content to work across several
site configurations.  This will only work, however, if the node nids are shared
between all sites.</p>
<p>Put each base URL on a separate line. Each must end with a slash.</p>"),
  );

  // Get the configured exclude paths
  $excludepaths = variable_get('mostpopular_exclude_paths', array());
  $form['paths']['mostpopular_exclude_paths'] = array(
    '#type' => 'textarea',
    '#rows' => 10,
    '#title' => t('Paths to exclude'),
    '#default_value' => implode("\n", $excludepaths),
    '#description' => t(
"<p>These Drupal pages will be excluded from the most popular results for any
services that return nodes.  The homepage will automatically be excluded, but
you can use this field to hide landing pages or other non-content pages.</p>
<p>Each URL should be an internal Drupal path with no leading slash, and can
point either to node/%d or to an alias.   Put each path on a separate line.</p>"),
  );

  $form['#submit'][] = 'mostpopular_settings_form_submit';
  $form = system_settings_form($form);
  return $form;
}

function mostpopular_settings_form_validate($form, &$form_state) {
  // Validate the max results box
  $max = (int)$form_state['values']['mostpopular_max'];
  if (empty($max) || !is_integer($max) || $max <= 0) {
    form_set_error('mostpopular_max', t('You must enter a positive number'));
  }
}

function mostpopular_settings_form_submit($form, &$form_state) {
  // If the max is changing, reset all the service last run times
  if ($form_state['values']['mostpopular_max'] != variable_get('mostpopular_max', 5)) {
    MostPopularLastRun::resetLastRun();
    drupal_set_message(t('The last run times for the services were reset.'));
  }

  // Change the encoding for the path fields
  $basepaths = explode("\n", $form_state['values']['mostpopular_basepaths']);
  $form_state['values']['mostpopular_basepaths'] = array();
  foreach ($basepaths as $path) {
    $path = trim($path);
    if (!empty($path)) {
      $form_state['values']['mostpopular_basepaths'][] = $path;
    }
  }

  $excludepaths = explode("\n", $form_state['values']['mostpopular_exclude_paths']);
  $form_state['values']['mostpopular_exclude_paths'] = array();
  foreach ($excludepaths as $path) {
    $path = trim($path);
    if (!empty($path)) {
      $form_state['values']['mostpopular_exclude_paths'][] = $path;
    }
  }
}

/* ----------------------------------------------------------------------------
 * Intervals Form
 * --------------------------------------------------------------------------*/
function mostpopular_intervals_form() {
  $form = array();

  // Get all of the intervals, and add an empty interval to the end
  $intervals = MostPopularInterval::fetchAll();
  $intervals[] = MostPopularInterval::create(count($intervals));

  $form['description'] = array(
    '#type' => 'markup',
    '#value' => '<p>' . t("
The interval field for each row must contain a string that can be understood by
<a href='@strtotime' target='php'>strtotime()</a>.  You must specify each as a
negative interval relative to today.", array(
        '@strtotime' => 'http://php.net/manual/en/function.strtotime.php',
      )) . '</p>' .
      '<p>' . t('To remove an interval, clear both the title and interval values.') . '</p>' .
      '<p>' . t(
"If you make changes to the intervals, any custom service throttles you may
have set up will be reset to their default values.") . '</p>',
  );
  $form['intervals'] = array(
    '#tree' => TRUE,
    '#theme' => 'mostpopular_config_intervals_form',
  );
  foreach ($intervals as $key => $interval) {
    $form['intervals'][$key] = array(
      'title' => array(
        '#type' => 'textfield',
        '#size' => 32,
        '#default_value' => $interval->title,
      ),
      'string' => array(
        '#type' => 'textfield',
        '#size' => 10,
        '#default_value' => $interval->string,
      ),
      'weight' => array(
        '#type' => 'weight',
        '#delta' => count($intervals),
        '#default_value' => $interval->weight,
      ),
      'object' => array(
        '#type' => 'value',
        '#value' => $interval,
      ),
    );
  }
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
  );
  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to Default Configuration'),
    '#attributes' => array( 'onclick' => 'javascript:return confirm("' . t(
"This will reset all the intervals and all the cached most popular data as
well as any custom service throttles.  Are you sure you want to do this?") .
    '");'),
  );
  return $form;
}

function mostpopular_intervals_form_validate($form, $form_state) {
  // Validate the intervals
  $intervals = $form_state['values']['intervals'];
  $good = FALSE;
  foreach ($intervals as $i => $inv) {
    $title = $inv['title'];
    $string = $inv['string'];

    if (empty($title)) {
      if (empty($string)) {
        // Ignore blank rows
        continue;
      }
      else {
        form_set_error("intervals][$i][title", t('You must specify the title to show users for this interval.'));
      }
    }
    else {
      if (empty($string) || strtotime($string) === FALSE) {
        form_set_error("intervals][$i][string", t(
"You must specify an interval that can be understood by <a href='@strtotime' target='php'>strtotime()</a>.",
          array(
            '@strtotime' => 'http://php.net/manual/en/function.strtotime.php'
          )
        ));
      }
      elseif (strtotime($string) > time()) {
        form_set_error("intervals][$i][string", t(
          'You must specify a negative interval relative to the current time'));
      }
      else {
        $good = TRUE;
      }
    }
  }
  if (!$good) {
    form_set_error(NULL, t('You must define at least one interval'));
  }
}

function mostpopular_intervals_form_submit($form, $form_state) {
  switch ($form_state['values']['op']) {
    case $form_state['values']['reset']:
      MostPopularInterval::reset();
      drupal_set_message(t('The interval configuration has been reset.'));

      mostpopular_clear_caches();
      break;

    default:
      $intervals = $form_state['values']['intervals'];
      foreach ($intervals as $i => $inv) {
        $title = $inv['title'];
        $string = $inv['string'];
        $weight = $inv['weight'];
        $object = $inv['object'];
        $iid = $object->iid;

        // If there is data, save it
        if (!empty($title) && !empty($string)) {

          // If the interval changed, reset the throttles for this interval
          if ($iid > 0 && $object->string != $string) {
            MostPopularLastRun::resetThrottles(NULL, $iid);
            drupal_set_message(t(
              'The service throttles were reset for interval %title.',
              array(
                '%title' => $title,
              )));
          }
          // Update the interval and save it
          $object->update(array(
            'title' => $title,
            'string' => $string,
            'weight' => $weight));

          if ($iid == 0) {
            drupal_set_message(t(
              'Interval %title was added. The default service throttles will be used for it.',
              array(
                '%title' => $object->fullTitle(),
              )));
          }
          $object->save();
        }

        // Otherwise, remove the interval
        elseif ($iid > 0) {
          // Remove the interval
          $object->remove();

          // Reset the throttles for the interval
          MostPopularLastRun::resetThrottles(NULL, $iid);

          // Remove any cached most popular items for the interval
          MostPopularItem::reset(NULL, $iid);

          drupal_set_message(t(
            'Interval %title was removed and the custom service throttles for it were cleared.',
            array(
              '%title' => $object->fullTitle(),
            )));
        }
      }
      drupal_set_message(t('The interval configuration has been saved.'));
      break;
  }
}

function theme_mostpopular_config_intervals_form($form) {
  drupal_add_tabledrag('mostpopular-intervals', 'order', 'sibling', 'sort');
  $header = array(
    '',
    array('data' => t('Title'), 'colspan' => 2),
    t('Interval'),
    'Sort');

  $rows = array();
  $output = '';

  foreach (element_children($form) as $key) {
    // Add class to group weight fields for drag and drop
    $form[$key]['weight']['#attributes']['class'] = 'sort';

    $row = array('');
    $row[] = array('data' => 'Past', 'width' => '10');
    $row[] = drupal_render($form[$key]['title']);
    $row[] = drupal_render($form[$key]['string']);
    $row[] = drupal_render($form[$key]['weight']);
    $rows[] = array('data' => $row, 'class' => 'draggable');
  }

  $output .= theme('table', $header, $rows, array('id' => 'mostpopular-intervals'));
  $output .= drupal_render($form);
  return $output;
}

/* ----------------------------------------------------------------------------
 * Services Form
 * --------------------------------------------------------------------------*/
function mostpopular_services_form() {
  $services = MostPopularService::fetchSorted();

  $form = array(
    '#tree' => TRUE,
    '#theme' => 'mostpopular_config_services_form',
    'services' => array(),
  );
  foreach ($services as $key => $service) {
    $form['services'][$key] = array(
      'enabled' => array(
        '#type' => 'checkbox',
        '#default_value' => $service->enabled,
      ),
      'status' => array(
        '#type' => 'item',
        '#value' => theme('mostpopular_service_status', $service->status),
      ),
      'name' => array(
        '#markup' => $service->name,
      ),
      'title' => array(
        '#type' => 'textfield',
        '#size' => 32,
        '#default_value' => $service->title,
      ),
      'weight' => array(
        '#type' => 'weight',
        '#delta' => MostPopularService::numServices(),
        '#default_value' => $service->weight,
      ),
      'config' => array(
        '#markup' => l(t('Configure'), "admin/settings/mostpopular/services/$service->sid"),
      ),
      'service' => array(
        '#type' => 'value',
        '#value' => serialize($service),
      ),
    );
  }
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
  );
  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset Titles'),
  );

  // Add a reset button
  $form['clear'] = array(
    '#type' => 'submit',
    '#attributes' => array( 'onclick' => 'javascript:return confirm("' . t(
"Each service will be reset and the most popular items will be cleared.
You should refresh the stats after clearing the caches. Are you sure you want to do this?") .
      '");'
    ),
    '#value' => t('Clear all cached values'),
  );
  return $form;
}

function mostpopular_services_form_validate($form, $form_state) {
  if ($form_state['values']['op'] != $form_state['values']['reset']) {
    // Validate the services
    $services = $form_state['values']['services'];
    foreach ($services as $i => $service) {
      $title = $service['title'];
      $enabled = $service['enabled'];
      if ($enabled && empty($title)) {
        form_set_error("services][$i][title", t('You must choose a title to be displayed this service.'));
      }
    }
  }
}

function mostpopular_services_form_submit($form, $form_state) {
  $reset_menu = TRUE;
  
  switch ($form_state['values']['op']) {
    
    // Action: Reset Titles 
    case $form_state['values']['reset']:
      MostPopularService::reset();
      drupal_set_message(t('Reset all service titles to their default values.'));
      break;

    // Action: Clear all cached values
    case $form_state['values']['clear']:
      mostpopular_clear_caches();
      $reset_menu = FALSE;
      // Fall through

    // Action: Save Configuration
    default:
      $services = $form_state['values']['services'];
      foreach ($services as $i => $service) {
        $s = unserialize($service['service']);
        unset($service['service']);

        $s->update($service);
        $s->save();
      }
      drupal_set_message(t('The service configuration has been saved.'));
  }
  
  // Rebuild the menus so we can create a menu item for each service.
  if ($reset_menu) {
    menu_rebuild();
  }
}

function theme_mostpopular_config_services_form(&$form) {
  drupal_add_tabledrag('mostpopular-services', 'order', 'sibling', 'sort');
  $header = array('', t('Enabled'), t('Status'), t('Service Name'), t('Title'), t('Weight'), '');
  $rows = array();
  $output = '';

  foreach (element_children($form['services']) as $key) {
    $item =& $form['services'][$key];

    // Add class to group weight fields for drag and drop
    $item['weight']['#attributes']['class'] = 'sort';

    $row = array('');
    $row[] = drupal_render($item['enabled']);
    $row[] = drupal_render($item['status']);
    $row[] = $item['name']['#markup'];
    $row[] = drupal_render($item['title']);
    $row[] = drupal_render($item['weight']);
    $row[] = $item['config']['#markup'];

    $rows[] = array('data' => $row, 'class' => 'draggable');
  }
  $output .= theme('table', $header, $rows, array('id' => 'mostpopular-services'));
  $output .= drupal_render($form);
  return $output;
}

function theme_mostpopular_service_status($status) {
  $out = "<span class='mostpopular--service-status mostpopular--service-status-$status'>";
  switch ($status) {
    case MostPopularService::STATUS_OK:
      $out .= t('OK');
      break;

    case MostPopularService::STATUS_CONFIGURED:
      $out .= t('Configured');
      break;

    default:
      $out .= '&nbsp;';
  }
  $out .= "</span>";
  return $out;
}

/* ----------------------------------------------------------------------------
 * Service Config Form
 * --------------------------------------------------------------------------*/
function mostpopular_service_config_form(&$form_values, $sid = 1) {
  $service = MostPopularService::fetch($sid);
  $intervals = MostPopularInterval::fetchAll();

  // If the service provides any configuration form, show it first
  $form = module_invoke($service->module, 'mostpopular_service',
    'config', $service->delta);

  if (empty($form)) {
    $form = array();
  }

  //---------------------------------------------------------------------------
  // Add the throttle config options

  $form['sid'] = array(
    '#type' => 'value',
    '#value' => $sid,
  );

  // Add a fieldset for the throttle
  $form['throttle_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Throttle'),
    '#tree' => TRUE,
    '#theme' => 'mostpopular_config_service_form_throttles',
    '#description' => '<p>' . t(
"This service may have a quota limiting the number of times it can be called
within a given period of time.  By setting the throttle, you can restrict the
frequency with which the service is called.") . '</p>' .
      '<p>' . t(
"You must specify the time as a <em>positive interval relative to the time the
service was last run</em>, in a format the <a href='@strtotime' target='php'>strtotime()</a>
function can understand, such as '%example1 or %example2.  If the result is
less than the current time, the service can be called again.", array(
        '%example1' => '1 hour',
        '%example2' => '1 day 00:00:00',
        '@strtotime' => 'http://php.net/manual/en/function.strtotime.php',
      )) . '</p>' .
      '<p>' . t(
"<em>If you leave this field empty</em>, the service will be called every time
the cron job is run or the administrator goes to the Refresh Stats tab.") . '</p>',
  );

  foreach ($intervals as $interval) {
    $iid = $interval->iid;
    $run = MostPopularLastRun::fetch($sid, $iid);

    $form['throttle_fieldset'][$iid]['interval'] = array(
      '#type' => 'item',
      '#title' => t('Interval'),
      '#value' => $interval->title,
    );

    // Add the throttle field
    $form['throttle_fieldset'][$iid]['throttle'] = array(
      '#type' => 'textfield',
      '#title' => t('Minimum elapsed interval'),
      '#default_value' => $run->throttle,
      '#element_validate' => array('mostpopular_service_config_form_validate_throttle'),
    );

    // Show the last time the service was run for this interval
    $form['throttle_fieldset'][$iid]['last_run'] = array(
      '#type' => 'item',
      '#title' => t('The service was last run at'),
      '#value' => $run->last_run == 0 ? 'never' : date('M d, Y H:i:s', $run->last_run),
    );

    $next_run = $run->nextRun();

    // Show the next time the service will run
    $form['throttle_fieldset'][$iid]['next_run'] = array(
      '#type' => 'item',
      '#title' => t('The service can next run at'),
      '#value' => $next_run == time() ? 'now' : date('M d, Y H:i:s', $next_run),
    );
  }
  $form['#submit'][] = 'mostpopular_service_config_form_submit';

  $form = system_settings_form($form);

  // Add a reset button
  $form['buttons']['clear'] = array(
    '#type' => 'submit',
    '#attributes' => array( 'onclick' => 'javascript:return confirm("' . t(
"This service will be reset and its most popular items will be cleared. You should
refresh the stats after clearing the caches. Are you sure you want to do this?") .
      '");'
    ),
    '#value' => t('Clear cached values'),
  );
  $form['buttons']['back'] = array(
    '#type' => 'submit',
    '#value' => t('Back'),
  );

  return $form;
}

/**
 * Validates the throttle field in config forms.
 */
function mostpopular_service_config_form_validate_throttle($element, &$form_state) {
  $value = $element['#value'];
  $value = trim($value);

  // If the value is not empty, try to convert it with strtotime()
  if (!empty($value)) {
    $ts = strtotime($value);

    // Is the user's input a valid time interval?
    if ($ts === FALSE) {
      form_error($element, t(
"You must specify the interval in a format that can be understood by <a href='@strtotime' target='php'>strtotime()</a>.",
        array(
          '@strtotime' => 'http://php.net/manual/en/function.strtotime.php'
        )
      ));
    }
    // Is the time interval in the future relative to now?
    elseif ($ts <= time()) {
      form_error($element, t('You must specify the time as a positive interval relative to the current time.'));
    }
  }
}

function mostpopular_service_config_form_submit($form, &$form_state) {
  $sid = $form_state['values']['sid'];
  unset($form_state['values']['sid']);

  $throttles = $form_state['values']['throttle_fieldset'];
  unset($form_state['values']['throttle_fieldset']);

  $back = $form_state['values']['back'];
  unset($form_state['values']['back']);

  $clear = $form_state['values']['clear'];
  unset($form_state['values']['clear']);

  switch ($form_state['values']['op']) {
    case $form_state['values']['reset']:
      MostPopularLastRun::resetThrottles($sid);
      drupal_set_message(t('The throttles have been reset to their default values.'));
      break;

    case $back:
      $form_state['redirect'] = 'admin/settings/mostpopular/services';
      break;

    case $clear:
      MostPopularLastRun::resetLastRun($sid);
      drupal_set_message(t('The most popular caches have been cleared for this service. You should refresh the stats.'));
      // Fall through

    case $form_state['values']['submit']:
      foreach ($throttles as $iid => $field) {
        $last = MostPopularLastRun::fetch($sid, $iid);
        $last->throttle = $field['throttle'];
        $last->save();
      }
      // Reset the service
      $service = MostPopularService::fetch($sid);
      $service->updateStatus(MostPopularService::STATUS_CONFIGURED);

      drupal_set_message(t('This service has been configured.'));
      break;
  }
}

function theme_mostpopular_config_service_form_throttles($form) {
  $header = array(t('Interval'), t('Minimum Elapsed Interval'),
    t('Last Run'), t('Can Next Run'));
  $rows = array();
  $output = '';

  foreach (element_children($form) as $iid) {
    $row = array();
    foreach (element_children($form[$iid]) as $key) {
      unset($form[$iid][$key]['#title']);
      $row[] = drupal_render($form[$iid][$key]);
    }
    $rows[] = array('data' => $row);
  }
  $output .= theme('table', $header, $rows, array('id' => 'mostpopular-throttles'));
  $output .= drupal_render($form);
  return $output;
}
