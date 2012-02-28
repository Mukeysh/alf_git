<?php

define('FEATURE_PUBLIC', 1);
define('FEATURE_PRIVATE', 2);
define('FEATURE_DISABLED', 0);

/**
 * Return the content type of a vsite based on the privacy
 * @param $privacy and array (or single value) (0 -> disabled, 2 -> private, 1 -> public)
 * @param $vsite optional / the active vsite if nothing provided
 * @return unknown_type
 */
function vsite_content_types($privacy = array(1), $vsite = NULL){
  if (! is_array($privacy)) {
    $privacy = array(
        $privacy
    );
  }

  if (! $vsite) {
    $vsite = vsite_get_vsite();
  }

  $result = array();
  if ($vsite) {
    $all_types = node_get_types('names');
    $features_types = features_get_component_map('node');

    $site_features = variable_get('spaces_features', array());
    foreach ( $features_types as $type => $features ) {
      if(!count($features)) continue;

      foreach ($features as $feature){
	      if (isset($site_features[$feature]) && in_array(( int ) $site_features[$feature], $privacy)) {
	        $result[$type] = $all_types[$type];
	      }
      }//Since the component map can pickup disabled features search through each
    }
  }
  return $result;
}


function vsite_create_links($privacy = NULL){
  if (!$privacy){
    $types = vsite_content_types(array(2, 1));
  }else {
    $types = vsite_content_types(array($privacy));
  }
  drupal_alter('vsite_content_types', $types);
  foreach ( $types as $type => $name ) {
    $add_url = 'node/add/'. str_replace('_', '-', $type);
    $item = menu_get_item($add_url);
    if ($item && $item['access'] && strpos($_GET['q'], $add_url) !== 0) {
      $links[$type] = array('title' => t('Add @type', array('@type' => $name)), 'href' => $add_url);
    }
  }
  return isset($links) ? $links : array();
}

/**
 * Theme that returns the html for a scholar logo
 *
 * @param viste $scholar
 * @param string $s_logo_field
 * @param string $preset
 * @param string $alt
 * @param string $title
 * @param array $attributes
 * @param boolean $bypass_browser_cache
 * @param boolean $b_as_link
 * @return string
 */
function theme_vsite_logo($scholar = false, $s_logo_field = "field_vsite_logo", $preset = false, $alt = '' , $title = '', $attributes = array(), $bypass_browser_cache =false, $b_as_link = false){
  $s_image_path;
  $s_out;
  if(!$scholar) $scholar = vsite_get_vsite();

  if(!$scholar || !($a_files = filefield_get_node_files($scholar->group,$s_logo_field)) || !count($a_files)){
  	$s_image_path = drupal_get_path('module','vsite_design')."/theme/images/default_logo.jpg";
  }else{
  	$a_image = current($a_files);
  	$s_image_path = $a_image['filepath'];
  }//Default image?

  $s_url_extra = "";
  if($bypass_browser_cache) $s_url_extra .= "?version=".time();

  if($preset){
    $s_image_path = imagecache_create_url($preset, $s_image_path);
  }else{
  	$s_image_path = "/".$s_image_path;
  }//Cached or orig

  $attributes = drupal_attributes($attributes);
  $s_out = '<img src="'.$s_image_path . $s_url_extra .'" alt="'. check_plain($alt) .'" title="'. check_plain($title) .'" '. $attributes .' />';


  if($b_as_link) $s_out = l($s_out,'node/'.$scholar->id,array('html'=>true));

  return $s_out;
}

/**
 * Returns the HTML for a login link
 *
 * @param string $link_text
 * @param array $a_attributes
 *
 * @return string
 */
