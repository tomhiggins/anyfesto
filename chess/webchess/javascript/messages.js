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

function MessagePlayer(playerID)
{
        var where="sendmessage.php?to="+playerID;
        var height=400;
        var width=600;
        var left=(screen.availWidth/2)-(width/2);
        var top=(screen.availHeight/2)-(height/2)-100;
        window.open(where,"","height="+height+",width="+width+",left="+left+",top="+top);
}

function HideMessage(messageID)
{
    document.messageHideForm.messageID.value=messageID;
    document.messageHideForm.submit();
}
