(function ($, Drupal) {

  'use strict';
  
  Drupal.behaviors.resizeRemoteVideoCaption = {
    attach: function (context) {
      document.querySelectorAll('figure').forEach((fig) => {
        if (fig.querySelector('iframe')) {
          // Set the figure to 100% width.
          fig.style.width ='100%';
          
          // Make the caption as wide as the video.
          var caption = fig.querySelector(':scope > figcaption');
          if (caption) {
            var newHTML = '<div class="container"><div class="row justify-content-center"><div class="col-12 col-md-10 col-lg-12"><div class="uds-video-container">' + caption.outerHTML + '</div></div></div></div>';
            caption.outerHTML = newHTML;
          }
          
          fig.querySelectorAll('.uds-video-container').forEach((div) => {
            if (div.querySelector('iframe')) {
              div.style.marginBottom = '0';
//              div.style.borderBottom = 'none';
            }
            else {
              div.style.marginTop = '0';
            }
          });
        }
      });
    }
  };

})(jQuery, Drupal);
