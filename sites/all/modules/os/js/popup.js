/**
 * Switches which set of commands to use based on the link clicked
 * I don't need to do this with modalframe, since it should take care
 * of itself.
 */
(function () {
	var old_responder = Drupal.CTools.AJAX.respond;
	Drupal.CTools.AJAX.respond = function (data) {
		var clicked = $('.ctools-ajaxing'),
			type, i;
		
		if (clicked.hasClass('ctools-use-modal')) {
			type = 'modal';
		}
		else if (clicked.hasClass('ctools-use-dialog')) {
			type = 'dialog';
		}
		
		for (i in data) {
			data[i].command = data[i].command.replace(/(modal|dialog)/, type);
		}
		old_responder(data);
	};
})();