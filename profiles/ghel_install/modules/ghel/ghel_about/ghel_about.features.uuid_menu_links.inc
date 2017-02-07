<?php
/**
 * @file
 * ghel_about.features.uuid_menu_links.inc
 */

/**
 * Implements hook_uuid_menu_default_menu_links().
 */
function ghel_about_uuid_menu_default_menu_links() {
  $uuid_menu_links = array();

  // Exported menu link: main-menu:node/29054226-a1c9-a8f4-552c-6f16fb21e2c4
  $uuid_menu_links['main-menu:node/29054226-a1c9-a8f4-552c-6f16fb21e2c4'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Additional Training Opportunities',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'uuid_link_path' => 'node/29054226-a1c9-a8f4-552c-6f16fb21e2c4',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => 'node/5754803a-4fcb-0fe4-09ec-ff1ac89b25ea',
  );
  // Exported menu link: main-menu:node/2921be2f-31fa-8904-4911-57626a6f0323
  $uuid_menu_links['main-menu:node/2921be2f-31fa-8904-4911-57626a6f0323'] = array(
    'router_path' => 'node/%',
    'link_title' => 'How to Use Courses',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'uuid_link_path' => 'node/2921be2f-31fa-8904-4911-57626a6f0323',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => 'node/5754803a-4fcb-0fe4-09ec-ff1ac89b25ea',
  );
  // Exported menu link: main-menu:node/5754803a-4fcb-0fe4-09ec-ff1ac89b25ea
  $uuid_menu_links['main-menu:node/5754803a-4fcb-0fe4-09ec-ff1ac89b25ea'] = array(
    'router_path' => 'node/%',
    'link_title' => 'About GHeL',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -46,
    'uuid_link_path' => 'node/5754803a-4fcb-0fe4-09ec-ff1ac89b25ea',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => NULL,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About GHeL');
  t('Additional Training Opportunities');
  t('How to Use Courses');


  return $uuid_menu_links;
}
