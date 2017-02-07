<?php
/**
 * @file
 * ghel_testimonial.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_testimonial_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ghel_testimonial_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ghel_testimonial_node_info() {
  $items = array(
    'ghel_testimonial' => array(
      'name' => t('Testimonial'),
      'base' => 'node_content',
      'description' => t('A sentence highlighting a successful learner.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
