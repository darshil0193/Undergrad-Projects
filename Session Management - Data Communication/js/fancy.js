$(document).ready(function(){
	
	//Initialising the variables with the values.
		
	var div_height = $('#fancy_box').height();  //Assigning the value of division height to the variable
	var div_width = $('#fancy_box').width();    //Assigning the value of division width to the variable
	var window_height = $(window).height(); 	//Assigning the value of window height to the variable
	var window_width = $(window).width();		//Assigning the value of window width to the variable
	var document_height = $(document).height();	//Assigning the value of the document height to the variable
	var document_width = $(document).width();	//Assigning the value of the document width to the variable
	
   // var login_width = $('#login_button').width();
	var session_height = $('#session').height(); 	//Assigning the value of the session window height to the variable
	var session_width = $('#session').width();		//Assigning the value of the session window width to the variable
	var admin_width = $('#admin_login').width();	//Assigning the value of the division height to the variable
	var admin_height = $('#admin_login').height();	//Assigning the value of the division width to the variable
	var session_admin_wd = $('.adminsession').width();   //Assigning the value of the division width to the variable
	var session_admin_ht = $('.adminsession').height(); 	//Assigning the value of the division height to the variable
	
	//Placing the fancy box in the centre of the window.
	
	$('#fancy_box').css('left',(window_width/2)-(div_width/2)); 
	$('#fancy_box').css('top',(window_height/2)-(div_height/2));
	
	//Placing the cover in the centre of the window.
	
	$('#cover').css('width',document_width).css('height',document_height); 
	//$('#login_button').css('width',login_width); 

	//Placing the session box to the centre of the window.
		
	$('#session').css('left',(window_width/2)-(session_width/2));
	//$('#session').css('top',(window_height/2)-(session_height/2));
	$('#admin_login').css('left',(window_width/2)-(admin_width/2));
	$('#admin_login').css('top',(window_height/2)-(admin_height/2));
	
	$('.adminsession').css('left',(window_width/2)-(session_admin_wd/2));
			
	//Appearance setting for the login_button (On click)
	$('#login_button').click(function(){
		$('#cover').fadeIn('slow'); //Fade In animation to the cover.
		$('#fancy_box').fadeIn('slow'); //Fade In animation to the Fancy Box.
	});
	
	//Appearance setting for the close button. (On click)
	
	$('#close').click(function(){
		$('#cover').fadeOut('slow');
		$('#fancy_box').fadeOut('slow');
	});
	
	//Appearance setting for the news_icon (On click)
	
	$('#newsicon').click(function(){
		$('#rssnew').fadeIn();
		$('#session_button').fadeOut();
	});
	
	//Appearance setting for the Rss Window. (On click)
	
	$('#rssnew').click(function(){
		$('#rssnew').fadeOut();
		$('#session_button').fadeIn();
	});
	
	//Appearance setting for the view session button. (On click)
	
	$('#session_button').click(function(){
		$('#session').fadeIn('2');
		$('.close_session').fadeIn();
		//$('#cover').fadeIn();
		$('#newsicon').fadeOut();
		$('#session_button').fadeOut();
		$('#changepass').fadeOut();
		$('#rssnew').fadeOut();
		$('#logout').fadeOut();
		
		
	});
	
	//Appearance setting for the close session. (On click)
	
	$('#close_session').click(function(){
		$('#session').fadeOut('');
		
	});
	
	//Appearance setting for the admin login button (On click)
	
	$('#admin_button').click(function(){
		$('#fancy_box').fadeOut('slow');
		$('#admin_login').fadeIn('slow');
		
	});
	
	//Appearance setting for the admin close session button (On click)
	
	$('#admin_close').click(function(){
		$('#fancy_box').fadeIn('slow');
		$('#admin_login').fadeOut('slow');
		
	});
	
	//Appearance setting for the view session button (On click)
		
	$('#view').click(function(){
		$('.adminsession').fadeIn('slow');
		$('#button_close').fadeIn('slow');
		$('#cover').fadeIn();
		$('#view').fadeOut();
		$('.adminpass').fadeOut();
	});
	
	//Appearance setting for the close session view (On click)	
		
	$('#button_close').click(function(){
		$('.adminsession').fadeOut();
		$('#button_close').fadeOut('slow');
		$('#view').fadeIn();
		$('.adminpass').fadeIn();
		
	});
	
	//Appearance setting for the close session view for the Recieve.php page.(On click)
			
	$('.close_session').click(function(){
		$('#session').fadeOut();
		$('.close_session').fadeOut();
		//$('#cover').fadeOut();
		$('#newsicon').fadeIn();
		$('#session_button').fadeIn();
		$('#rssnew').fadeOut();
		$('#logout').fadeIn();
		
		
	});
	
	$('.adminpass').click(function(){
		$('#changepass').fadeIn();
	});
	
	$('#change').click(function(){
		$('#changepass').fadeOut();
	});
						
});


//function close.
//The parameters passes are either the class or the id of the divisions or the buttons used which is used to uniquely identify the parameters and hence apply the style and animation to it.
