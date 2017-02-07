<?php
/**
 * @file
 * ghel_partner.features.uuid_menu_links.inc
 */

/**
 * Implements hook_uuid_menu_default_menu_links().
 */
function ghel_partner_uuid_menu_default_menu_links() {
  $uuid_menu_links = array();

  // Exported menu link: main-menu:node/46a97e8f-ea2e-5ba4-b156-82ec58350962
  $uuid_menu_links['main-menu:node/46a97e8f-ea2e-5ba4-b156-82ec58350962'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Partners',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'uuid_link_path' => 'node/46a97e8f-ea2e-5ba4-b156-82ec58350962',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => 'node/5754803a-4fcb-0fe4-09ec-ff1ac89b25ea',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Partners');


  return $uuid_menu_links;
}
