(function($, Drupal)
{
    Drupal.ajax.prototype.commands.ghel_populate_regions_js = function(ajax, response, status)
    {
      $("#edit-field-ghel-sub-region-und").val(response.ghel_sub_region);

      // Disable
      $("#edit-field-ghel-sub-region-und").attr('disabled','disabled');
      $("#edit-field-ghel-region-und").val(response.ghel_region);

      //Then disable
      $("#edit-field-ghel-region-und").attr('disabled','disabled');

    };
}(jQuery, Drupal));
