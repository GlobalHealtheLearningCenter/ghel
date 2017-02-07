<?php
/**
 * @file
 * ghel_reports.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ghel_reports_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ghel_ach_course';
  $view->description = 'All achievements for individual courses';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Achievements by Course';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Achievements';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
    4 => '4',
    3 => '3',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'achievement_id' => 'achievement_id',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'achievement_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Achievements: Related achievement node */
  $handler->display->display_options['relationships']['achievement_id']['id'] = 'achievement_id';
  $handler->display->display_options['relationships']['achievement_id']['table'] = 'achievement_unlocks';
  $handler->display->display_options['relationships']['achievement_id']['field'] = 'achievement_id';
  $handler->display->display_options['relationships']['achievement_id']['required'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Field: Given/First Name */
  $handler->display->display_options['fields']['field_ghel_first_name']['id'] = 'field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['table'] = 'field_data_field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['field'] = 'field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Family/Last Name */
  $handler->display->display_options['fields']['field_ghel_last_name']['id'] = 'field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['table'] = 'field_data_field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['field'] = 'field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['element_label_colon'] = FALSE;
  /* Field: Achievements: Achievement type */
  $handler->display->display_options['fields']['achievement_type']['id'] = 'achievement_type';
  $handler->display->display_options['fields']['achievement_type']['table'] = 'achievement_unlocks';
  $handler->display->display_options['fields']['achievement_type']['field'] = 'achievement_type';
  /* Field: Achievements: Date achieved */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'achievement_unlocks';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'long';
  /* Field: User: Country */
  $handler->display->display_options['fields']['field_ghel_user_location']['id'] = 'field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['table'] = 'field_data_field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['field'] = 'field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['element_label_colon'] = FALSE;
  /* Field: User: Occupation Category */
  $handler->display->display_options['fields']['field_ghel_occupation_category']['id'] = 'field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['table'] = 'field_data_field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['field'] = 'field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['label'] = 'Occupation';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['element_label_colon'] = FALSE;
  /* Field: User: Organization Category */
  $handler->display->display_options['fields']['field_ghel_organization_category']['id'] = 'field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['table'] = 'field_data_field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['field'] = 'field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['label'] = 'Organization';
  /* Field: User: Sex */
  $handler->display->display_options['fields']['field_ghel_sex']['id'] = 'field_ghel_sex';
  $handler->display->display_options['fields']['field_ghel_sex']['table'] = 'field_data_field_ghel_sex';
  $handler->display->display_options['fields']['field_ghel_sex']['field'] = 'field_ghel_sex';
  $handler->display->display_options['fields']['field_ghel_sex']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'achievement_id';
  $handler->display->display_options['fields']['title']['label'] = 'Course name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Achievements: Achievement Revision */
  $handler->display->display_options['fields']['achievement_revision']['id'] = 'achievement_revision';
  $handler->display->display_options['fields']['achievement_revision']['table'] = 'achievement_unlocks';
  $handler->display->display_options['fields']['achievement_revision']['field'] = 'achievement_revision';
  $handler->display->display_options['fields']['achievement_revision']['label'] = 'Course Revision';
  /* Sort criterion: Achievements: Date achieved */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'achievement_unlocks';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'achievement_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Completion numbers for %1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'ghel_course' => 'ghel_course',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Country (field_ghel_user_location) */
  $handler->display->display_options['filters']['field_ghel_user_location_value']['id'] = 'field_ghel_user_location_value';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['table'] = 'field_data_field_ghel_user_location';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['field'] = 'field_ghel_user_location_value';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_user_location_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['operator_id'] = 'field_ghel_user_location_value_op';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['label'] = 'Filter by Location';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['operator'] = 'field_ghel_user_location_value_op';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['identifier'] = 'location';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ghel_user_location_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: User: Occupation Category (field_ghel_occupation_category) */
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['id'] = 'field_ghel_occupation_category_tid';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['table'] = 'field_data_field_ghel_occupation_category';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['field'] = 'field_ghel_occupation_category_tid';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['operator_id'] = 'field_ghel_occupation_category_tid_op';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['label'] = 'Filter by Occupation';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['operator'] = 'field_ghel_occupation_category_tid_op';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['identifier'] = 'occupation';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['vocabulary'] = 'ghel_occupation_category';
  /* Filter criterion: User: Organization Category (field_ghel_organization_category) */
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['id'] = 'field_ghel_organization_category_tid';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['table'] = 'field_data_field_ghel_organization_category';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['field'] = 'field_ghel_organization_category_tid';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['operator_id'] = 'org_cat_op';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['label'] = 'Filter by Organization';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['operator'] = 'field_ghel_organization_category_tid_op';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['identifier'] = 'org_cat';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['vocabulary'] = 'ghel_organization_category';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['hierarchy'] = 1;
  /* Filter criterion: User: Sex (field_ghel_sex) */
  $handler->display->display_options['filters']['field_ghel_sex_value']['id'] = 'field_ghel_sex_value';
  $handler->display->display_options['filters']['field_ghel_sex_value']['table'] = 'field_data_field_ghel_sex';
  $handler->display->display_options['filters']['field_ghel_sex_value']['field'] = 'field_ghel_sex_value';
  $handler->display->display_options['filters']['field_ghel_sex_value']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_sex_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['operator_id'] = 'field_ghel_sex_value_op';
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['label'] = 'Filter by Sex';
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['operator'] = 'field_ghel_sex_value_op';
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['identifier'] = 'sex';
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ghel_sex_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Achievements: Date achieved */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'achievement_unlocks';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['operator'] = 'between';
  $handler->display->display_options['filters']['timestamp']['group'] = 1;
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Filter by date';
  $handler->display->display_options['filters']['timestamp']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Achievements: Achievement type */
  $handler->display->display_options['filters']['achievement_type']['id'] = 'achievement_type';
  $handler->display->display_options['filters']['achievement_type']['table'] = 'achievement_unlocks';
  $handler->display->display_options['filters']['achievement_type']['field'] = 'achievement_type';
  $handler->display->display_options['filters']['achievement_type']['operator'] = 'like';
  $handler->display->display_options['filters']['achievement_type']['value'] = 'g-c-completion';
  $handler->display->display_options['filters']['achievement_type']['expose']['operator_id'] = 'achievement_type_op';
  $handler->display->display_options['filters']['achievement_type']['expose']['label'] = 'Achievement type';
  $handler->display->display_options['filters']['achievement_type']['expose']['operator'] = 'achievement_type_op';
  $handler->display->display_options['filters']['achievement_type']['expose']['identifier'] = 'achievement_type';
  $handler->display->display_options['filters']['achievement_type']['expose']['remember_roles'] = array(
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

  /* Display: Data review page - completed */
  $handler = $view->new_display('page', 'Data review page - completed', 'page');
  $handler->display->display_options['display_description'] = 'Review and prepare data for users who have started a course';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'course/%/reports/course-complete';

  /* Display: Data export - csv */
  $handler = $view->new_display('views_data_export', 'Data export - csv', 'views_data_export_1');
  $handler->display->display_options['display_description'] = 'Export data in csv format';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-yyyy_%timestamp-mm_%timestamp-mmmm_%timestamp-dd_%1-title.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'course/%/reports/course-complete/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Data export - xls */
  $handler = $view->new_display('views_data_export', 'Data export - xls', 'views_data_export_2');
  $handler->display->display_options['display_description'] = 'Export data in xls format';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-yyyy_%timestamp-mm_%timestamp-mmmm_%timestamp-dd_%1-title.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'course/%/reports/course-complete/xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $export['ghel_ach_course'] = $view;

  $view = new view();
  $view->name = 'ghel_all_achievements';
  $view->description = 'All certificates earned by all users';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'All earned certificates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Earned Certificates';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'achievement_id' => 'achievement_id',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'achievement_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Achievements: Related achievement node */
  $handler->display->display_options['relationships']['achievement_id']['id'] = 'achievement_id';
  $handler->display->display_options['relationships']['achievement_id']['table'] = 'achievement_unlocks';
  $handler->display->display_options['relationships']['achievement_id']['field'] = 'achievement_id';
  $handler->display->display_options['relationships']['achievement_id']['required'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Field: Given/First Name */
  $handler->display->display_options['fields']['field_ghel_first_name']['id'] = 'field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['table'] = 'field_data_field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['field'] = 'field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Family/Last Name */
  $handler->display->display_options['fields']['field_ghel_last_name']['id'] = 'field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['table'] = 'field_data_field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['field'] = 'field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['element_label_colon'] = FALSE;
  /* Field: Achievements: Achievement type */
  $handler->display->display_options['fields']['achievement_type']['id'] = 'achievement_type';
  $handler->display->display_options['fields']['achievement_type']['table'] = 'achievement_unlocks';
  $handler->display->display_options['fields']['achievement_type']['field'] = 'achievement_type';
  /* Field: Achievements: Date achieved */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'achievement_unlocks';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'long';
  /* Field: User: Country */
  $handler->display->display_options['fields']['field_ghel_user_location']['id'] = 'field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['table'] = 'field_data_field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['field'] = 'field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['element_label_colon'] = FALSE;
  /* Field: User: Occupation Category */
  $handler->display->display_options['fields']['field_ghel_occupation_category']['id'] = 'field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['table'] = 'field_data_field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['field'] = 'field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['label'] = 'Occupation';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['element_label_colon'] = FALSE;
  /* Field: User: Organization Category */
  $handler->display->display_options['fields']['field_ghel_organization_category']['id'] = 'field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['table'] = 'field_data_field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['field'] = 'field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['label'] = 'Organization';
  /* Field: User: Sex */
  $handler->display->display_options['fields']['field_ghel_sex']['id'] = 'field_ghel_sex';
  $handler->display->display_options['fields']['field_ghel_sex']['table'] = 'field_data_field_ghel_sex';
  $handler->display->display_options['fields']['field_ghel_sex']['field'] = 'field_ghel_sex';
  $handler->display->display_options['fields']['field_ghel_sex']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'achievement_id';
  $handler->display->display_options['fields']['title']['label'] = 'Course name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['access']['date_format'] = 'medium';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['login']['date_format'] = 'medium';
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  /* Sort criterion: Achievements: Date achieved */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'achievement_unlocks';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Achievements: Date achieved */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'achievement_unlocks';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['operator'] = 'between';
  $handler->display->display_options['filters']['timestamp']['group'] = 1;
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Filter by date';
  $handler->display->display_options['filters']['timestamp']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'achievement_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Filter by Course Name';
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
  /* Filter criterion: User: Country (field_ghel_user_location) */
  $handler->display->display_options['filters']['field_ghel_user_location_value']['id'] = 'field_ghel_user_location_value';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['table'] = 'field_data_field_ghel_user_location';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['field'] = 'field_ghel_user_location_value';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_user_location_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['operator_id'] = 'field_ghel_user_location_value_op';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['label'] = 'Filter by Location';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['operator'] = 'field_ghel_user_location_value_op';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['identifier'] = 'location';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ghel_user_location_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: User: Occupation Category (field_ghel_occupation_category) */
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['id'] = 'field_ghel_occupation_category_tid';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['table'] = 'field_data_field_ghel_occupation_category';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['field'] = 'field_ghel_occupation_category_tid';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['operator_id'] = 'field_ghel_occupation_category_tid_op';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['label'] = 'Filter by Occupation';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['operator'] = 'field_ghel_occupation_category_tid_op';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['identifier'] = 'occupation';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['vocabulary'] = 'ghel_occupation_category';
  /* Filter criterion: User: Organization Category (field_ghel_organization_category) */
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['id'] = 'field_ghel_organization_category_tid';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['table'] = 'field_data_field_ghel_organization_category';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['field'] = 'field_ghel_organization_category_tid';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['operator_id'] = 'org_cat_op';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['label'] = 'Filter by Organization';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['operator'] = 'field_ghel_organization_category_tid_op';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['identifier'] = 'org_cat';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['vocabulary'] = 'ghel_organization_category';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['hierarchy'] = 1;
  /* Filter criterion: User: Sex (field_ghel_sex) */
  $handler->display->display_options['filters']['field_ghel_sex_value']['id'] = 'field_ghel_sex_value';
  $handler->display->display_options['filters']['field_ghel_sex_value']['table'] = 'field_data_field_ghel_sex';
  $handler->display->display_options['filters']['field_ghel_sex_value']['field'] = 'field_ghel_sex_value';
  $handler->display->display_options['filters']['field_ghel_sex_value']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_sex_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['operator_id'] = 'field_ghel_sex_value_op';
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['label'] = 'Filter by Sex';
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['operator'] = 'field_ghel_sex_value_op';
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['identifier'] = 'sex';
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ghel_sex_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['mail']['group_info']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['group_info']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['mail']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Achievements: Achievement type */
  $handler->display->display_options['filters']['achievement_type']['id'] = 'achievement_type';
  $handler->display->display_options['filters']['achievement_type']['table'] = 'achievement_unlocks';
  $handler->display->display_options['filters']['achievement_type']['field'] = 'achievement_type';
  $handler->display->display_options['filters']['achievement_type']['operator'] = 'like';
  $handler->display->display_options['filters']['achievement_type']['value'] = 'g-c-completion';
  $handler->display->display_options['filters']['achievement_type']['group'] = 2;
  /* Filter criterion: Achievements: Achievement type */
  $handler->display->display_options['filters']['achievement_type_1']['id'] = 'achievement_type_1';
  $handler->display->display_options['filters']['achievement_type_1']['table'] = 'achievement_unlocks';
  $handler->display->display_options['filters']['achievement_type_1']['field'] = 'achievement_type';
  $handler->display->display_options['filters']['achievement_type_1']['operator'] = 'like';
  $handler->display->display_options['filters']['achievement_type_1']['value'] = 'g-p-completion';
  $handler->display->display_options['filters']['achievement_type_1']['group'] = 2;

  /* Display: Reports - data review */
  $handler = $view->new_display('page', 'Reports - data review', 'page');
  $handler->display->display_options['display_description'] = 'Review all data prior to export';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'reports/all';

  /* Display: Data export - csv */
  $handler = $view->new_display('views_data_export', 'Data export - csv', 'views_data_export_1');
  $handler->display->display_options['display_description'] = 'Export data in csv format';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'ghel_%timestamp-yyyy_%timestamp-mm_%timestamp-mmmm_%timestamp-dd.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'reports/all/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';

  /* Display: Data export - xls */
  $handler = $view->new_display('views_data_export', 'Data export - xls', 'views_data_export_2');
  $handler->display->display_options['display_description'] = 'Export data in excel format';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'ghel_%timestamp-yyyy_%timestamp-mm_%timestamp-mmmm_%timestamp-dd.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'reports/all/xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $export['ghel_all_achievements'] = $view;

  $view = new view();
  $view->name = 'ghel_email_members';
  $view->description = 'Email members';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Email members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Email members';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'uid' => 'uid',
    'field_ghel_first_name' => 'field_ghel_first_name',
    'picture' => 'field_ghel_last_name',
    'mail' => 'field_ghel_last_name',
    'field_ghel_last_name' => 'field_ghel_last_name',
    'access' => 'access',
    'field_ghel_user_location' => 'field_ghel_user_location',
    'field_ghel_occupation_category' => 'field_ghel_occupation_category',
    'field_ghel_organization_category' => 'field_ghel_organization_category',
    'rid' => 'rid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ghel_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ', ',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ghel_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'access' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ghel_user_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ghel_occupation_category' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ghel_organization_category' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Global: Send e-mail */
  $handler->display->display_options['fields']['views_send']['id'] = 'views_send';
  $handler->display->display_options['fields']['views_send']['table'] = 'views';
  $handler->display->display_options['fields']['views_send']['field'] = 'views_send';
  $handler->display->display_options['fields']['views_send']['element_label_colon'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Field: Field: Given/First Name */
  $handler->display->display_options['fields']['field_ghel_first_name']['id'] = 'field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['table'] = 'field_data_field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['field'] = 'field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ghel_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  /* Field: User: Family/Last Name */
  $handler->display->display_options['fields']['field_ghel_last_name']['id'] = 'field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['table'] = 'field_data_field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['field'] = 'field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_ghel_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ghel_last_name']['alter']['text'] = '[field_ghel_first_name] [field_ghel_last_name]';
  $handler->display->display_options['fields']['field_ghel_last_name']['element_label_colon'] = FALSE;
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['access']['date_format'] = 'medium';
  /* Field: User: Country */
  $handler->display->display_options['fields']['field_ghel_user_location']['id'] = 'field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['table'] = 'field_data_field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['field'] = 'field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['element_label_colon'] = FALSE;
  /* Field: User: Occupation Category */
  $handler->display->display_options['fields']['field_ghel_occupation_category']['id'] = 'field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['table'] = 'field_data_field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['field'] = 'field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['element_label_colon'] = FALSE;
  /* Field: User: Organization Category */
  $handler->display->display_options['fields']['field_ghel_organization_category']['id'] = 'field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['table'] = 'field_data_field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['field'] = 'field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['element_label_colon'] = FALSE;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rid']['separator'] = ' | ';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field: Given/First Name (field_ghel_first_name) */
  $handler->display->display_options['filters']['field_ghel_first_name_value']['id'] = 'field_ghel_first_name_value';
  $handler->display->display_options['filters']['field_ghel_first_name_value']['table'] = 'field_data_field_ghel_first_name';
  $handler->display->display_options['filters']['field_ghel_first_name_value']['field'] = 'field_ghel_first_name_value';
  $handler->display->display_options['filters']['field_ghel_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_ghel_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_first_name_value']['expose']['operator_id'] = 'field_ghel_first_name_value_op';
  $handler->display->display_options['filters']['field_ghel_first_name_value']['expose']['label'] = 'Filter by First Name';
  $handler->display->display_options['filters']['field_ghel_first_name_value']['expose']['operator'] = 'field_ghel_first_name_value_op';
  $handler->display->display_options['filters']['field_ghel_first_name_value']['expose']['identifier'] = 'field_ghel_first_name_value';
  $handler->display->display_options['filters']['field_ghel_first_name_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: User: Family/Last Name (field_ghel_last_name) */
  $handler->display->display_options['filters']['field_ghel_last_name_value']['id'] = 'field_ghel_last_name_value';
  $handler->display->display_options['filters']['field_ghel_last_name_value']['table'] = 'field_data_field_ghel_last_name';
  $handler->display->display_options['filters']['field_ghel_last_name_value']['field'] = 'field_ghel_last_name_value';
  $handler->display->display_options['filters']['field_ghel_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_ghel_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_last_name_value']['expose']['operator_id'] = 'field_ghel_last_name_value_op';
  $handler->display->display_options['filters']['field_ghel_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_ghel_last_name_value']['expose']['operator'] = 'field_ghel_last_name_value_op';
  $handler->display->display_options['filters']['field_ghel_last_name_value']['expose']['identifier'] = 'last_name';
  $handler->display->display_options['filters']['field_ghel_last_name_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'Email';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
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
  /* Filter criterion: User: Country (field_ghel_user_location) */
  $handler->display->display_options['filters']['field_ghel_user_location_value']['id'] = 'field_ghel_user_location_value';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['table'] = 'field_data_field_ghel_user_location';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['field'] = 'field_ghel_user_location_value';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_user_location_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['operator_id'] = 'location_op';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['label'] = 'Filter by Location';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['operator'] = 'field_ghel_user_location_value_op';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['identifier'] = 'location_value';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ghel_user_location_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: User: Organization Category (field_ghel_organization_category) */
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['id'] = 'field_ghel_organization_category_tid';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['table'] = 'field_data_field_ghel_organization_category';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['field'] = 'field_ghel_organization_category_tid';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['value'] = '';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['operator_id'] = 'field_ghel_organization_category_tid_op';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['label'] = 'Filter by Organization Category';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['operator'] = 'field_ghel_organization_category_tid_op';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['identifier'] = 'org_cat';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['vocabulary'] = 'ghel_organization_category';
  /* Filter criterion: User: Last access */
  $handler->display->display_options['filters']['access']['id'] = 'access';
  $handler->display->display_options['filters']['access']['table'] = 'users';
  $handler->display->display_options['filters']['access']['field'] = 'access';
  $handler->display->display_options['filters']['access']['operator'] = 'between';
  $handler->display->display_options['filters']['access']['exposed'] = TRUE;
  $handler->display->display_options['filters']['access']['expose']['operator_id'] = 'access_op';
  $handler->display->display_options['filters']['access']['expose']['label'] = 'Access dates';
  $handler->display->display_options['filters']['access']['expose']['description'] = 'Filter by access dates';
  $handler->display->display_options['filters']['access']['expose']['operator'] = 'access_op';
  $handler->display->display_options['filters']['access']['expose']['identifier'] = 'access';
  $handler->display->display_options['filters']['access']['expose']['remember_roles'] = array(
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
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Filter by role';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'email-members';
  $export['ghel_email_members'] = $view;

  $view = new view();
  $view->name = 'ghel_list_group_mem_report';
  $view->description = 'Reports for group members';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Reports for group members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Group members';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_ghel_first_name' => 'field_ghel_first_name',
    'picture' => 'picture',
    'field_ghel_last_name' => 'field_ghel_last_name',
    'view_user' => 'view_user',
    'field_ghel_user_location' => 'field_ghel_user_location',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_ghel_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ghel_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_user' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ghel_user_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Field: Field: Given/First Name */
  $handler->display->display_options['fields']['field_ghel_first_name']['id'] = 'field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['table'] = 'field_data_field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['field'] = 'field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Family/Last Name */
  $handler->display->display_options['fields']['field_ghel_last_name_1']['id'] = 'field_ghel_last_name_1';
  $handler->display->display_options['fields']['field_ghel_last_name_1']['table'] = 'field_data_field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name_1']['field'] = 'field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name_1']['element_label_colon'] = FALSE;
  /* Field: User: Family/Last Name */
  $handler->display->display_options['fields']['field_ghel_last_name']['id'] = 'field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['table'] = 'field_data_field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['field'] = 'field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['label'] = 'Full name';
  $handler->display->display_options['fields']['field_ghel_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ghel_last_name']['alter']['text'] = '[field_ghel_first_name] [field_ghel_last_name] ';
  $handler->display->display_options['fields']['field_ghel_last_name']['element_label_colon'] = FALSE;
  /* Field: User: Country */
  $handler->display->display_options['fields']['field_ghel_user_location']['id'] = 'field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['table'] = 'field_data_field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['field'] = 'field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['og_user_node']['id'] = 'og_user_node';
  $handler->display->display_options['fields']['og_user_node']['table'] = 'field_data_og_user_node';
  $handler->display->display_options['fields']['og_user_node']['field'] = 'og_user_node';
  $handler->display->display_options['fields']['og_user_node']['label'] = 'All Groups';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['label'] = 'Site role(s)';
  $handler->display->display_options['fields']['rid']['element_label_colon'] = FALSE;
  /* Field: OG membership: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'og_membership';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: User: Occupation Category */
  $handler->display->display_options['fields']['field_ghel_occupation_category']['id'] = 'field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['table'] = 'field_data_field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['field'] = 'field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['element_label_colon'] = FALSE;
  /* Field: User: Organization Category */
  $handler->display->display_options['fields']['field_ghel_organization_category']['id'] = 'field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['table'] = 'field_data_field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['field'] = 'field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['element_label_colon'] = FALSE;
  /* Field: User: Sex */
  $handler->display->display_options['fields']['field_ghel_sex']['id'] = 'field_ghel_sex';
  $handler->display->display_options['fields']['field_ghel_sex']['table'] = 'field_data_field_ghel_sex';
  $handler->display->display_options['fields']['field_ghel_sex']['field'] = 'field_ghel_sex';
  $handler->display->display_options['fields']['field_ghel_sex']['element_label_colon'] = FALSE;
  /* Field: User: USAID category */
  $handler->display->display_options['fields']['field_ghel_usaid_category']['id'] = 'field_ghel_usaid_category';
  $handler->display->display_options['fields']['field_ghel_usaid_category']['table'] = 'field_data_field_ghel_usaid_category';
  $handler->display->display_options['fields']['field_ghel_usaid_category']['field'] = 'field_ghel_usaid_category';
  $handler->display->display_options['fields']['field_ghel_usaid_category']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Family/Last Name (field_ghel_last_name) */
  $handler->display->display_options['sorts']['field_ghel_last_name_value']['id'] = 'field_ghel_last_name_value';
  $handler->display->display_options['sorts']['field_ghel_last_name_value']['table'] = 'field_data_field_ghel_last_name';
  $handler->display->display_options['sorts']['field_ghel_last_name_value']['field'] = 'field_ghel_last_name_value';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['gid']['title'] = 'Members';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'ghel-admin/members/report/%';

  /* Display: Export - xls */
  $handler = $view->new_display('views_data_export', 'Export - xls', 'views_data_export_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'group_%1-title_%timestamp-yyyy_%timestamp-mmm_%timestamp-dd_.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'ghel-admin/members/report/%/xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Export - csv */
  $handler = $view->new_display('views_data_export', 'Export - csv', 'views_data_export_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'group_%1-title_%timestamp-yyyy_%timestamp-mmm_%timestamp-dd_.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'ghel-admin/members/report/%/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['ghel_list_group_mem_report'] = $view;

  $view = new view();
  $view->name = 'ghel_new_users';
  $view->description = 'All certificates earned by all users';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'New users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'New Users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'achievement_id' => 'achievement_id',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'achievement_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Field: Given/First Name */
  $handler->display->display_options['fields']['field_ghel_first_name']['id'] = 'field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['table'] = 'field_data_field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['field'] = 'field_ghel_first_name';
  $handler->display->display_options['fields']['field_ghel_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Family/Last Name */
  $handler->display->display_options['fields']['field_ghel_last_name']['id'] = 'field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['table'] = 'field_data_field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['field'] = 'field_ghel_last_name';
  $handler->display->display_options['fields']['field_ghel_last_name']['element_label_colon'] = FALSE;
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Joined';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  /* Field: User: Country */
  $handler->display->display_options['fields']['field_ghel_user_location']['id'] = 'field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['table'] = 'field_data_field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['field'] = 'field_ghel_user_location';
  $handler->display->display_options['fields']['field_ghel_user_location']['element_label_colon'] = FALSE;
  /* Field: User: Occupation Category */
  $handler->display->display_options['fields']['field_ghel_occupation_category']['id'] = 'field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['table'] = 'field_data_field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['field'] = 'field_ghel_occupation_category';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['label'] = 'Occupation';
  $handler->display->display_options['fields']['field_ghel_occupation_category']['element_label_colon'] = FALSE;
  /* Field: User: Organization Category */
  $handler->display->display_options['fields']['field_ghel_organization_category']['id'] = 'field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['table'] = 'field_data_field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['field'] = 'field_ghel_organization_category';
  $handler->display->display_options['fields']['field_ghel_organization_category']['label'] = 'Organization';
  /* Field: User: Sex */
  $handler->display->display_options['fields']['field_ghel_sex']['id'] = 'field_ghel_sex';
  $handler->display->display_options['fields']['field_ghel_sex']['table'] = 'field_data_field_ghel_sex';
  $handler->display->display_options['fields']['field_ghel_sex']['field'] = 'field_ghel_sex';
  $handler->display->display_options['fields']['field_ghel_sex']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['access']['date_format'] = 'medium';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['login']['date_format'] = 'medium';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Created date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'users';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Joined between';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
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
  /* Filter criterion: User: Country (field_ghel_user_location) */
  $handler->display->display_options['filters']['field_ghel_user_location_value']['id'] = 'field_ghel_user_location_value';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['table'] = 'field_data_field_ghel_user_location';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['field'] = 'field_ghel_user_location_value';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_user_location_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['operator_id'] = 'field_ghel_user_location_value_op';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['label'] = 'Filter by Location';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['operator'] = 'field_ghel_user_location_value_op';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['identifier'] = 'location';
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_user_location_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ghel_user_location_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: User: Occupation Category (field_ghel_occupation_category) */
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['id'] = 'field_ghel_occupation_category_tid';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['table'] = 'field_data_field_ghel_occupation_category';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['field'] = 'field_ghel_occupation_category_tid';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['operator_id'] = 'field_ghel_occupation_category_tid_op';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['label'] = 'Filter by Occupation';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['operator'] = 'field_ghel_occupation_category_tid_op';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['identifier'] = 'occupation';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ghel_occupation_category_tid']['vocabulary'] = 'ghel_occupation_category';
  /* Filter criterion: User: Organization Category (field_ghel_organization_category) */
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['id'] = 'field_ghel_organization_category_tid';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['table'] = 'field_data_field_ghel_organization_category';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['field'] = 'field_ghel_organization_category_tid';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['operator_id'] = 'org_cat_op';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['label'] = 'Filter by Organization';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['operator'] = 'field_ghel_organization_category_tid_op';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['identifier'] = 'org_cat';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['vocabulary'] = 'ghel_organization_category';
  $handler->display->display_options['filters']['field_ghel_organization_category_tid']['hierarchy'] = 1;
  /* Filter criterion: User: Sex (field_ghel_sex) */
  $handler->display->display_options['filters']['field_ghel_sex_value']['id'] = 'field_ghel_sex_value';
  $handler->display->display_options['filters']['field_ghel_sex_value']['table'] = 'field_data_field_ghel_sex';
  $handler->display->display_options['filters']['field_ghel_sex_value']['field'] = 'field_ghel_sex_value';
  $handler->display->display_options['filters']['field_ghel_sex_value']['group'] = 1;
  $handler->display->display_options['filters']['field_ghel_sex_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['operator_id'] = 'field_ghel_sex_value_op';
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['label'] = 'Filter by Sex';
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['operator'] = 'field_ghel_sex_value_op';
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['identifier'] = 'sex';
  $handler->display->display_options['filters']['field_ghel_sex_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ghel_sex_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['mail']['group_info']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['group_info']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['mail']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );

  /* Display: New user - data review */
  $handler = $view->new_display('page', 'New user - data review', 'page');
  $handler->display->display_options['display_description'] = 'Review new user data prior to export';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'reports/users-new';

  /* Display: New user export - csv */
  $handler = $view->new_display('views_data_export', 'New user export - csv', 'views_data_export_1');
  $handler->display->display_options['display_description'] = 'Export new user data in csv format';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'new_users_ghel_%timestamp-yyyy_%timestamp-mm_%timestamp-mmmm_%timestamp-dd.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'reports/users-new/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';

  /* Display: New user export - xls */
  $handler = $view->new_display('views_data_export', 'New user export - xls', 'views_data_export_2');
  $handler->display->display_options['display_description'] = 'Export new user data in excel format';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'new_users_ghel_%timestamp-yyyy_%timestamp-mm_%timestamp-mmmm_%timestamp-dd.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'reports/users-new/xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $export['ghel_new_users'] = $view;

  return $export;
}
