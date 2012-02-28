<?php
/**
 * Page/JS Callbacks and Theme Functions
 */

/**
 * Page Callback
 * main entry point for "cp/settings/appearance"
 *
 * Renders the page for editing block layouts
 */
function vsite_layout_ui_layout() {
  jquery_ui_add(array('ui.draggable', 'ui.droppable', 'ui.sortable'));

  drupal_add_js(drupal_get_path('module', 'vsite_layout_ui') . '/theme/vsite_layout_ui.js');
  drupal_add_css(drupal_get_path('module', 'vsite_layout_ui') . '/theme/vsite_layout_ui.css');
  drupal_add_css(drupal_get_path('module', 'vsite_layout_ui') . '/theme/cp-layout-map.css');

  //tiny scrollbar code
  drupal_add_js(drupal_get_path('module', 'vsite_layout_ui') . '/theme/jquery.tinyscrollbar.min.js');
  drupal_add_css(drupal_get_path('module', 'vsite_layout_ui') . '/theme/tinyscrollbar.css');

  //Support for ctools popups
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();

  $space = vsite_get_vsite();
  $a_info = drupal_parse_info_file(drupal_get_path('theme', $space->group->og_theme) . "/" . $space->group->og_theme . ".info");
  if (is_array($a_info) && array_key_exists('os', $a_info) && array_key_exists('cp_layout_css', $a_info['os'])) {
    //cp_layout_css
    drupal_add_css(drupal_get_path('theme', $space->group->og_theme) . "/" . $a_info['os']['cp_layout_css']);
  }//Apply CSS for custom theme Layouts

  //Print the Form
  $form = drupal_get_form('vsite_layout_ui_settings_form');

  return $form;
}

/**
 * Javascript Callback to swap out the regions avalible for different pages
 * @param $s_region
 * @return string
 */
function vsite_layout_ui_region_widgets_callback() {
  ctools_include('ajax');
  ctools_include('modal');

  $scholar = vsite_get_vsite();
  $s_page_type = ($_POST['page_type'])?$_POST['page_type']:"none";

  $features = spaces_features();
  $a_feature_contexts = array();
  if (!empty($features[$s_page_type]) && !empty($features[$s_page_type]->info['features']['context'])) {
    $a_feature_contexts =  drupal_map_assoc($features[$s_page_type]->info['features']['context']);
  }

  $a_region_wgts = vsite_layout_ui_region_widgets($s_page_type);
  $a_themed_regions = array();

  $regions = system_region_list('scholar_base');
  foreach ($regions as $region => $s_label) {
    $widgets = array_key_exists($region, $a_region_wgts)?$a_region_wgts[$region]:array();
    $wgts_id = 'scholarlayout-' . str_replace('_', '-', $region);
    if ($s_page_type == 'none') vsite_layout_ui_check_for_overrides($widgets, $region);
    vsite_layout_ui_check_for_disabled_widgets($widgets, $scholar);
    $a_themed_regions[$region] = theme('vsite_layout_ui_layout_widgets', $widgets, $wgts_id, 'scholarlayout-widgets-list', ucwords($s_label));
  }
  $a_themed_regions['content'] = theme('vsite_layout_ui_layout_widgets', array(), 'scholarlayout-content-main', 'scholarlayout-widgets-list', 'Main Content');

  $output= theme('vsite_layout_ui_layout',$a_themed_regions,$s_page_type);

  drupal_json(array('status' => TRUE, 'data' => $output));
}

/**
 * Javascript Callback to swap out the top widgets avalible for different pages
 * @param $s_region
 * @return string
 */
function vsite_layout_ui_top_widgets_callback() {
  ctools_include('ajax');
  ctools_include('modal');

  $s_page_type = ($_POST['page_type'])?$_POST['page_type']:"none";
  $a_region_wgts = vsite_layout_ui_region_widgets( $s_page_type );
  //The widgets in the unused Top Area
  $wgts = $a_region_wgts['unused'];

  //Disable widgets from disabled features
  vsite_layout_ui_check_for_disabled_widgets($wgts);

  $top = theme('vsite_layout_ui_tagged_widgets', $wgts, 'scholarlayout-top-widgets', 'scholarlayout-widgets-list');

  drupal_json(array('status' => TRUE, 'data' => $top));
}

