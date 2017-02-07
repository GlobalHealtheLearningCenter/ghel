<?php
/**
 * @file
 * ghel_workflow.features.og_workflow.inc
 */

/**
 * Implements hook_og_workflow_default_transitions().
 */
function ghel_workflow_og_workflow_default_transitions() {
  $og_workflows = array();
  
  // Exported og_workflow: Course Status
  $og_workflows['Course Status'] = array(
    'name' => 'Course Status',
    'transitions' => array(
      '(creation)->Archived' => array(
        'target_state' => 'Archived',
        'roles' => array(),
        'state' => '(creation)',
      ),
      '(creation)->Feedback' => array(
        'target_state' => 'Feedback',
        'roles' => array(),
        'state' => '(creation)',
      ),
      '(creation)->Published' => array(
        'target_state' => 'Published',
        'roles' => array(),
        'state' => '(creation)',
      ),
      '(creation)->Under Review' => array(
        'target_state' => 'Under Review',
        'roles' => array(
          'og_workflow_features_author' => 'og_workflow_features_author',
        ),
        'state' => '(creation)',
      ),
      'Archived->Feedback' => array(
        'target_state' => 'Feedback',
        'roles' => array(
          'node:ghel_course:administrator member' => 'node:ghel_course:administrator member',
        ),
        'state' => 'Archived',
      ),
      'Archived->Published' => array(
        'target_state' => 'Published',
        'roles' => array(),
        'state' => 'Archived',
      ),
      'Archived->Under Review' => array(
        'target_state' => 'Under Review',
        'roles' => array(
          'node:ghel_course:administrator member' => 'node:ghel_course:administrator member',
        ),
        'state' => 'Archived',
      ),
      'Feedback->Archived' => array(
        'target_state' => 'Archived',
        'roles' => array(),
        'state' => 'Feedback',
      ),
      'Feedback->Published' => array(
        'target_state' => 'Published',
        'roles' => array(
          'node:ghel_course:administrator member' => 'node:ghel_course:administrator member',
        ),
        'state' => 'Feedback',
      ),
      'Feedback->Under Review' => array(
        'target_state' => 'Under Review',
        'roles' => array(
          'node:ghel_course:administrator member' => 'node:ghel_course:administrator member',
        ),
        'state' => 'Feedback',
      ),
      'Published->Archived' => array(
        'target_state' => 'Archived',
        'roles' => array(
          'node:ghel_course:administrator member' => 'node:ghel_course:administrator member',
          'node:ghel_course:administrator (unprivileged)' => 'node:ghel_course:administrator (unprivileged)',
        ),
        'state' => 'Published',
      ),
      'Published->Feedback' => array(
        'target_state' => 'Feedback',
        'roles' => array(),
        'state' => 'Published',
      ),
      'Published->Under Review' => array(
        'target_state' => 'Under Review',
        'roles' => array(
          'node:ghel_course:administrator member' => 'node:ghel_course:administrator member',
          'node:ghel_course:administrator (unprivileged)' => 'node:ghel_course:administrator (unprivileged)',
        ),
        'state' => 'Published',
      ),
      'Under Review->Archived' => array(
        'target_state' => 'Archived',
        'roles' => array(
          'node:ghel_course:administrator member' => 'node:ghel_course:administrator member',
        ),
        'state' => 'Under Review',
      ),
      'Under Review->Feedback' => array(
        'target_state' => 'Feedback',
        'roles' => array(
          'node:ghel_course:administrator member' => 'node:ghel_course:administrator member',
        ),
        'state' => 'Under Review',
      ),
      'Under Review->Published' => array(
        'target_state' => 'Published',
        'roles' => array(),
        'state' => 'Under Review',
      ),
    ),
  );

  return $og_workflows;
}
