<?php
/**
 * Override or insert PHPTemplate variables into the templates.
 */
function cp_theme_preprocess_page(&$vars, $hook) {
  $tabs2 =  menu_secondary_local_tasks();
  if ($tabs2){
    $vars['tabs2'] = '<ul class="tabs secondary clear-block">' . menu_secondary_local_tasks() . '</ul>';
  }
  //adds cp page classes
  $body_classes = array($vars['body_classes']);
  list($section, ) = explode('/', $_GET['q'], 1);
  $body_classes[] = scholar_base_id_safe('page-' . $section);
  $vars['body_classes'] = implode(' ', $body_classes);
}

/**
 * Returns the rendered local tasks. The default implementation renders
 * them as tabs. Overridden to split the secondary tasks.
 *
 * @ingroup themeable
 */
function cp_theme_menu_local_tasks() {
  $output = '';
  $primary = menu_primary_local_tasks();
  if ($primary){
    $output .= '<ul class="tabs primary clear-block">' . $primary . '</ul>';
  }
  return $output;
}


/**
 * Form theme function for customization items.
 *
 * Overridden: So that they remain in fieldsets
 */
function cp_theme_spaces_customize_item($form) {
	$output = '';
  foreach (element_children($form) as $element) {
    if ($form[$element]['#type'] == 'fieldset') {
      $title = $form[$element]['#title'];
      unset($form[$element]['#title']);
      unset($form[$element]['#type']);
      $output .= "<div class='fieldset-wrapper'>".drupal_render($form[$element])."</div>";
    }
  }
  return $output;
}

/**
 * Change the link to users on the og memebers view
 * @param $view
 * @param $field
 * @param $row
 * @return unknown_type
 */
function cp_theme_views_view_field__og_members__name($view, $field, $row) {
	return check_plain($row->{$field->field_alias});
	//return ctools_modal_text_button(check_plain($row->{$field->field_alias}), 'cp/users/edit/'. $row->{$field->aliases['uid']} , 'edit '.$row->{$field->field_alias});
}

/**
 * override theme function for spaces_features_form().
 * @see spaces/spaces.theme.inc
 * The only thing this does is add class 'enabled' to the 
 * row of the enabled features 
 */
function cp_theme_spaces_features_form($form){
  $rows = array();
  $spaces_features = variable_get('spaces_features', array());
  foreach ( element_children($form['spaces_features']) as $f_name => $feature ) {
    $class = ($spaces_features[$feature]) ? 'enabled' : '';
    $rows[] = array(
      'data' => array(
        array(
          'class' => 'name', 
          'data' => drupal_render($form['labels'][$feature]) 
        ), 
        array(
          'class' => 'option', 
          'data' => drupal_render($form['spaces_features'][$feature]) 
        ), 
        array(
          'class' => 'actions', 
          'data' => drupal_render($form['settings'][$feature]) 
        ) 
      ), 
      'class' => $class 
    )
    ;
  }
  $output = theme('table', array(), $rows, array('class' => 'spaces-features'));
  $output .= drupal_render($form);
  return $output;
}