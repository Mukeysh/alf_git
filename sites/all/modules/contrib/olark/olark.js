// $Id:

Drupal.behaviors.olark = function() {
  if ((typeof olark == 'function') && (typeof Drupal.settings.olark.uid != 'undefined')) {
    olark.extend(function(api){
      api.chat.updateVisitorNickname({
        snippet: Drupal.settings.olark.name,
        hidesDefault: true
      });
      api.chat.updateVisitorStatus({
        snippet: Drupal.settings.olark.mail + ' | ' + Drupal.settings.olark.userpage
      });
      api.chat.onReady(function(){
        if ((typeof Drupal.settings.olark.mail != 'undefined') && typeof Drupal.settings.olark.name != 'undefined') {
          olark('api.visitor.updateEmailAddress', {emailAddress: Drupal.settings.olark.mail});
          olark('api.visitor.updateFullName', {fullName: Drupal.settings.olark.name});
        }
      });
    }); 
  }

  // Hides Olark box if agent is iPod, iPad, iPhone.
  if(Drupal.settings.olark.disable_ios && Drupal.settings.olark.enabled){
    olark('api.box.onShow',checkIOS);
  }
}

function checkIOS() {
  var agent = navigator.userAgent.toLowerCase();
  var isIOS = (agent.match(/iP(hone|ad)/i) !== null);
  if (isIOS) {
    olark('api.box.hide');
  }
}