function theme_vsite_login_link($link_text = "Login", $a_attributes = array()){
  global $user;
  $s_out = "";

  if(!$user -> uid){

    $vsite = vsite_get_vsite();

    // Use $_GET here to retrieve the original path in source form.
    $path = isset($_GET['q']) ? $_GET['q'] : '';

    //If we are in a vsite alter the URL to add the correct prefix and show the alias
    if($vsite && function_exists('custom_url_rewrite_outbound')){
      // Modules may alter outbound links by reference. (We don't just call "url" here because we don't want aliases or absolute urls)
      $options = array('fragment' => '','query' => '','absolute' => FALSE,'alias' => FALSE,'prefix' => '');
      custom_url_rewrite_outbound($path, $options, $path);
    }

    //Add the existing query string if it exists
    $query = drupal_query_string_encode($_GET, array('q'));
    if ($query != '') {
      $path .= '?'. $query;
    }
    $query = 'destination='. urlencode($path);

    $s_out .= l($link_text, "user", array('purl' => array('disabled' => TRUE), 'attributes' => $a_attributes,'alias' => FALSE, 'query' => $query));
  }

  return $s_out;
}



/**
 * returns an array of available themes for faculty to chose
 *
 * @param $theme_type string
 *    The ID of the site type that you would like to recieve themes for
 *
 * @see _cp_is_scholar_theme
 * @todo private themes ?!
 */
function vsite_vsite_themes($theme_type = "vsite"){
  $allthemes = list_themes();
  _vsite_get_theme_type($theme_type);

  return (array_filter($allthemes,"_vsite_is_vsite_theme"));
}

/**
 * Set the theme_type to filter by
 *
 * THIS FUNCTION IS PRIVATE
 * as such it should not be called from outside this file
 */
function _vsite_get_theme_type( $s_set_theme_type = false ){
	static $s_theme_type;

	if($s_set_theme_type) $s_theme_type = $s_set_theme_type;

	return $s_theme_type;
}

/**
 * a callback function for array_filter() in iq_og_fac_themes
 *
 * @param unknown_type $atheme - the theme to be tested
 * @return TRUE if it should be listed as faculty theme, false otherwise
 */
function _vsite_is_vsite_theme($atheme){
  $vsite = vsite_get_vsite();
  $site_key = $vsite?$vsite->group->purl:false;

  return (array_key_exists('os',$atheme->info)
       && array_key_exists('theme_type',$atheme->info['os'])
       && _vsite_get_theme_type() == $atheme->info['os']['theme_type']
       && ($atheme->info['os']['theme_access'] != "private" || user_access('access private scholar themes') || $site_key == strtolower($atheme->name))
       && !empty($atheme->status));
}

/**
 * Returns a random default theme from a specified list per installation
 * Checks to make sure selected theme is in the list of public themes
 * @return the machine name of the theme
 */
function _vsite_get_random_theme($theme_type = "vsite"){
  global $conf;
  $themes = array_intersect(array_keys(vsite_vsite_themes($theme_type)), $conf['openscholar_selected_themes']);
  if(count($themes)) {
    shuffle($themes);
    return $themes[0];
  }
  return $conf['openscholar_vsite_default_theme'];
}

/**
   * Imports an image as a filefield image of a given node
   *
   * Usage example:
   * --------------
   * $node = node_load(array('nid' => 61));
   * $image = drupal_get_path('module', 'vsite_design').'/theme/images/default_logo.jpg';
   * simport_node_add_imagefield_image($image, 'field_img', $node);
   *
   * @param $source  the path to the source image
   * @param $field_name the name of the cck field
   * @param $node the node object to upload the image to (passed by reference)
   */
function vsite_add_imagefield_image($source, $field_name, &$node){

  // get the cck filefield
  $field = content_fields($field_name, $node -> type);

  // validators (can add our own validators if we want)
  $validators = array_merge(filefield_widget_upload_validators($field), imagefield_widget_upload_validators($field));

  // where to store the file
  $files_path = filefield_widget_file_path($field);

  if(og_is_group_type($node->type)){
    $vsite = spaces_load('og',$node->nid);
    $files_path .= $vsite->group->purl;
    file_check_directory($files_path,FILE_CREATE_DIRECTORY);
    $files_path .= '/files';
    file_check_directory($files_path,FILE_CREATE_DIRECTORY);
  }//If this is the group node lets put it in the group directory

  // create the file object
  if(!@filesize($source)){
    error_log("could not get file size for [$source] ");
    return false;
  }//if the file does not exsit dont try and save

  $file = field_file_save_file($source, $validators, $files_path);

  // attach it to the filefield field
  $node->$field_name = array(
  0 => array(
  'fid' => $file['fid'],
  'uid' => $node -> uid,
  'list' => 1,
    )
  );

  // save the node
  node_save($node);

  return $file['destination'];
}

