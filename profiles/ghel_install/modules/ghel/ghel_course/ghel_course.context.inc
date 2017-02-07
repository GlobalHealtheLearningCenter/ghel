<?php
/**
 * @file
 * ghel_course.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_course_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'courses';
  $context->description = 'A context for the Courses page.';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'courses' => 'courses',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ghel_courses-block' => array(
          'module' => 'views',
          'delta' => 'ghel_courses-block',
          'region' => 'content',
          'weight' => '1',
        ),
        'ghel_reports-encouragements' => array(
          'module' => 'ghel_reports',
          'delta' => 'encouragements',
          'region' => 'sidebar_second',
          'weight' => '-60',
        ),
        'ghel_reports-completions' => array(
          'module' => 'ghel_reports',
          'delta' => 'completions',
          'region' => 'sidebar_second',
          'weight' => '-59',
        ),
        'views-program_list_block-block' => array(
          'module' => 'views',
          'delta' => 'program_list_block-block',
          'region' => 'sidebar_second',
          'weight' => '-58',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context for the Courses page.');
  t('page');
  $export['courses'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_course_menu_trail';
  $context->description = 'Set active menu trail of courses and course pages.';
  $context->tag = 'ghel';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ghel_course' => 'ghel_course',
        'ghel_course_page' => 'ghel_course_page',
        'ghel_course_section' => 'ghel_course_section',
        'matching' => 'matching',
        'multichoice' => 'multichoice',
        'quiz' => 'quiz',
        'quiz_directions' => 'quiz_directions',
        'truefalse' => 'truefalse',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'node/4',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Set active menu trail of courses and course pages.');
  t('ghel');
  $export['ghel_course_menu_trail'] = $context;

  return $export;
}
