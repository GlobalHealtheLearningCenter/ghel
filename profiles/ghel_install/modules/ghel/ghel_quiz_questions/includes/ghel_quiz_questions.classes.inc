<?php

/**
 * Defines the classes necessary for a True/False quiz.
 *
 * @file
 */


/**
 * The main classes for the multichoice question type.
 *
 * These inherit or implement code found in multichoice.classes.inc, which
 * inherit from quiz_question.classes.inc.
 *
 * Project: Refactor Quiz
 * Vendor: Lingotek
 *
 * Based on: patch by Lingotek
 * 
 * Modified this function to enable multilingual Body to be
 * displayed from content translated node
 *
 *
 * @file
 * Question type, enabling the creation of multiple choice and multiple answer questions.
 */



/**
 * A base implementation of a quiz_question, adding a layer of abstraction between the
 * node API, quiz API and the question types.
 *
 * It is required that Question types extend this abstract class.
 *
 * This class has default behaviour that all question types must have. It also handles the node API, but
 * gives the question types oppurtunity to save, delete and provide data specific to the question types.
 *
 * This abstract class also declares several abstract functions forcing question-types to implement required
 * methods.
 */
abstract class TranslatedQuizQuestion extends QuizQuestion {

  /**
   * Get the form through which the user will answer the question.
   *
   * @param $form_state
   *  The FAPI form_state array
   * @param $rid
   *  The result id.
   * @return
   *  Must return a FAPI array. At the moment all form elements that takes
   *  user response must have a key named "tries". (This is a Quiz 3.x legacy AFAIK. I'm
   *  not thrilled about it...)
   * 
   *    6/5/2015
   * Project: Refactor Quiz
   * Vendor: Lingotek
   * Description:
   * Modified this function to enable multilingual Body to be displayed from 
   * Content Translated Node
   * 
   */
  public function getAnsweringForm(array $form_state = NULL, $rid) {
    global $language;
watchdog('ghel_quiz', 'inside getAnsweringForm1');
    $lang = $language->language;
    $base_node = node_load($this->node->nid);
    $translations = translation_node_get_translations($base_node->tnid);
    $translated_node = (isset($translations[$lang])?node_load($translations[$lang]->nid):$base_node);
watchdog('ghel_quiz', 'inside ghel_quiz quiz question class');
drupal_set_message('inside ghel_quiz quiz question class');

    //echo $this->node->type;exit;
    $form = parent::getAnsweringForm($form_state, $rid);
    $body = field_get_items('node', $translated_node, 'body');
    $form['question']['#markup'] = check_markup($body[0]['value'], $body[0]['format'],$langcode=$lang);
    return $form;
  }

  // Must declare previously abstracted methods
  /**
   * Get the form used to create a new question.
   *
   * @param
   *  FAPI form state
   * @return
   *  Must return a FAPI array.
   */
///  public function getCreationForm(array &$form_state = NULL);

  /**
   * Get the maximum possible score for this question.
   */
///  public function getMaximumScore();

  /**
   * Save question type specific node properties
   */
///  public function saveNodeProperties($is_new = FALSE);

  /**
   * Provides validation for question before it is created.
   *
   * When a new question is created and initially submited, this is
   * called to validate that the settings are acceptible.
   *
   * @param $form
   *  The processed form.
   */
///  public function validateNode(array &$form);

}



/**
 * Each question type must store its own response data and be able to calculate a score for
 * that data.
 */
abstract class TranslatedQuizQuesionResponse extends QuizQuestionResponse {
  /**
   * get the question part of the reportForm
   *
   * @param $showpoints
   * @param $showfeedback
   * @return
   *  FAPI form array holding the question
   * 
   *     6/5/2015
   * Project: Refactor Quiz
   * Vendor: Lingotek
   * Description:
   * Modified this function to enable multilingual Body to be displayed from 
   * Content Translated Node
   * 
   */
  public function getReportFormQuestion($showpoints = TRUE, $showfeedback = TRUE) {
        global $language;
    $lang = $language->language;
    $base_node = node_load($this->question->nid);
    $translations = translation_node_get_translations($base_node->tnid);
    $translated_node = (isset($translations[$lang])?node_load($translations[$lang]->nid):$base_node);

    $node = node_load($translated_node->nid);
    $items = field_get_items('node', $node, 'body');
    return field_view_value('node', $node, 'body', $items[0]);
  }
}


/**
 * Extension of QuizQuestion.
 */
class TranslatedMultichoiceQuestion extends MultichoiceQuestion {

