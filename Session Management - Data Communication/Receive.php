<div id="cover"></div>
<div id="phpout">

<!-- This php script fetches the value entered by the user in the input form in index.php, checks whether the 
	 user has entered any values and opens the users session page on user request -->
<?php
$uname = $_POST['uname'];   //Username of the user from the form
$fname = $_POST['fname']; 	//First Name
$lname = $_POST['lname']; 	//LAst Name


// Checking whether the user has entered any value or not 

if(!$lname||!$uname||!$lname)
{
	//If no value if entered the session will end after giving alert to the user.
	
	echo"<script>alert(\"Invalid User : Enter Valid Values\")</script>";
	echo"<br/><div id=\"again\"><a href=\"./index.php\">Login Again</a></div>";
	exit(0);

}
else if ($uname == "admin" || $uname == "Admin" || $uname == "ADMIN")
{
	echo "Use Administrator login option for accessing the administrator permissions <br/>";
	exit (0);
}


//Else the user id welcomed and the session is stored in the file under the username (which is a unique key).and is stored in a file .


//Time of User Login
	date_default_timezone_set("Asia/Calcutta");
	$var = date('d-m-y')." ".date ('H:m:s');
	echo "<div id=\"welcome\"> Hi, $fname <br/> $var </div>";
	
$filename = $uname.".htm";
$file_contents = $var."  ".$uname."	".$fname." ".$lname."<br/>";
$fptr = fopen("database/$filename","a");   //File Data of the user accesible only to the user;
fwrite($fptr,"$file_contents");
fclose($fptr);
$ptr2 = fopen("admin-files/admin.htm","a"); //Data Accesibe only to admin; 
fwrite($ptr2,"$file_contents");
fclose($ptr2);





?> 
<!-- Reading Files of DataBase for the Specified User-->

<div id="session"> 
<p align="center">SESSION</p> <hr/>
<div class="session">
<?php

//Reading the user session from the file of the user.

$ptr3 = fopen("database/$filename","r");
$read = fread($ptr3,999999);
echo "$read";

?>
</div>
</div>
<div class="close_session" >CLOSE</div>
</div>

<link href="css/new.css" type="text/css" rel="stylesheet"/>

<div id="rssnew">
<img id="close" src="images/close.png">

<!-- Fetching RSS NEWS FEEDS -->
<!-- The RSS content is stored in a file.
	 	The content of the file is printed in a formatted way using the title tags and link tags	 -->
<?php
$url = "http://news.google.com/?output=rss";
//$rss = fopen("http://news.google.com/?output=rss","r");
//$text = fread($rss);
//fclose($rss);

//echo $text;

//Reading RSS text from the web file.
$rss = simplexml_load_file($url);


if($rss)
{
	//Displaying the formatted contents.
	
	echo '<div id="ID"><h1>'.$rss->channel->title.'</h1></div>';	
	echo '<li id="link">'.$rss->channel->pubDate.'</li>';
	$items = $rss->channel->item;
	foreach($items as $item)
	{
		$title = "<p id=\"title_style\">".$item->title."</p>";
		$link = $item->link;
		$published_on = $item->pubDate;
		$description = $item->description;

		echo '<h3 id="title"><a href="'.$link.'">'.$title.'</a></h3>';
		echo '<span>('.$published_on.')</span>';
		echo '<p id="news">'.$description.'</p>';
	}
}

?>
</div>



</div>

<!-- HTML Content of the page -->

<html>
<head>
<link rel="stylesheet" href="css/style.css" type="text/css" />
</head>
<title>Welcome Page</title>
<body>
<div id="header">Session Management On the Web : Innovative Assignment for DATA COMMUNICATION (2CE223)</div>
<div id="footer">Project Submitted By Darshil Patel (11BCE070) and Rohit S Nair (11BCE081)</div>
</body>
<script type="text/javascript"  src="js/jQuery-1.9.1.js">
</script>

<script type="text/javascript"  src="js/fancy.js">
</script>


<a><img id="newsicon" src="images/news.png" /></a>
<div id="session_button" >SEE YOUR SESSION</div>
<a href="index.php"><div id="logout" >LOGOUT</div></a>

</html>


