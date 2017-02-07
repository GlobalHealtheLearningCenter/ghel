<?php
/**
 * @file
 * Glossary term migration.
 */

/**
 * Glossary -> taxonomy term migration.
 */
class GhelGlossaryMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('GHEL legacy Glossary import');

    // The example uses a SQL database as source.
    // @@@ The db name is hardcoded to bdragon's env atm.
    $query = db_select('funnymonkey_import.glossary', 'g')
      ->fields('g', array(
        'glossaryid',
        'termdefinition',
      ));
    $query->leftJoin('funnymonkey_import.glossaryPatch', 'p', 'g.glossaryid = p.glossaryid');
    // Inner join on courseGlossary to eliminate terms not linked to a course.
    $query->innerJoin('funnymonkey_import.courseGlossary', 'y', 'g.glossaryid = y.glossaryid');
    // Allow glossaryPatch to override term names.
    $query->addExpression('IFNULL(p.new_term, g.term)', 'term');
    $query->groupBy('g.glossaryid');

    $this->source = new MigrateSourceSQL($query);
    // Migrate into users.
    $this->destination = new MigrateDestinationTerm('ghel_glossary');

    // We instantiate the MigrateMap.
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'glossaryid' => array(
            'type' => 'int',
            'unsigned' => TRUE,
            'not null' => TRUE,
            'alias' => 'g',
          ),
        ),
        MigrateDestinationTerm::getKeySchema()
      );

    // Finally we add simple field mappings.
    $this->addFieldMapping('name', 'term')
      ->dedupe('taxonomy_term_data', 'name');
    $this->addFieldMapping('description', 'termdefinition');
    $this->addFieldMapping('format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('weight')
      ->defaultValue(0);

  }

  public function prepare(stdClass $node, stdClass $row) {
  }

}
