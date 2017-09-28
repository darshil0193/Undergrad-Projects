<!--This page accepts the use input and validates the input upon the entered and hence transfers the input values to the page Recieve.php -->


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
<title>Innovative Assignment DC</title>
<!-- Including the stylesheet which defines the color, font-size, font and other graphical attributes of the divisions and links used in the CODE. -->
<link rel = "stylesheet" type = "text/css" href ="css/style.css" >
</head>

<body>

<!-- Laying Out the basic structure of the display view -->

<a ><div id="login_button" >LOGIN</div></a> <!-- Setting the login button -->
<div id="header">Session Management On the Web : Innovative Assignment for DATA COMMUNICATION (2CE223)</div>
<div id="cover"></div>
<img id="bgone" width="720"  src="images/DC.jpg"  /> <!-- Displaying the background image -->
<div id="footer">Project Submitted By Darshil Patel (11BCE070) and Rohit S Nair (11BCE081)</div>

<div id="cover"></div>

<div id="fancy_box"> <!-- calling the fancy box (login - box) -->

<div id="Header">
LOGIN PAGE<hr/><br/>
</div>
<!--  Login Form Code || PHP and HTML based -->

<div id="form">


<!-- Setting the input values and the input type  -->
<form method = "POST" action = "./Receive.php" > <!-- The values obtained from the input boxes are sent to the file Recieve.php using the method Post -->

<!-- Post method is used to preserve user security -->

    	<label>Username*<br/></label>
        <input type = "text" name = "uname" maxlength="20" style="width:200px;"/> <!-- Input box to accept input -->
         <br/>
       
        <label>First Name*<br/></label>
        <input type = "text" name = "fname" maxlength="20" style="width:200px;"/> <!-- Input box to accept the first name of the user -->
        
        <br/>
               
        <label>Last Name*<br/> </label>
        <input type = "text" name = "lname" max="40" style="width:200px;"/> <!-- Input box to accept the last name from the user -->
        <br/><br/>
        <input type = "submit" name = "submit" wifth = "40px" value = "Enter"  /> <!-- Submit Button,On clicking the submit button, the values are sent to the file Recieve.php for further validation and processing  -->
        </hr>
        
		
		
     </form>
     <!-- Form Closed -->
     
     <div id="text"><br/>Fields marked with * are compulsory <br/><br/><br/>
     <p class="admin"> <button id ="admin_button" style="font-size : 11px;">Click Here for Administrator Login</button>  </p></div>
 <div id="image_box">
 <img src="images/DC.png"/> 
 
 </div>
 
 
 
  
<a href=""><div id="close"><img id="close" src="images/close.png" /><p class ="close">Close</p></div></a>

</div>



</div>	

<!-- Administrator Login -->
<!-- Defining the form for Administrator login containing the admin -password -->
<div id="admin_login">
ADMIN LOGIN
<form action="./admin.php" method="post" > <!-- The values here are sent to a different page admin.php where the password entered is validates with the password in the file. -->

<label ><hr/><p style="font-size:9px">PASSWORD*</label>
<input type="password" name="password" maxlength="20" style="width :222px;"  /> <br/>
<input type="submit" value="Submit" /> 

</form>



<div id="admin_close"><img width="20px;" src="images/metro_back.png"/></div>
</div>

<!-- calling the javascript file to use jQuery functions  -->

<script type="text/javascript"  src="js/jQuery-1.9.1.js">
</script>

<script type="text/javascript"  src="js/fancy.js">
</script>

<div id = "info">
</div>


</body>

</html>