<?php

/**
 * API function which construct an autocomplete node field
 * TODO caller should be able to override the element attributes
 * not just the title
 */
function vsite_node_autocomplete_element($title = NULL){
  $item = array(
    '#type' => 'textfield',
    '#title' => $title ? $title : t('Select a post'),
    '#maxlength' => 180,
    '#autocomplete_path' => 'vsite/node/autocomplete',
    '#element_validate' => array('vsite_node_autocomplete_validate'),
    '#description' => t('Start typing the title of an existing post')
  );
  
  return $item;
}

/**
 * schlar nodeautocomplete callback function
 */
function vsite_node_autocomplete($str){

  //initialize view to generate sessions output when viewing a conference
  $view = views_get_view('vsite_autocomplete');
  $view->init();

  $view->set_display('default');
  $view -> set_items_per_page(0);
  $view -> execute();
  foreach ($view -> result as $node){
    if(stristr($node -> node_title, $str)){
     $matches[$node -> node_title. ' [nid:' . $node->nid . ']'] = check_plain($node -> node_title);
    }
  }

  print drupal_to_js($matches);
  exit();
}


function vsite_node_autocomplete_validate($element, &$form_state){
  $element_value = $element['#value'];
  if ($element_value){
    $nid = _vsite_node_autocomplete_title_to_nid($element_value);
    
    if ($nid) {
      $form_state['scholar_referenced_nid'] = $nid;
    }
    else {
      form_error($element, t('This post title is not valid'));
    }
  }
}

function _vsite_node_autocomplete_title_to_nid($title){
  preg_match('/^(?:\s*|(.*) )?\[\s*nid\s*:\s*(\d+)\s*\]$/', $title, $matches);
  if (!empty($matches)) {
    return $matches[2];
  }elseif (intval($title)){
  	//Have we been passed a nid and not a title?
  	return intval($title);
  }else {
    return NULL;
  }

}

function _vsite_node_autocomplete_nid_to_title($nid){
  $query = "SELECT n.title FROM {node} n WHERE n.nid=%d";
  $title = db_result(db_query($query, $nid));
  $title .= ' [nid:' . $nid . ']';
  return $title;
}