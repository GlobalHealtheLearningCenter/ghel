<?php
/**
 * @file
 * ghel_contact.features.uuid_menu_links.inc
 */

/**
 * Implements hook_uuid_menu_default_menu_links().
 */
function ghel_contact_uuid_menu_default_menu_links() {
  $uuid_menu_links = array();

  // Exported menu link: main-menu:node/22e2c592-888b-92e4-1141-df2cb9222110
  $uuid_menu_links['main-menu:node/22e2c592-888b-92e4-1141-df2cb9222110'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'uuid_link_path' => 'node/22e2c592-888b-92e4-1141-df2cb9222110',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => 'node/5754803a-4fcb-0fe4-09ec-ff1ac89b25ea',
  );
  // Exported menu link: menu-footer-menu:node/22e2c592-888b-92e4-1141-df2cb9222110
  $uuid_menu_links['menu-footer-menu:node/22e2c592-888b-92e4-1141-df2cb9222110'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Contact',
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
    'weight' => -49,
    'uuid_link_path' => 'node/22e2c592-888b-92e4-1141-df2cb9222110',
    'uuid_menu_name' => 'menu-footer-menu',
    'uuid_parent_path' => NULL,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');


  return $uuid_menu_links;
}
