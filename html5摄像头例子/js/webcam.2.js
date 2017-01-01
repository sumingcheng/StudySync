(function(Neave) {
  
  var isMobile = $('body').hasClass('mobile'),
    hasHTML5;
  
  Neave.createApp = function() {
    $('#button-access').buttonClick(function() {
      WebcamToy.init();
    });
    document.title = 'HTML5 Webcam Toy';
  };
  
  $(document).ready(function() {
    if (Neave.isIE6) {
      return;
    }
    
    if (location.search === '?flash') {
      location.href = '/webcam/app/';
      return;
    }
    
    hasHTML5 = Neave.hasWebGL && WebcamToy.Camera.hasGetUserMedia;
    
    if (hasHTML5) {
      $('#toy').show();
      if (isMobile) {
        $('#info').hide();
      }
      WebcamToy.UI.loadImages();
    } else {
      $('#info .text').show();
    }
    
    if (!Neave.isOpera) {
      //WebcamToy.Services.facebookInit();
    }
    
    if (!isMobile) {
      $('#info').click(function(e) {
        if (!e.target.href) {
          $('#info .text').toggle();
        }
      });
    }
    
    Neave.createApp();
  });
  
}(Neave));
