<?php
/**
 * @file
 * ghel_announcement.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function ghel_announcement_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Announcement',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4c350404-52c1-6674-d975-7d2a43cdcd84',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_announcement_types',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
    ),
  );
  $terms[] = array(
    'name' => 'Conference Announcement',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5dc75a2b-d92b-a6a4-4d0a-5c84419dd879',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_announcement_types',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
    ),
  );
  $terms[] = array(
    'name' => 'Learner Profile Highlight',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8ac88178-4112-88a4-cd40-c5df2f09c3e3',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_announcement_types',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
    ),
  );
  return $terms;
}
