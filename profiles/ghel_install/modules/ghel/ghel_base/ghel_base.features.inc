<?php
/**
 * @file
 * ghel_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ghel_base_image_default_styles() {
  $styles = array();

  // Exported image style: large_left.
  $styles['large_left'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => 400,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'large_left',
  );

  // Exported image style: large_right.
  $styles['large_right'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => 400,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'large_right',
  );

  // Exported image style: medium_left.
  $styles['medium_left'] = array(
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => 250,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'medium_left',
  );

  // Exported image style: medium_right.
  $styles['medium_right'] = array(
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => 250,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'medium_right',
  );

  // Exported image style: teaser.
  $styles['teaser'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 160,
          'height' => 120,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'teaser',
  );

  return $styles;
}
