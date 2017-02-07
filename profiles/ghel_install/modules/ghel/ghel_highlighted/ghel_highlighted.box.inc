<?php
/**
 * @file
 * ghel_highlighted.box.inc
 */

/**
 * Implements hook_default_box().
 */
function ghel_highlighted_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ghel_headline_box';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Box: Headline';
  $box->options = array(
    'body' => array(
      'value' => '<h2 class="headline">Current Technical Information for Global Health Professionals</h2>',
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
  );
  $export['ghel_headline_box'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ghel_signup_button_box';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Box: Registration Buttons';
  $box->options = array(
    'body' => array(
      'value' => '<a href="user/register" class="button-register">Register</a>  <a href="user/login" class="button-signup">Sign In</a>',
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
  );
  $export['ghel_signup_button_box'] = $box;

  return $export;
}
