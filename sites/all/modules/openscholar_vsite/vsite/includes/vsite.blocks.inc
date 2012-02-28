<?php

/**
 * Render the search block on the page
 */
function vsite_search_block(){
  if (! module_exists('search') || ! user_access('search content')) {
    return;
  }
  $block['content'] = drupal_get_form('search_form');
  return $block;
}

/**
 * A widget to allow translation of a page
 * @return array
 */
function vsite_googletranslate_block(){
  global $language;
  $lang = ($language->language)?$language->language:'en';

  $block['subject'] = t(''); //Blank
  $block['content'] = '<div id="google_translate_element"></div><script>
                        function googleTranslateElementInit() {
                          new google.translate.TranslateElement({
                            pageLanguage: \''.$lang.'\'
                          }, \'google_translate_element\');
                        }
                        </script><script src="http://translate.google.com/translate_a/element.js?cb=googleTranslateElementInit"></script>';
  return $block;

}