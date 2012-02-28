/* detects an illegal slash at the beginning of url path aliases */

$(document).ready(function() {
  //remove front slash, show message
  $('#edit-path').blur(function() {
    var path = $('#edit-path').attr('value');
    
    //strip leading slash
    if (path.indexOf('/') == 0) {
      path = path.replace(/^\/+/, '');
      pathauto_extra_warning('URL Path alias cannot begin with a slash.');
    }
    
    //strip trailing slash
    if (path.substr(-1) == '/') {
      path = path.replace(/\/+$/, '');
      pathauto_extra_warning('URL Path alias cannot end with a slash.');
    }
    
    $('#edit-path').attr('value', path); 
  });
  
  //remove message, if displayed
  $('#edit-path').focus(function() {
    $('div.pathauto_extra-warning').remove();
  });
  
  //add listener to URL path settings.  fetch new path via ajax
  $('a.vertical-tabs-list-path').click(function(){
    if (Drupal.settings.pathauto_extra && Drupal.settings.pathauto_extra.make_alias) {
      var href = href = 'http://' + document.location.host + '/pathauto_extra/alias_js';
      var data = Drupal.settings.pathauto_extra;
      data.title = $.trim($('#edit-title').attr('value'));
    
      if (  data.title.length > 0 && $('#edit-pathauto-perform-alias').attr('checked')  ) {
        $.getJSON(href, data, function(json) {
          if (json.status) {
            $('#edit-path').attr('value', json.data);
          }
        });
      }
    }
  });
  
  function pathauto_extra_warning(str) {
    $('#edit-path + div.description').after('<div class="description pathauto_extra-warning">' + str + '</div>');
    $('#edit-path').change(); //.change() updates vtab preview
  }
});