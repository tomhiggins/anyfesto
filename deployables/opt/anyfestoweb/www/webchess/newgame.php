<?php
	// $Id: newgame.php,v 1.5 2010/08/14 16:57:54 sandking Exp $

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

/* these functions are used to start a new game */
	function initBoard()
	{
		global $board;

		/* clear board */
		for ($i = 0; $i < 8; $i++)
		{
			for ($j = 0; $j < 8; $j++)
			{
				$board[$i][$j] = 0;
			}
		}

		/* setup white pieces */
		$board[0][0] = WHITE | ROOK;
		$board[0][7] = WHITE | ROOK;
		$board[0][1] = WHITE | KNIGHT;
		$board[0][6] = WHITE | KNIGHT;
		$board[0][2] = WHITE | BISHOP;
		$board[0][5] = WHITE | BISHOP;
		$board[0][3] = WHITE | QUEEN;
		$board[0][4] = WHITE | KING;

		/* setup black pieces */
		$board[7][0] = BLACK | ROOK;
		$board[7][7] = BLACK | ROOK;
		$board[7][1] = BLACK | KNIGHT;
		$board[7][6] = BLACK | KNIGHT;
		$board[7][2] = BLACK | BISHOP;
		$board[7][5] = BLACK | BISHOP;
		$board[7][3] = BLACK | QUEEN;
		$board[7][4] = BLACK | KING;

		/* setup pawns */
		for ($i = 0; $i < 8; $i++)
		{
			$board[1][$i] = WHITE | PAWN;
			$board[6][$i] = BLACK | PAWN;
		}
	}

	function createNewGame($gameID)
	{
		global $CFG_TABLE;
		/* clear history */
		global $numMoves;

		/* old PHP versions don't have _POST, _GET and _SESSION as auto_globals */
		if (!minimum_version("4.1.0"))
			global $_POST, $_GET, $_SESSION;

		$numMoves = -1;
		mysql_query("DELETE FROM " . $CFG_TABLE[history] . " WHERE gameID = ".$_SESSION['gameID']);

		initBoard();
	}
?>
