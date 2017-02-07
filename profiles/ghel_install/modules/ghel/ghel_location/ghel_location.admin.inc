<?php

/**
 * Implements hook_admin_settings_form().
 */
function ghel_location_admin_settings_form() {
  $current_locations = ghel_location_get_current_locations();
  $country_allowed_values = ghel_location_get_allowed_values('field_ghel_user_location');
  $subregion_allowed_values = ghel_location_get_allowed_values('field_ghel_sub_region');
  $region_allowed_values = ghel_location_get_allowed_values('field_ghel_region');

  list($add_countries, $delete_countries) = ghel_location_update_countries($current_locations, $country_allowed_values);
  if (count($add_countries) > 0) {
    drupal_set_message('The following countries from the field config list will be added upon submit to the region/sub-region mapping table: ' . implode(', ', $add_countries));
  }
  if (count($delete_countries) > 0) {
    drupal_set_message('The following countries will be deleted upon submit from the region/sub-region mapping table: ' . implode(', ', $delete_countries));
  }

  $rows = array();
  // Make it a tree for easier traversing of the entered values on submission.
  $rows['#tree'] = TRUE;
  foreach ($current_locations as $cid => $location) {
    $subregion = (array_key_exists($location['sub_region_key'], $subregion_allowed_values)) ? array('#type' => 'select', '#options' => $subregion_allowed_values, '#default_value' => $location['sub_region_key']) : array('#type' => 'select', '#options' => $subregion_allowed_values, '#prefix' => '<span style="white-space:nowrap; color: red">*</span>', '#default_value' => 0);

    $alt_cid = str_pad($cid, 3, '0', STR_PAD_LEFT);
    if (array_key_exists($alt_cid, $country_allowed_values)) {
      $description = ($location['location_description'] != $country_allowed_values[$alt_cid]) ? $country_allowed_values[$alt_cid] : $location['location_description'];
      $old_description = $location['location_description'];
      $rows[$cid] = array(
        'country' => array('#markup' => check_plain($description)),
        'sub_region_key' => $subregion,
        'region_key' => array('#type' => 'select', '#options' => $region_allowed_values, '#default_value' => $location['region_key']),
      );
    }
  }

  foreach ($add_countries as $cid => $location) {
    $rows[$cid] = array(
      'country' => array('#markup' => check_plain($location)),
      'sub_region_key' => array('#type' => 'select', '#options' => $subregion_allowed_values, '#prefix' => '<span style="white-space:nowrap; color: red">*</span>', '#default_value' => 0),
      'region_key' => array('#type' => 'select', '#options' => $region_allowed_values),
    );
  }
  uasort($rows, 'ghel_location_country_cmp');

  $form['table'] = array(
    // Theme this part of the form as a table.
    '#theme' => 'ghel_location_form_table',
    // Pass header information to the theme function.
    '#header' => array(t('Country'), t('Sub-Region'), t('Region')),
    // Rows in the form table.
    'rows' => $rows,
  );
  $form['add_countries'] = array('#type' => 'hidden', '#value' => $add_countries);
  $form['delete_countries'] = array('#type' => 'hidden', '#value' => $delete_countries);
  $form['db_locations'] = array('#type' => 'hidden', '#value' => $current_locations);

  // Add a submit button for fun.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

function ghel_location_country_cmp($a, $b) {
  return (strcasecmp($a['country']['#markup'], $b['country']['#markup']));
}

/**
 * Theme callback for the form table.
 */
function theme_ghel_location_form_table(&$variables) {
  // Get the userful values.
  $form = $variables['form'];
  $rows = $form['rows'];
  $header = $form['#header'];

  // Setup the structure to be rendered and returned.
  $content = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => array(),
  );

  // Traverse each row.  @see element_chidren().
  foreach (element_children($rows) as $row_index) {
    $row = array();
    // Traverse each column in the row.  @see element_children().
    foreach (element_children($rows[$row_index]) as $col_index) {
      // Render the column form element.
      $row[] = drupal_render($rows[$row_index][$col_index]);
    }
    // Add the row to the table.
    $content['#rows'][] = $row;
  }

  // Redner the table and return.
  return drupal_render($content);
}

/**
 * Form submit handler for ghel_location_form.
 *
 * Handles parsing of passed data changes.
 */
