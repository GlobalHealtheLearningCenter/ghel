<?php
/**
 * @file
 * ghel_action_plan.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ghel_action_plan_user_default_permissions() {
  $permissions = array();

  // Exported permission: create ghel_action_plan content.
  $permissions['create ghel_action_plan content'] = array(
    'name' => 'create ghel_action_plan content',
    'roles' => array(
      0 => 'learner',
      1 => 'site administrator',
      2 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any ghel_action_plan content.
  $permissions['delete any ghel_action_plan content'] = array(
    'name' => 'delete any ghel_action_plan content',
    'roles' => array(
      0 => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own ghel_action_plan content.
  $permissions['delete own ghel_action_plan content'] = array(
    'name' => 'delete own ghel_action_plan content',
    'roles' => array(
      0 => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any ghel_action_plan content.
  $permissions['edit any ghel_action_plan content'] = array(
    'name' => 'edit any ghel_action_plan content',
    'roles' => array(
      0 => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own ghel_action_plan content.
  $permissions['edit own ghel_action_plan content'] = array(
    'name' => 'edit own ghel_action_plan content',
    'roles' => array(
      0 => 'learner',
      1 => 'site administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
