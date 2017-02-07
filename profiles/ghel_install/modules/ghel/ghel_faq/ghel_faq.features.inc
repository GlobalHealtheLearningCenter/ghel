<?php
/**
 * @file
 * ghel_faq.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_faq_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ghel_faq_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ghel_faq_node_info() {
  $items = array(
    'ghel_faq' => array(
      'name' => t('FAQ'),
      'base' => 'node_content',
      'description' => t('A frequently asked question along with its answer.'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
