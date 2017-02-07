<?php

/**
 * @file
 * Provide specific views implementation details.
 *
 */

/**
 * Implements hook_views_data().
 */
function ghel_achievements_views_data() {
  // Define the label that will show up in the views UI
  $data['achievement_unlocks']['table']['group'] =  t('Achievements');

  // Define how this joins to the user table.
  $data['achievement_unlocks']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  // Define the user id field
  $data['achievement_unlocks']['uid'] = array(
    'title' => t('User'),
    'help' => t('The user this achievement pertains to.'),
    'relationship' => array(
      'base' => 'users',
      'base field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('Achievement user'),
      'title' => t('Related achivement user'),
      'help' => t('The user associated with this achievement'),
    ),
  );

  // Define the achievement_id field
  $data['achievement_unlocks']['achievement_id'] = array(
    'title' => t('Achievement ID'),
    'help' => t('The achievement ID this row pertains to.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'field' => 'achievement_id',
      'join_handler' => 'ghel_achievements_views_join',
      'label' => t('Achievement node'),
      'title' => t('Related achievement node'),
      'help' => t('The node associated with this achievement'),
    ),
  );

  // Define the achievement_id as achievement_type field
  $data['achievement_unlocks']['achievement_type'] = array(
    'real field' => 'achievement_id',
    'title' => t('Achievement type'),
    'help' => t('The achievement type this row pertains to.'),
    'field' => array(
      'handler' => 'ghel_achievements_views_type_handler',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_string',
    ),
    'filter' => array(
      'handler' => 'ghel_achievements_views_handler_type_filter',
    ),
  );

  // Define the achievement_id as revision field
  $data['achievement_unlocks']['achievement_revision'] = array(
    'real field' => 'achievement_id',
    'title' => t('Achievement Revision'),
    'help' => t('The achievement revision.'),
    'field' => array(
      'handler' => 'ghel_achievements_views_revision_handler',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'relationship' => array(
      'base' => 'field_data_field_ghel_revision',
      'base field' => 'field_ghel_revision_value',
      'field' => 'achievement_id',
      'join_handler' => 'ghel_achievements_revision_views_join',
      'label' => t('Achievement revision'),
      'title' => t('Related course revision'),
      'help' => t('The course revision associated with this achievement'),
    ),
  );


  // Define the rank field
  $data['achievement_unlocks']['rank'] = array(
    'title' => t('Users rank'),
    'help' => t('Where is the user ranked relative to other users?'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Define the timestamp
  $data['achievement_unlocks']['timestamp'] = array(
    'title' => t('Date achieved'),
    'help' => t('When the user acquired the achievement.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // Define the seen field
  $data['achievement_unlocks']['seen'] = array(
    'title' => t('Seen'),
    'help' => t('Has the user seen the achievement?'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Seen'),
      'type' => 'yes-no',
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  return $data;
}


class ghel_achievements_views_join extends views_join {
  /**
   * This function is nearly the same as views_join::build_join except for the
   * condition.
   *
   * @see views_join::build_oin
   */
  function build_join($select_query, $table, $view_query) {
    if (empty($this->definition['table formula'])) {
      $right_table = $this->table;
    }
    else {
      $right_table = $this->definition['table formula'];
    }

    if ($this->left_table) {
      $left = $view_query->get_table_info($this->left_table);
      $left_field = "$left[alias].$this->left_field";
    }
    else {
      // This can be used if left_field is a formula or something. It should be used only *very* rarely.
      $left_field = $this->left_field;
    }

    // THIS IS THE ONLY LINE CHANGED FROM parent::build_join()
    // Certificates we want are in the form X-X-NAME-NID-REVISION
    // SUBSTRING INDEX -2 gives us NID-REVISION and then we pick of NID
    $condition = "SUBSTRING_INDEX(SUBSTRING_INDEX($left_field, '-', -2), '-', 1) = $table[alias].$this->field";
    $arguments = array();

    // Tack on the extra.
    if (isset($this->extra)) {
      if (is_array($this->extra)) {
        $extras = array();
        foreach ($this->extra as $info) {
          $extra = '';
          // Figure out the table name. Remember, only use aliases provided
          // if at all possible.
          $join_table = '';
          if (!array_key_exists('table', $info)) {
            $join_table = $table['alias'] . '.';
          }
          elseif (isset($info['table'])) {
            // If we're aware of a table alias for this table, use the table
            // alias instead of the table name.
            if (isset($left) && $left['table'] == $info['table']) {
              $join_table = $left['alias'] . '.';
            }
            else {
              $join_table = $info['table'] . '.';
            }
          }

          // Convert a single-valued array of values to the single-value case,
          // and transform from IN() notation to = notation
          if (is_array($info['value']) && count($info['value']) == 1) {
            if (empty($info['operator'])) {
              $operator = '=';
            }
            else {
              $operator = $info['operator'] == 'NOT IN' ? '!=' : '=';
            }
            $info['value'] = array_shift($info['value']);
          }

          if (is_array($info['value'])) {
            // With an array of values, we need multiple placeholders and the
            // 'IN' operator is implicit.
            foreach ($info['value'] as $value) {
              $placeholder_i = ':views_join_condition_' . $select_query->nextPlaceholder();
              $arguments[$placeholder_i] = $value;
            }

            $operator = !empty($info['operator']) ? $info['operator'] : 'IN';
            $placeholder = '( ' . implode(', ', array_keys($arguments)) . ' )';
          }
          else {
            // With a single value, the '=' operator is implicit.
            $operator = !empty($info['operator']) ? $info['operator'] : '=';
            $placeholder = ':views_join_condition_' . $select_query->nextPlaceholder();
            $arguments[$placeholder] = $info['value'];
          }

          $extras[] = "$join_table$info[field] $operator $placeholder";
        }

        if ($extras) {
          if (count($extras) == 1) {
            $condition .= ' AND ' . array_shift($extras);
          }
          else {
            $condition .= ' AND (' . implode(' ' . $this->extra_type . ' ', $extras) . ')';
          }
        }
      }
      elseif ($this->extra && is_string($this->extra)) {
        $condition .= " AND ($this->extra)";
      }
    }

    $select_query->addJoin($this->type, $right_table, $table['alias'], $condition, $arguments);
  }
}


class ghel_achievements_revision_views_join extends views_join {
  /**
   * This function is nearly the same as views_join::build_join except for the
   * condition.
   *
   * @see views_join::build_oin
   */
  function build_join($select_query, $table, $view_query) {
    if (empty($this->definition['table formula'])) {
      $right_table = $this->table;
    }
    else {
      $right_table = $this->definition['table formula'];
    }

    if ($this->left_table) {
      $left = $view_query->get_table_info($this->left_table);
      $left_field = "$left[alias].$this->left_field";
    }
    else {
      // This can be used if left_field is a formula or something. It should be used only *very* rarely.
      $left_field = $this->left_field;
    }

    // THIS IS THE ONLY LINE CHANGED FROM parent::build_join()
    // Certificates we want are in the form X-X-NAME-NID-REVISION
    // SUBSTRING INDEX -2 gives us NID-REVISION and then we pick of NID (1) and REVISION (-1)
    // The achievement revision is used to match against field_ghel_revision_value
    $condition = "(SUBSTRING_INDEX(SUBSTRING_INDEX($left_field, '-', -2), '-', -1) = $table[alias].$this->field";
    $condition .= " AND SUBSTRING_INDEX(SUBSTRING_INDEX($left_field, '-', -2), '-', 1) = $table[alias].entity_id)";
    $arguments = array();

    // Tack on the extra.
    if (isset($this->extra)) {
      if (is_array($this->extra)) {
        $extras = array();
        foreach ($this->extra as $info) {
          $extra = '';
          // Figure out the table name. Remember, only use aliases provided
          // if at all possible.
          $join_table = '';
          if (!array_key_exists('table', $info)) {
            $join_table = $table['alias'] . '.';
          }
          elseif (isset($info['table'])) {
            // If we're aware of a table alias for this table, use the table
            // alias instead of the table name.
            if (isset($left) && $left['table'] == $info['table']) {
              $join_table = $left['alias'] . '.';
            }
            else {
              $join_table = $info['table'] . '.';
            }
          }

          // Convert a single-valued array of values to the single-value case,
          // and transform from IN() notation to = notation
          if (is_array($info['value']) && count($info['value']) == 1) {
            if (empty($info['operator'])) {
              $operator = '=';
            }
            else {
              $operator = $info['operator'] == 'NOT IN' ? '!=' : '=';
            }
            $info['value'] = array_shift($info['value']);
          }

          if (is_array($info['value'])) {
            // With an array of values, we need multiple placeholders and the
            // 'IN' operator is implicit.
            foreach ($info['value'] as $value) {
              $placeholder_i = ':views_join_condition_' . $select_query->nextPlaceholder();
              $arguments[$placeholder_i] = $value;
            }

            $operator = !empty($info['operator']) ? $info['operator'] : 'IN';
            $placeholder = '( ' . implode(', ', array_keys($arguments)) . ' )';
          }
          else {
            // With a single value, the '=' operator is implicit.
            $operator = !empty($info['operator']) ? $info['operator'] : '=';
            $placeholder = ':views_join_condition_' . $select_query->nextPlaceholder();
            $arguments[$placeholder] = $info['value'];
          }

          $extras[] = "$join_table$info[field] $operator $placeholder";
        }

        if ($extras) {
          if (count($extras) == 1) {
            $condition .= ' AND ' . array_shift($extras);
          }
          else {
            $condition .= ' AND (' . implode(' ' . $this->extra_type . ' ', $extras) . ')';
          }
        }
      }
      elseif ($this->extra && is_string($this->extra)) {
        $condition .= " AND ($this->extra)";
      }
    }

    $select_query->addJoin($this->type, $right_table, $table['alias'], $condition, $arguments);
  }
}
