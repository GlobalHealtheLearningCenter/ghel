<?php
/**
 * @file
 * ghel_action_plan.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ghel_action_plan_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ghel_action_plan_node_info() {
  $items = array(
    'ghel_action_plan' => array(
      'name' => t('Action Plan'),
      'base' => 'node_content',
      'description' => t('Global Health eLearning Action Plan'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('One of the objectives of the Global Health eLearning Center is to improve health practice and programming by providing learners with a greater understanding of health problems and their solutions. Please take a few moments to plan how you will apply your knowledge of this course in your work.

Using the form below, identify actions that you intend to take in your work to apply what you have learned or to address the issues you learned about in this course. We encourage you to revisit this plan frequently, but at a minimum you should try to update it three to six months from today. This action plan will always be available on <a href="/?q=dashboard" alt="Learner home" title="Learner home" target="_blank">your learner home</a>. You can also incorporate some of the information in your action plan into your job description, individual work plan, or annual evaluation. Consider also sharing some of your goals and plans with your supervisor.'),
    ),
  );
  return $items;
}