/**
 * Get an array of referrer nids, by node.type & field.type
 * @param nid
 *     the nid we want to find referres for
 * @param fieldnames
 *     array of fieldnames to be checked for referrers
 * @param nodetypes
 *     array of node types to be checked for referrers
 */

function vsite_get_referrers($nid,  $fieldnames = array(), $nodetypes = array()) {

	if ($nodetypes) {
    $filter_nodetypes = "AND n.type IN (" .  rtrim(str_repeat(" '%s' ,", count($nodetypes)),',') . ")";
  }
  else {
    $filter_nodetypes = '';
  }

  $fields = content_fields();
  // Set default values of fieldnames.
  if (!count($fieldnames)) {
    $fieldnames = array_keys($fields);
  }

  $values = array();
  foreach ($fieldnames as $fieldname) {
    if ($fields[$fieldname]['type'] == 'nodereference') {
      $db_info = content_database_info($fields[$fieldname]);


        $query = "SELECT       n.nid, n.vid, n.title
                  FROM         {" . $db_info['table'] . "} nr
                  INNER JOIN   {node} n ON n.vid = nr.vid AND n.status = 1 " . $filter_nodetypes . "
                  WHERE        nr." . $db_info['columns']['nid']['column'] . " = %d
                  ORDER BY     n.created DESC";



      $query = db_rewrite_sql($query);
      $result = db_query($query, array_merge($nodetypes,array($nid)));

      while ($value = db_fetch_array($result)) {
        // avoid duplicate referrers by using nid as key
        $values[$value['nid']] = $value;
      }
    }
  }
  return $values;
}

/**
 * Get information about this instalation
 */
function vsite_get_version_information(){
  if(!variable_get('drupal_install_age',false)) variable_set('drupal_install_age',time());

  $a_info = array();
  $a_info['version'] = OPENSCHOLAR_VERSION."_Drupal_".VERSION;
  $a_info['openscholar_version'] = OPENSCHOLAR_VERSION;

  $a_info['vsite'] = false;
  if($vsite = vsite_get_vsite()){
    $a_info['vsite'] = $vsite->group->purl;
  }

  $a_info['host'] = variable_get('purl_base_domain',$_SERVER['HTTP_HOST']);
  $a_info['age'] = variable_get('drupal_install_age','0');

  return $a_info;
}

/**
 * Change the vsite links/images so that they have the correct domain etc.
 * This should be used when linking to a vsite
 */
function theme_views_view_field_link_to_vsite($view, $field, $row) {

  $nid_alias = $field->aliases['nid'];
  $nid = $row->$nid_alias;

  if(($vsite = vsite_get_vsite($nid)) && $vsite->purl_provider){

    $value = $field->render($row);
    $options = array('html' => 'TRUE');

    $options['purl'] = array('provider' => $vsite->purl_provider, 'id' => $vsite->id);
    $options['absolute'] = true;

    $s_content = l($value, 'node/'.$nid, $options);

    $field->last_render = $s_content;

    return $s_content;
  }


  return $view->field[$field->options['id']]->advanced_render($row);
}

/**
 * Static function that retrieves the active feature
 */
function vsite_active_feature(){
	static $s_feature;

	if(!isset($s_feature)){
		$contexts = context_get('context');
    if(!empty($contexts) && is_array($contexts)){
    	foreach ($contexts as $s_key => $context) {
    		list($namespace,$key,$value) = explode("-",$s_key);
    		if ($namespace == "openscholar" && $key == "feature") {
    			$s_feature = $value;
    		}
    	}
    }
	}

	return $s_feature;
}
