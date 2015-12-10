// $Id: isCheckMate.js,v 1.13 2010/08/14 16:57:54 sandking Exp $

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

/*
*****************************************************************************
isCheckMate() pseudocode
*****************************************************************************

1) can king move out of checkmate?
2) can attacker be eaten?
3) can attacker be blocked?


for each of the possible squares the king can move to, use isSafe() to see if king can move there
  if one of them is safe, isCheckMate() = false

from king's position, scan out in all 8 directions to find attackers (note: there may be two!)

for each attacker found:
  - use isSafe() on attacker to see if attacker can be eaten; if so, isCheckMate() = false
  - if the attacker is not a knight
      o then for each square between the attacker and the king:
          . use isSafe() to determine if a move is possible to block the attacker; if so, isCheckMate() = false

if none of these is possible, isCheckMate() = true
*/

/* directions:
    0     1
 2  8  9 10  3
   15  * 11
 4 14 13 12  5
    6     7
 NOTE: directions 0 through 7 are actually positions and represent knights!
*****************************************************************************
  END PSEUDOCODE
*****************************************************************************
*/

/* reset getNextAttacker function */
curDir = -1;

/* IMPORTANT NOTE!!!
   getNextAttacker() will currently only work when called for one situation
   (ie: one set of coords, no changes to board between calls) and as such
   should NOT be used outside of isCheckmate()

   POSSIBLE FIXES:
   - if getNextAttacker() does not need to be nested, reseting the function
     before each call should do the trick
   - build a 3D lookup table based on targetRow, targetCol and targetColor;
     if current parameters exist in table, set curDir to value;
     else add entry to table, reset curDir;
     before exiting getNextAttacker(), update lookup table with curDir
*/
function getNextAttacker(targetRow, targetCol, targetColor, attackerCoords)
{
	var attackerColor = getOtherColor(targetColor);
	while(curDir <= 15)
	{
		var rowStep, colStep;

		/* start next direction */
		curDir++;

		switch(curDir)
		{
			case 0:
				if (isInBoard(targetRow + 2, targetCol - 1))
					if (board[targetRow + 2][targetCol - 1] == getPieceCode(attackerColor, "knight"))
					{
						attackerCoords.row = targetRow + 2;
						attackerCoords.col = targetCol - 1;
						return true;
					}
				break;
			case 1:
				if (isInBoard(targetRow + 2, targetCol + 1))
					if (board[targetRow + 2][targetCol + 1] == getPieceCode(attackerColor, "knight"))
					{
						attackerCoords.row = targetRow + 2;
						attackerCoords.col = targetCol + 1;
						return true;
					}
				break;
			case 2:
				if (isInBoard(targetRow + 1, targetCol - 2))
					if (board[targetRow + 1][targetCol - 2] == getPieceCode(attackerColor, "knight"))
					{
						attackerCoords.row = targetRow + 1;
						attackerCoords.col = targetCol - 2;
						return true;
					}
				break;
			case 3:
				if (isInBoard(targetRow + 1, targetCol + 2))
					if (board[targetRow + 1][targetCol + 2] == getPieceCode(attackerColor, "knight"))
					{
						attackerCoords.row = targetRow + 1;
						attackerCoords.col = targetCol + 2;
						return true;
					}
				break;
			case 4:
				if (isInBoard(targetRow - 1, targetCol - 2))
					if (board[targetRow - 1][targetCol - 2] == getPieceCode(attackerColor, "knight"))
					{
						attackerCoords.row = targetRow - 1;
						attackerCoords.col = targetCol - 2;
						return true;
					}
				break;
			case 5:
				if (isInBoard(targetRow - 1, targetCol + 2))
					if (board[targetRow - 1][targetCol + 2] == getPieceCode(attackerColor, "knight"))
					{
						attackerCoords.row = targetRow - 1;
						attackerCoords.col = targetCol + 2;
						return true;
					}
				break;
			case 6:
				if (isInBoard(targetRow - 2, targetCol - 1))
					if (board[targetRow - 2][targetCol - 1] == getPieceCode(attackerColor, "knight"))
					{
						attackerCoords.row = targetRow - 2;
						attackerCoords.col = targetCol - 1;
						return true;
					}
				break;
			case 7:
				if (isInBoard(targetRow - 2, targetCol + 1))
					if (board[targetRow - 2][targetCol + 1] == getPieceCode(attackerColor, "knight"))
					{
						attackerCoords.row = targetRow - 2;
						attackerCoords.col = targetCol + 1;
						return true;
					}
				break;
			case 8:
				rowStep = 1;
				colStep = -1;
				break;
			case 9:
				rowStep = 1;
				colStep = 0;
				break;
			case 10:
				rowStep = 1;
				colStep = 1;
				break;
			case 11:
				rowStep = 0;
				colStep = 1;
				break;
			case 12:
				rowStep = -1;
				colStep = 1;
				break;
			case 13:
				rowStep = -1;
				colStep = 0;
				break;
			case 14:
				rowStep = -1;
				colStep = -1;
				break;
			case 15:
				rowStep = 0;
				colStep = -1;
				break;
		}

		if (curDir > 7)
		{
			var attackerFound = false;
			var i = 1;
			while (isInBoard(targetRow + (i * rowStep), targetCol + (i * colStep)) && !attackerFound)
			{
				if (board[targetRow + (i * rowStep)][targetCol + (i * colStep)] != 0)
				{
					attackerFound = true;
					if (getPieceColor(board[targetRow + (i * rowStep)][targetCol + (i * colStep)]) == attackerColor)
						if (isAttacking(board[targetRow + (i * rowStep)][targetCol + (i * colStep)], targetRow + (i * rowStep), targetCol + (i * colStep), attackerColor, targetRow, targetCol))
						{
							attackerCoords.row = targetRow + (i * rowStep);
							attackerCoords.col = targetCol + (i * colStep);

							return true;
						}
				}
				i++;
			}
		}
	}

	/* return true if attacker found, false otherwise */
	return false;
}

