<?php
class spaces_controller_vsite_views extends spaces_controller {

  static $fields = array('header', 'header_format', 'header_empty', 'footer', 'footer_format', 'footer_empty', 'items_per_page');

  /**
   * Loads the original values
   * Is run on the first ::get() call
   * Don't expect any values for it before that
   * @see spaces_controller::load_original_values()
   */
  protected function load_original_values($id = NULL) {
    if (!$id) return;
    // split id by :
    // frag[0] = view name
    // frag[1] = display

    if (empty($this->loaded_all['original'])) {
      list($name, $display) = explode(':', $id);
      $view = views_get_view($n);

      $this->values['original'][$view->name] = array();
      foreach (spaces_controller_vsite_views::$fields as $f) {
        if (isset($views->display[$display]->options[$f])) {
          $this->values['original'][$id][$f] = $views->display[$display]->options[$f];
          $this->loaded['original'][$id] = TRUE;
        }
      }
    }
  }

  protected function load_space_values($id = NULL) {
    if (!$this->loaded_all['space']) {
      if (isset($id) && !isset($this->loaded['space'][$id])) {
        $q = db_query("SELECT object_id AS id, value
          FROM {spaces_overrides}
          WHERE type = '%s'
            AND id = '%s'
            AND object_type = '%s'
            AND object_id LIKE '%s%%'",
          $this->space_type, $this->space_id, $this->controller, $id);

        while ($r = db_fetch_array($q)) {
          $field = str_replace($id.':', '', $r['id']);
          $this->values['space'][$id][$field] = unserialize($r['value']);
        }
        $this->loaded['space'][$id] = TRUE;
      }
      else {
        $q = db_query("SELECT object_id AS id, value
          FROM {spaces_overrides}
          WHERE type = '%s'
            AND id = '%s'
            AND object_type = '%s'",
          $this->space_type, $this->space_id, $this->controller);

        while ($r = db_fetch_array($q)) {
          list($name, $display, $field) = explode(':', $r['id']);
          $id = $name.':'.$display;
          $this->values['space'][$id][$field] = unserialize($r['value']);
          $this->loaded['space'][$id] = TRUE;
        }
        $this->loaded_all['space'] = TRUE;
      }
    }
  }

  public function set($id, $value) {
    foreach ($value as $field => $data) {
      parent::set($id.':'.$field, $data);
      unset($this->values['spaces'][$id.':'.$field]);
    }
    $this->values['spaces'][$id] = $value;
  }
}