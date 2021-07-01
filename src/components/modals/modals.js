(function ($,Drupal) {

  'use strict';

  Drupal.behaviors.modals = {
    attach: function (context) {
      $("#openModalButton").click(function(e){
        e.preventDefault();
        $("#uds-modal").addClass('open');
      });
      $("#closeModalButton").click(function(e){
        e.preventDefault();
        $("#uds-modal").removeClass('open');
      });
    }
  };

})(jQuery, Drupal);
