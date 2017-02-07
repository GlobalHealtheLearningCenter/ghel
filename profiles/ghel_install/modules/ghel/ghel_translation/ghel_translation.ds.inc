<?php
/**
 * @file
 * ghel_translation.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ghel_translation_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ghel_translation|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ghel_translation';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_ghel_trans_file' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_html5_field_ul',
        ),
      ),
    ),
  );
  $export['node|ghel_translation|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ghel_translation|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ghel_translation';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => 'article-title',
        'ft' => array(),
      ),
    ),
    'field_ghel_trans_file' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_html5_field_ul',
        ),
      ),
    ),
  );
  $export['node|ghel_translation|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ghel_translation_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_translation|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_translation';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'regions' => array(
      'main_content' => array(
        0 => 'field_image',
        1 => 'field_ghel_promotional_text',
      ),
      'aside' => array(
        2 => 'field_ghel_language',
        3 => 'field_ghel_trans_file',
      ),
    ),
    'fields' => array(
      'field_image' => 'main_content',
      'field_ghel_promotional_text' => 'main_content',
      'field_ghel_language' => 'aside',
      'field_ghel_trans_file' => 'aside',
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
  $export['node|ghel_translation|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_translation|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_translation';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'field_ghel_language',
        2 => 'field_ghel_trans_file',
      ),
      'main_content' => array(
        3 => 'field_image',
        4 => 'field_ghel_promotional_text',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_ghel_language' => 'header',
      'field_ghel_trans_file' => 'header',
      'field_image' => 'main_content',
      'field_ghel_promotional_text' => 'main_content',
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
  $export['node|ghel_translation|teaser'] = $ds_layout;

  return $export;
}
