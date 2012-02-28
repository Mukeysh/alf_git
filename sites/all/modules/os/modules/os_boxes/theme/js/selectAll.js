/**
 * 
 */

Drupal.behaviors.selectAllStart = function (ctx) {
	function selectAll() {
		var stop = this.name.lastIndexOf('['),
			name = this.name.slice(0,stop),
			chk = this.checked,
			$cbxs = $('input[name^="'+name+'"]');
		$cbxs.each(function() {
			this.checked = chk;
		});
	}
	
	$('input[name$="[all]"]').change(selectAll);
};