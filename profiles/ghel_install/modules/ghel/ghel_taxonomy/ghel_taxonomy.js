(function($) {
  Drupal.behaviors.ghelTaxonomy = {
    attach : function(context, settings) {
      $('a[href*="/taxonomy/term"]', context).not('a[href*="edit"]').once('ghel-taxonomy', function() {
        $(this).attr('href', function(index, attr) {
          return attr.replace('/taxonomy/term/', '/gheltaxonomy/term/');
        });
        $(this).colorbox({maxWidth:'90%', maxHeight:'90%', initialHeight:"33%", initialWidth:"33%"});
      });
      $('a[href*="/?q=taxonomy/term/"]', context).not('a[href*="edit"]').once('ghel-taxonomy', function() {
        $(this).attr('href', function(index, attr) {
          return attr.replace('/?q=taxonomy/term/', '/gheltaxonomy/term/');
        });
        $(this).colorbox({maxWidth:'90%', maxHeight:'90%', initialHeight:"33%", initialWidth:"33%"});
      });
    }
  }
})(jQuery);
