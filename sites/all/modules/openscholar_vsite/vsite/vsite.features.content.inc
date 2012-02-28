<?php

/**
 * Implementation of hook_content_default_fields().
 */
function vsite_content_default_fields() {
  $fields = array();

  // Exported field: field_vsite_address
  $fields['vsite-field_vsite_address'] = array(
    'field_name' => 'field_vsite_address',
    'type_name' => 'vsite',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'change' => 'Change basic information',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_address][0][value',
        ),
      ),
      'default_value_php' => '',
      'default_value_widget' => NULL,
      'group' => FALSE,
      'required' => 0,
      'multiple' => '0',
      'text_processing' => '0',
      'max_length' => '',
      'allowed_values' => '',
      'allowed_values_php' => '',
      'op' => 'Save field settings',
      'widget_module' => 'text',
      'columns' => array(
        'value' => array(
          'type' => 'text',
          'size' => 'big',
          'not null' => FALSE,
          'sortable' => TRUE,
          'views' => TRUE,
        ),
      ),
      'label' => 'Address',
      'weight' => '30',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_vsite_logo
  $fields['vsite-field_vsite_logo'] = array(
    'field_name' => 'field_vsite_logo',
    'type_name' => 'vsite',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
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
      'default_image' => array(
        'filename' => 'default_logo.jpg',
        'filepath' => 'sites/all/modules/openscholar_vsite/vsite_design/theme/images/default_logo.jpg',
        'filemime' => 'image/jpeg',
        'source' => 'default_image_upload',
        'filesize' => 37046,
        'uid' => '1',
        'status' => 1,
        'timestamp' => 1253894074,
        'origname' => '',
        'fid' => '23',
      ),
      'use_default_image' => 1,
      'collapsible' => '2',
      'resolution' => '180x140',
      'enforce_ratio' => 1,
      'croparea' => '400x400',
      'enforce_minimum' => NULL,
      'label' => 'Site logo',
      'weight' => '31',
      'description' => '',
      'type' => 'imagefield_crop_widget',
      'module' => 'imagefield_crop',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Address');
  t('Site logo');

  return $fields;
}
