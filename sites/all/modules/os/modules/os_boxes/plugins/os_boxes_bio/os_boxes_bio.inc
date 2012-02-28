<?php

/**
 * @file
 * The class for "CC license" type widgets.
 */

class os_boxes_bio extends os_boxes_node {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){

    //get nid of this vsite's bio
    if (($vsite = vsite_get_vsite()) == FALSE) {
      return array();
    }//We must be in a vsite
    
    $form = parent::options_form();
    
    $form['nid']['#type'] = 'value';
    $form['nid']['#value'] = 0;
    unset($form['nid']['#element_validate']);
    
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
  	
  	if (($vsite = vsite_get_vsite()) == FALSE) {
      return array();
    }//We must be in a vsite
    
    //check if a bio has been set
    if (($bio_node = content_profile_load('bio', $vsite->group->uid, $lang = '')) == TRUE) {
      //we have a bio.  set it here and try again.
      $this->options['nid'] = $bio_node->nid;
      $block = parent::render();
    } else {
      //no bio yet.
	    $block['content'] = $this->render_no_bio();
    }
    

    return $block;
  }
  
  /**
   * Render help text for a user that does not have a bio yet
   */
  protected function render_no_bio(){
    $vsite = vsite_get_vsite();
    if(!$vsite || !$vsite->access_admin()) return "";
    $spaces_features = variable_get('spaces_features',array());

    $bio_link = $spaces_features["scholar_biocv"]?l("Setup your bio now","node/add/bio")." or":"The bio feature is disabled";
    $front_settings = l("change what displays","cp/build/layout",array("query" => array("page_type" => "front")));
    $result = <<<MESSAGE
        <div id="welcome_front_wrapper">
          <p>Your sites front page is set to display your bio by default.  {$bio_link} {$front_settings} for the front of your site.</p>
        </div>
MESSAGE;

    return $result;
  }

  
  /**
   * Return the cache parameters for this box
   */
  public function cache_info(){
    
  	//Clear when bio nodes are saved
    $cache_key = array(
      'os_og' => array('current' => 'current'),
      'node' => array('bio' => 'bio'),
    );
    
    return array('type' => BLOCK_CACHE_CONTENT_CACHE, 'keys' => $cache_key);
  }

}