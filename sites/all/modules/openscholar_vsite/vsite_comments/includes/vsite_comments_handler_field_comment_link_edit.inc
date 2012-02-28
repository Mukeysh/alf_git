<?php


/**
 * Field handler to present a link node edit.
 */
class vsite_comments_handler_field_comment_link_edit extends views_handler_field_comment_link {
  function construct() {
    parent::construct();
    $this->additional_fields['uid'] = 'uid';
  }

  function render($values) {
    // ensure user has access to edit this comment.
    $comment = new stdClass();
    $comment->cid = $values->{$this->aliases['cid']};
    $comment->uid = $values->{$this->aliases['uid']};
    if (!vsite_comments_admin_access()) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    return l($text, "comment/edit/" . $values->{$this->aliases['cid']});
  }
}