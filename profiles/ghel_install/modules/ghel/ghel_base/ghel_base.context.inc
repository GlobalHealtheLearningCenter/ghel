<?php
/**
 * @file
 * ghel_base.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_base_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_front_page';
  $context->description = 'A context for the front page.';
  $context->tag = 'path';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ghel_featured_courses-block' => array(
          'module' => 'views',
          'delta' => 'ghel_featured_courses-block',
          'region' => 'above_content',
          'weight' => '-8',
        ),
        'views-035d3df99f27c035491978a040a0b516' => array(
          'module' => 'views',
          'delta' => '035d3df99f27c035491978a040a0b516',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-ghel_announcements-block_2' => array(
          'module' => 'views',
          'delta' => 'ghel_announcements-block_2',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-ghel_testimonials-block' => array(
          'module' => 'views',
          'delta' => 'ghel_testimonials-block',
          'region' => 'content',
          'weight' => '-8',
        ),
        'ghel_reports-observations' => array(
          'module' => 'ghel_reports',
          'delta' => 'observations',
          'region' => 'below_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context for the front page.');
  t('path');
  $export['ghel_front_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global';
  $context->description = 'A context for the global elements on the site.';
  $context->tag = 'global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-ghel_base_menu_blocks-2' => array(
          'module' => 'menu_block',
          'delta' => 'ghel_base_menu_blocks-2',
          'region' => 'util_nav',
          'weight' => '-61',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'util_nav',
          'weight' => '-60',
        ),
        'menu_block-ghel_base_menu_blocks-1' => array(
          'module' => 'menu_block',
          'delta' => 'ghel_base_menu_blocks-1',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'menu_block-ghel_base_menu_blocks-4' => array(
          'module' => 'menu_block',
          'delta' => 'ghel_base_menu_blocks-4',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context for the global elements on the site.');
  t('global');
  $export['global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global_anon';
  $context->description = 'Global nav for non-logged-in users';
  $context->tag = 'global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'util_nav',
          'weight' => '-10',
        ),
        'menu_block-ghel_base_menu_blocks-1' => array(
          'module' => 'menu_block',
          'delta' => 'ghel_base_menu_blocks-1',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'menu_block-ghel_base_menu_blocks-4' => array(
          'module' => 'menu_block',
          'delta' => 'ghel_base_menu_blocks-4',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global nav for non-logged-in users');
  t('global');
  $export['global_anon'] = $context;

  return $export;
}
