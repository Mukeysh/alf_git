<?php

/**
 * @file
 * The box class for "Twitter feed" type widgets.
 */

class os_boxes_twitterfeed extends os_boxes_default {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults(){
    $options = parent::options_defaults();
    
    // the default value for the form
    $options['twitter_username'] = '';
    $options['num_items'] = 5;
    $options['followme_link'] = 0;
    $options['followme_text'] = t("Follow me on twitter");
    $options['followme_url'] = "";
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    
    $form['twitter_username'] = array(
      '#type' => 'textfield', 
      '#title' => t('Twitter key'), 
      '#required' => TRUE, 
      '#default_value' => $this->options['twitter_username'], 
      '#description' => "Can be a twitter username (prepended with @), a list (@username/listname), a hashtag (prepended with #) or a search keyword (no prefix)." 
    );
    
    $form['num_items'] = array(
      '#type' => 'textfield', 
      '#title' => t('Number of tweets'), 
      '#default_value' => $this->options['num_items'], 
      '#description' => t('Number of tweets to display') 
    );
    
    $form['followme_link'] = array(
      '#type' => 'checkbox', 
      '#title' => t('Include a "follow me link"'), 
      '#default_value' => $this->options['followme_link'], 
      '#description' => t('This will add a more link to the bottom of this widget, which will link to your twitter page'), 
      '#tree' => TRUE 
    );
    
    ctools_include('dependent');
    ctools_add_js('dependent');
    
    $form['followme_text'] = array(
      '#type' => 'textfield', 
      '#title' => t('Text'), 
      '#default_value' => $this->options['followme_text'], 
      '#description' => t("The title / label of the link."), 
      '#process' => array(
        'ctools_dependent_process' 
      ), 
      '#dependency' => array(
        'edit-followme-link' => array(
          1 
        ) 
      ) 
    );
    
    $form['followme_url'] = array(
      '#type' => 'textfield', 
      '#title' => t('Link'), 
      '#default_value' => $this->options['followme_url'], 
      '#description' => t("The url/path for this link."), 
      '#process' => array(
        'ctools_dependent_process' 
      ), 
      '#dependency' => array(
        'edit-followme-link' => array(
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
  public function render(){
    $block = parent::render();
    
    $twitkey = $this->options['twitter_username'];
    $num_items = $this->options['num_items'];
    $followme_link = $this->options['followme_link'];
    
    $output = twitter_pull_render($twitkey, $title = NULL, $num_items);
    
    // include a followme link
    if ($this->options['followme_link']) {
      $output .= '<div class="twitter-followme">' . l($this->options['followme_text'], $this->options['followme_url']) . '</div>';
    }
    
    $block['content'] = $output;
    return $block;
  }

  /**
   * Return the cache parameters for this box
   */
  public function cache_info(){
    
    // Do not cache twitter_pull has is't own caching so the impact is low and running through the theme function will change the last updated times
    // Caching should be added back if we use other services here
    return array();
    
  //  	//Clear any time the site is saved
  //    $cache_key = array(
  //      'os_og' => array('current' => 'current'),
  //    );
  //
  //    //Only cache twitter feeds for 15 minutes (max_lifespan)
  //    return array('type' => BLOCK_CACHE_CONTENT_CACHE, 'keys' => $cache_key, 'max_lifespan' => 900);
  }

}