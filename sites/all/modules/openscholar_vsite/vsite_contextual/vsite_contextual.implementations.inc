<?php

/**
 * Contextual Annotation
 */

/**
 * iqss_gking
 */

/**
 * Implementation of hook_vsite_admin_link()
 */
function scholar_biocv_vsite_admin_link($type, $object){
  $links = array();
  $vsite = vsite_get_vsite();
  if ($vsite && $type == 'node' && $object->type == 'bio' &&
     ($cv_node = content_profile_load('cv', $vsite->group->uid))) {

    $path = "node/{$cv_node->nid}/edit";
    $item = menu_get_item($path);
    if ($item && $item['access']) {

      $links['node-edit-cv'] = array(
        'title' => t('Edit CV'),
        'href' => $path,
        'attributes' => array(
          'class' => 'icon-edit'
        ),
        'query' => array(
          'destination' => $_GET['q']
        )
      );
    }

  }
  return $links;
}


/**
 * Implementation of hook_link().
 */
function scholar_front_vsite_admin_link($type, $object){
  $links = array();
  global $user;
  //check font page settings here, only execute if front page setting equals flag
  $vsite = vsite_get_vsite();
  if(!$vsite) return array();

  $a_front_settings = $vsite->controllers->variable->get('vsite_setting_front');
  if ($a_front_settings['frontpage'] !== 'flag' ||
      !($vsite -> access_admin()) ||
      !flag_fetch_definition($type)){
    return $links;
  }



  // Get frontpage flags
  $flag = flag_get_flag('scholar_frontpage');


  if (!$flag->applies_to_content_object($object)) {
    // Flag does not apply to this content.
    return false;
  }

  $content_id = $flag->get_content_id($object);
  // The flag links are actually fully rendered theme functions.
  // The HTML attribute is set to TRUE to allow whatever the themer desires.
  $links['flag-'. $flag->name] = array(
  'title' => $flag->theme($flag->is_flagged($content_id) ? 'unflag' : 'flag', $content_id),
  'html' => TRUE,
  );

  if (isset($links)) {
    return $links;
  }
}


/**
 * Implementation of hook_scholar_admin_link() on behalf of the node module.
 */
function scholar_software_vsite_admin_link($type, $object) {
  $links = array();
  if ($type == 'node' && $object->type == 'scholar_software_project' && empty($object->field_scholar_software_method[0]['value'])) {

    $item = menu_get_item('node/add/scholar-software-release');
    if ($item && $item['access']) {
      $links['scholar-software-add-release'] = array(
        'title' => t('Add new Release'),
        'href' => 'node/add/scholar-software-release',
        'query' => array('software_name' => $object->field_scholar_software_name[0]['value']),
      );
    }
  }
  return $links;
}

/**
 * Implementation of hook_vsite_admin_link
 */
function vsite_taxonomy_vsite_admin_link($type, $object){
  $links = array();
  // edit/delete links for vocabularies
  if ($type == 'vocabulary') {

    $links[] = array(
      'title' => 'edit',
      'href' => 'vsite/taxonomy/nojs/edit/vocabulary/' . $object -> vid,
      'attributes' => array(
        'class' => 'ctools-use-dialog edit-link'
      )
    );
  }
  elseif ($type == 'term') {

    $links[] = array(
      'title' => 'edit',
      'href' => 'vsite/taxonomy/nojs/terms/edit/' . $object->tid,
      'attributes' => array(
        'class' => 'ctools-use-dialog edit-link'
      )
    );

    $vocab = taxonomy_vocabulary_load($object->vid);
    if(!$vocab->tags){
	    $links[] = array(
	      'title' => 'add child',
	      'href' => 'vsite/taxonomy/nojs/terms/'.$object->vid.'/add_term/'.$object->tid,
	      'attributes' => array(
	        'class' => 'ctools-use-dialog edit-link'
	      )
	    );
    }
  }

  return $links;
}

/**
 * Implementation of hook_admin_link().
 */
function vsite_widgets_vsite_admin_link($type, $object){
  $links = array();
  global $user;
  //check font page settings here, only execute if front page setting equals flag
  if(!($vsite = vsite_get_vsite()) || !is_object($vsite)){
    return $links;
  }

  if (!($vsite->access_admin()) ||
      !flag_fetch_definition($type)){
    return $links;
  }

  // Get frontpage flags
  $flag = flag_get_flag('featuredposts');


  if (!$flag->applies_to_content_object($object)) {
    // Flag does not apply to this content.
    return false;
  }

  $content_id = $flag->get_content_id($object);
  // The flag links are actually fully rendered theme functions.
  // The HTML attribute is set to TRUE to allow whatever the themer desires.
  $links['flag-'. $flag->name] = array(
  'title' => $flag->theme($flag->is_flagged($content_id) ? 'unflag' : 'flag', $content_id),
  'html' => TRUE,
  );

  if (isset($links)) {
    return $links;
  }
}