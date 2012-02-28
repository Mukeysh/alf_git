/**
 * 
 */
Drupal.behaviors.os_modalframe_links = function (ctx) {	
	$('.os-popup-modal-link', ctx).click(function (e) {
		var url = $(this).attr('href'),
		    modal_start = url.indexOf('/modal/'),
		    params = url.slice(modal_start+7),
			query = ['modal'], i, next = '';
		url = url.replace('/modal/'+params, '');
		params = params.split('/');
		
		// construct a set of query parameters
		for (i in params) {
			if (next == '') {
				next = params[i]+'=';
			}
			else {
				query.push(next+params[i]);
				next = '';
			}
		}
		
		url = url+'?'+query.join('&');
		
		var modalOptions = {
			url: url,
			autoFit: true,
			width: 980,
			height: 150,
			onOpen: function (e) {
				// modalframe comes with an OnLoad, but it doesn't fire
				// if child.js hasn't been included in the new page,
				// which is hasn't in a straight json return
				Drupal.modalFrame.iframe.$element.bind('load', onLoad);
			},
			onSubmit: Drupal.CTools.AJAX.respond,
		};
		
		Drupal.modalFrame.open(modalOptions);
		
		e.preventDefault();
	});
	
	function onLoad() {
		// get mimetype
		// if its json, close the modalframe and pass commands into CTools
		// otherwise, do nothing
		var doc = (this.contentWindow || this.contentDocument),
		response, $body, i, headers;
		if (doc.document) {
			doc = doc.document;
		}
		$body = $(doc.body);
		if ($body.find('pre').length) {
			response = eval('('+$body.find('pre').text()+')');
			for (i in response) {
				if (response[i].command == 'modal_dismiss' 
					|| response[i].command == 'dialog_dismiss'
					|| response[i].command == 'reload') {
					// close the iframe and send the rest of the commands to
					// the parent
					Drupal.modalFrame.close(response);
				}
				else if (response[i].command == 'modal_display'
					|| response[i].command == 'dialog_display') {
					// display the content
					$body.html(response[i].argument)
					doc.head.innerHTML = headers; 
				}
				else if (response[i].command == "css_files"
					|| response[i].command == "scripts")
					headers += response[i].argument;
			}
		}
		else {
			// this is a normal form.
			// boxes tries to submit the form through ajax, which we don't want.
			// we have to get the iframe's jQuery object to do this
			var win = 'defaultView' in doc? doc.defaultView : doc.parentWindow;
			win.$('.boxes-ajax', $body).removeClass('boxes-ajax').unbind('click');
		}
	}
};