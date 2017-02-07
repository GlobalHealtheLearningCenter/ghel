<?php
/**
 * @file
 * ghel_perms_program.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function ghel_perms_program_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:ghel_grp_program:manager'.
  $roles['node:ghel_grp_program:manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'ghel_grp_program',
    'name' => 'manager',
  );

  return $roles;
}
