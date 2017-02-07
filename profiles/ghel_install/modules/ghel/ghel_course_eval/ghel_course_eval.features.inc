<?php
/**
 * @file
 * ghel_course_eval.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_course_eval_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
