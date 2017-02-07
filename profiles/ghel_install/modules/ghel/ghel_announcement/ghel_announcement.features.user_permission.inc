<?php
/**
 * @file
 * ghel_announcement.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ghel_announcement_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ghel_announcement content'.
  $permissions['create ghel_announcement content'] = array(
    'name' => 'create ghel_announcement content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any ghel_announcement content'.
  $permissions['delete any ghel_announcement content'] = array(
    'name' => 'delete any ghel_announcement content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own ghel_announcement content'.
  $permissions['delete own ghel_announcement content'] = array(
    'name' => 'delete own ghel_announcement content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any ghel_announcement content'.
  $permissions['edit any ghel_announcement content'] = array(
    'name' => 'edit any ghel_announcement content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own ghel_announcement content'.
  $permissions['edit own ghel_announcement content'] = array(
    'name' => 'edit own ghel_announcement content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
