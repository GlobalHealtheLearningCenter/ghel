<?php
/**
 * @file
 * ghel_achievements_settings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ghel_achievements_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access achievements'.
  $permissions['access achievements'] = array(
    'name' => 'access achievements',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'achievements',
  );

  // Exported permission: 'administer achievements'.
  $permissions['administer achievements'] = array(
    'name' => 'administer achievements',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'achievements',
  );

  // Exported permission: 'earn achievements'.
  $permissions['earn achievements'] = array(
    'name' => 'earn achievements',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'learner' => 'learner',
      'site administrator' => 'site administrator',
      'staff' => 'staff',
    ),
    'module' => 'achievements',
  );

  return $permissions;
}
