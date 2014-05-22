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

// these functions are used to test the validity of moves
DEBUG = false;

var Files = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'];
var knightMove = [[-1, -2], [+1, -2], [-2, -1], [-2, +1], [-1, +2], [+1, +2], [+2, -1], [+2, +1]];
var diagonalMove = [[-1, -1], [-1, +1], [+1, +1], [+1, -1]];
var horzVertMove = [[-1, 0], [0, +1], [+1, 0], [0, -1]];
// The array 'direction' is a combination of diagonalMove and horzVertMove
// It could also be created using 'var direction = horzVertMove.concat(diagonalMove)'
// although the order of the elements would be different
var direction = [[-1, -1], [-1, 0], [-1, +1], [0, +1], [+1, +1], [+1, 0], [+1, -1], [0, -1]];
var pawnMove = [[+1, -1], [+1, 0], [+2, 0], [+1, +1]];

// object definition (used by isSafe)
function GamePiece()
{
	this.piece = 0;
	this.dist = 0;
}

	/* isSafe tests whether the square at testRow, testCol is safe */
	/* for a piece of color testColor to travel to */
	function isSafe(testRow, testCol, testColor)
	{
		/* NOTE: if a piece occupates the square itself,
			that piece does not participate in determining the safety of the square */

		/* IMPORTANT: note that if we're checking to see if the square is safe for a pawn
			we're moving, we need to verify the safety for En-passant */

		/* OPTIMIZE: cache results (if client-side game only, invalidate cache after each move) */

		/* AI NOTE: just because a square isn't entirely safe doesn't mean we don't want to
			move there; for instance, we may be protected by another piece */

		/* DESIGN NOTE: this function is mostly designed with CHECK checking in mind and
			may not be suitable for other purposes */

		if (DEBUG)
			alert("in isSafe(" + testRow + ", " + testCol + ", " + testColor + ")");

		var ennemyColor = 0;
		if (testColor == 'white')
			ennemyColor = 128; /* 1000 0000 */

		/* check for knights first */
		for (var i = 0; i < 8; i++) {	// Check all eight possible knight moves
			var fromRow = testRow + knightMove[i][0];
			var fromCol = testCol + knightMove[i][1];
			if (isInBoard(fromRow, fromCol))
				if (board[fromRow][fromCol] == (KNIGHT | ennemyColor))	// Enemy knight found
						return false;
		}

		/* tactic: start at test pos and check all 8 directions for an attacking piece */
		/* directions:
			0 1 2
			7 * 3
			6 5 4
		*/
		var pieceFound = new Array();
		for (var i = 0; i < 8; i++)
			pieceFound[i] = new GamePiece();

		for (var i = 1; i < 8; i++)
		{
			if (((testRow - i) >= 0) && ((testCol - i) >= 0))
				if ((pieceFound[0].piece == 0) && (board[testRow - i][testCol - i] != 0))
				{
					if (DEBUG)
						alert("isSafe -> pieceFound[0] = " + board[testRow - i][testCol - i] + "\ndist = " + i);

					pieceFound[0].piece = board[testRow - i][testCol - i];
					pieceFound[0].dist = i;
				}

			if ((testRow - i) >= 0)
				if ((pieceFound[1].piece == 0) && (board[testRow - i][testCol] != 0))
				{
					if (DEBUG)
						alert("isSafe -> pieceFound[1] = " + board[testRow - i][testCol] + "\ndist = " + i);

					pieceFound[1].piece = board[testRow - i][testCol];
					pieceFound[1].dist = i;
				}

			if (((testRow - i) >= 0) && ((testCol + i) < 8))
				if ((pieceFound[2].piece == 0) && (board[testRow - i][testCol + i] != 0))
				{
					if (DEBUG)
						alert("isSafe -> pieceFound[2] = " + board[testRow - i][testCol + i] + "\ndist = " + i);

					pieceFound[2].piece = board[testRow - i][testCol + i];
					pieceFound[2].dist = i;
				}

			if ((testCol + i) < 8)
				if ((pieceFound[3].piece == 0) && (board[testRow][testCol + i] != 0))
				{
					if (DEBUG)
						alert("isSafe -> pieceFound[3] = " + board[testRow][testCol + i] + "\ndist = " + i);

					pieceFound[3].piece = board[testRow][testCol + i];
					pieceFound[3].dist = i;
				}

			if (((testRow + i) < 8) && ((testCol + i) < 8))
				if ((pieceFound[4].piece == 0) && (board[testRow + i][testCol + i] != 0))
				{
					if (DEBUG)
						alert("isSafe -> pieceFound[4] = " + board[testRow + i][testCol + i] + "\ndist = " + i);

					pieceFound[4].piece = board[testRow + i][testCol + i];
					pieceFound[4].dist = i;
				}

			if ((testRow + i) < 8)
				if ((pieceFound[5].piece == 0) && (board[testRow + i][testCol] != 0))
				{
					if (DEBUG)
						alert("isSafe -> pieceFound[5] = " + board[testRow + i][testCol] + "\ndist = " + i);

					pieceFound[5].piece = board[testRow + i][testCol];
					pieceFound[5].dist = i;
				}

			if (((testRow + i) < 8) && ((testCol - i) >= 0))
				if ((pieceFound[6].piece == 0) && (board[testRow + i][testCol - i] != 0))
				{
					if (DEBUG)
						alert("isSafe -> pieceFound[6] = " + board[testRow + i][testCol - i] + "\ndist = " + i);

					pieceFound[6].piece = board[testRow + i][testCol - i];
					pieceFound[6].dist = i;
				}

			if ((testCol - i) >= 0)
				if ((pieceFound[7].piece == 0) && (board[testRow][testCol - i] != 0))
				{
					if (DEBUG)
						alert("isSafe -> pieceFound[7] = " + board[testRow][testCol - i] + "\ndist = " + i);

					pieceFound[7].piece = board[testRow][testCol - i];
					pieceFound[7].dist = i;
				}
		}

		/* check pieces found for possible threats */
		for (var i = 0; i < 8; i++)
			if ((pieceFound[i].piece != 0) && ((pieceFound[i].piece & BLACK) == ennemyColor))
				switch(i)
				{
					/* diagonally: queen, bishop, pawn, king */
					case 0:
					case 2:
					case 4:
					case 6:
						if (((pieceFound[i].piece & COLOR_MASK) == QUEEN)
								|| ((pieceFound[i].piece & COLOR_MASK) == BISHOP))
						{
							if (DEBUG)
								alert("isSafe -> notKnight -> diagonal -> Q or B -> " + getPieceColor(pieceFound[i].piece) + " " + getPieceName(pieceFound[i].piece) + "\ndist = " + pieceFound[i].dist + "\ndir = " + i);
							return false;
						}

						if ((pieceFound[i].dist == 1)
								&& ((pieceFound[i].piece & COLOR_MASK) == PAWN))
						{
							if (DEBUG)
								alert("isSafe -> notKnight -> diagonal -> Pawn -> " + getPieceColor(pieceFound[i].piece) + " " + getPieceName(pieceFound[i].piece) + "\ndist = " + pieceFound[i].dist + "\ndir = " + i);
							if ((ennemyColor == WHITE) && ((i == 0) || (i == 2)))
								return false;
							else if ((ennemyColor == BLACK) && ((i == 4) || (i == 6)))
								return false;
						}

						if ((pieceFound[i].dist == 1)
								&& ((pieceFound[i].piece & COLOR_MASK) == KING))
						{
							if (DEBUG)
								alert("isSafe -> notKnight -> diagonal -> King -> " + getPieceColor(pieceFound[i].piece) + " " + getPieceName(pieceFound[i].piece) + "\ndist = " + pieceFound[i].dist + "\ndir = " + i);

							/* Are the kings next to each other? */
							if ((board[testRow][testCol] & COLOR_MASK) == KING)
								return false;

							/* save current board destination */
							var tmpPiece = board[testRow][testCol];

							/* update board with move (client-side) */
							board[testRow][testCol] = pieceFound[i].piece;

							var kingRow = 0;
							var kingCol = 0;
							switch(i)
							{
								case 0: kingRow = testRow - 1; kingCol = testCol - 1;
									break;
								case 1: kingRow = testRow - 1; kingCol = testCol;
									break;
								case 2: kingRow = testRow - 1; kingCol = testCol + 1;
									break;
								case 3: kingRow = testRow;     kingCol = testCol + 1;
									break;
								case 4: kingRow = testRow + 1; kingCol = testCol + 1;
									break;
								case 5: kingRow = testRow + 1; kingCol = testCol;
									break;
								case 6: kingRow = testRow + 1; kingCol = testCol - 1;
									break;
								case 7: kingRow = testRow;     kingCol = testCol - 1;
									break;
							}

							board[kingRow][kingCol] = 0;

							/* if king needs to move into check to capture piece, isSafe() is true */
							var tmpIsSafe = isInCheck(getOtherColor(testColor));

							/* restore board to previous state */
							board[kingRow][kingCol] = pieceFound[i].piece;
							board[testRow][testCol] = tmpPiece;

							/* if king CAN eat target without moving into check, return false */
							/* otherwise, continue checking other piecesFound */
							if (!tmpIsSafe)
								return false;
						}
						break;

					/* horizontally/vertically: queen, rook, king */
					case 1:
					case 3:
					case 5:
					case 7:
						if (((pieceFound[i].piece & COLOR_MASK) == QUEEN)
								|| ((pieceFound[i].piece & COLOR_MASK) == ROOK))
						{
							if (DEBUG)
								alert("isSafe -> notKnight -> horiz/vert -> Q or R -> " + getPieceColor(pieceFound[i].piece) + " " + getPieceName(pieceFound[i].piece) + "\ndist = " + pieceFound[i].dist + "\ndir = " + i);

							return false;
						}

						if ((pieceFound[i].dist == 1)
								&& ((pieceFound[i].piece & COLOR_MASK) == KING))
						{
							if (DEBUG)
								alert("isSafe -> notKnight -> horiz/vert -> King -> " + getPieceColor(pieceFound[i].piece) + " " + getPieceName(pieceFound[i].piece) + "\ndist = " + pieceFound[i].dist + "\ndir = " + i);

							/* Are the kings next to each other? */
							if ((board[testRow][testCol] & COLOR_MASK) == KING)
								return false;

							/* save current board destination */
							var tmpPiece = board[testRow][testCol];

							/* update board with move (client-side) */
							board[testRow][testCol] = pieceFound[i].piece;

							var kingRow = 0;
							var KingCol = 0;
							switch(i)
							{
								case 0: kingRow = testRow - 1; kingCol = testCol - 1;
									break;
								case 1: kingRow = testRow - 1; kingCol = testCol;
									break;
								case 2: kingRow = testRow - 1; kingCol = testCol + 1;
									break;
								case 3: kingRow = testRow;     kingCol = testCol + 1;
									break;
								case 4: kingRow = testRow + 1; kingCol = testCol + 1;
									break;
								case 5: kingRow = testRow + 1; kingCol = testCol;
									break;
								case 6: kingRow = testRow + 1; kingCol = testCol - 1;
									break;
								case 7: kingRow = testRow;     kingCol = testCol - 1;
									break;
							}

							board[kingRow][kingCol] = 0;

							/* if king needs to move into check to capture piece, isSafe() is true */
							var tmpIsSafe = isInCheck(getOtherColor(testColor));

							/* restore board to previous state */
							board[kingRow][kingCol] = pieceFound[i].piece;
							board[testRow][testCol] = tmpPiece;

							/* if king CAN eat target without moving into check, return false */
							/* otherwise, continue checking other piecesFound */
							if (!tmpIsSafe)
								return false;
						}
						break;
				}
		if (DEBUG)
			alert("isSafe is true");

		return true;
	}

	function isValidMoveKing(fromRow, fromCol, toRow, toCol, tmpColor)
	{
		/* the king cannot move to a square occupied by a friendly piece */
		if ((board[toRow][toCol] != 0) && (getPieceColor(board[toRow][toCol]) == tmpColor))
		{
			return false;
		}
		/* temporarily move king to destination to see if in check */
		var tmpPiece = board[toRow][toCol];
		board[toRow][toCol] = board[fromRow][fromCol];
		board[fromRow][fromCol] = 0;

		/* The king does not move to a square that is attacked by an enemy piece */
		if(tmpColor == 'white')
			var atkColor = BLACK;
		else
			var atkColor = WHITE;
		if (isInCheck(tmpColor))
		{
			/* return king to original position */
			board[fromRow][fromCol] = board[toRow][toCol];
			board[toRow][toCol] = tmpPiece;

			if (DEBUG)
				alert("king -> destination not safe!");

			errMsg = "Cannot move into check.";
			return false;
		}

		/* return king to original position */
		board[fromRow][fromCol] = board[toRow][toCol];
		board[toRow][toCol] = tmpPiece;

		/* NORMAL MOVE: */
		if ((Math.abs(toRow - fromRow) <= 1) && (Math.abs(toCol - fromCol) <= 1))
		{
			if (DEBUG)
				alert("king -> normal move");

			return true;
		}
		/* CASTLING: */
		else if ((fromRow == toRow) && (fromCol == 4) && (Math.abs(toCol - fromCol) == 2))
		{
			/*
			The following conditions must be met:
			    * The King and rook must occupy the same rank (or row).
			    * The king that makes the castling move has not yet moved in the game.
			*/
			if (DEBUG)
				alert("isValidMoveKing -> Castling");

			var rookCol = 0;
			if (toCol - fromCol == 2)
				rookCol = 7;

			/* ToDo: chessHistory check can probably be cut in half by only checking every other move (ie: current color's moves) */
			for (var i = 0; i <= numMoves; i++)
			{
				/* if king has already moved */
				if ((chessHistory[i][FROMROW] == fromRow) && (chessHistory[i][CURPIECE] == "king"))
				{
					errMsg = "Can only castle if king has not moved yet.";
					return false;
				}
				/* if rook has already moved */
				else if ((chessHistory[i][FROMROW] == fromRow) && (chessHistory[i][FROMCOL] == rookCol))
				{
					errMsg = "Can only castle if rook has not moved yet.";
					return false;
				}
			}

			/*
			    * All squares between the rook and king before the castling move are empty.
			*/
			tmpStep = (toCol - fromCol) / 2;
			for (var i = 4 + tmpStep; i != rookCol; i += tmpStep)
				if (board[fromRow][i] != 0)
				{
					if (DEBUG)
						alert("king -> castling -> square not empty");

					errMsg = "Can only castle if there are no pieces between the rook and the king";
					return false;
				}

			/*
			    * The king is not in check.
			    * The king does not move over a square that is attacked by an enemy piece during the castling move
			*/

			/* NOTE: the king's destination has already been checked, so */
			/* all that's left is it's initial position and it's final one */
			if (isSafe(fromRow, fromCol, tmpColor)
					&& isSafe(fromRow, fromCol + tmpStep, tmpColor))
			{
				if (DEBUG)
					alert("king -> castling -> VALID!");

				return true;
			}
			else
			{
				if (DEBUG)
					alert("king -> castling -> moving over attacked square");

				errMsg = "When castling, the king cannot move over a square that is attacked by an ennemy piece";
				return false;
			}
		}
		/* INVALID MOVE */
		else
		{
			if (DEBUG)
				alert("king -> completely invalid move\nfrom " + fromRow + ", " + fromCol + "\nto " + toRow + ", " + toCol);
			errMsg = "Kings cannot move like that.";
			return false;
		}

		if (DEBUG)
			alert("king -> castling -> unknown error");
	}

	/* checks whether a pawn is making a valid move */
	function isValidMovePawn(fromRow, fromCol, toRow, toCol, tmpDir, epCol)
	{
		if (arguments.length < 6)	// Was epCol not passed as a parameter to this function?
			epCol = -1;	// Make sure that epCol is defined
		if (((toRow - fromRow)/Math.abs(toRow - fromRow)) != tmpDir)
		{
			errMsg = "Pawns cannot move backwards, only forward.";
			return false;
		}

		/* standard move */
		if ((tmpDir * (toRow - fromRow) == 1) && (toCol == fromCol) && (board[toRow][toCol] == 0))
			return true;
		/* first move double jump - white */
		if ((tmpDir == 1) && (fromRow == 1) && (toRow == 3) && (toCol == fromCol) && (board[2][toCol] == 0) && (board[3][toCol] == 0))
			return true;
		/* first move double jump - black */
		if ((tmpDir == -1) && (fromRow == 6) && (toRow == 4) && (toCol == fromCol) && (board[5][toCol] == 0) && (board[4][toCol] == 0))
			return true;
		/* standard eating DJ-NOTE: Shouldn't we check that the pawn being eaten is of the correct color? */
		else if ((tmpDir * (toRow - fromRow) == 1) && (Math.abs(toCol - fromCol) == 1) && (board[toRow][toCol] != 0))
			return true;
		/* en passant - white */
		else if ((tmpDir == 1) && (fromRow == 4) && (toRow == 5) && (board[4][toCol] == (PAWN | BLACK)))
		{
			/* can only move en passant if last move is the one where the black pawn moved up two */
			if (epCol == toCol ||
				(numMoves >= 0 && chessHistory[numMoves][FROMROW] == 6 && chessHistory[numMoves][TOROW] == 4
								&& chessHistory[numMoves][TOCOL] == toCol))
				return true;
			else
			{
				errMsg = "Pawns can only capture en passant immediately after an opponent advanced his pawn two squares.";
				return false;
			}
		}
		/* en passant - black */
		else if ((tmpDir == -1) && (fromRow == 3) && (toRow == 2) && (board[3][toCol] == PAWN))
		{
			/* can only move en passant if last move is the one where the white pawn moved up two */
			if (epCol == toCol ||
				(numMoves >= 0 && chessHistory[numMoves][FROMROW] == 1 && chessHistory[numMoves][TOROW] == 3
								&& chessHistory[numMoves][TOCOL] == toCol))
				return true;
			else
			{
				errMsg = "Pawns can only capture en passant immediately after an opponent advanced his pawn two squares.";
				return false;
			}
		}
		else
		{
			errMsg = "Pawns cannot move like that.";
			return false;
		}
	}

	/* checks whether a knight is making a valid move */
	function isValidMoveKnight(fromRow, fromCol, toRow, toCol)
	{
		errMsg = "Knights cannot move like that.";
		if (Math.abs(toRow - fromRow) == 2)
		{
			if (Math.abs(toCol - fromCol) == 1)
				return true;
			else
				return false;
		}
		else if (Math.abs(toRow - fromRow) == 1)
		{
			if (Math.abs(toCol - fromCol) == 2)
				return true;
			else
				return false;
		}
		else
		{
			return false;
		}
	}

	/* checks whether a bishop is making a valid move */
	function isValidMoveBishop(fromRow, fromCol, toRow, toCol)
	{
		if (Math.abs(toRow - fromRow) == Math.abs(toCol - fromCol))
		{
			if (toRow > fromRow)
			{
				if (toCol > fromCol)
				{
					for (var i = 1; i < (toRow - fromRow); i++)
						if (board[fromRow + i][fromCol + i] != 0)
						{
							errMsg = "Bishops cannot jump over other pieces.";
							return false;
						}
				}
				else
				{
					for (var i = 1; i < (toRow - fromRow); i++)
						if (board[fromRow + i][fromCol - i] != 0)
						{
							errMsg = "Bishops cannot jump over other pieces.";
							return false;
						}
				}

				return true;
			}
			else
			{
				if (toCol > fromCol)
				{
					for (var i = 1; i < (fromRow - toRow); i++)
						if (board[fromRow - i][fromCol + i] != 0)
						{
							errMsg = "Bishops cannot jump over other pieces.";
							return false;
						}
				}
				else
				{
					for (var i = 1; i < (fromRow - toRow); i++)
						if (board[fromRow - i][fromCol - i] != 0)
						{
							errMsg = "Bishops cannot jump over other pieces.";
							return false;
						}
				}

				return true;
			}
		}
		else
		{
			errMsg = "Bishops cannot move like that.";
			return false;
		}
	}

	/* checks wether a rook is making a valid move */
	function isValidMoveRook(fromRow, fromCol, toRow, toCol)
	{
		if (toRow == fromRow)
		{
			if (toCol > fromCol)
			{
				for (var i = (fromCol + 1); i < toCol; i++)
					if (board[fromRow][i] != 0)
					{
						errMsg = "Rooks cannot jump over other pieces.";
						return false;
					}
			}
			else
			{
				for (var i = (toCol + 1); i < fromCol; i++)
					if (board[fromRow][i] != 0)
					{
						errMsg = "Rooks cannot jump over other pieces.";
						return false;
					}

			}

			return true;
		}
		else if (toCol == fromCol)
		{
			if (toRow > fromRow)
			{
				for (var i = (fromRow + 1); i < toRow; i++)
					if (board[i][fromCol] != 0)
					{
						errMsg = "Rooks cannot jump over other pieces.";
						return false;
					}
			}
			else
			{
				for (var i = (toRow + 1); i < fromRow; i++)
					if (board[i][fromCol] != 0)
					{
						errMsg = "Rooks cannot jump over other pieces.";
						return false;
					}

			}

			return true;
		}
		else
		{
			errMsg = "Rooks cannot move like that.";
			return false;
		}
	}

	/* this function checks whether a queen is making a valid move */
	function isValidMoveQueen(fromRow, fromCol, toRow, toCol)
	{
		if (isValidMoveRook(fromRow, fromCol, toRow, toCol) || isValidMoveBishop(fromRow, fromCol, toRow, toCol))
			return true;

		if (errMsg.search("jump") == -1)
			errMsg = "Queens cannot move like that.";
		else
			errMsg = "Queens cannot jump over other pieces.";

		return false;
	}

	/* this functions checks to see if curColor is in check */
	function isInCheck(curColor)
	{
		var targetKing = getPieceCode(curColor, "king");

		/* find king */
		for (var i = 0; i < 8; i++)
			for (var j = 0; j < 8; j++)
				if (board[i][j] == targetKing)
					/* verify it's location is safe */
					return !isSafe(i, j, curColor);

		/* the next lines will hopefully NEVER be reached */
		errMsg = "CRITICAL ERROR: KING MISSING!"
		return false;
	}

	/* Ignoring pins, could the piece on the from-square move to the to-square? */
	function isValidNoPinMove(fromRow, fromCol, toRow, toCol, epCol)
	{
		var tmpDir = 1;
		var curColor = "white";
		if (board[fromRow][fromCol] & BLACK)
		{
			tmpDir = -1;
			curColor = "black";
		}

		var isValid = false;
		switch(board[fromRow][fromCol] & COLOR_MASK)
		{
			case PAWN:
				isValid = isValidMovePawn(fromRow, fromCol, toRow, toCol, tmpDir, epCol);
				break;
			case KNIGHT:
				isValid = isValidMoveKnight(fromRow, fromCol, toRow, toCol);
				break;
			case BISHOP:
				isValid = isValidMoveBishop(fromRow, fromCol, toRow, toCol);
				break;
			case ROOK:
				isValid = isValidMoveRook(fromRow, fromCol, toRow, toCol);
				break;
			case QUEEN:
				isValid = isValidMoveQueen(fromRow, fromCol, toRow, toCol);
				break;
			case KING:
				isValid = isValidMoveKing(fromRow, fromCol, toRow, toCol, curColor);
				break;
			default:	/* ie: not implemented yet */
				if (DEBUG)
					alert("unknown game piece");
		}
		return isValid;
	}

	function isValidMove(fromRow, fromCol, toRow, toCol, epCol)
	{
		if(!isValidNoPinMove(fromRow, fromCol, toRow, toCol, epCol))
			return false;	// The piece on the from-square doesn't even move in this way

		/* now that we know the move itself is valid, let's make sure we're not moving into check */
		/* NOTE: we don't need to check for the king since it's covered by isValidMoveKing() */

		var curColor = "white";
		if (board[fromRow][fromCol] & BLACK)
			curColor = "black";

		var isValid = true;

		if ((board[fromRow][fromCol] & COLOR_MASK) != KING)
		{
			if (DEBUG)
				alert("isValidMove -> are we moving into check?");

			/* save current board destination */
			var tmpPiece = board[toRow][toCol];

			/* is it an en passant capture? Then remove the captured pawn */
			var tmpEnPassant = 0;
			if (((board[fromRow][fromCol] & COLOR_MASK) == PAWN) && (Math.abs(toCol - fromCol) == 1) && (tmpPiece == 0))
			{
				tmpEnPassant = board[fromRow][toCol];
				board[fromRow][toCol] = 0;
			}

			/* update board with move (client-side) */
			board[toRow][toCol] = board[fromRow][fromCol];
			board[fromRow][fromCol] = 0;

			/* are we in check now? */
			if (isInCheck(curColor))
			{
				if (DEBUG)
					alert("isValidMove -> moving into check -> CHECK!");

				/* if so, invalid move */
				errMsg = "Cannot move into check.";
				isValid = false;
			}

			/* restore board to previous state */
			board[fromRow][fromCol] = board[toRow][toCol];
			board[toRow][toCol] = tmpPiece;
			if (tmpEnPassant != 0)
			{
				board[fromRow][toCol] = tmpEnPassant;
			}
		}

		if (DEBUG)
			alert("isValidMove returns " + isValid);

		return isValid;
	}

