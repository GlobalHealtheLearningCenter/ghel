<?php
/**
 * @file
 * ghel_onboarding.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_onboarding_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}