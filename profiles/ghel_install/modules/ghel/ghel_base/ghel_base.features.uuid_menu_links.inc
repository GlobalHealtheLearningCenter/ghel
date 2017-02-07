<?php
/**
 * @file
 * ghel_base.features.uuid_menu_links.inc
 */

/**
 * Implements hook_uuid_menu_default_menu_links().
 */
function ghel_base_uuid_menu_default_menu_links() {
  $uuid_menu_links = array();

  // Exported menu link: menu-footer-menu:https://www.facebook.com/USAIDGH
  $uuid_menu_links['menu-footer-menu:https://www.facebook.com/USAIDGH'] = array(
    'router_path' => '',
    'link_title' => 'Facebook',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'uuid_link_path' => 'https://www.facebook.com/USAIDGH',
    'uuid_menu_name' => 'menu-footer-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: menu-footer-menu:node/a1efef5f-181e-8a44-4157-773572f37ec6
  $uuid_menu_links['menu-footer-menu:node/a1efef5f-181e-8a44-4157-773572f37ec6'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Privacy',
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
    'weight' => -48,
    'uuid_link_path' => 'node/a1efef5f-181e-8a44-4157-773572f37ec6',
    'uuid_menu_name' => 'menu-footer-menu',
    'uuid_parent_path' => NULL,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Facebook');
  t('Privacy');


  return $uuid_menu_links;
}
