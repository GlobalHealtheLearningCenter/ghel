<?php
/**
 * @file
 * ghel_announcement.features.uuid_menu_links.inc
 */

/**
 * Implements hook_uuid_menu_default_menu_links().
 */
function ghel_announcement_uuid_menu_default_menu_links() {
  $uuid_menu_links = array();

  // Exported menu link: main-menu:node/dd8509ce-8bee-52c4-f99e-2271eeac65ad
  $uuid_menu_links['main-menu:node/dd8509ce-8bee-52c4-f99e-2271eeac65ad'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Announcements',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'uuid_link_path' => 'node/dd8509ce-8bee-52c4-f99e-2271eeac65ad',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => NULL,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Announcements');


  return $uuid_menu_links;
}
