<?php


/**
 * Classes used in the Quiz Question module.
 *
 * The core of the Quiz Question module is a set of abstract classes that
 * can be used to quickly and efficiently create new question types.
 *
 * Why OO?
 * Drupal has a long history of avoiding many of the traditional OO structures
 * and metaphors. However, with PHP 5, there are many good reasons to use OO
 * principles more broadly.
 *
 * The case for Quiz question types is that question types all share common
 * structure and logic. Using the standard hook-only Drupal metaphor, we are
 * forced to copy and paste large amounts of repetitive code from question
 * type to question type. By using OO principles and construction, we can
 * easily encapsulate much of that logic, while still making it easy to
 * extend the existing content.
 *
 * Where do I start?
 * To create a new question type, check out the multichoice question type for instance.
 *
 * @file
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
class TranslatedQuizQuestion extends QuizQuestion {

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
}


/**
 * Each question type must store its own response data and be able to calculate a score for
 * that data.
 */
class TranslatedQuizQuesionResponse extends QuizQuestionResponse {
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

