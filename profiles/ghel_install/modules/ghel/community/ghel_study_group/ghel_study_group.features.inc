<?php
/**
 * @file
 * ghel_study_group.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_study_group_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ghel_study_group_node_info() {
  $items = array(
    'ghel_grp_study' => array(
      'name' => t('Study Group'),
      'base' => 'node_content',
      'description' => t('Study Groups are related directly to a course, and are generally private, with a smaller number of members working directly within the group.'),
      'has_title' => '1',
      'title_label' => t('Group name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
