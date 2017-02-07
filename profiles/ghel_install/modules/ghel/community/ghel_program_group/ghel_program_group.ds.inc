<?php
/**
 * @file
 * ghel_program_group.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function ghel_program_group_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_grp_program|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_grp_program';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'regions' => array(
      'hgroup' => array(
        0 => 'group_group',
        1 => 'field_ghel_er_program',
      ),
      'main_content' => array(
        2 => 'body',
      ),
      'aside' => array(
        3 => 'field_ghel_grp_mgrs',
      ),
    ),
    'fields' => array(
      'group_group' => 'hgroup',
      'field_ghel_er_program' => 'hgroup',
      'body' => 'main_content',
      'field_ghel_grp_mgrs' => 'aside',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'hgroup' => 'div',
      'main_content' => 'div',
      'figure' => 'div',
      'aside' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|ghel_grp_program|default'] = $ds_layout;

  return $export;
}
