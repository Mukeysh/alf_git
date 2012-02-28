<?php
/**
 *  template for theming a list of widgets
 *  Variables:
 *  ----------
 *  $wgts -> list of all the widgets (dpm($wgts) for more info)
 *  $wgts_id -> the id of the ul
 *  $wgts_class -> the class of the ul
 */
$s_tagged_output = array('All' => "", 'Content' => "",'Media' => "",'Social' => "",'Misc' => "");
$factories = array();
foreach($wgts as $s_widget_key => $w){
	if(!is_array($w['tags'])) $w['tags'] = array();

	//Return the first tag that matches the display categories above
	$s_tag = array_shift(array_intersect(array_keys($s_tagged_output),$w['tags']));
	if($w['factory']){
	 $factories[$s_widget_key] = $w;
	}elseif($s_tag){
	  $s_tagged_output[$s_tag] .= theme('vsite_layout_ui_cp_widget', $s_widget_key, $w);
	}else{
		$w['tags'][] = "Misc";
		$s_tagged_output['Misc'] .= theme('vsite_layout_ui_cp_widget', $s_widget_key, $w);
	}
}

?>

<div id="<?php print $wgts_id; ?>-wrapper" class="<?php print $wgts_id; ?>-wrapper">
<?php if(count($factories)) echo _vsite_layout_ui_build_dropdown($factories); ?>

<div id="websiteLabelTab"><img src="<?php echo $GLOBALS['base_path'].drupal_get_path('module', 'vsite_layout_ui') . '/theme/images/websiteLayoutBarLabel.png'; ?>"></div>
<ul id="widget-categories">
<?php
  foreach($s_tagged_output as $s_tag_name => $output){
  	$s_tag_id = strtolower( str_replace(' ', '_', $s_tag_name));
    echo "<li><a href=\"#{$s_tag_id}\">{$s_tag_name}</a></li>";
  }
?>
</ul>

<div class="tagged-list">
  <dl id="<?php print $wgts_id; ?>" class = "<?php print $wgts_class; ?>">
    <dt><?php print $region_name;?></dt>
	  <?php
	  echo implode(" ",$s_tagged_output);
  	?>
  </dl>
</div>
</div>





