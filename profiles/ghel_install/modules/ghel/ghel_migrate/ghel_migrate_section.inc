<?php
/**
 * @file
 * Course section node migration.
 */

/**
 * Section(topic) -> node migration.
 */
class GhelCourseSectionMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('GHEL legacy Course import');

    // The example uses a SQL database as source.
    // @@@ The db name is hardcoded to bdragon's env atm.
    $query = db_select('funnymonkey_import.topic', 't')
      ->fields('t', array(
        'topicid',
        'name',
        'courseid',
        'icon',
        'timelength',
        'displayorder',
        'keypoints',
      ))
      ->condition('deleted', 0);
    $this->source = new MigrateSourceSQL($query);
    // Migrate into users.
    $this->destination = new MigrateDestinationNode('ghel_course_section');

    // We instantiate the MigrateMap.
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'topicid' => array(
            'type' => 'int',
            'unsigned' => TRUE,
            'not null' => TRUE,
          ),
        ),
        MigrateDestinationNode::getKeySchema()
      );

    // Finally we add simple field mappings.
    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('body', 'keypoints');
    $this->addFieldMapping('body:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('status')
      ->defaultValue(1);

    $this->addFieldMapping('field_ghel_course', 'courseid')
      ->sourceMigration('GhelCourse');
    $this->addFieldMapping('field_image', 'imagefile');
    $this->addFieldMapping('field_image:source_dir')
      ->defaultValue(GHELBINARYDIR);
    $this->addFieldMapping('field_image:alt', 'imagealttext');
    $this->addFieldMapping('field_image:title', 'imagecaption');
    $this->addFieldMapping('promote')
      ->defaultValue(0);
    $this->addFieldMapping('sticky')
      ->defaultValue(0);
  }

  public function prepare(stdClass $node, stdClass $row) {
    $published = db_query('SELECT published FROM funnymonkey_import.course WHERE courseid = :course', array(':course' => $row->courseid))->fetchField();

    // Set the workflow.
    $node->workflow = $published ? _ghel_migrate_get_workflow_state('Course Page Status', 'Complete') : _ghel_migrate_get_workflow_state('Course Page Status', 'Revision');
  }
}
