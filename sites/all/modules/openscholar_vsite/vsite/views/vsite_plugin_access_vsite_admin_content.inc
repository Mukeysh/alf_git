<?php

/**
 * Provides access control for views by checking against the current space's
 * feature settings. Optionally allows a permission to be checked in addition
 * to the first feature access control check.
 *
 * This access plugin delegates access control first to spaces_feature_access()
 * which will check whether the user can first access content, then the active
 * space type's 'feature_access' method will be called.  If implementing your
 * own space type you have the ability to define your own access control.  See
 * 'space_og' class in Spaces OG module for an example implementation.
 */
class vsite_plugin_access_vsite_admin_content extends views_plugin_access {

  function get_access_callback() {
    return array('spaces_access_admin', array());
  }
  
  function summary_title() {
    return 'Space admin'; 
  }

}
