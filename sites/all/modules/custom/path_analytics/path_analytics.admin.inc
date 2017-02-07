<?php


function path_analytics_admin_settings_form() {
  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
    '#collapsible' => FALSE,
  );

  $names = node_type_get_names();
  $form['settings']['path_analytics_nodetypes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Provide path-based Google Analytics using the following content types as initial paths.'),
    '#default_value' => variable_get('path_analytics_nodetypes', array()),
    '#options' => array_map('check_plain', $names),
    '#description' => t('Enable path-based analytics reports for the selected content type(s).'),
  );

  $options = array(0 => t('No'), 1 => t('Yes'));
  $localtask = variable_get('path_analytics_localtask', 1);

  $form['settings']['path_analytics_localtask'] = array(
    '#type' => 'radios',
    '#title' => t('Provide access to the report from the main node.'),
    '#default_value' => isset($localtask) ? $localtask : 0,
    '#options' => $options,
    '#description' => t('This will provide a local menu task tab (next to "Edit", etc.) on the main node. WARNING: You will need to provide a link to the report(s) if you turn off this option. Links should be in the form of "path_analytics/[nid]"'),
  );

  return system_settings_form($form);
}


function path_analytics_admin_settings_form_submit($form, &$form_state) {
  // Save form settings.
  system_settings_form_submit($form, $form_state);
}
