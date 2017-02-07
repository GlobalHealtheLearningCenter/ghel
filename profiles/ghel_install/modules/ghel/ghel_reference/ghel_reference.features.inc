<?php
/**
 * @file
 * ghel_reference.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_reference_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ghel_reference_node_info() {
  $items = array(
    'ghel_reference' => array(
      'name' => t('Reference'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
