<?php
/**
 * @file
 * ghel_testimonial.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ghel_testimonial_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ghel_testimonial|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ghel_testimonial';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_ghel_course_program' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Course',
        ),
      ),
    ),
  );
  $export['node|ghel_testimonial|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ghel_testimonial|quote';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ghel_testimonial';
  $ds_fieldsetting->view_mode = 'quote';
  $ds_fieldsetting->settings = array(
    'field_ghel_course_program' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Course',
        ),
      ),
    ),
    'field_ghel_first_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_html5_field_address',
        ),
      ),
    ),
  );
  $export['node|ghel_testimonial|quote'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ghel_testimonial_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_testimonial|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_testimonial';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'main_content' => array(
        0 => 'body',
      ),
      'footer' => array(
        0 => 'field_ghel_first_name',
        1 => 'field_ghel_location',
        2 => 'field_ghel_course_program',
      ),
    ),
    'fields' => array(
      'body' => 'main_content',
      'field_ghel_first_name' => 'footer',
      'field_ghel_location' => 'footer',
      'field_ghel_course_program' => 'footer',
    ),
    'classes' => array(),
  );
  $export['node|ghel_testimonial|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_testimonial|quote';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_testimonial';
  $ds_layout->view_mode = 'quote';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_ghel_course_program',
      ),
      'main_content' => array(
        1 => 'body',
      ),
      'footer' => array(
        2 => 'field_ghel_first_name',
        3 => 'field_ghel_location',
      ),
    ),
    'fields' => array(
      'field_ghel_course_program' => 'header',
      'body' => 'main_content',
      'field_ghel_first_name' => 'footer',
      'field_ghel_location' => 'footer',
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
  $export['node|ghel_testimonial|quote'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_testimonial|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_testimonial';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_ghel_first_name',
        2 => 'field_ghel_location',
        3 => 'field_ghel_course_program',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_ghel_first_name' => 'ds_content',
      'field_ghel_location' => 'ds_content',
      'field_ghel_course_program' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|ghel_testimonial|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ghel_testimonial_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'quote';
  $ds_view_mode->label = 'Quote';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['quote'] = $ds_view_mode;

  return $export;
}
