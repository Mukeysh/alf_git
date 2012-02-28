<?php

/**
 * Build a view object.
 *
 * This function converts a simple set of parameters into a full View definition.
 *
 * @param $simpleview

 *   $simpleview['filter']    (Optional, defaults to 'all')
 *   $simpleview['style']     (Optional, defaults to 'teasers')
 *   $simpleview['sort']      (Optional, defaults to 'newest')
 *   $simpleview['argument']  (Optional)
 *
 *   For individual properties inside $simplview, accepted values include:
 *   $simpleview['filter']    'all', or 'node:$nodetype'
 *   $simpleview['style']     'teasers', 'titles', or 'gallery'
 *   $simpleview['sort']      'newest', 'oldest', 'a-z', 'rating', or 'hits'
 *   $simpleview['argument']  'author', 'date', 'term:$vid', or 'field:$fieldname'
 *
 * @return
 *   A newly constructed View object. To be properly handled by the Views module,
 *   the $view->name property must be set.
 */
function _spaces_simpleviews_build_view($simpleview = array()) {
  //$simpleview += spaces_simpleviews_default_data();

  views_include('view');
  // Now we'll set up the basic starting structure.
  $view = new view;
  $view->name = 'os_simpleview';
  $view->description = "Generated automatically by os_simpleview module.";
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE;

  // Bootstrap the default display for the view. Here's where the action happens.
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('title', $simpleview['title']);  //@todo not really needed


  
  //$handler->override_option('use_ajax', TRUE); // @todo not working
  $handler->override_option('items_per_page', $simpleview['number_of_items']); 
  /*
  if ($simpleview['use_pager']){
    $handler->override_option('use_pager', 'mini'); 
  }
  */
  
  // the row style based on the style selected by the user (e.g. teaser, fields)
  _spaces_simpleviews_set_row_style($handler, $simpleview);
  _spaces_simpleviews_add_filter($handler, $simpleview);
  _spaces_simpleviews_add_sort($handler, $simpleview);
  _spaces_simpleviews_add_argument($handler, $simpleview);


  // we dont add any display (page, block, rss etc.). The caller
  // would have to load this view and execute it in hook_menu / hook_block etc.

  // in case someone wants to alter
  drupal_alter('os_simpleview', $view, $simpleview);

  // We will NOT save the view. Instead we're going to return it so others can
  // expose it as a default, save it to the DB, or whatever they'd like to do.
  return $view;
}

function _spaces_simpleviews_set_row_style($handler, $simpleview){
  // teaser or fields ?

  if ($simpleview['style'] == 'teasers') {
    _spaces_simpleviews_set_display_to_teaser_list($handler, $simpleview);
  }
  elseif ($simpleview['style'] == 'titles') {
    _spaces_simpleviews_set_display_to_title_list($handler, $simpleview);
  }

}

/**
 * sets the display to teaser view
 */
function _spaces_simpleviews_set_display_to_teaser_list(&$handler, $simpleview){
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'teaser' => 1,
    'links' => 1,
    'comments' => 0
  ));
}
/**
 * sets the display to list view
 */
function _spaces_simpleviews_set_display_to_title_list(&$handler, $simpleview) {

  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array('button' => 'Use default'),
    ),
  ));
  $handler->override_option('row_plugin', 'fields');
  $handler->override_option('style_plugin', 'list');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'type' => 'ul',
  ));
}


function _spaces_simpleviews_add_filter(&$handler, $simpleview) {
  // We always want to add the status filter.
  $filters['status'] = array(
    'operator' => '=',
    'value' => 1,
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'status',
    'table' => 'node',
    'field' => 'status',
    'relationship' => 'none',
  );

  // .. and always show nodes in current space only

  $filters['current'] = array(
    'operator' => 'active',
    'value' => '',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'current',
    'table' => 'spaces',
    'field' => 'current',
    'relationship' => 'none',
  );

  // Currently, the only supported filters are per-node-type.
  // 'all' is actually just a passthrough option that doesn't apply
  // filtering beyond the standard 'published' check.
  $filter = $simpleview['filter'];
  $type_filter = array(
      'operator' => 'in',
      'value' => array(),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array('operator' => FALSE, 'label' => ''),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    );

  if (strstr($filter, 'node') !== FALSE && $type = end(explode(':', $filter))) {
    $filters['type'] = $type_filter;
    $filters['type']['value'] = array($type => $type);
  } elseif ($filter == 'all') {
    if (module_exists('vsite')) {
      // openscholar vsite integration - lists correct content types
      vsite_include('vsiteapi');
      $node_options = vsite_content_types();
      drupal_alter('vsite_content_types', $node_options);

      $filters['type'] = $type_filter;
      $types = array_combine(array_keys($node_options), array_keys($node_options));
      $filters['type']['value'] = $types;
    }
  }

  $handler->override_option('filters', $filters);
}