/**
 * For the Layout Display, Add help text to widgets are overridden in a child page
 *
 * This is not used outside of the CP
 *
 * @param array $widgets
 * @param string $s_region
 * @param vsite $space
 */
function vsite_layout_ui_check_for_overrides(&$widgets, $s_region) {
  if(!count($widgets)) return;

  foreach (vsite_layout_ui_get_pagetypes() as $s_page_nm => $s_page_readable) {
    if ($s_page_nm == 'none') continue;

    $context = context_load('openscholar-feature-'.$s_page_nm);
    if(!($a_page_widgets = $context->reactions['block']['blocks'])) continue;

    foreach ($widgets as $s_wgt_name => $wgt) {
      if (!array_key_exists($s_wgt_name, $a_page_widgets) || $a_page_widgets[$s_wgt_name]['region'] != $s_region) {
        $widgets[$s_wgt_name]['overides'][] = $s_page_readable;
      }
    }
  }
}

/**
 * For the Layout Display, Check to see if a widget should be disabled
 * If so add a parameter telling the object to be display none
 *
 * This is not used outside of the CP
 *
 * @param $widgets array or widgets
 * @param $a_feature_contexts array of contexts
 * @param $space space to check for overides
 */
function vsite_layout_ui_check_for_disabled_widgets(&$widgets, $space = NULL) {
  if (!count($widgets)) return; //Nothing to do because there are no widgets to act on
  if (!$space) $space = vsite_get_vsite(); //Get current Viste

  foreach ($widgets as $s_wgt_name => $wgt) {
  	//Let them in by default
  	$access = true;

  	global $user;
  	if($wgt['access callback'] && function_exists($wgt['access callback'])){
  		$access = call_user_func($wgt['access callback'],$wgt,$user);
  	}

  	//Also check default access function
  	//If the parent is a feature and it is disabled then lets not show this block
  	//or if views does not give access (usually using the feature access)
  	if($access) $access = vsite_layout_vsite_widgets_access($wgt,$user);


  	$widgets[$s_wgt_name]['hidden'] = !$access;
  }

}

/**
 * helper function for vsite_layout_ui-layout.tpl.php
 * Introduces a variable for each region in the admin_base theme
 * e.g. $vsite_layout_ui_header_left will contain a themed list of
 * block names in the header_left
 */
function vsite_layout_ui_cp_region_contents($widgets, $page_type) {

	$vars = array();
  $regions = system_region_list('scholar_base');

	foreach ($regions as $region => $s_label) {
    $wgts_id = 'scholarlayout-' . str_replace('_', '-', $region);
    $wgts = array_key_exists($region, $widgets)?$widgets[$region]:array();
    if ($page_type == 'none') vsite_layout_ui_check_for_overrides($wgts, $region);

    vsite_layout_ui_check_for_disabled_widgets($wgts);
    $vars[$region] = theme('vsite_layout_ui_layout_widgets', $wgts, $wgts_id, 'scholarlayout-widgets-list', ucwords($s_label));
  }

  $vars['content'] = theme('vsite_layout_ui_layout_widgets', array(), 'scholarlayout-content-main', 'scholarlayout-widgets-list', 'Main Content');

  return $vars;
}

/**
 * _vsite_layout_ui_build_dropdown
 * Given a list of widgets, builts a dropdown out of them
 * This is used to build the dropdown of factories on the cp layout form
 * @param array $factories - An Array of factory widgets
 * @return string - A themed ctools dropdown list
 */
