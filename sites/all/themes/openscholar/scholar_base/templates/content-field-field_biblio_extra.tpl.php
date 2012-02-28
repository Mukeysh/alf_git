<?php
// $Id: content-field-field_biblio_extra.tpl.php,v 1.1.2.5 2008/11/03 12:46:27 rbrandon Exp $

/**
 * @file content-field-field_biblio_extra.tpl.php
 * Default theme implementation to display the value of a field.
 *
 * Available variables:
 * - $node: The node object.
 * - $field: The field array.
 * - $items: An array of values for each item in the field array.
 * - $teaser: Whether this is displayed as a teaser.
 * - $page: Whether this is displayed as a page.
 * - $field_name: The field name.
 * - $field_type: The field type.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $label: The item label.
 * - $label_display: Position of label display, inline, above, or hidden.
 * - $field_empty: Whether the field has any valid value.
 *
 * Each $item in $items contains:
 * - 'view' - the themed view for that item
 *
 * @see template_preprocess_field()
 */
?>
<?php if (!$field_empty) : ?>
<div class="field-type-<?php print $field_type_css ?> field-<?php print $field_name_css ?>">
  
    <?php
    foreach ($items as $delta => $item) :
      if (!$item['empty']) : ?>
        <h3><?php print $item['safe_label']. ":</h3>". $item['safe_value'];
      endif;
    endforeach;?>
</div>
<?php endif; ?>
