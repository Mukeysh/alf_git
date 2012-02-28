<?php
/**
 * CP Form Functions
 */
require_once ( drupal_get_path('module', 'taxonomy'). '/taxonomy.admin.inc');

function vsite_taxonomy_form($form_state) {

  dialog_add_js();
  drupal_add_js('misc/collapse.js');
  $vsite = vsite_get_vsite();
  $vocabs = $vsite ? $vsite->get_vocabs() : array();
  require_once drupal_get_path('module','taxonomy').'/taxonomy.admin.inc';

  ctools_include('ajax');
  ctools_include('modal');

  $form['new_menu_link_context'] = array(
    '#type' => 'markup',
    '#value' => theme('item_list', array(
      l('Add New Vocabulary', 'vsite/taxonomy/nojs/add/vocabulary',  array('attributes' => array('class' => 'ctools-use-dialog context-button')))
    ), $title = NULL, $type = 'ul', $attributes = array(
      "class" => "context-links"
    )),
  );
  $form['buttons'] = array();

  // let's do something crazy
  // I'm going to get the forms for each category in a vsite,
  // stick the elements in a fieldset with #tree = TRUE
  // then in the submit, I'll send each fieldset off to taxonomy's
  // submit handler.
  // each vocabulary is encapsulated in the form and in form_state[values]

  foreach ($vocabs as $vid => $v) {

    $form_id = 'taxonomy_overview_terms';
    $form_state_frag = array('storage' => NULL, 'submitted' => FALSE);
    $args = array($form_id, &$form_state_frag, taxonomy_vocabulary_load($vid));

    $form_frag = call_user_func_array('drupal_retrieve_form', $args);
    drupal_prepare_form($form_id, $form_frag, $form_state_frag);
    unset($form_frag['#parents']);
    if (!$form_frag['#parent_fields']) {
      unset($form_frag['#parent_fields']);
    }

    foreach ($form_frag as $k => $field) {
      if (is_array($field) && isset($field['#term'])) {
        $form_frag[$k]['edit']['#value'] = l('Edit', "vsite/taxonomy/nojs/terms/edit/".$field['#term']['tid'], array('attributes' => array('class' => 'ctools-use-dialog')));
      }
    }

    $fieldset = array(
      '#type' => 'fieldset',
      '#title' => ucfirst($v->name),
      '#tree' => TRUE,
      '#theme' => 'taxonomy_overview_terms',
      '#desciption' => 'taxonomy meta-data',
    );
    $form['buttons']['submit'] = $form_frag['submit'];
    unset($form_frag['submit'], $form_frag['reset_alphabetical']);
    $form_frag['add_new_term'] = array(
      '#type' => 'markup',
      '#prefix' => '<div>',
      '#suffix' => '</div>',
      '#value' =>  l('Add new term to this vocabulary', "vsite/taxonomy/nojs/terms/".$vid."/add_term", array('attributes' => array('class' => 'admin ctools-use-dialog context-button'))),
    );
    $form_frag['edit_vocab'] = array(
      '#type' => 'markup',
      '#prefix' => '<div>',
      '#suffix' => '</div>',
      '#value' => ' '.l('Edit vocabulary', 'vsite/taxonomy/nojs/edit/vocabulary/'.$vid, array('attributes' => array('class' => 'admin ctools-use-dialog context-button'))),
    );

    $fieldset += $form_frag;
    $form[strtolower(str_replace(' ', '_', $v->name))] = $fieldset;
  }
  $form['buttons'] += array(
    '#type' => 'markup',
    '#prefix' => '<div>',
    '#suffix' => '</div>',
    '#weight' => 1,
  );

  drupal_set_title(t('Taxonomy'));

  return $form;
}

function vsite_taxonomy_form_submit($form, &$form_state) {
  $new_form_state = $form_state;
  foreach ($form_state['values'] as $v_name => $vocab_form_state) {
    if (is_array($vocab_form_state)) {
      $vocab_new_state = $new_form_state;
      $vocab_new_state['values'] = $vocab_form_state;
      $vocab_form = $form[$v_name];
      $vocab_form['#post'] += $form['#post'][$v_name];

      foreach ($vocab_form['#submit'] as $submit) {
        $submit($vocab_form, $vocab_new_state);
      }
    }
  }
}

