<?php
/**
 * @file
 * ghel_program.features.uuid_menu_links.inc
 */

/**
 * Implements hook_uuid_menu_default_menu_links().
 */
function ghel_program_uuid_menu_default_menu_links() {
  $uuid_menu_links = array();

  // Exported menu link: main-menu:node/36c2a6fb-183f-79c4-6179-6b8e6c102010
  $uuid_menu_links['main-menu:node/36c2a6fb-183f-79c4-6179-6b8e6c102010'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Certificate Programs',
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
    'weight' => -48,
    'uuid_link_path' => 'node/36c2a6fb-183f-79c4-6179-6b8e6c102010',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => NULL,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Certificate Programs');


  return $uuid_menu_links;
}
