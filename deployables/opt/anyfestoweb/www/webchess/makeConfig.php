<?php
// $Id: makeConfig.php,v 1.1 2010/08/23 02:53:46 sandking Exp $

/*
    This file is part of WebChess. http://webchess.sourceforge.net
	Copyright 2010 Jonathan Evraire, Rodrigo Flores, rigao

    WebChess is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    WebChess is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with WebChess.  If not, see <http://www.gnu.org/licenses/>.
*/

//This file is called by install.php (case 3 of the switch, before it ends the installation
//procedure. It has two functions: first, to create a new user if told so. Second,
//to make the config.php file and put it for download.

//This function creates the user that will interact with the database.
//Normally it would be expected for this file to be located in install.php
//but coding the installer has yeld to the conclusion that it is easier to put it
//right here.
function createUser($new_user,$new_password,$user,$password,$server,$DBname){
   $dbh=mysql_connect ($server, $user, $password)
           or die ('WebChess cannot connect to the database.
              Please check the database settings you provided.<br>');
   mysql_select_db ($DBname);

   $query="GRANT SELECT, INSERT, UPDATE, DELETE ON ".$DBname.".* TO ".$new_user." IDENTIFIED BY '".$new_password."';";
   $result= mysql_query($query);
   mysql_query("quit");
   return $result;
}

/* debug flag */
define ("DEBUG", 0);

header('Cache-Control: no-store, no-cache, must-revalidate'); // HTTP 1.1
header('Cache-Control: pre-check=0, post-check=0, max-age=0'); // HTTP 1.1
header('Pragma: no-cache'); // HTTP 1.0
header('Expires: Mon, 26 Jul 1997 05:00:00 GMT');
header('Content-Transfer-Encoding: none');
header('Content-Type: text/php; name="config.php"');
header('Content-Disposition: attachment; filename="config.php');
// header("Content-length: $content_len");
//We see if the administrator has provided a new user to be used. If it is so
//(FALSE case) we will create the new user, if it is not (TRUE case) we won't
//create any user.
if ($_POST['reuse']=='true')
{
   //In case we reuse, there is no need to create the new username.
   $user=$_POST['user_last'];
   $pass=$_POST['pass_last'];
   $new_user=$_POST['user_last'];
   $new_pass=$_POST['pass_last'];
} else {
   //We would need to create a new user.
   $new_user=$_POST['user'];
   $new_pass=$_POST['pass'];
   $user=$_POST['user_last'];
   $pass=$_POST['pass_last'];

   $result=createUser($new_user,$new_pass,$user,$pass,$_POST['server'],$_POST['DBname']);
   /*
    * This code is called to make config.php. There is no way to write a warning code
    * as it will be in the config.php. What we will do is post it as commented php
    * code insider config.php if there is an error. It is not perfect, but it is
    * the only solution I find.
    */
   if ($result==true)
   {
      //No need to mess with config.php if everything has gone allright.
      //echo "New user created correctly<br>";
   } else {
      //We write this sentence in config.php. There must be a FAQ entry to explain it.
      echo "/* There was a <b><u>problem</u></b> and the new user was not created */\n";
   }
}

//Here we start the second part. We start to generate config.php.
echo "<?php";
echo "\$_CONFIG=true;\n\n";

echo "/* database settings */\n";
echo "\$CFG_SERVER = '".$_POST['server']."';\n";
echo "\$CFG_USER = '".$new_user."';\n";
echo "\$CFG_PASSWORD = '".$new_pass."';\n";
echo "\$CFG_DATABASE = '".$_POST['DBname']."';\n";
echo "\n/* server settings */\n";

echo "\$CFG_SESSIONTIMEOUT = ".$_POST['timeout'].";\n";
echo "\$CFG_EXPIREGAME = ".$_POST['expire'].";\n";
echo "\$CFG_MINAUTORELOAD = ".$_POST['autoreload'].";\n";


echo "\$CFG_USEEMAILNOTIFICATION = ";
if ($_POST['mail_not']=='1')
   echo "TRUE;\n";
else echo "FALSE;\n";

echo "\$CFG_MAILADRESS = '".$_POST['mail_adr']."';\n";

echo "\$CFG_MAINPAGE = '".$_POST['url']."';\n";
echo "\$CFG_MAXUSERS = ".$_POST['maxUsers'].";\n";
echo "\$CFG_MAXACTIVEGAMES = ".$_POST['maxGames'].";\n";
echo "\$CFG_NICKCHANGEALLOWED = ";
if ($_POST['changeNick']=='1')
   echo "TRUE;\n";
else echo "FALSE;\n";

echo "\$CFG_NEW_USERS_ALLOWED = ";
if ($_POST['newUsers']=='1')
   echo "TRUE;\n";
else echo "FALSE;\n";

echo "\$CFG_BOARDSQUARESIZE = ".$_POST['size'].";\n";

?>
/* mysql table names */
$CFG_TABLE[communication] = "communication";
$CFG_TABLE[games] = "games";
$CFG_TABLE[history] = "history";
$CFG_TABLE[messages] = "messages";
$CFG_TABLE[pieces] = "pieces";
$CFG_TABLE[players] = "players";
$CFG_TABLE[preferences] = "preferences";

<?
echo "\$CFG_IMAGE_EXT = '".$_POST['imageExtension']."';\n";
echo "?>";
?>
