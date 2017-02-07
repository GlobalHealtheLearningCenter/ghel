<?php
/**
 * @file
 * ghel_spam.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ghel_spam_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function ghel_spam_flag_default_flags() {
  $flags = array();
  // Exported flag: "Comment abuse".
  $flags['ghel_flag_comment_abuse'] = array(
    'entity_type' => 'comment',
    'title' => 'Comment abuse',
    'global' => 0,
    'types' => array(
      0 => 'comment_node_ghel_action_plan',
      1 => 'comment_node_ghel_discussion',
      2 => 'comment_node_ghel_resource',
    ),
    'flag_short' => 'Report Abuse',
    'flag_long' => 'Mark this content as off topic, abusive, or spam',
    'flag_message' => 'This has been flagged for review',
    'unflag_short' => 'Un-flag this item',
    'unflag_long' => 'If you marked this item as off topic or abusive by mistake, please un-flag the item.',
    'unflag_message' => 'You have un-flagged this content.',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'flag_confirmation' => 'Are you sure you want to mark this item as abusive or spam?',
    'unflag_confirmation' => 'Are you sure you want to un-flag this item as abusive or spam?',
    'module' => 'ghel_spam',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
