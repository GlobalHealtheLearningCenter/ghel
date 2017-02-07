<?php
/**
 * @file
 * ghel_course_section.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_course_section_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ghel_course_section_node_info() {
  $items = array(
    'ghel_course_section' => array(
      'name' => t('Course Section'),
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
