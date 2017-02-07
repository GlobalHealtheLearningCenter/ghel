<?php
/**
 * @file
 * This template is used to conditionally provide a link to the course
 * evaluation if the user has not already completed it.
 */

// See if the user has completed a evaluation based on this.
print ghel_course_eval_print_link($row->{$view->field['nid']->field_alias});
