<?php
// $Id: move.php,v 1.4 2010/08/14 16:57:54 sandking Exp $

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

/* these functions deal specifically with moving a piece */
	function doMove()
	{
		global $board, $isPromoting, $doUndo, $history, $numMoves;

		/* old PHP versions don't have _POST, _GET and _SESSION as auto_globals */
		if (!minimum_version("4.1.0"))
			global $_POST, $_GET, $_SESSION;
		
		/* if moving en-passant */
		/* (ie: if pawn moves diagonally without replacing anything) */
		if ((($board[$_POST['fromRow']][$_POST['fromCol']] & COLOR_MASK) == PAWN) && ($_POST['toCol'] != $_POST['fromCol']) && ($board[$_POST['toRow']][$_POST['toCol']] == 0))
			/* delete eaten pawn */
			$board[$_POST['fromRow']][$_POST['toCol']] = 0;
		
		/* move piece to destination, replacing whatever's there */
		$board[$_POST['toRow']][$_POST['toCol']] = $board[$_POST['fromRow']][$_POST['fromCol']];

		/* delete piece from old position */
		$board[$_POST['fromRow']][$_POST['fromCol']] = 0;

		/* if not Undoing, but castling */
		if (($doUndo != "yes") && (($board[$_POST['toRow']][$_POST['toCol']] & COLOR_MASK) == KING) && (($_POST['toCol'] - $_POST['fromCol']) == 2))
		{
			/* castling to the right, move the right rook to the left side of the king */
			$board[$_POST['toRow']][5] = $board[$_POST['toRow']][7];

			/* delete rook from original position */
			$board[$_POST['toRow']][7] = 0;
		}
		elseif (($doUndo != "yes") && (($board[$_POST['toRow']][$_POST['toCol']] & COLOR_MASK) == KING) && (($_POST['fromCol'] - $_POST['toCol']) == 2))
		{
			/* castling to the left, move the left rook to the right side of the king */
			$board[$_POST['toRow']][3] = $board[$_POST['toRow']][0];

			/* delete rook from original position */
			$board[$_POST['toRow']][0] = 0;
		}

		return true;
	}
?>
