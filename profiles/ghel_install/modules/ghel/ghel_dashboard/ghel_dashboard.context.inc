<?php
/**
 * @file
 * ghel_dashboard.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_dashboard_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_author_dashboard';
  $context->description = 'Blocks for the course author dashboard';
  $context->tag = 'dashboard';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'course creator' => 'course creator',
        'course publisher' => 'course publisher',
        'site administrator' => 'site administrator',
        'staff' => 'staff',
      ),
    ),
    'views' => array(
      'values' => array(
        'ghel_author_tools:page' => 'ghel_author_tools:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ghel_author_my_courses-block_2' => array(
          'module' => 'views',
          'delta' => 'ghel_author_my_courses-block_2',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-ghel_author_my_courses-block_1' => array(
          'module' => 'views',
          'delta' => 'ghel_author_my_courses-block_1',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-ghel_edit_profile-block' => array(
          'module' => 'views',
          'delta' => 'ghel_edit_profile-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'menu-menu-ghel-create-course' => array(
          'module' => 'menu',
          'delta' => 'menu-ghel-create-course',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'menu-menu-ghel-reports' => array(
          'module' => 'menu',
          'delta' => 'menu-ghel-reports',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'author-dashboard',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks for the course author dashboard');
  t('dashboard');
  $export['ghel_author_dashboard'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_learner_dashboard';
  $context->description = 'Blocks for the learner user dashboard';
  $context->tag = 'dashboard';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dashboard' => 'dashboard',
      ),
    ),
    'user' => array(
      'values' => array(
        'learner' => 'learner',
        'staff' => 'staff',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ghel_certificate-courses-in-progress' => array(
          'module' => 'ghel_certificate',
          'delta' => 'courses-in-progress',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-ghel_edit_profile-block' => array(
          'module' => 'views',
          'delta' => 'ghel_edit_profile-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'ghel_reports-encouragements' => array(
          'module' => 'ghel_reports',
          'delta' => 'encouragements',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'ghel_reports-completions' => array(
          'module' => 'ghel_reports',
          'delta' => 'completions',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-b887904bd1981e380220915524d2a354' => array(
          'module' => 'views',
          'delta' => 'b887904bd1981e380220915524d2a354',
          'region' => 'course_blocks_dashboard',
          'weight' => '-10',
        ),
        'views-235527a14f399baa411ca3e6dd15317a' => array(
          'module' => 'views',
          'delta' => '235527a14f399baa411ca3e6dd15317a',
          'region' => 'course_blocks_dashboard',
          'weight' => '-9',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'learner-dashboard',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks for the learner user dashboard');
  t('dashboard');
  $export['ghel_learner_dashboard'] = $context;

  return $export;
}
