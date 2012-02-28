if (Drupal.jsEnabled) {
  $(document).ready(function() {
	  vsite_design_grey_out($('#edit-settings-generic-disable-shield'));
  });
}

function vsite_design_grey_out(element){
	if($(element).is(':checked')){
	  $('.shield_wrapper').prepend("<div id=\'shield_screen\'></div>").css({ 'position': 'relative', 'overflow': 'hidden' });
		$('#shield_screen').css({ 'opacity': 0.8,
			               'width':$('.shield_wrapper').width(),
			               'height':$('.shield_wrapper').height(),
			               'position': 'absolute',
			               'margin':'0',
			               'background':'#fff'
		});
	}else{
	  $('#shield_screen').remove();
	}
}