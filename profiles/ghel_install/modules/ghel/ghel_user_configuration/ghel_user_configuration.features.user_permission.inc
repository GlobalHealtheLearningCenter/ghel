<?php
/**
 * @file
 * ghel_user_configuration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ghel_user_configuration_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'learner' => 'learner',
      'site administrator' => 'site administrator',
      'staff' => 'staff',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'learner' => 'learner',
      'site administrator' => 'site administrator',
      'staff' => 'staff',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access workflow summary views'.
  $permissions['access workflow summary views'] = array(
    'name' => 'access workflow summary views',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'workflow_views',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'ds',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer boxes'.
  $permissions['administer boxes'] = array(
    'name' => 'administer boxes',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'boxes',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'content admin' => 'content admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer group'.
  $permissions['administer group'] = array(
    'name' => 'administer group',
    'roles' => array(
      'content admin' => 'content admin',
      'course publisher' => 'course publisher',
      'site administrator' => 'site administrator',
    ),
    'module' => 'og',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer realname'.
  $permissions['administer realname'] = array(
    'name' => 'administer realname',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'realname',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer sharethis'.
  $permissions['administer sharethis'] = array(
    'name' => 'administer sharethis',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'sharethis',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer workflow'.
  $permissions['administer workflow'] = array(
    'name' => 'administer workflow',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'workflow_admin_ui',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create ghel_discussion content'.
  $permissions['create ghel_discussion content'] = array(
    'name' => 'create ghel_discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create ghel_grp_program content'.
  $permissions['create ghel_grp_program content'] = array(
    'name' => 'create ghel_grp_program content',
    'roles' => array(
      'content admin' => 'content admin',
      'course publisher' => 'course publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create ghel_grp_study content'.
  $permissions['create ghel_grp_study content'] = array(
    'name' => 'create ghel_grp_study content',
    'roles' => array(
      'content admin' => 'content admin',
      'course publisher' => 'course publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create ghel_resource content'.
  $permissions['create ghel_resource content'] = array(
    'name' => 'create ghel_resource content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any ghel_discussion content'.
  $permissions['delete any ghel_discussion content'] = array(
    'name' => 'delete any ghel_discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any ghel_grp_program content'.
  $permissions['delete any ghel_grp_program content'] = array(
    'name' => 'delete any ghel_grp_program content',
    'roles' => array(
      'content admin' => 'content admin',
      'course publisher' => 'course publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any ghel_grp_study content'.
  $permissions['delete any ghel_grp_study content'] = array(
    'name' => 'delete any ghel_grp_study content',
    'roles' => array(
      'content admin' => 'content admin',
      'course publisher' => 'course publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any ghel_resource content'.
  $permissions['delete any ghel_resource content'] = array(
    'name' => 'delete any ghel_resource content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ghel_discussion content'.
  $permissions['delete own ghel_discussion content'] = array(
    'name' => 'delete own ghel_discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own ghel_grp_program content'.
  $permissions['delete own ghel_grp_program content'] = array(
    'name' => 'delete own ghel_grp_program content',
    'roles' => array(
      'content admin' => 'content admin',
      'course publisher' => 'course publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ghel_grp_study content'.
  $permissions['delete own ghel_grp_study content'] = array(
    'name' => 'delete own ghel_grp_study content',
    'roles' => array(
      'content admin' => 'content admin',
      'course publisher' => 'course publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ghel_resource content'.
  $permissions['delete own ghel_resource content'] = array(
    'name' => 'delete own ghel_resource content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any ghel_discussion content'.
  $permissions['edit any ghel_discussion content'] = array(
    'name' => 'edit any ghel_discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any ghel_grp_program content'.
  $permissions['edit any ghel_grp_program content'] = array(
    'name' => 'edit any ghel_grp_program content',
    'roles' => array(
      'content admin' => 'content admin',
      'course publisher' => 'course publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ghel_grp_study content'.
  $permissions['edit any ghel_grp_study content'] = array(
    'name' => 'edit any ghel_grp_study content',
    'roles' => array(
      'content admin' => 'content admin',
      'course publisher' => 'course publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ghel_resource content'.
  $permissions['edit any ghel_resource content'] = array(
    'name' => 'edit any ghel_resource content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit boxes'.
  $permissions['edit boxes'] = array(
    'name' => 'edit boxes',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'boxes',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'learner' => 'learner',
      'site administrator' => 'site administrator',
      'staff' => 'staff',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own ghel_discussion content'.
  $permissions['edit own ghel_discussion content'] = array(
    'name' => 'edit own ghel_discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own ghel_grp_program content'.
  $permissions['edit own ghel_grp_program content'] = array(
    'name' => 'edit own ghel_grp_program content',
    'roles' => array(
      'content admin' => 'content admin',
      'course publisher' => 'course publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ghel_grp_study content'.
  $permissions['edit own ghel_grp_study content'] = array(
    'name' => 'edit own ghel_grp_study content',
    'roles' => array(
      'content admin' => 'content admin',
      'course publisher' => 'course publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ghel_resource content'.
  $permissions['edit own ghel_resource content'] = array(
    'name' => 'edit own ghel_resource content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'migration information'.
  $permissions['migration information'] = array(
    'name' => 'migration information',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'migrate',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'learner' => 'learner',
      'site administrator' => 'site administrator',
      'staff' => 'staff',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'schedule workflow transitions'.
  $permissions['schedule workflow transitions'] = array(
    'name' => 'schedule workflow transitions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'workflow',
  );

  // Exported permission: 'score taken quiz answer'.
  $permissions['score taken quiz answer'] = array(
    'name' => 'score taken quiz answer',
    'roles' => array(),
    'module' => 'quiz',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'learner' => 'learner',
      'site administrator' => 'site administrator',
      'staff' => 'staff',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'use text format ds_code'.
  $permissions['use text format ds_code'] = array(
    'name' => 'use text format ds_code',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view others certificates'.
  $permissions['view others certificates'] = array(
    'name' => 'view others certificates',
    'roles' => array(
      'site administrator' => 'site administrator',
      'staff' => 'staff',
    ),
    'module' => 'ghel_certificate',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'learner' => 'learner',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  return $permissions;
}
