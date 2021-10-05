console.log('loads');
(function ($) {
  jQuery(function () {
    'use strict';
    let element;
    
    
    $('button.uds-tooltip').on('click', (_this, e) => {
      if (element?.is(':focus')) element.trigger('blur');
      element = element
        ? undefined
        : $(
            `button[aria-describedby=${$(_this)
              .get(0)
              .currentTarget.getAttribute('aria-describedby')}]`
          );
    });
    $('button.uds-tooltip').on('blur', () => {
      setTimeout(() => (element = undefined));
    });
  });
}(jQuery));