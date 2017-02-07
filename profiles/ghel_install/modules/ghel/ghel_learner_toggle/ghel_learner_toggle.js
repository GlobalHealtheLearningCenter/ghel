(function ($) {
Drupal.behaviors.learnertoggle_submit = {
    attach: function (context) {
      $('.ghel-learner-toggle-form').once('learnertoggle', function() {
        var $this = $(this);
        $this.find('input.form-submit').hide();
        $this.find('input[type=checkbox]').change(function() {
          $this.find('input.form-submit').click();
          return false;
        });
      });
    }
  }
})(jQuery);
