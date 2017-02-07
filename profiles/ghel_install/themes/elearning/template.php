<?php

/**
 * MENUS
 */

/**
 * Overrides theme_menu_tree() for the main menu.
 */

function elearning_menu_tree__main_menu($variables) {
  return '<ul class="nav nav--main">' . $variables['tree'] . '</ul>';
}

/**
 * Overrides theme_menu_tree() for the main menu.
 */

function elearning_menu_tree__user_menu($variables) {
  return '<ul class="nav nav--user">' . $variables['tree'] . '</ul>';
}

/**
 * Overrides theme_menu_tree() for the footer menu.
 */

function elearning_menu_tree__menu_footer_menu($variables) {
  return '<ul class="nav nav--footer">' . $variables['tree'] . '</ul>';
}

/**
 * Overrides theme_menu_tree() for the local menu.
 */

function elearning_menu_tree__menu_block__ghel_about_menu_blocks_5($variables) {
  return '<ul class="nav nav-stacked nav-buttons">' . $variables['tree'] . '</ul>';
}

/**
 * Overrides theme_menu_local_tasks().
 */

function elearning_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="nav-local-tasks">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }

  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="nav nav-pills">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

/**
 * Implements hook_preprocess_menu_link()
 */

function elearning_preprocess_menu_link(&$vars) {
  /* Set shortcut variables. Hooray for less typing! */
  $menu = $vars['element']['#original_link']['menu_name'];
  $mlid = $vars['element']['#original_link']['mlid'];
  $item_classes = &$vars['element']['#attributes']['class'];
  $link_classes = &$vars['element']['#localized_options']['attributes']['class'];

  /* Add global classes to all menu links */
  $item_classes[] = 'nav-item';
  $link_classes[] = 'nav-link';
}

/**
 * Custom implementation of theme_menu_link()
 */

function elearning_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  // Custom classes
  $custom_class =  drupal_html_class(check_plain($element['#title']));
  $element['#attributes']['class'][] = 'nav-item-' . $custom_class;
  $element['#localized_options']['attributes']['class'][] = 'nav-link-' . $custom_class;
  $element['#localized_options']['html'] = TRUE;

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * FIELDS
 */

/**
 * Implements hook_preprocess_field()
 */

function elearning_preprocess_field(&$vars) {
  $field = $vars['element']['#field_name'];
  $bundle = $vars['element']['#bundle'];
  $mode = $vars['element']['#view_mode'];
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  $item_classes = array();

  $base_class = drupal_clean_css_identifier($field);

  /* Global field styles */
  $classes = array('field', $base_class);
  $title_classes[] = 'field-label';
  $content_classes[] = 'field-items';
  $item_classes[] = 'field-item';

  /* Uncomment the lines below to see variables you can use to target a field */
  // print '<strong>Field:</strong> ' . $field . '<br/>';
  // print '<strong>Bundle:</strong> ' . $bundle  . '<br/>';
  // print '<strong>Mode:</strong> ' . $mode .'<br/>';

  switch ($field) {
    case 'field_ghel_highlight_1_type_':
    case 'field_ghel_highlight_2_type_':
      $classes = array('highlight-heading');
      break;
    case 'field_ghel_highlight_1_':
    case 'field_ghel_highlight_2_':
      $classes = array('highlight-content');
      break;
    case 'post_date':
      if ($mode == 'dated' || 'dated_featured') {
        $timestamp = strtotime($vars['items'][0]['#markup']);
        $month = date("M", $timestamp);
        $date = date("d", $timestamp);
        $vars['items'][0]['#markup'] = '<span class="month">' . $month . '</span>';
        $vars['items'][0]['#markup'] .= ' <span class="day">' . $date . '</span>';
        $classes[] = 'date-thumbnail';
      }
      break;
    case 'field_ghel_twitter':
    case 'field_ghel_facebook':
    case 'field_ghel_website':
      $classes[] = 'social-link';
      break;
    case 'field_ghel_course_authors':
    case 'field_ghel_course_managers':
      $content_classes[] = 'no-bullets';
      break;
  }

  // Apply odd or even classes along with our custom classes to each item */
  foreach ($vars['items'] as $delta => $item) {
    $vars['item_attributes_array'][$delta]['class'] = $item_classes;
    $stripe = $delta % 2 ? 'odd' : 'even';
    $vars['item_attributes_array'][$delta]['class'][] = $stripe;
  }
}

