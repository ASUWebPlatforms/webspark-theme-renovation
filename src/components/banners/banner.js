
(function ($,Drupal) {

  'use strict';

  Drupal.behaviors.closeBanner = {
    attach: function (context) {
      $('#btn-close', context).click(function () {
        $('#btn-close').closest('.block').hide();
      });
    }
  };

})(jQuery, Drupal);