function _vsite_layout_ui_build_dropdown($factories = array()) {
  // get a link for each factory
  $fact_links = array();
  foreach ($factories as $wgt) {
    // make sure there's a plugin
    vsite_layout_ui_find_widget_plugin($wgt);
    if (!os_boxes_box_access($wgt)) continue;

    // get info for the plugin
    $info = os_boxes_get_boxes_plugins($wgt['plugin']);

    // this is the primary group for the factory
    $group = $info['tags'][0];

    if (!isset($fact_links[$group])) {
      $fact_links[$group] = array(
        'data' => $group,
        'children' => array(),
      );
    }

    // check to see if this is a modalframe box. if it is, the path is different
    $uses_modalframe = false;
    $plugin = $info;
    while ($plugin['handler']['parent'] && !$uses_modalframe) {
      if ($plugin['handler']['parent'] == 'os_boxes_modalframe') {
        $uses_modalframe = true;
      }
      else {
        $plugin = os_boxes_get_boxes_plugins($plugin['handler']['parent']);
      }
    }

    // construct the link arrays
    $item = menu_get_item($wgt['block_config_path']);
    $item['href'] .= $uses_modalframe?'/modal/box/'.$wgt['plugin'].'/configure/dropdown':'/dropdown';
    $item['title'] = $wgt['label'];
    $item['attributes']['class'] = strtolower(implode(' ', array('ctools-use-modal', $wgt['plugin'])));
    $options = array(
    	'attributes' => array(
    		'class' => 'help',
    		'onclick' => "var w=window.open(this.href, 'advanced_help_window', 'width=500,height=500,scrollbars,resizable'); w.focus(); return false;"
      ),
      'query' => 'popup=1'
    );
    // build the links
    $fact_links[$group]['children'][$item['title']] = l($item['title'], $item['href'], $item).' '.l('Help', 'help/vsitehelp/'.$wgt['plugin'], $options);
  }
  $ordered = array();
  foreach ($fact_links as $grp => $data) {
    ksort($data['children']);
    if ($grp != 'Misc') {
      $ordered[$grp] = $data;
    }
  }
  ksort($ordered);
  $ordered['Misc'] = $fact_links['Misc'];
  // theme it!
  return theme('ctools_dropdown_content', t('Add New Widget'), theme('item_list', $ordered), FALSE, 'context-links');
}


/**
 * Form Controlls
 */

/*
 * The CP form for saving the block values and thier order
 */
function vsite_layout_ui_settings_form($form_state){

  $space = vsite_get_vsite();
  if(!$space) return array();

  //Support for ctools popups
  ctools_include('ajax');
  ctools_include('modal');

  // just do have distinct id for each setting form
  $form['#prefix'] = '<div id = "cp-settings-layout">';
  $form['#suffix'] = '</div>';

  $s_page_type = isset($_GET['page_type'])?$_GET['page_type']:'front';

  $a_page_types = vsite_layout_ui_get_pagetypes($space);

  $form['page_type'] = array(
    '#type' => 'select',
    '#title' => t('Site section'),
    '#default_value' => $s_page_type,
    '#options' => $a_page_types,
    '#description' => t('Widget will appear only in the selected section. "All Sections" indicates that widget will be displayed everywhere in your site.<br />'),
    '#weight' => 0,
    '#ahah' => array(
          'event' => 'go_ahah',
          'path' => 'cp/build/layout/region_widgets_js',
          'wrapper' => 'scholarlayout-container',
          'progress' => array('type' => 'throbber', 'message' => t('Loading Page...')),
          'effect' => 'fade',
          'method' => 'replaceWith',
    ),
  );

  $form['secret_hidden_ahah'] = array(
    '#type' => 'hidden',
    '#value' => $s_page_type,
    '#ahah' => array(
          'event' => 'go_ahah',
          'path' => 'cp/build/layout/top_widgets_js',
          'wrapper' => 'scholarlayout-top-widgets-wrapper',
          'effect' => 'fade',
          'progress' => array('type' => 'none'),
          'method' => 'replaceWith',
    ),
  );

  //Get the widgets available for this page type
  $layout_widgets = vsite_layout_ui_region_widgets($s_page_type);

  //Filter out just the unused widgets for the top area
  $unused_wgts = $layout_widgets['unused'];

  //Disable widgets that are part of inactive features
  vsite_layout_ui_check_for_disabled_widgets($unused_wgts);

  $regions = array_keys(system_region_list('scholar_base'));

  // create form elements for each region
  // changes made to the layout are saved in these
  foreach ($regions as $region) {
    $reg_id = 'scholarlayout-'.str_replace('_','-', $region);

    $default = '';
    if (is_array($layout_widgets[$region])) {
      $default = implode('|', array_keys($layout_widgets[$region]));
    }

    $form[$reg_id] = array(
      '#type' => 'hidden',
      '#default_value' => $default,
    );
  }

  //Markup for "Top" Available Widgets Section
  $form['available_widgets_markup'] = array(
    '#value' => theme('vsite_layout_ui_tagged_widgets', $unused_wgts, 'scholarlayout-top-widgets', 'scholarlayout-widgets-list'),
    '#weight' => 1,
  );

  $layout_regions = vsite_layout_ui_cp_region_contents($layout_widgets, $s_page_type);

  //The main layout area
  $form['layout_markup'] = array(
    '#value' => theme('vsite_layout_ui_layout', $layout_regions, $s_page_type),
    '#weight' => 2,
  );

  // pass the settingid too
  $form['setting'] = array(
    '#type' => 'value',
    '#value' => 'layout',
  );

  // add the submit button (not in the form definition yet)
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
    '#weight' => 100,
  );

  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
    '#submit' => array('vsite_layout_ui_settings_form_reset'),
    '#access' => user_access('reset layout to defaults'),
    '#weight' => 101,
  );

  return $form;

}

