$(document).ready(function(){
	var div_height = $('#fancy_box').height();
	var div_width = $('#fancy_box').width();
	var window_height = $(window).height();
	var window_width = $(window).width();
	var document_height = $(document).height();
	var document_width = $(document).width();
	
	$('#fancy_box').css('left',(window_width/2)-(div_width/2));
	$('#fancy_box').css('top',(window_height/2)-(div_height/2));
	$('#cover').css('width',document_width).css('height',document_height); 
	
	$('#button').click(function(){
		$('#cover').fadeIn('slow');
		$('#fancy_box').fadeIn('slow');
	});
	
	$('#cover').click(function(){
		$('#cover').fadeOut('slow');
		$('#fancy_box').fadeOut('slow');
	});
});