<?php
/**
 * @file
 * ghel_faq.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_faq_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_faq';
  $context->description = 'A context for the FAQ page.';
  $context->tag = 'ghel';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'faq*' => 'faq*',
        'about/faq*' => 'about/faq*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-faqs-block' => array(
          'module' => 'views',
          'delta' => 'faqs-block',
          'region' => 'content',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context for the FAQ page.');
  t('ghel');
  $export['ghel_faq'] = $context;

  return $export;
}
