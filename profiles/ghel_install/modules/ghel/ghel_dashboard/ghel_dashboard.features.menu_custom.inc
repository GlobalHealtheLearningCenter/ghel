<?php
/**
 * @file
 * ghel_dashboard.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ghel_dashboard_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-ghel-create-course.
  $menus['menu-ghel-create-course'] = array(
    'menu_name' => 'menu-ghel-create-course',
    'title' => 'Create a course',
    'description' => 'For course creators - place the link to create a course on the learner home',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Create a course');
  t('For course creators - place the link to create a course on the learner home');

  return $menus;
}
