<?php
/**
 * @file
 * ghel_course_section.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function ghel_course_section_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_course_section|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_course_section';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'main_content' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'body' => 'main_content',
    ),
    'classes' => array(),
  );
  $export['node|ghel_course_section|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_course_section|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_course_section';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'main_content' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'body' => 'main_content',
    ),
    'classes' => array(),
  );
  $export['node|ghel_course_section|teaser'] = $ds_layout;

  return $export;
}