function canSquareBeBlocked(testRow, testCol, testColor)
{
	/*
	NOTE: This function is similar to isSafe(); however, the pawn detection
	is different. While the original function checks pawns moving diagonally
	or en-passant, this function doesn't.
	Since this function is intended for checkmate detection, specifically the
	canBlockAttacker() function, it must validate pawns moving forward.
	Also, king is not /allowed/ to block a square.
	NOTE: testColor is the attacker color!
	*/

	//var DEBUG=true;

	if (DEBUG)
	{
		alert("in canSquareBeBlocked(" + testRow + ", " + testCol + ", " + testColor + ")");
		//alert("Test Color: " + testColor);
	}
	var ennemyColor = WHITE;	// Attacking
	var myColor = BLACK;		// Blocking
	if (testColor == 'black')
	{
		ennemyColor = BLACK; /* 1000 0000 */
		myColor = WHITE;
	}

	/* check for knights first */
	for (var i = 0; i < 8; i++) {	// Check all eight possible knight moves
		var fromRow = testRow + knightMove[i][0];
		var fromCol = testCol + knightMove[i][1];
		if (isInBoard(fromRow, fromCol))
			if (board[fromRow][fromCol] == (KNIGHT | myColor))	// Knight found
				if(isValidMove(fromRow, fromCol, testRow, testCol))
					return true;	// It can move and block the attack
	}

	/* tactic: start at test pos and check all 8 directions for an attacking piece */
	/* directions:    BLACK:    WHITE:
		0 1 2         2 1 0     6 5 4
		7 * 3         3 * 7     7 * 3
		6 5 4         4 5 6     0 1 2
	*/
	for (var j = 0; j < 8; j++)		// Look for pieces in all directions
	{
		var fromRow = testRow;
		var fromCol = testCol;
		for (var i = 1; i < 8; i++)	// Distance from the test square
		{
			fromRow += direction[j][0];
			fromCol += direction[j][1];
			if (isInBoard(fromRow, fromCol))
			{ // if square is in board..
				if (board[fromRow][fromCol] != 0)
				{ // We found the first piece in this direction
					if((board[fromRow][fromCol] & BLACK) == myColor)
					{ // It is my piece
						if(isValidMove(fromRow, fromCol, testRow, testCol))
							return true;	// It can move and block the attack
					}
					break;		// No need to look further in this direction
				}
			}
			else
				break;	// We fell off the edge of the board
		}
	}
	return false;	// The attack cannot be blocked
}

