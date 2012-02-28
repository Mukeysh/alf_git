<?php

/**
 * Request object for slideshare api
 */
class Slideshareapi {
  private $key;
  private $secret;
  private $user;
  private $password;
  private $apiurl;

  function __construct(){
    $this -> key = variable_get('slideshareapi_key', '');
    $this -> secret = variable_get('slideshareapi_secret', '');
    $this -> user = variable_get('slideshareapi_user', '');
    $this -> password = variable_get('slideshareapi_pass', '');
    $this -> apiurl= variable_get('slideshareapi_apiurl', 'http://www.slideshare.net/api/2/');

  }

  /**
   * performs the request to slideshare.net
   * @param $call the name of the api function to call
   * @param $params array of parameters
   * @return unknown_type
   */
  public function request($call, $params){
    $ts = time();
    $hash = sha1($this->secret . $ts);
    $params['api_key'] = $this -> key;
    $params['ts'] = $ts;
    $params['hash'] = $hash;
    $params['username'] = $this -> user;
    $params['password'] = $this -> password;

    $query = http_build_query($params);

    $response = drupal_http_request($this->apiurl . $call . "?" . $query);
    if ($response->code == '200') {
      return $this -> XMLtoArray(utf8_encode($response -> data));
    }
    else {
      watchdog('error', 'HTTP error !code received', array('!code' => $response->code));
    }
    return FALSE;
  }

  /**
   * xml to php aray conversion
   */
  private function XMLtoArray($data){
    $finarr = array();
    $parser = xml_parser_create();
    xml_parse_into_struct($parser, $data, $values, $tags);
    xml_parser_free($parser);
    foreach ( $tags as $key => $val ) {
      if (strtoupper($key) == "SLIDESHARESERVICEERROR") {
        $finarr[0]["Error"] = "true";
        $finarr[0]["Message"] = $values[$tags["MESSAGE"][0]]["value"];
        return $finarr;
      }
      if ((strtolower($key) != "slideshow")
           && (strtolower($key) != "slideshows")
           && (strtolower($key) != "slideshowdeleted")
           && (strtolower($key) != "slideshowuploaded")
           && (strtolower($key) != "tags")
           && (strtolower($key) != "group")
           && (strtolower($key) != "name")
           && (strtolower($key) != "count")
           && (strtolower($key) != "user")) {
        for($i = 0; $i < count($val); $i ++) {
          $finarr[$i][$key] = $values[$val[$i]]["value"];
        }
      }
      else {
        continue;
      }
    }
    return $finarr;
  }
}

