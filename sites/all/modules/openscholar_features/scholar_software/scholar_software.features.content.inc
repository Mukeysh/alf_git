<?php

/**
 * Implementation of hook_content_default_fields().
 */
function scholar_software_content_default_fields() {
  $fields = array();

  // Exported field: field_os_inline_files
  $fields['scholar_software_project-field_os_inline_files'] = array(
    'field_name' => 'field_os_inline_files',
    'type_name' => 'scholar_software_project',
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
      'weight' => '13',
      'description' => 'Upload a file and enter a description. Your file will be linked with the description as it\'s text.',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_os_inline_image
  $fields['scholar_software_project-field_os_inline_image'] = array(
    'field_name' => 'field_os_inline_image',
    'type_name' => 'scholar_software_project',
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
      'weight' => '9',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_os_inline_oembed
  $fields['scholar_software_project-field_os_inline_oembed'] = array(
    'field_name' => 'field_os_inline_oembed',
    'type_name' => 'scholar_software_project',
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
      'weight' => '11',
      'description' => 'Enter the URL of a video or other shareable resource and it will be embedded in the page. For a list of shareable resource providers, visit <a href="http://embed.ly/providers">http://embed.ly/providers</a>. If the video doesn\'t appear after saving, refresh the page.',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_scholar_software_logo
  $fields['scholar_software_project-field_scholar_software_logo'] = array(
    'field_name' => 'field_scholar_software_logo',
    'type_name' => 'scholar_software_project',
    'display_settings' => array(
      'weight' => '-9',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '',
    'list_default' => '',
    'description_field' => '',
    'widget' => array(
      'file_extensions' => NULL,
      'file_path' => NULL,
      'progress_indicator' => NULL,
      'max_filesize_per_file' => NULL,
      'max_filesize_per_node' => NULL,
      'max_resolution' => NULL,
      'min_resolution' => NULL,
      'alt' => NULL,
      'custom_alt' => NULL,
      'title' => NULL,
      'custom_title' => NULL,
      'title_type' => NULL,
      'default_image' => NULL,
      'use_default_image' => NULL,
      'label' => 'Logo',
      'weight' => '-10',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_scholar_software_method
  $fields['scholar_software_project-field_scholar_software_method'] = array(
    'field_name' => 'field_scholar_software_method',
    'type_name' => 'scholar_software_project',
    'display_settings' => array(
      'weight' => '-12',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
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
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => 'return scholar_software_cck_options("method");',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Packaging method',
      'weight' => '-12',
      'description' => 'Choose the packaging method used for this project.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_scholar_software_name
  $fields['scholar_software_project-field_scholar_software_name'] = array(
    'field_name' => 'field_scholar_software_name',
    'type_name' => 'scholar_software_project',
    'display_settings' => array(
      'weight' => '-10',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
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
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '30',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_scholar_software_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Software key',
      'weight' => '-11',
      'description' => 'The machine-readable name for your project. This name must contain only lowercase letters, numbers, and underscores. <strong>Example:</strong> cooking_recipes.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_scholar_software_repo
  $fields['scholar_software_project-field_scholar_software_repo'] = array(
    'field_name' => 'field_scholar_software_repo',
    'type_name' => 'scholar_software_project',
    'display_settings' => array(
      'weight' => '-8',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_scholar_software_repo][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Repository URL',
      'weight' => '-9',
      'description' => 'Example: http://r.harvard.edu/src/PACKAGE.CookingRecipes',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_os_inline_files
  $fields['scholar_software_release-field_os_inline_files'] = array(
    'field_name' => 'field_os_inline_files',
    'type_name' => 'scholar_software_release',
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
      'weight' => '106',
      'description' => 'Upload a file and enter a description. Your file will be linked with the description as it\'s text.',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_os_inline_image
  $fields['scholar_software_release-field_os_inline_image'] = array(
    'field_name' => 'field_os_inline_image',
    'type_name' => 'scholar_software_release',
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
      'weight' => '102',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_os_inline_oembed
  $fields['scholar_software_release-field_os_inline_oembed'] = array(
    'field_name' => 'field_os_inline_oembed',
    'type_name' => 'scholar_software_release',
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
      'weight' => '104',
      'description' => 'Enter the URL of a video or other shareable resource and it will be embedded in the page. For a list of shareable resource providers, visit <a href="http://embed.ly/providers">http://embed.ly/providers</a>. If the video doesn\'t appear after saving, refresh the page.',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_scholar_software_file
  $fields['scholar_software_release-field_scholar_software_file'] = array(
    'field_name' => 'field_scholar_software_file',
    'type_name' => 'scholar_software_release',
    'display_settings' => array(
      'weight' => '-13',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
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
      'file_extensions' => 'tgz tar gz zip',
      'file_path' => 'scholar_software',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Package',
      'weight' => '-13',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_scholar_software_project
  $fields['scholar_software_release-field_scholar_software_project'] = array(
    'field_name' => 'field_scholar_software_project',
    'type_name' => 'scholar_software_release',
    'display_settings' => array(
      'weight' => '-11',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
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
      'scholar_software_project' => 'scholar_software_project',
      'announcement' => 0,
      'blog' => 0,
      'book' => 0,
      'class' => 0,
      'class_material' => 0,
      'event' => 0,
      'feed' => 0,
      'gallery' => 0,
      'image' => 0,
      'link' => 0,
      'page' => 0,
      'person' => 0,
      'profile' => 0,
      'biblio' => 0,
      'vsite' => 0,
      'scholar_software_release' => 0,
      'vsite_users_profile' => 0,
      'bio' => 0,
      'cv' => 0,
    ),
    'advanced_view' => 'scholar_software_releaseprojects',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Project',
      'weight' => '-11',
      'description' => '',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_scholar_software_recommend
  $fields['scholar_software_release-field_scholar_software_recommend'] = array(
    'field_name' => 'field_scholar_software_recommend',
    'type_name' => 'scholar_software_release',
    'display_settings' => array(
      'weight' => '-6',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => 'return scholar_software_cck_options(\'recommended\');',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Recommended',
      'weight' => '-6',
      'description' => 'The recommended releases will be displayed on the project page. The latest recommended release per major version will be offered for update status.',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_scholar_software_security
  $fields['scholar_software_release-field_scholar_software_security'] = array(
    'field_name' => 'field_scholar_software_security',
    'type_name' => 'scholar_software_release',
    'display_settings' => array(
      'weight' => '-5',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => 'return scholar_software_cck_options(\'security\');',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 'Not a security release',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Security release',
      'weight' => '-5',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_versionextra
  $fields['scholar_software_release-field_versionextra'] = array(
    'field_name' => 'field_versionextra',
    'type_name' => 'scholar_software_release',
    'display_settings' => array(
      'weight' => '-7',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '20',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_versionextra][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Extra version',
      'weight' => '-7',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_versionmajor
  $fields['scholar_software_release-field_versionmajor'] = array(
    'field_name' => 'field_versionmajor',
    'type_name' => 'scholar_software_release',
    'display_settings' => array(
      'weight' => '-9',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '0',
    'max' => '500',
    'allowed_values' => '',
    'allowed_values_php' => 'return scholar_software_cck_options(\'major\');',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Major version',
      'weight' => '-9',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_versionpatch
  $fields['scholar_software_release-field_versionpatch'] = array(
    'field_name' => 'field_versionpatch',
    'type_name' => 'scholar_software_release',
    'display_settings' => array(
      'weight' => '-8',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => 0,
    'max' => 500,
    'allowed_values' => '',
    'allowed_values_php' => 'return scholar_software_cck_options(\'patch\');',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Patch version',
      'weight' => '-8',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Extra version');
  t('Inline Files');
  t('Inline Image');
  t('Inline Media');
  t('Logo');
  t('Major version');
  t('Package');
  t('Packaging method');
  t('Patch version');
  t('Project');
  t('Recommended');
  t('Repository URL');
  t('Security release');
  t('Software key');

  return $fields;
}