  /**
   * Generates the question form.
   *
   * This is called whenever a question is rendered, either
   * to an administrator or to a quiz taker.
   * 
   *     6/5/2015
   * Project: Refactor Quiz
   * Vendor: Lingotek
   * Description:
   * Modified this function to enable multilingual Body to be displayed from 
   * Content Translated Node
   * 
   */
  public function getAnsweringForm(array $form_state = NULL, $rid) {
        global $language;
watchdog('ghel_quiz', 'inside ghel_quiz multichoice class1');
    $lang = $language->language;
    $base_node = node_load($this->node->nid);
    $translations = translation_node_get_translations($base_node->tnid);
    $translated_node = (isset($translations[$lang])?node_load($translations[$lang]->nid):$base_node);

watchdog('ghel_quiz', 'inside ghel_quiz multichoice class');
drupal_set_message('inside ghel_quiz multichoice class');
    $form = parent::getAnsweringForm($form_state, $rid);

    for ($i = 0; isset($translated_node->alternatives[$i]); $i++) {
      $display = $translated_node->alternatives[$i];
      $short = $this->node->alternatives[$i];

      $answer_markup = check_markup($display['answer'], $display['answer_format'],$langcode=$lang);
      if (drupal_strlen($answer_markup) > 0) {
        $form['tries[answer]']['#options'][$short['id']] = $answer_markup;
      }
    }
    return $form;
  }


  /**
   * Implementation of getReportFormResponse
   *
   * @see getReportFormResponse($showpoints, $showfeedback, $allow_scoring)
   * 
   *    6/5/2015
   * Project: Refactor Quiz
   * Vendor: Lingotek
   * Description:
   * Modified this function to enable multilingual Body to be displayed from 
   * Content Translated Node
   * 
   */
  public function getReportFormResponse($showpoints = TRUE, $showfeedback = TRUE, $allow_scoring = FALSE) {
        global $language;
    $lang = $language->language;
    $base_node = node_load($this->question->nid);
    $translations = translation_node_get_translations($base_node->tnid);
    $translated_node = (isset($translations[$lang])?node_load($translations[$lang]->nid):$base_node);

    $i = 0;
    $this->orderAlternatives($this->question->alternatives);

    // Find the alternative with the highest score
    if ($translated_node->choice_multi == 0) {
      $max_score_if_chosen = -999;
      while (isset($this->question->alternatives[$i]) && is_array($this->question->alternatives[$i])) {
        $short = $this->question->alternatives[$i];
        if ($short['score_if_chosen'] > $max_score_if_chosen) {
          $max_score_if_chosen = $short['score_if_chosen'];
        }
        $i++;
      }
      $i = 0;
    }
    // Fetch all data for the report
    $data = array();
    while (isset($this->question->alternatives[$i])) {
      $display = $translated_node->alternatives[$i];
      $short = $this->question->alternatives[$i];
      if (drupal_strlen($this->checkMarkup($display['answer'], $display['answer_format'], $langcode=$lang)) > 0) {
        $alternative = array();

        // Did the user choose the alternative?
        $alternative['is_chosen'] = in_array($short['id'], $this->user_answer_ids);

        // Questions where multiple answers isn't allowed are scored differently...
        if ($this->question->choice_multi == 0) {

          if ($this->question->choice_boolean == 0) {
            if ($short['score_if_chosen'] > $short['score_if_not_chosen']) {
              $alternative['is_correct'] = $short['score_if_chosen'] < $max_score_if_chosen ? 1 : 2;
            }
            else {
              $alternative['is_correct'] = 0;
            }
          }

          else {
            $alternative['is_correct'] = $short['score_if_chosen'] > $short['score_if_not_chosen'] ? 2 : 0;
          }
        }

        // Questions where multiple answers are allowed
          else {
          $alternative['is_correct'] = $short['score_if_chosen'] > $short['score_if_not_chosen'] ? 2 : 0;
        }

        $alternative['answer'] = $this->checkMarkup($display['answer'], $display['answer_format'], FALSE);

        $not = $alternative['is_chosen'] ? '' : '_not';
        $alternative['feedback'] = $this->checkMarkup($display['feedback_if' . $not . '_chosen'], $display['feedback_if' . $not . '_chosen_format'],$langcode=$lang, FALSE);
        $data[] = $alternative;
      }
      $i++;
    }
    // Return themed report
    return array('#markup' => theme('multichoice_response', array('data' => $data)));
  }
}


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

}
