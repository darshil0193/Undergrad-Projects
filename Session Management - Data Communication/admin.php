<link rel="stylesheet" href="css/style.css" type="text/css" />
<link href="css/new.css" type="text/css" rel="stylesheet"/>

<?php
//Password Validation from the password stored in the file.

$password = $_POST['password'];
$temp = fopen("admin-files/pass.pass","r");
$pass = fread($temp,20);
//And viewing the session of all the files from the file admin-files/admin.htm.

if($password != $pass)
	{
		//Returns error if the password do not match.
		echo"<div id=\"back\" ></div>";
		echo"<script>alert(\"Incorrect Password\")</script>";
		echo"<div id=\"back\" ></div>";		
		echo"<div style=\"width:100%; text-align:center;  margin-top:100px;\"><a id= \"linktoindex\" style=\"color:#000; text-decoration:none; font-size:30px; font-family:verdana;  \" href=\"index.php\"> CLICK HERE TO LOGIN AGAIN </a></div>";
		
		
		exit(0);
		
		
		
	}
	

	
?>

<div id="cover"></div>
<div class="adminsession">
<p align="center" style="color:#666;">USER SESSION</p> <hr/>
<div id="file">
<?php
$fileadmin = fopen("admin-files/admin.htm","r");

//Readin contents from admin-files/admin.htm

$content = fread($fileadmin,999999);
echo $content;





?>



</div>
<hr/>
</div>

<!--Changing the password
	1. Reading the password (OLD) form the user.
    2. Reading the new password from the user.
    3. Validating the password entered from the password stored in the file.
    4. Updating the password in the file if all conditions are satisfied.
     -->
<button style="font-size:10px;" id="button_close" >CLOSE</button>
<div id="changepass">
<img id="change" width="20px;" src="images/metro_back.png"/>
<div class="changepass">

<form action="./passchange.php" method="post"> 
Enter the Old password<br/><input type="password" name="passold" />
<br/>
Enter the New password<br/><input type="password" name="passnew"/>
<br/>
Confirm New Password<br/><input type="password" name="passconf"/>
<br/><input style="font-size:8px;" type="submit" value="Submit" />
</form>
</div>
</div>
<!--<div id="clear">
<form action="admin.php">
<input type="submit" value="Clear Session"  /></form>
</div>
-->
<html>
<head>
<title>Administrator Page</title>
<link rel="stylesheet" href="css/style.css" type="text/css" />
<link href="css/new.css" type="text/css" rel="stylesheet"/>
<body>

<div id="header">Session Management On the Web : Innovative Assignment for DATA COMMUNICATION (2CE223)</div>
<div id="view">
VIEW USER SESSION
</div>
<div class="adminpass">
CHANGE THE ADMINISTRATOR PASSWORD
</div>


<script type="text/javascript"  src="js/jQuery-1.9.1.js">
</script>

<script type="text/javascript"  src="js/fancy.js">
</script>
<div id="footer">Project Submitted By Darshil Patel (11BCE070) and Rohit S Nair (11BCE081)</div>


</body>
</head>

</html>
