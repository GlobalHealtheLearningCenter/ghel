<?php
/**
 * @file
 * Quiz migration.
 */

/**
 * "Check" quiz.
 */
class GhelCourseQuizCheckMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('GHEL legacy Quiz import -- Knowledge Check');
    $this->dependencies = array(
      'GhelCourseQuizMultiChoice',
      'GhelCourseQuizTrueFalse',
      'GhelCourseQuizMatching',
    );

    // The example uses a SQL database as source.
    // Limit to topics with questions assigned to the knowledge check.
    $query = db_select('funnymonkey_import.topic', 't')
      ->fields('t', array(
        'topicid',
        'name',
        'courseid',
        'icon',
        'timelength',
        'displayorder',
        'keypoints',
        'deleted',
      ))
      ->groupBy('t.topicid')
      ->condition('t.deleted', 0);
    $query->innerJoin('funnymonkey_import.question', 'q', 't.topicid = q.topicid');
    $query
      ->condition('q.knowledgecheck', 1);

    $this->source = new MigrateSourceSQL($query);
    // Migrate into quiz nodes.
    $this->destination = new MigrateDestinationNode('quiz');

    // We instantiate the MigrateMap.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'topicid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 'q',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Finally we add simple field mappings.
    $this->addFieldMapping('title', 'name');

    // @todo Is there anything to use in the quiz body?
    $this->addFieldMapping('body')
      ->defaultValue('');
    $this->addFieldMapping('body:format')
      ->defaultValue('filtered_html');
    // @todo Remap to deleted?
    $this->addFieldMapping('status')
      ->defaultValue(1);
    $this->addFieldMapping('pass_rate')
      ->defaultValue(85);

    $this->addFieldMapping('field_ghel_course', 'courseid')
      ->sourceMigration('GhelCourse');

    $this->addFieldMapping('promote')
      ->defaultValue(0);
    $this->addFieldMapping('sticky')
      ->defaultValue(0);
  }

  public function complete($entity, $row) {
    // Assemble the list of questions.
    $questions = db_query('SELECT questionid FROM funnymonkey_import.question WHERE knowledgeCheck = 1 AND topicid = :topicid ORDER BY checkDisplayOrder ASC', array(':topicid' => $row->topicid))->fetchCol();
    // The questions can be handled by any of the question types. Make migrate
    // do all the work for us.
    $question_nids = $this->handleSourceMigration(array(
      'GhelCourseQuizMultiChoice',
      'GhelCourseQuizTrueFalse',
      'GhelCourseQuizMatching',
    ), $questions, NULL, $this);
    $result = db_query('SELECT nid, vid FROM {node} WHERE nid IN (:nids)', array(':nids' => $question_nids));
    $questions = array();
    $weight = 0;
    foreach ($result as $qdata) {
      $weight++;
      $question = new stdClass();
      $question->nid = $qdata->nid;
      $question->vid = $qdata->vid;
      $question->state = QUESTION_ALWAYS;
      $question->weight = $weight;
      // @todo Check if this is always correct.
      $question->max_score = 1;
      $question->refresh = FALSE;
      $questions[] = $question;
    }
    $node = node_load($entity->nid, $entity->vid, TRUE);
    quiz_set_questions($node, $questions);
  }

  public function prepare(stdClass $node, stdClass $row) {
    $published = db_query('SELECT published FROM funnymonkey_import.course WHERE courseid = :course', array(':course' => $row->courseid))->fetchField();

    // Set the workflow.
    $node->workflow = $published ? _ghel_migrate_get_workflow_state('Course Page Status', 'Complete') : _ghel_migrate_get_workflow_state('Course Page Status', 'Revision');

    $node->title = t('!title Knowledge Check', array('!title' => $node->title));

  }
}

/**
 * "Recap" quiz.
 */
class GhelCourseQuizRecapMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('GHEL legacy Quiz import -- Knowledge Recap');
    $this->dependencies = array(
      'GhelCourseQuizMultiChoice',
      'GhelCourseQuizTrueFalse',
      'GhelCourseQuizMatching',
    );

    // The example uses a SQL database as source.
    // Limit to topics with questions assigned to the knowledge recap.
    $query = db_select('funnymonkey_import.topic', 't')
      ->fields('t', array(
        'topicid',
        'name',
        'courseid',
        'icon',
        'timelength',
        'displayorder',
        'keypoints',
        'deleted',
      ))
      ->groupBy('t.topicid')
      ->condition('t.deleted', 0);
    $query->innerJoin('funnymonkey_import.question', 'q', 't.topicid = q.topicid');
    $query
      ->condition('q.knowledgerecap', 1);
    $this->source = new MigrateSourceSQL($query);
    // Migrate into quiz nodes.
    $this->destination = new MigrateDestinationNode('quiz');

    // We instantiate the MigrateMap.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'topicid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 'q',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Finally we add simple field mappings.
    $this->addFieldMapping('title', 'name');
    // @todo Is there anything to use in the quiz body?
    $this->addFieldMapping('body')
      ->defaultValue('');
    $this->addFieldMapping('body:format')
      ->defaultValue('filtered_html');
    // @@@ Remap to deleted?
    $this->addFieldMapping('status')
      ->defaultValue(1);

    $this->addFieldMapping('field_ghel_course', 'courseid')
      ->sourceMigration('GhelCourse');

    $this->addFieldMapping('promote')
      ->defaultValue(0);
    $this->addFieldMapping('sticky')
      ->defaultValue(0);
  }

  public function complete($entity, $row) {
    // Assemble the list of questions.
    $questions = db_query('SELECT questionid FROM funnymonkey_import.question WHERE knowledgeRecap = 1 AND topicid = :topicid ORDER BY recapDisplayOrder ASC', array(':topicid' => $row->topicid))->fetchCol();
    // The questions can be handled by any of the question types. Make migrate
    // do all the work for us.
    $question_nids = $this->handleSourceMigration(array(
      'GhelCourseQuizMultiChoice',
      'GhelCourseQuizTrueFalse',
      'GhelCourseQuizMatching',
    ), $questions, NULL, $this);
    $result = db_query('SELECT nid, vid FROM {node} WHERE nid IN (:nids)', array(':nids' => $question_nids));
    $questions = array();
    $weight = 0;
    foreach ($result as $qdata) {
      $weight++;
      $question = new stdClass();
      $question->nid = $qdata->nid;
      $question->vid = $qdata->vid;
      $question->state = QUESTION_ALWAYS;
      $question->weight = $weight;

      // @todo Check if this is always correct.
      $question->max_score = 1;
      $question->refresh = FALSE;
      $questions[] = $question;
    }
    $node = node_load($entity->nid, $entity->vid, TRUE);
    quiz_set_questions($node, $questions);
  }

  public function prepare(stdClass $node, stdClass $row) {
    $published = db_query('SELECT published FROM funnymonkey_import.course WHERE courseid = :course', array(':course' => $row->courseid))->fetchField();

    // Set the workflow.
    $node->workflow = $published ? _ghel_migrate_get_workflow_state('Course Page Status', 'Complete') : _ghel_migrate_get_workflow_state('Course Page Status', 'Revision');

    $node->title = t('!title Knowledge Recap', array('!title' => $node->title));

  }
}

/**
 * Final exam.
 */
class GhelCourseQuizExamMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('GHEL legacy Quiz import -- Exam');
    $this->dependencies = array(
      'GhelCourseQuizMultiChoice',
      'GhelCourseQuizTrueFalse',
      'GhelCourseQuizMatching',
    );

    // The example uses a SQL database as source.
    // Limit to topics with questions assigned to the exam.
    $query = db_select('funnymonkey_import.topic', 't')
      ->fields('t', array(
        'topicid',
        'name',
        'courseid',
        'icon',
        'timelength',
        'displayorder',
        'keypoints',
        'deleted',
      ))
      ->condition('t.deleted', 0);
    $query->innerJoin('funnymonkey_import.question', 'q', 't.topicid = q.topicid');
    $query
      ->condition('q.exam', 1);
    $this->source = new MigrateSourceSQL($query);
    // Migrate into quiz nodes.
    $this->destination = new MigrateDestinationNode('quiz');

    // We instantiate the MigrateMap.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'courseid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 't',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Finally we add simple field mappings.
    $this->addFieldMapping('title')
      ->defaultValue(t('Final Exam'));

    // @todo Is there anything to use in the quiz body?
    $this->addFieldMapping('body')
      ->defaultValue('');
    $this->addFieldMapping('body:format')
      ->defaultValue('filtered_html');

    // @@@ Remap to deleted?
    $this->addFieldMapping('status')
      ->defaultValue(1);

    $this->addFieldMapping('field_ghel_course', 'courseid')
      ->sourceMigration('GhelCourse');

    $this->addFieldMapping('promote')
      ->defaultValue(0);
    $this->addFieldMapping('sticky')
      ->defaultValue(0);
  }

  public function complete($entity, $row) {
    // Assemble the list of questions.
    $questions = db_query('SELECT q.questionid FROM funnymonkey_import.question q LEFT JOIN funnymonkey_import.topic t ON t.topicid = q.topicid WHERE exam = 1 AND t.courseid = :course AND t.deleted = 0 AND q.deleted = 0 ORDER BY q.examDisplayOrder ASC', array(':course' => $row->courseid))->fetchCol();
    // The questions can be handled by any of the question types. Make migrate
    // do all the work for us.
    $question_nids = $this->handleSourceMigration(array(
      'GhelCourseQuizMultiChoice',
      'GhelCourseQuizTrueFalse',
      'GhelCourseQuizMatching',
    ), $questions, NULL, $this);
    $result = db_query('SELECT nid, vid FROM {node} WHERE nid IN (:nids)', array(':nids' => $question_nids));
    $questions = array();
    $weight = 0;
    foreach ($result as $qdata) {
      $weight++;
      $question = new stdClass();
      $question->nid = $qdata->nid;
      $question->vid = $qdata->vid;
      $question->state = QUESTION_ALWAYS;
      $question->weight = $weight;

      // @todo Check if this is always correct.
      $question->max_score = 1;
      $question->refresh = FALSE;
      $questions[] = $question;
    }
    $node = node_load($entity->nid, $entity->vid, TRUE);
    quiz_set_questions($node, $questions);
  }

  public function prepare(stdClass $node, stdClass $row) {
    $published = db_query('SELECT published FROM funnymonkey_import.course WHERE courseid = :course', array(':course' => $row->courseid))->fetchField();

    // Set the workflow.
    $node->workflow = $published ? _ghel_migrate_get_workflow_state('Course Page Status', 'Complete') : _ghel_migrate_get_workflow_state('Course Page Status', 'Revision');
  }
}
