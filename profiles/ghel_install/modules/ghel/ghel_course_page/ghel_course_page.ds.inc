<?php
/**
 * @file
 * ghel_course_page.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function ghel_course_page_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'ghel_highlight_1';
  $ds_field->label = 'Highlight 1';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php if (isset($entity->field_ghel_highlight_1_type_[\'und\'][0][\'safe_value\'])) { 
  print \'<h3 class="highlight-heading highligh-heading-1">\' . $entity->field_ghel_highlight_1_type_[\'und\'][0][\'safe_value\'] . \'</h3>\';
} ?> 
<?php if (isset($entity->field_ghel_highlight_1_[\'und\'][0][\'safe_value\'])) { 
  print \'<div class="highlight-content highlight-content-1">\' . $entity->field_ghel_highlight_1_[\'und\'][0][\'safe_value\'] . \'</div>\';
} ?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['ghel_highlight_1'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'ghel_highlight_2';
  $ds_field->label = 'Highlight 2';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php if (isset($entity->field_ghel_highlight_2_type_[\'und\'][0][\'safe_value\'])) { 
  print \'<h3 class="highlight-heading highligh-heading-2">\' . $entity->field_ghel_highlight_2_type_[\'und\'][0][\'safe_value\'] . \'</h3>\';
} ?> 
<?php if (isset($entity->field_ghel_highlight_2_[\'und\'][0][\'safe_value\'])) { 
  print \'<div class="highlight-content highlight-content-2">\' . $entity->field_ghel_highlight_2_[\'und\'][0][\'safe_value\'] . \'</div>\';
} ?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['ghel_highlight_2'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ghel_course_page_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_course_page|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_course_page';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'regions' => array(
      'main_content' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'body' => 'main_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'hgroup' => 'div',
      'main_content' => 'div',
      'figure' => 'div',
      'aside' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|ghel_course_page|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_course_page|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_course_page';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'main_content' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'body' => 'main_content',
    ),
    'classes' => array(),
  );
  $export['node|ghel_course_page|teaser'] = $ds_layout;

  return $export;
}
