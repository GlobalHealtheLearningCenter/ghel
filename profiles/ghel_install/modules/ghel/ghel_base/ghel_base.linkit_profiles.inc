<?php
/**
 * @file
 * ghel_base.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function ghel_base_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new stdClass();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'ghel_linkit_taxo';
  $linkit_profile->admin_title = 'Taxonomy';
  $linkit_profile->data = array(
    'plugins' => array(
      'entity:node' => array(
        'weight' => '0',
        'enabled' => 0,
      ),
      'entity:taxonomy_term' => array(
        'weight' => '0',
        'enabled' => 1,
      ),
      'entity:user' => array(
        'weight' => '0',
        'enabled' => 0,
      ),
    ),
    'entity:node' => array(
      'result_description' => '',
      'bundles' => array(
        'ghel_announcement' => 0,
        'page' => 0,
        'ghel_course' => 0,
        'ghel_course_page' => 0,
        'ghel_course_section' => 0,
        'ghel_faq' => 0,
        'matching' => 0,
        'multichoice' => 0,
        'ghel_program' => 0,
        'quiz' => 0,
        'quiz_directions' => 0,
        'ghel_reference' => 0,
        'ghel_testimonial' => 0,
        'truefalse' => 0,
        'webform' => 0,
        'ghel_partner' => 0,
      ),
      'group_by_bundle' => 0,
      'include_unpublished' => 0,
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '[term:name] : [term:description]',
      'bundles' => array(
        'ghel_glossary' => 'ghel_glossary',
        'ghel_announcement_types' => 0,
        'ghel_faq_categories' => 0,
        'ghel_funder' => 0,
        'ghel_occupation_category' => 0,
        'ghel_organization_category' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'autocomplete' => array(
      'charLimit' => 3,
      'wait' => 350,
      'remoteTimeout' => 10000,
    ),
    'attributes' => array(
      'rel' => array(
        'weight' => '0',
        'enabled' => 0,
      ),
      'class' => array(
        'weight' => '0',
        'enabled' => 1,
      ),
      'accesskey' => array(
        'weight' => '0',
        'enabled' => 0,
      ),
      'id' => array(
        'weight' => '0',
        'enabled' => 1,
      ),
      'title' => array(
        'weight' => '0',
        'enabled' => 1,
      ),
    ),
  );
  $linkit_profile->role_rids = array(
    6 => 1,
  );
  $linkit_profile->weight = 0;
  $export['ghel_linkit_taxo'] = $linkit_profile;

  return $export;
}