/**
 * Custom implementation of theme_field_multiple_value_form() that checks for a title.
 */
function elearning_field_multiple_value_form($variables) {
  $element = $variables['element'];
  $output = '';

  if ($element['#cardinality'] > 1 || $element['#cardinality'] == FIELD_CARDINALITY_UNLIMITED) {
    $table_id = drupal_html_id($element['#field_name'] . '_values');
    $order_class = $element['#field_name'] . '-delta-order';
    $required = !empty($element['#required']) ? theme('form_required_marker', $variables) : '';
    $field_title = $element['#title']
      ? '<label>' . t('!title !required', array('!title' => $element['#title'], '!required' => $required)) . '</label>'
      : ' ';
    $header = array(
      array(
        'data' => $field_title,
        'colspan' => 2,
        'class' => array('field-label'),
      ),
      t('Order'),
    );
    $rows = array();

    // Sort items according to '_weight' (needed when the form comes back after
    // preview or failed validation)
    $items = array();
    foreach (element_children($element) as $key) {
      if ($key === 'add_more') {
        $add_more_button = &$element[$key];
      }
      else {
        $items[] = &$element[$key];
      }
    }
    usort($items, '_field_sort_items_value_helper');

    // Add the items as table rows.
    foreach ($items as $key => $item) {
      $item['_weight']['#attributes']['class'] = array($order_class);
      $delta_element = drupal_render($item['_weight']);
      $cells = array(
        array(
          'data' => '',
          'class' => array('field-multiple-drag'),
        ),
        drupal_render($item),
        array(
          'data' => $delta_element,
          'class' => array('delta-order'),
        ),
      );
      $rows[] = array(
        'data' => $cells,
        'class' => array('draggable'),
      );
    }

    $output = '<div class="form-item">';
    $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => $table_id, 'class' => array('field-multiple-table'))));
    $output .= $element['#description'] ? '<div class="description">' . $element['#description'] . '</div>' : '';
    $output .= '<div class="clearfix">' . drupal_render($add_more_button) . '</div>';
    $output .= '</div>';

    drupal_add_tabledrag($table_id, 'order', 'sibling', $order_class);
  }
  else {
    foreach (element_children($element) as $key) {
      $output .= drupal_render($element[$key]);
    }
  }

  return $output;
}

/**
 * LINKS
 */

