<?php
/**
 * @file
 * Comment radioactivity views handler to allow choosing between LEFT or INNER joining.
 */

class radioactivity_comment_views_handler_sort_left_or_inner extends radioactivity_node_views_handler_sort_left_or_inner {
  function radioactivity_object_type_in_plural() {
    return 'comments';
  }
}
