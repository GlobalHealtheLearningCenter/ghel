<?php
/**
 * @file
 * ghel_trans_perms.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ghel_trans_perms_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ghel_translation content'.
  $permissions['create ghel_translation content'] = array(
    'name' => 'create ghel_translation content',
    'roles' => array(
      'content admin' => 'content admin',
      'content creator' => 'content creator',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any ghel_translation content'.
  $permissions['delete any ghel_translation content'] = array(
    'name' => 'delete any ghel_translation content',
    'roles' => array(
      'content admin' => 'content admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ghel_translation content'.
  $permissions['delete own ghel_translation content'] = array(
    'name' => 'delete own ghel_translation content',
    'roles' => array(
      'content creator' => 'content creator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ghel_translation content'.
  $permissions['edit any ghel_translation content'] = array(
    'name' => 'edit any ghel_translation content',
    'roles' => array(
      'content admin' => 'content admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ghel_translation content'.
  $permissions['edit own ghel_translation content'] = array(
    'name' => 'edit own ghel_translation content',
    'roles' => array(
      'content creator' => 'content creator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
