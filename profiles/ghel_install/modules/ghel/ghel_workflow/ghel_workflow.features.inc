<?php
/**
 * @file
 * ghel_workflow.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_workflow_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_workflow_default_workflows().
 */
function ghel_workflow_workflow_default_workflows() {
  $workflows = array();

  // Exported workflow: Course Status
  $workflows['Course Status'] = array(
    'name' => 'Course Status',
    'tab_roles' => 'author,3,4,5,6',
    'options' => 'a:3:{s:16:"comment_log_node";i:0;s:15:"comment_log_tab";i:0;s:13:"name_as_title";i:1;}',
    'states' => array(
      0 => array(
        'state' => '(creation)',
        'weight' => -50,
        'sysid' => 1,
        'status' => 1,
      ),
      1 => array(
        'state' => 'Under Review',
        'weight' => 1,
        'sysid' => 0,
        'status' => 1,
      ),
      2 => array(
        'state' => 'Feedback',
        'weight' => 1,
        'sysid' => 0,
        'status' => 1,
      ),
      3 => array(
        'state' => 'Published',
        'weight' => 2,
        'sysid' => 0,
        'status' => 1,
      ),
      4 => array(
        'state' => 'Archived',
        'weight' => 2,
        'sysid' => 0,
        'status' => 1,
      ),
    ),
    'transitions' => array(
      0 => array(
        'roles' => 'site administrator',
        'state' => '(creation)',
        'target_state' => 'Published',
      ),
      1 => array(
        'roles' => 'workflow_features_author_name,course creator',
        'state' => '(creation)',
        'target_state' => 'Under Review',
      ),
      2 => array(
        'roles' => 'site administrator',
        'state' => '(creation)',
        'target_state' => 'Archived',
      ),
      3 => array(
        'roles' => 'site administrator,course publisher,course creator,staff',
        'state' => 'Under Review',
        'target_state' => 'Published',
      ),
      4 => array(
        'roles' => 'site administrator,course publisher,course creator,staff',
        'state' => 'Under Review',
        'target_state' => 'Archived',
      ),
      5 => array(
        'roles' => 'workflow_features_author_name,site administrator,course publisher,course creator,staff',
        'state' => 'Under Review',
        'target_state' => 'Feedback',
      ),
      6 => array(
        'roles' => 'workflow_features_author_name',
        'state' => 'Feedback',
        'target_state' => 'Under Review',
      ),
      7 => array(
        'roles' => 'site administrator,course publisher',
        'state' => 'Feedback',
        'target_state' => 'Published',
      ),
      8 => array(
        'roles' => 'site administrator',
        'state' => 'Feedback',
        'target_state' => 'Archived',
      ),
      9 => array(
        'roles' => 'site administrator,course publisher',
        'state' => 'Published',
        'target_state' => 'Under Review',
      ),
      10 => array(
        'roles' => 'site administrator,course publisher',
        'state' => 'Published',
        'target_state' => 'Archived',
      ),
      11 => array(
        'roles' => 'site administrator',
        'state' => 'Archived',
        'target_state' => 'Published',
      ),
      12 => array(
        'roles' => 'site administrator,course publisher',
        'state' => 'Archived',
        'target_state' => 'Under Review',
      ),
      13 => array(
        'roles' => 'site administrator,course publisher',
        'state' => 'Archived',
        'target_state' => 'Feedback',
      ),
    ),
    'node_types' => array(
      0 => 'ghel_course',
    ),
  );

  return $workflows;
}
