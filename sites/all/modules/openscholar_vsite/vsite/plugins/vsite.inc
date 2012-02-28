<?php

/**
 * Vsite space object
 *
 * @author rbrandon
 * @todo verify that the menu_access workflow is fine (code at bottom of page)
 */
class vsite extends space_og {

  //Store the current provider in our multi-provider system
  public $purl_provider = false;

  function feature_options() {
    return array(0 => t('Disabled'), 1 => t('Public'), 2 => 'Private');
  }

  /**
   * Return the absolute URL to this vsite
   */
  public function get_absolute_url($path = ""){
  	if(!$this->purl_provider){
  		self::verify_purl();
  	}

    return url($path, array( 'purl' => array( 'provider' => $this->purl_provider,'id' => $this->id), 'absolute' => true));

  }

  /**
   * Override of activate().
   */
  function activate(){
  	
    if (!$this->verify_purl()) {
      $this->purge_request_destination();

      if($this->purl_provider){
      	//Set the provider to use for redirection
      	$options = array('query' => drupal_query_string_encode($_GET, array('q')), 'purl' => array('provider' => $this->purl_provider, 'id' => $this->id));
      	$path = $_GET['q'];

      	$aliased = url($path);
      	if($path != $aliased && isset($_REQUEST['q']) && $path == $_REQUEST['q']){
      		// If the path we are going to has an alias, and the current page we are on does not use that
      		// that alias value.  Then lets skip purl_goto since unaliased paths with a path prefix make it think it's
      		// in a redirect loop.  ex( GET[q] will hold node/123 for both the aliases and non-aliased paths)
      		$path = $this->get_absolute_url($path);
      		drupal_goto($path);
      	}

        purl_goto($path, $options);
      }//Just like the check in spaces_purl_provider but with dynamic provider
    }

    if (parent::activate()) {
      return TRUE;
    }

    return FALSE;
  }

  /**
    * Implementation of space->router().
    */
  public function router($op, $object = NULL) {
  	//Fixes bug where when menu's are loaded any menu that points to a node causes redirection, leaving this not so eligant code in place till the following is resolved
  	// http://drupal.org/node/936234
  	if(arg(0) == 'admin') return;

  	global $user;
    switch ($op) {
    	case 'node':
    		//Route home if we are viewing the group node
        if (og_is_group_type($object->type)) {
          //We are loading a group node, instead redirect to this groups home page
          if (isset($object->nid) && (!$object->active || ($this->active && $this->id != $object->nid)) && $space = spaces_load('og', $object->nid)) {
          	$space->verify_purl(); //Setup the correct purl provider

          	$current_url = url($_GET['q'], array('absolute' => TRUE, 'query' => drupal_query_string_encode($_GET, array('q'))));
          	if($current_url != rtrim($this->get_absolute_url(),"/")){
              purl_goto("<front>", array( 'purl' => array( 'provider' => $space->purl_provider,'id' => $space->id)));
          	}
            return;
          }
        }
    	break;
    	case 'init':
	    	$private = $this->controllers->variable->get('vsite_private');
	      if ($this->active && $private && !og_is_group_member($this->id)) {
	        purl_goto("private_site", array('purl' => array( 'provider' => $this->purl_provider, 'id' => $this->id)));
	      }
      break;
    }
    parent::router($op, $object);
  }

	/**
	 * Returns the vocabularies associated with a vsite.
	 * If a content type is provided, return vocabs associated
	 * with that content type only.
	 * @param $node_type
	 * @return array
	 */
	public function get_vocabs($node_type = NULL){

	  if ($this->group) {

	    if (isset($this->group->og_vocabularies)) {
	      if (!$node_type) {
	        return $this->group->og_vocabularies;
	      }

	      $result = array();

	      foreach ( $this->group->og_vocabularies as $v ) {
	        if (in_array($node_type, array_keys($v->nodes))) {
	          $result[$v->vid] = $v;
	        }
	      }

	      return $result;
	    }
	  }
	}

  /**
   * Override of access_feature().
   */
  function access_feature($op = 'view', $feature, $account = NULL) {

    if($feature == 'vsite' && $op == 'view' && user_access('access content')) return true;

    $access = parent::access_feature($op, $feature, $account);

    //Check 'Private' Settings
    $features = variable_get('spaces_features', array());
    if($access && $features[$feature] > 1){
    	//Handle privacy levels that are not simple Public/Disabled
    	switch ($features[$feature]){
    		//Private
    		case 2:
    			if(!og_is_group_member($this->id, TRUE, $account->uid)){
    				$access = false;
    			}//Admin or group member?
    		break;
    		default:
	    		//Unknown Privacy Level
	    		$access = false;
    		break;
    	}
    }

    return $access;
  }

  /**
   * If this space is loaded outside a active context (ie) externally from the home page
   * then determine which purl_provider would be best
   *
   * domain if they have that set otherwise path
   */
  protected function verify_purl() {

    $domain_method = variable_get('purl_method_vsite_domain',false);
    $elements = purl_active()->get($domain_method);
    foreach ($elements as $element) {
      if ($element->provider == "vsite_domain" && $element->id == $this->id) {
        $this->purl_provider = "vsite_domain";
        return TRUE;
      }
    }

    $method = variable_get("purl_method_spaces_{$this->type}", 'path');
    $elements = purl_active()->get($method);
    foreach ($elements as $element) {
      if ($element->provider == "spaces_{$this->type}" && $element->id == $this->id) {
        $this->purl_provider = "spaces_{$this->type}";
        return TRUE;
      }
    }

    //No provider is active, lookup from id so redirection works
    //Return false if we have reached here
    $valid_providers = array();
    $result = db_query("SELECT provider FROM {purl} WHERE id = %d ", $this->id);
    while ($provider = db_result($result)) $valid_providers[] = $provider;

    if(in_array('vsite_domain',$valid_providers)){
    	//This site has a domain provider
    	$this->purl_provider = 'vsite_domain';
    }elseif (in_array("spaces_{$this->type}",$valid_providers)){
    	//This site has a default provider
    	$this->purl_provider = "spaces_{$this->type}";
    }//Set from db

    return FALSE;
  }

  /**
   * Save all settings to the DB
   */
  public function save_all() {
    foreach ($this->controllers as $c) {
      $settings = $c->get('', 'space');
      foreach ($settings as $id => $value) {
        $c->set($id, $value);
      }
    }
  }

  /**
   * Override of excluded_paths().
   * The parent exlcudes 'features' and 'features/*'
   * We want them back
   */
  protected function excluded_paths(){
    $excluded = parent::excluded_paths();

    unset($excluded[array_search('features', $excluded)]);
    unset($excluded[array_search('features/*', $excluded)]);

    $more = array(
      'user',
      'user/*',
      'users/*',
      'private_site',
      'help/*',
      'site/register',
      'welcome',
    );

    $excluded = array_merge($excluded, $more);
    return $excluded;
  }

  /**
   * Check to see if a path is 'excluded'
   * @param string $q
   */
  public static function is_excluded_path($q){
    $paths = implode("\n", self::excluded_paths());

    return drupal_match_path($q, $paths)?true:false;
  }
  
  /**
   * Override access_admin().
   */
  function access_admin($account = NULL) {
    global $user;
    $account = isset($account) ? $account : $user;
    
    // Adventurous modules can cause us to arrive here before og_init() has fired.
    // See http://drupal.org/node/285696
    if ($account->uid && !isset($account->og_groups)) {
      $account = user_load(array('uid' => $account->uid));
    }

    return parent::access_admin($account);
  }
}
