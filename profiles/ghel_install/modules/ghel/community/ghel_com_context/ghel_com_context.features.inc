<?php
/**
 * @file
 * ghel_com_context.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_com_context_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}