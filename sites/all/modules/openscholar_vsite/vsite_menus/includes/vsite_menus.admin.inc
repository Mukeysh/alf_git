<?php
/**
 * Form Controls
 */

function _vsite_menus_get_menus() {
  $menus = variable_get('scholar_site_menus', array(
    'features' => 'Primary Menu',
    'scholar_secondary_menu' => 'Secondary Menu',
  ));

  $menus += array('none' => 'Not in a Menu');

  return $menus;
}

/*
 * The CP form for saving the block values and thier order
 */
function vsite_menus_settings_form($form_state){

  $space = vsite_get_vsite();
  if(!$space) return array();

  ctools_include('ajax');
  ctools_include('modal');

  $form['new_menu_link_context'] = array(
    '#type' => 'markup',
    '#value' => theme('item_list', array(
      ctools_modal_text_button('Add new Link', "cp/build/menus/add/nojs", 'add a link', 'context-button')
    ), $title = NULL, $type = 'ul', $attributes = array(
      "class" => "context-links"
    )),
  );

  // just do have distinct id for each setting form
  $form['#prefix'] = '<div id = "cp-settings-menus">';
  $form['#suffix'] = '</div>';
  $form['conf'] = array(
    '#type' => 'markup',
    '#value' => '',
    '#theme' => array('vsite_menus_settings'),
  );

  $a_site_menus = _vsite_menus_get_menus();

  //user_created

  // ensure these array entries exist so tabledrag doesn't crap out
  foreach ($a_site_menus as $m => $t) {
    $form['conf'][$m] = array();
  }

  //all that were avalible orig..
  $all_initial = $space->controllers->vsite_menu->get_multiple(array_keys($a_site_menus));

  $menus = array();
  $hidden_menus = array();
  foreach ($all_initial as $key => $link) {
    $path = $link['link_path'];
    list($initial_menu,$initial_path) = split(":",$key,2);
    if($initial_menu && $link['menu_name'] != $initial_menu){
    	$link['menu_name'] = $initial_menu;
    }//Sanity Check

    if (!$link['external']) {
      $menu = menu_get_item($path);
      if (!$menu['access']) continue;

      if($link['hidden'] && !array_key_exists($path,$hidden_menus)){
      	$hidden_menus[$path] = $link;
      	continue;
      }//Hidden
    }

    $hidden_menus[$path] = false;
    if (!isset($link['menu_name']) || !isset($a_site_menus[$link['menu_name']])) {
      // this link isn't in a menu already, or it is not a site menu
      $link['menu_name'] = 'none';
      $menus['none:'.$link['link_path']] = $link;
    }
    else {
      // this link is in a menu.
      // and it's in one of the accepted menus
      $menus[$key] = $link;
    }
  }

  $hidden_menus = array_diff($hidden_menus,array(false));
  foreach ($hidden_menus as $path => $link) {
  	$link['menu_name'] = 'none';
  	$menus['none:'.$link['link_path']] = $link;
  }

  foreach ($menus as $key => $link) {
    $link_path = $link['link_path'];
    $url = url($link_path, array('absolute' => TRUE));
    $form['conf'][$link['menu_name']][str_replace('.', '__', $key)] = array(
      '#tree' => TRUE,
      '#weight' => $link['weight'],
      'name' => array(
        '#type' => 'textfield',
        '#description' => l($url, $url),
        '#size' => 30,
        '#default_value' => !empty($link['link_title']) ? $link['link_title'] : ucwords(str_replace('_', ' ', $key)),
      ),
      'region' => array(
        '#type' => 'select',
        '#options' => $a_site_menus,
        '#default_value' => $link['menu_name'],
        '#attributes' => array(
          'class' => 'field-region-select field-region-'. $link['menu_name'],
        ),
      ),
      'weight' => array(
        '#type' => 'textfield',
        '#default_value' => $link['weight'],
        '#size' => 3,
        '#attributes' => array(
          'class' => 'field-weight field-weight-'. $link['menu_name'],
        ),
      ),
      'region-old' => array(
        '#type' => 'hidden',
        '#value' => $link['menu_name'],
      ),
      'link_path' => array(
        '#type' => 'value',
        '#value' => $link['link_path'],
      ),
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );

  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
    '#submit' => array('vsite_menus_settings_form_reset'),
  );

  /*
  $form['help_text'] = array(
    '#type' => 'markup',
    '#value' => '<div class="help-text">Drag links to order them and move them between menus.</div>',
  );
  */


  $form['#after_build'][] = 'vsite_menus_settings_form_after_build';

  return $form;

}

function vsite_menus_new_link_callback($js) {
  if ($js) {
    ctools_include('ajax');
    ctools_include('modal');

     $form_state = array(
      'title' => t('New Menu Link'),
      'ajax' => TRUE,
     );

     // get the ctools page now
     $output = ctools_modal_form_wrapper('vsite_menus_new_link_form', $form_state);
     if ($form_state['values']['op'] == $form_state['values']['cancel']) {
       $output[] = ctools_modal_command_dismiss();
     }
     elseif (empty($output)) {
       $output[] = ctools_ajax_command_reload();
     }
     ctools_ajax_render($output);
  }
  else {
    return drupal_get_form('vsite_menus_new_link_form');
  }
}

function vsite_menus_new_link_form(&$form_state) {
  $form = array();

  $a_site_menus = _vsite_menus_get_menus();

  $form['new_menu'] = array(
    '#type' => 'fieldset',
    'new_menu_title' => array(
      '#type' => 'textfield',
      '#title' => t('Menu Title'),
      '#description' => t('What text will appear for the entry.'),
    ),
    'new_menu_url' => array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#description' => t('Enter the URL for the new menu entry.'),
    ),
    'new_menu_region' => array(
      '#type' => 'select',
      '#title' => t('Default Region'),
      '#description' => t('Which menu should this entry go in?'),
      '#options' => array_diff_key($a_site_menus, array('none' => 0)),
    ),
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
  );

  $form['#validate'][] = 'vsite_menus_settings_form_validate';
  $form['#submit'][] = 'vsite_menus_settings_form_submit';

  return $form;
}

