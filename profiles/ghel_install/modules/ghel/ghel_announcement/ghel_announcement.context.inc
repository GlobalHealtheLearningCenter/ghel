<?php
/**
 * @file
 * ghel_announcement.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_announcement_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'announcements';
  $context->description = 'A context for the Announcements page.';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'announcements' => 'announcements',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ghel_announcements-block_1' => array(
          'module' => 'views',
          'delta' => 'ghel_announcements-block_1',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-announcement_types-block' => array(
          'module' => 'views',
          'delta' => 'announcement_types-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context for the Announcements page.');
  t('page');
  $export['announcements'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_announcement_menu_trail';
  $context->description = 'Set active menu trail for announcements.';
  $context->tag = 'ghel';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ghel_announcement' => 'ghel_announcement',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'node/3',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Set active menu trail for announcements.');
  t('ghel');
  $export['ghel_announcement_menu_trail'] = $context;

  return $export;
}
