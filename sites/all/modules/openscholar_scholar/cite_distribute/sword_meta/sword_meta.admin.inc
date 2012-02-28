<?php

/**
* sword_meta_config()
* 
* @return 	Returns the system settings form for sword_meta 'Configuration' page
*/
function sword_meta_config(){
 
  
  $form['sword_meta'] = array( 
      '#type' => 'fieldset', 
      '#title' => t('Enter SWORD Information'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE, 
      ); 
      
      /* form will be harcoded for now.  when it's a bit more mature I'll generalize it
       * and give it its own db.  not sure how the gui will work for creating new entries
       * but making a new content type is probably overkill.  maybe a list/add tab display 
       * like taxonomy (although that is content...)
       */
      
  return $form;
}
