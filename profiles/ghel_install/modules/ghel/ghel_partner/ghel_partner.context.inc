<?php
/**
 * @file
 * ghel_partner.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_partner_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'partners';
  $context->description = 'A context for the Partners page.';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about/partners' => 'about/partners',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-partners_page-block' => array(
          'module' => 'views',
          'delta' => 'partners_page-block',
          'region' => 'content',
          'weight' => '2',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context for the Partners page.');
  t('page');
  $export['partners'] = $context;

  return $export;
}
