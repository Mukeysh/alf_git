<?php

/**
 * Field handler to present a link to delete a node.
 */
class vsite_comments_handler_field_comment_link_delete extends views_handler_field_comment_link {
  function render($values) {
    //needs permission to administer vsite comments
    if (!vsite_comments_admin_access()) {
      return;
    }
    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    return l($text, "comment/delete/" . $values->{$this->aliases['cid']}, array('query' => drupal_get_destination()));
  }
}


