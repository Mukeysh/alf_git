<?php

/**
 * Settings form for configureing your scholar front page
 * @param vsite $space
 */
function scholar_front_settings($form_state) {

  if (!($new_title = variable_get('scholar_front_site_title', ''))) {
    $vsite = vsite_get_vsite();
    $new_title = $vsite->group->title;
  }

  $form['site_title'] = array(
    '#type' => 'fieldset',
    'scholar_front_site_title' => array(
      '#type' => 'textfield',
      '#title' => t('Site Title'),
      '#description' => t('This title will appear in the title bar of your browser.'),
      '#default_value' => $new_title,
    ),
  );

  return system_settings_form($form);
}


/**
 * Add the admin links and message box to the top of the vsite front page
 */
function _scholar_front_admin_frontpage(){
	  $vsite = vsite_get_vsite();
	  $result = '';

	  $a_messages_confirmed_settings = variable_get('vsite_setting_messages_confirmed',array());
    if($vsite && $vsite->access_admin()  && (!is_array($a_messages_confirmed_settings)  || !$a_messages_confirmed_settings['welcome_message'])){

      $s_hide_link = l("Forever","cp/confirm_message/welcome_message",array('attributes'=>array('class'=>'hide'),'query' => array('source'=>$_GET['q']) ));
      $s_close_link = l("For now","",array('attributes'=>array('class'=>'close','onClick'=>'$("div#message_welcome_message").remove(); return false;')));

      $s_features = l("Enable or disable features for your site",'cp/build/features');
      $s_members = l("Manage who may use your site",'cp/users');
      $s_theme = l("Change the look of your site",'cp/appearance');
      $s_layout = l("Move elements in your page layout",'cp/build/layout');
      $s_docs = l("View documentation","help/vsitehelp/OpenScholar-Documentation");

      //Created in the last 26 hours?
      $s_welcome_message = (time() - $vsite->group->created < 93600)?"Welcome to your new website!":"";
      $s_short_message = (time() - $vsite->group->created < 93600)?"Need help <span>getting started?</span>":"Need quick access to <span>common settings?</span>";
      drupal_add_js(drupal_get_path('module', 'vsite').'/theme/vsite.js', 'module');

      //Add Content
      $s_content = l("Add/manage content",'cp/content');
      $s_bio = ($vsite->access_feature($op = 'view', 'scholar_biocv') && !content_profile_load('bio', $vsite->group->uid))?"<li>".l("Add your bio",'node/add/bio',array('query' => array('destination'=>'biocv')))."</li>":"";
      $s_cv = ($vsite->access_feature($op = 'view', 'scholar_biocv')  && !content_profile_load('cv', $vsite->group->uid))?"<li>".l("Add your cv",'node/add/cv',array('query' => array('destination'=>'biocv')))."</li>":"";

      $result = <<<MESSAGE
      <div id="message_welcome_message">
        <div class="toggle">$s_short_message</div>
        <div id="welcome_wrapper" class="slider">
          <h3>{$s_welcome_message}</h3>
          <p>Below are a few additional resources to help you. You may access the control panel at any time by clicking the link in the top right corner of the screen.</p>
          <ul id="resource-list">
            <li>{$s_features}</li>
            <li>{$s_content}</li>
            <li>{$s_members}</li>
            <li>{$s_theme}</li>
            <li>{$s_layout}</li>
            {$s_bio}
            {$s_cv}
            <li>{$s_docs}</li>
          </ul>
          <div class="vsite-admin">
            <div class="toggle"><span>Hide this message</span></div>
            <div class="slider">
               <ul class="links">
                <li class="first">{$s_hide_link}</li>
                <li>{$s_close_link}</li>
               </ul>
            </div>
          </div>
        </div> <!-- SLIDER -->
      </div>
      {$result}
MESSAGE;
    }

    return $result;
}


/**
 * Redirect to the home page
 */
function scholar_front_redirect_home(){
	if(!drupal_is_front_page()){
	  drupal_goto("<front>");
	}
}

/**
 * Default front page
 */
function scholar_front_home(){
	
	return "";
}