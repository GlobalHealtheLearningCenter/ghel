<?php
/**
 * @file
 * Achievements migration.
 *
 * @see achievements_unlocked()
 * @see http://drupal.org/node/1650596
 */

/**
 * Exam status -> Achievements migration.
 */
class GhelExamStatusMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('GHEL legacy exam status');
    $this->dependencies = array('GhelCourse', 'GhelUser');

    $query = db_select('funnymonkey_import.examStatus', 'e')
      ->fields('e', array('examstatusid', 'memberid', 'courseid', 'passdate'));
    $query->leftJoin('funnymonkey_import.member', 'm', 'e.memberid = m.memberid');
    $query->orderBy('passdate');

    $this->source = new MigrateSourceSQL($query);

    $this->destination = new MigrateDestinationTable('achievement_unlocks');

    // We instantiate the MigrateMap.
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'examstatusid' => array(
            'type' => 'int',
            'unsigned' => TRUE,
            'not null' => TRUE,
          ),
        ),
        MigrateDestinationTable::getKeySchema('achievement_unlocks')
      );

    $this->addFieldMapping('uid', 'memberid')
      ->sourceMigration('GhelUser');

    $this->addFieldMapping('achievement_id', 'courseid')
      ->sourceMigration('GhelCourse');

    $this->addFieldMapping('seen')
      ->defaultValue(1);

    // Will remap in prepare().
    $this->addFieldMapping('rank')
      ->defaultValue(1);

    // Add a defaulut mapping of now (we'll adjust properly in prepare()).
    $this->addFieldMapping('timestamp', 'passdate')
      ->defaultValue(date('U'));
  }

  public function prepare(stdClass $table, stdClass $row) {
    // Map to the appropriate achievement.
    $table->achievement_id = 'ghel-course-completion-' . $table->achievement_id;

    // Map the previous date time string to a unix timestamp.
    $date = new DateTime($row->passdate);
    $table->timestamp = date_format($date, 'U');

    $last_rank = db_select('achievement_unlocks', 'au')
      ->fields('au', array('rank'))
      ->condition('achievement_id', $table->achievement_id)
      ->orderBy('rank', 'DESC')
      ->range(0, 1)
      ->execute()->fetchField();
    $table->rank = $last_rank ? $last_rank + 1 : 1;
  }

  protected function postImport() {
    parent::postImport();

    // Set all the entries in achievement_totals.
    _ghel_migrate_set_achievement_totals();
  }

  protected function postRollback() {
    parent::postRollback();

    // Clear out all entries and re-calculate.
    _ghel_migrate_set_achievement_totals();

  }

}
