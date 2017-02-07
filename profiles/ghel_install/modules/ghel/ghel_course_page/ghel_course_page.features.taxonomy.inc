<?php
/**
 * @file
 * ghel_course_page.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ghel_course_page_taxonomy_default_vocabularies() {
  return array(
    'ghel_glossary' => array(
      'name' => 'Glossary',
      'machine_name' => 'ghel_glossary',
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
