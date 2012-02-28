<?php

/**
 * Implementation of hook_content_default_fields().
 */
function scholar_image_gallery_content_default_fields() {
  $fields = array();

  // Exported field: field_gallery
  $fields['image-field_gallery'] = array(
    'field_name' => 'field_gallery',
    'type_name' => 'image',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'gallery' => 'gallery',
      'announcement' => 0,
      'support_answer' => 0,
      'blog' => 0,
      'book' => 0,
      'class' => 0,
      'class_material' => 0,
      'event' => 0,
      'feature_request' => 0,
      'feed' => 0,
      'image' => 0,
      'link' => 0,
      'page' => 0,
      'profile' => 0,
      'biblio' => 0,
      'support_question' => 0,
      'vsite' => 0,
      'scholar_software_project' => 0,
      'scholar_software_release' => 0,
      'vsite_users_profile' => 0,
      'bio' => 0,
      'cv' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 1,
        'full' => 1,
        'title' => 'Add image',
        'hover_title' => 'Add a new image to this gallery',
        'destination' => 'node',
      ),
      'fallback' => 'select',
      'edit_fallback' => NULL,
      'wysiwyg_fields_status' => 0,
      'wysiwyg_fields_icon' => '6f7621a02161e347e66d99d8ace540a3',
      'wysiwyg_fields_formatters' => array(),
      'wysiwyg_fields_hide' => 1,
      'wysiwyg_fields_delete' => 1,
      'label' => 'Gallery',
      'weight' => '-3',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_gallery_image
  $fields['image-field_gallery_image'] = array(
    'field_name' => 'field_gallery_image',
    'type_name' => 'image',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'thumb_linked',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'reg_linked',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'reg_linked',
      ),
      '2' => array(
        'format' => 'reg_linked',
      ),
      '3' => array(
        'format' => 'reg_linked',
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'jpg jpeg png gif',
      'file_path' => 'images',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '2M',
      'max_filesize_per_node' => '',
      'max_resolution' => '1024x768',
      'min_resolution' => 0,
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'wysiwyg_fields_status' => NULL,
      'wysiwyg_fields_icon' => NULL,
      'wysiwyg_fields_formatters' => NULL,
      'wysiwyg_fields_hide' => NULL,
      'wysiwyg_fields_delete' => NULL,
      'filefield_sources' => NULL,
      'filefield_source_attach_path' => NULL,
      'filefield_source_attach_absolute' => NULL,
      'filefield_source_attach_mode' => NULL,
      'filefield_source_autocomplete' => NULL,
      'insert' => 0,
      'insert_styles' => array(
        'auto' => 0,
        'link' => 0,
        'image' => 0,
        'imagecache_AttachmentThumbnail' => 0,
        'imagecache_book_cover' => 0,
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
      ),
      'insert_default' => 'auto',
      'insert_class' => '',
      'insert_width' => '',
      'label' => 'Image',
      'weight' => '-4',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Gallery');
  t('Image');

  return $fields;
}
