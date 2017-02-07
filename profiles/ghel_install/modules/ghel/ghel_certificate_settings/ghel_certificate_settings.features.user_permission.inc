<?php
/**
 * @file
 * ghel_certificate_settings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ghel_certificate_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view own certificates'.
  $permissions['view own certificates'] = array(
    'name' => 'view own certificates',
    'roles' => array(
      'learner' => 'learner',
      'site administrator' => 'site administrator',
      'staff' => 'staff',
    ),
    'module' => 'ghel_certificate',
  );

  return $permissions;
}
