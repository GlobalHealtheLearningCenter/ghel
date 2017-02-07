<?php
/**
 * @file
 * ghel_announcement.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ghel_announcement_taxonomy_default_vocabularies() {
  return array(
    'ghel_announcement_types' => array(
      'name' => 'Announcement Types',
      'machine_name' => 'ghel_announcement_types',
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
