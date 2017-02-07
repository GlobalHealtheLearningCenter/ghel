<?php
/**
 * @file
 * ghel_reports.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ghel_reports_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-ghel-reports_admin-course-list:course-list/admin.
  $menu_links['menu-ghel-reports_admin-course-list:course-list/admin'] = array(
    'menu_name' => 'menu-ghel-reports',
    'link_path' => 'course-list/admin',
    'router_path' => 'course-list/admin',
    'link_title' => 'Admin Course List',
    'options' => array(
      'attributes' => array(
        'title' => 'An administrative list of all courses',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ghel-reports_admin-course-list:course-list/admin',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-ghel-reports_administer-feedback:course-admin/feedback-review.
  $menu_links['menu-ghel-reports_administer-feedback:course-admin/feedback-review'] = array(
    'menu_name' => 'menu-ghel-reports',
    'link_path' => 'course-admin/feedback-review',
    'router_path' => 'course-admin/feedback-review',
    'link_title' => 'Administer feedback',
    'options' => array(
      'attributes' => array(
        'title' => 'Review and, if needed, bulk-delete feedback on courses',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ghel-reports_administer-feedback:course-admin/feedback-review',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-ghel-reports_certificate-reports:reports/all.
  $menu_links['menu-ghel-reports_certificate-reports:reports/all'] = array(
    'menu_name' => 'menu-ghel-reports',
    'link_path' => 'reports/all',
    'router_path' => 'reports/all',
    'link_title' => 'Certificate reports',
    'options' => array(
      'attributes' => array(
        'title' => 'List of all certificates earned in the site',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ghel-reports_certificate-reports:reports/all',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-ghel-reports_find-participants:program-participants/find.
  $menu_links['menu-ghel-reports_find-participants:program-participants/find'] = array(
    'menu_name' => 'menu-ghel-reports',
    'link_path' => 'program-participants/find',
    'router_path' => 'program-participants/find',
    'link_title' => 'Find participants',
    'options' => array(
      'attributes' => array(
        'title' => 'Search for program participants within the site',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ghel-reports_find-participants:program-participants/find',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-ghel-reports_new-users:reports/users-new.
  $menu_links['menu-ghel-reports_new-users:reports/users-new'] = array(
    'menu_name' => 'menu-ghel-reports',
    'link_path' => 'reports/users-new',
    'router_path' => 'reports/users-new',
    'link_title' => 'New users',
    'options' => array(
      'attributes' => array(
        'title' => 'Information on new users, and users who have not earned a certificate',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ghel-reports_new-users:reports/users-new',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Admin Course List');
  t('Administer feedback');
  t('Certificate reports');
  t('Find participants');
  t('New users');

  return $menu_links;
}
