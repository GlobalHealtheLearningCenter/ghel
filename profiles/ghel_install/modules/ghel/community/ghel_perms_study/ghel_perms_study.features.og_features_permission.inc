<?php
/**
 * @file
 * ghel_perms_study.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function ghel_perms_study_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:ghel_grp_study:add user'
  $permissions['node:ghel_grp_study:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:administer group'
  $permissions['node:ghel_grp_study:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:approve and deny subscription'
  $permissions['node:ghel_grp_study:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:create ghel_course_page content'
  $permissions['node:ghel_grp_study:create ghel_course_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:create ghel_course_section content'
  $permissions['node:ghel_grp_study:create ghel_course_section content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:create ghel_discussion content'
  $permissions['node:ghel_grp_study:create ghel_discussion content'] = array(
    'roles' => array(
      'manager' => 'manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:create ghel_reference content'
  $permissions['node:ghel_grp_study:create ghel_reference content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:create ghel_resource content'
  $permissions['node:ghel_grp_study:create ghel_resource content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:create matching content'
  $permissions['node:ghel_grp_study:create matching content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:create multichoice content'
  $permissions['node:ghel_grp_study:create multichoice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:create quiz content'
  $permissions['node:ghel_grp_study:create quiz content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:create truefalse content'
  $permissions['node:ghel_grp_study:create truefalse content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete any ghel_course_page content'
  $permissions['node:ghel_grp_study:delete any ghel_course_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete any ghel_course_section content'
  $permissions['node:ghel_grp_study:delete any ghel_course_section content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete any ghel_discussion content'
  $permissions['node:ghel_grp_study:delete any ghel_discussion content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:delete any ghel_reference content'
  $permissions['node:ghel_grp_study:delete any ghel_reference content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete any ghel_resource content'
  $permissions['node:ghel_grp_study:delete any ghel_resource content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:delete any matching content'
  $permissions['node:ghel_grp_study:delete any matching content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete any multichoice content'
  $permissions['node:ghel_grp_study:delete any multichoice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete any quiz content'
  $permissions['node:ghel_grp_study:delete any quiz content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete any truefalse content'
  $permissions['node:ghel_grp_study:delete any truefalse content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete own ghel_course_page content'
  $permissions['node:ghel_grp_study:delete own ghel_course_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete own ghel_course_section content'
  $permissions['node:ghel_grp_study:delete own ghel_course_section content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete own ghel_discussion content'
  $permissions['node:ghel_grp_study:delete own ghel_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete own ghel_reference content'
  $permissions['node:ghel_grp_study:delete own ghel_reference content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete own ghel_resource content'
  $permissions['node:ghel_grp_study:delete own ghel_resource content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete own matching content'
  $permissions['node:ghel_grp_study:delete own matching content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete own multichoice content'
  $permissions['node:ghel_grp_study:delete own multichoice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete own quiz content'
  $permissions['node:ghel_grp_study:delete own quiz content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:delete own truefalse content'
  $permissions['node:ghel_grp_study:delete own truefalse content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:manage members'
  $permissions['node:ghel_grp_study:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:manage permissions'
  $permissions['node:ghel_grp_study:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:manage roles'
  $permissions['node:ghel_grp_study:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:subscribe'
  $permissions['node:ghel_grp_study:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:subscribe without approval'
  $permissions['node:ghel_grp_study:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:unsubscribe'
  $permissions['node:ghel_grp_study:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:update any ghel_course_page content'
  $permissions['node:ghel_grp_study:update any ghel_course_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:update any ghel_course_section content'
  $permissions['node:ghel_grp_study:update any ghel_course_section content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:update any ghel_discussion content'
  $permissions['node:ghel_grp_study:update any ghel_discussion content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:update any ghel_reference content'
  $permissions['node:ghel_grp_study:update any ghel_reference content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:update any ghel_resource content'
  $permissions['node:ghel_grp_study:update any ghel_resource content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:update any matching content'
  $permissions['node:ghel_grp_study:update any matching content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:update any multichoice content'
  $permissions['node:ghel_grp_study:update any multichoice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:update any quiz content'
  $permissions['node:ghel_grp_study:update any quiz content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:update any truefalse content'
  $permissions['node:ghel_grp_study:update any truefalse content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:update group'
  $permissions['node:ghel_grp_study:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:update own ghel_course_page content'
  $permissions['node:ghel_grp_study:update own ghel_course_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:update own ghel_course_section content'
  $permissions['node:ghel_grp_study:update own ghel_course_section content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:update own ghel_discussion content'
  $permissions['node:ghel_grp_study:update own ghel_discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:update own ghel_reference content'
  $permissions['node:ghel_grp_study:update own ghel_reference content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:update own ghel_resource content'
  $permissions['node:ghel_grp_study:update own ghel_resource content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:ghel_grp_study:update own matching content'
  $permissions['node:ghel_grp_study:update own matching content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:update own multichoice content'
  $permissions['node:ghel_grp_study:update own multichoice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:update own quiz content'
  $permissions['node:ghel_grp_study:update own quiz content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_grp_study:update own truefalse content'
  $permissions['node:ghel_grp_study:update own truefalse content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
