<?php

/**
 * Implementation of hook_spaces_presets().
 */
function os_spaces_presets() {
  $export = array();
  $spaces_presets = new stdClass;
  $spaces_presets->disabled = FALSE; /* Edit this to true to make a default spaces_presets disabled initially */
  $spaces_presets->api_version = 3;
  $spaces_presets->name = 'scholar';
  $spaces_presets->title = 'OS personal';
  $spaces_presets->description = 'OpenScholar personal site';
  $spaces_presets->space_type = 'og';
  $spaces_presets->value = array(
    'variable' => array(
      'spaces_features' => array(
        'scholar_announcements' => 0,
        'scholar_publications' => 1,
        'scholar_front' => 1,
        'scholar_biocv' => 1,
        'scholar_classes' => 1,
        'scholar_pages' => 1,
        'scholar_image_gallery' => 0,
        'scholar_blog' => 0,
        'scholar_reader' => 0,
        'scholar_dvn' => 0,
        'scholar_links' => 0,
        'scholar_software' => 0,
      ),
      'spaces_og_selective' => 3,
      'spaces_og_register' => 0,
      'spaces_og_directory' => 1,
      'spaces_og_private' => 0,
      'site_frontpage' => "home",
      'default_theme' => 'scholar_airstream',
      'vsite_design_maintheme' => 'scholar_airstream',
      'spaces_preset_og' => 'scholar',
      'disqus_domain' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('OS personal');
  t('OpenScholar personal site');

  $export['scholar'] = $spaces_presets;
  
  $spaces_presets = new stdClass;
  $spaces_presets->disabled = FALSE; /* Edit this to true to make a default spaces_presets disabled initially */
  $spaces_presets->api_version = 3;
  $spaces_presets->name = 'project';
  $spaces_presets->title = 'Project Web Site preset';
  $spaces_presets->description = 'Project site preset';
  $spaces_presets->space_type = 'og';
  $spaces_presets->value = array(
    'variable' => array(
      'spaces_features' => array(
        'scholar_front' => 1,
        'scholar_pages' => 1,
        'scholar_announcements' => 1,
        'scholar_events' => 1,
        'scholar_profiles' => 1,
        'scholar_publications' => 0,
        'scholar_classes' => 0,
        'scholar_image_gallery' => 0,
        'scholar_reader' => 0,
        'scholar_blog' => 0,
        'scholar_dvn' => 0,
        'scholar_links' => 0,
        'scholar_software' => 0,
      ),
      'spaces_og_selective' => 3,
      'spaces_og_register' => 0,
      'spaces_og_directory' => 1,
      'spaces_og_private' => 0,
      'site_frontpage' => "home",
      'default_theme' => 'scholar_airstream',
      'vsite_design_maintheme' => 'scholar_airstream',
      'spaces_preset_og' => 'project',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('OS project');
  t('OpenScholar project site');

  $export['project'] = $spaces_presets;
  return $export;
}