<?php
/**
 * @file
 * ghel_com_views.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_com_views_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ghel_com_views_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
