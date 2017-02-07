<?php
/**
 * @file
 * ghel_course.features.uuid_menu_links.inc
 */

/**
 * Implements hook_uuid_menu_default_menu_links().
 */
function ghel_course_uuid_menu_default_menu_links() {
  $uuid_menu_links = array();

  // Exported menu link: main-menu:node/a343e8f9-3edd-4584-61e6-613de9ea4554
  $uuid_menu_links['main-menu:node/a343e8f9-3edd-4584-61e6-613de9ea4554'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Courses',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'uuid_link_path' => 'node/a343e8f9-3edd-4584-61e6-613de9ea4554',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => NULL,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Courses');


  return $uuid_menu_links;
}
