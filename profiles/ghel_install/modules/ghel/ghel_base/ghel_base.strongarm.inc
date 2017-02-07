<?php
/**
 * @file
 * ghel_base.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ghel_base_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'boxes_edit_location';
  $strongarm->value = 2;
  $export['boxes_edit_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_field_template';
  $strongarm->value = 1;
  $export['ds_extras_field_template'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ft-default';
  $strongarm->value = 'theme_ds_field_minimal';
  $export['ft-default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_ids';
  $strongarm->value = array(
    0 => 1,
    1 => 2,
    2 => 4,
    3 => 5,
  );
  $export['menu_block_ids'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_default_active_menus';
  $strongarm->value = array(
    0 => 'devel',
    1 => 'features',
    2 => 'menu-footer-menu',
    3 => 'main-menu',
    4 => 'management',
    5 => 'navigation',
    7 => 'user-menu',
    8 => 'menu-ghel-create-course',
    9 => 'menu-ghel-reports',
    10 => 'menu-login-logout',
  );
  $export['menu_default_active_menus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'node/1';
  $export['site_frontpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_name';
  $strongarm->value = 'Global Health eLearning Center';
  $export['site_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_node_types';
  $strongarm->value = array(
    'page' => 'page',
  );
  $export['uuid_features_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_term_vocabs';
  $strongarm->value = array(
    'ghel_announcement_types' => 'ghel_announcement_types',
    'ghel_faq_categories' => 'ghel_faq_categories',
    'ghel_funder' => 'ghel_funder',
    'ghel_occupation_category' => 'ghel_occupation_category',
    'ghel_organization_category' => 'ghel_organization_category',
  );
  $export['uuid_features_term_vocabs'] = $strongarm;

  return $export;
}