function elearning_links__articles($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  global $language_url;
  $output = '';

  // Add custom classes for articles.
  $attributes['class'][] = 'article-list';
  foreach ($links as $link_id => $link) {
    $links[$link_id]['attributes'] = array(
      'class' => array('article-title', 'is-small'),
    );
  }

  if (count($links) > 0) {
    $output = '';

    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading.
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $output .= '<ul' . drupal_attributes($attributes) . '>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = array($key);
      // Add custom article classes to the li.
      $class[] = 'article-item';
      $class[] = 'is-bulleted';

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class[] = 'first';
      }
      if ($i == $num_links) {
        $class[] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
           && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}

/**
 * NODES
 */

/**
 * Implements hook_preprocess_node()
 */

function elearning_preprocess_node(&$vars) {
  /* Set shortcut variables. Hooray for less typing! */


  $type = $vars['type'];
  $mode = $vars['view_mode'];
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  $content = &$vars['content'];

  // Highlight field value and type are biconditional display IFF value has content.
  if (empty($content['field_ghel_highlight_1_']['#items'][0]['value']) && isset($content['field_ghel_highlight_1_type_'])) {
    unset($content['field_ghel_highlight_1_type_']);
  }
  if (empty($content['field_ghel_highlight_2_']['#items'][0]['value']) && isset($content['field_ghel_highlight_2_type_'])) {
    unset($content['field_ghel_highlight_2_type_']);
  }

  switch ($type) {
    case 'ghel_course_page':

      if ($mode == 'full') {
        $vars['highlight_1'] = '';
        $vars['highlight_2'] = '';

        //Add equal heights JS file
        drupal_add_js(drupal_get_path('theme', 'elearning') . '/js/jquery.equalheights.js');
        $vars['scripts'] = drupal_get_js();

        $equalheightsjs = "(function ($) {
          $('aside.highlights .highlight').equalHeights(10, 5000);
        })(jQuery);";
        drupal_add_js($equalheightsjs, array('type' => 'inline', 'scope' => 'footer'));


        /* Combine Highlight fields */
        if (isset($content['field_ghel_highlight_1_type_'])) {
          $content['highlight_1'] = array(
            '#prefix' => '<div class="highlight highlight-1">',
            '#suffix' => '</div>',
            '#weight' => -2,
          );
          if (isset($content['field_ghel_highlight_1_type_'])) {
            $content['highlight_1'][] = $content['field_ghel_highlight_1_type_'];
            $vars['highlight_1'] = $content['field_ghel_highlight_1_type_'];
          }
          if (isset($content['field_ghel_highlight_1_'])) {
            $content['highlight_1'][] = $content['field_ghel_highlight_1_'];
          }
          $vars['highlight_1'] = render($content['highlight_1']);
        }
        unset($content['field_ghel_highlight_1_type_']);
        unset($content['field_ghel_highlight_1_']);

        if (isset($content['field_ghel_highlight_2_type_'])) {
          $content['highlight_2'] = array(
            '#prefix' => '<div class="highlight highlight-2">',
            '#suffix' => '</div>',
            '#weight' => -1,
          );
          if (isset($content['field_ghel_highlight_2_type_'])) {
            $content['highlight_2'][] = $content['field_ghel_highlight_2_type_'];
          }
          if (isset($content['field_ghel_highlight_2_'])) {
            $content['highlight_2'][] = $content['field_ghel_highlight_2_'];
          }
          $vars['highlight_2'] = render($content['highlight_2']);
        }
        unset($content['field_ghel_highlight_2_type_']);
        unset($content['field_ghel_highlight_2_']);
      }
     break;
    case 'ghel_course':
      // Show courses under review.
      if (isset($vars['workflow']) && $vars['workflow'] == '7') {
        $classes[] = 'workflow--under-review';
        $vars['content']['title'][0]['#prefix'] = '<small class="workflow-state">'
          . t('Course Under Revision') . '</small>';
        // Remove the link from the title.
        $vars['content']['title'][0]['#markup'] = '<h3 class="article-title">'
          . t($vars['title']) . '</h3>';
        // Remove the link from the image.
        unset($vars['content']['field_image'][0]['#path']);
      }
      break;
    case 'quiz':
      if (isset($vars['content']['stats'])) {
        unset($vars['content']['stats']);
      }
      break;
  }
}

/**
 * BLOCKS
 */

/**
 * Implements hook_block_view_MODULE_DELTA_alter().
 */
function elearning_block_view_search_form_alter(&$data, $block) {
  // Add a title to the search block so we can create a link on small screens.
  $data['subject'] = t('Search');
}

/**
 * Implements hook_preprocess_block()
 */
