<?php

/**
 * theme a individual term
 * @param unknown_type $term
 */
function theme_vsite_taxonomy_term($term, $b_description = true, $b_admin_links = true, $s_term_feature = false, $b_feature_context = false){

  $a_filter_nodes = array();
  if($s_term_feature){
    $a_filter_nodes = vsite_taxonomy_get_nodes_in_feature($s_term_feature);
  }//Retrieve nodes that the list should be filtered by if a feature is passed

  $vocab = taxonomy_vocabulary_load($term->vid);
  //Is this vocab a tree, if so include the childeren in the count
  $b_count_childeren = (bool) $vocab->hierarchy;
  
  $count = vsite_taxonomy_term_count_nodes($term->tid, $b_count_childeren, $a_filter_nodes);
  
  if($count <= 0){
    $term_link = $term->name;

  }else{
    $term_link = l($term->name, _vsite_taxonomy_get_term_path($term->tid,$s_term_feature, $b_feature_context), array('title' => t($term->description)));
  }

  $item = '<div class="term-head">' . $term_link;

  $item .= ($count > 0)?'<span class = "count" > (' . $count . ')</span>':"";

  if($b_admin_links && cp_access_cp()){
    // add term's admin links
    $item .= theme('links', vsite_get_admin_links('term', $term), $attributes = array(
      'class' => 'admin'
    ));
  }

  if ($b_description && $term -> description) {
    $item .= '<div class="description">' . $term -> description . '</div>';
  }

  $item .= '</div><!--/term-head-->';

  return $item;
}