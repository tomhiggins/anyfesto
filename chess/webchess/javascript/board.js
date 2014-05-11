// $Id: board.js,v 1.9 2010/08/18 00:32:24 sandking Exp $

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

function getObject(obj) {
  if (document.getElementById) {  // Mozilla, FireFox, Explorer 5+, Opera 5+, Konqueror, Safari, iCab, Ice, OmniWeb 4.5
    if (typeof obj == "string") {
      if(document.getElementById(obj)) {
        return document.getElementById(obj);
      } else {
        return document.getElementsByName(obj)[0];
      }
    } else {
      return obj.style;
    }
  }
  if (document.all) {				// Explorer 4+, Opera 6+, iCab, Ice, Omniweb 4.2-
    if (typeof obj == "string") {
      return document.all(obj);
    } else {
      return obj.style;
    }
  }
  if (document.layers) {			// Netscape 4, Ice, Escape, Omniweb 4.2-
    if (typeof obj == "string") {
      return document.layers(obj);
    } else {
      return obj.style;
    }
  }
  alert('Object not found: ' + obj);
}

function isGameDrawn()
{
	// Stalemate?
	if(isKingInCheck != '1')
	{	// Not in check
		var myColor = WHITE;
		if(numMoves >= 0 && chessHistory[numMoves][CURCOLOR] == 'white')
			 myColor = BLACK;
		if(countMoves(myColor) == 0)
		{
			alert('Stalemate - You should offer your opponent a draw');
		}
	}

	// Is the game drawn due to insufficient material to checkmate?
	var count = 0;
	var canCheckmate = false;
	for (var i = 0; i < 8; i++)
	{
		for (var j = 0; j < 8; j++)
			if(board[i][j] != 0 && (board[i][j] & COLOR_MASK) != KING)
			{
				if((board[i][j] & COLOR_MASK) != KNIGHT && (board[i][j] & COLOR_MASK) != BISHOP)
					canCheckmate = true;
				else
					count++;
			}
	}
	if(count < 2 && !canCheckmate)
	{
		alert('Insufficient material to checkmate - You should offer your opponent a draw');
	}

	// Is the game drawn because this is the third time that the exact same position arises?
	if(numMoves >= 0 && isThirdTimePosDraw(theFEN))
	{
		alert('Draw (this position has occurred three times) - You should offer your opponent a draw')
	}

	// Draw because of no capture of pawn move for the last 50 moves?
	if(numMoves >= 0 && isFiftyMoveDraw(theFEN[theFEN.length-1]))
	{
		alert('Draw (50 move rule) - You should offer your opponent a draw');
	}
}

function displayCaptPieces() {
	var color = 'white';
	var html = '<div>';
	var piece = '';
	for(var i=0; i < captPieces.length; i++)
	{
		for(var j=0; j < captPieces[i].length; j++)
		{
			piece = color + '_' + captPieces[i][j];
			html += '<img src="images/' + CURRENTTHEME + '/' + piece + '.' + cfgImageExt + '" width="';
			html += parseInt(squareSize * 3 / 5) + '" height="' + parseInt(squareSize * 3 / 5) + '" alt="' + piece + '" />';
		}
		html += "</div>\n<div>";
		color = 'black';
	}
	html += '</div>';
	getObject('captures').innerHTML = html;
}

function unhighlightCurMove()
{
	var square = chessHistory[numMoves][FROMROW] * 8 + chessHistory[numMoves][FROMCOL];
	var bgCol = '';
	if(square % 8 < 6)
		bgCol = getObject('tsq' + (square + 2) + '').style.backgroundColor;
	else
		bgCol = getObject('tsq' + (square - 2) + '').style.backgroundColor;

	getObject('tsq' + square + '').style.backgroundColor = bgCol;
	unhighlight(chessHistory[numMoves][TOROW], chessHistory[numMoves][TOCOL]);
}

