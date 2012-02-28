<?php

/**
 * Implementation of hook_spaces_registry_alter().
 */
function vsite_layout_spaces_registry_alter(&$registry) {

  //Use our own context controller
  if(isset($registry['controllers']['context'])){
    $registry['controllers']['context']['plugin'] = "spaces_controller_vsite_context";
  }

}



/**
 * Implementation of hook_spaces_plugins().
 */
function vsite_layout_spaces_plugins() {
  $plugins = array();

  //define the vsite controller for contexts
  $plugins['spaces_controller_vsite_context'] = array(
    'handler' => array(
      'path' => drupal_get_path('module', 'vsite_layout') .'/plugins',
      'file' => 'spaces_controller_vsite_context.inc',
      'class' => 'spaces_controller_vsite_context',
      'parent' => 'spaces_controller_context',
    ),
  );
  return $plugins;
}

/**
 * Implementation of hook_spaces_preset_alter().
 *
 * This will add the default blocks to the feature contexts for the space preset
 */
function vsite_layout_spaces_presets_alter(&$presets) {
  foreach ($presets as &$preset) {
	  if ($preset->export_module == 'spaces_og' || $preset->space_type != 'og') continue;
		if(!isset($preset->value['context'])) $preset->value['context'] = array();

		$contexts = context_load();
		foreach ($contexts as $s_key => $context) {
			if(strpos($s_key,"openscholar-feature-") !== 0) continue;
			$blocks = isset($context->reactions['block']['blocks'])? $context->reactions['block']['blocks']:array();
			
			if(is_array($blocks)){
			  $preset->value['context'][$s_key.":reaction:block"]['blocks'] = $blocks;
			}
		}
	}
}
