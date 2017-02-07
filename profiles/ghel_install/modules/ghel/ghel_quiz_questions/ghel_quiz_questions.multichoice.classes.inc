<?php

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
 * Extension of QuizQuestion.
 */
class TranslatableMultichoiceQuestion extends MultichoiceQuestion {

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
    $lang = $language->language;
    $base_node = node_load($this->node->nid);
    $translations = translation_node_get_translations($base_node->tnid);
    $translated_node = (isset($translations[$lang])?node_load($translations[$lang]->nid):$base_node);

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
