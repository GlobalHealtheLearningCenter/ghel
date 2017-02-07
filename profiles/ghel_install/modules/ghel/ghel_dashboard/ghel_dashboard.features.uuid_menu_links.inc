<?php
/**
 * @file
 * ghel_dashboard.features.uuid_menu_links.inc
 */

/**
 * Implements hook_uuid_menu_default_menu_links().
 */
function ghel_dashboard_uuid_menu_default_menu_links() {
  $uuid_menu_links = array();

  // Exported menu link: user-menu:node/2f4de39e-82d9-d4e4-6de4-d02ef08e2a5e
  $uuid_menu_links['user-menu:node/2f4de39e-82d9-d4e4-6de4-d02ef08e2a5e'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Learner Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -20,
    'uuid_link_path' => 'node/2f4de39e-82d9-d4e4-6de4-d02ef08e2a5e',
    'uuid_menu_name' => 'user-menu',
    'uuid_parent_path' => NULL,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Learner Home');


  return $uuid_menu_links;
}
