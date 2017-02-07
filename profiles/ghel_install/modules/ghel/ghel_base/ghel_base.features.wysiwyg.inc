<?php
/**
 * @file
 * ghel_base.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function ghel_base_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: filtered_html
  $profiles['filtered_html'] = array(
    'format' => 'filtered_html',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'Strike' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Indent' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Link' => 1,
          'Blockquote' => 1,
          'PasteText' => 1,
          'Format' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
        'video_filter' => array(
          'video_filter' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 1,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 1,
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'css_setting' => 'self',
      'css_path' => '%b%t/css/screen.css',
      'css_classes' => 0,
    ),
    'epub_export_type' => 'wysiwyg_profile',
    'formblock_entity_type' => 'wysiwyg_profile',
    'rdf_mapping' => array(),
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
    ),
  );

  return $profiles;
}
