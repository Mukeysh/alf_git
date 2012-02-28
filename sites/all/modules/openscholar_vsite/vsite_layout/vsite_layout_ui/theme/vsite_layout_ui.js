Drupal.behaviors.scholarlayout = function() {
  Drupal.CTools.AJAX.commands.updateLayoutForm = function(data) {
	  scholarlayout_update_moved_elements(data.warning);
  }
  
  var layoutRegions = [ "#scholarlayout-header-left", "#scholarlayout-header-main", "#scholarlayout-header-right", "#scholarlayout-navbar", "#scholarlayout-left", "#scholarlayout-right", "#scholarlayout-footer" ];
  
  if( $("#edit-page-type").val() == "front"){
    layoutRegions.push("#scholarlayout-content-top");
    layoutRegions.push("#scholarlayout-content-bottom");
    layoutRegions.push("#scholarlayout-content-left");
    layoutRegions.push("#scholarlayout-content-right");
  }

  scholarlayout_add_sortable(layoutRegions);

  if (!scholarlayout_change_bound) {
    scholarlayout_change_bound = true;

    $('#vsite-layout-ui-settings-form').submit(function() {
      scholarlayout_update_moved_elements(false);
      return true;
    });

    $("#edit-page-type").bind('change', function(e) {
      if (scholarlayout_catchchanges()) {
        $('#edit-secret-hidden-ahah').val($("#edit-page-type").val());
        $('#edit-secret-hidden-ahah').trigger('go_ahah');
        $("#edit-page-type").trigger('go_ahah');
        $("#scholarforms_save_warning").remove();
        scholarlayout_add_sortable(layoutRegions);
      } else {
        // revert
        $('#edit-page-type').val($("#edit-secret-hidden-ahah").val());
      }
    });
  }
  scholarlayout_add_removal_hooks();
  
  //Add scroller that shows what exceptions exist
  vsite_layout_setExceptionScroller();

  //init scroller on topbox
  vsite_layout_init_horz_scroller();
  
  //Add tabbed event for catigorized widgets
  vsite_layout_add_category_select();
  
  //remove or prevent ctools modal handling from modalframe links
  vsite_layout_modalframe_links();
  
  //compress widgets widths to fit in the space provided
  vsite_layout_set_widget_width(false);
  
  //Create the wobble func
  $(document).bind('CToolsDetachBehaviors',function(element) {
	//Shake new widgets when they are created
	vsite_layout_wobble_new();
  });
};

function scholarlayout_add_removal_hooks() {
  $(".ui-sortable .close-this:not(.close-this-processed)").addClass('close-this-processed')
  .click(function(e) {
    var parent = $(this).parent("dd");
    $("body").append("<div class='poof'></div>");

    // set the x and y offset of the poof animation <div> from cursor
    // position (in pixels)
    var xOffset = 24;
    var yOffset = 24;

    $('.poof').css({
      left : e.pageX - xOffset + 'px',
      top : e.pageY - yOffset + 'px'
    }).show(); // display the poof <div>
    animatePoof(); // run the sprite animation

    parent.appendTo("#scholarlayout-top-widgets");
    scholarlayout_update_moved_elements(true);

    parent.fadeIn('fast');
    vsite_layout_init_categories();
    vsite_layout_update_scroller_width();
  });
}

var scholarlayout_change_bound = false;
var scholarlayout_oScrollbar = false; 

//Executed after a block is dragged
function scholarlayout_afterdrag(event, ui) {
  
  scholarlayout_update_moved_elements(true);
  vsite_layout_update_scroller_width();
  
  //compress widgets widths to fit in the space provided
  vsite_layout_set_widget_width(ui.item);
};

/**
 * Update the form with the correct values after elemens have been moved.
 * @param warning
 * @return
 */
function scholarlayout_update_moved_elements(warning){
	  var regions = $("#scholarlayout-container > .scholarlayout-widgets-list");
	  $.each(regions.filter(":visible"), function(i, region) {
	    var items = $("#" + region.id + " > .scholarlayout-item");
	    var ids = "";
	    $.each(items, function(i, value) {
	      if (ids.length) {
	        ids += "|";
	      }
	      ids += value.id;
	    });
	    $('#edit-' + region.id).val(ids);
	  });
	  
	  $.each(regions.filter(":hidden"), function(i, region) {
		$('#edit-' + region.id).val("");
	  });

	  if (!$("#scholarforms_save_warning").length && warning) {
	    $("#cp-settings-layout").before(
	        $('<div id="scholarforms_save_warning" class="warning"><span class="warning tabledrag-changed">*</span> Your changes have not yet been saved. Click "Save Settings" for your changes to take effect</div>')
	    );
	  }
	  
}