/* NOTE: isAttacking() assumes no piece exists between attacker and target, such is the case in getNextAttacker() */
function isAttacking(attackerPiece, attackerRow, attackerCol, attackerColor, targetRow, targetCol)
{
	var rowDiff = Math.abs(attackerRow - targetRow);
	var colDiff = Math.abs(attackerCol - targetCol);

	switch(attackerPiece & COLOR_MASK)
	{
		case PAWN:
			var forwardDir = -1;
			if (attackerColor == "white")
				forwardDir = 1;

			if ((colDiff == 1) && ((targetRow - attackerRow) == forwardDir))
				return true;
			break;

		case ROOK:
			if ((rowDiff == 0) || (colDiff == 0))
				return true;
			break;

		case KNIGHT:
			if (((rowDiff == 2) && (colDiff == 1)) || ((rowDiff == 1) && (colDiff == 2)))
				return true;
			break;

		case BISHOP:
			if (rowDiff == colDiff)
				return true;
			break;

		case QUEEN:
			if ((rowDiff == 0) || (colDiff == 0) || (rowDiff == colDiff))
				return true;
			break;

		case KING:
			if ((rowDiff <= 1) && (colDiff <= 1))
				return true;
			break;
	}

	return false;
}

function canBlockAttacker(attackerPiece, attackerRow, attackerCol, attackerColor, targetRow, targetCol)
{
	var tmpAttackerPiece = attackerPiece & COLOR_MASK;

	/* Knights can never be blocked */
	if (tmpAttackerPiece == KNIGHT)
		return false;

	/* setup loop parameters */
	var rowDiff = attackerRow - targetRow;
	var colDiff = attackerCol - targetCol;

	var rowStep = 0;
	if (rowDiff != 0)
		rowStep = rowDiff / Math.abs(rowDiff);

	var colStep = 0;
	if (colDiff != 0)
		colStep = colDiff / Math.abs(colDiff);

	var numSteps = Math.max(Math.abs(rowDiff), Math.abs(colDiff));
	var ennemyPawn = BLACK | PAWN;
	if (attackerColor == "black")
	{
		ennemyPawn = WHITE | PAWN;
	}

	/* for each square between the attacker and the target... */
	for (var i = 1; i < numSteps; i++)
	{

		/* if a piece of the target's color can move there, the attack can be blocked */
		if(DEBUG)
		{
			alert("Checking square (" + (targetRow + (i*rowStep)) + "," + (targetCol + (i*colStep)) + ")");
		}

		if (canSquareBeBlocked(targetRow + (i * rowStep), targetCol + (i * colStep), attackerColor))
		{
			if(DEBUG)
			{
				alert("canBeBlocked() -> some piece can move into (" + (targetRow + (i * rowStep)) + "," + (targetCol + (i*colStep)) + ")");
			}

			return true;
		}

	}

	return false;
}