function elearning_preprocess_block(&$vars) {
  /* Set shortcut variables. Hooray for less typing! */
  $block_id = $vars['block']->module . '-' . $vars['block']->delta;
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];

  /* Add global classes to all blocks */
  $title_classes[] = 'block-title';
  $content_classes[] = 'block-content';

  /* Uncomment the line below to see variables you can use to target a block */
  // print $block_id . '<br/>';

  /* Add classes based on the block delta. */
  switch ($block_id) {
    /* My Recent Courses block */
    case 'views-ghel_author_my_courses-block_1':
    /* My Publised Courses block */
    case 'views-ghel_author_my_courses-block_2':
    /* My Completed Courses block */
    case 'ghel_certificate-courses-completed':
    /* My In Progress Courses block */
    case 'ghel_certificate-courses-in-progress':
    /* My Competed Programs block */
    case 'ghel_certificate-programs-in-progress':
    /* My In Progress Programs block */
    case 'ghel_certificate-programs-complete':
    /* My Certificates block */
    case 'ghel_certificate-my-certificates':
      $title_classes[] = 'block-title-condensed';
      $classes[] = 'block-spaced';
      break;
    /* Create course block */
    case 'menu-menu-ghel-create-course':
    /* Course reference block */
    case 'views-ghel_course_reference-block':
    /* Course creation links block */
    case 'views-bd49fdb7a862674db8451fcbc694adb4':
    /* Course next link */
    case 'ghel_course-next':
    /* Course previous link */
    case 'ghel_course-previous':
    /* Encouragements */
    case 'ghel_reports-encouragements':
    /* Footer Menu */
    case 'menu_block-ghel_base_menu_blocks-4':
    /* Local Menu */
    case 'menu_block-ghel_about_menu_blocks-5':
      $title_classes[] = 'element-invisible';
      break;
    case 'views-certificate_programs-block':
      $title_classes = array('section-heading');
      break;
    case 'views-ghel_featured_courses-block':
      $title_classes[] = 'block-title-ruled';
      break;
    /* Main Menu block */
    case 'menu_block-ghel_base_menu_blocks-1':
    /* User Menu block */
    case 'menu_block-ghel_base_menu_blocks-2':
    case 'system-user-menu':
    /* Search form */
    case 'search-form':
      $title_classes[] = 'tab-title';
      $title_classes[] = 'element-invisible';
      break;
    case 'views-certificate_programs-block':
      $title_classes = array('section-heading');
      break;
    case 'views-ghel_featured_courses-block':
      $title_classes[] = 'block-title-ruled';
      break;
    /* FAQs block */
    case 'views-faqs-block':
      $classes[] = 'accordion';
      drupal_add_library('system', 'ui.accordion');
      // Turn faq articles into accordians.
      drupal_add_js("(function ($) {
          $(document).ready(function(){
            $('.accordion').find('.faq-title').addClass('ss-navigateright');
            $('.accordion').find('.ds-header').addClass('is-collapsed').click(
              function() {
                $(this).toggleClass('is-collapsed is-expanded').next().toggle('fast');
                $(this).find('.faq-title').toggleClass('ss-navigateright ss-navigatedown');
                return false;
              }
            ).next().hide();
          });
        })(jQuery);",
        'inline');
      break;
  }
}

/**
 * FORMS
 */

/**
 * Implements hook_form_alter
 */

function elearning_form_alter(&$form, &$form_state, $form_id) {
  /* Add placeholder text to a form */
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#attributes']['placeholder'] = "Enter a search term...";
  }
}


/**
 * Implements hook_preprocess_html()
 */

function elearning_preprocess_html(&$variables) {
  if (_in_course_workflow()) {
    $variables['classes_array'][] = 'course-workflow';
  }
}
/*
 * In cases where this content is child of a ghel_course CT,
 * Permit Feedback when workflow state is GHEL_WORKFLOW_STATE_FEEDBACK
 */
