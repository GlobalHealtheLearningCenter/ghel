<?php
/**
 * @file
 * ghel_faq.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ghel_faq_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ghel_faq|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ghel_faq';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h4',
        'class' => 'faq-title',
      ),
    ),
  );
  $export['node|ghel_faq|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ghel_faq_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_faq|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_faq';
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
  $export['node|ghel_faq|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_faq|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_faq';
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
  $export['node|ghel_faq|teaser'] = $ds_layout;

  return $export;
}
