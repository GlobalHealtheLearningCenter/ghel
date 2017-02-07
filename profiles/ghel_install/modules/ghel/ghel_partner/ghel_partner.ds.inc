<?php
/**
 * @file
 * ghel_partner.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function ghel_partner_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_partner|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_partner';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'field_ghel_logo',
        1 => 'field_ghel_partner_website',
      ),
      'main_content' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'field_ghel_logo' => 'header',
      'field_ghel_partner_website' => 'header',
      'body' => 'main_content',
    ),
    'classes' => array(),
  );
  $export['node|ghel_partner|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_partner|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_partner';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_ghel_logo',
      ),
      'main_content' => array(
        1 => 'body',
        2 => 'field_ghel_partner_website',
      ),
    ),
    'fields' => array(
      'field_ghel_logo' => 'header',
      'body' => 'main_content',
      'field_ghel_partner_website' => 'main_content',
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
  $export['node|ghel_partner|teaser'] = $ds_layout;

  return $export;
}