function theme_vsite_taxonomy_form($form) {
  $content = '';
  foreach (element_children($form) as $element) {
    $element_content = drupal_render($form[$element]);
    if ($form[$element]['#type'] == 'fieldset') {
      $element_content = str_replace('id="taxonomy"', 'id="taxonomy-'.$element.'"', $element_content);

      // tabledrag
      if ($form[$element]['#parent_fields']) {
        drupal_add_tabledrag('taxonomy-'.$element, 'match', 'parent', 'term-parent', 'term-parent', 'term-id', FALSE);
        drupal_add_tabledrag('taxonomy-'.$element, 'depth', 'group', 'term-depth', NULL, NULL, FALSE);
      }
    }
    $content .= $element_content;
  }

  // prevents js error
  drupal_add_js('Drupal.behaviors.termDrag = function(context) {}','inline');

  return $content;
}

/**
 * Add vocabulary form callback
 */
function vsite_taxonomy_form_add_vocabulary($ajax = FALSE){
  $taxs = module_invoke_all('vsite_vocabulary_default');
  if ($ajax) {
    ctools_include('ajax');
    $form_state = array(
      'ajax' => TRUE,
      'title' => t('Add vocabulary')
    );

    $output = dialog_form_wrapper('taxonomy_form_vocabulary', $form_state);

    if (empty($output)) {
      $output[] = dialog_command_display(t('Vocabulary was created!'), t('(Reloading page)'));
      $output[] = ctools_ajax_command_reload();
    }
    else {
      foreach ( $output as $i => $command ) {
        if ($command['command'] == 'dialog_display') {
          $output[$i]['options'] = vsite_taxonomy_dialog_options();
        }
      }
    }
    ctools_ajax_render($output);

  }
  else {
    return drupal_get_form('taxonomy_form_vocabulary');
  }

}

/**
 * edit/delete vocabulary form callback
 */
function vsite_taxonomy_form_edit_vocabulary($vocabulary, $ajax = FALSE){
  $delete_mode = FALSE;

  if ((isset($_POST['op']) && $_POST['op'] == t('Delete')) || isset($_POST['confirm']) && $_POST['op'] == t('Delete')) {
    $delete_mode = TRUE;
    return vsite_taxonomy_delete_vocabulary($vocabulary->vid, $ajax);
  }

  if ($ajax) {
    ctools_include('ajax');
    $form_state = array(
      'ajax' => TRUE,
      'title' => t('Edit vocabulary'),
      'args' => array(
        'edit' => ( array ) $vocabulary
      )
    );

    if ($_POST['op'] == t('Reset to alphabetical')) {
      $form_state['args']['edit'] = $vocabulary->vid;
      $output = dialog_form_wrapper('taxonomy_vocabulary_confirm_reset_alphabetical', $form_state);
    }
    else {
      $output = dialog_form_wrapper('taxonomy_form_vocabulary', $form_state);
    }

    if (empty($output)) {
      $output[] = dialog_command_display(t('Vocabulary settings changed!'), t('(Reloading page)'));
      $output[] = ctools_ajax_command_reload();
    }
    else {
      foreach ( $output as $i => $command ) {
        if ($command['command'] == 'dialog_display') {
          $output[$i]['options'] = vsite_taxonomy_dialog_options();
        }
      }
    }
    ctools_ajax_render($output);

  }
  else {
    return drupal_get_form('taxonomy_form_vocabulary', ( array ) $vocabulary);
  }

}

/**
 * delete vocabulary confirmation form
 */
function vsite_taxonomy_delete_vocabulary($vid, $ajax = FALSE){
  if ($ajax) {
    ctools_include('ajax');
    $form_state = array(
      'ajax' => TRUE,
      'title' => t('Delete this vocabulary'),
      'args' => array(
        'vid' => $vid
      )
    );

    $output = dialog_form_wrapper('taxonomy_vocabulary_confirm_delete', $form_state);

    if (empty($output)) {
      $output[] = dialog_command_display(t('Vocabulary settings changed!'), t('(Reloading page)'));
      $output[] = ctools_ajax_command_reload();
    }
    else {
      foreach ( $output as $i => $command ) {
        if ($command['command'] == 'dialog_display') {
          $output[$i]['options'] = vsite_taxonomy_dialog_options();
        }
      }
    }
    ctools_ajax_render($output);
  }
  else {
    return drupal_get_form('taxonomy_vocabulary_confirm_delete', $vid);
  }
}

/**
 * add term form callback
 */
function vsite_taxonomy_add_term($vocabulary, $ajax = FALSE, $n_parent_tid = false){

  if ($ajax) {
    ctools_include('ajax');
    $form_state = array(
      'ajax' => TRUE,
      'title' => t('Add a new term to this vocabulary'),
      'args' => array(
        'vocabulary' => $vocabulary
      ),
    );

    if($n_parent_tid) $form_state['default_parent'] = array($n_parent_tid);

    $output = dialog_form_wrapper('taxonomy_form_term', $form_state);

    if (empty($output)) {
      $output[] = dialog_command_display(t('Saving your settings'), t('(Reloading page)'));
      $output[] = ctools_ajax_command_reload();
    }
    else {
      foreach ( $output as $i => $command ) {
        if ($command['command'] == 'dialog_display') {
          $output[$i]['options'] = vsite_taxonomy_dialog_options();
        }
      }
    }
    ctools_ajax_render($output);
  }
  else {
    $form = drupal_get_form('taxonomy_form_term', $vocabulary);
    if($n_parent_tid){
      $form['advanced']['parent']['#default_value'] = array($n_parent_tid);
    }
    return $form;
  }
}

