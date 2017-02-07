<?php
/**
 * @file
 * ghel_reports.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ghel_reports_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-ghel-reports.
  $menus['menu-ghel-reports'] = array(
    'menu_name' => 'menu-ghel-reports',
    'title' => 'Reports and Admin Tools',
    'description' => 'A menu for reports and other administrative tools',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('A menu for reports and other administrative tools');
  t('Reports and Admin Tools');

  return $menus;
}
