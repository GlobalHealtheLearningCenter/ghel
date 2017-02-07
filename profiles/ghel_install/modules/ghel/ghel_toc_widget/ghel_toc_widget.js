(function ($) {
  // Define the grandparent toggle behavior
  Drupal.behaviors.ghelTocToggle = {
    attach: function (context, settings) {
      $('a.gheltocselector', context).once('gheltoctoggle-applied').toggle(
        function () {
          $(this).parent().addClass('expanded');
          $(this).parent().removeClass('collapsed');
          $(this).parent().next().slideDown();
        },
        function () {
          $(this).parent().addClass('collapsed');
          $(this).parent().removeClass('expanded');
          $(this).parent().next().slideUp();
        }
      );
    }
  }
})(jQuery);

jQuery(document).ready(function($) {
    // roll-up all course sections
    $('a.gheltocselector').parent().next().toggle();

    // If page is active unroll it's group
    $('div.course-page-active').parent().toggle();

    // if section is active unroll it's group
    $('h4.course-section-active').next().toggle();
  });