function highlightCurMove()
{
	getObject('tsq' + (chessHistory[numMoves][FROMROW] * 8 + chessHistory[numMoves][FROMCOL]) + '').style.backgroundColor = '#FF0';
	setTimeout('highlight(chessHistory[numMoves][TOROW], chessHistory[numMoves][TOCOL])', 200);
	setTimeout('unhighlightCurMove()', 750);
}

function drawCoordinates(invertBoard) {
  var i, j;
  for(i = 1; i < 9; i++) {
    if(!invertBoard) {
      j = i;
    } else {
      j = 9 - i;
    }
    getObject('rank'+i).innerHTML = j;
    getObject('file'+(i-1)).innerHTML = Files[j-1];
  }
}

function moveTo(objMoveId)
{
	if(currMoveIdx > 0)
	{
		getObject('m' + currMoveIdx + '').style.backgroundColor = '#F5F5DC';
	}
	currMoveIdx = objMoveId.id.slice(1);
	currMoveIdx = parseInt(currMoveIdx);
	FENToBoard(theFEN[currMoveIdx]);
	var theBoard = htmlBoard();
	getObject('chessboard').innerHTML = theBoard;
	drawCoordinates(perspective == 'black');
	getObject('m' + currMoveIdx + '').style.backgroundColor = '#3C86F6';
}

function moveJmp(moveDelta)
{
	var moveIdx = currMoveIdx;
	if(moveIdx + moveDelta > theFEN.length - 1)
	{
		moveIdx = theFEN.length - 1;
	}
	else if(moveIdx + moveDelta < 0)
	{
		moveIdx = 0;
	}
	else
	{
		moveIdx += moveDelta;
	}
	moveTo(getObject('m' + moveIdx + ''));
}

function displayMovesColumns() {
	var objGamebody = getObject('gamebody');
	var theMoves = '<span id="m0"></span>';
	var moveId = 1;
	theMoves += '<div align="center" style="padding-top:5px; padding-bottom:5px;"><table cellpadding="0" cellspacing="0" style="padding:0; border-collapse: collapse;border-spacing:0;" width="225px">';
	for(var i = 0; i < moves.length; i++)
	{
		if(isGameOver == '1')
		{
			theMoves += '<tr><td class="mn" style="border:1px solid #888; text-align:right;">' + (i+1) + '. </td>';
			theMoves += '<td id="m' + (moveId) + '" class="wm" ' + 'onclick="moveTo(this);" style="border:1px solid #888;">' + moves[i][0] + '</td>';
			theMoves += '<td id="m' + (moveId+1) + '" class="bm" ' + 'onclick="moveTo(this);" style="border:1px solid #888;"> ' + moves[i][1] + '</td></tr>';
			moveId = moveId + 2;
		}
		else
		{
			theMoves += '<tr><td class="mn" style="border:1px solid #888; text-align:right;">' + (i+1) + '.</td> <td class="wm" style="border:1px solid #888;">';
			theMoves += moves[i][0] + '</td><td style="border:1px solid #888;"> ' + moves[i][1] + '</td></tr>';
		}
	}
	theMoves += '</table></div>';
	objGamebody.innerHTML = theMoves;
}

function displayMovesParagraph() {
	var objGamebody = getObject('gamebody');
	var theMoves = '<span id="m0"></span>';
	var moveId = 1;
	for(var i = 0; i < moves.length; i++)
	{
		if(isGameOver == '1')
		{
			theMoves += '<span id="m' + moveId++ + '" class="wm" ' + 'onclick="moveTo(this);"><span class="mn">' + (i+1) + '.</span> ' + moves[i][0] + '</span>';
			theMoves += '<span id="m' + moveId++ + '" class="bm" ' + 'onclick="moveTo(this);"> ' + moves[i][1] + '</span> ';
		}
		else
		{
			theMoves += '<span class="wm"><span class="mn">' + (i+1) + '.</span> ' + moves[i][0] + '</span> ' + moves[i][1] + ' ';
		}
	}
	objGamebody.innerHTML = theMoves;
}

function displayMoves() {
	if(historyLayout == 'columns')
		displayMovesColumns();
	else
		displayMovesParagraph();
}

