<?php
/**
 * @file
 * ghel_discussion.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ghel_discussion_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'comment-comment_node_ghel_discussion-comment_body'.
  $field_instances['comment-comment_node_ghel_discussion-comment_body'] = array(
    'bundle' => 'comment_node_ghel_discussion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'comment_body',
    'label' => 'Comment',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'comment-comment_node_ghel_discussion-field_ghel_comm_binary'.
  $field_instances['comment-comment_node_ghel_discussion-field_ghel_comm_binary'] = array(
    'bundle' => 'comment_node_ghel_discussion',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'comment',
    'field_name' => 'field_ghel_comm_binary',
    'formblock_expose' => 0,
    'label' => 'Attachments',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'comm_binary/[current-user:uid]/Y_m',
      'file_extensions' => 'txt ppt doc docx xls pdf odt ovf rtf png jpg gif pptx xlsx mp3 mp4',
      'max_filesize' => '32 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'icon_link',
        'insert_styles' => array(
          'auto' => 0,
          'colorbox__extra_large_center' => 0,
          'colorbox__featured' => 0,
          'colorbox__large' => 0,
          'colorbox__large_center' => 0,
          'colorbox__large_left' => 0,
          'colorbox__large_right' => 0,
          'colorbox__linkit_thumb' => 0,
          'colorbox__medium' => 0,
          'colorbox__medium_center' => 0,
          'colorbox__medium_left' => 0,
          'colorbox__medium_right' => 0,
          'colorbox__teaser' => 0,
          'colorbox__thumbnail' => 0,
          'colorbox__user_profile' => 0,
          'icon_link' => 'icon_link',
          'image' => 0,
          'image_extra_large_center' => 0,
          'image_featured' => 0,
          'image_large' => 0,
          'image_large_center' => 0,
          'image_large_left' => 0,
          'image_large_right' => 0,
          'image_linkit_thumb' => 0,
          'image_medium' => 0,
          'image_medium_center' => 0,
          'image_medium_left' => 0,
          'image_medium_right' => 0,
          'image_teaser' => 0,
          'image_thumbnail' => 0,
          'image_user_profile' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-ghel_discussion-body'.
  $field_instances['node-ghel_discussion-body'] = array(
    'bundle' => 'ghel_discussion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-ghel_discussion-field_ghel_comm_binary'.
  $field_instances['node-ghel_discussion-field_ghel_comm_binary'] = array(
    'bundle' => 'ghel_discussion',
    'deleted' => 0,
    'description' => 'Enter any relevant files. Upload speed of files will vary based on you internet connection. Total file size of all files cannot exceed 32 MB.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_ghel_comm_binary',
    'formblock_expose' => 0,
    'label' => 'Attachments',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'comm_binary/[current-user:uid]/[current-date:custom:Y_m]',
      'file_extensions' => 'txt ppt doc docx xls pdf odt ovf rtf png jpg gif pptx xlsx mp3 mp4',
      'max_filesize' => '32 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'icon_link',
        'insert_styles' => array(
          'auto' => 0,
          'colorbox__extra_large_center' => 0,
          'colorbox__featured' => 0,
          'colorbox__large' => 0,
          'colorbox__large_center' => 0,
          'colorbox__large_left' => 0,
          'colorbox__large_right' => 0,
          'colorbox__linkit_thumb' => 0,
          'colorbox__medium' => 0,
          'colorbox__medium_center' => 0,
          'colorbox__medium_left' => 0,
          'colorbox__medium_right' => 0,
          'colorbox__teaser' => 0,
          'colorbox__thumbnail' => 0,
          'colorbox__user_profile' => 0,
          'icon_link' => 'icon_link',
          'image' => 0,
          'image_extra_large_center' => 0,
          'image_featured' => 0,
          'image_large' => 0,
          'image_large_center' => 0,
          'image_large_left' => 0,
          'image_large_right' => 0,
          'image_linkit_thumb' => 0,
          'image_medium' => 0,
          'image_medium_center' => 0,
          'image_medium_left' => 0,
          'image_medium_right' => 0,
          'image_teaser' => 0,
          'image_thumbnail' => 0,
          'image_user_profile' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-ghel_discussion-field_ghel_post_in'.
  $field_instances['node-ghel_discussion-field_ghel_post_in'] = array(
    'bundle' => 'ghel_discussion',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_ghel_post_in',
    'formblock_expose' => 0,
    'label' => 'Post in',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_buttons',
          ),
          'status' => TRUE,
        ),
        'prepopulate' => array(
          'action' => 'disable',
          'fallback' => 'none',
          'skip_perm' => 'bypass node access',
          'status' => 1,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-ghel_discussion-group_content_access'.
  $field_instances['node-ghel_discussion-group_content_access'] = array(
    'bundle' => 'ghel_discussion',
    'default_value' => array(
      0 => array(
        'value' => 2,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'group_content_access',
    'formblock_expose' => 0,
    'label' => 'Visibility settings',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'view modes' => array(
      'full' => array(
        'label' => 'above',
        'type' => 'list_default',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'list_default',
      ),
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
    'widget_type' => 'options_select',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Attachments');
  t('Body');
  t('Comment');
  t('Enter any relevant files. Upload speed of files will vary based on you internet connection. Total file size of all files cannot exceed 32 MB.');
  t('Post in');
  t('Visibility settings');

  return $field_instances;
}
