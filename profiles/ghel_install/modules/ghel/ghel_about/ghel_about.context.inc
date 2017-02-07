<?php
/**
 * @file
 * ghel_about.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_about_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'about';
  $context->description = 'A context for the About page and subpages.';
  $context->tag = 'page';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'node/7' => 'node/7',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-ghel_about_menu_blocks-5' => array(
          'module' => 'menu_block',
          'delta' => 'ghel_about_menu_blocks-5',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'about-section',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context for the About page and subpages.');
  t('page');
  $export['about'] = $context;

  return $export;
}