/* canBeCaptured returns true if the piece at testRow, testCol can be captured */
function canBeCaptured(testRow, testCol, epCol)
{
	/* DESIGN NOTE: this function is designed only with CAPTURE checking in mind and should
		not be used for other purposes, e.g. if there is no piece (or a king) on the give square */
	/* Both normal captures and en passant captures are checked. The epCol parameter
	   should contain the column number of the en passant square or -1 if there is none.
	   If epCol >= 0 it indicates that we are replying to a pawn double advance move */

	var	tmpDir = -1;
	var	ennemyColor = BLACK;
	if (board[testRow][testCol] & BLACK)
	{
		tmpDir = 1;
		ennemyColor = WHITE;
	}
	var thePiece = getPieceName(board[testRow][testCol]);

	var atkSquare = new Array();
	atkSquare = getAttackers(testRow, testCol, ennemyColor);	// Find all attackers

	for (var i = 0; i < atkSquare.length; i++)	// Are the attackers pinned or can they capture?
		if(isValidMove(atkSquare[i][0], atkSquare[i][1], testRow, testCol))
			return true;	// The piece can be captured

	// If thePiece is a pawn can it by captured en passant?
	if(thePiece == 'pawn' && ((testRow == 3 && ennemyColor == BLACK) || (testRow == 4 && ennemyColor == WHITE)))
	{	// The pawn is on the correct row for a possible e.p. capture
		if(testCol > 0 && board[testRow][testCol-1] == (PAWN | ennemyColor))
			if(board[testRow + tmpDir][testCol] == 0)	// It's not a regular capture
					if(isValidMove(testRow, testCol-1, testRow + tmpDir, testCol, epCol))
						return true;	// En passant capture
		if(testCol < 7 && board[testRow][testCol+1] == (PAWN | ennemyColor))
			if(board[testRow + tmpDir][testCol] == 0)	// It's not a regular capture
					if(isValidMove(testRow, testCol+1, testRow + tmpDir, testCol. epCol))
						return true;	// En passant capture
	}
	return false;	// The piece cannot be captured
}

