<?php
/**
 * @file
 * ghel_lang_taxo.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function ghel_lang_taxo_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Arabic',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '69dfca88-ea73-4633-b391-ffa5d4b6d439',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_trans_language',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
      'hash' => 'e9af8b31de9fb72ba9545b0764ca8bd5',
    ),
  );
  $terms[] = array(
    'name' => 'Portugese',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6c2d4d84-dbff-4fd6-bbfa-12b359855c3c',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_trans_language',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
      'hash' => 'e9af8b31de9fb72ba9545b0764ca8bd5',
    ),
  );
  $terms[] = array(
    'name' => 'French',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '7c221dbb-6630-4fe1-82cd-84f66b4096d3',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_trans_language',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
      'hash' => 'e9af8b31de9fb72ba9545b0764ca8bd5',
    ),
  );
  $terms[] = array(
    'name' => 'Spanish',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b91912d6-3a24-4ebb-b4a4-f873407e155e',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'ghel_trans_language',
    'epub_export_type' => 'taxonomy_term',
    'formblock_entity_type' => 'taxonomy_term',
    'lingotek' => array(
      'name' => 'DISABLED',
      'profile' => 'DISABLED',
      'hash' => 'e9af8b31de9fb72ba9545b0764ca8bd5',
    ),
  );
  return $terms;
}
