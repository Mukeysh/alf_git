Drupal.behaviors.scholar_dvn = function (context) {
  $('#feature-dataverse').prepend('<h2 id="dvn_loading" class="title">Loading Dataverse<span class="views-throbbing">&nbsp</span></h2>');
  $('#feature-dataverse iframe').load(function(){
	  $('#feature-dataverse #dvn_loading').remove();
  });
  
}
