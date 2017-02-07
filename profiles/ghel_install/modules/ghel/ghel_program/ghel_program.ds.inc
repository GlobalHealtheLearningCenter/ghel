<?php
/**
 * @file
 * ghel_program.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ghel_program_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ghel_program|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ghel_program';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_ghel_courses' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Courses',
          'lb-el' => 'h2',
          'lb-cl' => 'section-heading',
          'lb-col' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'article-list',
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => 'article-item',
        ),
      ),
    ),
  );
  $export['node|ghel_program|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ghel_program|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ghel_program';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'article-title',
      ),
    ),
  );
  $export['node|ghel_program|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ghel_program_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_program|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_program';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'regions' => array(
      'main_content' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'body' => 'main_content',
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
  );
  $export['node|ghel_program|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_program|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_program';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'title',
      ),
      'main_content' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'body' => 'main_content',
    ),
    'classes' => array(),
  );
  $export['node|ghel_program|teaser'] = $ds_layout;

  return $export;
}
