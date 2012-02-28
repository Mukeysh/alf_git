/*
 * If the TinyMCE wysiwyg files are loaded after the document is ready, it fails to initialize properly
 */
Drupal.behaviors.AAATinyMceInitFailsafe = function(ctx) {
	if (typeof tinymce != 'undefined') {
		tinymce.dom.Event._pageInit();
	}

	if ($('.wysiwyg', ctx).length) {
		$('#modalContent #edit-submit', ctx).mouseover(function (e) {
			if (tinyMCE) {
				tinyMCE.triggerSave();
			}
		});
	}
}

Drupal.behaviors.osWysiwygHideTips = function (ctx) {
	// don't do this for every thing
	if (ctx != document) return;
	function toggle (e) {
		$('.tips', ctx).toggle();
	}
	$('.tips', ctx).hide();
	$('#wysiwyg-toggle-edit-body', ctx).die('click', toggle).live('click', toggle);
};

Drupal.behaviors.osWysiwygAddHelpLink = function (ctx) {
	var fields = $('input[class*="wysiwyg-field"], div[class*="wysiwyg-field"]'),
		$cont, $this, handled = {}, $fieldset, classes, i, id;
	
	fields.each(function (i) {
		$this = $(this);
		classes = $this.attr('class').split(' ');
		for (i in classes) {
			if (classes[i].indexOf('wysiwyg-field-') > -1) {
				id = classes[i].replace('wysiwyg-field-', '');
				break;
			}
		}
		if (typeof handled[id] == 'undefined') {
			$('#'+id+'-wrapper').css('position', 'relative').prepend($('<a class="help advanced-help-link" href="'+Drupal.settings.basePath+'help/vsitehelp/Editing-Content">Help</a>'));
			$('#'+id+'-wrapper').find('a.help').click(function (e) {
				window.open(this.href+'?popup=1', 'advanced-help-window', 'width=500,height=500,scrollbars,resizable').focus();
				e.preventDefault();
			});
			handled[id] = true;
		}
	});
};

Drupal.behaviors.osWysiwygFormattingInWindow = function (ctx) {
	var format;
	// get the existing format
	$('div.wysiwyg, input.wysiwyg[checked="checked"]').each(function () {
		var classes = $(this).attr('class').split(' '),
			i;
		for (i in classes) {
			if (classes[i].indexOf('wysiwyg-format-') > -1) {
				format = classes[i].replace('wysiwyg-format-', '');
				break;
			}
		}
	});
	
	function open(e) {
		window.open(this.href+'/'+format+'?modal', 'advanced-help-window', 'width=500,height=500,scrollbars,resizable').focus();
		e.preventDefault();
	}
	
	$('a[href$="filter/tips"]', ctx).unbind('click', open).click(open);
};

/**
 * Apply styling to body fields that have wysiwyg's so that when they are detached the body looks ok
 */
Drupal.behaviors.osWysiwygFormSave = function(context) {

  $('.wysiwyg-editor-tinymce:not(.os-wysiwyg-processed)', context).each(function() {
	var params = Drupal.wysiwyg.getParams(this);
    var $this = $(this).addClass('os-wysiwyg-processed');
    
    $('#' + params.field).filter(":visible").parents('form').submit(function (event) {
      
      // Do not call if the event was cancelled.
      if (event.originalEvent.returnValue === false) {
        return;
      }
      
      overlayPosition = $('#' + params.field).position();
      overlayWidth = $('#' + params.field).css('width');
      
      $('#' + params.field).css('opacity',0.25).before('<b style="background: rgba(FF, FF, FF, 0.8);color:#000;top: '+overlayPosition.top+';display: block;position: absolute;text-align: center;margin: 0;margin-top: 40px;width: '+overlayWidth+';left: '+overlayPosition.left+';font-size: 15px;">Saving <a class="ctools-ajaxing" onclick="return false;"> &nbsp; </a></b>');
    });
  });
};