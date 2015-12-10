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

	$_CONFIG = true;

	/* database settings */
	$CFG_SERVER = "localhost";
	$CFG_USER = "WebChessUser";
	$CFG_PASSWORD = "WebChessPassword";
	$CFG_DATABASE = "WebChess_DB";

	/* server settings */
	$CFG_SESSIONTIMEOUT = 900;		/* session times out if user doesn't interact after 900 secs (15 mins) */
	$CFG_EXPIREGAME = 14;			/* number of days before untouched games expire */
	$CFG_MINAUTORELOAD = 5;			/* min number of secs between automatic reloads reloads */
						/* email notification requires PHP to be properly configured for */
	/* NOTE: in chessutils.php a line is commented containing:
	$headers .= "To: ".$msgTo."\r\n";
	Some MTAs may require for you to uncomment such line. Do so if mail notification doesn't work */
	$CFG_USEEMAILNOTIFICATION = false;	/* SMTP operations.  This flag allows you to easily activate
						   or deactivate this feature.  It is highly recommended you test
						   it before putting it into production */
						/* email address people see when receiving WebChess generated mail */
	$CFG_MAILADDRESS = "WebChess@webchess.org";
	/* This URL is displayed in the email notices */
	$CFG_MAINPAGE = "http://webchess.sourceforge.net/webchess/";

	$CFG_MAXUSERS = 50;
	$CFG_MAXACTIVEGAMES = 50;
	$CFG_NICKCHANGEALLOWED = false;		/* whether a user can change their nick from the main menu */

	$CFG_NEW_USERS_ALLOWED = true;

	/* mysql table names
	   Change these if your database needs different table names */
	$CFG_TABLE[communication] = "communication";
	$CFG_TABLE[games] = "games";
	$CFG_TABLE[history] = "history";
	$CFG_TABLE[messages] = "messages";
	$CFG_TABLE[pieces] = "pieces";
	$CFG_TABLE[players] = "players";
	$CFG_TABLE[preferences] = "preferences";

	/* theme settings */
	$CFG_BOARDSQUARESIZE = 50; /* May be used to resize board size */
	$CFG_IMAGE_EXT = "png";
?>