function isCheckMate(curColor, epCol)
{
	var kingRow = 0;
	var kingCol = 0;
	var targetKing = getPieceCode(curColor, "king");

	/* find king */
	for (var i = 0; i < 8; i++)
		for (var j = 0; j < 8; j++)
			if (board[i][j] == targetKing)
			{
				kingRow = i;
				kingCol = j;
			}

//	inform('Color:' + curColor + ' kingrow: ' + kingRow + ' kingCol:  ' + kingCol);
	/* check the squares around the king for a safe move (including squares occupied by enemy pieces */
	/* Note that in case of a double check this exhausts all possible moves to avoid checkmate  */
	for (var i = -1; i <= 1; i++)
	{ // For each row
		for (var j = -1; j <= 1; j++)
		{ // And for each column
			if (((i != 0) || (j != 0)) && isInBoard(kingRow + i, kingCol + j))
			{ // If the row and col is part of the board..
				if (isValidMoveKing(kingRow, kingCol, kingRow + i, kingCol + j, curColor))	// DJ: Fixed
				{ // If the king is safe to move
					if (DEBUG)
					{
						alert("King can move into a safe square!");
					}
					return false; // Then it's not a check mate
				}
			}
		}
	} /* RF - Added braces for readability/reliability */

//	inform(curColor + ' king cannot move to a safe square');
	var attackerColor = getOtherColor(curColor);

	/* reset getNextAttacker function */
	curDir = -1;

	/* find the attacker(s)... (can be two) */
	var attackerCoords = {row:0, col:0};
	if (getNextAttacker(kingRow, kingCol, curColor, attackerCoords))
	{
		var attackerRow = attackerCoords.row;
		var attackerCol = attackerCoords.col;

		/* in case of double check (two attackers) it's checkmate.*/
		/* There is no way to block or capture both */
		/* (we already checked if king may move) */
		if (getNextAttacker(kingRow, kingCol, curColor, attackerCoords))
		{
//			inform('Double check with checkmate');
			return true;
		}

		/* can attacker be captured */
		var isEnPrise = canBeCaptured(attackerRow, attackerCol, epCol);

		/* can attacker be blocked */
		var canBeBlocked = false;
		if (canBlockAttacker(board[attackerRow][attackerCol], attackerRow, attackerCol, attackerColor, kingRow, kingCol))
			canBeBlocked = true;

		if (DEBUG)
		{
			if(canBeBlocked)
				alert("can be blocked");
			else
				alert("Can't be blocked");
			if(isEnPrise)
				alert("can be captured");
			else
				alert("Can't be captured");
		}

//		inform('isEnPrise: ' + isEnPrise + ' canBeBlocked: ' + canBeBlocked);
		if (!isEnPrise && !canBeBlocked)
			return true;
	} else {
//		inform('No attacker found');
	}

//	inform('Not checkmate');
	return false;
}
