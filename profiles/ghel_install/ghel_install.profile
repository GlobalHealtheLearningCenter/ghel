<?php
/**
 * @file
 * Base install profile setup for GHeL.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function ghel_install_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];

  // Adjust date options so that date/date API is happy on install.
  module_load_include('inc', 'system', 'system.admin');
  $regional_form = system_regional_settings();
  $form['server_settings']['date_first_day'] = $regional_form['locale']['date_first_day'];
  $settings = system_date_time_settings();
  $form['server_settings']['formats'] = $settings['formats'];
  $form = system_settings_form($form);
}

/**
 * Implements hook_install_tasks().
 */
function ghel_install_install_tasks() {
  return array(
    'ghel_install_revert_features' => array(
      'display_name' => t('Features Revert'),
    ),
    'ghel_install_final_cleanup' => array(
      'display_name' => t('Final Cleanup'),
    ),
  );
}

/**
 * Performs any necessary cleanup at install end.
 */
function ghel_install_revert_features() {
  $features_revert = array(
    'ghel_base',        // revert required for home page node association
    'ghel_workflow',  // Initial revert for workflow "Course Page Status"
    'ghel_workflow',  // Second revert for og workflow "Course Page Status"
  );

  foreach ($features_revert as $module) {
    if (($feature = feature_load($module, TRUE)) && module_exists($module)) {
      $components = array();

      // Gather all the feature components.
      foreach (array_keys($feature->info['features']) as $component) {
        if (features_hook($component, 'features_revert')) {
          $components[] = $component;
        }
      }

      // Revert each component.
      foreach ($components as $component) {
        features_revert(array($module => array($component)));
      }
    }
  }
}

/**
 * Perform any necessary cleanup at install end.
 */
function ghel_install_final_cleanup() {

  // Avoid node_access_rebuild message on install.
  node_access_rebuild();

  // This can't be an install dependency as the featurized workflows need revert
  // before they work properly.
  // Workflow_actions throws several errors if workflows do not exist  prior to
  // calling.
  module_enable(array('workflow_actions'));
}
