/**
 * @file
 * 
 * When citation_distribute options change, this script updates the vertical tab to display new settings.
 */

// The following line will prevent a JavaScript error if this file is included and vertical tabs are disabled.
Drupal.verticalTabs = Drupal.verticalTabs || {};

Drupal.verticalTabs.citation_distribute_selections = function() {
  var vals = [];
  
  /* Get checked options, add their label text to array */
  $('fieldset.vertical-tabs-citation_distribute_selections input:checked')
    .parent()
    .each( function(){vals.push( $(this).text() )} )
  
  if (vals.join(', ') == '') {
    return Drupal.t('None');
  }
  return vals.join(', ');
}