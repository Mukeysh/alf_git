<?php
function scholar_publications_settings($space) {

  include_once drupal_get_path('module', 'biblio') .'/biblio.admin.inc';

  $s_style = biblio_get_style();

  $form['#columns'] = TRUE;

  $form['biblio_style'] = array(
    '#type' => 'radios',
    '#title' => t('Select your preferred bibliographic format'),
    //'#description' => t('This alters the bibliographic format of your publications.'),
    '#default_value' => $s_style,
    '#options' => _biblio_admin_get_styles(),
    '#region' => 'right',
  );

  $form['biblio_export_links'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Select which export formats should accompany each bibliographic record'),
    '#default_value' => variable_get('biblio_export_links', array('tagged', 'xml', 'bibtex')),
    '#options' => array(
      'tagged'  => t('EndNote Tagged'),
      'xml'     => t('EndNote XML'),
      'bibtex'  => t('BibTex'),
    ),
    '#description' => t('Each selected format will appear in its own export link.'),
    '#region' => 'right',
  );

  $form['biblio_google_link'] = array(
    '#type' => 'checkbox',
    '#title' => t('Link to Google Scholar'),
    '#return_value' => 1,
    '#default_value' => variable_get('biblio_google_link', 1),
    '#description' => t('This adds the necessary metadata to your web site to allow Google Scholar to properly index your publication.'),
    '#region' => 'right',
  );

  $form['scholar_publications_note_in_teaser'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the "note" content in teaser?'),
    //'#description' => t('This alters the bibliographic format of your publications.'),
    '#default_value' => variable_get('scholar_publications_note_in_teaser',false),
    '#description' => t('If this is checked and you add a note to a publication then it will show as part of a publications teaser.'),
    '#region' => 'right',
  );

  $form['biblio_rowsperpage'] = array(
    '#type' => 'textfield',
    '#title' => t('Publications per page'),
    '#size' => 5,
    '#default_value' => variable_get('biblio_rowsperpage',25),
    '#description' => t('Select the number of publication to be displayed on each page.'),
  );

  $form['biblio_sort'] = array(
    '#type' => 'radios',
    '#title' => t('By default, sort publications by which category'),
    '#default_value' => variable_get('biblio_sort','year'),
    '#options' => array('author' => t('Author'), 'keyword' => t('Keyword'), 'title' => t('Title'), 'type' => t('Type'), 'year' => t('Year')),
  );

  $form['biblio_order'] = array(
    '#type' => 'radios',
    '#title' => t('Select default order of the sort category'),
    '#default_value' => variable_get('biblio_order', 'DESC'),
    '#options' => array('DESC' => t('Descending'), 'ASC' => t('Ascending')),
  );

  $form['biblio_sort_tabs'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Allow additional sorting of your publications by'),
    '#default_value' => variable_get('biblio_sort_tabs', array('author'=>'author', 'title'=>'title', 'type'=>'type', 'year'=>'year')),
    '#options' => array('author' => t('Author'), 'title' => t('Title'), 'type' => t('Type'), 'year' => t('Year')),
    //'#description' => t('You turn the sorting links at the top of the /biblio page here.'),
  );
  
  $form['scholar_publications_filter_publication_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Show only publications of type'),
    '#default_value' => variable_get('scholar_publications_filter_publication_types', array_keys(scholar_publications_get_biblio_types())),
    '#options' => scholar_publications_get_biblio_types(),
    '#description' => t('The main list of publications on your publications page will list the types slected here.'),
    '#region' => 'right',
    '#attributes' => array("class" => "form-checkboxes-scrolling"),
  );
  
  //Should urls in citations be shortened?
  $form['scholar_publications'] = array(
  '#type' => 'fieldset',
  '#region' => 'footer',
  );
 
  $form['scholar_publications']['scholar_publications_shorten_citations'] = array(
   '#type' => 'checkbox',
   '#title' => t('When this is checked, a shortened URL will be included in the citation.'),
   '#default_value' => variable_get('scholar_publications_shorten_citations', 0),
    );

  


  $form['buttons']['#region'] = 'footer';

  return system_settings_form($form);
}
