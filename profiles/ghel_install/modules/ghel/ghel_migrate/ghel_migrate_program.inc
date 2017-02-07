<?php
/**
 * @file
 * Program node migration.
 */

/**
 * Program -> node migration.
 */
class GhelProgramMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('GHEL legacy Program import');
    // The example uses a SQL database as source.
    // @@@ The db name is hardcoded to bdragon's env atm.
    $query = db_select('funnymonkey_import.program', 'p')
      ->fields('p', array(
        'programid',
        'name',
        'description',
        'updatedate',
        'published',
        'private',
        'publisheddate',
        'import_courses',
      ))
      ->condition('deleted', 0);
    $this->source = new MigrateSourceSQL($query);
    // Migrate into users.
    $this->destination = new MigrateDestinationNode('ghel_program');

    // We instantiate the MigrateMap.
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'programid' => array(
            'type' => 'int',
            'unsigned' => TRUE,
            'not null' => TRUE,
          ),
        ),
        MigrateDestinationNode::getKeySchema()
      );

    // Finally we add simple field mappings.
    // 'Username' is unused.
    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('body', 'description');
    $this->addFieldMapping('status', 'published');
    $this->addFieldMapping('created', 'publisheddate');
    $this->addFieldMapping('changed', 'updatedate');
    $this->addFieldMapping('body:format')
      ->defaultValue('filtered_html');

    $this->addFieldMapping('field_ghel_courses', 'import_courses')
      ->separator(',')
      ->sourceMigration('GhelCourse');


    $this->addFieldMapping('promote')
      ->defaultValue(0);
    $this->addFieldMapping('sticky')
      ->defaultValue(0);
  }

  public function prepare(stdClass $node, stdClass $row) {


  }
}
