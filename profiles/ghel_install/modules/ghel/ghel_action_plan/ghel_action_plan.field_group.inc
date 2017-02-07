<?php
/**
 * @file
 * ghel_action_plan.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ghel_action_plan_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ghel_ap_fq|node|ghel_action_plan|default';
  $field_group->group_name = 'group_ghel_ap_fq';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ghel_action_plan';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Follow Up Questions',
    'weight' => '3',
    'children' => array(
      0 => 'field_ghel_fu_barriers',
      1 => 'field_ghel_implement',
      2 => 'field_ghel_know_gaps',
      3 => 'field_ghel_measure',
      4 => 'field_ghel_refresher',
      5 => 'field_ghel_valuable',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_ghel_ap_fq|node|ghel_action_plan|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ghel_ap_fq|node|ghel_action_plan|full';
  $field_group->group_name = 'group_ghel_ap_fq';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ghel_action_plan';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Follow Up Questions',
    'weight' => '3',
    'children' => array(
      0 => 'field_ghel_fu_barriers',
      1 => 'field_ghel_implement',
      2 => 'field_ghel_know_gaps',
      3 => 'field_ghel_measure',
      4 => 'field_ghel_refresher',
      5 => 'field_ghel_valuable',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_ghel_ap_fq|node|ghel_action_plan|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ghel_ap_iq|node|ghel_action_plan|default';
  $field_group->group_name = 'group_ghel_ap_iq';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ghel_action_plan';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Initial Questions',
    'weight' => '2',
    'children' => array(
      0 => 'field_ghel_barriers',
      1 => 'field_ghel_gaps',
      2 => 'field_ghel_job_behav',
      3 => 'field_ghel_plan',
      4 => 'field_ghel_support',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_ghel_ap_iq|node|ghel_action_plan|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ghel_ap_iq|node|ghel_action_plan|full';
  $field_group->group_name = 'group_ghel_ap_iq';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ghel_action_plan';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Initial Questions',
    'weight' => '2',
    'children' => array(
      0 => 'field_ghel_barriers',
      1 => 'field_ghel_gaps',
      2 => 'field_ghel_job_behav',
      3 => 'field_ghel_plan',
      4 => 'field_ghel_support',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_ghel_ap_iq|node|ghel_action_plan|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ghel_fq|node|ghel_action_plan|form';
  $field_group->group_name = 'group_ghel_fq';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ghel_action_plan';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Follow Up Questions',
    'weight' => '4',
    'children' => array(
      0 => 'field_ghel_fu_barriers',
      1 => 'field_ghel_implement',
      2 => 'field_ghel_know_gaps',
      3 => 'field_ghel_measure',
      4 => 'field_ghel_refresher',
      5 => 'field_ghel_valuable',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Follow Up Questions',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Answer the questions in this section three to six months after completing the course.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_ghel_fq|node|ghel_action_plan|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ghel_iq|node|ghel_action_plan|form';
  $field_group->group_name = 'group_ghel_iq';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ghel_action_plan';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Initial Questions',
    'weight' => '3',
    'children' => array(
      0 => 'field_ghel_barriers',
      1 => 'field_ghel_gaps',
      2 => 'field_ghel_job_behav',
      3 => 'field_ghel_plan',
      4 => 'field_ghel_support',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Initial Questions',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Answer the questions in this section directly after completing the course.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_ghel_iq|node|ghel_action_plan|form'] = $field_group;

  return $export;
}