/**
 * Reset function for the CP blocks form to return the settings for the current theme to defaults
 */
function vsite_layout_ui_settings_form_reset($form, &$form_state) {
  $space = vsite_get_vsite();
  if(!$space) return;

  foreach (array_keys(vsite_layout_ui_get_pagetypes($space)) as $s_page_type) {
    $space->controllers->context->del('openscholar-feature-'.$s_page_type.":reaction:block:".$space->group->og_theme);
  }
}

/**
 * Save Handler for the CP Layout Form
 */
function vsite_layout_ui_settings_form_submit($form, &$form_state) {
  $space = vsite_get_vsite();
  if(!$space) return;

  $s_page_type = $form_state['values']['page_type'];
  $regions = array_keys(system_region_list('scholar_base'));

  //Gather the region settings from the form values
  $region_setting = array();
  foreach ($form_state['values'] as $field => $value) {
    $field = str_replace('-', '_', str_replace('scholarlayout-', '', $field));
    if (!in_array($field, $regions)) continue;

    $a_values = strlen($value)?split("\|", $value):array();
    foreach ($a_values as $val) $setting[$val] = $field;
  }

  //Apply the region settings
  $a_avalible_blocks = $space->controllers->context->get('openscholar-feature-'.$s_page_type.":reaction:block");
  _vsite_layout_ui_add_new_widgets($a_avalible_blocks['blocks']);

  //Sort them for easy display
  uasort($a_avalible_blocks['blocks'], 'vsite_layout_sort_block_by_weight');

  foreach ($a_avalible_blocks['blocks'] as $s_key => $block) {
    $a_avalible_blocks['blocks'][$s_key]['region'] = isset($setting[$s_key])? $setting[$s_key]:false;
    $a_avalible_blocks['blocks'][$s_key]['weight'] = array_search($s_key,array_keys($setting));
  }

  uasort($a_avalible_blocks['blocks'], 'vsite_layout_sort_block_by_weight'); //Put them in the right order to simplify showing them in the cp
  if($s_page_type == 'none') vsite_layout_apply_layout_changes($a_avalible_blocks);
  $space->controllers->context->set('openscholar-feature-'.$s_page_type.":reaction:block:".$space->group->og_theme, $a_avalible_blocks);

  if ($s_page_type && $s_page_type != 'front') {
    $form_state['redirect'] = array($_GET['q'], "page_type=" . $s_page_type);
  }
}



/**
 * CP Layout Helper Functions
 */

/**
 * Return a List of the Page Types Avalible
 *
 * @param vsite $space
 */
function vsite_layout_ui_get_pagetypes($space = null) {
  if (!$space && !($space = vsite_get_vsite()))  return array(); //No valid space

  static $a_page_types;

  if ($a_page_types) return $a_page_types;

  $contexts = context_load();
  $space_features = spaces_features('og');
  $a_feature_permissions = $space->controllers->variable->get('spaces_features');

  module_load_include('inc', 'features', 'features.export');
  $feature_context_map = features_get_default_map('context');

  $a_first = array('front','none'); //Include First in the List
  $a_page_types = array();
  $a_features = array();
  foreach ($contexts as $s_key => $context) {
    //Is this a site "Section"?
    if(strpos($s_key,"openscholar-feature-") !== 0 || !($s_shortname = str_replace("openscholar-feature-","",$s_key))) continue;

    //If this is a spaces feature is the feature Enabled?
    if(isset($space_features[$feature_context_map[$s_key]]) && !$a_feature_permissions[$feature_context_map[$s_key]] ) continue;

    $s_nice_name = ($context->description)? ucfirst($context->description): ucfirst($s_shortname);

    //Move front to the ... front of the list
    if (in_array($s_shortname,$a_first)) {
      if($s_shortname == 'none'){
        $a_page_types = array_merge(array($s_shortname => $s_nice_name), $a_page_types);
      } else {
        $a_page_types[$s_shortname] = $s_nice_name;
      }
    }else{
      $a_features[$s_shortname] = $s_nice_name;
    }
  }
  asort($a_features,SORT_STRING); //Alpha order
  $a_page_types = array_merge($a_page_types,$a_features);

  return $a_page_types;
}

