/**
 * Monitors an autocomplete field for any changes.
 * When it does, it changes an Edit Post link to match the change
 */
Drupal.behaviors.PostInBox_autocomplete = function(ctx) {
	if (ctx == document) {
		ctx = $('#modalContent');
	}
	var nid_reg = /\[nid:(\d+)\]/,
		link_reg = /node\/(\d+)\/edit/,
		timeout_id = setInterval(function() {
			var input = $('#edit-nid', ctx),
				link = $('a.edit-node', ctx),
				match;
			if (input.is(':visible') && input.size() && link.size()) {
				match = input.val().match(nid_reg)
				if (match) {
					link.show();
					link[0].href = link[0].href.replace(link_reg, 'node/'+match[1]+'/edit');
				}
				else {
					link.hide();
				}
			}
			else {
				clearInterval(timeout_id);
			}
		}, 500);
	
	//var href = $('a.edit-node', ctx).attr('href')+'?destination='+Drupal.settings.getQ;
	//$('a.edit-node', ctx).attr('href', href);
};