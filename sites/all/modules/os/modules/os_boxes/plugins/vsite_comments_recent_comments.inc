<?php

/**
 * @author rbran100
 * @category boxes
 *
 * The class for showing comments for a given content-type
 */

class vsite_comments_recent_comments extends os_boxes_default {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['comment_type'] = 'drupal';
    $options['node_type'] = 0;
    $options['number_of_items'] = 6;
    
    $options['disqus_avatars'] = false;
    $options['disqus_avatar_size'] = 32;
    
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){

  	ctools_include('dependent');
    ctools_add_js('dependent');
    
    //Get the avalible nodes
    // os/vsite integration - lists correct content types
    if (module_exists('vsite') && vsite_get_vsite()) {
      vsite_include('vsiteapi');
      //Get public and private types
      $node_options = vsite_content_types(array(1,2));
      drupal_alter('vsite_content_types', $node_options);
    }
    
    if (!isset($node_options)) {
      $node_options = node_get_types('names');
    }
    
    //Sort by node name
    asort($node_options);
    $a_used_ctypes = array();
    foreach ( $node_options as $type => $name ) {
    	$ctype = $this->node_comment_setting($type);
    	if ($ctype == 'drupal'){
	      //Make name pretty
    		$node_options[$type] = t('!type posts', array(
	        '!type' => ucfirst($name),
	      ));
    	}else{
    		//This type does not use drupal comments so it isn't selectable
    		unset($node_options[$type]);
    	}
    	
    	if($ctype){
    		$a_used_ctypes[$ctype] = $ctype;
    	}
    }
    
    
    $comment_types = array();
    if(in_array('drupal',$a_used_ctypes)){
      $comment_types['drupal'] = t('Standard Drupal Comments');
    }
    
    if(in_array('disqus',$a_used_ctypes) && module_exists('disqus')){
    	$comment_types['disqus'] = "Disqus Comments";
    }
    
    if(!count($comment_types)){
    	$form['error'] = array(
    	  '#type' => 'markup',
        '#value' => "<p>".t('Sorry, No post types have been configured to use comments.')."</p>",
    	);
    	
    	return $form;
    }
    
    if(count($comment_types) > 1){
	    $form['comment_type'] = array(
	      '#type' => 'select',
	      '#title' => t('Type of comments to display'),
	      '#options' => $comment_types,
	      '#required' => TRUE,
	      '#default_value' => $this->options['comment_type'],
	    );
    }else{
    	//Only one type avalible set accordingly
    	$form['comment_type'] = array(
        '#type' => 'value',
        '#value' => current(array_keys($comment_types)),
      );
    }
  	
    if(in_array('drupal',$a_used_ctypes)){
	    $form['node_type'] = array(
	      '#type' => 'select',
	      '#title' => t('Comments From'),
	      '#options' => array_merge(array(
	        0 => "All Post Types",
	      ),$node_options),
	      '#required' => false,
	      '#default_value' => $this->options['node_type'],
	      '#description' =>  "Choose the content type that you would like to display comments from.",
	      '#process' => array(
	        'ctools_dependent_process'
	      ),
	      '#dependency' => array(
	        'edit-comment-type' => array(
	          'drupal'
	        )
	      )
	    );
    }
    
    
    $form['number_of_items'] = array(
      '#type' => 'select',
      '#title' => t('Number of comments to display'),
      '#options' => array(
                      1 => "1",
                      2 => "2",
                      3 => "3",
                      4 => "4",
                      5 => "5",
                      6 => "6",
                      7 => "7",
                      10 => "10",
                      15 => "15",
                      20 => "20",
                      25 => "25",
                    ),
      '#default_value' => $this->options['number_of_items']
    );
    
    if(in_array('disqus',$a_used_ctypes)){
	    $form['disqus_avatars'] = array(
	      '#type' => 'checkbox',
	      '#title' => t('Display Disqus Avatars'),
	      '#description' => t('This will add an avatar image if avalible next to each comment.'),
	      '#default_value' => $this->options['disqus_avatars'],
	      '#tree' => TRUE,
	      '#process' => array(
	        'ctools_dependent_process'
	      ),
	      '#dependency' => array(
	        'edit-comment-type' => array(
	          'disqus'
	        )
	      )
	    );
	    
	    $form['disqus_avatar_size'] = array(
	      '#type' => 'select',
	      '#title' => t('Avatar Size'),
	      '#options' => array(
	                      24 => "Small (24 px)",
	                      32 => "Medium (32 px)",
	                      48 => "Large (48 px)",
	                    ),
	      '#default_value' => $this->options['disqus_avatar_size'],
	      '#process' => array(
	        'ctools_dependent_process'
	      ),
	      '#dependency' => array(
	        'edit-disqus-avatars' => array(
	          1
	        )
	      )
	    );
    }

    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    $block = parent::render();
    
    //Is this comment type still enabled?
    $enabled = false;
    if (module_exists('vsite') && vsite_get_vsite()) {
      vsite_include('vsiteapi');
      //Get public and private types
      $node_options = vsite_content_types(array(1,2));
      drupal_alter('vsite_content_types', $node_options);
      foreach ($node_options as $type => $value) {
      	if($this->options['comment_type'] === $this->node_comment_setting($type)){
      		$enabled = true;
      		break;
      	}
      }
    }
    
    if(!$enabled){
    	return $block;
    }
    
    $comments_html = "";
    switch ($this->options['comment_type']){
    	case 'drupal':
    		$view_name = 'vsite_comments_display';
        $display_id = "block_1";
        
		    if ($view = views_get_view($view_name)) {
		      if ($view->access($display_id) && (!$this->options['node_type'] || $this->node_comment_setting($this->options['node_type']) == 'drupal')) {
		        $view->set_display($display_id);
		        
		        //Tie this view to this box (this tells the view to call this box's view alter)
		        $view->dom_id = "boxes-".$this->delta;
		        
		        $output = $view->execute_display();
		        $comments_html = $output['content'];
		      }//Make sure they have access to see this view
		      $view->destroy();
		    }
    	break;
    	case 'disqus':
    		if(!module_exists('disqus') || !($shortname = variable_get('disqus_domain', ''))){
    			break;
    		}
    		$avatar_settings = $this->options['disqus_avatars'] ? '&amp;avatar_size='. $this->options['disqus_avatar_size'] : '&amp;hide_avatars=1';
    		//Disqus embed code
    		$comments_html = <<<EOT
<div id="dsq-recentcomments" class="dsq-widget"><script type="text/javascript" src="http://disqus.com/forums/{$shortname}/recent_comments_widget.js?num_items={$this->options['number_of_items']}{$avatar_settings}"></script></div>
EOT;
    	break;
    	case 'facebook':
    		//Facebook embed code here
    	break;
    }
    
    if(strlen($comments_html)) $block['content'] = $comments_html;

    return $block;
  }
  
  /**
   * Determine if this box is avalible for use
   */
  public function access(){
  	if($this->options['node_type'] && vsite_get_vsite()){
  		vsite_include('vsiteapi');
      $avalible_types = array_keys(vsite_content_types(array(2, 1)));
      
      if(!in_array($this->options['node_type'],$avalible_types)){
      	return false;
      }//Disabled Type
  	}
  	
  	//Check if commenting is enabled
  	return vsite_comments_admin_access($this->options['node_type']);
  }
  
  /**
   * Return the cache parameters for this box
   */
  public function cache_info(){
    
  	$cache_key = false;
  	switch($this->options['comment_type']){
  		case 'drupal':
  			//Adding comments triggers a node clear
		    $cache_key = array(
		      'os_og' => array('current' => 'current'),
		      'node' => array($this->options['node_type'] => $this->options['node_type']),
		      'comment' => array(
		        'changed' => 1,
		      )
		    );
  		break;
  	}
    
  	if(!$cache_key){
  		//Do not cache
  		return array();
  	}
  
    $cache_params = array('type' => BLOCK_CACHE_CONTENT_CACHE, 'keys' => $cache_key);

    return $cache_params;
  }
  
  protected function node_comment_setting($node_type){
  	//Get Feature/node comment settings
    $default_setting = variable_get("comment_{$node_type}",0)?'drupal':0;
    
    return variable_get("vsite_comments_comment_type_{$node_type}", $default_setting);
  }

/**
   * Called from views_pre_view
   *
   * @param view $view
   */
  public function views_alter(&$view, &$display_id, &$args){
    
    if($this->options['node_type']){
	    $filter = array(
	      'operator' => 'in',
	      'group' => '0',
	      'exposed' => FALSE,
	      'expose' => array('operator' => FALSE, 'label' => ''),
	      'id' => 'type',
	      'table' => 'node',
	      'field' => 'type',
	      'relationship' => 'nid',
	      'value' => array($this->options['node_type'] => $this->options['node_type']),
	    );
	    $view->set_item($display_id, 'filter', 'type', $filter);
    }
    
    //Set the number of items
    if(intval($this->options['number_of_items'])){
      $view->display_handler->set_option('items_per_page',intval($this->options['number_of_items']));
      $view->set_items_per_page(intval($this->options['number_of_items']));
    }
    
  }
}