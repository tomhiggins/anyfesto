<?php
// $Id: chess.php,v 1.13 2010/08/18 09:38:56 sandking Exp $

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

	/* load settings */
	if (!isset($_CONFIG))
		require 'config.php';

	/* define constants */
	require 'chessconstants.php';

	/* include outside functions */
	if (!isset($_CHESSUTILS))
		require 'chessutils.php';
	require 'gui.php';
	require 'chessdb.php';
	require 'move.php';
	require 'undo.php';

	/* allow WebChess to be run on PHP systems < 4.1.0, using old http vars */
	fixOldPHPVersions();

	/* check session status */
	require 'sessioncheck.php';

	/* check if loading game */
	if (isset($_POST['gameID']))
		$_SESSION['gameID'] = $_POST['gameID'];

	/* debug flag */
	define ("DEBUG", 0);

	/* connect to database */
	require 'connectdb.php';

	/* get White's nick */
	$tmpNick = mysql_query("SELECT nick FROM " . $CFG_TABLE[players] . ", " . $CFG_TABLE[games] . " WHERE playerID = whitePlayer AND gameID = " . $_SESSION['gameID']);
	$whiteNick = mysql_result($tmpNick, 0);

	/* get Black's nick */
	$tmpNick = mysql_query("SELECT nick FROM " . $CFG_TABLE[players] . ", " . $CFG_TABLE[games] . " WHERE playerID = blackPlayer AND gameID = " . $_SESSION['gameID']);
	$blackNick = mysql_result($tmpNick, 0);

	/* load game */
	$isInCheck = ($_POST['isInCheck'] == 'true');
	$isCheckMate = false;
	$isPromoting = false;
	$isUndoing = false;
	loadHistory();
	loadGame();
	processMessages();

	if ($isUndoing)
	{
		doUndo();
		saveGame();
	}
	elseif (($_POST['promotion'] != "") && ($_POST['toRow'] != "") && ($_POST['toCol'] != ""))
	{
		savePromotion();
		$board[$_POST['toRow']][$_POST['toCol']] = $_POST['promotion'] | ($board[$_POST['toRow']][$_POST['toCol']] & BLACK);
		saveGame();
	}
	elseif (($_POST['fromRow'] != "") && ($_POST['fromCol'] != "") && ($_POST['toRow'] != "") && ($_POST['toCol'] != ""))
	{
		/* ensure it's the current player moving				 */
		/* NOTE: if not, this will currently ignore the command...               */
		/*       perhaps the status should be instead?                           */
		/*       (Could be confusing to player if they double-click or something */
		$tmpIsValid = true;
		if (($numMoves == -1) || ($numMoves % 2 == 1))
		{
			/* White's move... ensure that piece being moved is white */
			if ((($board[$_POST['fromRow']][$_POST['fromCol']] & BLACK) != 0) || ($board[$_POST['fromRow']][$_POST['fromCol']] == 0))
				/* invalid move */
				$tmpIsValid = false;
		}
		else
		{
			/* Black's move... ensure that piece being moved is black */
			if ((($board[$_POST['fromRow']][$_POST['fromCol']] & BLACK) != BLACK) || ($board[$_POST['fromRow']][$_POST['fromCol']] == 0))
				/* invalid move */
				$tmpIsValid = false;
		}

		if ($tmpIsValid)
		{
			saveHistory();
			doMove();
			saveGame();
		}
	}
	elseif($history[$numMoves]['curPiece'] == 'pawn' && $history[$numMoves]['promotedTo'] == null)
	{	// Incomplete promotion?
		if($history[$numMoves]['toRow'] == 7 || $history[$numMoves]['toRow'] == 0)
		{
			$isPromoting = true;
		}
	}

	mysql_close();
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
   "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1" />
<meta http-equiv="pragma" content="no-cache" />
<link rel="stylesheet" href="chess.css" type="text/css" />
<?php
	echo("<link rel='stylesheet' href='images/");
	echo($_SESSION['pref_theme'] . "/wctheme.css' type='text/css' />\n");

	/* find out if it's the current player's turn */
	if (( (($numMoves == -1) || (($numMoves % 2) == 1)) && ($playersColor == "white"))
			|| ((($numMoves % 2) == 0) && ($playersColor == "black")))
		$isPlayersTurn = true;
	else
		$isPlayersTurn = false;

	if ($_SESSION['isSharedPC'])
		echo("<title>WebChess</title>\n");
	else if ($isPlayersTurn)
		echo("<title>WebChess - Your Move</title>\n");
	else
		echo("<title>WebChess - Opponent's Move</title>\n");
