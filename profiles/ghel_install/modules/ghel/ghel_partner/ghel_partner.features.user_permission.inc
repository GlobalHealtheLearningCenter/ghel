<?php
/**
 * @file
 * ghel_partner.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ghel_partner_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ghel_partner content'.
  $permissions['create ghel_partner content'] = array(
    'name' => 'create ghel_partner content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any ghel_partner content'.
  $permissions['delete any ghel_partner content'] = array(
    'name' => 'delete any ghel_partner content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own ghel_partner content'.
  $permissions['delete own ghel_partner content'] = array(
    'name' => 'delete own ghel_partner content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any ghel_partner content'.
  $permissions['edit any ghel_partner content'] = array(
    'name' => 'edit any ghel_partner content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own ghel_partner content'.
  $permissions['edit own ghel_partner content'] = array(
    'name' => 'edit own ghel_partner content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
