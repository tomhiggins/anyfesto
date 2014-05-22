<?

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

$GETTEXT_SUPPORT = false;

if ( ! function_exists('gettext')) {
	function gettext($text) {
		return $text;
	}
}

// Must do some testing before releasing it to mainstream
if($GETTEXT_SUPPORT) {
	//$LANGUAGE = 'es_ES';
	$LANGUAGE = 'en_US';

	putenv("LANG=$LANGUAGE"); 
	setlocale(LC_ALL, $LANGUAGE);

	// Set the text domain as 'webchess'
	$domain = 'webchess';
	bindtextdomain($domain, "./locale"); 
	textdomain($domain);
}
?>
