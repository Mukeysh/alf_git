<?php

/**
 * @file
 *
 * helper functions for creating new boxes and adding them to regions
 */

/**
 * @function os_boxes_mk_box
 *   Creates a box object and adds it to a vsite
 *
 * @param &$vsite
 *   vsite to place the new box in
 *
 * @param $type
 *   Box plugin to use
 *
 * @param $opts
 *   Options to pass to new box
 *
 * @return
 *   Retruns box object or false if box couldn't be created
 *
 */
function os_boxes_mk_box(&$vsite, $type, $opts) {
  require_once drupal_get_path('module', 'boxes') . '/boxes.module';
  global $box_plugins;
  if (empty($box_plugins)) {
    $box_plugins  = os_boxes_get_boxes_plugins();
  }

  $identifier = $vsite->type . '-' . $vsite->id;
  $hash = boxes_create_hash($identifier);
  $delta = $identifier . '-' . $hash;
  $opts['delta'] = $delta;

  if (($box = boxes_factory($type, $opts)) && isset($vsite->controllers->boxes)) {
    $box->tags = $box_plugins[$type]['tags'];
    $vsite->controllers->boxes->set($box->delta, $box);
    return $box;
  } else {
    return false;
  }
}


/**
 * @function os_boxes_put_box
 *   Puts a box object in the specified region of a vsite
 *
 * @param &$vsite
 *   vsite to show box.  box must already belong to vsite.  this function affects the box's region within the vsite
 *
 * @param $box
 *   box object to put in a region
 *
 * @param $region
 *   section of the page to move the box to
 *
 */
// adds box to vsite.  returns id of vsite on successful creation
function os_boxes_put_box($context, &$vsite, $box, $region) {

	//og_theme is not avalible in the context controller during updates, lets do it manually if space override exists
	$og_theme = db_result(db_query('SELECT og_theme FROM {og} WHERE nid = %d', $vsite->group->nid));
  if($og_theme){
    $context_block_reaction = $vsite->controllers->context->get($context.':reaction:block:'.$og_theme,'space');

    if(!$context_block_reaction){
      $context_block_reaction = $vsite->controllers->context->get($context.':reaction:block');

      //Since og_theme is not avalible in updates
      if(is_array($context_block_reaction['blocks'])) _os_boxes_apply_theme_settings($context_block_reaction['blocks'],$og_theme);
    }//No space get from preset
  }

  //let spaces select the current setting or the default
  if(!$context_block_reaction) $context_block_reaction = $vsite->controllers->context->get($context.':reaction:block');

  $context_block_reaction['blocks']['boxes-' . $box->delta] = array(
    'module' => 'boxes',
    'delta' => $box->delta,
    'weight' => 0,
    'region' => $region,
    'label' => $box->description,
    'block_config_path' => 'cp/osboxes/nojs/' . $box->delta . '/configure', //is this always correct?
    'tags' => $box->tags,
  );

  if($og_theme){
    $og_theme = ":{$og_theme}";
  }else{
    $og_theme = "";
  }

  if ($vsite->controllers->context->set('openscholar-feature-front:reaction:block'.$og_theme, $context_block_reaction)) {
    return $vsite->id;
  } else {
    return FALSE;
  }
}

/**
 * @function os_boxes_remove_box
 *    Wrapper for os_boxes_put_box instead removes display of the box
 */
function os_boxes_remove_box(&$vsite, $box) {
  os_boxes_put_box($vsite, $box, false);
}

/**
 * Remove a instance of a box that has been overridden or exists only in a vsite
 * @param vsite $vsite
 * @param box $box
 */
function os_boxes_remove_spaces_box_instance($vsite,$box){

	if(!isset($vsite->controllers->boxes) || !is_object($box)){
		return false;
	}

	return $vsite->controllers->boxes->del($box->delta);
}
/**
 * @function os_boxes_replace_boxes
 *    Given a block id, replace it with the given block
 * @param $block_id - String id of the block to replace
 * @param $box - Object (instance)
 * @param $default_region
 * @param $sid (the site to replace or all sites by default)
 */
function os_boxes_replace_boxes($block_id, $box, $default_region = false, $sid = false, $limit = false) {

  if (!$box->delta) {
  	//There is no reason to create a delta here, the box should be made before you try and put it in the db
    error_log("Invalid Box Passed to replace function.");
    return false;
  }
  $widget_def = os_boxes_get_vsite_widget($box);

  $params = array($block_id);
  if($sid) $params[] = $sid;

  $sql_limit = ($limit)?"LIMIT {$limit} ":"";
  $return = false;

  $q = db_query("SELECT * FROM {spaces_overrides} WHERE type = 'og' AND object_type = 'context' AND object_id LIKE '%%reaction:block%%' AND value LIKE '%%%s%%' ".($sid?" AND id = %d ":"").$sql_limit, $params);
  while ($r = db_fetch_array($q)) {
    $value = unserialize($r['value']);
    // if the box is already in the context, don't add a new one
    if (!isset($value['blocks']['boxes-'.$box->delta])) {
      $region = isset($value['blocks'][$block_id]['region'])?$value['blocks'][$block_id]['region']:$default_region; //False regions accepted
      $weight = $value['blocks'][$block_id]['weight']?$value['blocks'][$block_id]['weight']:0;
      $value['blocks']['boxes-'.$box->delta] = array('region' => $region, 'weight' => $weight) + $widget_def;
    }
    unset($value['blocks'][$block_id]);
    db_query("UPDATE {spaces_overrides} SET value = '%s' WHERE type = 'og' AND object_type = 'context' AND id = %d AND object_id = '%s'", serialize($value), $r['id'], $r['object_id']);
    $return = true;
  }
  return $return;
}

/**
 * Manually apply theme settings since og_theme is not avalible in updates
 *
 * @param array $blocks
 * @param string $og_theme
 */
function _os_boxes_apply_theme_settings(&$blocks ,$og_theme){

    $a_settings = array();

  $s_path = drupal_get_path('theme', $og_theme);
  if ($s_path){
    $a_info = drupal_parse_info_file($s_path . "/" . $og_theme . ".info");
    $a_settings = (is_array($a_info) && array_key_exists('os', $a_info) && array_key_exists('widgets', $a_info['os']))?$a_info['os']['widgets']:array();
  }

  foreach ($a_settings as $s_widget => $s_region) {
    $s_region = (strlen($s_region) && $s_region != 'false')?$s_region:false;
    if (array_key_exists($s_widget, $blocks)) $blocks[$s_widget]['region'] = $s_region;
  }//alter based on theme settings

}