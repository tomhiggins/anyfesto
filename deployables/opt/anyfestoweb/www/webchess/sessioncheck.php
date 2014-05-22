<?php
	// $Id: sessioncheck.php,v 1.6 2010/08/15 00:29:04 sandking Exp $

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

	/* load settings */
	if (!isset($_CONFIG))
		require 'config.php';

	if (!isset($_SESSION['playerID']))
		$_SESSION['playerID'] = -1;

	if ($_SESSION['playerID'] != -1)
	{
		if (time() - $_SESSION['lastInputTime'] >= $CFG_SESSIONTIMEOUT)
			$_SESSION['playerID'] = -1;
		else if (!isset($_GET['autoreload']))
			$_SESSION['lastInputTime'] = time();
	}

	if ($_SESSION['playerID'] == -1)
	{
			die("Session timed out.  Please <a href='index.php'>login again</a> to continue.");
	}
?>

