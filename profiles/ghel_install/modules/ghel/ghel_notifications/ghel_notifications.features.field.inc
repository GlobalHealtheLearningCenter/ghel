<?php
/**
 * @file
 * ghel_notifications.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function ghel_notifications_field_default_fields() {
  $fields = array();

  // Exported field: 'user-user-field_ghel_notifications'.
  $fields['user-user-field_ghel_notifications'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_ghel_notifications',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          86400 => 'Daily',
          302400 => 'Semiweekly',
          604800 => 'Weekly',
          0 => 'Never',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_integer',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => array(
        0 => array(
          'value' => 604800,
        ),
      ),
      'deleted' => '0',
      'description' => 'How often would you prefer to receive notifications about activity in your program groups?',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 18,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'user',
      'field_name' => 'field_ghel_notifications',
      'formblock_expose' => 0,
      'label' => 'Notify me of new content in my program groups',
      'required' => 0,
      'settings' => array(
        'user_register_form' => 1,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '19',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('How often would you prefer to receive notifications about activity in your program groups?');
  t('Notify me of new content in my program groups');

  return $fields;
}
