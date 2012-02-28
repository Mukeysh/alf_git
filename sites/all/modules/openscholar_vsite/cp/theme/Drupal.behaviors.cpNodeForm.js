Drupal.behaviors.cpNodeForm = function() {

	if($('form#node-form fieldset.vt-advanced-options').length < 1){
	  $('form#node-form div.vertical-tabs').wrap('<fieldset class="vt-advanced-options collapsible collapsed" />');
	  $('form#node-form fieldset.vt-advanced-options').prepend('<legend>Advanced Options</legend>');
	}

	if (Drupal.modalFrameChild && typeof Drupal.modalFrameChild.newPage == 'undefined') {
		Drupal.behaviors.modalFrameChildResize = function () {
			// run this behavior after all other behaviors
			$('img.jcrop-preview').load(function (e) { 
				Drupal.modalFrameChild.triggerParentEvent('childResize');
			});
		};
	}
};