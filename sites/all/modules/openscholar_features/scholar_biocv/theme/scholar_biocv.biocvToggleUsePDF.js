Drupal.behaviors.biocvToggleUsePDF = function (context) {
  var selector = 'input[name="'+Drupal.settings.biocvToggleUsePDF['monitor']+'"]';
  if($(selector).length){
	  $(selector).change(Drupal.biocvToggleUsePDF);
	  
	  //Wait till the MCE editor is loaded then set defaults
	  var setDefaults = function() { 
		var triggered = false;
        for (var ee in tinyMCE.editors) {
        	if(triggered) continue;
        	triggered = true;
        	$(selector).trigger('change'); 
	    }
        if(!triggered) setTimeout(setDefaults, 500);
	  };
      setTimeout(setDefaults, 500);
      //END -- Set Defaults
  }
}

Drupal.biocvToggleUsePDF = function(e) {
	var disable = $(this).is(':checked');
	biocvSetMCEEditors(tinyMCE.editors);
	
	$(Drupal.settings.biocvToggleUsePDF['toggleOff']).each(function (i,name) {
	  if($('[name="'+name+'"]').length){
    	  if(disable){
    	    $('[name="'+name+'"]').attr("disabled", "disabled");
    	    
    	  }else{
    	    $('[name="'+name+'"]').removeAttr("disabled");
    	  }
	  }
	  
	  for (var editor_id in Drupal.settings.biocvToggleUsePDF['mce_editors']) {
          if (editor_id == $('[name="'+name+'"]').attr('id')) {
        	  biocvToogleMCEEditor($('[name="'+name+'"]').attr('id'),disable);
          }
      }
    });

};

function biocvToogleMCEEditor(sElementEditorID,bDisabled) {
    try {
        if(bDisabled) {
        	tinyMCE.get(sElementEditorID).remove();
            //tinyMCE.removeMCEControl(tinyMCE.get(sElementEditorID));
        } else {
        	tinyMCE.execCommand('mceAddControl', false, sElementEditorID);
            //tinyMCE.addMCEControl(document.getElementById(sElementEditorID), sElementEditorID);
        }
    } catch(e) {
        //error handling
    	//alert(e);
    }
}

function biocvSetMCEEditors(editors){
  if(!Drupal.settings.biocvToggleUsePDF['mce_editors']){
	  Drupal.settings.biocvToggleUsePDF['mce_editors'] = new Array();
	  var i = 0;
	  for (var editor_id in editors) {
		  Drupal.settings.biocvToggleUsePDF['mce_editors'][editor_id] = editor_id;
		  i++;
      }
  }
}//Put this in a function so we don't pass by reference