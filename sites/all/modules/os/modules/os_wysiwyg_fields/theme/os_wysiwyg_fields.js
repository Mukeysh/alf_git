/**
 * Overrides some of wysiwyg_fields' functions to be more intuitive
 */
(function ($) {
	if (typeof Drupal.wysiwyg == 'undefined')
		return;
	
	function cleanUp(id) {
		// click the Expand button and remove it.
		// the only reason it would be needed is if the user had dozens of videos
		// which is an edge case at best.
		var btn = $('#wysiwyg_fields-' + id + '-dialog .ui-dialog-titlebar .wysiwyg_fields-icon-expand').hide();
		if (1 && id == 'field_os_inline_oembed') {
			btn.click();
		}
		
		// remove the Insert button added by wysiwyg_fields.
		// The button provided by Insert is more useful for filefields.
		$('#wysiwyg_fields-' + id + '-dialog .ui-dialog-buttonpane').not('#wysiwyg_fields-field_os_inline_oembed-dialog .ui-dialog-buttonpane').remove();
	}
	
	// store the current functions
	// we need to run our cleanUp function after the dialogs are opened.
	// save the old ones so we can replace them.
	var dialogShowDefaultOld = Drupal.wysiwygFields.dialogShowDefault,
		dialogShowUpdateOld = Drupal.wysiwygFields.dialogShowUpdate;
	
	// overwrite current functions with new ones that call the current funcs and tweak the results.
	Drupal.wysiwygFields.dialogShowDefault = function (id) {
		dialogShowDefaultOld.call(Drupal.wysiwygFields, id);
		cleanUp(id);
	}
	
	Drupal.wysiwygFields.dialogShowUpdate = function (id) {
		dialogShowUpdateOld.call(Drupal.wysiwygFields, id);
		cleanUp(id);
	}
	
	/**
	 * Adjusts wysiwyg settings:
	 * Does a number of things:
	 * 	1. Changes the text on the enable/disable link
	 * 	2. Adds span ids and iframes to the valid elements list
	 * 	3. Moves the button provided by Insert next to the Remove button provided by Filefield
	 * 		It looks better this way
	 * 	4. Adds an event handler to tinyMCE so that the links in oembed content don't go anywhere
	 */
	var hasRun = false;
	Drupal.behaviors.adjustWysiwygSettings = function () {
		
		Drupal.settings.wysiwyg.enable = 'Rich-text Editor View';
		Drupal.settings.wysiwyg.disable = 'HTML View';
		
		// set extended valid settings to include id for spans
		// prevents error with inserted items ending up in helper elements that are removed later
		// run this every time incase an ahah call replaces it
		var settings = Drupal.settings.wysiwyg.configs.tinymce;
		
		if (typeof settings.format1 == 'object')
			settings = settings.format1;
		else if (typeof settings.format6 == 'object')
			settings = settings.format6;
		else if (typeof settings.format5 == 'object') 
			settings = settings.format5;
		else return;
		
		// adds span ids and iframes to the valid elements list
		// adding iframes is necessary so that oembed code isn't stripped out by the editor
		// before wysiwyg_fields can convert it into a token
		var eve = settings.extended_valid_elements.split(',');
		jQuery.each(eve, function(i, item) {
			if (item.indexOf('span') != -1 && item.indexOf('id') == -1) {
				var t = item;
				t = t.replace('span[', '').replace(']','').split('|');
				t.push('id');
				eve[i] = 'span['+t.join('|')+']';
			}
		});
		settings.extended_valid_elements = eve.join(',');
	    
		if (hasRun) {
			// pull the Insert button out of a div and next to remove
			$('.widget-edit:visible').each(function (item) {
				var btn = this.getElementsByClassName('insert-button')[0];
				if (!btn) return;
				btn.parentNode.removeChild(btn);
				
				$('input[value="Remove"]', this).before(btn);
			});
		}
		else {
			// prevent links in oembed code from going anywhere
			// double layered event handler
			tinyMCE.onAddEditor.add(function () {
				tinyMCE.activeEditor.onClick.add(function (ed, e) {
					var targ = e.target || e.srcElement;
					while (targ.contentEditable == 'inherit') {
						targ = targ.parentNode;
					}
					if (targ.contentEditable == 'false') {
						this.selection.select(targ);
						e.preventDefault();
						return false;
					}
				});
			});
		}
		hasRun = true;
	};
})(jQuery);