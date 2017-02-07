<?php
/**
 * @file
 * ghel_trans_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ghel_trans_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ghel_trans_views';
  $view->description = 'A list of courses for the Courses page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Translations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    7 => '7',
    8 => '8',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'New Search';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'article-item';
  $handler->display->display_options['style_options']['class'] = 'article-list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'large_teaser_thumb',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ghel_translation' => 'ghel_translation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Search by title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['ui_name'] = 'Search by title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Language (field_ghel_language) */
  $handler->display->display_options['filters']['field_ghel_language_tid']['id'] = 'field_ghel_language_tid';
  $handler->display->display_options['filters']['field_ghel_language_tid']['table'] = 'field_data_field_ghel_language';
  $handler->display->display_options['filters']['field_ghel_language_tid']['field'] = 'field_ghel_language_tid';
  $handler->display->display_options['filters']['field_ghel_language_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_language_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_language_tid']['expose']['operator_id'] = 'field_ghel_language_tid_op';
  $handler->display->display_options['filters']['field_ghel_language_tid']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['field_ghel_language_tid']['expose']['operator'] = 'field_ghel_language_tid_op';
  $handler->display->display_options['filters']['field_ghel_language_tid']['expose']['identifier'] = 'field_ghel_language_tid';
  $handler->display->display_options['filters']['field_ghel_language_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_ghel_language_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ghel_language_tid']['vocabulary'] = 'ghel_trans_language';

  /* Display: Translations */
  $handler = $view->new_display('block', 'Translations', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    1 => '1',
    2 => '2',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'large_teaser_thumb',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '55';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Promotional Text */
  $handler->display->display_options['fields']['field_ghel_promotional_text']['id'] = 'field_ghel_promotional_text';
  $handler->display->display_options['fields']['field_ghel_promotional_text']['table'] = 'field_data_field_ghel_promotional_text';
  $handler->display->display_options['fields']['field_ghel_promotional_text']['field'] = 'field_ghel_promotional_text';
  $handler->display->display_options['fields']['field_ghel_promotional_text']['label'] = '';
  $handler->display->display_options['fields']['field_ghel_promotional_text']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['field_ghel_promotional_text']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_ghel_promotional_text']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_ghel_promotional_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Translations - list and search';

  /* Display: Admin translation list */
  $handler = $view->new_display('page', 'Admin translation list', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Administrative Translation List';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    3 => '3',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'sid' => 'sid',
    'edit_node' => 'title',
    'field_ghel_course_list' => 'field_ghel_course_list',
    'field_ghel_featured' => 'field_ghel_featured',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'sid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ghel_course_list' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ghel_featured' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<ul>
<li>
<a href="/node/add/ghel-translation" alt="Add a new translation" title="Add a new translation">Add a new translation</a>
</li>
</ul>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Course name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_ghel_language']['id'] = 'field_ghel_language';
  $handler->display->display_options['fields']['field_ghel_language']['table'] = 'field_data_field_ghel_language';
  $handler->display->display_options['fields']['field_ghel_language']['field'] = 'field_ghel_language';
  $handler->display->display_options['fields']['field_ghel_language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ghel_language']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Promotional Text */
  $handler->display->display_options['fields']['field_ghel_promotional_text']['id'] = 'field_ghel_promotional_text';
  $handler->display->display_options['fields']['field_ghel_promotional_text']['table'] = 'field_data_field_ghel_promotional_text';
  $handler->display->display_options['fields']['field_ghel_promotional_text']['field'] = 'field_ghel_promotional_text';
  $handler->display->display_options['fields']['field_ghel_promotional_text']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_ghel_promotional_text']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_ghel_promotional_text']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_ghel_promotional_text']['element_label_colon'] = FALSE;
  /* Field: Content: Translation */
  $handler->display->display_options['fields']['field_ghel_trans_file']['id'] = 'field_ghel_trans_file';
  $handler->display->display_options['fields']['field_ghel_trans_file']['table'] = 'field_data_field_ghel_trans_file';
  $handler->display->display_options['fields']['field_ghel_trans_file']['field'] = 'field_ghel_trans_file';
  $handler->display->display_options['fields']['field_ghel_trans_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ghel_trans_file']['empty'] = 'No file attached';
  $handler->display->display_options['fields']['field_ghel_trans_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_ghel_trans_file']['delta_offset'] = '0';
  $handler->display->display_options['path'] = 'translation-list/admin';
  $export['ghel_trans_views'] = $view;

  return $export;
}
