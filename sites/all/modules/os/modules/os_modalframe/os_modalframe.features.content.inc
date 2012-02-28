<?php

/**
 * Implementation of hook_content_default_fields().
 */
function os_modalframe_content_default_fields() {
  $fields = array();

  // Exported field: field_link_from_image
  $fields['modal_image-field_link_from_image'] = array(
    'field_name' => 'field_link_from_image',
    'type_name' => 'modal_image',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
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
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
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
    'url' => 'optional',
    'title' => 'value',
    'title_value' => '[os_modalframe_image_src]',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'wysiwyg_fields_status' => 0,
      'wysiwyg_fields_icon' => '6f7621a02161e347e66d99d8ace540a3',
      'wysiwyg_fields_formatters' => array(),
      'wysiwyg_fields_hide' => 1,
      'wysiwyg_fields_delete' => 1,
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Link From Image',
      'weight' => '-1',
      'description' => 'Enter a URL to link the image to. ',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_modal_image
  $fields['modal_image-field_modal_image'] = array(
    'field_name' => 'field_modal_image',
    'type_name' => 'modal_image',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
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
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'resolution' => '0',
      'enforce_ratio' => 0,
      'croparea' => '500x500',
      'enforce_minimum' => 0,
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
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
      'wysiwyg_fields_status' => 0,
      'wysiwyg_fields_icon' => '6f7621a02161e347e66d99d8ace540a3',
      'wysiwyg_fields_formatters' => array(),
      'wysiwyg_fields_hide' => 1,
      'wysiwyg_fields_delete' => 1,
      'label' => 'Image',
      'weight' => '-4',
      'description' => 'Upload an image, and then select the area of the image you wish to display. The final result you see here will then be scaled to the width you select below.',
      'type' => 'imagefield_crop_widget',
      'module' => 'imagefield_crop',
    ),
  );

  // Exported field: field_modal_image_size
  $fields['modal_image-field_modal_image_size'] = array(
    'field_name' => 'field_modal_image_size',
    'type_name' => 'modal_image',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
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
    'type' => 'number_integer',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '150|150 pixels
200|200 pixels
300|300 pixels
500|500 pixels
900|900 pixels',
    'allowed_values_php' => '',
    'widget' => array(
      'wysiwyg_fields_status' => 0,
      'wysiwyg_fields_icon' => '6f7621a02161e347e66d99d8ace540a3',
      'wysiwyg_fields_formatters' => array(),
      'wysiwyg_fields_hide' => 1,
      'wysiwyg_fields_delete' => 1,
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Image Size',
      'weight' => '-3',
      'description' => 'Select a width to set the above image to when it\'s displayed.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Image');
  t('Image Size');
  t('Link From Image');

  return $fields;
}
