<?php
/**
 * @file
 * ghel_reference.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ghel_reference_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ghel_reference content'.
  $permissions['create ghel_reference content'] = array(
    'name' => 'create ghel_reference content',
    'roles' => array(
      'course publisher' => 'course publisher',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any ghel_reference content'.
  $permissions['delete any ghel_reference content'] = array(
    'name' => 'delete any ghel_reference content',
    'roles' => array(
      'course publisher' => 'course publisher',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ghel_reference content'.
  $permissions['delete own ghel_reference content'] = array(
    'name' => 'delete own ghel_reference content',
    'roles' => array(
      'course publisher' => 'course publisher',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ghel_reference content'.
  $permissions['edit any ghel_reference content'] = array(
    'name' => 'edit any ghel_reference content',
    'roles' => array(
      'course publisher' => 'course publisher',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ghel_reference content'.
  $permissions['edit own ghel_reference content'] = array(
    'name' => 'edit own ghel_reference content',
    'roles' => array(
      'course publisher' => 'course publisher',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
