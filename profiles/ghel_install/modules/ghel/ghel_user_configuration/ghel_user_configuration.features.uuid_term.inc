<?php
/**
 * @file
 * ghel_user_configuration.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function ghel_user_configuration_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Other',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '049d85ae-fb16-9f24-5552-bb5da2cbc931',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_occupation_category',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
    ),
  );
  $terms[] = array(
    'name' => 'Academic',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6d04380a-8315-a0c4-f1f6-93e75d734664',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_occupation_category',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
    ),
  );
  $terms[] = array(
    'name' => 'Programmatic',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '92d86690-549f-9574-61a8-67a556aa5c75',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_occupation_category',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
    ),
  );
  $terms[] = array(
    'name' => 'Tanzanian Health Network Programme',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => 'a5f6dc74-5fe6-489c-9429-04c4df390ea8',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_occupation_category',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
      'hash' => 'e9af8b31de9fb72ba9545b0764ca8bd5',
    ),
  );
  $terms[] = array(
    'name' => 'Student',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'd0952a96-8ae9-fd54-b5de-8c21f820e78f',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_occupation_category',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
    ),
  );
  $terms[] = array(
    'name' => 'Clinical',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'eb17680d-8a15-e4e4-6d62-1fb723179b03',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_occupation_category',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
    ),
  );
  return $terms;
}
