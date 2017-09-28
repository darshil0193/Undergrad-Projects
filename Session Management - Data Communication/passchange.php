
<?php
//This script accepts the user input from the page admin.php and validates and then updates the password to the file.

$temp = fopen("admin-files/pass.pass","r"); //Fectching the password from the file.
$pass = fread($temp,20);

$passold = $_POST['passold'];
$passnew = $_POST['passnew'];
$passconf = $_POST['passconf'];

//Checking whether the entered passowrd is same as that in the file?

if($passold ==  $pass)
{
		if($passnew == $passconf)
		{
			//Checking whether the new password entered is same as the confirmation entered?
			
			$ptrtemp = fopen("admin-files/pass.pass","w");
			//Writing the new password to the file pass.pass
			fwrite($ptrtemp,$passnew);
			//Success message in the form of an alert script.
			echo"<script>alert(\"Password Changed Successfully\")</script>";
			
		}

		else
		{
		//If the entered value does not match with the value in the file. An error is generated.
		echo"<script>alert(\"New Password do not match\")</script>";
		echo"<div id =\"pass\" align=\"center\"><a href=\"admin.php\"><img src=\"images/metro_back.png\" /></a></div>";
		exit(0);
		
		}
}
else
{
echo"<script>alert(\"Old Password is Incorrect\")</script>";
exit(0);
}
?>
<div style="texta">
<a style="font-zize:20px;"  align="center" href="index.php" ><img width"50px;" src="images/metro_back.png"/><br/></a></div>

