<?php
/**
 * @file
 * ghel_course.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function ghel_course_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:ghel_course:administrator (unprivileged)'.
  $roles['node:ghel_course:administrator (unprivileged)'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'ghel_course',
    'name' => 'administrator (unprivileged)',
  );

  return $roles;
}
