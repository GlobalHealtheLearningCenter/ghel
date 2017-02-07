<?php

/**
 * Defines the classes necessary for a True/False quiz.
 *
 * @file
 */


/**
 * Extension of QuizQuestionResponse
 */
class TranslatedTrueFalseResponse extends TrueFalseResponse {
  /**
   * Implementation of getReportFormResponse
   *
   * @see QuizQuestionResponse#getReportFormResponse($showpoints, $showfeedback, $allow_scoring)
   * 
   * 6/5/2015
   * Project: Refactor Quiz
   * Vendor: Lingotek
   * Description:
   * Modified this function to enable multilingual Body to be displayed from 
   * Content Translated Node
   */

  public function getReportFormResponse($showpoints = TRUE, $showfeedback = TRUE, $allow_scoring = FALSE) {
    global $language;
    $lang = $language->language;
    $base_node = node_load($this->question->nid);
    $translations = translation_node_get_translations($base_node->tnid);
    $translated_node = (isset($translations[$lang])?node_load($translations[$lang]->nid):$base_node);


watchdog('ghel_quiz', 'inside ghel_quiz true-false class');
drupal_set_message('inside ghel_quiz true-false class');
    if (empty($this->question->answers)) {
      return array(
        '#markup' => t('Missing question.'),
      );
    }
    $metadata = array();
    $data = array();
    // Build the question answers header (add blank space for IE).
    if ($showpoints) {
      $metadata[] = t('Correct Answer');
    }
    $metadata[] = t('User answer');
    if ($showfeedback && !empty($translated_node->feedback)) {
      $metadata[] = t('Feedback');
    }

    $answer = $this->question->answers[0];
    $correct_answer = $answer['is_correct'] ? $answer['answer'] : !$answer['answer'];
    $user_answer = $answer['answer'];

    if ($showpoints) {
      $data[0]['correct_answer'] = ($correct_answer ? t('True') : t('False'));
    }
    $data[0]['user_answer'] = (($user_answer === NULL) ? '' : ($user_answer ? t('True') : t('False')));

    if ($showfeedback && !empty($translated_node->feedback)) {
      $data[0]['feedback'] = check_markup($translated_node->feedback, $this->getFormat(),$langcode=$lang);
    }

    // Return themed output
    return array(
      '#markup' => theme('truefalse_response', array('metadata' => $metadata, 'data' => $data)),
    );
  }
                                                                                                                                                                 351,15        97%

}
