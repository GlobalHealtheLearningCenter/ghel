<?php
/**
 * @file
 * ghel_course.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ghel_course_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_translation_files'.
  $field_bases['field_translation_files'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_translation_files',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  return $field_bases;
}
