<?php
/**
 * @file
 * ghel_com_views.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function ghel_com_views_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'community_quicktabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Community QuickTabs';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'views_delta_ghel_com_inter-block_1',
      'hide_title' => 0,
      'title' => 'Community Activity',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'views_delta_ghel_com_disc_cur-block_1',
      'hide_title' => 0,
      'title' => 'Discussions',
      'weight' => '-99',
      'type' => 'block',
    ),
    2 => array(
      'bid' => 'views_delta_ghel_com_res_cur-block_1',
      'hide_title' => 0,
      'title' => 'Resources',
      'weight' => '-98',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Community Activity');
  t('Community QuickTabs');
  t('Discussions');
  t('Resources');

  $export['community_quicktabs'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'study_groups_quicktab';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'StudyProg Groups Quicktab';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'views_delta_ghel_com_disc_mem-block_1',
      'hide_title' => 0,
      'title' => 'Discussions',
      'weight' => '-99',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'views_delta_ghel_com_res_mem-block_1',
      'hide_title' => 0,
      'title' => 'Resources',
      'weight' => '-98',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Discussions');
  t('Resources');
  t('StudyProg Groups Quicktab');

  $export['study_groups_quicktab'] = $quicktabs;

  return $export;
}
