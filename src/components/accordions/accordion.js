
(function ($,Drupal) {

  'use strict';

  Drupal.behaviors.closeBanner = {
    attach: function (context) {
      $(".ac-label").click(function(e){
        e.preventDefault();
        $check = $(this).prev();
        if($check.prop('checked'))
          $check.prop( "checked", false );
        else
          $check.prop( "checked", true );
      });
    }
  };

})(jQuery, Drupal);
