<?php
/**
 * @file
 * ghel_action_plan.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_action_plan_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_action_plan';
  $context->description = 'Active context on action plan nodes';
  $context->tag = 'ghel';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ghel_action_plan' => 'ghel_action_plan',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ghel_action_plan-links' => array(
          'module' => 'ghel_action_plan',
          'delta' => 'links',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'context-action-plan',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active context on action plan nodes');
  t('ghel');
  $export['ghel_action_plan'] = $context;

  return $export;
}
