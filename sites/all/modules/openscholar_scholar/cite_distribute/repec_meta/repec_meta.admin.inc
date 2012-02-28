<?php

/**
* repec_meta_config()
* 
* @return 	Returns the system settings form for repec_meta 'Configuration' page
*/
function repec_meta_config(){
 
  
  $form['repec_meta'] = array( 
      '#type' => 'fieldset', 
      '#title' => t('Enter RePEc Information'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE, 
      ); 
  
  $form['repec_meta']['repec_meta_inst_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Institution Name'),
      '#default_value' => variable_get('repec_meta_inst_name',''),
      '#description' => t('Enter your institution\'s Name'),
      );
      
  
  $form['repec_meta']['repec_meta_archive_code'] = array(
      '#type' => 'textfield',
      '#title' => t('Archive Code'),
      '#required' => TRUE,
      '#default_value' => variable_get('repec_meta_archive_code',''),
      '#description' => t('Enter your institution\'s 3 letter archive code' )
       
  	);
  	
  $form['repec_meta']['repec_meta_provider_institution'] = array(
      '#type' => 'textfield',
      '#title' => t('Provider Institution Code'),
      '#required' => TRUE,
      '#default_value' => variable_get('repec_meta_provider_institution',''),
      '#description' => t('Enter your institution\'s provider code.  e.g. RePEc:edi:adsflkj' )
       
  	);
  $form['repec_meta']['repec_meta_archive_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Archive Root Path'),
      '#required' => TRUE,
      '#default_value' => variable_get('repec_meta_archive_path',''),
      '#description' => t('Enter the absolute path to the root of the RePEc archive. Do not include the RePEc directory.
       <br> For example: /nfs/test/archive' )
       
  	);
 
  $form['repec_meta']['repec_meta_archive_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Archive URL'),
      '#required' => TRUE,
      '#default_value' => variable_get('repec_meta_archive_url',''),
      '#description' => t("Enter your institution's archive base URL. 
      Do not include any directories in the URL. <br> For example: http://test.repec.com" )  
  	);	

  	$form['repec_meta']['repec_meta_maintainer_email'] = array(
      '#type' => 'textfield',
      '#title' => t('Maintainer\'s Email Address'),
      '#required' => TRUE,
      '#default_value' => variable_get('repec_meta_maintainer_email',''),
      '#description' => t("Email address for contacting the maintainer of this archive." )  
  	);  			

  	$form['repec_meta']['repec_meta_maintainer_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Maintainer\'s Name'),
      '#required' => TRUE,
      '#default_value' => variable_get('repec_meta_maintainer_name',''),
      '#description' => t("Name of the maintainer of this RePEc archive." )  
  	);

  	$form['repec_meta']['repec_meta_provider_homepage'] = array(
      '#type' => 'textfield',
      '#title' => t('Provider\'s Homepage'),
      '#required' => TRUE,
      '#default_value' => variable_get('repec_meta_provider_homepage',''),
      '#description' => t("Homepage for this archive." )  
  	);  
  	return system_settings_form($form);
}

/**
* repec_meta_templates()
* 
* @return 
* 	Returns the settings form for biblio to repec_meta 'Template Mappings'
*/	
function repec_meta_templates() {
  
  $default_value = 'wpaper';
  
  //creating an array of biblio types from query
  $sql = db_query("SELECT * FROM {repec_biblio_types} ORDER BY bid ASC");
  while ($data = db_fetch_object($sql)){
  		$b_type[$data->bid] = $data->b_type;
  			}
  //creating an array of repec types from query
  $sql = db_query("SELECT * FROM {repec_types} ORDER BY tid ASC");
  	while ($data = db_fetch_object($sql)){
  	 	$r_type[$data->tid] = $data->type;
  			}
  
  $form['repec_meta_templates'] = array(
  	'#type' => 'fieldset',
      '#title' => 'Assign Biblio to RePEc Template Mappings',
      '#description' => t('You can re-assign a RePEc template to the corresponding Biblio template by selecting from the drop down list'),
  	'#collapsible' => TRUE,
  	'#collapsed' => FALSE,
        );
  
    //query to generate options of for drop down list    
  $sql = db_query("SELECT * FROM {repec_biblio_types} ORDER BY bid ASC");
  while ($data = db_fetch_object($sql)){
  
  $form['repec_meta_templates'][$data->bid] = array(
    '#type' => 'select',
    '#title' =>  $data->b_type,
    '#options' => $r_type,
    '#default_value' => $data->rid,
    );
  }
  
    $form['repec_meta_templates']['submit'] = array(
    '#type' => 'submit',
   	'#value' => t('Save Settings'),
    '#prefix' => "<br>",
    );	
  
  return $form;
}

/**
* repec_meta_fields()
* 
* @return 
* 	Returns the settings form 'Manage Fields' for repec_meta indetifier fields
*/
function repec_meta_fields() {
  
  $sql = db_query("SELECT * FROM {repec_types}");
  
  
    while ($data = db_fetch_object($sql)) {
    		$repec_types[$data->tid] =  $data->type;
    	}

  //foreach loop here is generating a fieldset and form for each repec type
  foreach ($repec_types AS $tid => $type) {
  	
  	
  	//repec template friendly names
  	$friendly_name  = repec_meta_template_names($tid);

  	$form['repec_meta_fields'][$tid] = array( 
      '#type' => 'fieldset', 
      '#title' => t("$friendly_name Fields"),
      '#description' => t("All fields in the '$type' template are included by default within the RePEc rdf file. 
      You can choose to EXCLUDE any of the fields by highlighting them, except for those preceed with an 
      asterisk which are required fields. Required fields will always be included. "),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE, 
      ); 
  
  	//get list of identifer fields here
  	$sql_form = db_query("SELECT * FROM {repec_type_details} WHERE tid = %d ORDER BY weight ASC", $tid);
  	
  	
   while ($data_form = db_fetch_object($sql_form)) {
  		
  	//checking if required, if so place an asterisk at the end
  	$req = $data_form->required > 0 ?
  	'*'	: '' ;	
  	
  	//checking rows where active is 0 for default value highlight
  	if ($data_form->active < 1)		{
  	$default_value[] .= $data_form->active .  '___' .$data_form->identifier;
  	}

  	$options[$data_form->active .  '___' .$data_form->identifier] = $data_form->identifier . "$req";
  	
  	//$cur_type = $data_form->type;
  	$identifier = $data_form->identifier;
  	}

  	//the special symbol in the last array key here is 3 underscores
  	//which is used because this string will be split using this unique identifier in the submit() function
  	
  	$form['repec_meta_fields'][$tid][$type] = array(
      '#type' => 'select',
      '#multiple' => TRUE,
      '#title' => t('Select Fields To Exclude'),
      '#default_value' => $default_value,
      '#options' => $options,
       );
      
  	unset($default_value);
  	unset($options);	
  	}

   $form['repec_meta_fields']['submit'] = array(
      '#type' => 'submit',
     	'#value' => t('Save Settings'),
      '#prefix' => "<br>",
      
      );	
   
  return $form;
}