/* Find all pieces of color atkColor that attack the given square */
/* Note: Even if a piece attacks a square it may not be able to move there */
/* Note: En passant captures are not considered by this function */
function getAttackers(toRow, toCol, atkColor)
{
	var atkSquare = new Array();

	/* check for knights first */
	for (var i = 0; i < 8; i++) {	// Check all eight possible knight moves
		var fromRow = toRow + knightMove[i][0];
		var fromCol = toCol + knightMove[i][1];
		if (isInBoard(fromRow, fromCol))
			if (board[fromRow][fromCol] == (KNIGHT | atkColor))	// Enemy knight found
					atkSquare[atkSquare.length] = [fromRow, fromCol];
	}
	/* tactic: start at test square and check all 8 directions for an attacking piece */
	/* directions:
		0 1 2
		7 * 3
		6 5 4
	*/

	for (var j = 0; j < 8; j++)		// Look in all directions
	{
		var fromRow = toRow;
		var fromCol = toCol;
		for (var i = 1; i < 8; i++)	// Distance from thePiece
		{
			fromRow += direction[j][0];
			fromCol += direction[j][1];
			if (isInBoard(fromRow, fromCol))
			{
				if (board[fromRow][fromCol] != 0)
				{	// We found the first piece in this direction
					if((board[fromRow][fromCol] & BLACK) == atkColor)	// It is an enemy piece
					{
						if(isAttacking(board[fromRow][fromCol], fromRow, fromCol, getPieceColor(board[fromRow][fromCol]), toRow, toCol))
							atkSquare[atkSquare.length] = [fromRow, fromCol];	// An attacker found
					}
					break;		// No need to look further in this direction
				}
			}
			else
				break;
		}
	}
	return atkSquare;
}