/**
 * Include the css in after_build so that it always appears with the form, even with a cached form
 */
function vsite_menus_settings_form_after_build($form, &$form_state) {
  //CSS To be included with the form
  drupal_add_js(drupal_get_path('module', 'nodeformcols') . '/js/nodeformcols.js');
  drupal_add_css(drupal_get_path('module', 'vsite_menus') . '/theme/vsite_menus.css');
  $regions = _vsite_menus_get_menus();    // this line is why I needed to copy it
  foreach ($regions as $region => $title) {
    if (is_array($form['conf'][$region])) {
      uasort($form['conf'][$region], "element_sort");
      drupal_add_tabledrag('fields', 'match', 'sibling', 'field-region-select', 'field-region-'. $region, NULL, FALSE);
      drupal_add_tabledrag('fields', 'order', 'sibling', 'field-weight', 'field-weight-'. $region);
    }
  }
  return $form;
}

/**
 * Reset function for the CP blocks form to return the settings for the current theme to defaults
 */
function vsite_menus_settings_form_reset($form, &$form_state) {
  $space = vsite_get_vsite();
  if(!$space) return;

  foreach (array_keys(_vsite_menus_get_menus()) as $s_menu) {
    $space->controllers->vsite_menu->del($s_menu);
  }
}

function vsite_menus_settings_form_validate(&$form, &$form_state) {
  if ($form_state['values']['new_menu_title'] XOR $form_state['values']['new_menu_url']) {
    // if only one is set
    form_set_error($form_state['values']['new_menu_title']?'new_menu_url':'new_menu_title', t('Missing URL or Title for new link!'));
  }
  elseif ($form_state['values']['new_menu_title'] && $form_state['values']['new_menu_url']) {
  	global $base_url;

  	$vsite = vsite_get_vsite();
  	$site_base = $vsite->get_absolute_url();

  	if(strpos($form_state['values']['new_menu_url'],$site_base) === 0){
  		$a_path_info = parse_url($form_state['values']['new_menu_url']);
  		$form_state['values']['new_menu_url'] = $a_path_info['path'];
  	}//Strip off the domain if this is a local path

  	if(menu_path_is_external($form_state['values']['new_menu_url'])){
  	  $form_state['values']['new_menu_router_path'] = $form_state['values']['new_menu_url'];
  	}else{
  		$form_state['values']['new_menu_url'] = drupal_get_normal_path(ltrim($form_state['values']['new_menu_url'],"/"));

  		$item = menu_get_item($form_state['values']['new_menu_url']);
  		if($item && $item['access']){
  			$form_state['values']['new_menu_router_path'] = $item['path'];
  		}
  	}

    // the link isn't valid.
    if(!isset($form_state['values']['new_menu_router_path'])) form_set_error('new_menu_url', t('The URL is not valid'));
  }
}

/**
 * Save Handler for the CP Menus Form
 */
function vsite_menus_settings_form_submit($form, &$form_state) {
  $space = vsite_get_vsite();
  if(!$space || $form_state['values']['op'] == $form_state['values']['cancel']) return;

  $menus = $space->controllers->vsite_menu->get();

  foreach ($form_state['values'] as $key => $data) {
    if (!is_array($data)) continue;
    $key = str_replace('__', '.', $key);

    // set some vars for readability
    $region_old = $data['region-old'];
    $region = $data['region'];
    $menu_key = $region.':'.$data['link_path'];

    // the underlying structure is like this:
    // $menus['features']['features:bio']

    $link =& $menus[$region_old][$key];

    if(!$link){
    	$link = vsite_menus_get_menu_item($data['link_path'],false,true);
    }

    if ($region_old != $region) {
      // the regions are different.
      // move the link into the new region
      $menus[$region][$menu_key] =& $link;
      // and remove it from the old
      unset($menus[$region_old][$key]);
    }

    $link['link_title'] = $data['name'];
    $link['menu_name'] = $data['region'];
    $link['weight'] = $data['weight'];
    $link['key'] = $menu_key;
    $link['hidden'] = false;

    if ($link['user_created'] && $region == 'none' || !isset($link['link_path'])) {
      // we're deleting the link
      unset($menus[$region][$menu_key]);
    }
    drupal_set_message(t("Menu Settings Saved."), 'status', false);
  }

  if ($form_state['values']['new_menu_title'] && $form_state['values']['new_menu_url']) {

    // add a new menu
    $new_link = array(
      'menu_name' => $form_state['values']['new_menu_region'],
      'link_path' => $form_state['values']['new_menu_url'],
      'router_path' => $form_state['values']['new_menu_router_path'],
      'key' => $form_state['values']['new_menu_region'].':'.$form_state['values']['new_menu_url'],
      'link_title' => check_plain($form_state['values']['new_menu_title']),
      'options' => array(),
      'module' => 'system',
      'hidden' => '0',
      'external' => menu_path_is_external($form_state['values']['new_menu_url'])?'1':'0',
      'has_children' => '0',
      'expanded' => '0',
      'user_created' => TRUE,
    );
    $new_link['weight'] = count($menus[$new_link['menu_name']]) + 10;//Add the new link to the end of the list

    $menus[$new_link['menu_name']][$new_link['key']] = $new_link;
    drupal_set_message(t("New Link Added."), 'status', false);
  }

  foreach ($menus as $key => $data) {
    $space->controllers->vsite_menu->set($key, $data);
  }
}