function scholarlayout_catchchanges() {
  if (!$("#scholarforms_save_warning").length 
      || confirm("Your changes have not been saved. Continue and lose your changes?")) {
    return true;
  }    
  return false;
};

function scholarlayout_add_sortable(layoutRegions) {
  var allRegions = layoutRegions.slice();
  allRegions[allRegions.length] = "#scholarlayout-top-widgets";
  $.each(allRegions, function(i, value) {
	$(value).sortable('destroy');
    $(value).sortable({
      appendTo: '#vsite-layout-ui-settings-form',
      helper: 'clone',
      cursorAt: {top: 25, left: 38},
      connectWith : allRegions,
      stop : scholarlayout_afterdrag,
      tolerance : 'pointer',
      start: function (event, ui) {ui.helper.width('75px'); },
      over : function(event, ui) {$(event.target).addClass('active');},
      out : function(event, ui) {$(event.target).removeClass('active');}
    });
  });
}

// The jQuery Poof Effect was developed by Kreg Wallace at The Kombine Group,
// Inc. http://www.kombine.net/

function animatePoof() {
  var bgTop = 0; // initial background-position for the poof sprit is '0 0'
  var frames = 5; // number of frames in the sprite animation
  var frameSize = 32; // size of poof <div> in pixels (32 x 32 px in this example)
  var frameRate = 80; // set length of time each frame in the animation will
                      // display (in milliseconds)

  // loop through amination frames
  // and display each frame by resetting the background-position of the poof
  // <div>
  for (i = 1; i < frames; i++) {
    $('.poof').animate({backgroundPosition : '0 ' + (bgTop - frameSize) + 'px'}, frameRate);
    bgTop -= frameSize; // update bgPosition to reflect the new
                        // background-position of our poof <div>
  }

  // wait until the animation completes and then hide the poof <div>
  setTimeout("$('.poof').remove()", frames * frameRate);
}

 // Horizontal Sliding Exceptions
function vsite_layout_setExceptionScroller() {

  $('span.toggle-exceptions').click(function() {
    $(this).siblings('div.layout-exceptions').stop().animate({
      right : '-20px'
    }, {
      queue : false,
      duration : 300
    });
  });

  $('div.layout-exceptions').click(function() {
    $(this).stop().animate({
      right : '-101%'
    }, {
      queue : false,
      duration : 300
    });
  });

}

//attaches event listeners to category select widget
//when its changed, show only widgets that match the category
function vsite_layout_add_category_select() {
 $('#widget-categories li').click(function() {
   $('#widget-categories li').removeClass('active');
   $(this).addClass('active');
   vsite_layout_init_categories();
   vsite_layout_update_scroller_width();
   return false;
 });
 
 // behaviors gets run after an ajax call
 // prevent this from selecting multiple tabs
 if (!$('#widget-categories li.active').length) {
	 $('#widget-categories li:first').addClass('active');
 }
 vsite_layout_init_categories();
}

function vsite_layout_init_categories(){
	var cat = $('#widget-categories li.active a').attr('href').substring(1);
	vsite_layout_swap_categories(cat);
}

function vsite_layout_swap_categories(cat) {
	if (cat == 'all') {
		$('#scholarlayout-top-widgets dd').not('.disabled').show();
	}
	else {
		$('#scholarlayout-top-widgets').children('dd:not(.' + cat + ')').hide();
		$('#scholarlayout-top-widgets').children("."+cat + ':not(.disabled)').show();
	}
	vsite_layout_update_scroller_width();
}

//remove or prevent ctools modal handling from modalframe links
function vsite_layout_modalframe_links(){
	  
  function modalFrameSubmitHandler(args, messages) {
	  Drupal.CTools.AJAX.respond(args);
  }
	$('a.ctools-use-modal').each(function(i, elem) {
		  if (elem.href && elem.href.indexOf('/modal/') != -1) {
			  var $this = $(this);
			  $this.removeClass('ctools-use-modal');
			  if ($this.hasClass('ctools-use-modal-processed')) {
				  $this.unbind('click', Drupal.CTools.Modal.clickAjaxLink);
			  }
			  
			  $this.click(function (e) {
				var url = $(this).attr('href'),
				    modal_start = url.indexOf('/modal/'),
				    params = url.slice(modal_start);
				url = url.replace(params, '');
				params = params.split('/');
				
				url = url+'?modal&box='+params[3]+'&source='+params[5];
				
				var modalOptions = {
					url: url,
					autoFit: true,
					width: 980, 
					height: 150,
					onSubmit: modalFrameSubmitHandler
				};
				
				Drupal.modalFrame.open(modalOptions);
				
				e.preventDefault();
		  	  });
		  }
	  });
}

