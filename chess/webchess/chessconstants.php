<?php
	// $Id: chessconstants.php,v 1.4 2010/08/14 16:57:54 sandking Exp $

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

	/* define constants */
	define ("EMPTY", 0);	/* 0000 0000 */
	define ("PAWN", 1);	/* 0000 0001 */
	define ("KNIGHT", 2);	/* 0000 0010 */
	define ("BISHOP", 4);	/* 0000 0100 */
	define ("ROOK", 8);	/* 0000 1000 */
	define ("QUEEN", 16);	/* 0001 0000 */
	define ("KING", 32);	/* 0010 0000 */
	define ("BLACK", 128);	/* 1000 0000 */
	define ("WHITE", 0);
	define ("COLOR_MASK", 127);	/* 0111 1111 */
?>
