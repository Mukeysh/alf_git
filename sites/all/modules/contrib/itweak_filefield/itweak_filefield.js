/* $Id: itweak_filefield.js,v 1.2.2.6 2011/1/4 03:39:40 iva2k Exp $ */

Drupal.behaviors.filefielditweak = function (context) {
 $('.filefield-upload input[type=submit]', context).hide();
 
 $('.filefield-upload input[type=file]', context).change(function() {
   if($('.file-upload-js-error').length == 0) {
     $(this).next('input[type=submit]').trigger('mousedown');
   }
  });

};