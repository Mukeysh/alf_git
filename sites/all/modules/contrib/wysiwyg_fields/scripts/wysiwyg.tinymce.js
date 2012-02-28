(function ($) {
  /**
   *
   */
  Drupal.wysiwygFields = Drupal.wysiwygFields || {};
  Drupal.wysiwygFields.wysiwyg = Drupal.wysiwygFields.wysiwyg || {};

  /**
   *
   */
  Drupal.wysiwygFields.wysiwyg.tinymce = {
    init: function(id) {
      // MCEditor icon size fix.
      $('.mce_wysiwyg_fields_' + id).addClass('mce_wysiwyg_fields_icon');
    },

    /**
     *
     */
    insert: function(instance, content) {
      tinyMCE.editors[instance].selection.setContent(content);
    },

    /**
     * @TODO - Remove IMG resize helper.
     */
    wysiwygIsNode: function(element) {
      var editor = tinyMCE.activeEditor,
      	range = editor.contentDocument.createRange(),
      	sel = editor.selection.getSel();

      // Create the range for the element.
      range.selectNode(element);

      // Select the range.
      if (sel.containsNode(element)) {
	      sel.removeAllRanges();
	      sel.addRange(range);
      }
    },
    
    selectNode: function(element) {
    	var editor = tinyMCE.activeEditor,
    		range = editor.contentDocument.createRange(),
    		sel = editor.selection.getSel();
    	
    	range.selectNode(element);
    	sel.removeAllRanges();
    	sel.addRange(range);
    },

    /**
     *
     */
    divToWysiwygField: function() {
      delete Drupal.settings.wysiwygFields.timer;
      var replacement;
      if (typeof tinyMCE !== "undefined") {
        $.each(tinyMCE.editors, function(instance) {
          if (typeof tinyMCE.editors[instance].contentDocument !== "undefined") {
            $('.wysiwyg_fields-placeholder', tinyMCE.editors[instance].contentDocument.body).each(function() {
              replacement = Drupal.settings.wysiwygFields.fields[$(this).attr('wf_field')].replacements[$(this).attr('wf_deltas')][$(this).attr('wf_formatter')];
              Drupal.wysiwygFields.wysiwyg.tinymce.selectNode(this);
              $(this).replaceWith(replacement);
            });
          }

          else {
            // Document not ready, reset timer.
            Drupal.wysiwygFields._wysiwygAttach();
          }
        });
      }

      else {
        // API not ready, reset timer.
        Drupal.wysiwygFields._wysiwygAttach();
      }
    }
  }
})(jQuery);
