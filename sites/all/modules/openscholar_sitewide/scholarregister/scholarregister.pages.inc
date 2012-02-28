<?php

/**
 * Construct the registration form
 */
function scholarregister_signup_form(){
  global $user;
  $form = array();

  drupal_add_css(drupal_get_path('module', 'scholarregister') . '/theme/scholarregister.css');

  // clear any drupal_messages. Ajax takes care of them
  drupal_get_messages();
  ctools_include('ajax');
  ctools_add_js('ajax-responder');
  $form['#prefix'] = '<div id = "user_register">';
  $form['#suffix'] = '</div>';

  //Create sites on behalf of others
  $b_create_sites = user_access("create openscholar site on behalf of others");
  //Create site(s) for yourself
  $b_create_own_sites = user_access("create own openscholar site");

  if($_REQUEST['register_for']) $site_owner = user_load(intval($_REQUEST['register_for']));

  if(!$site_owner) $site_owner = $user;
  $existing_sites = vsite_get_vsite_by_owner($site_owner->uid);

  //this is a current site owner creating another site for himself, use existing account information
  if( (!$b_create_sites || ($b_create_sites && $_REQUEST['register_for']) || ($b_create_own_sites && !$b_create_sites)) && ($b_create_sites || $existing_sites) && count($existing_sites) < variable_get('openscholar_vsites_per_user', 1)){
    $form['create_multiple_sites']['#type'] = 'value';
    $form['create_multiple_sites']['#value'] = 1;

    _scholarregister_add_form_items($form,$site_owner);
  }
  //non site owner trying to create a site, use the existing user account information when creating the new site
   elseif(isset($user->name) && isset($user->mail) && !vsite_get_vsite_by_owner($user->uid) && (!$b_create_sites && $b_create_own_sites)){
    $form['create_site_is_authenticated']['#type'] = 'value';
    $form['create_site_is_authenticated']['#value'] = 1;

    //Add text for 'name' and 'mail' instead of textfields, when authenticated user creating a site for self
    _scholarregister_add_form_items($form);
  }

  // otherwise show the normal form
  else{
  	//$b_create_sites || $b_create_own_sites

	  // username
	  $form['name'] = array(
	      '#type' => 'textfield',
	      '#size' => 35,
	      '#title' => ($b_create_sites) ? t('Choose Site Owner\'s Username') : t('Desired user name'),
	      '#required' => TRUE,
	      '#description' => t('Spaces are allowed; punctuation is not allowed except for periods, hyphens, and underscores.'),
	      '#prefix' => '<div id="name-field">',
	      '#suffix' => '<div id="name-suffix"></div></div>',
	  );
	  ctools_ajax_associate_url_to_element($form, $form['name'], url('scholarregister/name_js'), 'ctools-use-ajax-onchange');

	  // last name
	  $form['mail'] = array(
	      '#type' => 'textfield',
	      '#size' => 35,
	      '#title' => ($b_create_sites) ? t('Site Owner\'s email address') :  t('Your email address'),
	      '#required' => TRUE,
	      '#description' => t('A valid e-mail address is required. All e-mails from OpenScholar will be sent to this address.'),
	      '#prefix' => '<div id="mail-field">',
	      '#suffix' => '<div id="mail-suffix"></div></div>'
	  );
	  ctools_ajax_associate_url_to_element($form, $form['mail'], url('scholarregister/mail_js'), 'ctools-use-ajax-onchange');

	   //if user is user with special access then load any additional fields (password, etc.)
	  if ($b_create_sites){

	    drupal_add_css(drupal_get_path('module', 'scholarregister') .'/scholarregister.css', 'module', 'all', FALSE);

	    //add password field
	    _scholarregister_password_field($form);

	    //add send mail field
	    _scholarregister_send_mail_field($form);
	  }else{
      $form['send_mail'] = array(
        '#type' => 'value',
        '#value' => 1,
      );
    }

  } //else clause ends here

  // domain field
  global $base_url;
  $form['domain'] = array(
      '#type' => 'textfield',
      '#title' => ($b_create_sites) ?  t('Select a Domain Name') :  t('Your URL'),
      '#required' => TRUE,
      '#field_prefix' => $base_url . '/',
      '#size' => 35,
      '#weight' => 20,
      '#default_value' => $form_values['name'],
      '#description' => t('Minimum of 3 characters. Punctuation is not allowed except for hyphens and underscores. <br />Example: a choice of \'jdoe\' would result in the URL: %site.', array(
          '%site' => $base_url . '/jdoe'
      )),
      '#prefix' => '<div id="domain-field">',
      '#suffix' => '<div id="domain-suffix"></div></div>',
  );
  ctools_ajax_associate_url_to_element($form, $form['domain'], url('scholarregister/domain_js'), 'ctools-use-ajax-onchange');

  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => ($b_create_sites) ?  t('Create a new site') :  t('Create your site'),
      '#weight' => 40,
      '#attributes' => array('class' => 'ctools-use-ajax' ),
      '#suffix' => '<div id="submit-suffix"></div>'
      );

  return $form;
}

/**
 * validation callback for the registration form
 */
