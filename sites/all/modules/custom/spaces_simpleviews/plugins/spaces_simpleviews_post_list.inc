<?php

/**
 * @file
 * The class for "list" type widgets.  It allows users to define widgets that are
 * list of posts (i.e. latest anouncements, blogs etc).
 * It's simply an interface to an existing view (as in views module)
 */

class spaces_simpleviews_post_list extends boxes_box {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults(){
    $options = array(
      'filter' => 'all nodes',  // @todo get the current context and the node type(s) associated with it, make that the default
      'style' => 'titles',
      'sort' => 'newest',
      'argument' => '',
      'number_of_items' => 6,
      //'use_pager' => 1,
      'more' => 0,
      'more_text' => t('more'),
      'more_link' => ""
    );
    
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    $simpleview  = $this -> options;
    
    $form['filter'] = array(
      '#type' => 'select',
      '#title' => t('Display'),
      '#options' => array(
        'all' => t('All posts')
      ),
      '#required' => TRUE,
      '#default_value' => $simpleview['filter']
    );
    ctools_include('ajax');
    ctools_add_js('ajax-responder');
    ctools_ajax_associate_url_to_element($form, $form['filter'], url('spaces_simpleviews/nodetype_js'), 'ctools-use-ajax-onchange');
    
    // os/vsite integration - lists correct content types
    if (module_exists('vsite') && vsite_get_vsite()) {
      vsite_include('vsiteapi');
      //Get public and private types
      $node_options = vsite_content_types(array(1,2));
      drupal_alter('vsite_content_types', $node_options);
    }
    
    if (! isset($node_options)) {
      $node_options = node_get_types('names');
    }
    
    asort($node_options);
    foreach ( $node_options as $type => $name ) {
      $form['filter']['#options']['node:' . $type] = t('!type posts', array(
        '!type' => $name
      ));
    }
    
    $form['sort'] = array(
      '#type' => 'select',
      '#title' => t('Sort'),
      '#options' => array(
        'newest' => t('Newest first'),
        'oldest' => t('Oldest first'),
        'a-z' => t('By title')
      ),
      '#required' => TRUE,
      '#default_value' => $simpleview['sort']
    );
    if (module_exists('statistics')) {
      $form['sort']['#options']['popular'] = t('By number of hits');
    }
    if (module_exists('votingapi')) {
      $form['sort']['#options']['top-rated'] = t('By rating');
    }
    
    $form['style'] = array(
      '#type' => 'select',
      '#title' => t('Display Style'),
      '#options' => array(
        //'full' => t('List of full posts'),
        'teasers' => t('List of teasers'),
        'titles' => t('List of titles')
      ),  //'grid' => t('Grid of thumbnails'),
      '#required' => TRUE,
      '#default_value' => $simpleview['style']
    );
    
    $form['number_of_items'] = array(
      '#type' => 'textfield',
      '#title' => 'Number of displayed posts',
      '#default_value' => $simpleview['number_of_items'],
      '#size' => 10
    );
    
    /*
    $form['use_pager'] = array(
      '#title' => t('Add pager'),
      '#type' => 'checkbox',
      '#default_value' => $simpleview['use_pager'],
      '#description' => t('Will add a pager at the end of the list')
    );
    */
    
    ctools_include('dependent');
    ctools_add_js('dependent');
    
    $form['more'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add "more" link'),
      '#description' => t('This will add a more link to the bottom of this widget, which will link to the page listing all the posts of type selected above'),
      '#default_value' => $simpleview['more'],
      '#tree' => TRUE
    );
    
    $form['more_text'] = array(
      '#type' => 'textfield',
      '#title' => t('Label'),
      '#default_value' => $simpleview['more_text'],
      '#description' => t("The title / label of the link."),
      '#process' => array(
        'ctools_dependent_process'
      ),
      '#dependency' => array(
        'edit-more' => array(
          1
        )
      )
    );
    
    $form['more_link'] = array(
      '#type' => 'textfield',
      '#title' => t('Link'),
      '#default_value' => $simpleview['more_link'],
      '#description' => t("The url/path for this link."),
      '#process' => array(
        'ctools_dependent_process'
      ),
      '#dependency' => array(
        'edit-more' => array(
          1
        )
      )
    );
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render(){
    
    //prepare the view
    $simpleview = $this->options;

    $view = spaces_simpleviews_build_view($simpleview);
    $view->init();
    $view->set_display('default');
   
    // trick the view to calculate the total nr of items
    $view->get_total_rows = TRUE;
    $content = $view->execute_display();

    //add the "more" link. We show "more" only if "more" checkbox is selected
    // *AND* number of items returned by the view is > nr of itemes in the box settings
    if ($simpleview['more'] && ($view -> total_rows > $simpleview['number_of_items']) ) {
      
      $more_text = $simpleview['more_text'];
      $more_path = url($simpleview['more_link']);
      
      if (strlen($more_path)) {
        $content .= theme('views_more', $more_path, $more_text);
      }
    }elseif (!$view -> total_rows){
    	$content = '';
    }
    
    $title = isset($this->title) ? check_plain($this->title) : NULL;
    $block = array(
      'title' => $title,
      'subject' => $title,
      'delta' => $this->delta,
      'content' => $content
    );
    
    return $block;
  }

}


