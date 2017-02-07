<?php
/**
 * @file
 * ghel_faq.features.uuid_menu_links.inc
 */

/**
 * Implements hook_uuid_menu_default_menu_links().
 */
function ghel_faq_uuid_menu_default_menu_links() {
  $uuid_menu_links = array();

  // Exported menu link: main-menu:node/cb309de1-a301-99e4-31eb-53eb1d3f45d5
  $uuid_menu_links['main-menu:node/cb309de1-a301-99e4-31eb-53eb1d3f45d5'] = array(
    'router_path' => 'node/%',
    'link_title' => 'FAQs',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'uuid_link_path' => 'node/cb309de1-a301-99e4-31eb-53eb1d3f45d5',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => 'node/5754803a-4fcb-0fe4-09ec-ff1ac89b25ea',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('FAQs');


  return $uuid_menu_links;
}
