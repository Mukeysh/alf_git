<?php

/**
 * recursive function to build the tree of terms
 * @see vsite_taxonomy_vocabs
 */
function theme_vsite_taxonomy_term_list($current_index, $tree, $s_term_theme = 'vsite_taxonomy_term', $b_description = true, $b_show_empty = true, $b_show_admin_links = true, $s_term_feature = false, $b_feature_context = false){
	static $index;
	$index = $current_index; //Remove need for pass_by_ref which theme funcs don't support
	
  $items = array();

  $a_filter_nodes = array();
  if($s_term_feature){
    $a_filter_nodes = vsite_taxonomy_get_nodes_in_feature($s_term_feature);
  }//Retrieve nodes that the list should be filtered by if a feature is passed
  
  $vocab = taxonomy_vocabulary_load($tree[$index]->vid);
  //Is this vocab a tree, if so include the childeren in the count
  $b_count_childeren = (bool) $vocab->hierarchy;
  
  $current_depth = $tree[$index]->depth;
  while ( $index < count($tree) && $tree[$index]->depth >= $current_depth ) {
    $term = $tree[$index];
    $b_show_term = ($b_show_empty || vsite_taxonomy_term_count_nodes($term->tid, $b_count_childeren, $a_filter_nodes));

    if ($tree[$index + 1]->depth > $current_depth) {
      $index ++;
      
      $item = array(
        'data' => theme($s_term_theme, $term, $b_description, $b_show_admin_links, $s_term_feature, $b_feature_context),
        'children' => theme('vsite_taxonomy_term_list',$index, $tree,$s_term_theme, $b_description, $b_show_empty, $b_show_admin_links, $s_term_feature, $b_feature_context),
        'class' => "term-".strtolower(str_replace(" ","-",$term->name)),
      );
      
      if($b_show_term || $item['children']) {
        $items[] = $item;
      }//Show term with values, or if the terms childeren have values
    }
    else {
      if($b_show_term) $items[] = theme($s_term_theme, $term, $b_description, $b_show_admin_links, $s_term_feature, $b_feature_context);
      $index ++;
    }
  }
  return $items;
}