?>
<script type="text/javascript">
<?php
	echo("var cfgImageExt = '$CFG_IMAGE_EXT';\n");
	/* transfer board data to javacript */
	writeJSboard();
	/* if it's not the player's turn, enable auto-refresh */
	$autoRefresh = !$isPlayersTurn && !isBoardDisabled() && !$_SESSION['isSharedPC'];
	echo('var autoreload = ');
	if(!$autoRefresh)
		echo('0');
	else if ($_SESSION['pref_autoreload'] >= $CFG_MINAUTORELOAD)
		echo ($_SESSION['pref_autoreload']);
	else
		echo ($CFG_MINAUTORELOAD);
	echo(";\n");
	writeJShistory();
	drawboard();
	echo 'var gameId = ' . $_SESSION['gameID'] . ";\n";
	echo 'var players = "' . $whiteNick . ' - ' . $blackNick . "\";\n";
	echo 'var playersColor = "' . $playersColor . "\";\n";
	echo 'var isPromoting = "'.$isPromoting. "\";\n";
	echo 'var isKingInCheck = "'.$isInCheck. "\";\n";
	echo 'var isGameOver = "'.$isGameOver. "\";\n";
	echo 'var historyLayout = "'.$_SESSION['pref_historylayout']. "\";\n";

	writeStatus();
	writeHistory();
	// Captured pieces..
	require 'capt.php';
?>
</script>
<script type="text/javascript" src="javascript/chessutils.js"></script>
<script type="text/javascript" src="javascript/commands.js"></script>
<script type="text/javascript" src="javascript/validation.js"></script>
<?php
if($isPlayersTurn || $_SESSION['isSharedPC'] || $isPromoting)
	echo('
<script type="text/javascript" src="javascript/isCheckMate.js"></script>');
if(!isBoardDisabled() || $_SESSION['isSharedPC'])
	echo('
<script type="text/javascript" src="javascript/squareclicked.js"></script>');
?>
<script type="text/javascript" src="javascript/board.js"></script>
</head>
<body>
<div id="wrapper">
	<div id="header">
	  <div id="heading">WebChess</div>
	</div>
	<div id="boardsection" align="center">
		<form name="gamedata" method="post" action="chess.php">
		<?php
			if ($isPromoting && (!$isPlayersTurn || $_SESSION['isSharedPC'])) // Write promotion dialog only to the correct player
				writePromotion();
			if ($isUndoRequested)
				writeUndoRequest();
			if ($isDrawRequested)
				writeDrawRequest();
		?>
		<div id="chessboard"></div>
		<div id="moveinfo">
			<div id="curmove">&nbsp;</div>
			<div id="whosmove">&nbsp;</div>
		</div>
		<div id="gamebuttons">
		<input type="button" id="btnUndo" class="button" value="Request Undo" disabled="disabled" />
		<input type="button" id="btnDraw" class="button" value="Request Draw" disabled="disabled" />
		<input type="button" id="btnResign" class="button" value="Resign" disabled="disabled" />
		</div>
		<input type="hidden" name="requestUndo" value="no" />
		<input type="hidden" name="requestDraw" value="no" />
		<input type="hidden" name="resign" value="no" />
		<input type="hidden" name="fromRow" value="<?php if (isPromoting) echo ($_POST['fromRow']); ?>" />
		<input type="hidden" name="fromCol" value="<?php if (isPromoting) echo ($_POST['fromCol']); ?>" />
		<input type="hidden" name="toRow" value="<?php if (isPromoting) echo ($_POST['toRow']); ?>" />
		<input type="hidden" name="toCol" value="<?php if (isPromoting) echo ($_POST['toCol']); ?>" />
		<input type="hidden" name="isInCheck" value="false" />
		<input type="hidden" name="isCheckMate" value="false" />
		</form>
		<div id="gamenav"></div>
		<div>When castling, just move the king (the rook will move automatically).</div>
		<div id="captheading">Captured pieces</div>
		<div id="captures"></div>
	</div>

	<div id="content">
		<div id="players" class="move_header"></div>
		<div id="gameid" class="move_header"></div>
		<div id="gamebody" class="move_header"></div>
		<div id="checkmsg"></div>
		<div id="statusmsg"></div>
		<form name="gamemenu" method="post" action="chess.php" style="text-align:center;">
		<input type="button" id="btnMainMenu" class="button" value="Menu" disabled="disabled" />
		<input type="button" id="btnReload" class="button" value="Reload" disabled="disabled" />
		<input type="button" id="btnPGN" class="button" value="PGN" disabled="disabled" />
		<input type="button" id="btnLogout" class="button" value="Logout" disabled="disabled" />
		<input type="hidden" name="ToDo" value="Logout" />	<!-- NOTE: this field is only used to Logout -->
		</form>
	</div>

	<div id="footer">
		<p><a href="http://webchess.sourceforge.net/">WebChess</a> is Free Software released under the GNU General Public License (GPL).</p>
	</div>
</div>
</body>
</html>
