<?php
/**
 * @file
 * ghel_spam.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ghel_spam_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag ghel_flag_comment_abuse'.
  $permissions['flag ghel_flag_comment_abuse'] = array(
    'name' => 'flag ghel_flag_comment_abuse',
    'roles' => array(
      'learner' => 'learner',
      'staff' => 'staff',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag ghel_flag_comment_abuse'.
  $permissions['unflag ghel_flag_comment_abuse'] = array(
    'name' => 'unflag ghel_flag_comment_abuse',
    'roles' => array(
      'learner' => 'learner',
      'staff' => 'staff',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