/**
 * Returns an associative array by region of widgets
 *
 * This is used mostly to display what blocks are avalible in the layout page
 * This function also modifies the widgets to ensure they have all the necessary
 * properties.
 *
 * @param string $page_type
 * @return array
 */
function vsite_layout_ui_region_widgets( $page_type = 'none') {

  // get default context
  $space = vsite_get_vsite();
  $blocks = $space->controllers->context->get('openscholar-feature-'.$page_type.":reaction:block");
  $blocks = $blocks['blocks'];

  // get default widgets
  $default_blocks = vsite_layout_get_widgets();
  foreach ($default_blocks as $s_key => $a_block) {
    $default_blocks[$s_key]['region'] = false; //Get any new blocks that have been introduced, and include them in the top bar
  }

  $a_region_widgets = array('unused' => array());
  if ($blocks) {
    $a_widgets = array_merge($default_blocks, $blocks);
  }
  else {
    $a_widgets = $default_blocks;
  }
	uasort($a_widgets, 'vsite_layout_sort_block_by_weight'); //Put them in the right order to simplify showing them in the cp

  foreach ($a_widgets as $s_widget_key => $widget) {
    $widget = (array)$widget;

    // blocks stored in context override have old path
    // and could overwrite the defaults
    if (isset($default_blocks[$s_widget_key])) {
      $widget['tags'] = $default_blocks[$s_widget_key]['tags'];
      $widget['plugin'] = $default_blocks[$s_widget_key]['plugin'];
      $widget['access callback'] = $default_blocks[$s_widget_key]['access callback'];
      $widget['block_config_path'] = $default_blocks[$s_widget_key]['block_config_path'];
      // if this is a local instance or if there is a factory for this box type, we can delete it
      $widget['can_delete'] = strpos($widget['delta'], 'og-') !== FALSE || isset($a_widgets['boxes-boxes_add__'.$widget['plugin']]);
      if ($widget['can_delete']) {
        // the delete path is always the same
        $widget['block_delete_path'] = "cp/build/layout/nojs/".$widget['delta']."/delete";
      }
    }else{
    	static $existing_blocks = array();
    	//Get avalible blocks for this module
    	if(!isset($existing_blocks[$widget['module']])) $existing_blocks[$widget['module']] = module_invoke($widget['module'], 'block', 'list');

    	//Check to make sure this block still exists
    	if(is_array($existing_blocks[$widget['module']]) && !array_key_exists($widget['delta'],$existing_blocks[$widget['module']])){
    		unset($a_widgets[$s_widget_key]);
    		continue;
    	}
    }

    if (!is_array($widget['tags'])) {
      $widget['tags'][] = 'Misc';
    }
    $widget['class'] = strtolower(implode(' ', $widget['tags']));

    if ($widget['region']) {
      $a_region_widgets[$widget['region']][$s_widget_key] = $widget;
    }
    else {
      $a_region_widgets['unused'][$s_widget_key] = $widget;
    }
  }

  return $a_region_widgets;
}

// given a widget created by boxes, get the plugin used to define the box
function vsite_layout_ui_find_widget_plugin(&$widget) {
  if (!isset($widget['plugin']) && $widget['module'] == 'boxes') {
    if ($box = boxes_load($widget['delta'])) {
      $widget['plugin'] = $box->plugin_key;
    }
    else {
      $widget['plugin'] = str_replace('boxes_add__', '', $widget['delta']);
    }
  }
}

function _vsite_layout_ui_add_new_widgets(&$widgets) {
  $all_widgets = vsite_layout_get_widgets();
  foreach ($all_widgets as $key => &$w) {
    $w['region'] = false;
    if($w['factory']) unset($all_widgets[$key]);
  }

  $widgets += $all_widgets;
}