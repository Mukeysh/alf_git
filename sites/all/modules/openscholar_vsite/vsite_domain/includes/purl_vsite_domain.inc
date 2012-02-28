<?php
/**
 * Create the processor that will override the purl_domain
 */

if (!class_exists('purl_vsite_domain')) {
  
  /**
   *  Full domain handling for scholar, will also remove purl prefix's from alias's
   */
  class purl_vsite_domain extends purl_domain implements purl_processor {
  
    public $modifier_regex = '!^[a-z0-9_\.-]+$!';
    
    /**
     * Simply match our 'q' (aka domain) against an allowed value.
     *
     * If none is found and $q starts with www. then try without
     */
    public function parse($valid_values, $q) {
      $path_elements = parent::parse($valid_values, $q);
      
      if (!count($path_elements) && strpos($q, 'www.') === 0) {
        //Remove www
        $q = substr($q, 4);
        $path_elements = parent::parse($valid_values, $q);
      }
      
      return $path_elements;
    }
    
    function detect($q) {
    	$plugin = ctools_get_plugins('spaces', 'plugins','vsite');
      if($plugin) $class = ctools_plugin_get_class($plugin, 'handler');
      
      if(isset($class) && call_user_func(array($class,'is_excluded_path'),$q)){
        global $base_url;
        return $base_url;  //Match based on global base URL
      }else{
        $domain = parent::detect($q);
        
        //Remove the port if it is 80 (some browsers don't do this by default)
        if(substr($domain,-3) == ":80") $domain = substr($domain,0,(strlen($domain) - 3));
        
        return $domain;
      }
    }
  
    public function method() {
      return PURL_VSITE_DOMAIN;
    }
  
    public function description() {
      return t('Enter a domain registered for this scholar site, such as "www.example.edu".  Do not include http://');
    }
  
    private function remove_scholar_purl($path) {
      if (!($vsite = vsite_get_vsite()) || !strlen($vsite->group->purl)) return $path;
      $args = explode('/', $path);
  
      // Remove the value from the front of the query string
      if (current($args) === (string) $vsite->group->purl) {
        array_shift($args);
      }
      return implode('/', $args);
    }
    
    /**
     * Either force the url, or set it back to the base.
     */
    public function rewrite(&$path, &$options, $element) {
    	$plugin = ctools_get_plugins('spaces', 'plugins','vsite');
      if($plugin) $class = ctools_plugin_get_class($plugin, 'handler');
      if(isset($class) && call_user_func(array($class,'is_excluded_path'),$path)) return; //Do not alter if this is a link to a excluded path
      
      $options['absolute'] = TRUE;
      if (!_purl_skip($element, $options)) {
        $path = $this->remove_scholar_purl($path);
        $options['base_url'] = "http://{$element->value}";
      }
      else {
        global $base_url;
        $options['base_url'] = variable_get('purl_base_domain', $base_url);
      }
    }
    
    /**
     * If a purl_path/domain has been set we should rewrite the current url
     * so that aliased paths will be picked up
     */
    public function adjust(&$value, $item, &$q) {
      if ( (!($vsite = vsite_get_vsite()) && !($vsite = vsite_get_vsite($item->id))) || !strlen($vsite->group->purl)) return;
      
      if (trim($_GET['q'], '/') == trim($_REQUEST['q'], '/')) {
        vsite_domain_processed_purls($vsite->group->purl);
        
        $args = explode('/', trim($_GET['q'], '/'));
  
        // Add the value to the front of the query string
        if (current($args) !== (string) $vsite->group->purl) array_unshift($args, $vsite->group->purl);
        
        $qstring = implode('/', $args); //String with purl added
        $qstring_alias = drupal_lookup_path('source', $qstring); //Alias of that url
        
        if ($qstring_alias && $qstring != $qstring_alias) $q = $qstring; //Modify $q since purl/path/path has an alias
      }//It has not been aliased yet
    }
  }
}
