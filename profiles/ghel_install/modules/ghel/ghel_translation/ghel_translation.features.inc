<?php
/**
 * @file
 * ghel_translation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_translation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ghel_translation_node_info() {
  $items = array(
    'ghel_translation' => array(
      'name' => t('Translation'),
      'base' => 'node_content',
      'description' => t('Used to store translations'),
      'has_title' => '1',
      'title_label' => t('Translated Course Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
