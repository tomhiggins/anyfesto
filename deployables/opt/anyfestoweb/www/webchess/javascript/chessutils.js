// $Id: chessutils.js,v 1.8 2010/08/18 02:48:19 sandking Exp $

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

 /* these are utility functions used by other functions */
var Files = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'];

var pieceNameToLtr = new Array();
pieceNameToLtr = {'king':'k', 'queen':'q', 'rook':'r', 'bishop':'b', 'knight':'n', 'pawn':'p'};

var pieceLtrToName = new Array();
pieceLtrToName = {'k':'king', 'q':'queen', 'r':'rook', 'b':'bishop', 'n':'knight', 'p':'pawn'};

var pieceColor = new Array();
pieceColor = {'K':'w', 'Q':'w', 'R':'w', 'B':'w', 'N':'w', 'P':'w',
			  'k':'b', 'q':'b', 'r':'b', 'b':'b', 'n':'b', 'p':'b'};

var colorLtrToName = new Array();
colorLtrToName = {'w':'white', 'b':'black'};

function isInBoard(row, col)
{
	if ((row >= 0) && (row <= 7) && (col >= 0) && (col <= 7))
		return true;
	else
		return false;
}

	function getPieceColor(piece)
	{
		if (BLACK & piece)
			return "black";
		else
			return "white";
	}

	function getPieceName(piece)
	{
		var pieceName = new Array();
		pieceName[PAWN] = "pawn";
		pieceName[ROOK] = "rook";
		pieceName[KNIGHT] = "knight";
		pieceName[BISHOP] = "bishop";
		pieceName[QUEEN] = "queen";
		pieceName[KING] = "king";

		return pieceName[piece & COLOR_MASK];
	}

	function getPieceCode(color, piece)
	{
		var code;
		switch(piece)
		{
			case "pawn":
				code = PAWN;
				break;
			case "knight":
				code = KNIGHT;
				break;
			case "bishop":
				code = BISHOP;
				break;
			case "rook":
				code = ROOK;
				break;
			case "queen":
				code = QUEEN;
				break;
			case "king":
				code = KING;
				break;
		}

		if (color == "black")
			code = BLACK | code;

		return code;
	}

	var tmpOriginalClassName = "";

	function highlight(row, col)
	{
		if (board[parseInt(row)][parseInt(col)] != "")
		{
			var square = parseInt(row) * 8 + parseInt(col);
			tmpOriginalClassName = document.getElementById("tsq" + square).className;
			document.getElementById("tsq" + square).className = "highlighted";
		}

		return true;
	}

	function unhighlight(row, col)
	{
		if (DEBUG)
			alert("unhighlight -> row = " + row + ", col = " + col);


		if (board[parseInt(row)][parseInt(col)] != "")
		{
			var square = parseInt(row) * 8 + parseInt(col);
			document.getElementById("tsq" + square).className = tmpOriginalClassName;
		}

		return true;
	}

	function getOtherColor(color)
	{
		if (color == "white")
			return "black";
		else
			return "white";
	}

//
// FEN functions
//

