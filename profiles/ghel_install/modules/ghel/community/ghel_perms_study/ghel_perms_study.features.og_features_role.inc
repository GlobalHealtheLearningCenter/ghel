<?php
/**
 * @file
 * ghel_perms_study.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function ghel_perms_study_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:ghel_grp_study:manager'.
  $roles['node:ghel_grp_study:manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'ghel_grp_study',
    'name' => 'manager',
  );

  return $roles;
}
