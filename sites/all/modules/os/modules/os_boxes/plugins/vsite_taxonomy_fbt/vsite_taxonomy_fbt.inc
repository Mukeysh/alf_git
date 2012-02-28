<?php

/**
 * @author rbran100
 * @category boxes
 *
 * The class for filtering content by taxonomy
 */

class vsite_taxonomy_fbt extends os_boxes_default {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $vsite = vsite_get_vsite();
    //Default - All vocabs if in vsite, None if outside
    $vocabs = $vsite ? $vsite->get_vocabs() : array();

    $options['vocabulary'] = is_array($vocabs)?array_keys($vocabs):array();
    $options['number_of_items'] = false;
    $options['behavior'] = 'contextual';
    $options['show_empty_terms'] = 0;
    $options['show_term_descriptions'] = 0;
    $options['show_vocabulary_name'] = 1;
    
    //Tree
    $options['show_tree'] = 1;
    $options['tree_max_depth'] = 0;

    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){

  	ctools_include('dependent');
  	ctools_add_js('dependent');
  	
  	$vsite = vsite_get_vsite();
  	$vocabs = $vsite ? $vsite->get_vocabs() : taxonomy_get_vocabularies();

  	$a_options = array();
  	foreach ($vocabs as $vid => $v) $a_options[$vid] = $v->name;

  	if(!$this->options['vocabulary'] || !count($this->options['vocabulary'])){
  		$defaults = $this->options_defaults();
  		$this->options['vocabulary'] = $defaults['vocabulary'];
  	}
  	
    $form['vocabulary'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Vocabularies'),
      '#options' => $a_options,
      '#required' => TRUE,
      '#default_value' => $this->options['vocabulary'],
      '#description' => t('Which vocabularies would you like to use to filter posts.'),
    );

    $form['number_of_items'] = array(
      '#type' => 'select',
      '#title' => t('Number of terms to display (per vocabulary)'),
      '#options' => array(
                      0 => "All Terms",
                      3 => "3",
                      5 => "5",
                      10 => "10",
                      15 => "15",
                      20 => "20",
                      25 => "25",
                    ),
      '#default_value' => $this->options['number_of_items']
    );

    $form['show_vocabulary_name'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show vocabulary name'),
      '#default_value' => $this->options['show_vocabulary_name'],
      '#description' => t('Should the vocabulary name be shown above the list of terms.'),
    );

    $form['show_empty_terms'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show empty terms'),
      '#default_value' => $this->options['show_empty_terms'],
      '#description' => t('Should terms be shown that do not have any posts tagged to them.'),
    );

    $form['show_term_descriptions'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show term descriptions'),
      '#default_value' => $this->options['show_term_descriptions'],
      '#description' => t('Show the description of the term if avalible under each term.'),
    );
    
    $form['behavior'] = array(
      '#type' => 'select',
      '#title' => t('Behavior'),
      '#options' => array(
                      'contextual' => "Filter the posts on the current page by a term",
                      'global' => "Show to all posts tagged with the term",
                    ),
      '#default_value' => $this->options['behavior'],
      '#description' => t('What should happen when you click a term, should it filter the current results if applicable or always link to all posts tagged with the term.'),
    );
    
    $form['show_tree'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show as a tree'),
      '#default_value' => $this->options['show_tree'],
      '#description' => t('Show child terms underneath parent terms.'),
    );
    
    $form['tree_max_depth'] = array(
      '#type' => 'select',
      '#title' => t('Levels of the tree to display'),
      '#options' => array(
                      0 => "Show all childeren",
                      1 => "Show only first level",
                      2 => "2nd Level",
                      3 => "3rd Level",
                      4 => "4th Level",
                    ),
      '#default_value' => $this->options['tree_max_depth'],
      '#process' => array('ctools_dependent_process'),
      '#dependency' => array(
        'edit-show-tree' => array(
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

	  $vsite = vsite_get_vsite();
	  vsite_include('vsiteapi');


	  $active_feature = false;
	  $active_nodes = array();
	  if($this->options['behavior'] == 'contextual'){
	  	//The current active feature
	  	$active_feature = vsite_active_feature();
	  	if($active_feature && !in_array($active_feature,array('front','search','none'))){
		  	//The active features context
		  	$context = context_load('openscholar-feature-'.$active_feature);

			  if(isset($context->conditions['node']['values'])){
		      $active_nodes = $context->conditions['node']['values'];
		    }
	  	}else{
	  		$active_feature = false;
	  	}
	  }//Get terms based on context

	  if ($vsite) {

	  	// get all vocabs or based on context, then filter by box settings
      $vcs = array();
	    if($active_feature){
        foreach ($active_nodes as $s_type) $vcs += $vsite->get_vocabs($s_type);
      }else{
        $vcs = $vsite->get_vocabs($s_type);
      }
      
		  if(!$this->options['vocabulary'] || !count($this->options['vocabulary'])){
	      $defaults = $this->options_defaults();
	      $this->options['vocabulary'] = $defaults['vocabulary'];
	    }//If they have not selected a vocab use all vocabs

      //Filter by box settings
      $vcs = array_intersect_key($vcs,array_flip($this->options['vocabulary']));

      //Set depth
      if($this->options['show_tree']){
      	$max_depth = $this->options['tree_max_depth'];
      	if(!$max_depth) $max_depth = NULL;
      }else{
      	$max_depth = 1;
      }
      

	    $terms_html = "";
	    foreach ($vcs as $n_vid => $taxonomy){

	      $terms = taxonomy_get_tree($taxonomy->vid,0,-1,$max_depth);

	      if($this->options['number_of_items']){
	      	$terms = array_slice($terms,0,$this->options['number_of_items'],true);
	      }//Just show n terms

	      $items = theme('vsite_taxonomy_term_list',0, $terms,'vsite_taxonomy_term', $this->options['show_term_descriptions'], $this->options['show_empty_terms'], $b_show_admin_links = false, $s_term_filter = ($active_feature?"scholar_".$active_feature:false), true);

	      if (count($items)) {
	        $terms_html .= strlen($terms_html)?'</div></div><div class="block block-views"><div class="content">':""; //sudo blocks

	        if($this->options['show_vocabulary_name']){
	        	$terms_html .= "<h3 class=\"title\">".ucfirst($taxonomy->name)."</h3>";
	        }//Show the vocab name?

	        $terms_html .= theme('item_list', $items, NULL, 'ul');
	      }

	    }
	    if(strlen($terms_html)) $block['content'] = $terms_html;
	  }

    return $block;
  }
  
  /**
   * Return the cache parameters for this box
   */
  public function cache_info(){
  	
    //Clear any time the site is saved since taxonomy counts and terms can change in many ways
    $cache_key = array(
      'os_og' => array('current' => 'current'),
    );
  
    $cache_params = array('type' => BLOCK_CACHE_CONTENT_CACHE, 'keys' => $cache_key);
    
    //If the vocab changes based on context, cache per context
    if($this->options['behavior'] == 'contextual'){
    	$cache_params['granularity'] = array('context');
    }
    
    return $cache_params;
  }

}