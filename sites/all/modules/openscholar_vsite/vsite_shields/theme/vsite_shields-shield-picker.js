if (Drupal.jsEnabled) {
  Drupal.behaviors.shields = function(ctx) {
	if ($('.shield_wrapper',ctx).length == 1) return;
    $('.shield_wrapper .form-radios ').hide();

    var theList = '<ul class="shield-picker">';
    var n_container = 0;

    function getLi(liId, liChecked, liContent){
    	return '<li class="item-shield-picker ' + liChecked + '" id="' + liId  + '">' + liContent + '</li>';

    }
    $('.shield_wrapper .form-radios .form-item').each(function(){
    	var liIdArr = $(this).attr('id').split('-');
    	liIdArr.shift(); liIdArr.shift(); liIdArr.shift(); liIdArr.pop();
    	var liId = liIdArr.join("-");
    	var liChecked = $(this).find('input').attr('checked') ? 'checked' : '';

    	// get the whole img div
    	var liContent = $(this).find('.item-shield-picker').html();

    	theList = theList + getLi(liId, liChecked, liContent);

    	n_container++;
    });


    theList += '</ul>';

    $('.shield_wrapper').append(theList);

    $(".item-shield-picker:first").addClass('active');

//    $('div#prev,div#next,.shield_subnav li').cpSlidingContainer({containerW: 600,
//    mainListSelector:'ul.shield-picker',
//		listItemClass: 'item-shield-picker',
//		navClass:'shield_subnav'});

    $('li.item-shield-picker').click(function(){
    	// remove the active class from every li first
    	$(".item-shield-picker").removeClass('checked');
    	// add the class to this one
    	$(this).addClass('checked');

    	var id = $(this).attr('id');
    	$(".form-radio").removeAttr("checked");
    	$('.form-radio').each(function(){
    		if( $(this).attr('id').indexOf(id) != -1){
    			$(this).attr("checked", "checked");
    		}
    	});
    	//$("#edit-settings-generic-" + id.replace('.','\.')).attr("checked", "checked");
    });

  };
}