//init scroller on topbox
function vsite_layout_init_horz_scroller(){
	
	//Top Scroller
	$('#scholarlayout-top-widgets-wrapper').addClass('scroll-wrapper').append('<div class="scrollbar"><div class="track"><div class="thumb"><div class="end"></div></div></div></div>');
	$('.scroll-wrapper .tagged-list').addClass('scroll-viewport');
	$('.scroll-wrapper .tagged-list #scholarlayout-top-widgets').addClass('scroll-content');
	
  	scholarlayout_oScrollbar = $('.scroll-wrapper').tinyscrollbar({ axis: 'x'});
	
	if ($('#scholarlayout-top-widgets-wrapper').hasClass('scroll-wrapper')) {
	  vsite_layout_update_scroller_width();
	}
}

/*
 * Update the width of divs and re-init to scrollbar object
 */
function vsite_layout_update_scroller_width(){
	var vp_width = $('.scroll-wrapper .scroll-viewport').width();
	//arb large
	$('.scroll-wrapper .scroll-viewport').width(5000);
	$('.scroll-wrapper .scroll-content').css('width','auto');
	
	var ct_width = Math.max($('.scroll-wrapper .scroll-content').width(),vp_width);
	$('.scroll-wrapper .scroll-content').width(ct_width);
	
	$('.scroll-wrapper .scroll-viewport').width(vp_width);
	if(scholarlayout_oScrollbar) scholarlayout_oScrollbar.tinyscrollbar_update();
}

/**
 * Only does something when a widget has been added dynamically.
 */
Drupal.behaviors.widgetBeenAdded = function (ctx) {
	// ctx is a jQuery object with our element inside
	// do nothing if our ctx doesnt have the widget class!
	if (!('hasClass' in ctx) || !ctx.hasClass('scholarlayout-item')) return;
	
	$('#widget-categories li a').each(function () {
		var cat = $(this).attr('href').substring(1);
		if (ctx.hasClass(cat)) {
			$(this).click();
			return false;
		}
	});
};

/*
* adjusts the width of a single widget to fit the container
* takes either an element or a jQuery object
*/ 
function vsite_layout_set_widget_width(widget){
    
	var nHeight = 36; //Height of one widget

	var regions;
	if(widget){
	  regions = widget.parent();
	}else{
	  regions = $("#scholarlayout-container > .scholarlayout-widgets-list");
	}
    
	$.each(regions, function(i, region){
		
		var rgn = $("#"+region.id);
		if(region.id == 'scholarlayout-top-widgets' && widget){
			//top widgets should go back to default size
			$(widget).removeAttr( "style" );
		}else if(rgn.height() < nHeight *2){
			//If this is a skinny container
			var items = $("#"+region.id+" > .scholarlayout-item");
			var nWidth = (rgn.width()) / items.length;
			items.width(nWidth - 51);
	    }else if(rgn.hasClass('scholarlayout-widgets-list') && widget){
		  var nWidth = rgn.width();
		  $(widget).width(nWidth-51);
		}
	});
}

/**
 * AHAH leaves an unmarked div inbetween our wrapper and content elements
 * This fixes it
 */
function vsite_layout_fix_top_ahah() {
	var $top = $('#scholarlayout-top-widgets'),
		top = $top[0];
	
	if (typeof top.parentNode.id == 'undefined' && top.parentNode.className == '') {
		// we have an unmarked div
		var rem = $(top.parentNode),
			targ = $(top.parentNode.parentNode);
		$top.detach();
		rem.remove();
		targ.after($top);
	}
}

////////wobble///////////
function vsite_layout_wobble_new(){	
	
	$('dd.changed').each(function(){
	  var i = 0;	
	  while(i < 8) {
		$(this).animate({marginTop:'-'+3+'px'}, 90);
		$(this).animate({marginTop:3}, 90);
		i++;
	  }
	  $(this).removeClass('changed');
	});  
}
