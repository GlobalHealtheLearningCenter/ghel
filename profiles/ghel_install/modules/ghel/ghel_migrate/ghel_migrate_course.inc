<?php
/**
 * @file
 * Course node migration.
 */

/**
 * Course -> node migration.
 */
class GhelCourseMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('GHEL legacy Course import');
    $this->dependencies = array(
      'GhelUser',
      'GhelProgram',
      'GhelCourseSection',
      'GhelCoursePage',
      'GhelCourseQuizCheck',
      'GhelCourseQuizRecap',
    );

    // The example uses a SQL database as source.
    // @@@ The db name is hardcoded to bdragon's env atm.
    $query = db_select('funnymonkey_import.course', 'c')
      ->fields('c', array(
        'courseid',
        'name',
        'abbreviation',
        'controllerid',
        'passpercentage',
        'createdate',
        'updatedate',
        'nbrofpages',
        'styleid',
        'summary',
        'purpose',
        'objective',
        'udtitle',
        'udtext',
        'timelength',
        'displayorder',
        'published',
        'private',
        'othertitle',
        'othertext',
        'publisheddate',
        'reference',
        'examintro',
        'exampassmark',
        'coursecredit',
        'lastupdatedate',
        'deleted',
        'coursemanager',
        'displaycoursemanager',
        'courseauthor',
        'displaycourseauthor',
        'accesslevelid',
        'membercategoryid',
      ))
      ->condition('deleted', 0);
    $query->addExpression("IF(hex(c.imageFile) = '00', '', c.imageFile)", 'imagefile');

    $this->source = new MigrateSourceSQL($query);
    // Migrate into users.
    $this->destination = new MigrateDestinationNode('ghel_course');

    // We instantiate the MigrateMap.
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'courseid' => array(
            'type' => 'int',
            'unsigned' => TRUE,
            'not null' => TRUE,
            'alias' => 'c',
          ),
        ),
        MigrateDestinationNode::getKeySchema()
      );

    // Finally we add simple field mappings
    // 'Username' is unused.
    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('body', 'purpose')
      ->callbacks('_ghel_migrate_fix_taxonomy_links');
    $this->addFieldMapping('status', 'published');
    $this->addFieldMapping('created', 'createdate');
    // @@@ what is publisheddate used for?
    $this->addFieldMapping('changed', 'updatedate');
    $this->addFieldMapping('body:format')
      ->defaultValue('filtered_html');

    $this->addFieldMapping('field_ghel_objective', 'objective');
    $this->addFieldMapping('field_ghel_objective:format')
      ->defaultValue('filtered_html');

    $this->addFieldMapping('uid', 'controllerid')
      ->sourceMigration('GhelUser');

    $this->addFieldMapping('field_image', 'imagefile');
    $this->addFieldMapping('field_image:source_dir')
      ->defaultValue(GHELBINARYDIR . 'courseheaders/');
    $this->addFieldMapping('field_image:alt', 'imagealttext');
    $this->addFieldMapping('field_image:title', 'imagecaption');
    $this->addFieldMapping('promote')
      ->defaultValue(0);
    $this->addFieldMapping('sticky')
      ->defaultValue(0);

    $this->addFieldMapping('field_ghel_credits', 'coursecredit');
    $this->addFieldMapping('field_ghel_credits:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('field_ghel_course_authors', 'courseauthor');
    $this->addFieldMapping('field_ghel_course_managers', 'coursemanager');

    $this->addFieldMapping('field_ghel_epub')
      ->defaultValue(array('value' => 1, 'status' => 1, 'fid' => 0));
    // Unmigrated sources.
    $this->addUnmigratedSources(array(
      'nbrofpages',
      'udtitle',
      'udtext',
    ));


  }

  public function prepare(stdClass $node, stdClass $row) {
    // Set workflow.
    $node->workflow = $node->status ? _ghel_migrate_get_workflow_state('Course Status', 'Published') : _ghel_migrate_get_workflow_state('Course Status', 'Under Review');

    // Assemble the course navigation uber-field.

    // Find topics in course.
    $topics = db_query('SELECT topicid FROM funnymonkey_import.topic WHERE courseid = :courseid AND deleted = 0 ORDER BY displayorder ASC', array(':courseid' => $row->courseid));
    foreach ($topics as $topic) {
      // a) Add the topic to the navigation.
      $section = $this->handleSourceMigration('GhelCourseSection', $topic->topicid, FALSE, $this);
      if (!empty($section)) {
        $node->field_ghel_course_navigation[LANGUAGE_NONE][] = array(
          'target_id' => (int) $section,
        );
      }

      $quiz = $this->handleSourceMigration('GhelCourseQuizCheck', $topic->topicid, FALSE, $this);
      if (!empty($quiz)) {
        // b) Knowledge check comes next.
        $node->field_ghel_course_navigation[LANGUAGE_NONE][] = array(
          'target_id' => (int) $quiz,
        );
      }
      $pages = db_query('SELECT pageid FROM funnymonkey_import.page WHERE topicid = :topicid ORDER BY displayorder ASC', array(':topicid' => $topic->topicid))->fetchCol();
      if (!empty($pages)) {
        $pagenids = $this->handleSourceMigration('GhelCoursePage', $pages, NULL, $this);
      }
      if (!empty($pagenids)) {
        if (!is_array($pagenids)) {
          // Ensure single value is treated as an array.
          $pagenids = array($pagenids);
        }
        foreach ($pagenids as $page) {
          // c) All pages in display order.
          if (!empty($page)) {
            $node->field_ghel_course_navigation[LANGUAGE_NONE][] = array('target_id' => $page);
          }
        }
      }
      $quiz = $this->handleSourceMigration('GhelCourseQuizRecap', $topic->topicid, FALSE, $this);
      if (!empty($quiz)) {
        // d) Knowledge recap.
        $node->field_ghel_course_navigation[LANGUAGE_NONE][] = array(
          'target_id' => (int) $quiz,
        );
      }
    }

    // e) Final Exam
    $final = $this->handleSourceMigration('GhelCourseQuizExam', $row->courseid, FALSE, $this);
    if (!empty($final)) {
      $node->field_ghel_course_navigation[LANGUAGE_NONE][] = array(
        'target_id' => (int) $final,
      );
    }
  }

  protected function createStub($migration, $source_id) {
    $node = new stdClass();
    $node->title = 'Stub for ' . $source_id[0];
    $node->body = 'Stub body';
    $node->type = $this->destination->getBundle();
    $node->uid = 1;
    $node->status = 0;
    $node->field_ghel_epub[LANGUAGE_NONE][0] = array(
      'version' => 1,
      'status' => 1,
      'fid' => 0,
    );
    node_save($node);
    if (isset($node->nid)) {
      return array($node->nid);
    }
    else {
      return FALSE;
    }
  }
}
