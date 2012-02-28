<?php

/**
 * Implementation of hook_strongarm().
 */
function os_wysiwyg_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'better_formats_per_node_type';
  $strongarm->value = 1;
  $export['better_formats_per_node_type'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'embedfilter_filtertip';
  $strongarm->value = 'You can use &lt;object>, &lt;embed> and &lt;script> tags from the following sites to add media to your posts. You must disable the rich text editor for this to work.';
  $export['embedfilter_filtertip'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'embedfilter_host_whitelist';
  $strongarm->value = 'localhost
youtube.com
flicker.com
twitter.com
facebook.com
google.com
yahoo.com
gmodules.com
harvard.edu
statcounter.com';
  $export['embedfilter_host_whitelist'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_default_format';
  $strongarm->value = '1';
  $export['filter_default_format'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_html_1';
  $strongarm->value = '1';
  $export['filter_html_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_html_help_1';
  $strongarm->value = 1;
  $export['filter_html_help_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_html_nofollow_1';
  $strongarm->value = 0;
  $export['filter_html_nofollow_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'format';
  $strongarm->value = '6';
  $export['format'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembed_maxheight_1';
  $strongarm->value = '';
  $export['oembed_maxheight_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembed_maxheight_2';
  $strongarm->value = '';
  $export['oembed_maxheight_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembed_maxheight_6';
  $strongarm->value = '';
  $export['oembed_maxheight_6'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembed_maxwidth_1';
  $strongarm->value = '440';
  $export['oembed_maxwidth_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembed_maxwidth_2';
  $strongarm->value = '440';
  $export['oembed_maxwidth_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembed_maxwidth_6';
  $strongarm->value = '440';
  $export['oembed_maxwidth_6'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_box_1';
  $strongarm->value = array(
    'margin-right' => 'margin-right',
    'margin-left' => 'margin-left',
    'padding' => 'padding',
    'padding-top' => 'padding-top',
    'padding-right' => 'padding-right',
    'padding-bottom' => 'padding-bottom',
    'padding-left' => 'padding-left',
    'margin' => 0,
    'margin-top' => 0,
    'margin-bottom' => 0,
  );
  $export['wysiwyg_filter_styles_box_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_box_5';
  $strongarm->value = array(
    'margin-right' => 'margin-right',
    'margin-left' => 'margin-left',
    'padding' => 'padding',
    'padding-top' => 'padding-top',
    'padding-right' => 'padding-right',
    'padding-bottom' => 'padding-bottom',
    'padding-left' => 'padding-left',
    'margin' => 0,
    'margin-top' => 0,
    'margin-bottom' => 0,
  );
  $export['wysiwyg_filter_styles_box_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_box_6';
  $strongarm->value = array(
    'margin-right' => 'margin-right',
    'margin-left' => 'margin-left',
    'padding' => 'padding',
    'padding-top' => 'padding-top',
    'padding-right' => 'padding-right',
    'padding-bottom' => 'padding-bottom',
    'padding-left' => 'padding-left',
    'margin' => 0,
    'margin-top' => 0,
    'margin-bottom' => 0,
  );
  $export['wysiwyg_filter_styles_box_6'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_color_1';
  $strongarm->value = array(
    'color' => 'color',
    'background' => 0,
    'background-color' => 0,
    'background-image' => 0,
    'background-repeat' => 0,
    'background-attachment' => 0,
    'background-position' => 0,
  );
  $export['wysiwyg_filter_styles_color_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_color_5';
  $strongarm->value = array(
    'color' => 'color',
    'background' => 0,
    'background-color' => 0,
    'background-image' => 0,
    'background-repeat' => 0,
    'background-attachment' => 0,
    'background-position' => 0,
  );
  $export['wysiwyg_filter_styles_color_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_color_6';
  $strongarm->value = array(
    'color' => 'color',
    'background' => 0,
    'background-color' => 0,
    'background-image' => 0,
    'background-repeat' => 0,
    'background-attachment' => 0,
    'background-position' => 0,
  );
  $export['wysiwyg_filter_styles_color_6'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_dimension_1';
  $strongarm->value = array(
    'height' => 'height',
    'width' => 'width',
    'line-height' => 0,
    'max-height' => 0,
    'max-width' => 0,
    'min-height' => 0,
    'min-width' => 0,
  );
  $export['wysiwyg_filter_styles_dimension_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_dimension_5';
  $strongarm->value = array(
    'height' => 'height',
    'width' => 'width',
    'line-height' => 0,
    'max-height' => 0,
    'max-width' => 0,
    'min-height' => 0,
    'min-width' => 0,
  );
  $export['wysiwyg_filter_styles_dimension_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_dimension_6';
  $strongarm->value = array(
    'height' => 'height',
    'width' => 'width',
    'line-height' => 0,
    'max-height' => 0,
    'max-width' => 0,
    'min-height' => 0,
    'min-width' => 0,
  );
  $export['wysiwyg_filter_styles_dimension_6'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_font_1';
  $strongarm->value = array(
    'font' => 'font',
    'font-family' => 'font-family',
    'font-size' => 'font-size',
    'font-size-adjust' => 0,
    'font-stretch' => 0,
    'font-style' => 0,
    'font-variant' => 0,
    'font-weight' => 0,
  );
  $export['wysiwyg_filter_styles_font_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_font_5';
  $strongarm->value = array(
    'font' => 'font',
    'font-family' => 'font-family',
    'font-size' => 'font-size',
    'font-weight' => 'font-weight',
    'font-size-adjust' => 0,
    'font-stretch' => 0,
    'font-style' => 0,
    'font-variant' => 0,
  );
  $export['wysiwyg_filter_styles_font_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_font_6';
  $strongarm->value = array(
    'font' => 'font',
    'font-family' => 'font-family',
    'font-size' => 'font-size',
    'font-style' => 'font-style',
    'font-size-adjust' => 0,
    'font-stretch' => 0,
    'font-variant' => 0,
    'font-weight' => 0,
  );
  $export['wysiwyg_filter_styles_font_6'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_layout_1';
  $strongarm->value = array(
    'display' => 'display',
    'float' => 'float',
    'clear' => 0,
    'position' => 0,
    'visibility' => 0,
  );
  $export['wysiwyg_filter_styles_layout_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_layout_5';
  $strongarm->value = array(
    'display' => 'display',
    'float' => 'float',
    'clear' => 0,
    'position' => 0,
    'visibility' => 0,
  );
  $export['wysiwyg_filter_styles_layout_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_layout_6';
  $strongarm->value = array(
    'display' => 'display',
    'float' => 'float',
    'clear' => 0,
    'position' => 0,
    'visibility' => 0,
  );
  $export['wysiwyg_filter_styles_layout_6'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_text_1';
  $strongarm->value = array(
    'text-align' => 'text-align',
    'text-decoration' => 'text-decoration',
    'text-indent' => 'text-indent',
    'text-transform' => 0,
    'letter-spacing' => 0,
    'word-spacing' => 0,
    'white-space' => 0,
    'direction' => 0,
    'unicode-bidi' => 0,
  );
  $export['wysiwyg_filter_styles_text_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_text_5';
  $strongarm->value = array(
    'text-align' => 'text-align',
    'text-decoration' => 'text-decoration',
    'text-indent' => 'text-indent',
    'text-transform' => 0,
    'letter-spacing' => 0,
    'word-spacing' => 0,
    'white-space' => 0,
    'direction' => 0,
    'unicode-bidi' => 0,
  );
  $export['wysiwyg_filter_styles_text_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_styles_text_6';
  $strongarm->value = array(
    'text-align' => 'text-align',
    'text-decoration' => 'text-decoration',
    'text-indent' => 0,
    'text-transform' => 0,
    'letter-spacing' => 0,
    'word-spacing' => 0,
    'white-space' => 0,
    'direction' => 0,
    'unicode-bidi' => 0,
  );
  $export['wysiwyg_filter_styles_text_6'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_elements_parsed_1';
  $strongarm->value = array(
    'a' => array(
      'href' => array(
        'required' => TRUE,
      ),
      'target' => array(
        'values' => array(
          0 => '_blank',
        ),
      ),
      'title' => array(),
      'id' => array(),
      'class' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'address' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'b' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'blockquote' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'br' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'caption' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'cite' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'code' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'dd' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'div' => array(
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'justify',
          2 => 'left',
          3 => 'right',
        ),
      ),
      'style' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'dl' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'dt' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'em' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'embed' => array(
      '*' => array(),
    ),
    'h2' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'h3' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'h4' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'h5' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'h6' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'i' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'iframe' => array(
      '*' => array(),
    ),
    'img' => array(
      'src' => array(
        'required' => TRUE,
      ),
      'width' => array(),
      'height' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'li' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'object' => array(
      '*' => array(),
    ),
    'ol' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'p' => array(
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'justify',
          2 => 'left',
          3 => 'right',
        ),
      ),
      'style' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'param' => array(
      '*' => array(),
    ),
    'pre' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'script' => array(
      'src' => array(),
      'type' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'span' => array(
      'id' => array(),
      'style' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'strike' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'strong' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'sub' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'sup' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'table' => array(
      'style' => array(),
      'border' => array(),
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'left',
          2 => 'right',
        ),
      ),
      'cellpadding' => array(),
      'cellspacing' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'td' => array(
      'colspan' => array(),
      'rowspan' => array(),
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'justify',
          2 => 'left',
          3 => 'right',
        ),
      ),
      'valign' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'tr' => array(
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'justify',
          2 => 'left',
          3 => 'right',
        ),
      ),
      'valign' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'u' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'ul' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
  );
  $export['wysiwyg_filter_valid_elements_parsed_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_elements_parsed_5';
  $strongarm->value = array(
    'a' => array(
      'href' => array(
        'required' => TRUE,
      ),
      'target' => array(
        'values' => array(
          0 => '_blank',
        ),
      ),
      'title' => array(),
      'style' => array(),
      'class' => array(),
      'id' => array(),
    ),
    'b' => array(
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'blockquote' => array(
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'br' => array(
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'cite' => array(
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'code' => array(
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'dd' => array(
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'div' => array(
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'justify',
          2 => 'left',
          3 => 'right',
        ),
      ),
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'dl' => array(
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'dt' => array(
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'em' => array(
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'embed' => array(
      '*' => array(),
    ),
    'i' => array(
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'iframe' => array(
      '*' => array(),
    ),
    'img' => array(
      'src' => array(
        'required' => TRUE,
      ),
      'width' => array(),
      'height' => array(),
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'li' => array(
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'object' => array(
      'width' => array(),
      'height' => array(),
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'ol' => array(
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'p' => array(
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'justify',
          2 => 'left',
          3 => 'right',
        ),
      ),
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'param' => array(
      'name' => array(),
      'value' => array(),
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'span' => array(
      'id' => array(),
      'style' => array(),
      'class' => array(),
      'title' => array(),
    ),
    'strong' => array(
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
    'ul' => array(
      'style' => array(),
      'class' => array(),
      'id' => array(),
      'title' => array(),
    ),
  );
  $export['wysiwyg_filter_valid_elements_parsed_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_elements_parsed_6';
  $strongarm->value = array(
    'a' => array(
      'href' => array(
        'required' => TRUE,
      ),
      'target' => array(
        'values' => array(
          0 => '_blank',
        ),
      ),
      'title' => array(),
      'id' => array(),
      'class' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'address' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'blockquote' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'br' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'caption' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'cite' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'code' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'dd' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'div' => array(
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'justify',
          2 => 'left',
          3 => 'right',
        ),
      ),
      'style' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'dl' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'dt' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'em' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'embed' => array(
      '*' => array(),
    ),
    'h2' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'h3' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'h4' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'h5' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'h6' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'iframe' => array(
      '*' => array(),
    ),
    'img' => array(
      'src' => array(
        'required' => TRUE,
      ),
      'width' => array(),
      'height' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'li' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'object' => array(
      '*' => array(),
    ),
    'ol' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'p' => array(
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'justify',
          2 => 'left',
          3 => 'right',
        ),
      ),
      'style' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'param' => array(
      '*' => array(),
    ),
    'pre' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'script' => array(
      'src' => array(),
      'type' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'span' => array(
      'id' => array(),
      'style' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'strong' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'sub' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'sup' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'table' => array(
      'style' => array(),
      'border' => array(),
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'left',
          2 => 'right',
        ),
      ),
      'cellpadding' => array(),
      'cellspacing' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
    ),
    'td' => array(
      'colspan' => array(),
      'rowspan' => array(),
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'justify',
          2 => 'left',
          3 => 'right',
        ),
      ),
      'valign' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'tr' => array(
      'align' => array(
        'values' => array(
          0 => 'center',
          1 => 'justify',
          2 => 'left',
          3 => 'right',
        ),
      ),
      'valign' => array(),
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
    'ul' => array(
      'id' => array(),
      'class' => array(),
      'title' => array(),
      'dir' => array(
        'values' => array(
          0 => 'ltr',
          1 => 'rtl',
        ),
      ),
      'lang' => array(),
      'style' => array(),
    ),
  );
  $export['wysiwyg_filter_valid_elements_parsed_6'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_elements_raw_1';
  $strongarm->value = '@[id|class|title|dir<ltr?rtl|lang|style],
a[!href|target<_blank|title],
div[align<center?justify?left?right|style],
p[align<center?justify?left?right|style],
br,span[id|style],cite,code,blockquote,ul,ol,li,dl,dt,dd,img[!src|width|height],embed[*],object[*],param[*],script[src|type],iframe[*],
sup,sub,blockquote,
table[style|border|align<center?left?right|cellpadding|cellspacing],
tr[align<center?justify?left?right|valign],
td[colspan|rowspan|align<center?justify?left?right|valign],
caption,
address,h2,h3,h4,h5,h6,pre,
strong/b,em/i,strike,u';
  $export['wysiwyg_filter_valid_elements_raw_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_elements_raw_5';
  $strongarm->value = '@[style|class|id|title],
a[!href|target<_blank|title],
div[align<center?justify?left?right|style],
p[align<center?justify?left?right|style],
br,span[id|style],em/i,strong/b,cite,code,blockquote,ul,ol,li,dl,dt,dd,
object[width|height],param[name|value],embed[*],img[!src|width|height],iframe[*]';
  $export['wysiwyg_filter_valid_elements_raw_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_elements_raw_6';
  $strongarm->value = '@[id|class|title|dir<ltr?rtl|lang|style],
a[!href|target<_blank|title],
div[align<center?justify?left?right|style],
p[align<center?justify?left?right|style],
br,span[id|style],em,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,img[!src|width|height],embed[*],object[*],param[*],script[src|type],iframe[*],
sup,sub,blockquote,
table[style|border|align<center?left?right|cellpadding|cellspacing],
tr[align<center?justify?left?right|valign],
td[colspan|rowspan|align<center?justify?left?right|valign],
caption,
address,h2,h3,h4,h5,h6,pre';
  $export['wysiwyg_filter_valid_elements_raw_6'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_ids_1';
  $strongarm->value = array(
    0 => 'mce*',
  );
  $export['wysiwyg_filter_valid_ids_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_ids_5';
  $strongarm->value = array(
    0 => 'os-*',
  );
  $export['wysiwyg_filter_valid_ids_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wysiwyg_filter_valid_ids_6';
  $strongarm->value = array(
    0 => 'mce*',
  );
  $export['wysiwyg_filter_valid_ids_6'] = $strongarm;

  return $export;
}
