<?php


/**
 * Implementation of CCK's hook_widget_info().
 */
function slidesharefield_widget_info(){
  return array(
      'slidesharefield_widget' => array(
          'label' => t('Slideshare Upload'),
          'field types' => array(
              'filefield'
          ),
          'callbacks' => array(
              'default value' => CONTENT_CALLBACK_CUSTOM
          ),
          'description' => t('A widget which sends its uploaded files to Slideshare.net.')
      )
  );
}

/**
 * Implementation of CCK's hook_widget().
 */
function slidesharefield_widget(&$form, &$form_state, $field, $items, $delta = 0){
  return filefield_widget($form, $form_state, $field, $items, $delta);
}

/**
 * Implementation of hook_elements().
 */
function slidesharefield_elements(){
  $filefield_elements = filefield_elements();
  $elements['slidesharefield_widget'] = $filefield_elements['filefield_widget'];
  $elements['slidesharefield_widget']['#process'][] = 'slidesharefield_widget_process';
  $elements['slidesharefield_widget']['#element_validate'][] = 'filefield_widget_validate';

  return $elements;
}


/**
 * Form API #process callback; see hook_elements().
 */
function slidesharefield_widget_process($element, $edit, &$form_state, $form){
  if (_form_button_was_clicked($element['filefield_remove'])) {
    unset($element['#value']['data']['slideshare_doc_id']);
    $_SESSION['scribfield_removed_files'][$element['#delta']] ++;
  }

  // we have no way of knowing if someone has a) edited the node, b) clicked
  // Remove, c) uploaded a new file to the same delta. For some reason, the
  // 'data' elements are retained even during such a workflow, so we have to
  // keep track of deleted files in SESSION - if they have, we always wipe
  // out our custom values there, so that the file can be handled on presave.
  if ($_SESSION['scribfield_removed_files'][$element['#delta']]) {
    unset($element['#value']['data']['slideshare_doc_id']);

  }

  if (! empty($element['#value']['filepath'])) {
    $element['data']['slidesharefield_warning'] = array(
        '#type' => 'markup',  // we don't handle any remote file deletion, so let the user know. AND MAKE 'EM DO THE LEGWORK. HAHAHAHAH.
        '#value' => t('<div class="description">Files intended for Slideshare.net are not sent until this entire form has been saved. Uploaded files are <strong>never</strong> automatically removed from Slideshare.net: if you remove the file or delete this content, you\'ll also need to manually remove them from Slideshare\'s "My Uploads".</div>')
    );
  }

  return $element;
}



/**
 * Implementation of hook_field_formatter_info().
 */
function slidesharefield_field_formatter_info(){
  return array(
      'slideshare' => array(
          'label' => t('Slide Share Embeded'),
          'field types' => array(
              'filefield'
          ),
          'description' => t('Displays uploaded Slideshare.net files in Embeded form.')
      ),
      'slideshare_thumbnail' => array(
          'label' => t('Slide Share Thumnail'),
          'field types' => array(
              'filefield'
          ),
          'description' => t('Displays Thumnail for Slide Share Uploaded file.')
      ),
      'slideshare_thumb_popup' => array(
        'label' => t('Slide Share Thumbnail with Lightbox Popup'),
        'field types' => array(
          'filefield'
        ),
        'description' => t('Displays Thumbnail for Slide Share Uploaded file, with a clickable popup for the full Flash presentation.'),
      ),
  );
}



/**
 * Implementation of hook_widget_settings().
 */
function slidesharefield_widget_settings($op, $widget){
  switch ($op) {
    case 'form' :
      $form = array();

      $form['file_extensions'] = array(
          '#type' => 'textfield',
          '#title' => t('Permitted upload file extensions for Slide Share'),
          '#default_value' => is_string($widget['file_extensions']) ? $widget['file_extensions'] : 'pdf ppt pps pptx',
          '#required' => TRUE,
          '#description' => t('Extensions a user can upload to this field. Separate extensions with a space and do not include the leading dot. Leaving this blank will allow users to upload a file with any extension.'),
          '#weight' => 1
      );
      return $form;

    case 'save' :
      return array(
          'file_extensions'
      );
  }

}





