<?php

define('GHEL_LEARNER_TOGGLE_YES' , 1);
define('GHEL_LEARNER_TOGGLE_NO', 2);  // can't be zero

/**
 * Expose organic groups group nodes as a context condition.
 */
class ghel_learner_toggle_condition_learner extends context_condition {
  function condition_values() {
    return array();
  }

  function condition_form($context) {
    $form = parent::editor_form($context);
    $defaults = $this->fetch_from_context($context, 'values');

    $form['#type'] = 'select';
    $form['#default_value'] = !empty($defaults) ? $defaults : GHEL_LEARNER_TOGGLE_YES;
    $form['#description'] = t('Select "Is Learner" if this context should be active when the user has the learner role, or if the user has enabled "learner mode"');
    $form['#options'] = array(
      GHEL_LEARNER_TOGGLE_YES => t('Is Learner'),
      GHEL_LEARNER_TOGGLE_NO => t('Is Not Learner')
    );


    return $form;
  }

  function condition_form_submit($values) {
    return array($values => $values);
  }

  function execute($account) {
    $learner = FALSE;

    // see if the user has the learner role
    if (in_array('learner', $account->roles)) {
      $learner = TRUE;
    }
    else {
      // now check to see if they have turned on "learner mode"

      // make sure we have a fully loaded user object
      if (!isset($account->field_ghel_learner_toggle)) {
        $account = user_load($account->uid);
      }

      $learnermode = field_get_items('user', $account, 'field_ghel_learner_toggle');
      if (!empty($learnermode[0]['value'])) {
        $learner = TRUE;
      }
    }

    // Alternatively if the user cannot edit the current node (if any) and it is a course node
    $node = menu_get_object('node');
    $types = ghel_course_get_course_content_types(TRUE);
    if (!empty($node) && in_array($node->type, $types)) {
      if (!node_access('update', $node, $account)) {
        if (!$learner) {
          // If learner mode is not already active output a message indicating why
          // the user is seeing learner mode.
          drupal_set_message('Learner mode is activated for this page since you are unable to edit this page.');
        }
        $learner = TRUE;
      }

    }

    foreach ($this->get_contexts() as $context) {
      $tmp = $this->fetch_from_context($context, 'values');
      $toggle = reset($tmp);
      if (($learner && $toggle == GHEL_LEARNER_TOGGLE_YES) || (!$learner && $toggle == GHEL_LEARNER_TOGGLE_NO)) {
        $this->condition_met($context, $toggle);
      }
    }
  }
}
