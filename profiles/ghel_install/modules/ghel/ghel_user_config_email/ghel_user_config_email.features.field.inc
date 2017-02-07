<?php
/**
 * @file
 * ghel_user_config_email.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function ghel_user_config_email_field_default_fields() {
  $fields = array();

  // Exported field: 'user-user-field_ghel_cert_revocation'.
  $fields['user-user-field_ghel_cert_revocation'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_ghel_cert_revocation',
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
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
        'entity_translation_sync' => FALSE,
      ),
      'translatable' => '1',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'deleted' => '0',
      'description' => 'Your earned course and program certificates will become outdated when courses are revised or when courses are added to a program. Check this box to be notified when completed courses start undergoing revisions, when revised courses are available, and when courses are added to your completed programs.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 19,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'user',
      'field_name' => 'field_ghel_cert_revocation',
      'formblock_expose' => 0,
      'label' => 'Notify me when my certificates become outdated',
      'required' => 0,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'user_register_form' => 1,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '20',
      ),
    ),
  );

  // Exported field: 'user-user-field_ghel_reminder'.
  $fields['user-user-field_ghel_reminder'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_ghel_reminder',
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
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
        'entity_translation_sync' => FALSE,
      ),
      'translatable' => '1',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'deleted' => '0',
      'description' => 'Check this box to be reminded to complete courses that you have started but not yet completed. These reminders will be sent out one month after you have started the course, and again after three months.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 20,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'user',
      'field_name' => 'field_ghel_reminder',
      'formblock_expose' => 0,
      'label' => 'Remind me to complete courses I have started',
      'required' => 0,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'user_register_form' => 1,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '21',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Check this box to be reminded to complete courses that you have started but not yet completed. These reminders will be sent out one month after you have started the course, and again after three months.');
  t('Notify me when my certificates become outdated');
  t('Remind me to complete courses I have started');
  t('Your earned course and program certificates will become outdated when courses are revised or when courses are added to a program. Check this box to be notified when completed courses start undergoing revisions, when revised courses are available, and when courses are added to your completed programs.');

  return $fields;
}