function scholarregister_signup_form_validate($form, &$form_state){
  // get all the errors in the form (default drupal validation (required fields etc)
  $msgs = form_get_errors();

  if (count($msgs)) {
    $commands = array();
    foreach ( $msgs as $field_name => $m ) {
      $commands[] = ctools_ajax_command_html("#$field_name-suffix", $m);
      $commands[] = ctools_ajax_command_attr("#$field_name-suffix", 'class', 'error');
      $commands[] = _scholarregister_vsite_error();
    }
    ctools_ajax_render($commands);
  }

  //since we introduced multiple site capability, we need to check which fields
  //will be present in the form, then call the appropriate validation function
  $fields = array('name', 'mail', 'domain');
  foreach ($fields as $field){
    if ($form_state['values'][$field]){
      if(call_user_func('scholarregister_validate_' . $field, $form_state['values'][$field] )){
      	  $commands[] = _scholarregister_vsite_error();
      }
    }
  }
if (!empty($commands)) ctools_ajax_render($commands);
}

/**
 * the submit handler for the registration form
 */
function scholarregister_signup_form_submit($form, &$form_state) {
    //capture domain field
    $domain = $form_state ['values'] ['domain'];
    os_include('os.crud');
    //This if/else clause determines which user account to give owership when creating a new site
    if ($form ['create_multiple_sites']['#value']  == 1 ||  $form ['create_site_is_authenticated']['#value'] == 1){
      $user = user_load(array('name' => $form_state ['values'] ['register_for']));
      $name = $user -> name;
      $mail  = $user -> mail;
      ///this is a 'scholar user' user who is creating a site for first time
      if ($form ['create_site_is_authenticated']['#value'] == 1){
          $rid = array_search(variable_get('scholar_manager_role', 'scholar admin'), user_roles());
          os_add_user_to_role($user ->uid, $rid); //need to add 'scholar admin' role
      }
    }

    //user with special access or anonymous user creating a site. uses values in form to create new user and give site ownership
    else{
      $name = $form_state ['values'] ['name'];
      $mail = $form_state ['values'] ['mail'];
      $password =  !empty($form_state ['values'] ['password']) ? $form_state ['values'] ['password'] : user_password();
      $roles = variable_get('scholar_manager_role', 'scholar admin');

      //1. Create the user account
      $user = os_add_user($name, $password, $mail, $roles = array($roles), $status = 1);
      if (!$user){ // unlikely
        $commands [] = _scholarregister_vsite_error();
        ctools_ajax_render ( $commands );
      }
    }

  //add $user object to $form_state  so it can be used by subsequent submit functions
  if(is_object($user)){
    $form_state['new_user'] = $user;
  }

  // 2. Create the site
  $preset = variable_get('scholar_default_preset', 'scholar');
  $vsite = scholarregister_vsite_create($name, $domain, $preset);

  if (!$vsite){
    // first delete the user we just created
    // user_delete($user, $user -> uid);
    $commands [] = _scholarregister_vsite_error();
    ctools_ajax_render ( $commands );
  }

  else{
    // site created successfully add the form values for additional submit fuctions
    $form_state['vsite'] = $vsite;
    // 3. send e-mail to the user (unless specified not to by user with special access)
    $send_mail = ($form_state ['values'] ['send_mail'] == 0) ? FALSE : scholarregister_notify_user($vsite, $user);

  // 4. let user know this was all sucessful
    //ctools_add_js ( 'ajax-responder' );
    $commands = array ();
    global $base_url;
    $message = scholarregister_message($form, $domain);
    $commands [] = ctools_ajax_command_replace ( '#submit-suffix', $message );
    $commands[] = ctools_ajax_command_remove('#edit-submit');
  }

  //additional tasks and workflow if user with special access is creating site
  if (in_array('authenticated user', $user -> roles) && user_access("create openscholar site on behalf of others")){
    if($vsite){
      global $user;
      if($user -> uid !== '1'){
        //if user has create permissions and not admin give user admin rights to og/vsite
        og_save_subscription($vsite->id, $user->uid, array('is_active' => 1, 'is_admin' => 1));
      }
    }
  }

    //call any other submit functions here
  foreach($form['#submit'] as $fnc){
    if (__FUNCTION__ !== $fnc){
      call_user_func($fnc, $form, $form_state);
    }
  }
  ctools_ajax_render ( $commands );
}


/**
 * Functions to add form elements
 */
function _scholarregister_add_form_items(&$form, $site_owner = false){
  global $user;
  if(!$site_owner) $site_owner = $user;
   //TODO: alter div id's
  $form['name'] = array(
	  '#type' => 'item',
	  '#title' =>  t('Username'),
	  '#value' => $site_owner -> name,
	  '#prefix' => '<div id="name-item">',
	  '#suffix' => '</div>',
  );
  $form['register_for'] = array(
	  '#type' => 'value',
	  '#value' => $site_owner -> name,
  );
  $form['mail'] = array(
	  '#type' => 'item',
	  '#title' =>  t('Email Address'),
	  '#value' => $site_owner -> mail,
	  '#prefix' => '<div id="mail-item">',
	  '#suffix' => '</div>',
  );
}

function _scholarregister_password_field(&$form){
  //add dynamic password validation
  _user_password_dynamic_validation();

  // password field
  $form['password'] = array(
  '#type' => 'password_confirm',
  '#size' => 35,
  '#required' => TRUE,
  '#description' => ''
  );
}

function _scholarregister_send_mail_field(&$form){
  // send mail checkbox
  $form['send_mail'] = array(
  '#title' => 'Send an email notification to the site owner upon creating the site.',
  '#type' => 'checkbox',
  '#weight' => 30,
  '#default_value' => 1, //default should be  1 or 0 ???
  );
}

/**
 * Create a scholar vsite
 */
function scholarregister_vsite_create($name, $domain, $preset){
  os_include('os.crud');
  return os_create_vsite($name, $domain, $preset);
}

function _scholarregister_vsite_error(){
 return ctools_ajax_command_html('#submit-suffix', 'The web site cannot be created. Please fix the errors and try again.');
}

