<?php

/*
    This file is part of WebChess. http://webchess.sourceforge.net
	Copyright 2010 Jonathan Evraire, Rodrigo Flores

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

session_start();

	/* check session status */
	require 'sessioncheck.php';
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">

<html>

	<head>
		<meta http-equiv="content-type" content="text/html;charset=iso-8859-1">
		<meta name="generator" content="Adobe GoLive 6">
		<title>Send Message</title>

<?php
	$lisega_light_blue="#0099FF";
	$lisega_medium_blue="#0000FD";
	$lisega_dark_blue="#18189C";
	$lisega_white="#BBC9FB";
	$real_white="#CCCCFF";


	$bg = $lisega_dark_blue;
	$menu = $lisega_dark_blue; 
	$blocks = $lisega_light_blue;
	$top = $lisega_medium_blue;
	$box = $lisega_medium_blue;
	$content = $real_white;

if (!isset($_CONFIG))
                require 'config.php';

require "connectdb.php";
$id=$_SESSION['playerID'];

if($_POST['newMessage'])
{
	echo("<PRE>");
	print_r($_POST);
	echo("</PRE>");
        $fromPerson=($_POST['from'])?$_POST['from']:"NULL";
        $toPerson=($_POST['to'])?$_POST['to']:"NULL";

	echo("From $fromPerson, To $toPerson<br>");

        if ( ($fromPerson!=NULL) && ($toPerson!=NULL) ) {
        $mGame=($_POST['forGame'])?$_POST['from']:"NULL";
        $msgtitle=$_POST['txtTitle'];
        $msgtext=$_POST['txtMessage'];
        if($_POST['msgType']=="Article")
                $msgtype="0";
        else
                $msgtype="0"; // Always 0... yet..

        $sql = "INSERT INTO " . $CFG_TABLE[communication] . " (gameID,fromID,toID,title,text,postDate,expireDate,ack,commType) ";
        $sql .= "VALUES ( $mGame , $fromPerson , $toPerson, '$msgtitle', '$msgtext', NOW( ) , NULL , '0', '$msgtype' );";
        mysql_query($sql) or die("can't do query: $sql");
?>
Message Sent!
<script language="javascript">
window.close()
</script>
<?php
die();
}
}

?>

	</head>

	<body bgcolor="#808080">
		<div align="center">
			<form action="" method="post" name="FormName">
				Message Recipient:<br>
				<input type="hidden" name="from" value="<?php echo $id; ?>">
				<select name="to" size="1">
<?php

					$tmpQuery="SELECT playerID, nick FROM " . $CFG_TABLE[players] . " WHERE playerID <> ".$id." ORDER BY nick ASC";
	                                $tmpPlayers = mysql_query($tmpQuery) or die("Sorry: $tmpQuery");
                                        while($tmpPlayer = mysql_fetch_array($tmpPlayers, MYSQL_ASSOC))
                                        {
                                                if ($tmpPlayer['nick']){
						if($tmpPlayer['playerID']==$_GET['to'])
        	                                        echo("<option value='".$tmpPlayer['playerID']."' selected> ".$tmpPlayer['nick']."</option>\n");
						else
                	                                echo("<option value='".$tmpPlayer['playerID']."'> ".$tmpPlayer['nick']."</option>\n");
						}
                                        }

?>				
				</select><br>
				<br>
				Message Subject:<br>
				<input type="text" name="txtTitle" size="54" border="0"><br>
				<br>
				Message Text:<br>
				<textarea name="txtMessage" rows="10" cols="52" tabindex="1"></textarea><br><br>
				<input type="submit" name="newMessage" value="Send Message" border="0"> 
				<input type="button" name="btnCancel" value="Cancel" border="0" onClick="javascript:window.close();"><br>
			</form>
		</div>
	</body>

</html>