function ExpandFEN(FEN) {
  var ones = new Array ('', '1' ,'11', '111', '1111', '11111', '111111', '1111111', '11111111');
  var theFEN = '';
  for(var i=0; i < FEN.length; i++) {
    if(FEN.charAt(i) > '1' && FEN.charAt(i) < '9') {
      theFEN += (ones[Number(FEN.charAt(i))]);
    } else {
      theFEN = theFEN + '' +  FEN.charAt(i);
    }
  }
  return theFEN.replace(/\//g, "");                     // Leave only pieces and empty squares
///////////// The following caused an error (only) in IE5. Replaced with the above code
  var theFEN = FEN.replace(/[2-8]/g,	// Expand contiguous empty squares
    function strRepeat(count) {			//   e.g. change '4' to '1111'
      var strOut = '';
      for(var i=0; i < count; i++) {
       strOut += '1';
      }
     return strOut;
    }
  );
  return theFEN.replace(/\//g, "");		// Leave only pieces and empty squares
}

function SetSquare(Square, Piece) {
  var rank = 7 - parseInt(Square / 8);
  var file = Square % 8;
  var s;
  if(Piece == '1') {
    s = 0;
  } else {
    s = getPieceCode(colorLtrToName[pieceColor[Piece]], pieceLtrToName[Piece.toLowerCase()]);
  }
  board[rank][file] = s;
}

function FENToBoard(FEN) {
  var FENItems = new Array();
  FENItems = FEN.split(' ');
  var ExpFEN = ExpandFEN(FENItems[0]);
  var c;
  for(var i=0; i < 64; i++) {
    c = ExpFEN.charAt(i);
    SetSquare(i, c);
  }
  curColor = colorLtrToName[FENItems[1]];
};

function PackFEN(piecePlacement, activeColor, castlingAvail, epSquare, halfmoveClock, fullmoveNumber)
{ // Pack all the FEN fields into one string
	var FEN = '';
	var idx = 0;
	var empty = 0;
	var c = '';
	for(var i=0; i < 64; i++)
	{ // Generate the correct piece placement string
		if(i > 0 && (i % 8 == 0))
		{ // New row
			if(empty > 0)
			{ // Count of empty squares does not continue across rows
				FEN += empty + "";
				empty = 0;
				idx++;
			}
			FEN += '/';	// New row
		}
		c = piecePlacement.charAt(i);
		if(c == '1')
		{ // Count consecutive empty squares
			empty++;
		}
		else
		{ // Non-empty square
			if(empty > 0)
			{ // Add the number of consecutive empty squares to the output string
				FEN += empty + "";
				empty = 0;
				idx++;
			}
			FEN += c + "";
			idx++;
		}
	}
	if(empty > 0)
	{
		FEN += empty + "";
	}
	return FEN + ' ' + activeColor + ' ' + castlingAvail + ' ' + epSquare + ' ' + halfmoveClock + ' ' + fullmoveNumber;
}

function getFENStartPos()
{
	return 'rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1';
}

// Returns an array of FEN strings for the current game
// Note that this function assumes that the game started from the normal initial position
function historyToFEN()
{
	var FEN = new Array();
	FEN[0] = getFENStartPos();	// The start position
	var activeColor = 'w';
	var wKS = 'K';	// Castling availability
	var wQS = 'Q';
	var bKS = 'k';
	var bQS = 'q';
	var castlingAvail = 'KQkq';
	var epSquare = '-';	// The en passant square
	var halfmoveClock = 0;	// Number of half moves since last capture or pawn move
	var fullmoveNumber = 1;	// The move number
	var piece = '';
	for (var i = 0; i <= numMoves; i++)
	{
		FEN[i+1] = ExpandFEN(FEN[i]).slice(0, 64);	// Get the piece placement from the FEN string
		if(chessHistory[i][CURCOLOR] == 'white')
			activeColor = 'b';
		else
		{
			activeColor = 'w';
			fullmoveNumber++;
		}
		var fromCol = chessHistory[i][FROMCOL];
		var fromRow = chessHistory[i][FROMROW];
		var row = chessHistory[i][TOROW];
		var col = chessHistory[i][TOCOL];
		if(FEN[i+1].charAt(col + (7 - row) * 8) != '1' || chessHistory[i][CURPIECE] == 'pawn')
			halfmoveClock = 0;	// Restart the count after pawn move or capture
		else
			halfmoveClock++;
		if(typeof chessHistory[i][PROMOTEDTO] == "undefined")
			piece = FEN[i+1].charAt((7 - fromRow) * 8 + fromCol);
		else
		{
			piece = pieceNameToLtr[chessHistory[i][PROMOTEDTO]];
			if(chessHistory[i][CURCOLOR] == 'white')
				piece = piece.toUpperCase();
		}
		FEN[i+1] = FEN[i+1].slice(0, (7 - fromRow) * 8 + fromCol) + '1' + FEN[i+1].slice((7 - fromRow) * 8 + fromCol + 1);
		FEN[i+1] = FEN[i+1].slice(0, (7 - row) * 8 + col) + piece + FEN[i+1].slice((7 - row) * 8 + col + 1);

		if (chessHistory[i][CURPIECE] == 'king')
		{ // Can't castle after the king has been moved
			if(chessHistory[i][CURCOLOR] == 'white')
			{
				wKS = '';
				wQS = '';
			}
			else
			{
				bKS = '';
				bQS = '';
			}
			/* if this is a castling move the rook must also be moved */
			if (Math.abs(col - fromCol) == 2)
			{	// The king only moves two squares when castling
				var rookCol = 0;
				var rookToCol = 3
				if (col - fromCol == 2)
				{	// Kingside castling (would be == -2 if queenside)
					rookCol = 7;
					rookToCol = 5;
				}
				FEN[i+1] = FEN[i+1].slice(0, (7 - row) * 8 + rookToCol) + FEN[i+1].charAt((7 - row) * 8 + rookCol) + FEN[i+1].slice((7 - row) * 8 + rookToCol + 1);
				FEN[i+1] = FEN[i+1].slice(0, (7 - row) * 8 + rookCol) + '1' + FEN[i+1].slice((7 - row) * 8 + rookCol + 1);
			}
		}
		else if (chessHistory[i][CURPIECE] == 'rook')
		{
			if(chessHistory[i][CURCOLOR] == 'white')
			{
				if(fromRow == 0)
				{
					if(fromCol == 0)
						wQS = '';
					else
						wKS = '';
				}
			}
			else
			{
				if(fromRow == 7)
				{
					if(fromCol == 0)
						bQS = '';
					else
						bKS = '';
				}
			}
		}
		else if(chessHistory[i][CURPIECE] == 'pawn' && Math.abs(chessHistory[i][TOROW] - chessHistory[i][FROMROW]) == 2)
		{ // Pawn double advance, so en passant capture may be possible on the next move
			if(chessHistory[i][CURCOLOR] == 'white')
			{
				epSquare = Files[fromCol] + '3';
			}
			else
			{
				epSquare = Files[fromCol] + '6';
			}
		}
		castlingAvail = wKS + wQS + bKS + bQS;
		if(castlingAvail == '')
			castlingAvail = '-';
		FEN[i+1] = PackFEN(FEN[i+1], activeColor, castlingAvail, epSquare, halfmoveClock, fullmoveNumber);
		epSquare = '-';
	}
	return FEN;
}