function htmlBoard()
{	// Returns the HTML-code for an empty chessboard (Note: Fixed square size and theme)
	if(isBoardDisabled == '')
	{
		var classWSquare = 'light_enabled';
		var classBSquare = 'dark_enabled';
		var classHeader = 'header_enabled';
	}
	else
	{
		var classWSquare = 'light_disabled';
		var classBSquare = 'dark_disabled';
		var classHeader = 'header_disabled';
	}
	var sqBackground = [classWSquare, classBSquare];
	var invertBoard = (perspective == 'black');
	var borderWidth = squareSize / 2;
	var rank = 8;
	var rankLabel = rank;
	if(invertBoard)
	{
		rankLabel = 1
	}
	var j = 1;

	theBoard = '<table id="theBoard" cellpadding="0" style="border:1px solid #888; padding:0; border-collapse: collapse;border-spacing:0; margin-bottom:5px;">';
	theBoard += '<tr id="bordertop" style="height:' + borderWidth + 'px;"><td colspan="10" class="' + classHeader + '">&nbsp;</td></tr>';
	theBoard += '<tr><td id="rank' + rank-- + '" class="' + classHeader + '" width="' + borderWidth + '">' + rankLabel + '</td>';
	var row = 0;
	var col = 0;
	for(var k = 63; k >= 0; k--)
	{
		if((k+1) % 8 == 0)
		{
			var i = k - 7;
			if(invertBoard)
				i = 63 - i;
		}
		else
		{
			if(invertBoard)
				i--;
			else
				i++;
		}
		theBoard += '<td id="tsq' + i + '" class="' + sqBackground[j] + '" width="' + squareSize + '" height="' + squareSize + '">';
		var piece = '';
		var source = '';
		row = parseInt(i / 8);
		col = i % 8;
		if(board[row][col] != 0)
		{
			piece = getPieceColor(board[row][col]) + '_' + getPieceName(board[row][col]);
			source = 'images/' + CURRENTTHEME + '/' + piece + '.' + cfgImageExt;	// Update the square
			theBoard += '<img alt="' + piece + '" id="sq' + i + '" ';
			theBoard += 'src="' + source + '" width="' + squareSize + '" height="' + squareSize + '">';
		}
		else
		{
			theBoard += '&nbsp;';
		}
		theBoard += '<\/td>';
		if((k % 8) === 0) {
			theBoard += '<td id="rbrd' + (rank+1) + '" class="' + classHeader + '" width=' + borderWidth + '">&nbsp;<\/td><\/tr>';
			if(k != 0) {
				if(invertBoard)
				{
					rankLabel = 9 - rank;
				}
				else
				{
					rankLabel = rank;
				}
				theBoard += '<tr><td id="rank' + rank-- + '" class="' + classHeader + '" width="' + borderWidth + '">' + rankLabel + '</td>';
			}
		}
		else
		{
			j = 1 - j;
		}
	}
	theBoard += '<tr id="borderbottom" class="' + classHeader + '" height="' + borderWidth + '"><td width="' + borderWidth + '">&nbsp;<\/td>';
	var fileLabel;
	for(i = 0; i < 8; i++) {
		if(invertBoard) {
			fileLabel = Files[7-i];
		}
		else
		{
			fileLabel = Files[i];
		}
		theBoard += '<td id="file' + i + '" class="' + classHeader + '">' + fileLabel + '<\/td>';
	}
	theBoard += '<td id="rbrd0" class="' + classHeader + '">&nbsp;<\/td><\/tr><\/table>';
	return theBoard;
}

var theBoard = htmlBoard();	// The HTML code for the board
var theFEN = new Array();
var currMoveIdx = 0;