/* Is the given square attacked by a piece of color atkColor? */
function isAttacked(toRow, toCol, atkColor)
{
	return getAttackers(toRow, toCol, atkColor).length > 0;
}

/* Generate moves for a rook, bishop or queen placed at the from-square */
function genSlideMoves(fromRow, fromCol, moveDir)
{
	var toSquare = new Array();	// Store the generated moves
	var	ennemyColor = BLACK;
	if (board[fromRow][fromCol] & BLACK)
	{
		ennemyColor = WHITE;
	}
	for (var j = 0; j < moveDir.length; j++)	// Check all (valid) directions
	{
		var toRow = fromRow;
		var toCol = fromCol;
		for (var i = 1; i < 8; i++)	// Distance from the piece
		{
			toRow += moveDir[j][0];
			toCol += moveDir[j][1];
			if (isInBoard(toRow, toCol))
			{
				if (board[toRow][toCol] != 0)
				{	// We found the first piece in this direction
					if((board[toRow][toCol] & BLACK) == ennemyColor)	// It's an enemy piece
					{
						if(isValidMove(fromRow, fromCol, toRow, toCol))
							toSquare[toSquare.length] = [toRow, toCol];	// A capture
					}
					break;		// No need to look further in this direction
				}
				else	// an empty square
				{
					if(isValidMove(fromRow, fromCol, toRow, toCol))
						toSquare[toSquare.length] = [toRow, toCol];	// Move to an empty square
				}
			}
			else
				break;
		}
	}
	return toSquare;
}

