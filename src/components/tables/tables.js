(function ($, Drupal) {

  'use strict';

  Drupal.behaviors.fixedTables = {
    attach: function (context) {

      /**
       * Javascript for fixed table functionality. Fixed table should display scroll buttons when hovering over scrollable portion of table,
       * and hide them when hovering over fixed column or when mouse exits table.
       *
       * The scroll buttons must be outside the table container, within the table wrapper, due to the absolute positioning requirements.
       * Because the table scrolls, if they were to be absolutely positioned in the same container as the table, they would scroll with it.
       */
      window.addEventListener('DOMContentLoaded', function () {
        addFixedWrappers();
        initializeFixedTable();
      });

      function addFixedWrappers() {
        $('.uds-table-fixed').each(function( index ) {
          var wrapper = document.createElement('div');
          $(wrapper).addClass('uds-table-fixed-wrapper');
          // Add buttons prev and next.
          $(this).wrap(wrapper);
          var added_wrapper = $(this).parent();
          $(added_wrapper).prepend('<div class="scroll-control previous"><button type="button" class="btn btn-circle btn-circle-alt-gray"><i class="fas fa-chevron-left"></i><span class="sr-only">Previous</span></button></div>');
          $(added_wrapper).prepend('<div class="scroll-control next"><button type="button" class="btn btn-circle btn-circle-alt-gray"><i class="fas fa-chevron-right"></i><span class="sr-only">Next</span></button></div>');
        });
      }

      function initializeFixedTable() {
        const tableWrappers = document.getElementsByClassName(
                'uds-table-fixed-wrapper'
                );

        for (let wrapper of tableWrappers) {
          const container = wrapper.getElementsByClassName('uds-table-fixed')[0];
          const previous = wrapper.getElementsByClassName(
                  'scroll-control previous'
                  )[0];
          const next = wrapper.getElementsByClassName('scroll-control next')[0];

          // If the user leaves the scrollable area, hide the scroll
          wrapper.addEventListener('mouseleave', function () {
            previous.classList.remove('show');
            next.classList.remove('show');
          });

          // If the user mouses over the scrollable area, show the scroll
          const showScrollWhenHoverTheseElements = container.querySelectorAll(
                  'tr > *:nth-child(n + 2)'
                  );

          // If the user leaves the scrollable area, hide the scroll
          const hideScrollWhenHoverTheseElements = container.querySelectorAll(
                  'tr > *:first-child'
                  );
          for (let i = 0; i < showScrollWhenHoverTheseElements.length; i++) {
            ['mouseenter', 'focus', 'hover'].forEach((event) => {
              showScrollWhenHoverTheseElements[i].addEventListener(
                      event,
                      function () {
                        previous.classList.add('show');
                        next.classList.add('show');
                      }
              );
            });
          }

          // If the user leaves the scrollable area, hide the scroll
          for (let i = 0; i < hideScrollWhenHoverTheseElements.length; i++) {
            ['mouseenter', 'focus', 'hover'].forEach((event) => {
              hideScrollWhenHoverTheseElements[i].addEventListener(
                      event,
                      function () {
                        previous.classList.remove('show');
                        next.classList.remove('show');
                      }
              );
            });
          }

          ['click', 'focus'].forEach((event) => {
            previous.addEventListener(event, function () {
              // Scroll can't go beyond it's bounds, so don't need to do checks here (once it hits zero, it won't go lower)
              container.scrollLeft -= 100;
            });

            next.addEventListener(event, function () {
              container.scrollLeft += 100;
            });
          });
        };
      }
    }
  }
})(jQuery, Drupal);