function ghel_location_admin_settings_form_submit($form, &$form_state) {
//dpr($form);
  // Prepare to save form change
  form_state_values_clean($form_state);
  $values = $form_state['input']['rows'];
  $add_countries = $form_state['values']['add_countries'];
  $delete_countries = $form_state['values']['delete_countries'];
  $db_locations = $form_state['values']['db_locations'];

  // First, let's clear out countries to be deleted
  foreach ($delete_countries as $cid => $value) {
    try {
      db_delete('ghel_location_lookup')
        ->condition('location_key', $cid)
        ->execute();
      drupal_set_message("Deleted country $value, with id of $cid, from the lookup table");
    } catch (Exception $d) {
      watchdog_exception('type', $e);
    }
  }

  foreach ($values as $cid => $value) {
    $new_region = $value['region_key'];;
    $old_region = (isset($form_state['complete form']['table']['rows'][$cid]['region_key']['#default_value'])) ? $form_state['complete form']['table']['rows'][$cid]['region_key']['#default_value'] : NULL;
    $new_sub = $value['sub_region_key'];;
    $old_sub = (isset($form_state['complete form']['table']['rows'][$cid]['sub_region_key']['#default_value'])) ? $form_state['complete form']['table']['rows'][$cid]['sub_region_key']['#default_value'] : NULL;
    $country_name = $form_state['complete form']['table']['rows'][$cid]['country']['#markup'];

    // Check for and add new countries
    if (array_key_exists($cid, $add_countries)) {
      try {
        db_insert('ghel_location_lookup')
          ->fields(array(
            'region_key' => $new_region,
            'sub_region_key' => $new_sub,
            'location_description' => $country_name,
            'location_key' => $cid,
          ))
          ->execute();
      } catch (Exception $e) {
        watchdog_exception('type', $e);
      }
    } else {
    // Then update country entries
    $fields = array();

    // Find and save country name updates
    if ($country_name != $db_locations[$cid]['location_description']) {
      $fields['location_description'] = $country_name;
    }
    // Find and save sub_region updates
    if ($new_sub != $old_sub) {
      $fields['sub_region_key'] = $new_sub;
    }
    // Find and save region updates
    if ($new_region != $old_region) {
      $fields['region_key'] = $new_region;
    }
    // Combine update queries, so we don't end up running 2 queries for row
    if (!empty($fields)) {
      drupal_set_message("Updated region/sub-region data for $country_name");
      $query = db_update('ghel_location_lookup')
        ->fields($fields)
        ->condition('location_key', $cid)
        ->execute();
    }
    } // end if country being added
  }
    $new_sub = $value['sub_region_key'];
    $old_sub = $form_state['complete form']['table']['rows'][$cid]['sub_region_key']['#default_value'];
   drupal_set_message(t('Your location/country configuration changes have been saved.'));
}

/**
 * Figures out which countries need updating in the ghel_location_lookup table.
 *
 * $current_locations - a full list of countries and thier associations in db,
 *   provided as an array which key as country id, region_key, sub_region_key,
 *   and location_description as keys of that id's array.
 * $country_allowed_values - array of countries, keyed by id, from
 *   field_ghel_user_location field config: /admin/config/people/accounts/fields/field_ghel_user_location
 *
 * returns array containing an array of countries to add and one of countries to delete.
 */
function ghel_location_update_countries($current_locations, $country_allowed_values) {
  // Create simplified version of $current_locations similar to $country_allowed_values
  $simple_current_locations = array();
  foreach ($current_locations as $id => $data) {
    $simple_current_locations[str_pad($id, 3, '0', STR_PAD_LEFT)] = $data['location_description'];
  }
  $allowed_values = array();
  foreach ($country_allowed_values as $key => $value) {
    $allowed_values[str_pad($key, 3, '0', STR_PAD_LEFT)] = $value;
  }
  $add_countries = array_diff_key($allowed_values, $simple_current_locations);
  $delete_countries = array_diff_key($simple_current_locations, $allowed_values);

  // Now make sure this code is not being used for user location or location fields
  foreach ($delete_countries as $code => $name) {
    $count_user_location = db_select('field_data_field_ghel_user_location', 'fd')
      ->fields('fd', array('entity_id'))
      ->condition('fd.field_ghel_user_location_value', $code)
      ->countQuery()->execute()
      ->fetchField();
    $count_location = db_select('field_data_field_ghel_location', 'fd')
      ->fields('fd', array('entity_id'))
      ->condition('fd.field_ghel_location_value', $code)
      ->countQuery()
      ->execute()
      ->fetchField();
    // If not in use, we can leave it in the list to delete
    if ($count_user_location > 0 || $count_location > 0) {
      unset($delete_countries[$code]);
    }
  }

  return array($add_countries, $delete_countries);
}

/**
 * Helper function to retrieve list of current locations from the ghel_location_lookup table.
 *
 * @return array
 *   Multidimensional list of current locations in the ghel_location_lookup table, keyed by
 *   country id, containing region id, sub-region id and name/description.
 */
function ghel_location_get_current_locations() {
  $locations = array();
  $results = db_query("SELECT  lid, region_key, sub_region_key, location_description, location_key FROM {ghel_location_lookup}");
  foreach ($results as $record) {
    $locations[$record->location_key] = array('region_key' => $record->region_key, 'sub_region_key' => $record->sub_region_key, 'location_description' => $record->location_description);
  }
  return $locations;
}

/**
 * Helper function to retrieve allowed values (country, region or sub-region) from field config.
 *
 * @param string $field_name
 *   The field name for which to check allowed values.
 * @return array
 *   List of allowed options, keyed by their numerical codes (i.e. country codes).
 */
function ghel_location_get_allowed_values($field_name) {
  $field = db_query("SELECT data FROM {field_config} WHERE field_name = :name", array(':name' => $field_name))->fetchField();
  $field_data = unserialize($field);
  return $field_data['settings']['allowed_values'];
}
