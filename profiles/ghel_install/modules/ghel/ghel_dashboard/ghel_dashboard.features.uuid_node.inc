<?php
/**
 * @file
 * ghel_dashboard.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function ghel_dashboard_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'uid' => 0,
  'title' => 'Learner Home',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => 'c45d03ac-9606-7a64-190a-0289f035aa5a',
  'ds_switch' => '',
  'type' => 'page',
  'language' => 'en',
  'created' => 1345230254,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '2f4de39e-82d9-d4e4-6de4-d02ef08e2a5e',
  'revision_uid' => 0,
  'body' => array(),
  'field_image' => array(),
  'field_ghel_file' => array(),
  'title_field' => array(
    'ar' => array(
      0 => array(
        'value' => 'الصفحة الرئيسية للدارس',
        'format' => NULL,
        'safe_value' => 'الصفحة الرئيسية للدارس',
      ),
    ),
    'en' => array(
      0 => array(
        'value' => 'Learner Home',
        'format' => NULL,
        'safe_value' => 'Learner Home',
      ),
    ),
    'es' => array(
      0 => array(
        'value' => 'Página de inicio del estudiante',
        'format' => NULL,
        'safe_value' => 'Página de inicio del estudiante',
      ),
    ),
    'fr' => array(
      0 => array(
        'value' => ' Accueil Apprenant',
        'format' => NULL,
        'safe_value' => ' Accueil Apprenant',
      ),
    ),
    'pt' => array(
      0 => array(
        'value' => 'Página Inicial do Formando',
        'format' => NULL,
        'safe_value' => 'Página Inicial do Formando',
      ),
    ),
    'und' => array(
      0 => array(
        'value' => 'Learner Home',
        'format' => NULL,
        'safe_value' => 'Learner Home',
      ),
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'epub_export_type' => 'node',
  'formblock_entity_type' => 'node',
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'lingotek' => array(
    'name' => 'Website Base - Professional',
    'lingotek_nodes_translation_method' => 'field',
    'auto_upload' => 1,
    'auto_download' => 1,
    'allow_target_localization' => 0,
    'allow_source_overwriting' => 0,
    'allow_community_translation' => 0,
    'url_alias_translation' => 0,
    'project_id' => 33348,
    'workflow_id' => '64c4cf32-f315-48ea-8266-9ea7d7f9abb9',
    'vault_id' => 13043,
    'profile' => 4,
    'document_id' => '8d4213d1-28b4-4002-88af-ca5c1c57239b',
    'hash' => 'a958d9d35b719b4fdcf520545c39ca71',
    'last_uploaded' => 1448904338,
    'upload_status' => 'CURRENT',
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 0,
  'comment_count' => 0,
  'name' => '',
  'picture' => 0,
  'data' => NULL,
  'workflow' => FALSE,
  'date' => '2012-08-17 13:04:14 -0600',
);
  return $nodes;
}
