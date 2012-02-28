<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function vsite_comments_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "fb_social" && $api == "fb_social") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function vsite_comments_views_api() {
  return array(
    'api' => '2',
  );
}
