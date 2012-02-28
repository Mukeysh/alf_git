
Drupal.behaviors.scholarPublications = function() {
	
	if($('div#biblio-authors-wrapper').length){
		scholarPublicationsMonitorAuthors();
	}
	
//	$('fieldset legend a').live('mouseup', function() {
//		var td = Drupal.tableDrag.field_biblio_extra_values;
//		window.setTimeout(function () {
//			td.hideColumns(); 
//		}, 201);
//	});
};

scholarPublicationsMonitorAuthors  = function() {
  
  $('div#biblio-authors-wrapper td.biblio-contributor:last input:text').change(function(){
    if($(this).val() && !$(this).hasClass('no-more-authors') && !$(this).next('div#biblio-authors-wrapper input:text').length){
      $(this).addClass('no-more-authors');
      window.setTimeout('$("input#edit-contributors1-wrapper-biblio-authors-more").mousedown();', 200);
	}
  });
  
  $('div#biblio-secondary-authors-wrapper td.biblio-contributor:last input:text').change(function(){
    if($(this).val() && !$(this).hasClass('no-more-authors') && !$(this).next('div#biblio-secondary-authors-wrapper input:text').length){
      $(this).addClass('no-more-authors');
      window.setTimeout('$("input#edit-contributors2-wrapper-biblio-secondary-authors-more").mousedown();', 200);
    }
  });
};
