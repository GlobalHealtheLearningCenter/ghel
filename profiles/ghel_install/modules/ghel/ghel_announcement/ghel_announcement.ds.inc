<?php
/**
 * @file
 * ghel_announcement.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ghel_announcement_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ghel_announcement|dated';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ghel_announcement';
  $ds_fieldsetting->view_mode = 'dated';
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
    'post_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
  );
  $export['node|ghel_announcement|dated'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ghel_announcement|dated_featured';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ghel_announcement';
  $ds_fieldsetting->view_mode = 'dated_featured';
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
    'node_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more',
        'wrapper' => '',
        'class' => '',
      ),
    ),
    'post_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
  );
  $export['node|ghel_announcement|dated_featured'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ghel_announcement|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ghel_announcement';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
    'field_ghel_file' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_html5_field_ul',
          'lb' => 'Related file(s)',
        ),
      ),
    ),
  );
  $export['node|ghel_announcement|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ghel_announcement|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ghel_announcement';
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
    'node_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
  );
  $export['node|ghel_announcement|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ghel_announcement_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_announcement|dated';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_announcement';
  $ds_layout->view_mode = 'dated';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'post_date',
      ),
      'main_content' => array(
        0 => 'title',
      ),
    ),
    'fields' => array(
      'post_date' => 'header',
      'title' => 'main_content',
    ),
    'classes' => array(),
  );
  $export['node|ghel_announcement|dated'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_announcement|dated_featured';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_announcement';
  $ds_layout->view_mode = 'dated_featured';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'post_date',
      ),
      'main_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'node_link',
      ),
    ),
    'fields' => array(
      'post_date' => 'header',
      'title' => 'main_content',
      'body' => 'main_content',
      'node_link' => 'main_content',
    ),
    'classes' => array(),
  );
  $export['node|ghel_announcement|dated_featured'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_announcement|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_announcement';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'article';
  $ds_layout->settings = array(
    'regions' => array(
      'main_content' => array(
        0 => 'body',
        1 => 'field_ghel_file',
      ),
      'aside' => array(
        2 => 'field_image',
        3 => 'post_date',
      ),
    ),
    'fields' => array(
      'body' => 'main_content',
      'field_ghel_file' => 'main_content',
      'field_image' => 'aside',
      'post_date' => 'aside',
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
  $export['node|ghel_announcement|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ghel_announcement|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ghel_announcement';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'post_date',
        1 => 'title',
        2 => 'body',
        3 => 'node_link',
      ),
    ),
    'fields' => array(
      'post_date' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|ghel_announcement|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ghel_announcement_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'dated';
  $ds_view_mode->label = 'dated';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['dated'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'dated_featured';
  $ds_view_mode->label = 'dated-featured';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['dated_featured'] = $ds_view_mode;

  return $export;
}
