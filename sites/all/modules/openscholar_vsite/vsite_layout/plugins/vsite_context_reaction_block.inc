<?php

/**
 * Expose blocks as context reactions.
 */
class vsite_context_reaction_block extends context_reaction_block {

  /**
   * Determine whether inline editing requirements are met and that the current
   * user may edit.
   */
  protected function is_editable($reset = FALSE) {
  	/**
  	 * Hardcoded to flase for now, since we do not wish to have inline editing yet and don't need
  	 *
  	 * 1. All emty blocks displayed
  	 * 2. Extra divs attached to the blocks
  	 * 3. Extra div's and region names attached to the region
  	 */
    return (parent::is_editable($reset) && user_access('vsite_edit_contex_blocks') && false);
  }

  /**
   * Override to alter block subject for legacy support of block customizers
   */
  protected function build_block($block, $reset = FALSE) {
  	$block = parent::build_block($block,$reset);
  	$subject_overrides = variable_get('block_subject_customizer',array());

  	if(array_key_exists($block->bid,$subject_overrides)){
  		$block->subject = check_plain($subject_overrides[$block->bid]);
  	}

  	return $block;
  }

  // public wrapper for build_block
  public function get_block($block, $reset = FALSE) {
    if (!is_array($block) && !is_object($block)) {
      $parts = explode('-',$block);
      $block = array();
      $block['module'] = array_shift($parts);
      $block['delta'] = implode('-',$parts);
    }

    return $this->build_block((object)$block, $reset);
  }
}
