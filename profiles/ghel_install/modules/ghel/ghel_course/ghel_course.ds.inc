<?php
/**
 * @file
 * ghel_course.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ghel_course_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ghel_course|featured';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ghel_course';
  $ds_fieldsetting->view_mode = 'featured';
  $ds_fieldsetting->settings = array(
    'ghel_learn_more' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => 'article-title',
      ),
    ),
  );
  $export['node|ghel_course|featured'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ghel_course|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ghel_course';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'ghel_offline_content' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'course_start' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_html5_field_section',
        ),
      ),
    ),
    'field_ghel_course_authors' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_html5_field_ul',
        ),
      ),
    ),
    'field_ghel_course_managers' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_html5_field_ul',
        ),
      ),
    ),
    'field_ghel_credits' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Credits',
          'lb-el' => 'h3',
          'lb-cl' => 'credits-title field-label',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'section',
          'ow-cl' => 'credits',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'credits-content',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_ghel_objective' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_html5_field_section',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_ghel_related_courses' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_html5_field_ul',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_ghel_time' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_html5_field_section',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_ghel_link_toolkits' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_html5_field_ul',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_ghel_pub_up' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Published/Updated',
          'lb-el' => 'label',
          'lb-cl' => 'credits-title field-label',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'clearfix pub-wrapper',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|ghel_course|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ghel_course|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ghel_course';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => 'article-title',
      ),
    ),
    'field_ghel_promotional_text' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|ghel_course|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function ghel_course_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_start';
  $ds_field->label = 'Course Start';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'ghel_course|start',
    'block_render' => '3',
  );
  $export['course_start'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'ghel_learn_more';
  $ds_field->label = 'Learn More';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="[node:url]" class="learn-more">Learn More</a>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['ghel_learn_more'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'ghel_offline_content';
  $ds_field->label = 'Offline Content';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'ghel_course|offline',
    'block_render' => '2',
  );
  $export['ghel_offline_content'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ghel_course_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_course|featured';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_course';
  $ds_layout->view_mode = 'featured';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_image',
      ),
      'main_content' => array(
        1 => 'title',
        2 => 'ghel_learn_more',
      ),
    ),
    'fields' => array(
      'field_image' => 'header',
      'title' => 'main_content',
      'ghel_learn_more' => 'main_content',
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
  );
  $export['node|ghel_course|featured'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_course|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_course';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'regions' => array(
      'main_content' => array(
        0 => 'group_contentheader',
        1 => 'course_start',
        2 => 'field_image',
        3 => 'field_ghel_objective',
        4 => 'body',
        5 => 'field_ghel_credits',
      ),
      'aside' => array(
        6 => 'group_asideinner',
        7 => 'ghel_offline_content',
        8 => 'field_ghel_time',
        9 => 'field_translation_files',
        10 => 'field_ghel_pub_up',
        11 => 'field_ghel_course_authors',
        12 => 'field_ghel_course_managers',
        13 => 'field_ghel_related_courses',
        14 => 'field_ghel_link_toolkits',
      ),
    ),
    'fields' => array(
      'group_contentheader' => 'main_content',
      'course_start' => 'main_content',
      'field_image' => 'main_content',
      'field_ghel_objective' => 'main_content',
      'body' => 'main_content',
      'field_ghel_credits' => 'main_content',
      'group_asideinner' => 'aside',
      'ghel_offline_content' => 'aside',
      'field_ghel_time' => 'aside',
      'field_translation_files' => 'aside',
      'field_ghel_pub_up' => 'aside',
      'field_ghel_course_authors' => 'aside',
      'field_ghel_course_managers' => 'aside',
      'field_ghel_related_courses' => 'aside',
      'field_ghel_link_toolkits' => 'aside',
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
  $export['node|ghel_course|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_course|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_course';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_image',
      ),
      'main_content' => array(
        1 => 'title',
        2 => 'field_ghel_promotional_text',
      ),
    ),
    'fields' => array(
      'field_image' => 'header',
      'title' => 'main_content',
      'field_ghel_promotional_text' => 'main_content',
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
  );
  $export['node|ghel_course|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ghel_course_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'featured';
  $ds_view_mode->label = 'Featured';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['featured'] = $ds_view_mode;

  return $export;
}
