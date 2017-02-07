<?php
/**
 * @file
 * ghel_sharethis.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_sharethis_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_sharethis';
  $context->description = 'A context placing ShareThis buttons on course pages.';
  $context->tag = 'ghel';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ghel_course' => 'ghel_course',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'sharethis-sharethis_block' => array(
          'module' => 'sharethis',
          'delta' => 'sharethis_block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context placing ShareThis buttons on course pages.');
  t('ghel');
  $export['ghel_sharethis'] = $context;

  return $export;
}
