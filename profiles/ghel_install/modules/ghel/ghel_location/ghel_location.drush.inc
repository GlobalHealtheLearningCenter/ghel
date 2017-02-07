<?php

/*******************************************************************************
 * DRUSH SUPPORT
 ******************************************************************************/

/**
 * Implementation of hook_drush_command().
 */

function ghel_location_drush_command() {

  $items = array();
  $items['loc-update'] = array(
    'description' => dt('Run Location update'),
    'arguments' => array(
      'arg1' => dt('Optional User ID'),
    ),
    'callback' => 'ghel_loc_update',
    'examples' => array(
      'Standard example' => 'drush loc-update',
      'Argument example' => 'drush loc-update 5',
      'Range example. Return 5 records.' => 'drush loc-update 0 5',
    ),
    'aliases' => array('gloc'),
  );
  return $items;

}
/* Call update on user locations for given userid, range or all (with no arguments)*/
function ghel_loc_update($uid = 0, $range=0){
  ghel_location_update_user_location($uid, $range);
}