<?php
/**
 * @file
 * Page node migration.
 */

/**
 * Page -> node migration.
 */
class GhelCoursePageMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('GHEL legacy Page import');

    $this->dependencies = array('GhelGlossary');

    // The example uses a SQL database as source.
    // @@@ The db name is hardcoded to bdragon's env atm.
    $query = db_select('funnymonkey_import.page', 'p')
      ->fields('p', array(
        'pageid',
        'topicid',
        'name',
        'pagenavlabel',
        'content',
        'imagewidth',
        'imageheight',
        'imagealttext',
        'imagecaption',
        'element1type',
        'element2type',
        'pagetiptext',
        'displayorder',
        'createdate',
        'updatedate',
        'edituserid',
        'published',
        'publisheddate',
      ))
      ->condition('p.deleted', 0);
    $query->innerJoin('funnymonkey_import.topic', 't', 'p.topicid = t.topicid');
    $query->addField('t', 'courseid');
    // we need zero-padded courseID as course directory.
    $query->addExpression("IF(hex(p.imageFile) = '00', '', LPAD(t.courseID, 3, '0'))", 'coursedir');
    $query->addExpression("IF(hex(p.imageFile) = '00', '', p.imageFile)", 'imagefile');
    $query->condition('t.deleted', 0);

    // remap junk text to empty string
    $query->addExpression("IF(hex(p.element1text) = '00', '', p.element1text)", 'element1text');
    $query->addExpression("IF(hex(p.element2text) = '00', '', p.element2text)", 'element2text');
    $this->source = new MigrateSourceSQL($query);
    // Migrate into users.
    $this->destination = new MigrateDestinationNode('ghel_course_page');

    // We instantiate the MigrateMap.
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'pageid' => array(
            'type' => 'int',
            'unsigned' => TRUE,
            'not null' => TRUE,
          ),
        ),
        MigrateDestinationNode::getKeySchema()
      );

    // Finally we add simple field mappings.
    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('body', 'content')
      ->callbacks('_ghel_migrate_fix_taxonomy_links');
    $this->addFieldMapping('body:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('status', 'published');

    $this->addFieldMapping('field_ghel_course', 'courseid')
      ->sourceMigration('GhelCourse');

    $this->addFieldMapping('field_ghel_highlight_1_type_', 'element1type')
      ->callbacks(array($this, 'mapType'));
    $this->addFieldMapping('field_ghel_highlight_1_', 'element1text');
    $this->addFieldMapping('field_ghel_highlight_1_:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('field_ghel_highlight_2_type_', 'element2type')
      ->callbacks(array($this, 'mapType'));
    $this->addFieldMapping('field_ghel_highlight_2_', 'element2text');
    $this->addFieldMapping('field_ghel_highlight_2_:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('field_image', 'imagefile')
      ->callbacks(array($this, 'mapFile'));
    $this->addFieldMapping('field_image:source_dir', 'coursedir')
      ->callbacks(array($this, 'mapDir'));
    $this->addFieldMapping('field_image:alt', 'imagealttext');
    $this->addFieldMapping('field_image:title', 'imagecaption');
    $this->addFieldMapping('promote')
      ->defaultValue(0);
    $this->addFieldMapping('sticky')
      ->defaultValue(0);
  }

  protected function mapFile($value) {
    if (empty($value)) {
      return '';
    }
    else {
      return $value;
    }
  }

  protected function mapDir($value) {
    if (!empty($value) && $value != '000') {
      return(GHELBINARYDIR . '/' . $value);
    }
    else {
      return '';
    }
  }

  protected function mapType($value) {
    switch ($value) {
      case 1:
        return t('Highlights');
        break;

      case 2:
        return t('Did you know?');
        break;

      case 3:
        return t('You decide');
        break;

      case 4:
        return t('Ideas in action');
        break;

      default:
        return '';
        break;
    }
  }

  public function prepare(stdClass $node, stdClass $row) {
    $published = db_query('SELECT published FROM funnymonkey_import.course WHERE courseid = :course', array(':course' => $row->courseid))->fetchField();

    // Set the workflow.
    $node->workflow = $published ? _ghel_migrate_get_workflow_state('Course Page Status', 'Complete') : _ghel_migrate_get_workflow_state('Course Page Status', 'Revision');

  }
}
