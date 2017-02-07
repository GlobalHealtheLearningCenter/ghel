<?php
/**
 * @file
 * ghel_announcement.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_announcement_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ghel_announcement_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ghel_announcement_node_info() {
  $items = array(
    'ghel_announcement' => array(
      'name' => t('Announcement'),
      'base' => 'node_content',
      'description' => t('An event, notice, or other announcement to be displayed on the front page and on the Announcements page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
