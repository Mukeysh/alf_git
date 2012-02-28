<?php

/**
 * Implementation of hook_content_default_fields().
 */
function scholar_announcements_content_default_fields() {
  $fields = array();

  // Exported field: field_os_inline_files
  $fields['announcement-field_os_inline_files'] = array(
    'field_name' => 'field_os_inline_files',
    'type_name' => 'announcement',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '1',
    'widget' => array(
      'file_extensions' => '',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '128M',
      'max_filesize_per_node' => '',
      'wysiwyg_fields_status' => 1,
      'wysiwyg_fields_icon' => '32c1419a9092fb94fcc30f95d7a66fb4',
      'wysiwyg_fields_formatters' => array(
        'default' => 'default',
      ),
      'wysiwyg_fields_hide' => 1,
      'wysiwyg_fields_delete' => 0,
      'filefield_sources' => array(
        'remote' => 'remote',
        'reference' => 0,
        'attach' => 0,
      ),
      'filefield_source_attach_path' => 'file_attach',
      'filefield_source_attach_absolute' => '0',
      'filefield_source_attach_mode' => 'move',
      'filefield_source_autocomplete' => '0',
      'insert' => 1,
      'insert_styles' => array(
        'os_file_description' => 'os_file_description',
        'auto' => 0,
        'link' => 0,
        'image' => 0,
        'imagecache_AttachmentThumbnail' => 0,
        'imagecache_book_cover' => 0,
        'imagecache_book_cover_thumb' => 0,
        'imagecache_gallery_small_thumb' => 0,
        'imagecache_gallery_thumb' => 0,
        'imagecache_image_s' => 0,
        'imagecache_inline_default' => 0,
        'imagecache_inline_larger' => 0,
        'imagecache_openscholar_front_logo' => 0,
        'imagecache_presentation_thumb' => 0,
        'imagecache_square_35_35' => 0,
        'imagecache_square_50_50' => 0,
        'imagecache_thumb' => 0,
        'imagecache_vsite_design_default_logo' => 0,
        'imagecache_vsite_design_landscape_logo' => 0,
        'imagecache_vsite_design_portrait_logo' => 0,
        'imagecache_vsite_design_square_logo' => 0,
        'imagecache_vsite_shields_default_shield' => 0,
      ),
      'insert_default' => 'os_file_description',
      'insert_class' => '',
      'insert_width' => '',
      'label' => 'Inline Files',
      'weight' => '12',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_os_inline_image
  $fields['announcement-field_os_inline_image'] = array(
    'field_name' => 'field_os_inline_image',
    'type_name' => 'announcement',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'jpg jpeg png gif',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '128M',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'insert' => 1,
      'insert_styles' => array(
        'image' => 'image',
        'imagecache_image_s' => 'imagecache_image_s',
        'imagecache_inline_default' => 'imagecache_inline_default',
        'imagecache_inline_larger' => 'imagecache_inline_larger',
        'auto' => 0,
        'link' => 0,
        'os_file_description' => 0,
        'imagecache_AttachmentThumbnail' => 0,
        'imagecache_book_cover' => 0,
        'imagecache_book_cover_thumb' => 0,
        'imagecache_gallery_small_thumb' => 0,
        'imagecache_gallery_thumb' => 0,
        'imagecache_openscholar_front_logo' => 0,
        'imagecache_presentation_thumb' => 0,
        'imagecache_square_35_35' => 0,
        'imagecache_square_50_50' => 0,
        'imagecache_thumb' => 0,
        'imagecache_vsite_design_default_logo' => 0,
        'imagecache_vsite_design_landscape_logo' => 0,
        'imagecache_vsite_design_portrait_logo' => 0,
        'imagecache_vsite_design_square_logo' => 0,
        'imagecache_vsite_shields_default_shield' => 0,
      ),
      'insert_default' => 'imagecache_inline_default',
      'insert_class' => '',
      'insert_width' => '',
      'wysiwyg_fields_status' => 1,
      'wysiwyg_fields_icon' => 'd50522754f0bc7cc44d2f5231a467fe8',
      'wysiwyg_fields_formatters' => array(
        'default' => 'default',
      ),
      'wysiwyg_fields_hide' => 1,
      'wysiwyg_fields_delete' => 0,
      'filefield_sources' => array(
        'remote' => 'remote',
        'reference' => 'reference',
        'attach' => 0,
      ),
      'filefield_source_attach_path' => 'file_attach',
      'filefield_source_attach_absolute' => '0',
      'filefield_source_attach_mode' => 'move',
      'filefield_source_autocomplete' => '1',
      'label' => 'Inline Image',
      'weight' => '10',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_os_inline_oembed
  $fields['announcement-field_os_inline_oembed'] = array(
    'field_name' => 'field_os_inline_oembed',
    'type_name' => 'announcement',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '1',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'wysiwyg_fields_status' => 1,
      'wysiwyg_fields_icon' => 'bd515d035a09ee9d2f923e7a9ee8dd9e',
      'wysiwyg_fields_formatters' => array(
        'oembed_default_default' => 'oembed_default_default',
      ),
      'wysiwyg_fields_hide' => 1,
      'wysiwyg_fields_delete' => 0,
      'default_value' => array(
        '0' => array(
          'url' => '',
          'wysiwyg_fields_formatters' => 'oembedfield_formatter_oembed_default',
          'wysiwyg_fields' => array(
            'wysiwyg_fields_delta' => 0,
            'wysiwyg_fields_formatters' => 'oembedfield_formatter_oembed_default',
            'wysiwyg_fields_insert' => 'Insert',
            'wysiwyg_fields_select' => 0,
          ),
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Inline Media',
      'weight' => '14',
      'description' => 'Enter the URL of a video or other shareable resource and it will be embedded in the page. If the video doesn\'t appear after saving, refresh the page.',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Inline Files');
  t('Inline Image');
  t('Inline Media');

  return $fields;
}