/**
 * edit term form callback
 */
function vsite_taxonomy_edit_term($tid, $ajax = FALSE){
  $vsite = vsite_get_vsite();
  $vsite_vocabs = $vsite->get_vocabs($node_type);
  $term = taxonomy_get_term($tid);

  $access = array_key_exists($term->vid, $vsite_vocabs);

  if ($ajax) {
    ctools_include('ajax');
    // wrong tid ?
    if (! $term) {
      $commands = array();
      $commands[] = dialog_command_display(t('Page not found'));
      ctools_ajax_render($commands);
    }
    // no access ?
    if (! $access) {
      $commands = array();
      $commands[] = dialog_command_display(t('Access denied'));
      ctools_ajax_render($commands);
    }

    $form_state = array(
      'ajax' => TRUE,
      'title' => t('Edit term'),
      'args' => array(
        'vocabulary' => taxonomy_vocabulary_load($term->vid),
        'edit' => ( array ) $term
      )
    );

    $output = dialog_form_wrapper('taxonomy_form_term', $form_state);

    if (empty($output)) {
      $output[] = dialog_command_display(t('Saving your settings'), t('(Reloading page)'));
      $output[] = ctools_ajax_command_reload();
    }
    else {
      foreach ( $output as $i => $command ) {
        if ($command['command'] == 'dialog_display') {
          $output[$i]['options'] = vsite_taxonomy_dialog_options();
        }
      }
    }
    ctools_ajax_render($output);
  }
  else {
    return og_vocab_taxonomy_admin_term_edit($tid);
  }
}

/**
 * Implementation of hook_form_FORM_ID_alter().
 */
function vsite_taxonomy_form_taxonomy_form_term_alter(&$form, &$form_state) {

  // hide some advanced options from the term edit form
  $vsite = vsite_get_vsite();
  $form['identification']['#collapsible'] = false;
  $form['advanced']['#collapsed'] = true;
  $hides = array('relations', 'synonyms');
  foreach($hides as $element){
    unset($form['advanced'][$element]);
  }

  $form['identification']['description']['#description'] = t('A description of the term. To be displayed on taxonomy/term pages and RSS feeds. You may use HTML tags to add links, standard formatting elements such as bold and underline, as well as headers, lists, images and tables.');

  $form['advanced']['weight']['#type'] = 'value';
  $form['advanced']['weight']['#value'] = $form['advanced']['weight']['#default_value'];

  if($form_state['clicked_button']['#value'] == t('Delete')){
  	if($vsite && $form['actions']){
  		$form['actions']['cancel']['#value'] = l("Cancel","cp/build/taxonomy");
  	}
  	return;
  }

  if($form_state['default_parent'] && !count($form['advanced']['parent']['#default_value'])){
    $form['advanced']['parent']['#default_value'] = $form_state['default_parent'];
  }//Set your default term parent

  if($form['#vocabulary']['tags']){
    $form['advanced']['parent']['#type'] = 'value';
    unset($form['advanced']['parent']['#theme']);
    $form['identification']['name']['#element_validate'][] = 'vsite_taxonomy_form_term_name_validate';
  }

  $existing = false;
  if($form['#term']['tid']){
    $existing = vsite_menus_get_menu_item( _vsite_taxonomy_get_term_path($form['#term']['tid']) );
  }

  $form['advanced']['menu'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menu Entry (optional)'),
    '#collapsible' => false,
    '#description' => "Creates a menu entry that will link to the items associated with this term"
  );

  $form['advanced']['menu']['link_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Menu Title'),
    '#default_value' => $existing?$existing['link_title']:$form['identification']['name']['#default_value'],
    '#size' => 20,
    '#maxlength' => 40,
    '#required' => false,
  );

  $s_default = ($existing)?$existing['menu_name']:0;

  $form['advanced']['menu']['menu_name'] = array(
    '#type' => 'select',
    '#title' => t('Menu Location'),
    '#default_value' => $s_default,
    '#options' => array_merge(array(0 => t('No Menu')), variable_get('scholar_site_menus',array())),
  );

  $form['#submit'][] = 'vsite_taxonomy_form_taxonomy_form_term_submit';
}

