<?php
/**
 * @file
 * ghel_trans_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_trans_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_trans_context';
  $context->description = 'Context for Translated Courses';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/11358' => 'node/11358',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ghel_trans_views-block' => array(
          'module' => 'views',
          'delta' => 'ghel_trans_views-block',
          'region' => 'content',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for Translated Courses');
  t('page');
  $export['ghel_trans_context'] = $context;

  return $export;
}
