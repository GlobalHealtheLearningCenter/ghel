<?php
/**
 * @file
 * ghel_user_configuration.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ghel_user_configuration_taxonomy_default_vocabularies() {
  return array(
    'ghel_occupation_category' => array(
      'name' => 'Profile - Occupation Category',
      'machine_name' => 'ghel_occupation_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'epub_export_type' => 'taxonomy_vocabulary',
      'formblock_entity_type' => 'taxonomy_vocabulary',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
      'lingotek' => array(
        'name' => 'DISABLED',
        'profile' => 'DISABLED',
      ),
    ),
  );
}
