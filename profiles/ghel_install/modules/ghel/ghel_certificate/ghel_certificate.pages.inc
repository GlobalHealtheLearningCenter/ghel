<?php
/**
 * @file
 * Certificate rendering for GHeL programs.
 */

define('GHEL_CERTIFICATE_PAGE_WIDTH', 215);
define('GHEL_CERTIFICATE_PAGE_HEIGHT', 279);

/**
 * Custom process_ghel_certificate_html function for theming certificate pages.
 */
function ghel_certificate_process_ghel_certificate_html(&$variables) {
  // Construct page title.
  if (drupal_get_title()) {
    $head_title = array(
      'title' => strip_tags(drupal_get_title()),
      'name' => check_plain(variable_get('site_name', 'Drupal')),
    );
  }
  else {
    $head_title = array('name' => check_plain(variable_get('site_name', 'Drupal')));
    if (variable_get('site_slogan', '')) {
      $head_title['slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
    }
  }
  $variables['head_title_array'] = $head_title;
  $variables['head_title'] = implode(' | ', $head_title);

  $variables['head']    = drupal_get_html_head();
  $variables['css']     = drupal_add_css();
  $variables['styles']  = drupal_get_css();
  $variables['scripts'] = drupal_get_js();

  $variables['language']          = $GLOBALS['language'];
  $variables['language']->dir     = $GLOBALS['language']->direction ? 'rtl' : 'ltr';

}

/**
 * Custom process function for processing program certificate pages.
 */
function ghel_certificate_process_ghel_certificate_program(&$variables) {
  if (!empty($variables['courses'])) {
    $items = array();
    foreach ($variables['courses'] as $course) {
      $items[] = $course['title'];
    }
    $vars['items'] = $items;
    $vars['type'] = 'ul';
    $vars['attributes']['class'][] = 'course-list';
    $variables['courses'] = theme('item_list', $vars);
  }
  else {
    $variables['courses'] = '';
  }
}

/**
 * Not used refer to the tpl file instead.
 *
 * @see ghel_certificate.tpl.php
 */
function theme_ghel_certificate($variables) {
}

function ghel_certificate_build_pdf($html, $node) {
  if (pdf_using_mpdf_library_exist() != TRUE) {
    drupal_set_message(t('MPDF library does not exist'), 'error');
  }
  $fname = explode(' - ', variable_get('pdf_using_mpdf_pdf_filename', PDF_USING_MPDF_PDF_DEFAULT_FILENAME));
  $filename = token_replace($fname[0]);
  $nodetitle = token_replace($fname[1], array('node' => $node));
  $filename = "$filename Certificate - $nodetitle";

  $font_size = variable_get('pdf_using_mpdf_pdf_font_size', PDF_USING_MPDF_PDF_FONT_SIZE);

  // Creating Instance of mPDF Class Library.
  $mpdf = new mPDF(
    '',
    array(GHEL_CERTIFICATE_PAGE_WIDTH, GHEL_CERTIFICATE_PAGE_HEIGHT),
    $font_size
  );

  // Set the CSS
  $csspath = drupal_get_path('module', 'ghel_certificate');
  $cssfile = $csspath . '/ghel_certificate.css';
  if (is_file($cssfile)) {
    $css = file_get_contents($cssfile);
    $mpdf->WriteHTML($css, 1);
  }
  else {
    drupal_set_message(t('Unable to find certificate css file.'), 'warning');
  }

  $mpdf->WriteHTML($html);

  // Generating PDF File.
  if (variable_get('pdf_using_mpdf_pdf_save_option') == '0') {
    // Open in same browser.
    $mpdf->Output($filename . '.pdf', 'I');
    exit;
  }
  else {
    // Dialog box for Download as PDF.
    $mpdf->Output($filename . '.pdf', 'D');
  }
}

/**
 * Not used refer to the tpl file instead.
 *
 * @see ghel_certificate_overview.tpl.php
 */
function ghel_certificate_preprocess_ghel_certificate_overview(&$variables) {
  $links = array();
  foreach ($variables['certificates'] as $cert_id => $certificate) {
    $link = array(
      '#theme' => 'link',
      '#text' => $certificate['title'],
      '#options' => array(
        'attributes' => array('target' => '_blank'),
        'html' => FALSE,
      ),
      '#path' => 'certificate/' . $certificate['uid'] . '/' . $cert_id,
    );
    $markup = array(
      '#theme' => 'html_tag',
      '#tag' => 'span',
      '#value' => t('Completed !date', array('!date' => $certificate['pass_date'])),
    );

    $links[] = drupal_render($link) . ' ' . drupal_render($markup);
  }
  $variables['links'] = $links;
}

/**
 * Implements hook_preprocess_HOOK().
 */
function ghel_certificate_preprocess_certificate_overview(&$variables) {
}
