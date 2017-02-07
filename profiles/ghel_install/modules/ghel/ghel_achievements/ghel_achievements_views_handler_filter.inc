<?php

/**
 * @file
 * Definition of ghel_achievements_views_handler_achievement_filter.
 */

class ghel_achievements_views_handler_type_filter extends views_handler_filter {

  function value_form(&$form, &$form_state) {

    $types = ghel_achievements_get_types();

    // override views default
    if ($this->operator == '=') {
      $this->operator = 'like';
    }

    $form['operator'] = array(
      '#type' => 'radios',
      '#title' => t('Operator'),
      '#options' => array(
        'like' => t('Is'),
        'not like' => t('Is not'),
      ),
      '#default_value' => $this->operator,
    );

    // filter on our achievement type
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Achievement type'),
      '#options' => $types,
      '#default_value' => $this->value,
      '#multiple' => FALSE,
    );

  }

  function query() {
    switch ($this->operator) {
      case 'not like':
        $operator = 'NOT LIKE';
        break;

      default:
        $operator = 'LIKE';
        break;
    }

    $this->ensure_my_table();
    $field = "$this->table_alias.$this->real_field";

    // We just do a 'starts with' query
    $this->query->add_where($this->options['group'], $field, db_like($this->value) . '%', $operator);
  }
}
