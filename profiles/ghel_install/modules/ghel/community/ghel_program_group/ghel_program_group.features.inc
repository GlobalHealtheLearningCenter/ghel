<?php
/**
 * @file
 * ghel_program_group.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_program_group_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ghel_program_group_node_info() {
  $items = array(
    'ghel_grp_program' => array(
      'name' => t('Program Group'),
      'base' => 'node_content',
      'description' => t('Program groups are open to all site members, and are affiliated with a specific Certificate Program.'),
      'has_title' => '1',
      'title_label' => t('Group name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
