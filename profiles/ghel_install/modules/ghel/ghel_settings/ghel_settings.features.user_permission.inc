<?php
/**
 * @file
 * ghel_settings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ghel_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'search',
  );

  return $permissions;
}
