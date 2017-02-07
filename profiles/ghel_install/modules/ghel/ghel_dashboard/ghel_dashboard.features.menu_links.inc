<?php
/**
 * @file
 * ghel_dashboard.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ghel_dashboard_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-ghel-create-course_add-a-new-course:node/add/ghel-course.
  $menu_links['menu-ghel-create-course_add-a-new-course:node/add/ghel-course'] = array(
    'menu_name' => 'menu-ghel-create-course',
    'link_path' => 'node/add/ghel-course',
    'router_path' => 'node/add/ghel-course',
    'link_title' => 'Add a new course',
    'options' => array(
      'attributes' => array(
        'title' => 'Add a new course. This new course will include multiple sections, each complete with quizzes and internal pages to edit.',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-ghel-create-course_add-a-new-course:node/add/ghel-course',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a new course');

  return $menu_links;
}
