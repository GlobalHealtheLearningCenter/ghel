<?php
/**
 * @file
 * ghel_program.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_program_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'certificate_programs';
  $context->description = 'A context for the Certificate Programs page.';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'certificate-programs' => 'certificate-programs',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ghel_reports-encouragements' => array(
          'module' => 'ghel_reports',
          'delta' => 'encouragements',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'ghel_reports-completions' => array(
          'module' => 'ghel_reports',
          'delta' => 'completions',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-certificate_programs-block' => array(
          'module' => 'views',
          'delta' => 'certificate_programs-block',
          'region' => 'below_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context for the Certificate Programs page.');
  t('page');
  $export['certificate_programs'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_program_menu_trail';
  $context->description = 'Set active menu trail for programs.';
  $context->tag = 'ghel';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ghel_program' => 'ghel_program',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'node/8',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Set active menu trail for programs.');
  t('ghel');
  $export['ghel_program_menu_trail'] = $context;

  return $export;
}
