<?php
/**
 * @file
 * ghel_discussion.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ghel_discussion_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_discussion|node|ghel_discussion|default';
  $field_group->group_name = 'group_main_discussion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ghel_discussion';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_ghel_comm_binary',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => ' group-main-discussion field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_main_discussion|node|ghel_discussion|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_discussion|node|ghel_discussion|form';
  $field_group->group_name = 'group_main_discussion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ghel_discussion';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Content Discussion',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_ghel_comm_binary',
      2 => 'field_ghel_post_in',
      3 => 'group_content_access',
      4 => 'title',
      5 => 'path',
      6 => 'workflow',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Main Content Discussion',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-main-discussion field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_ghel_discussion_form_group_main_discussion',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_main_discussion|node|ghel_discussion|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Main Content Discussion');

  return $field_groups;
}
