<?php

/**
 * Implementation of hook_filter_default_formats().
 */
function os_wysiwyg_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML
  $formats['Filtered HTML'] = array(
    'name' => 'Filtered HTML',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'manager',
      '4' => 'scholar admin',
      '5' => 'scholar user',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'embedfilter',
        'delta' => '0',
        'weight' => '-10',
      ),
      '1' => array(
        'module' => 'wysiwyg_filter',
        'delta' => '0',
        'weight' => '-9',
      ),
      '2' => array(
        'module' => 'oembed',
        'delta' => '0',
        'weight' => '-8',
      ),
      '3' => array(
        'module' => 'filter',
        'delta' => '2',
        'weight' => '-7',
      ),
      '4' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '-6',
      ),
      '5' => array(
        'module' => 'filter',
        'delta' => '1',
        'weight' => '-5',
      ),
      '6' => array(
        'module' => 'wysiwyg_fields',
        'delta' => '0',
        'weight' => '-4',
      ),
    ),
  );

  // Exported format: Full HTML
  $formats['Full HTML'] = array(
    'name' => 'Full HTML',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'oembed',
        'delta' => '0',
        'weight' => '-10',
      ),
      '1' => array(
        'module' => 'filter',
        'delta' => '2',
        'weight' => '-9',
      ),
      '2' => array(
        'module' => 'filter',
        'delta' => '1',
        'weight' => '-8',
      ),
      '3' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '-7',
      ),
      '4' => array(
        'module' => 'wysiwyg_fields',
        'delta' => '0',
        'weight' => '10',
      ),
    ),
  );

  // Exported format: Minimal WYSIWYG
  $formats['Minimal WYSIWYG'] = array(
    'name' => 'Minimal WYSIWYG',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'manager',
      '3' => 'scholar admin',
      '4' => 'scholar user',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'embedfilter',
        'delta' => '0',
        'weight' => '-10',
      ),
      '1' => array(
        'module' => 'wysiwyg_filter',
        'delta' => '0',
        'weight' => '-9',
      ),
      '2' => array(
        'module' => 'filter',
        'delta' => '2',
        'weight' => '-8',
      ),
      '3' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '-7',
      ),
      '4' => array(
        'module' => 'filter',
        'delta' => '1',
        'weight' => '-6',
      ),
      '5' => array(
        'module' => 'wysiwyg_fields',
        'delta' => '0',
        'weight' => '-5',
      ),
    ),
  );

  // Exported format: Full WYSIWYG
  $formats['Full WYSIWYG'] = array(
    'name' => 'Full WYSIWYG',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'manager',
      '3' => 'scholar admin',
      '4' => 'scholar user',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'embedfilter',
        'delta' => '0',
        'weight' => '-10',
      ),
      '1' => array(
        'module' => 'wysiwyg_filter',
        'delta' => '0',
        'weight' => '-9',
      ),
      '2' => array(
        'module' => 'oembed',
        'delta' => '0',
        'weight' => '-8',
      ),
      '3' => array(
        'module' => 'filter',
        'delta' => '2',
        'weight' => '-7',
      ),
      '4' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '-6',
      ),
      '5' => array(
        'module' => 'filter',
        'delta' => '1',
        'weight' => '-5',
      ),
      '6' => array(
        'module' => 'wysiwyg_fields',
        'delta' => '0',
        'weight' => '-4',
      ),
    ),
  );

  return $formats;
}
