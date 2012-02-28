(function ($) {
  Drupal.wysiwyg.plugins['wysiwyg_fields_field_os_inline_oembed'] = {

    /**
     * Return whether the passed node belongs to this plugin.
     */
    isNode: function(node) {
      return Drupal.wysiwygFields.wysiwygIsNode('field_os_inline_oembed', node);
    },

    /**
     * Execute the button.
     */
    invoke: function(data, settings, instanceId) {
      Drupal.wysiwygFields.wysiwygInvoke('field_os_inline_oembed', data, settings, instanceId);
    },

    /**
     * Create wysiwyg_imagefield dialog window.
     */
    attach: function(content, settings, instanceId) {
      Drupal.wysiwygFields.init('field_os_inline_oembed');
      return Drupal.wysiwygFields.wysiwygAttach('field_os_inline_oembed', content, settings, instanceId);
    },

    /**
     *
     */
    detach: function(content, settings, instanceId) {
      return Drupal.wysiwygFields.wysiwygDetach('field_os_inline_oembed', content, settings, instanceId);
    }

  }
})(jQuery);
