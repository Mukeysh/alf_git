/**
 * Saves the current active tab for the session.
 * Restores this tab as the active tab when we return.
 */

Drupal.behaviors.quickTabsRemember = function (ctx) {
	$('.box-os_modal_tabbed', ctx).each(function () {
		var id = this.id,
			$this = $(this),
			active = sessionStorage[id],
			$tab = $this.find('.qtab-'+active);
		
		// we set the class AND click because the order behaviors run in is uncertain
		if($tab.length){
		  $this.find('li.active').removeClass('active');
		  $tab.addClass('active').find('a').click();
		}
		
		$this.find('ul.quicktabs_tabs:first li a').unbind('click', clickHandle).click(clickHandle);
	});
	
	function clickHandle(e) {
		var $this = $(this),
			id = $this.parents('.block').attr('id'),
			val = this.myTabIndex;	// haha what
		
		sessionStorage[id] = val;
	}
};