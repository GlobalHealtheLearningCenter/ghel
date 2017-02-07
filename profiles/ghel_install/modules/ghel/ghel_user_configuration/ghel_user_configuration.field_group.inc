<?php
/**
 * @file
 * ghel_user_configuration.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ghel_user_configuration_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ghel_grp_add|user|user|form';
  $field_group->group_name = 'group_ghel_grp_add';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Information',
    'weight' => '10',
    'children' => array(
      0 => 'field_ghel_text_assoc',
      1 => 'field_ghel_text_bio',
      2 => 'field_ghel_tr_interests',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-ghel-grp-add field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_ghel_grp_add|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ghel_grp_online|user|user|form';
  $field_group->group_name = 'group_ghel_grp_online';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Online Sites',
    'weight' => '9',
    'children' => array(
      0 => 'field_ghel_facebook',
      1 => 'field_ghel_twitter',
      2 => 'field_ghel_website',
      3 => 'field_ghel_link_linkedin',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-ghel-grp-online field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_ghel_grp_online|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional Information');
  t('Online Sites');

  return $field_groups;
}
