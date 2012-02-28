if (Drupal.jsEnabled) {
  $(document).ready(function() {

    $('li.item-theme-picker').click(function(){
  	  // remove the active class from every li first
      $(this).siblings(".item-theme-picker").removeClass('checked');
      if(!$(this).hasClass('current')){    	  
        // add the class to this one
    	$(this).addClass('checked');
      }
      $("#edit-vsite-design-" + $(this).attr('id')).attr("checked", "checked").change();
    });
    
    $('li.item-theme-picker').find('select').change(function(){
    	// remove the active class from every li first
      	$(".item-theme-picker").removeClass('checked');
      	// add the class to this one
      	$(this).closest('li.item-theme-picker').addClass('checked');
      	
      	$("#edit-vsite-design-" + $(this).closest('li.item-theme-picker').attr('id')).attr("checked", "checked").change();
    });
    
    $('#vsite-design-theme-picker-form').submit(function(event) {
    	//Add the ajax spinner
    	if(!$('#design-submit-waiting').length) $('#edit-submit').after('<div id="design-submit-waiting" class="ctools-ajaxing" count="0"> &nbsp; </div>');
    	
    	//Loop untill the ajax is done or we have waited 5 cycles
    	if($('.ctools-ajaxing:not(#design-submit-waiting)').length > 0 && $('#design-submit-waiting').attr('count') < 6){
    	  event.preventDefault();
    	  $('#edit-submit').animate({ dummy: 1 }, 1000) //Replace this line with delay when we upgrade to jquery 1.4
    	  .queue('fx',function(){
    		$('#design-submit-waiting').attr('count',parseInt($('#design-submit-waiting').attr('count'))+1);
    	    $('#vsite-design-theme-picker-form').submit();
    	    $(this).dequeue();
    	  });
    	}
    	return true;
    });
    

  });
}

