<?php
/**
 * @file
 * ghel_course.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function ghel_course_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:ghel_course:add user'
  $permissions['node:ghel_course:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:administer group'
  $permissions['node:ghel_course:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:approve and deny subscription'
  $permissions['node:ghel_course:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:create ghel_course_page content'
  $permissions['node:ghel_course:create ghel_course_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:create ghel_course_section content'
  $permissions['node:ghel_course:create ghel_course_section content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:create ghel_reference content'
  $permissions['node:ghel_course:create ghel_reference content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:create matching content'
  $permissions['node:ghel_course:create matching content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:create multichoice content'
  $permissions['node:ghel_course:create multichoice content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:create quiz content'
  $permissions['node:ghel_course:create quiz content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:create truefalse content'
  $permissions['node:ghel_course:create truefalse content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:delete any ghel_course_page content'
  $permissions['node:ghel_course:delete any ghel_course_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:delete any ghel_course_section content'
  $permissions['node:ghel_course:delete any ghel_course_section content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:delete any ghel_reference content'
  $permissions['node:ghel_course:delete any ghel_reference content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:delete any matching content'
  $permissions['node:ghel_course:delete any matching content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:delete any multichoice content'
  $permissions['node:ghel_course:delete any multichoice content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:delete any quiz content'
  $permissions['node:ghel_course:delete any quiz content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:delete any truefalse content'
  $permissions['node:ghel_course:delete any truefalse content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:delete own ghel_course_page content'
  $permissions['node:ghel_course:delete own ghel_course_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:delete own ghel_course_section content'
  $permissions['node:ghel_course:delete own ghel_course_section content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:delete own ghel_reference content'
  $permissions['node:ghel_course:delete own ghel_reference content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:delete own matching content'
  $permissions['node:ghel_course:delete own matching content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:delete own multichoice content'
  $permissions['node:ghel_course:delete own multichoice content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:delete own quiz content'
  $permissions['node:ghel_course:delete own quiz content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:delete own truefalse content'
  $permissions['node:ghel_course:delete own truefalse content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:manage members'
  $permissions['node:ghel_course:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:manage permissions'
  $permissions['node:ghel_course:manage permissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_course:manage roles'
  $permissions['node:ghel_course:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_course:subscribe'
  $permissions['node:ghel_course:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_course:subscribe without approval'
  $permissions['node:ghel_course:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:ghel_course:unsubscribe'
  $permissions['node:ghel_course:unsubscribe'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update any ghel_course_page content'
  $permissions['node:ghel_course:update any ghel_course_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update any ghel_course_section content'
  $permissions['node:ghel_course:update any ghel_course_section content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update any ghel_reference content'
  $permissions['node:ghel_course:update any ghel_reference content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update any matching content'
  $permissions['node:ghel_course:update any matching content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update any multichoice content'
  $permissions['node:ghel_course:update any multichoice content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update any quiz content'
  $permissions['node:ghel_course:update any quiz content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update any truefalse content'
  $permissions['node:ghel_course:update any truefalse content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update group'
  $permissions['node:ghel_course:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update own ghel_course_page content'
  $permissions['node:ghel_course:update own ghel_course_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update own ghel_course_section content'
  $permissions['node:ghel_course:update own ghel_course_section content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update own ghel_reference content'
  $permissions['node:ghel_course:update own ghel_reference content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update own matching content'
  $permissions['node:ghel_course:update own matching content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update own multichoice content'
  $permissions['node:ghel_course:update own multichoice content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update own quiz content'
  $permissions['node:ghel_course:update own quiz content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:ghel_course:update own truefalse content'
  $permissions['node:ghel_course:update own truefalse content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  return $permissions;
}
