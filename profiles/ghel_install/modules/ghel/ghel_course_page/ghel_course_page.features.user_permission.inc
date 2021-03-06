<?php
/**
 * @file
 * ghel_course_page.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ghel_course_page_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ghel_course_page content'.
  $permissions['create ghel_course_page content'] = array(
    'name' => 'create ghel_course_page content',
    'roles' => array(
      'course creator' => 'course creator',
      'course publisher' => 'course publisher',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any ghel_course_page content'.
  $permissions['delete any ghel_course_page content'] = array(
    'name' => 'delete any ghel_course_page content',
    'roles' => array(
      'course publisher' => 'course publisher',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ghel_course_page content'.
  $permissions['delete own ghel_course_page content'] = array(
    'name' => 'delete own ghel_course_page content',
    'roles' => array(
      'course creator' => 'course creator',
      'course publisher' => 'course publisher',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ghel_course_page content'.
  $permissions['edit any ghel_course_page content'] = array(
    'name' => 'edit any ghel_course_page content',
    'roles' => array(
      'course publisher' => 'course publisher',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ghel_course_page content'.
  $permissions['edit own ghel_course_page content'] = array(
    'name' => 'edit own ghel_course_page content',
    'roles' => array(
      'course creator' => 'course creator',
      'course publisher' => 'course publisher',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
