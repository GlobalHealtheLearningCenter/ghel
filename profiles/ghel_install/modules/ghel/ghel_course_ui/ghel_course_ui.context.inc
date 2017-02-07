<?php
/**
 * @file
 * ghel_course_ui.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_course_ui_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_course_expert_feedback';
  $context->description = 'Feedback block for course expert';
  $context->tag = 'ghel';
  $context->conditions = array(
    'context_og_condition_member_role' => array(
      'values' => array(
        2 => 2,
      ),
      'options' => array(
        'node_form' => 0,
      ),
    ),
    'learner' => array(
      'values' => array(
        1 => '1',
      ),
    ),
    'node' => array(
      'values' => array(
        'ghel_course_page' => 'ghel_course_page',
        'ghel_course_section' => 'ghel_course_section',
        'quiz' => 'quiz',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ghel_course_feedback-block' => array(
          'module' => 'views',
          'delta' => 'ghel_course_feedback-block',
          'region' => 'tab_feedback',
          'weight' => '-49',
        ),
        'formblock-comment' => array(
          'module' => 'formblock',
          'delta' => 'comment',
          'region' => 'tab_feedback',
          'weight' => '-48',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Feedback block for course expert');
  t('ghel');
  $export['ghel_course_expert_feedback'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_course_page_creation';
  $context->description = 'Blocks for the course pages on course creation';
  $context->tag = 'ghel';
  $context->conditions = array(
    'learner' => array(
      'values' => array(
        2 => '2',
      ),
    ),
    'node' => array(
      'values' => array(
        'ghel_course_page' => 'ghel_course_page',
        'ghel_course_section' => 'ghel_course_section',
        'quiz' => 'quiz',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'user' => array(
      'values' => array(
        'course creator' => 'course creator',
        'course publisher' => 'course publisher',
        'site administrator' => 'site administrator',
        'staff' => 'staff',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ghel_learner_toggle-learnertoggle' => array(
          'module' => 'ghel_learner_toggle',
          'delta' => 'learnertoggle',
          'region' => 'course_navigation',
          'weight' => '-10',
        ),
        'ghel_course-previous' => array(
          'module' => 'ghel_course',
          'delta' => 'previous',
          'region' => 'below_content_course_one',
          'weight' => '-10',
        ),
        'ghel_course-next' => array(
          'module' => 'ghel_course',
          'delta' => 'next',
          'region' => 'below_content_course_one',
          'weight' => '-9',
        ),
        'ghel_course-create' => array(
          'module' => 'ghel_course',
          'delta' => 'create',
          'region' => 'tab_pages',
          'weight' => '-61',
        ),
        'views-ghel_course_reference-block' => array(
          'module' => 'views',
          'delta' => 'ghel_course_reference-block',
          'region' => 'tab_pages',
          'weight' => '-60',
        ),
        'formblock-17b8673cd180c04ed181dd568026e09b' => array(
          'module' => 'formblock',
          'delta' => '17b8673cd180c04ed181dd568026e09b',
          'region' => 'tab_pages',
          'weight' => '-59',
        ),
        'formblock-workflow' => array(
          'module' => 'formblock',
          'delta' => 'workflow',
          'region' => 'tab_feedback',
          'weight' => '-10',
        ),
        'views-ghel_course_feedback-block' => array(
          'module' => 'views',
          'delta' => 'ghel_course_feedback-block',
          'region' => 'tab_feedback',
          'weight' => '-9',
        ),
        'formblock-comment' => array(
          'module' => 'formblock',
          'delta' => 'comment',
          'region' => 'tab_feedback',
          'weight' => '-8',
        ),
        'formblock-78aa48c21f1193199fe8163ee541b8d7' => array(
          'module' => 'formblock',
          'delta' => '78aa48c21f1193199fe8163ee541b8d7',
          'region' => 'tab_glossary',
          'weight' => '-10',
        ),
        'formblock-94e8460f62ffd8c7d136ff8195a2ad2f' => array(
          'module' => 'formblock',
          'delta' => '94e8460f62ffd8c7d136ff8195a2ad2f',
          'region' => 'tab_glossary',
          'weight' => '-10',
        ),
        'views-ghel_glossary_links-block_1' => array(
          'module' => 'views',
          'delta' => 'ghel_glossary_links-block_1',
          'region' => 'tab_glossary',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks for the course pages on course creation');
  t('ghel');
  $export['ghel_course_page_creation'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_learner_course';
  $context->description = 'Blocks for learner taking a course';
  $context->tag = 'ghel';
  $context->conditions = array(
    'learner' => array(
      'values' => array(
        1 => '1',
      ),
    ),
    'node' => array(
      'values' => array(
        'ghel_course_page' => 'ghel_course_page',
        'ghel_course_section' => 'ghel_course_section',
        'quiz' => 'quiz',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ghel_learner_toggle-learnertoggle' => array(
          'module' => 'ghel_learner_toggle',
          'delta' => 'learnertoggle',
          'region' => 'course_navigation',
          'weight' => '-10',
        ),
        'ghel_course-previous' => array(
          'module' => 'ghel_course',
          'delta' => 'previous',
          'region' => 'below_content_course_one',
          'weight' => '-10',
        ),
        'ghel_course-next' => array(
          'module' => 'ghel_course',
          'delta' => 'next',
          'region' => 'below_content_course_one',
          'weight' => '-9',
        ),
        'course_progress-course_progress_bar' => array(
          'module' => 'course_progress',
          'delta' => 'course_progress_bar',
          'region' => 'below_content_course_two',
          'weight' => '-10',
        ),
        'views-ghel_course_feedback-block' => array(
          'module' => 'views',
          'delta' => 'ghel_course_feedback-block',
          'region' => 'tab_feedback',
          'weight' => '-10',
        ),
        'views-b39bb4df67474432bbe525db0473cdc6' => array(
          'module' => 'views',
          'delta' => 'b39bb4df67474432bbe525db0473cdc6',
          'region' => 'tab_glossary',
          'weight' => '-10',
        ),
        'views-ghel_glossary_links-block' => array(
          'module' => 'views',
          'delta' => 'ghel_glossary_links-block',
          'region' => 'tab_glossary',
          'weight' => '-9',
        ),
        'ghel_toc_widget-navigation' => array(
          'module' => 'ghel_toc_widget',
          'delta' => 'navigation',
          'region' => 'tab_course',
          'weight' => '-10',
        ),
        'views-ghel_course_ref_node-block' => array(
          'module' => 'views',
          'delta' => 'ghel_course_ref_node-block',
          'region' => 'tab_reference',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks for learner taking a course');
  t('ghel');
  $export['ghel_learner_course'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_learner_quiz_question';
  $context->description = 'Blocks for quiz question nodes';
  $context->tag = 'ghel';
  $context->conditions = array(
    'learner' => array(
      'values' => array(
        1 => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'node/*/take' => 'node/*/take',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ghel_course-next' => array(
          'module' => 'ghel_course',
          'delta' => 'next',
          'region' => 'below_content_course_one',
          'weight' => '-9',
        ),
        'ghel_toc_widget-navigation' => array(
          'module' => 'ghel_toc_widget',
          'delta' => 'navigation',
          'region' => 'tab_course',
          'weight' => '-10',
        ),
        'views-ghel_course_ref_node-block' => array(
          'module' => 'views',
          'delta' => 'ghel_course_ref_node-block',
          'region' => 'tab_reference',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks for quiz question nodes');
  t('ghel');
  $export['ghel_learner_quiz_question'] = $context;

  return $export;
}
