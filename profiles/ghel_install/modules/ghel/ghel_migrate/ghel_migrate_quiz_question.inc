<?php
/**
 * @file
 * Quiz migration for questions.
 */

/**
 * Quiz multiple choice question migration.
 */
class GhelCourseQuizMultiChoiceMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('GHEL legacy Quiz import: Multiple Choice questions');

    // The example uses a SQL database as source.
    // @@@ The db name is hardcoded to bdragon's env atm.
    $query = db_select('funnymonkey_import.question', 'q')
      ->fields('q', array(
        'questionid',
        'question',
        'questiontypeid',
        'createdate',
        'updatedate',
        'topicid',
        'displayorder',
        'knowledgecheck',
        'knowledgerecap',
        'exam',
        'checkdisplayorder',
        'recapdisplayorder',
        'examdisplayorder',
        'displayselect',
        'eval',
        'evaldisplayorder',
        'explanation',
        'pageid',
        'deleted',
      ));

    // Mulitple choice: questiontypeid = 1.
    $query->innerJoin('funnymonkey_import.topic', 't', 'q.topicid = t.topicid');
    $query->fields('t', array('courseid', 'name'));
    $query
      ->condition('q.deleted', 0)
      ->condition('t.deleted', 0)
      ->condition('q.questiontypeid', 1);

    $this->source = new MigrateSourceSQL($query);
    // Migrate into users.
    $this->destination = new MigrateDestinationNode('multichoice');

    // We instantiate the MigrateMap.
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'questionid' => array(
            'type' => 'int',
            'unsigned' => TRUE,
            'not null' => TRUE,
            'alias' => 'q',
          ),
        ),
        MigrateDestinationNode::getKeySchema()
      );

    // Finally we add simple field mappings.
    // For lack of a better title, use the topic title.
    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('body', 'question');
    $this->addFieldMapping('body:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('status')
      ->defaultValue(1);

    $this->addFieldMapping('created', 'createdate');

    $this->addFieldMapping('field_ghel_course', 'courseid')
      ->sourceMigration('GhelCourse');

    // q.updateDate is always NULL...
    $this->addFieldMapping('changed', 'createdate');

    $this->addFieldMapping('promote')
      ->defaultValue(0);
    $this->addFieldMapping('sticky')
      ->defaultValue(0);
  }

  public function prepare(stdClass $node, stdClass $row) {
    // @todo Use $row->explanation as feedback fill!
    $result = db_query('SELECT response, responseexplanation, correctanswer, responsequestion FROM funnymonkey_import.questionResponse WHERE questionID = :id ORDER BY displayOrder ASC', array(':id' => $row->questionid));
    $correctcount = 0;
    foreach ($result as $answer) {
      if (!empty($answer->correctanswer)) {
        $correctcount++;
      }
      $node->alternatives[] = array(
        'correct' => !empty($answer->correctanswer) ? 1 : FALSE,
        'answer' => array(
          'value' => $answer->response,
          'format' => 'filtered_html',
        ),
        'feedback_if_chosen' => array(
          'value' => $answer->responseexplanation,
          'format' => 'filtered_html',
        ),
        'feedback_if_not_chosen' => array(
          'value' => '',
          'format' => 'filtered_html',
        ),
        // @todo Figure out exactly what logic we should use for scoring on
        // imports. Currently using "simple scoring" so both should be zero.
        // (I think.)
        'score_if_chosen' => 0,
        'score_if_not_chosen' => 0,
      );
    }
    // @todo Check against original behavior -- Is there a column that tells us
    // whether to use radios or checkboxes?
    $node->choice_multi = ($correctcount == 1) ? 0 : 1;
    $node->choice_random = 0;

    // Simple scoring.
    $node->choice_boolean = 1;

    // Prevent warnings.
    $node->add_directly = array(
      'new' => '',
    );
  }
}

/**
 * Quiz True/False question migration.
 */
class GhelCourseQuizTrueFalseMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('GHEL legacy Quiz import: True/False questions');

    // The example uses a SQL database as source.
    // questionTypeid = 2: True/False.
    $query = db_select('funnymonkey_import.question', 'q')
      ->fields('q', array(
        'questionid',
        'question',
        'questiontypeid',
        'createdate',
        'updatedate',
        'topicid',
        'displayorder',
        'knowledgecheck',
        'knowledgerecap',
        'exam',
        'checkdisplayorder',
        'recapdisplayorder',
        'examdisplayorder',
        'displayselect',
        'eval',
        'evaldisplayorder',
        'explanation',
        'pageid',
        'deleted',
      ));
    $query->innerJoin('funnymonkey_import.topic', 't', 'q.topicid = t.topicid');
    $query->fields('t', array('courseid', 'name'));
    $query
      ->condition('q.deleted', 0)
      ->condition('t.deleted', 0)
      ->condition('q.questiontypeid', 2);

    $this->source = new MigrateSourceSQL($query);
    // Migrate into users.
    $this->destination = new MigrateDestinationNode('truefalse');

    // We instantiate the MigrateMap.
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'questionid' => array(
            'type' => 'int',
            'unsigned' => TRUE,
            'not null' => TRUE,
            'alias' => 'q',
          ),
        ),
        MigrateDestinationNode::getKeySchema()
      );

    // Finally we add simple field mappings
    // For lack of a better title, use the topic title.
    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('body', 'question');
    $this->addFieldMapping('body:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('status')
      ->defaultValue(1);

    $this->addFieldMapping('created', 'createdate');

    $this->addFieldMapping('field_ghel_course', 'courseid')
      ->sourceMigration('GhelCourse');

    // q.updateDate is always NULL...
    $this->addFieldMapping('changed', 'createdate');

    $this->addFieldMapping('promote')
      ->defaultValue(0);
    $this->addFieldMapping('sticky')
      ->defaultValue(0);
  }

  public function prepare(stdClass $node, stdClass $row) {
    $istrue = db_query('SELECT correctanswer FROM funnymonkey_import.questionResponse WHERE questionID = :id AND response = :value', array(':id' => $row->questionid, ':value' => 'True'))->fetchField();
    $node->correct_answer = ($istrue) ? 1 : 0;

    // @todo Why does this appear to be forced plain-text? quiz.module bug?
    $node->feedback = $row->explanation;

    // Prevent warnings.
    $node->add_directly = array(
      'new' => '',
    );
  }
}

/**
 * Quiz matching question migration.
 */
class GhelCourseQuizMatchingMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('GHEL legacy Quiz import: Matching questions');

    // The example uses a SQL database as source.
    // questiontypeid = 3 Matching.
    $query = db_select('funnymonkey_import.question', 'q')
      ->fields('q', array(
        'questionid',
        'question',
        'questiontypeid',
        'createdate',
        'updatedate',
        'topicid',
        'displayorder',
        'knowledgecheck',
        'knowledgerecap',
        'exam',
        'checkdisplayorder',
        'recapdisplayorder',
        'examdisplayorder',
        'displayselect',
        'eval',
        'evaldisplayorder',
        'explanation',
        'pageid',
        'deleted',
      ));
    $query->innerJoin('funnymonkey_import.topic', 't', 'q.topicid = t.topicid');
    $query->fields('t', array('courseid', 'name'));
    $query
      ->condition('q.deleted', 0)
      ->condition('t.deleted', 0)
      ->condition('q.questiontypeid', 3);

    $this->source = new MigrateSourceSQL($query);
    // Migrate into users.
    $this->destination = new MigrateDestinationNode('matching');

    // We instantiate the MigrateMap.
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'questionid' => array(
            'type' => 'int',
            'unsigned' => TRUE,
            'not null' => TRUE,
            'alias' => 'q',
          ),
        ),
        MigrateDestinationNode::getKeySchema()
      );

    // Finally we add simple field mappings
    // For lack of a better title, use the topic title.
    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('body', 'question');
    $this->addFieldMapping('body:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('status')
      ->defaultValue(1);

    $this->addFieldMapping('created', 'createdate');
    // q.updateDate is always NULL...
    $this->addFieldMapping('changed', 'createdate');

    $this->addFieldMapping('field_ghel_course', 'courseid')
      ->sourceMigration('GhelCourse');

    $this->addFieldMapping('promote')
      ->defaultValue(0);
    $this->addFieldMapping('sticky')
      ->defaultValue(0);
  }

  public function prepare(stdClass $node, stdClass $row) {
    // @todo Use $row->explanation as feedback fill!
    $result = db_query('SELECT response, responseexplanation, correctanswer, responsequestion FROM funnymonkey_import.questionResponse WHERE questionID = :id ORDER BY displayOrder ASC', array(':id' => $row->questionid));
    $offset = 0;
    foreach ($result as $answer) {
      // Counting in form starts from 1 for some odd reason.
      $offset++;
      $node->match[$offset] = array(
        'question' => $answer->responsequestion,
        'answer' => $answer->response,
        // @todo Double check behavior regarding when this shows up vs. the old
        // site.
        'feedback' => !empty($answer->responseexplanation) ? $answer->responseexplanation : '',
      );
    }

    // @todo Check against original behavior -- Is there a column that tells us
    // whether to use radios or checkboxes?
    $node->choice_multi = 1;
    $node->choice_random = 0;

    // Simple scoring.
    $node->choice_boolean = 1;
    // Prevent warnings.
    $node->add_directly = array(
      'new' => '',
    );
  }
}
