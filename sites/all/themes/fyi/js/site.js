(function($){
  
  Drupal.behaviors.FYI = {
    attach: function(context) {
      
      $('input.clickClear').focus(function() {
         startText = $(this).val();
         $(this).val('').addClass('focus');
      });
      $('input.clickClear').blur(function() {
         blurText = $(this).val();
         if (blurText == '') {
            $(this).val(startText).removeClass('focus');
         };
      });
      
      $("#fyi_email input#first_name").attr("value", "First Name");
      $("#fyi_email input#last_name").attr("value", "Last Name");
      $("#fyi_email input#email-Primary").attr("value", "email");

      $(".media-gallery-collection article:odd").after("<hr class='clear' />");

    }
    
  }
  
  
})(jQuery)
