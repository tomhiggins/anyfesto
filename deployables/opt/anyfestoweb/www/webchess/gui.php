<?php
// $Id: gui.php,v 1.13 2010/08/15 10:29:00 sandking Exp $

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

	/* functions for outputting to html and javascript */
	require('chess.inc');
	function drawboard()
	{
		global $board, $playersColor, $numMoves;
		global $CFG_BOARDSQUARESIZE;

		/* old PHP versions don't have _POST, _GET and _SESSION as auto_globals */
		if (!minimum_version("4.1.0"))
			global $_POST, $_GET, $_SESSION;

		/* find out if it's the current player's turn */
		if (( (($numMoves == -1) || (($numMoves % 2) == 1)) && ($playersColor == "white"))
				|| ((($numMoves % 2) == 0) && ($playersColor == "black")) )
			$isPlayersTurn = true;
		else
			$isPlayersTurn = false;

		/* determine who's perspective of the board to show */
		if ($_SESSION['isSharedPC'] && !$isPlayersTurn)
		{
			if ($playersColor == "white")
				$perspective = "black";
			else
				$perspective = "white";
		}
		else
		{
			$perspective = $playersColor;
		}

		/* NOTE: if both players are using the same PC, in a sense it's always the players turn */
		if ($_SESSION['isSharedPC'])
			$isPlayersTurn = true;

		/* determine if board is disabled */
		$isDisabled = isBoardDisabled();

		echo ("var isBoardDisabled = '" . $isDisabled . "';\n");
		echo ("var isPlayersTurn = '" . $isPlayersTurn . "';\n");
		echo ("var perspective = '" . $perspective . "';\n");
		echo ("var squareSize = " . $CFG_BOARDSQUARESIZE . ";\n");
	}

	function writeJSboard()
	{
		global $board, $numMoves;

		/* old PHP versions don't have _POST, _GET and _SESSION as auto_globals */
		if (!minimum_version("4.1.0"))
			global $_POST, $_GET, $_SESSION;

		/* write out constants */
		echo ("var DEBUG = ".DEBUG.";\n");

		echo ("var CURRENTTHEME = '".$_SESSION['pref_theme']."';\n");
		echo ("var PAWN = ".PAWN.";\n");
		echo ("var KNIGHT = ".KNIGHT.";\n");
		echo ("var BISHOP = ".BISHOP.";\n");
		echo ("var ROOK = ".ROOK.";\n");
		echo ("var QUEEN = ".QUEEN.";\n");
		echo ("var KING = ".KING.";\n");
		echo ("var BLACK = ".BLACK.";\n");
		echo ("var WHITE = ".WHITE.";\n");
		echo ("var COLOR_MASK = ".COLOR_MASK.";\n");

		/* write code for array */
		echo ("var board = [");
		for ($i = 0; $i < 8; $i++)
		{
			echo ("\n[");
			for ($j = 0; $j < 8; $j++)
			{
				echo ($board[$i][$j]);
				if($j < 7)
					echo (', ');
			}
			echo ("]");
			if($i < 7)
			{
				echo (",");
			}
		}
		echo "];\n";

		echo("var numMoves = $numMoves;\n");
		echo("var errMsg = '';\n");	/* global var used for error messages */
	}

	/* provide history data to javascript function */
	/* NOTE: currently, only pawn validation script uses history */
	function writeJSHistory()
	{
		global $history, $numMoves;

		/* write out constants */
		echo ("var CURPIECE = 0;\n");
		echo ("var CURCOLOR = 1;\n");
		echo ("var FROMROW = 2;\n");
		echo ("var FROMCOL = 3;\n");
		echo ("var TOROW = 4;\n");
		echo ("var TOCOL = 5;\n");
		echo ("var PROMOTEDTO = 6;\n");

		/* write code for array */
		echo ("var chessHistory = [");
		for ($i = 0; $i <= $numMoves; $i++)
		{
			if($i % 4 == 0) // Four moves on each line
				echo("\n");
			echo ("['".$history[$i]['curPiece']."', ");
			echo ("'".$history[$i]['curColor']."', ");
			echo ($history[$i]['fromRow'].", ");
			echo ($history[$i]['fromCol'].", ");
			echo ($history[$i]['toRow'].", ");
			echo ($history[$i]['toCol']);
			if($history[$i]['promotedTo'] != '')
			{
				echo (", '".$history[$i]['promotedTo']."'");
			}
			echo ("]");
			if($i < $numMoves)
			{
				echo (",");
			}
		}
		echo "];\n";
	}

	function writeVerbousHistory()
	{
		global $history, $numMoves;

		for ($i = 0; $i <= $numMoves; $i++)
		{
			$tmpReplaced = "";
			if (!is_null($history[$i]['replaced']))
				$tmpReplaced = $history[$i]['replaced'];

			$tmpPromotedTo = "";
			if (!is_null($history[$i]['promotedTo']))
				$tmpPromotedTo = $history[$i]['promotedTo'];

			$tmpCheck = ($history[$i]['isInCheck'] == 1);

			$moves[$i/2][$i & 1] = moveToVerbousString($history[$i]['curColor'], $history[$i]['curPiece'], $history[$i]['fromRow'], $history[$i]['fromCol'], $history[$i]['toRow'], $history[$i]['toCol'], $tmpReplaced, $tmpPromotedTo, $tmpCheck);
		}

		return $moves;
	}

	function writeHistoryPGN()
	{
		global $history, $numMoves;

		for ($i = 0; $i <= $numMoves; $i++)
		{
			$tmpReplaced = "";
			if (!is_null($history[$i]['replaced']))
				$tmpReplaced = $history[$i]['replaced'];

			$tmpPromotedTo = "";
			if (!is_null($history[$i]['promotedTo']))
				$tmpPromotedTo = $history[$i]['promotedTo'];

			$tmpCheck = ($history[$i]['isInCheck'] == 1);

			$moves[$i/2][$i & 1] = moveToPGNString($history[$i]['curColor'], $history[$i]['curPiece'], $history[$i]['fromRow'], $history[$i]['fromCol'], $history[$i]['toRow'], $history[$i]['toCol'], $tmpReplaced, $tmpPromotedTo, $tmpCheck);
		}

		return $moves;
	}

	function writeHistory()
	{
		global $numMoves;

		/* old PHP versions don't have _POST, _GET and _SESSION as auto_globals */
		if (!minimum_version("4.1.0"))
			global $_POST, $_GET, $_SESSION;

		/* based on player's preferences, display the history */
		$moves  = array();	// Make sure that $moves is defined
		switch($_SESSION['pref_history'])
		{
			case 'verbous':
				$moves = writeVerbousHistory();
				break;

			case 'pgn':
				$moves = writeHistoryPGN();
				break;
		}

		$comma = '';
		echo("var moves = [");
		for ($i = 0; $i < count($moves); $i++)
		{
			echo($comma);
			if($i % 4 == 0) // Four moves on each line
				echo("\n");
			echo ("['" . $moves[$i][0]."', '".$moves[$i][1]."']");
			$comma = ', ';
		}
		echo("];\n");
	}

	function writeStatus()
	{
		global $numMoves, $history, $isCheckMate, $statusMessage, $isPlayersTurn;

		if (($numMoves == -1) || ($numMoves % 2 == 1))
			$curColor = "White";
		else
			$curColor = "Black";

		if ($_SESSION['isSharedPC'])
			echo ("var whosMove = '$curColor\'s Turn';\n");
		elseif ($isPlayersTurn)
			echo ("var whosMove = 'Your Turn';\n");
		else
			echo("var whosMove = 'Opponent\'s Turn';\n");

		echo("var checkMsg = '");
		if (!$isCheckMate && ($history[$numMoves]['isInCheck'] == 1))
			echo($curColor." is currently in check!");
		echo("';\n");
		echo("var statusMessage = '".$statusMessage."';\n");
	}

	function writePromotion()
	{
	?>
		<p>
		<table width="435" border="1">
		<tr><td>
			Promote pawn to:
			<br>
			<input type="radio" name="promotion" value="<?php echo (QUEEN); ?>" checked="checked"> Queen
			<input type="radio" name="promotion" value="<?php echo (ROOK); ?>"> Rook
			<input type="radio" name="promotion" value="<?php echo (KNIGHT); ?>"> Knight
			<input type="radio" name="promotion" value="<?php echo (BISHOP); ?>"> Bishop
			<input type="button" name="btnPromote" value="Promote" onClick="promotepawn()" />
		</td></tr>
		</table>
		</p>
	<?php
	}

	function writeUndoRequest()
	{
	?>
		<p>
		<table width="435" border="1">
		<tr><td>
			Your opponent would like to undo their latest move.  Will you allow it?
			<br>
			<input type="radio" name="undoResponse" value="yes"> Yes
			<input type="radio" name="undoResponse" value="no" checked="checked"> No
			<input type="hidden" name="isUndoResponseDone" value="no">
			<input type="button" value="Reply" onClick="this.form.isUndoResponseDone.value = 'yes'; this.form.submit()">
		</td></tr>
		</table>
		</p>
	<?php
	}

	function writeDrawRequest()
	{
	?>
		<p>
		<table width="435" border="1">
		<tr><td>
			Your opponent is proposing a draw.  Do you agree?
			<br>
			<input type="radio" name="drawResponse" value="yes"> Yes
			<input type="radio" name="drawResponse" value="no" checked="checked"> No
			<input type="hidden" name="isDrawResponseDone" value="no">
			<input type="button" value="Reply" onClick="this.form.isDrawResponseDone.value = 'yes'; this.form.submit()">
		</td></tr>
		</table>
		</p>
	<?php
	}

	function writePGN()
	{
		require 'connectdb.php';
		global $_SESSION, $history, $numMoves,$pWhite,$pWhiteF,$pWhiteL,$pBlack,$pBlackF,$pBlackL,$gStart;
		global $simplemove,$isDraw,$move_turn,$move_PlyNumber;
		$FEN="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
		set_FEN($FEN);
		#get_current_Position();
		#return;
		$xheader ="[Event \"WebChess Board #{$_SESSION['gameID']}\"]\n";
                $xheader .="[Site \"WebChess\"]\n";
                $xheader .="[Date \"$gStart\"]\n";
                $xheader .="[Round \"-\"]\n";
                $xheader .="[White \"$pWhiteL, $pWhiteF\"]\n";
                $xheader .="[Black \"$pBlackL, $pBlackF\"]\n";
		$body = "";
		$bodyLine = "";
		for ($i = 0; $i <= $numMoves; $i+=2)
		{
			// White's move
			$token = "".(($i/2)+1).".";
			if(strlen($bodyLine) + strlen($token) > 79)
			{
				$body .= $bodyLine . "\n";
				$bodyLine = "";
			}
			elseif(strlen($bodyLine) > 0)
			{
				$bodyLine .= " ";
			}
			$bodyLine .= $token;
			$tmpPromotedTo = "";
			if (!is_null($history[$i]['promotedTo']))
				$tmpPromotedTo = $history[$i]['promotedTo'];

			$tmpCheck = ($history[$i]['isInCheck'] == 1);

			$fr=$history[$i]['fromRow'];
			$fc=$history[$i]['fromCol'];
			$tr=$history[$i]['toRow'];
			$tc=$history[$i]['toCol'];
			$fs=coordsToSquare($fr,$fc);
			$ts=coordsToSquare($tr,$tc);
			#echo "<hr>Adding Move:$fs-$ts$tmpPromotedTo<hr>";
			add_Move("$fs-$ts".getPGNCode($tmpPromotedTo));
			#echo get_current_Position();
			$token = $simplemove;
			if(strlen($bodyLine) + strlen($token) > 79)
			{
				$body .= $bodyLine . "\n";
				$bodyLine = "";
			}
			elseif(strlen($bodyLine) > 0)
			{
				$bodyLine .= " ";
			}
			$bodyLine .= $token;
			if ($i != $numMoves)
			{	// Black's move
				$tmpPromotedTo = "";
				if (!is_null($history[$i+1]['promotedTo']))
					$tmpPromotedTo = $history[$i+1]['promotedTo'];

				$tmpCheck = ($history[$i+1]['isInCheck'] == 1);

				$fr=$history[$i+1]['fromRow'];
				$fc=$history[$i+1]['fromCol'];
				$tr=$history[$i+1]['toRow'];
				$tc=$history[$i+1]['toCol'];
				$fs=coordsToSquare($fr,$fc);
				$ts=coordsToSquare($tr,$tc);
				#echo "<hr>Adding Move:$fs-$ts$tmpPromotedTo<hr>";
				add_Move("$fs-$ts".getPGNCode($tmpPromotedTo));
				#echo get_current_Position();
			$token = $simplemove;
			if(strlen($bodyLine) + strlen($token) > 79)
			{
				$body .= $bodyLine . "\n";
				$bodyLine = "";
			}
			elseif(strlen($bodyLine) > 0)
			{
				$bodyLine .= " ";
			}
			$bodyLine .= $token;
			}
		}

		/* getResult() returns only definitive wins and remis.
		 * If a player resigns, this is not reflected in it, so we need to check
		 */
		$result=getResult();
		if($isDraw){
			$result="1/2-1/2";
		};

		$tmpQuery = "SELECT gameMessage, messageFrom FROM " . $CFG_TABLE[games] . " WHERE gameID = ".$_SESSION['gameID'];
		$tmpMessages = mysql_query($tmpQuery);
		$tmpMessage = mysql_fetch_array($tmpMessages, MYSQL_ASSOC);

		if ($tmpMessage['gameMessage'] == "playerResigned")
		{
			if ( $tmpMessage['messageFrom'] == "white" )
			{
				$result = "0-1";
			}
			else
			{
				$result = "1-0";
			}
		}

		$body .= $bodyLine;
		if(strlen($bodyLine) + strlen($result) > 79)
		{
			$body .= "\n";
		}
		elseif(strlen($bodyLine) > 0)
		{
			$body .= " ";
		}
		$body.= $result . "\n\n";
		$xheader .="[Result \"$result\"]\n\n";
		echo ($xheader);
		echo ($body);
	}
?>
