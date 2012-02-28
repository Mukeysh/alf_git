<?php

function scholar_presentations_settings() {
  $form = array();
  if (module_exists('slideshareapi')) {
    $form = slideshareapi_settings();
  }

  unset($form['slideshareapi']['slideshareapi_apiurl']);
  $vsite = vsite_get_vsite();
  $frag = &$form['slideshareapi'];
  $frag['slideshareapi_key'] = array_merge($frag['slideshareapi_key'], array('#default_value' => $vsite->controllers->variable->get('slideshareapi_key', 'space'), '#required' => FALSE));
  $frag['slideshareapi_secret'] = array_merge($frag['slideshareapi_secret'], array('#default_value' => $vsite->controllers->variable->get('slideshareapi_secret', 'space'), '#required' => FALSE));
  $frag['slideshareapi_user'] = array_merge($frag['slideshareapi_user'], array('#default_value' => $vsite->controllers->variable->get('slideshareapi_user', 'space'), '#required' => FALSE));
  $frag['slideshareapi_pass'] = array_merge($frag['slideshareapi_pass'], array('#default_value' => $vsite->controllers->variable->get('slideshareapi_pass', 'space'), '#required' => FALSE));

  // detect for presentations that haven't been uploaded
  $vsite = vsite_get_vsite();
  $s = 'SELECT c.* FROM {content_field_presentation_file} c JOIN {og_ancestry} o USING (nid) WHERE group_nid = %d';
  $q = db_query($s, $vsite->group->nid);
  $not_uploaded = 0;
  while ($r = db_fetch_array($q)) {
    $data = unserialize($r['field_presentation_file_data']);
    if (!isset($data['slideshare_doc_id'])) {
      $not_uploaded++;
    }
  }

  if ($not_uploaded) {
    $form['upload_missing'] = array(
      '#title' => t('You have @missing presentations not uploaded to SlideShare.', array('@missing' => $not_uploaded)),
      '#description' => t('Some of your presentations haven\'t been uploaded to SlideShare. Do you want to do so?'),
      '#default_value' => FALSE,
      '#type' => 'checkbox',
    );
  }

  $form['buttons']['#weight'] = 10;
  // system settings form is run by slideshareapi_settings
  // don't need to do it again here
  $form['#submit'][] = 'scholar_presentations_submit';
  return $form;
}

function scholar_presentations_submit(&$form, &$form_state) {
  // clear out blank space variables so we use the default
  $vsite = vsite_get_vsite();

  $var = &$vsite->controllers->variable;
  foreach (array('key', 'secret', 'user', 'pass') as $k) {
    if ($var->get('slideshareapi_'.$k, 'space') == '') {
      $var->del('slideshareapi_'.$k);
    }
  }

  if ($form_state['values']['upload_missing']) {
    $s = 'SELECT c.* FROM {content_field_presentation_file} c JOIN {og_ancestry} o USING (nid) WHERE group_nid = %d';
    $q = db_query($s, $vsite->group->nid);
    while ($r = db_fetch_array($q)) {
      $data = unserialize($r['field_presentation_file_data']);
      if (!isset($data['slideshare_doc_id'])) {
        // upload to slideshare
        $file = db_result(db_query("SELECT filepath FROM {files} WHERE fid = %d", $r['field_presentation_file_fid']));
        $response = slidesharefield_api_upload($file);
        $ss_id = $response[0]['SLIDESHOWID'];

        if ($ss_id) {
          $data['slideshare_doc_id'] = $ss_id;
          $r['field_presentation_file_data'] = serialize($data);
          drupal_write_record('content_field_presentation_file', $r, array('vid', 'field_presentation_file_fid'));
        }
      }
    }
  }
}