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
  return null;
}

function show(s) {
	hide();
	var id = s.hash.substring(1);
	var obj = getObject(id);
	obj.style.display = 'block';

	// Try to get a reference to an element with the id 'active' (a previously active tab header)
 	var oldActive = getObject('active');
	// If this element exists, remove its ID attribute
	if (oldActive) oldActive.removeAttribute('id');
	// Add the ID attribute with value 'active' to the newly active menu item (LI element)
	s.parentNode.setAttribute('id', 'active');
}

function hide() {
	var toggle = getObject('navlist');
	var as = toggle.getElementsByTagName('a');
	for (var i = 0; i < as.length; i++) {
		var id = as[i].hash.substring(1);
		var obj = getObject(id);
		if(obj) {
			getObject(id).style.display = 'none';
		}
	}
}

window.onload = function() {
	var toggle = getObject('navlist');
	var as = toggle.getElementsByTagName('a');
	for (var i = 0; i < as.length; i++) {
		var id = as[i].hash.substring(1);
		if(getObject(id)) {	// If there is a corresponding element to show/hide
			as[i].onclick = function() {
				show(this);
				return false;
			}
		} else if (as[i].hash == '#reload') {
			as[i].onclick = reload;
		} else if (as[i].hash == '#logout') {
			as[i].onclick = logout;
		}
	}
	show(as[0]);
}