window.onload = function ()
{
	var invertBoard = (perspective == 'black');
	getObject('chessboard').innerHTML = theBoard;
//	drawCoordinates(invertBoard);
/*
	var tblBoard = document.createElement('table');
	var tbody = document.createElement('tbody');
	tblBoard.appendChild(tbody);
	var row = document.createElement('tr');
	var col1 = document.createElement('td');
	col1.appendChild(document.createTextNode('Prufutexti'));
	row.appendChild(col1);
	tbody.appendChild(row);
	getObject('chessboard').appendChild(tblBoard);
*/

	// Display the current move below the chessboard
	if(moves.length > 0)
	{
		var lastMove = moves.length + '.';
		if(moves[moves.length-1][1] != '')
		{
			getObject('curmove').innerHTML = lastMove + '..' + moves[moves.length-1][1];
		}
		else
		{
			getObject('curmove').innerHTML = lastMove + ' ' + moves[moves.length-1][0];
		}
		if(isGameOver != '1')
			getObject("curmove").onclick = function(){highlightCurMove();};
	}
	getObject('gameid').innerHTML = 'Game #' + gameId;
	getObject('players').innerHTML = players;
	getObject('whosmove').innerHTML = whosMove;
	getObject('checkmsg').innerHTML = checkMsg;
	getObject('statusmsg').innerHTML = statusMessage;
	displayMoves();
	displayCaptPieces();

	theFEN = historyToFEN();

	getObject("btnMainMenu").disabled = false;
	getObject("btnReload").disabled = false;
	getObject("btnPGN").disabled = false;
	getObject("btnLogout").disabled = false;

	getObject("btnMainMenu").onclick = function(){displayMainmenu();};
	getObject("btnReload").onclick = function(){reloadPage(this);};
	getObject("btnPGN").onclick = function(){downloadPGN();};
	getObject("btnLogout").onclick = function(){logout();};

	getObject("btnUndo").onclick = function(){undo();};
	getObject("btnDraw").onclick = function(){draw();};
	getObject("btnResign").onclick = function(){resigngame();};

	if(isBoardDisabled != '1')
	{
		getObject("btnUndo").disabled = false;
		getObject("btnDraw").disabled = false;
		getObject("btnResign").disabled = false;
	}
	if(isGameOver == '1')
	{ // Allow game replay
		getObject('gamebuttons').style.display = 'none';
		currMoveIdx = theFEN.length - 1;
		var navButtons = '<form id="navigation" action="">';
		navButtons += '<span id="navbuttons">';
		navButtons += '<input id="start" title="Start of game" type="button" value="Start" />';
		navButtons += '<input id="jmpback" title="Go back five halfmoves" type="button" value="&nbsp;&lt;&lt;&nbsp;" />';
		navButtons += '<input id="prev" title="Go back one halfmove" type="button" value="&nbsp;&lt;&nbsp;" />';
		navButtons += '<input id="next" title="Go forward one halfmove" type="button" value="&nbsp;&gt;&nbsp;" />';
		navButtons += '<input id="jmpfwd" title="Go forward five halfmoves" type="button" value="&nbsp;&gt;&gt;&nbsp;" />';
		navButtons += '<input id="end" title="End of game" type="button" value="End" />';
		navButtons += '</span>';
		navButtons += '</form>';
		getObject('gamenav').innerHTML = navButtons;
		getObject("start").onclick = function(){moveJmp(-10000);};
		getObject("jmpback").onclick = function(){moveJmp(-5);};
		getObject("prev").onclick = function(){moveJmp(-1);};
		getObject("next").onclick = function(){moveJmp(1);};
		getObject("jmpfwd").onclick = function(){moveJmp(5);};
		getObject("end").onclick = function(){moveJmp(10000);};
	}
	else
	{ // Alert the players it's stalemate, 50 move draw or the same position has occurred three times
		isGameDrawn();
	}

	if(isPlayersTurn == '1')
	{ // No need to set event handlers unless it's the player's move
		for(var i=0; i < 64; i++) {
			getObject("tsq" + i).onclick = function(){squareClicked(this);};
		}
	}

	if(autoreload > 0)
    	var intervalId = setInterval("window.location.replace('chess.php?autoreload=yes')", autoreload * 1000);
}
