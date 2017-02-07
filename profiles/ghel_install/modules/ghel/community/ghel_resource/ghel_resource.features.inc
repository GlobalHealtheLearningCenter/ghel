<?php
/**
 * @file
 * ghel_resource.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_resource_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ghel_resource_node_info() {
  $items = array(
    'ghel_resource' => array(
      'name' => t('Resource'),
      'base' => 'node_content',
      'description' => t('Resources - used in Study Groups'),
      'has_title' => '1',
      'title_label' => t('Resource name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
