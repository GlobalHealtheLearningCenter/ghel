<?php
/**
 * @file
 * ghel_com_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ghel_com_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_com_landing';
  $context->description = 'Community Landing Page';
  $context->tag = 'community';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'community' => 'community',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ghel_announcements-block_2' => array(
          'module' => 'views',
          'delta' => 'ghel_announcements-block_2',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-certificate_programs-block_1' => array(
          'module' => 'views',
          'delta' => 'certificate_programs-block_1',
          'region' => 'below_content',
          'weight' => '-10',
        ),
        'quicktabs-community_quicktabs' => array(
          'module' => 'quicktabs',
          'delta' => 'community_quicktabs',
          'region' => 'quicktabs',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Community Landing Page');
  t('community');
  $export['ghel_com_landing'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_com_my';
  $context->description = 'Community dash for logged in user';
  $context->tag = 'community';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'ghel_com_inter:page' => 'ghel_com_inter:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ghel_com_grps_cur-block_1' => array(
          'module' => 'views',
          'delta' => 'ghel_com_grps_cur-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'ghel_reports-encouragements' => array(
          'module' => 'ghel_reports',
          'delta' => 'encouragements',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'ghel_reports-completions' => array(
          'module' => 'ghel_reports',
          'delta' => 'completions',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'ghel_certificate-courses-in-progress' => array(
          'module' => 'ghel_certificate',
          'delta' => 'courses-in-progress',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'quicktabs-community_quicktabs' => array(
          'module' => 'quicktabs',
          'delta' => 'community_quicktabs',
          'region' => 'quicktabs',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Community dash for logged in user');
  t('community');
  $export['ghel_com_my'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_com_program';
  $context->description = 'Program group landing pages';
  $context->tag = 'community';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ghel_grp_program' => 'ghel_grp_program',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'ghel_program_group-add-content' => array(
          'module' => 'ghel_program_group',
          'delta' => 'add-content',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-ghel_com_gr_mem-block' => array(
          'module' => 'views',
          'delta' => 'ghel_com_gr_mem-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'quicktabs-study_groups_quicktab' => array(
          'module' => 'quicktabs',
          'delta' => 'study_groups_quicktab',
          'region' => 'quicktabs',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Program group landing pages');
  t('community');
  $export['ghel_com_program'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ghel_com_study';
  $context->description = 'Study group landing pages';
  $context->tag = 'community';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ghel_grp_study' => 'ghel_grp_study',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'ghel_study_group-add-content' => array(
          'module' => 'ghel_study_group',
          'delta' => 'add-content',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-ghel_com_gr_mem-block' => array(
          'module' => 'views',
          'delta' => 'ghel_com_gr_mem-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'quicktabs-study_groups_quicktab' => array(
          'module' => 'quicktabs',
          'delta' => 'study_groups_quicktab',
          'region' => 'quicktabs',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Study group landing pages');
  t('community');
  $export['ghel_com_study'] = $context;

  return $export;
}
