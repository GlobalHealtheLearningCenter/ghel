<?php
/**
 * @file
 * ghel_reports.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_reports_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_reports';
  $context->description = 'Show menu for all reports';
  $context->tag = 'reports';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'program-participants/find*' => 'program-participants/find*',
        'reports/*' => 'reports/*',
        'course-list/admin' => 'course-list/admin',
        'course-admin*' => 'course-admin*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-ghel-reports' => array(
          'module' => 'menu',
          'delta' => 'menu-ghel-reports',
          'region' => 'above_content',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'context-reports',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Show menu for all reports');
  t('reports');
  $export['ghel_reports'] = $context;

  return $export;
}
