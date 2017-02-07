<?php
/**
 * @file
 * ghel_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_features_date_format_default().
 */
function ghel_settings_features_date_format_default() {
  $fdf_config = array();

  $fdf_config[] = array(
    'dfid' => 36,
    'format' => 'Y-m-d',
    'type' => 'custom',
    'locked' => 0,
  );
  return $fdf_config;
}