function ghel_node_feedback($variables){

  $feedback_permitted = 0;

  if (isset($variables['node'])) {

    //If ghel_course field value exists, use this to get the state of the parent course
    if($ghel_course_field = field_get_items('node', $variables['node'], 'field_ghel_course')){

      $ghel_course_nid = $ghel_course_field[0]['target_id'];
      $ghel_course_node = node_load($ghel_course_nid);

      //If state is feedback, then allow feedback comments
      if(workflow_node_current_state($ghel_course_node) ==  GHEL_WORKFLOW_STATE_FEEDBACK){
        $feedback_permitted = 1;
      }
    }
    return $feedback_permitted;
  }
}
/**
 * PAGES
 */

function elearning_preprocess_page(&$variables) {

  $feedback_permitted = ghel_node_feedback($variables);
  $classes = &$variables['classes_array'];
  $variables['title_attributes_array']['class'] = array('page-title');

  // Add logo links.
  $variables['usaid_logo'] = '<a href="http://usaid.gov" id="usaid-logo"><img alt="US Aid Logo" src="/' . path_to_theme() .'/images/usaid-logo.png"></a>';
  $variables['k4h_logo'] = '<a href="http://k4health.org" id="k4h-logo"><img alt="K4h Logo" src="/' . path_to_theme() .'/images/k4h-logo.png"></a>';

  if (_in_course_workflow($variables)) {
    $variables['theme_hook_suggestions'][] = 'page__course_workflow';
    $classes[] = 'page-course-workflow';

    // Remove local tasks for learners unless they are admins
    if (in_array('learner', $variables['user']->roles) &&
       !in_array('site administrator', $variables['user']->roles)) {
      unset($variables['tabs']);
    }
  } elseif (arg(0) == 'node' && is_numeric(arg(1)) && isset($variables['node']) && $variables['node']->title == "Courses") {
    // Add page class to the courses page
    $classes[] = 'page--courses';
  }

  // Remove certain tabs for non admins
    if (!in_array('site administrator', $variables['user']->roles)
        && isset($variables['tabs']['#primary'])
        && is_array($variables['tabs']['#primary'])) {
      foreach ($variables['tabs']['#primary'] as $tabs => $tab) {
        $path = $tab['#link']['path'];
        if($path == 'user/%/myresults' || $path == 'user/%/achievements') {
          unset($variables['tabs']['#primary'][$tabs]);
        }
      }
    }

  // Collect tabbed regions.
  $tabbed_regions = array(
    'tab_pages' => 'Pages',
    'tab_highlights' => 'Highlights',
    'tab_glossary' => 'Glossary',
    'tab_course' => 'Course',
    'tab_resources' => 'Resources',
    'tab_reference' => 'Reference',
  );
  if( $feedback_permitted ){
    $tabbed_regions['tab_feedback'] = 'Feedback';
  }

  // Set a default value.
  $variables['page']['#has_tabbed_regions'] = FALSE;

  // Create a new render array element to group tabbed regions.
  $variables['page']['tabbed_regions'] = array();

  foreach ($tabbed_regions as $region => $title) {
    // Move the regions into the new render array.
    $variables['page']['tabbed_regions'][$region] = $variables['page'][$region];
    unset($variables['page'][$region]);

    // Check if the current region is not empty.
    if (!empty($variables['page']['tabbed_regions'][$region])) {
      $variables['page']['#has_tabbed_regions'] = TRUE;
      // Make sure the array gets sorted before rendering.
      unset($variables['page']['tabbed_regions'][$region]['#sorted']);
      // Add a title to the current region.
      $variables['page']['tabbed_regions'][$region]['#title'] = array(
        '#markup' => '<h2 class="tab-title">' . t($title) . '</h2>',
        '#weight' => -10,
      );
    }
  }
}

/**
 * Implements hook_process_page()
 */
function elearning_process_page(&$variables) {
  // Alter page titles
  if (arg(0) == 'user' && (!arg(1) || is_numeric(arg(1)))) {
    $variables['title'] = NULL;
  }
}

/**
 * REGIONS
 */

