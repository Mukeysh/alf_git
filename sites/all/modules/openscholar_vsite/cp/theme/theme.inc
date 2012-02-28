<?php
/**
 * Preprocessor for theme('admin_toolbar').
 * TODO  do we ever have $depth > 0
 */

function cp_preprocess_cp_toolbar(&$vars) {
  $vars['collapsed'] = TRUE;
  foreach ($vars['tree'] as $depth => $menus) {
    foreach ($menus as $href => $links) {
      $class = ($depth > 0) ? 'collapsed' : '';
      if ($depth > 0 && cp_in_active_trail($href)) {
        $class = '';
        $vars['collapsed'] = FALSE;
      }
      $id = str_replace('/', '-', $href);

      // If we aren't on the top level menu, provide a way to get to the top level page.
      if ($depth > 0 && !empty($links)) {
        $links['view-all'] = array(
          'title' => t('View all'),
          'href' => $href,
        );
      }
      $vars["tree_{$depth}"][$id] = theme('links', $links, array('class' => "links clear-block $class", 'id' => "cp-toolbar-{$id}"));
    }
  }
}
