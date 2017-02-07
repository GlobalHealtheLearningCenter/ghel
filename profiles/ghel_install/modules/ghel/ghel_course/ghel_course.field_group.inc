<?php
/**
 * @file
 * ghel_course.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ghel_course_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_asideinner|node|ghel_course|full';
  $field_group->group_name = 'group_asideinner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ghel_course';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'aside_inner',
    'weight' => '4',
    'children' => array(
      0 => 'field_ghel_course_authors',
      1 => 'field_ghel_course_managers',
      2 => 'field_ghel_related_courses',
      3 => 'field_ghel_time',
      4 => 'field_ghel_link_toolkits',
      5 => 'field_ghel_pub_up',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'aside_inner',
      'instance_settings' => array(
        'classes' => ' group-asideinner field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_ghel_course_full_group_asideinner',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_asideinner|node|ghel_course|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contentheader|node|ghel_course|full';
  $field_group->group_name = 'group_contentheader';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ghel_course';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'content_header',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'content_header',
      'instance_settings' => array(
        'classes' => 'clearfix group-contentheader field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_ghel_course_full_group_contentheader',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_contentheader|node|ghel_course|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('aside_inner');
  t('content_header');

  return $field_groups;
}
