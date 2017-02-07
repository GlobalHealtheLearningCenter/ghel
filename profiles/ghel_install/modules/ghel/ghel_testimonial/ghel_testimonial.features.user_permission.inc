<?php
/**
 * @file
 * ghel_testimonial.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ghel_testimonial_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ghel_testimonial content'.
  $permissions['create ghel_testimonial content'] = array(
    'name' => 'create ghel_testimonial content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any ghel_testimonial content'.
  $permissions['delete any ghel_testimonial content'] = array(
    'name' => 'delete any ghel_testimonial content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own ghel_testimonial content'.
  $permissions['delete own ghel_testimonial content'] = array(
    'name' => 'delete own ghel_testimonial content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any ghel_testimonial content'.
  $permissions['edit any ghel_testimonial content'] = array(
    'name' => 'edit any ghel_testimonial content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own ghel_testimonial content'.
  $permissions['edit own ghel_testimonial content'] = array(
    'name' => 'edit own ghel_testimonial content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
