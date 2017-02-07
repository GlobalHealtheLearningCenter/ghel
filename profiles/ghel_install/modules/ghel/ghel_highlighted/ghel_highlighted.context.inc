<?php
/**
 * @file
 * ghel_highlighted.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_highlighted_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_front_page_headline';
  $context->description = 'A context for the headline box.';
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
        'boxes-ghel_headline_box' => array(
          'module' => 'boxes',
          'delta' => 'ghel_headline_box',
          'region' => 'above_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context for the headline box.');
  t('path');
  $export['ghel_front_page_headline'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_front_page_registration_buttons';
  $context->description = 'A context to show the registration buttons on the front page conditionally, based upon whether a user is signed in or anonymous.';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
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
        'boxes-ghel_signup_button_box' => array(
          'module' => 'boxes',
          'delta' => 'ghel_signup_button_box',
          'region' => 'above_content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context to show the registration buttons on the front page conditionally, based upon whether a user is signed in or anonymous.');
  t('page');
  $export['ghel_front_page_registration_buttons'] = $context;

  return $export;
}
