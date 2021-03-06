<?php
/**
 * @file
 * ghel_user_configuration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_user_configuration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ghel_user_configuration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ghel_user_configuration_image_default_styles() {
  $styles = array();

  // Exported image style: user_profile.
  $styles['user_profile'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 160,
          'height' => 160,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'user_profile',
  );

  return $styles;
}
