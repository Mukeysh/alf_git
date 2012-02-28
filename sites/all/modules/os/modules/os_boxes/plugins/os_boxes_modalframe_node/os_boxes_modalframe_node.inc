<?php

abstract class os_boxes_modalframe_node extends os_boxes_modalframe {

  public function options_defaults() {
    $options = parent::options_defaults();

    $options['path_add'] = 'node/add/%s';
    $options['path_edit'] = 'node/%d/edit';
    $options['nid'] = 0;
    $options['type'] = '';
    return $options;
  }

  public function options_form() {
    if ($this->options['nid']) {
      $this->options['path_edit'] = sprintf($this->options['path_add'], $this->options['type']);
    }
    else {
      $this->options['path_edit'] = sprintf($this->options['path_edit'], $this->options['nid']);
    }
    return parent::options_form();
  }

  public function render() {
    return node_view($this->options['nid'], TRUE, FALSE, FALSE);
  }
}