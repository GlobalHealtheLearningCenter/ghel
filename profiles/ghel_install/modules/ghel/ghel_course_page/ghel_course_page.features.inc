<?php
/**
 * @file
 * ghel_course_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_course_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ghel_course_page_image_default_styles() {
  $styles = array();

  // Exported image style: extra_large_center.
  $styles['extra_large_center'] = array(
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'extra_large_center',
  );

  // Exported image style: large_center.
  $styles['large_center'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'large_center',
  );

  // Exported image style: medium_center.
  $styles['medium_center'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'medium_center',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function ghel_course_page_node_info() {
  $items = array(
    'ghel_course_page' => array(
      'name' => t('Course Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
