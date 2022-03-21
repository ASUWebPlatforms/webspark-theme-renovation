(function ($, Drupal) {
    Drupal.behaviors.asugtm = {
      attach: function (context, settings) {
        $('.page__content')
          .once('page')
          .each(function () {
            const pushGAEvent = (args) => {
              const { dataLayer } = window;
              const event = {
                ...args,
              };
              if (dataLayer) dataLayer.push(event);
            };
  
            const elements = document.querySelectorAll('[data-ga-text]');
            elements.forEach((element) =>
              element.addEventListener('click', () => {
                const args = {
                  event: element.getAttribute('data-ga-event').toLowerCase(),  
                  action: element.getAttribute('data-ga-action').toLowerCase(),
                  name: element.getAttribute('data-ga-name').toLowerCase(),
                  type: element.getAttribute('data-ga-type').toLowerCase(),
                  region: element.getAttribute('data-ga-region').toLowerCase(),
                  section: element.getAttribute('data-ga-section').toLowerCase(),
                  text: element.getAttribute('data-ga-text').toLowerCase(),
                  component: element.getAttribute('data-ga-component').toLowerCase(),
                };
              pushGAEvent(args);
            })
          );
        }
      );
    }
  }
}(jQuery, Drupal));