<?php
/**
 * @file
 * This template is used to conditionally provide a link to the action 
 * plan if the user has completed it.
 */

// See if the user has completed a evaluation based on this.
print ghel_action_plan_print_link($row->{$view->field['nid']->field_alias});
