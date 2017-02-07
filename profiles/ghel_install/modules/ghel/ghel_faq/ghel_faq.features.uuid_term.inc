<?php
/**
 * @file
 * ghel_faq.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function ghel_faq_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Translations',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3da470b4-36d2-1154-a1c0-f82161be4845',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_faq_categories',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
    ),
  );
  $terms[] = array(
    'name' => 'Course Development',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '7c0bdabe-e143-e664-ddc8-bce9679302ea',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_faq_categories',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
    ),
  );
  $terms[] = array(
    'name' => 'Certificate Questions',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b649ce27-41b6-7ca4-513c-27e0656e995f',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_faq_categories',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
    ),
  );
  $terms[] = array(
    'name' => 'Course Access',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c48a3cec-993a-e1d4-65a6-7e49647e2295',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_faq_categories',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
    ),
  );
  return $terms;
}
