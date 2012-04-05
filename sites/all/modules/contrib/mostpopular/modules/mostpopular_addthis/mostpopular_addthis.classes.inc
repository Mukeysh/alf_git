<?php
// $Id: mostpopular_addthis.classes.inc,v 1.1 2010/12/09 19:31:15 czingerline Exp $
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
 * Provides a connector to the AddThis.com API.
 *
 * See http://www.addthis.com/help/analytics-api
 *
 * @author Andrew Marcus
 * @since Dec 30, 2009
 */
class AddThis {
  const data_scheme = 'http://';
  const data_url = 'api.addthis.com/analytics/1.0/pub/shares';

  protected $username;
  protected $password;
  protected $result;

  /**
   * Constructs a new AddThis class.
   *
   * It will use the configured username and password.
   */
  public function AddThis() {
    $this->username = variable_get('addthis_username', NULL);
    $this->password = variable_get('addthis_password', NULL);
  }

  /**
   * Makes a generic call to the AddThis.com server.
   *
   * See http://www.addthis.com/help/analytics-api
   *
   * @param string $dimension
   *   The dimension we're interested in.  It must be null or one of:
   *   - content
   *   - continent
   *   - country
   *   - domain
   *   - service
   * @param string $format
   *   The format to return results, either 'csv' or 'json'.
   * @param string $params
   *   Additional parameters to send.  The following are allowed:
   *   - period: 'day', 'week' or 'month'
   *   - domain: any URL domain
   *   - service: 'email'
   */
  public function fetch($dimension = '', $format = 'csv', $params = array()) {
    if (empty($this->username) || empty($this->password)) {
      drupal_set_message(t('You must configure the AddThis.com username and password'), 'error');
      return NULL;
    }

    // Create the URL
    $auth = $this->username . ':' . $this->password . '@';
    $url = self::data_url;
    if (!empty($dimension)) {
      $url .= '/' . $dimension;
    }
    $url .= '.' . $format;

    // Clean up the URL and add query parameters
    $request_url = url(self::data_scheme . $auth . $url,
      array( 'query' => $params ));

    $this->result = drupal_http_request($request_url);

    if (isset($this->result->error)) {
      drupal_set_message(t(
"Error connecting to AddThis.com service.<br/>
!url<br/>
@code @error", array(
          '!url' => url(self::data_scheme . $url, array( 'query' => $params )),
          '@code' => $this->result->code,
          '@error' => $this->result->error,
        )), 'error');
      return NULL;
    }
    return $this->result->data;
  }

  /**
   * Makes a call to the AddThis.com server and parses the CSV response.
   *
   * @param string $dimension
   *   The dimension we're interested in.  It must be null or one of:
   *   - content
   *   - continent
   *   - country
   *   - domain
   *   - service
   * @param string $params
   *   Additional parameters to send.  The following are allowed:
   *   - period: 'day', 'week' or 'month'
   *   - domain: any URL domain
   *   - service: 'email'
   *
   * @return array
   *   An array of associative arrays, each containing:
   *     - shares: The number of times the page was shared.
   *     - url: The URL of the page.
   */
  public function fetchCSV($dimension = '', $params = array()) {
    $out = array();

    $this->fetch($dimension, 'csv', $params);

    // If we got a result, parse the CSV fields
    if (empty($this->result->error)) {
      $lines = preg_split('(\r|\n|\r\n)', $this->result->data);
      $headers = array();
      foreach ($lines as $line) {
        $line = trim($line);
        if (!empty($line)) {

          // If this is the first row, use it as the headers
          if (empty($headers)) {
            $parts = split(',', $line);
            $headers = $parts;
          }
          // Otherwise, get the contents and match them to headers
          else {
            $parts = split(',', $line, count($headers));
            $data = array();
            foreach ($parts as $i => $part) {
              $data[$headers[$i]] = $part;
            }
            $out[] = $data;
          }
        }
      }
    }
    // Otherwise, parse the error to figure out what happened.
    else {
      // Get the message type
      if (preg_match("/<b>message<\/b> <u>(.+?)<\/u>/", $this->result->data, $matches)) {
        drupal_set_message($matches[1], 'error');
      }
    }
    return $out;
  }

  /**
   * Gets the most emailed nodes from AddThis.com for the given period of time.
   *
   * @param integer $ts
   *   The timestamp that starts the desired period of time that ends now.
   *   We use this to calculate whether we're interested in the last day,
   *   week or month.   Note that year is not yet supported by AddThis.com.
   *
   * @return array
   *   An array of associative arrays, each containing:
   *     - shares: The number of times the page was shared.
   *     - url: The URL of the page.
   */
  public function getNodeEmailCount($ts = 0) {
    $params = array(
      'service' => 'email',
    );
    $now = time();
    if (strtotime('-1 day -10 minutes') <= $ts) {
      $params['period'] = 'day';
    }
    elseif (strtotime('-1 week -10 minutes') <= $ts) {
      $params['period'] = 'week';
    }
    elseif (strtotime('-1 month -10 minutes') <= $ts) {
      $params['period'] = 'month';
    }
    // AddThis.com does not support any other options currently
    else {
      return FALSE;
    }
    return $this->fetchCSV('content', $params);
  }
}