function _spaces_simpleviews_add_sort(&$handler, $simpleview) {
  switch ($simpleview['sort']) {
    case 'newest':
      $sorts['created'] =  array(
        'order' => 'DESC',
        'granularity' => 'second',
        'id' => 'created',
        'table' => 'node',
        'field' => 'created',
        'relationship' => 'none',
      );
      break;

    case 'oldest':
      $sorts['created'] =  array(
        'order' => 'ASC',
        'granularity' => 'second',
        'id' => 'created',
        'table' => 'node',
        'field' => 'created',
        'relationship' => 'none',
      );
      break;

    case 'a-z':
      $sorts['title'] = array(
        'order' => 'ASC',
        'id' => 'title',
        'table' => 'node',
        'field' => 'title',
        'relationship' => 'none',
      );
      break;

    case 'top-rated':
      if (module_exists('fivestar')) {
        // Use percentages
        $handler->override_option('relationships', array(
          'votingapi_cache' => array(
            'label' => 'Average',
            'required' => 0,
            'votingapi' => array(
              'value_type' => 'percent',
              'tag' => 'vote',
              'function' => 'average',
            ),
            'id' => 'votingapi_cache',
            'table' => 'node',
            'field' => 'votingapi_cache',
            'relationship' => 'none',
          ),
        ));
      }
      else if (module_exists('plus1') || module_exists('drigg')) {
        // Use points
        $handler->override_option('relationships', array(
          'votingapi_cache' => array(
            'label' => 'Average',
            'required' => 0,
            'votingapi' => array(
              'value_type' => 'points',
              'tag' => 'vote',
              'function' => 'sum',
            ),
            'id' => 'votingapi_cache',
            'table' => 'node',
            'field' => 'votingapi_cache',
            'relationship' => 'none',
          ),
        ));
      }

      $sorts['value'] = array(
        'order' => 'DESC',
        'id' => 'value',
        'table' => 'votingapi_cache',
        'field' => 'value',
        'relationship' => 'votingapi_cache',
      );
      break;

    case 'popular':
      $sorts['totalcount'] = array(
        'order' => 'DESC',
        'id' => 'totalcount',
        'table' => 'node_counter',
        'field' => 'totalcount',
        'relationship' => 'none',
      );
      break;
  }

  if (!empty($sorts)) {
    $handler->override_option('sorts', $sorts);
  }
}


function _spaces_simpleviews_add_argument(&$handler, $simpleview) {
  $argument = $simpleview['argument'];

  //dpm($argument);
  if ($argument == 'author') {
    $handler->override_option('arguments', array(
      'uid' => array(
        'default_action' => 'summary asc',
        'style_plugin' => 'default_summary',
        'style_options' => array(),
        'wildcard' => 'all',
        'wildcard_substitution' => 'All',
        'title' => '',
        'default_argument_type' => 'fixed',
        'default_argument' => '',
        'validate_type' => 'none',
        'validate_fail' => 'not found',
        'break_phrase' => 0,
        'not' => 0,
        'id' => 'uid',
        'table' => 'users',
        'field' => 'uid',
        'relationship' => 'none',
        'default_options_div_prefix' => '',
      ),
    ));
  }
  else if ($argument == 'date') {
    $handler->override_option('arguments', array(
      'created_year_month' => array(
        'id' => 'created_year_month',
        'table' => 'node',
        'field' => 'created_year_month',
        'validate_type' => 'none',
        'validate_fail' => 'ignore',
        'default_argument_type' => 'fixed',
        'relationship' => 'none',
        'default_action' => 'summary desc',
        'validate_argument_php' => '',
      ),
    ));
  }
  else if (strstr($argument, 'term:') !== FALSE && $vid = end(explode(':', $argument))) {
    $handler->override_option('arguments', array(
      'tid' => array(
        'default_action' => 'summary asc',
        'style_plugin' => 'default_summary',
        'style_options' => array(),
        'wildcard' => 'all',
        'wildcard_substitution' => 'All',
        'title' => '',
        'default_argument_type' => 'fixed',
        'default_argument' => '',
        'validate_type' => 'taxonomy_term',
        'validate_fail' => 'ignore',
        'break_phrase' => 0,
        'add_table' => 0,
        'require_value' => 0,
        'reduce_duplicates' => 1,
        'set_breadcrumb' => 1,
        'id' => 'tid',
        'table' => 'term_node',
        'field' => 'tid',
        'relationship' => 'none',
        'validate_argument_vocabulary' => array((string)$vid => $vid),
        'validate_argument_type' => 'convert',
      ),
    ));
  }
  else if (strstr($argument, 'field:')) {
    // No handling for this at the moment. In the future, we want
    // to have some custom handling for CCK field based arguments.
    // For now? No love.
  }
}
