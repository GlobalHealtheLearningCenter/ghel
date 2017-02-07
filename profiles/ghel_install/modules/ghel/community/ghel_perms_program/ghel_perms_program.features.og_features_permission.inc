<?php
/**
 * @file
 * ghel_perms_program.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function ghel_perms_program_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:ghel_grp_program:add user'
  $permissions['node:ghel_grp_program:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_program:administer group'
  $permissions['node:ghel_grp_program:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_program:approve and deny subscription'
  $permissions['node:ghel_grp_program:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_program:create ghel_course_page content'
  $permissions['node:ghel_grp_program:create ghel_course_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:create ghel_course_section content'
  $permissions['node:ghel_grp_program:create ghel_course_section content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:create ghel_discussion content'
  $permissions['node:ghel_grp_program:create ghel_discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_program:create ghel_reference content'
  $permissions['node:ghel_grp_program:create ghel_reference content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:create ghel_resource content'
  $permissions['node:ghel_grp_program:create ghel_resource content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:create matching content'
  $permissions['node:ghel_grp_program:create matching content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:create multichoice content'
  $permissions['node:ghel_grp_program:create multichoice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:create quiz content'
  $permissions['node:ghel_grp_program:create quiz content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:create truefalse content'
  $permissions['node:ghel_grp_program:create truefalse content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete any ghel_course_page content'
  $permissions['node:ghel_grp_program:delete any ghel_course_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete any ghel_course_section content'
  $permissions['node:ghel_grp_program:delete any ghel_course_section content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete any ghel_discussion content'
  $permissions['node:ghel_grp_program:delete any ghel_discussion content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_program:delete any ghel_reference content'
  $permissions['node:ghel_grp_program:delete any ghel_reference content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete any ghel_resource content'
  $permissions['node:ghel_grp_program:delete any ghel_resource content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete any matching content'
  $permissions['node:ghel_grp_program:delete any matching content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete any multichoice content'
  $permissions['node:ghel_grp_program:delete any multichoice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete any quiz content'
  $permissions['node:ghel_grp_program:delete any quiz content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete any truefalse content'
  $permissions['node:ghel_grp_program:delete any truefalse content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete own ghel_course_page content'
  $permissions['node:ghel_grp_program:delete own ghel_course_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete own ghel_course_section content'
  $permissions['node:ghel_grp_program:delete own ghel_course_section content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete own ghel_discussion content'
  $permissions['node:ghel_grp_program:delete own ghel_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete own ghel_reference content'
  $permissions['node:ghel_grp_program:delete own ghel_reference content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete own ghel_resource content'
  $permissions['node:ghel_grp_program:delete own ghel_resource content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete own matching content'
  $permissions['node:ghel_grp_program:delete own matching content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete own multichoice content'
  $permissions['node:ghel_grp_program:delete own multichoice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete own quiz content'
  $permissions['node:ghel_grp_program:delete own quiz content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:delete own truefalse content'
  $permissions['node:ghel_grp_program:delete own truefalse content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:manage members'
  $permissions['node:ghel_grp_program:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_program:manage permissions'
  $permissions['node:ghel_grp_program:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_program:manage roles'
  $permissions['node:ghel_grp_program:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_program:subscribe'
  $permissions['node:ghel_grp_program:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:subscribe without approval'
  $permissions['node:ghel_grp_program:subscribe without approval'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_program:unsubscribe'
  $permissions['node:ghel_grp_program:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_program:update any ghel_course_page content'
  $permissions['node:ghel_grp_program:update any ghel_course_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:update any ghel_course_section content'
  $permissions['node:ghel_grp_program:update any ghel_course_section content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:update any ghel_discussion content'
  $permissions['node:ghel_grp_program:update any ghel_discussion content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_program:update any ghel_reference content'
  $permissions['node:ghel_grp_program:update any ghel_reference content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_program:update any ghel_resource content'
  $permissions['node:ghel_grp_program:update any ghel_resource content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:update any matching content'
  $permissions['node:ghel_grp_program:update any matching content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:update any multichoice content'
  $permissions['node:ghel_grp_program:update any multichoice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:update any quiz content'
  $permissions['node:ghel_grp_program:update any quiz content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:update any truefalse content'
  $permissions['node:ghel_grp_program:update any truefalse content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:update group'
  $permissions['node:ghel_grp_program:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_program:update own ghel_course_page content'
  $permissions['node:ghel_grp_program:update own ghel_course_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:update own ghel_course_section content'
  $permissions['node:ghel_grp_program:update own ghel_course_section content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:update own ghel_discussion content'
  $permissions['node:ghel_grp_program:update own ghel_discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_program:update own ghel_reference content'
  $permissions['node:ghel_grp_program:update own ghel_reference content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:update own ghel_resource content'
  $permissions['node:ghel_grp_program:update own ghel_resource content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:update own matching content'
  $permissions['node:ghel_grp_program:update own matching content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:update own multichoice content'
  $permissions['node:ghel_grp_program:update own multichoice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:update own quiz content'
  $permissions['node:ghel_grp_program:update own quiz content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_program:update own truefalse content'
  $permissions['node:ghel_grp_program:update own truefalse content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
