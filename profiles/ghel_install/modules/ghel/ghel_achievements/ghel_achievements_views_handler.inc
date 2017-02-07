<?php

/**
 * @file
 * Defines the field handler for achievement_id in the achievements table.
 */

class ghel_achievements_views_type_handler extends views_handler_field {
  function render($values) {
    $types = ghel_achievements_get_types();
    $key = $this->get_value($values);

    if (!empty($types[$key])) {
      return $types[$key];
    }
    else {
      return '';
    }
  }

  /**
   * Add our custom fields onto the field query.
   */
  function query() {
    $this->ensure_my_table();
    $this->field_alias = $this->view->query->add_field(NULL, "SUBSTRING_INDEX(achievement_id, '-', 3)", $this->table_alias . '_achievement_type');
  }

}

class ghel_achievements_views_revision_handler extends views_handler_field {
  function render($values) {
    $value = $this->get_value($values);
    if (!empty($value)) {
      return $value;
    }
    else {
      return 0;
    }
  }

  /**
   * Add our custom field to the field query.
   */
  function query() {
    $this->ensure_my_table();
    $this->field_alias = $this->view->query->add_field(NULL, "SUBSTRING_INDEX(achievement_id, '-', 3)", $this->table_alias . '_achievement_type');
    $this->field_alias = $this->view->query->add_field(NULL, "SUBSTRING_INDEX(SUBSTRING_INDEX(achievement_id, '-', -2), '-', -1)", $this->table_alias . '_achievement_revision');
  }
}