/* Generate all moves for the piece at the given square */
/* Currently this function is only used to test for stalemate.
   Therefore castling moves are not checked as they are not relevant
   for that purpose */
function genPieceMoves(fromRow, fromCol)
{
	var	ennemyColor = BLACK;
	if (board[fromRow][fromCol] & BLACK)
	{
		ennemyColor = WHITE;
	}
	var thePiece = board[fromRow][fromCol];

	var toSquare = new Array();

	switch(thePiece & COLOR_MASK)
	{
		case PAWN:
			var forwardDir = 1;
			if (ennemyColor == WHITE)
				forwardDir = -1;

			for (var i = 0; i < 4; i++) {
				var toRow = fromRow + pawnMove[i][0] * forwardDir;
				var toCol = fromCol + pawnMove[i][1];
				if (isInBoard(toRow, toCol))
					if (board[toRow][toCol] == 0 || (board[toRow][toCol] & BLACK) == ennemyColor)
						if(isValidMove(fromRow, fromCol, toRow, toCol))
							toSquare[toSquare.length] = [toRow, toCol];
			}
			break;

		case ROOK:
			toSquare = genSlideMoves(fromRow, fromCol, horzVertMove);
			break;

		case KNIGHT:
			for (var i = 0; i < 8; i++) {	// Check all eight possible knight moves
				var toRow = fromRow + knightMove[i][0];
				var toCol = fromCol + knightMove[i][1];
				if (isInBoard(toRow, toCol))
					if (board[toRow][toCol] == 0 || (board[toRow][toCol] & BLACK) == ennemyColor)
						if(isValidMove(fromRow, fromCol, toRow, toCol))
							toSquare[toSquare.length] = [toRow, toCol];
			}
			break;

		case BISHOP:
			toSquare = genSlideMoves(fromRow, fromCol, diagonalMove);
			break;

		case QUEEN:
			toSquare = genSlideMoves(fromRow, fromCol, direction);
			break;

		case KING:
			for (var i = 0; i < 8; i++) {	// Check all eight possible king moves
				var toRow = fromRow + direction[i][0];
				var toCol = fromCol + direction[i][1];
				if (isInBoard(toRow, toCol))
					if (board[toRow][toCol] == 0 || (board[toRow][toCol] & BLACK) == ennemyColor)
						if(isValidMove(fromRow, fromCol, toRow, toCol))
							toSquare[toSquare.length] = [toRow, toCol];
			}
			break;
	}

	return toSquare;
}

