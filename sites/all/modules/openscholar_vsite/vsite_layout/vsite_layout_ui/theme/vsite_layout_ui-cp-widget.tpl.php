<?php
/**
 *  Template for a single widget in the CP layout form
 *
 *  Renders the box and any controls it has
 *  Variables:
 *  ----------
 *  $s_widget_key -> the widgets key
 *  $w -> the widget
 */
$s_class = (isset($w['hidden']) && $w['hidden'])? 'scholarlayout-item disabled':'scholarlayout-item';

if ($w['plugin']) {
  $s_class .= ' '.$w['plugin'];
}

// extra classes used for tag selectin
if ($w['class']) {
  $s_class .= ' '.$w['class'];
}

if($w['overides']) {
	$s_class .= " with-overrides";
}

if($w['icon_path']){
	$dd_il_style = "style=\"background-image:url('{$w['icon_path']}');\"";
}
?>

<dd class="<?php echo strtolower($s_class); ?>" id="<?php print $s_widget_key; ?>" <?php $dd_il_style ?>> <?php print $w['label']; ?>
      <div class="close-this" title="Remove">Remove</div>
     <?php
     if ($w['block_config_path']){
       if ($w['can_delete']) print ctools_modal_text_button("Delete", $w['block_delete_path'], "Delete widget", "delete ctools-modal-openscholar-style-default");
     	 $class = (strpos($w['delta'],"boxes_add__") === 0)?"add":"setting";
       print ctools_modal_text_button("Configure",$w['block_config_path']."/configure/cp_layout","Configure widget",$class);
     }
     if($w['overides']){
       ?>
       <span class="scholarlayout-item-settings">Appears here on all pages with <span class="toggle-exceptions">exceptions</span>
        <div class="layout-exceptions">
          <h4>Exceptions:</h4>
          <ul>
            <?php
            $removethis = array("scholar", "Scholar");
            print "<li>" . implode(' , </li><li>',$w['overides']) . "</li>";
           ?>
          </ul>
        </div>
       </span>
       <?php
     }
     ?>
</dd>