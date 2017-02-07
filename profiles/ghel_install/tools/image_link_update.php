<?php
  /**
   * @file Update script for image cache changes related to drupal 7.20
   *
   * You will likely need to adjust the regexp and the $search and $replace
   * variables in cleanup(). Note that image_style_path_token generates
   * different tokens for different paths so you need to properly detect your
   * site URLs and rewrite them in the most robust pattern for your site.
   *
   * The existing patterns work with patterns like the following;
   * /?q=sites/default/files/styles/large_left/public/page-images/FILENAME.png
   * Rewritten to the following;
   * /sites/default/files/styles/large_left/public/page-images/FILENAME.png?itok=TOKEN
   *
   * Thanks to István Palócz https://drupal.org/user/59215 for sharing Old Image
   * link corrector.
   *
   * @see https://drupal.org/sandbox/pp/1924318
   *
   * Run with:
   *   drush php-script image_link_update.php
   */


  // Array of tables to search and replace keyed by the table name with an array
  // of fields.
  $tables = array(
    'field_data_body' => array('body_value'),
    'field_revision_body' => array('body_value'),
  );

  foreach ($tables as $table => $fields) {
    foreach ($fields as $field) {
      $sql = 'SELECT nrb.* FROM {' . $table . '} nrb ORDER BY entity_type, bundle, entity_id, revision_id, language, delta';
      $result = db_query($sql);
      foreach ($result as $record) {
        cleanup($table, $field, $record);
      }
    }
  }



function cleanup($table, $field, $record) {
  $regexp = '#"/\?q=(?P<full_link>[a-zA-Z0-9/_.:-]*/styles/(?P<style_name>[a-zA-z0-9_-]+)/(?P<scheme>[a-zA-z0-9_-]+)/(?P<path>\\S+\\.(png|jpg|jpeg|gif)))(?!\\?)"#';
  $matches = array();

  if (preg_match_all($regexp, $record->$field, $matches, PREG_SET_ORDER)) {
    print 'Updating: [' . $table . ']' . implode(':', array(
      $record->entity_type,
      $record->bundle,
      $record->entity_id,
      $record->revision_id,
      $record->language,
      $record->delta
    )) . "\n";

    foreach ($matches as $image_link) {
      $token = image_style_path_token($image_link['style_name'], $image_link['scheme'] . '://' . $image_link['path']);
      $search = '/?q=' . $image_link['full_link'];
      $replace = '/' . $image_link['full_link'] . '?' . IMAGE_DERIVATIVE_TOKEN . '=' . $token;
      $record->$field = str_replace($search, $replace, $record->$field);
      print "  Search: $search\n";
      print "  Replace: $replace\n";
    }

    $update = db_update($table)
      ->fields(array(
        $field => $record->$field,
      ))
      ->condition('entity_type', $record->entity_type)
      ->condition('bundle', $record->bundle)
      ->condition('entity_id', $record->entity_id)
      ->condition('revision_id', $record->revision_id)
      ->condition('language', $record->language)
      ->condition('delta', $record->delta)
      ->execute();
    if ($update == 1) {
      print "  Successfully updated\n";
    }
    else {
      print "  ***Fail expected 1 row affected but received ($update)\n";
    }

  }
}
