<?php
/**
 * @file
 * ghel_paths.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_paths_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