/**
 * Implements hook_preprocess_region()
 */

function elearning_preprocess_region(&$variables) {

  $region = $variables['region'];
  switch ($region) {
    case 'tab_pages':
    case 'tab_feedback':
    case 'tab_highlights':
    case 'tab_glossary':
    case 'tab_course':
    case 'tab_resources':
    case 'tab_reference':
      $variables['theme_hook_suggestions'][] = 'region__tabbed';
      $variables['title'] = $variables['elements']['#title']['#markup'];
      break;
  }
}


/**
 * This function overrides rendering for ghel_course_navigation and is needed by
 * ghel_toc_widget.
 *
 * This is more complex than desireable, but we also want to leverage as much of
 * the field api as possible. Additionally field API gets very angry if we mangle the
 * field item count.
 *
 * @see theme_ghel_toc_widget_section
 * @see theme_ghel_toc_widget_non_section
 * @see ghel_toc_widget_field_formatter_view
 * @see ghel_toc_widget.js
 */
function elearning_field__field_ghel_course_navigation__ghel_course($variables) {
  $output = '';
  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }

  // Render the items.
  $output .= '<div ' . $variables['content_attributes'] . '>';
  $activesection = 0;
  $activenonsection = 0;
  foreach ($variables['items'] as $delta => $item) {
    if (in_array('ghel-toc-section', $item['#options']['attributes']['class'])) {
      if ($activesection) {
        // closing div from previous section
        $output .= '</div>';
        if ($activenonsection) {
          $output .= '</div>';
          $activenonsection = 0;
        }
      }
      else {
        $activesection++;
      }
      $output .= '<div class="course-section-group">';
      $output .= drupal_render($item);
    }
    else {
      if (!$activenonsection) {
        $activenonsection++;
        $output .= '<div class="course-section-pages">';
      }
      $output .= drupal_render($item);
    }
  }

  // if we have an active non section div.
  if ($activenonsection) {
    $output .= '</div>';
  }
  // if we have an active section div.
  if ($activesection) {
    $output .= '</div>';
  }

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

/**
 * Implements theme_field
 * This function removes the extra colon after the labels.
 */

function elearning_field__ghel_action_plan($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . '</div>';
  }

  // Render the items.
  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}
/**
 * Implements hook_preprocess_user_profile
 */
function elearning_preprocess_user_profile(&$vars) {
  // User full name
  $vars['name'] = $vars['field_ghel_first_name'][0]['safe_value']
    . ' ' . $vars['field_ghel_last_name'][0]['safe_value'];

  // User email
  $email = $vars['elements']['#account']->mail;
  $vars['email'] = l(
    $email,
    'mailto://' . $email,
    array (
      'attributes' => array(
        'class' => array('email-link')
      )
    )
  );
}

function _in_course_workflow() {
  if(arg(0) == 'node' && is_int((int)arg(1))) {
    $node = node_load((int)arg(1));
    $course_node_types = array(
      'ghel_course_page',
      'ghel_course_section',
      'quiz',
    );
    if(!empty($node) && in_array($node->type, $course_node_types)) {
      return true;
    }
  }
  return false;
}

function elearning_file_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $url = file_create_url($file->uri);
  $icon = theme('file_icon', array('file' => $file, 'icon_directory' => $icon_directory));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
    ),
  );

  // Use the description as the link text if available.
  if (empty($file->description)) {
    $link_text = $file->filename;
  }
  else {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
  }

  if (strpos($file->filename, '.epub') !== FALSE) {
    return '<span class="file epub-file">' . l('Epub', $url, $options) . '</span>';
  }
  elseif (strpos($file->filename, '.mobi') !== FALSE) {
    return '<span class="file mobi-file">' . l('Mobi', $url, $options) . '</span>';
  }
  else {
    return '<span class="file">' . $icon . ' ' . l($link_text, $url, $options) . '</span>';
  }
}