/* Generate all possible moves for the side indicated by the myColor parameter */
function genAllMoves(myColor)
{
	var moves = new Array();
	for (var i = 0; i < 8; i++)			// For all board rows
	{
		for (var j = 0; j < 8; j++)		// Check all columns
		{
			if(board[i][j] != 0 && ((board[i][j] & BLACK) == myColor))
			{
				if(typeof moves[i] == 'undefined') {
					moves[i] = new Array();
				}

				moves[i][j] = genPieceMoves(i, j);
			}
		}
	}
	return moves;
}

/* Count how many different moves are possible in the current position for myColor */
function countMoves(myColor)
{
	var moves = genAllMoves(myColor);
	var count = 0;
	for (var i in moves)			// For all board rows
	{
		for (var j in moves[i])		// Check all columns
		{
			count += moves[i][j].length;
		}
	}
	return count;
}

function isFiftyMoveDraw(FEN)
{ // Returns true if the game is drawn due to the fifty move draw rule (no captures or pawn moves)
	return FEN.split(' ')[4] >= 100;
}

function isThirdTimePosDraw(FEN)
{ // Returns true if this is the third time that the exact same position arises with the same side to move
	var currentPos = FEN[FEN.length - 1].split(' ', 4).join(' ');
	var count = 0;
	for (var i = 0; i < FEN.length - 1; i++)
	{
		if(currentPos == FEN[i].split(' ', 4).join(' '))
		{
			count++;
		}
	}
	return count >= 2;
}
