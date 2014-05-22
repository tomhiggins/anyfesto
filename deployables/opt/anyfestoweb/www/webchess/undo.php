<?php
// $Id: undo.php,v 1.5 2010/08/14 16:57:54 sandking Exp $

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

/* these functions deal specifically with undoing a move */
	function doUndo()
	{
		global $CFG_TABLE;
		global $board, $numMoves;

		/* old PHP versions don't have _POST, _GET and _SESSION as auto_globals */
		if (!minimum_version("4.1.0"))
			global $_POST, $_GET, $_SESSION;

		/* get the last move from the history */
		/* NOTE: MySQL currently has no support for subqueries */
		$tmpMaxTime = mysql_query("SELECT Max(timeOfMove) FROM " . $CFG_TABLE[history] . " WHERE gameID = ".$_SESSION['gameID']);
		$maxTime = mysql_result($tmpMaxTime,0);
		$moves = mysql_query("SELECT * FROM " . $CFG_TABLE[history] . " WHERE gameID = ".$_SESSION['gameID']." AND timeOfMove = '$maxTime'");

		/* if there actually is a move... */
		if ($lastMove = mysql_fetch_array($moves, MYSQL_ASSOC))
		{
			/* if the last move was played by this player */

				/* undo move */
				$fromRow = $lastMove['fromRow'];
				$fromCol = $lastMove['fromCol'];
				$toRow = $lastMove['toRow'];
				$toCol = $lastMove['toCol'];

				$board[$fromRow][$fromCol] = getPieceCode($lastMove['curColor'], $lastMove['curPiece']);
				$board[$toRow][$toCol] = 0;

				/* check for en-passant */
				/* if pawn moves diagonally without replacing a piece, it's en passant */
				if (($lastMove['curPiece'] == "pawn") && ($toCol != $fromCol) && is_null($lastMove['replaced']))
				{
					if ($lastMove['curColor'] == "black")
						$board[$fromRow][$toCol] = getPieceCode("white", "pawn");
					else
						$board[$fromRow][$toCol] = getPieceCode("black", "pawn");
				}

				/* check for castling */
				if ((($board[$fromRow][$fromCol] & COLOR_MASK) == KING) && (abs($toCol - $fromCol) == 2))
				{
					/* move rook back as well */
					if (($toCol - $fromCol) == 2)
					{
						$board[$fromRow][7] = $board[$fromRow][5];
						$board[$fromRow][5] = 0;
					}
					else
					{
						$board[$fromRow][0] = $board[$fromRow][3];
						$board[$fromRow][3] = 0;
					}
				}

				/* restore lost piece */
				if (!is_null($lastMove['replaced']))
				{
					if ($lastMove['curColor'] == "black")
						$board[$toRow][$toCol] = getPieceCode("white", $lastMove['replaced']);
					else
						$board[$toRow][$toCol] = getPieceCode("black", $lastMove['replaced']);
				}

				/* remove last move from history */
				$numMoves--;
				mysql_query("DELETE FROM " . $CFG_TABLE[history] . " WHERE gameID = ".$_SESSION['gameID']." AND timeOfMove = '$maxTime'");

			/* else */
				/* output error message */
		}
	}
?>

