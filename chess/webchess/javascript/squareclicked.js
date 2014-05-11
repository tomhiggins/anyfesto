// $Id: squareclicked.js,v 1.6 2010/08/14 16:57:54 sandking Exp $

/*
    This file is part of WebChess. http://webchess.sourceforge.net
	Copyright 2010 Jonathan Evraire, Rodrigo Flores, Dadi Jonsson

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

// this is the main function that interacts with the user everytime they click on a square

	/* called whenever a square is clicked on */
	var is1stClick = true;

	function squareClickedFirst(row, col, isEmpty, curColor)
	{
		if (getPieceColor(board[row][col]) == curColor)
		{
			document.gamedata.fromRow.value = row;
			document.gamedata.fromCol.value = col;

			highlight(row, col);

			is1stClick = false;
		}
		else
			alert("I'm sorry, but you play the " + curColor +" pieces.");

	}

	function squareClickedSecond(row, col, isEmpty, curColor)
	{
		unhighlight(document.gamedata.fromRow.value, document.gamedata.fromCol.value);
		is1stClick = true;

		if ((document.gamedata.fromRow.value == row)
			&& (document.gamedata.fromCol.value == col))
		{
			document.gamedata.fromRow.value = "";
			document.gamedata.fromCol.value = "";
		}
		else
		{
			/* if, on a player's second click, they click on one of their own piece */
			/* act as if he was clicking for the first time (ie: select it) */
			if (board[row][col] != 0 )
				if (getPieceColor(board[row][col]) == curColor)
				{
					squareClickedFirst(row, col, isEmpty, curColor);
					return null;
				}

			var fromRow = parseInt(document.gamedata.fromRow.value);
			var fromCol = parseInt(document.gamedata.fromCol.value);
			document.gamedata.toRow.value = row;
			document.gamedata.toCol.value = col;

			if (isValidMove(fromRow, fromCol, row, col))
			{
				if (DEBUG)
					alert("Move is valid, updating game...");

				// Note the move in the history of the game
				// Note that this entry won't be used unless numMoves is incremented
				// Important: Some checks below need this entry, while it would cause others to fail
				// Therefore numMoves must be locally incremented and then reset again when it's needed
				var idx = numMoves + 1;
				chessHistory[idx] = new Array();
				chessHistory[idx][CURPIECE] = thePiece;
				chessHistory[idx][CURCOLOR] = curColor;
				chessHistory[idx][FROMROW] = fromRow;
				chessHistory[idx][FROMCOL] = fromCol;
				chessHistory[idx][TOROW] = row;
				chessHistory[idx][TOCOL] = col;

				var ennemyColor = "white";
				if (curColor == "white")
					ennemyColor = "black";
				var isCapture = (board[row][col] != 0);
				var thePiece = getPieceName(board[fromRow][fromCol]);

				/* update board with move (client-side) */
				board[row][col] = board[fromRow][fromCol];
				board[fromRow][fromCol] = 0;

				/* if this is a castling move the rook must also be moved */
				if ((thePiece == 'king') && (Math.abs(col - fromCol) == 2))
				{	// The king only moves two squares when castling
					var rookCol = 0;
					var rookToCol = 3
					if (col - fromCol == 2)
					{	// Kingside castling (would be == -2 if queenside)
						rookCol = 7;
						rookToCol = 5;
					}
					board[row][rookToCol] = board[row][rookCol];
					board[row][rookCol] = 0;
				}
				else if((thePiece == 'pawn') && (col != fromCol) && (!isCapture))
				{	/* if this is an en passant capture, the captured pawn must be removed */
					board[fromRow][col] = 0;
				}

				if (isInCheck(ennemyColor))
				{
					document.gamedata.isInCheck.value = "true";
					if(thePiece == 'pawn' && Math.abs(row - fromRow) == 2)	// Pawn double advance
						var epCol = col;	// The column of the en passant square
					else
						var epCol = -1;
					document.gamedata.isCheckMate.value = isCheckMate(ennemyColor, epCol);
				}
				else
				{	// Not in check
					document.gamedata.isInCheck.value = "false";
				}
				document.gamedata.submit();
			}
			else
			{
				document.gamedata.toRow.value = "";
				document.gamedata.toCol.value = "";

				alert("Invalid move:\n" + errMsg);
			}
		}
	}

	function squareClicked(squareObj)
	{
		var square = squareObj.id.slice(3);
		square = parseInt(square);
		var col = square % 8;
		var row = (square-col) / 8;
		var isEmpty = (board[row][col] == 0);
		if (DEBUG)
			alert('squareClicked -> row = ' + row + ', col = ' + col + ', isEmpty = ' + isEmpty);

		var curColor = "black";
		if ((numMoves == -1) || (numMoves % 2 == 1))
			curColor = "white";

		if (is1stClick)
		{ // No piece has been clicked yet
			if(!isEmpty)	// Not an empty square
				squareClickedFirst(row, col, isEmpty, curColor);
			else	// Clicked on an empty square
				return;
		}
		else	// The second click. A piece has already been marked with the first click
			squareClickedSecond(row, col, isEmpty, curColor);
	}

