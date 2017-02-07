<?php
/**
 * @file
 * ghel_faq.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ghel_faq_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ghel_faq content'.
  $permissions['create ghel_faq content'] = array(
    'name' => 'create ghel_faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any ghel_faq content'.
  $permissions['delete any ghel_faq content'] = array(
    'name' => 'delete any ghel_faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own ghel_faq content'.
  $permissions['delete own ghel_faq content'] = array(
    'name' => 'delete own ghel_faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any ghel_faq content'.
  $permissions['edit any ghel_faq content'] = array(
    'name' => 'edit any ghel_faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own ghel_faq content'.
  $permissions['edit own ghel_faq content'] = array(
    'name' => 'edit own ghel_faq content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
