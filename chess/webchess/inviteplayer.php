<?php
	// $Id: inviteplayer.php,v 1.5 2010/08/14 16:57:54 sandking Exp $

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

	/* neededfor fixOldPHPVersions() below */
	require 'chessutils.php';

	/* allow WebChess to be run on PHP systems < 4.1.0, using old http vars */
	fixOldPHPVersions();
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
   "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1" />
<link rel="stylesheet" href="mainmenu.css" type="text/css" />
<title>WebChess :: Invite Player</title>

	<script type="text/javascript">
		function getObject(obj) {
		  if (document.getElementById) {  // Mozilla, FireFox, Explorer 5+, Opera 5+, Konqueror, Safari, iCab, Ice, OmniWeb 4.5
			if (typeof obj == "string") {
			  if(document.getElementById(obj)) {
				return document.getElementById(obj);
			  } else {
				return document.getElementsByName(obj)[0];
			  }
			} else {
			  return obj.style;
			}
		  }
		  if (document.all) {				// Explorer 4+, Opera 6+, iCab, Ice, Omniweb 4.2-
			if (typeof obj == "string") {
			  return document.all(obj);
			} else {
			  return obj.style;
			}
		  }
		  if (document.layers) {			// Netscape 4, Ice, Escape, Omniweb 4.2-
			if (typeof obj == "string") {
			  return document.layers(obj);
			} else {
			  return obj.style;
			}
		  }
		  return null;
		}

	function challenge() {
		window.location = 'inviteplayer.php';
	}

	function reload() {
		window.location.replace(window.location.href);
	}

	function logout() {
		window.location.replace('index.php');
	}

	function show(s) {
		hide();
		var id = s.hash.substring(1);
		getObject(id).style.display = 'block';
	}

	function hide() {
		var toggle = getObject('navlist');
		var as = toggle.getElementsByTagName('a');
		for (var i = 0; i < as.length; i++) {
			var id = as[i].hash.substring(1);
			var obj = getObject(id);
			if(obj) {
				getObject(id).style.display = 'none';
			}
		}
	}

	window.onload = function() {
		var toggle = getObject('navlist');
		var as = toggle.getElementsByTagName('a');
		for (var i = 0; i < as.length; i++) {
			var id = as[i].hash.substring(1);
			if(getObject(id)) {	// If there is a corresponding element to show/hide
				as[i].onclick = function() {
					show(this);
					return false;
				}
			} else if (as[i].hash == '#challenge') {
				as[i].onclick = challenge;
			} else if (as[i].hash == '#reload') {
				as[i].onclick = reload;
			} else if (as[i].hash == '#logout') {
				as[i].onclick = logout;
			}
		}
		show(as[0]);
	}
	</script>
</head>

<body>
	<div id="header">
	  <div id="heading">WebChess :: Invite a player to play a new game</div>
	</div>
<div id="content">
<div id="navcontainer">
<ul id="navlist">
<li><a href="#continuegame">Active games</a></li>
<li><a href="#challenge">Challenge others</a></li>
<li><a href="#invitations">Pending challenges</a></li>
<li><a href="#viewgame">Replay</a></li>
<li><a href="#preferences">Preferences</a></li>
<li><a href="#personalinfo">Personal</a></li>
<li><a href="#reload">Reload</a></li>
<li><a href="#logout">Logout</a></li>
</ul>
</div>
<div id="rightcolumn">
<div id="personalinfo">
	<div id="ctr" align="center">
		<div class="preferences">
			<div class="preferences-form">
				<form name="newchallenge" action="mainmenu.php" method="post">
				<div class="form-block">
					<h1>Issue a challenge</h1>
						<div class="inputlabel">Opponent</div>
						<select name="opponent">
						<?php
							/* connect to the database */
							require 'connectdb.php';
							$tmpQuery="SELECT playerID, nick FROM " . $CFG_TABLE[players] . " WHERE playerID <> ".$_SESSION['playerID'];
							$tmpPlayers = mysql_query($tmpQuery);
							while($tmpPlayer = mysql_fetch_array($tmpPlayers, MYSQL_ASSOC))
							{
								echo ('<option value="'.$tmpPlayer['playerID'].'"> '.$tmpPlayer['nick']."</option>\n");
							}
							mysql_close();
						?>
						</select>
						<div class="inputlabel">Your Color</div>
						<div class="inputbox">
							<div><input name="color" type="radio" value="random" checked="checked" /> Random</div>
							<div><input name="color" type="radio" value="white" /> White</div>
							<div><input name="color" type="radio" value="black" /> Black</div>
						</div>
						<input type="button" value="Invite" class="button" />
						<input type="button" value="Cancel" class="button" onClick="window.open('mainmenu.php', '_self')" />
						<input type="hidden" name="ToDo" value="InvitePlayer" />
				</div>
				</form>
			</div>
			<div class="login-text">
				<div class="ctr"><img src="images/webchess.jpg" width="65" height="92" alt="security" /></div>
				<p>Select an opponent and challenge him to a new game.</p>
				<p></p>
			</div>
			<div class="clr"></div>
		</div>
	</div>
</div>
</body>
</html>
