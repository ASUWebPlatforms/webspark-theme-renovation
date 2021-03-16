
(function ($,Drupal) {

  'use strict';

  Drupal.behaviors.closeBanner = {
    attach: function (context) {
      $('#btn-close', context).click(function () {
        $('#block-bannerblock').hide();
      });
    }
  };

})(jQuery, Drupal);