function vsite_taxonomy_form_term_name_validate($element, &$form_state) {
  if (!$form_state['values']['tid'] && $form_state['args']['vocabulary']->tags && $form_state['values']['op'] != $form_state['values']['delete']) {
    if (db_result(db_query("SELECT COUNT(*) FROM {term_data} WHERE vid = %d AND name = '%s'", $form_state['args']['vocabulary']->vid, $form_state['values']['name']))) {
      form_set_error('name', t('May not have 2 terms with the same name in a free-tagging vocabulary.'));
    }
  }
}

/**
 * Create a menu link to the taxonomy term
 */
function vsite_taxonomy_form_taxonomy_form_term_submit($form, &$form_state){
  $vsite = vsite_get_vsite();
  if(!$vsite || $form_state['clicked_button']['#value'] == t('Delete')) return;
  /**
   * Handle Adding removing or Updating the menu link for this taxonomy term
   */
  $existing = false;
  if($form_state['tid']){
    $existing = vsite_menus_get_menu_item( _vsite_taxonomy_get_term_path($form_state['tid']) );
  }//Does this menu entry already exist

  if($form_state['values']['menu_name'] && $form_state['values']['link_title'] && $form_state['tid']){

    if($existing){
      list($old_menu,$path) = explode(":",$existing['key'],2);
      if($old_menu != $form_state['values']['menu_name']){
        $vsite->controllers->vsite_menu->delete_menu_item($old_menu,$existing['key']);
      }//Delete this link from the old menu?
    }

    $item['menu_name'] = $form_state['values']['menu_name'];
    $item['link_title'] = trim($form_state['values']['link_title']);
    $item['link_path'] = _vsite_taxonomy_get_term_path($form_state['tid']);
    $item['options']['attributes']['title'] = trim($node->title);
    $item['key'] = $item['menu_name'].":".$item['link_path'];
    $item = $item + array('router_path' => 'taxonomy/term/%', 'module' => 'vsite_taxonomy', 'weight' => 60, 'user_created' => 1);

    // Add or Update the menu link
    $a_menu = $vsite->controllers->vsite_menu->get( $item['menu_name'] );
    $vsite->controllers->vsite_menu->set( $item['menu_name'], array_merge($a_menu,array($item['menu_name'].":".$item['link_path'] => $item)));

  }elseif (count($existing)){
    //Remove the link if they deselect the menu or remove the link name
    $vsite->controllers->vsite_menu->delete_menu_item($existing['menu_name'], $existing['key']);
  }
}

/**
 * Implementation of hook_form_FORM_ID_alter().
 */
function vsite_taxonomy_form_taxonomy_form_vocabulary_alter(&$form, &$form_state){
  $vsite = vsite_get_vsite();
  if (!$vsite){
    return ;
  }
  if ($form_state['args']) {
    $form['reset_alphabetical'] = array(
      '#type' => 'submit',
      '#value' => t('Reset to alphabetical'),
    //  '#submit' => array('taxonomy_overview_terms_submit'),
    );
  }

  //Passes gid as a value in the taxonomy add/edit form
  unset($form['settings']['og_vocab']);

  $form['settings']['og_vocab']['og'] = array(
    '#type' => 'value',
    '#value' => $vsite->group->nid
  );

  //No Collapse
  $form['identification']['#collapsible'] = false;
  $form['content_types']['#collapsible'] = false;
  $form['settings']['#collapsible'] = false;


  // filter the content type based on the vsite
  vsite_include('vsiteapi');
  $vocab_types = vsite_content_types();
  drupal_alter('vsite_content_types', $vocab_types);
  $form['content_types']['nodes']['#options'] = $vocab_types;
  $form['content_types']['nodes']['#required'] = true; //Must select taxonomy

  // hide weight element
  unset($form['settings']['weight']);

  foreach ($form['#submit'] as &$submit) {
    if ($submit == 'taxonomy_form_vocabulary_submit') {
      $submit = 'vsite_taxonomy_form_taxonomy_form_vocabulary_submit';
    }
  }
}

function vsite_taxonomy_form_taxonomy_form_vocabulary_submit($form, &$form_state) {
  if ($form_state['values']['op'] == $form_state['values']['reset_alphabetical']) {

    // Execute the reset action.
    if ($form_state['values']['reset_alphabetical'] === TRUE) {
      return taxonomy_vocabulary_confirm_reset_alphabetical_submit($form, $form_state);
    }
    // Rebuild the form to confirm the reset action.
    $form_state['rebuild'] = TRUE;
    $form_state['confirm_reset_alphabetical'] = TRUE;
    return;
  }

  taxonomy_form_vocabulary_submit($form, $form_state);
}
