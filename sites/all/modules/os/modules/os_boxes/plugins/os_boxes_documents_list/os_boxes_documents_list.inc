<?php

/**
 * @file
 * The class for "recent documents" widget.
 */

class os_boxes_documents_list extends os_boxes_default {
  
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['number_of_items'] = 6;
    $options['more'] = 0;
    $options['more_text'] = t('more');
    $options['more_link'] = "documents";
    $options['use_pager'] = 1;
    $options['style'] = 'titles';

    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    ctools_include('dependent');
    ctools_add_js('dependent');
    
  	$form['style'] = array(
      '#type' => 'select',
      '#title' => t('Display Style'),
      '#options' => array(
        'teasers' => t('List of teasers'),
        'titles' => t('List of titles')
      ),
      '#required' => TRUE,
      '#default_value' => $this->options['style']
    );
    
  	$form['number_of_items'] = array(
      '#type' => 'textfield',
      '#title' => 'Number of displayed posts',
      '#default_value' => $this->options['number_of_items'],
      '#size' => 10
    );
    
    $form['use_pager'] = array(
      '#title' => t('Add pager'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['use_pager'],
      '#description' => t('Will add a pager at the end of the list')
    );
    
    $form['more'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add "more" link'),
      '#description' => t('This will add a more link to the bottom of this widget, which will link to the page listing of posts'),
      '#default_value' => $this->options['more'],
      '#tree' => TRUE
    );
    
    $form['more_text'] = array(
      '#type' => 'textfield',
      '#title' => t('Label'),
      '#default_value' => $this->options['more_text'],
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
      '#default_value' => $this->options['more_link'],
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
    
    $form += parent::options_form();
    return $form;
  }
  
  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    $block = parent::render();

    $view_name = 'scholar_books';
    $display_id = "block_1";
    
    if ($view = views_get_view($view_name)) {
      if ($view->access($display_id)) {
        $view->set_display($display_id);
        
        //Tie this view to this box (this tells the view to call this box's view alter)
        $view->dom_id = "boxes-".$this->delta;
        
        $output = $view->execute_display();
        $block['content'] = $output['content'];
      }
      $view->destroy();
    }

    //ADD THE MORE TEXT
    if(strlen($block['content']) && $this->options['more']){
      $block['content'] .= theme('views_more', url($this->options['more_link']), $this->options['more_text']);
    }

    return $block;
  }

  /**
   * Called from views_pre_view
   *
   * @param view $view
   */
  public function views_alter(&$view, &$display_id, &$args){
    //Set pager up
    if($this->options['use_pager']){
	    $view->display_handler->set_option('use_pager', 'mini');
	    $view->display_handler->set_option('use_ajax', TRUE);
    }else{
    	$view->display_handler->set_option('use_pager', false);
      $view->display_handler->set_option('use_ajax', false);
    }
    
	  //Sort by creation date, newest post first
    $view->display_handler->override_option('sorts', array(
      'created' => array(
        'order' => 'DESC',
        'granularity' => 'second',
        'id' => 'created',
        'table' => 'node',
        'field' => 'created',
        'override' => array(
          'button' => 'Override',
        ),
        'relationship' => 'none',
      ),
    ));
    
    //Set the number of items
    if(intval($this->options['number_of_items'])){
    	$view->display_handler->set_option('items_per_page',intval($this->options['number_of_items']));
    	$view->set_items_per_page(intval($this->options['number_of_items']));
    }
    
	  switch ($this->options['style']){
	  	case 'titles':
	  		//Change fron teaser view to using fields
	  		$view->display_handler->override_option('fields', array(
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
			  $view->display_handler->override_option('row_plugin', 'fields');
			  $view->display_handler->override_option('style_plugin', 'list');
			  $view->display_handler->override_option('style_options', array(
			    'grouping' => '',
			    'type' => 'ul',
			  ));
			 		  
			  
	    //Note: Some actions like "$view->validate()" (which the ajax callback uses) will cache (in code) the
      //      avalible fields this clears that since we change it here
      if(isset($view->display[$display_id]->handler->handlers['field'])){
        unset($view->display[$display_id]->handler->handlers['field']);
      }
      
	  	break;
	  	case 'teasers':
	  	default:
	  		//Do nothing, default
	  }
  }
  
  /**
   * Return the cache parameters for this box
   */
  public function cache_info(){

    return array(); //caching disabled so ajax pager gets init'ed
  }

  
}