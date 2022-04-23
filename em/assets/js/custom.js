/* custom js*/
jQuery(document).ready(function($){

  'use strict';

  /*function join_us () {
      var parentwidth = $(".main-container>.row>.col-sm-2").width();      
      jQuery("#block-asktheeyedoctor").width(parentwidth);   
             
  }
  function join_us_arabic () {
      var parentwidth = $(".arabic-text>.row>.col-sm-2").width();      
      jQuery("#block-asaldsamyrzq").width(parentwidth);        
  }
  join_us();
  join_us_arabic();*/


  /*var baseUrl = document.location.origin;
  var baseUrlarabic=baseUrl+'/ar';
  $("#block-bravo-ta-main-menu li.last a").prop("href", baseUrlarabic);
  $("#block-mainmenuarabic-2  ul li.first a").prop("href", baseUrl);
  $("#block-mainmenuarabic-2  ul li.last a").prop("href", baseUrlarabic);*/

  /*sethomepageColumnsHeights('.article-element');
  sethomepageColumnsHeights('.question-element');
  sethomepageColumnsHeights('.taxonomy-term-element');*/


  hide_textarea('#edit-field-pre-existing-illness-expla-wrapper');
  hide_textarea('#edit-field-surgery-explanation-wrapper');
  hide_textarea('#edit-field-eyedrops-explanation-wrapper');
  hide_textarea('#edit-field-lens-glasses-explanation-wrapper');
  hide_textarea('#edit-field-previous-disease-explanati-wrapper');


  check_textarea('#edit-field-suffer-pre-existing-in-eye','#edit-field-pre-existing-illness-expla-wrapper');
  check_textarea('#edit-field-perform-any-surgery-eyes','#edit-field-surgery-explanation-wrapper');
  check_textarea('#edit-field-do-you-use-any-eye-drops','#edit-field-eyedrops-explanation-wrapper');
  check_textarea('#edit-field-you-wear-lenses-or-glasses','#edit-field-lens-glasses-explanation-wrapper');
  check_textarea('#edit-field-do-you-suffer-from-any-dis','#edit-field-previous-disease-explanati-wrapper');


});
function sethomepageColumnsHeights(elementClass){
  console.log("elementclass = " + elementClass );
  var mh = 0;
  jQuery(elementClass).each(function(){
      if(mh < jQuery(this).height() ){
        mh = jQuery(this).height();
      }
  });

  jQuery(elementClass).each(function(){
      jQuery(this).height(mh);
  });
}	


function hide_textarea(elementClass){
  jQuery(elementClass).hide();
}
 
  
function check_textarea(elementClass1,elementClass2){
  jQuery(elementClass1).change(function() {
    if (jQuery(this).val() == 'Yes') {
        jQuery(elementClass2).show("slow","swing");
    }
    else
        jQuery(elementClass2).hide("fast","swing");
  });
 
}


/*
(function ($) {

  Drupal.behaviors.showModalBootstrap = {
    attach: function(context, settings) {
       //show status messages in a dialog.
		if(jQuery('#bravo_status_message').length){
			jQuery('#bravo_status_message').modal('show');
		}

		 $("#bravo_status_message").on('hidden.bs.modal', function(){
    		$(this).remove();
  		});
    }
  };


  

})(jQuery);

*/

