<?php
/*
    This file is part of WebChess. http://webchess.sourceforge.net
	Copyright 2010 Jonathan Evraire, Rodrigo Flores, rigao

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

/*******************************************************************************
 *                                                                             *
 *        This block of functions creates the table-system of WebChess.        *
 *                                                                             *
 ******************************************************************************/
//ToDo: The probing algoritm must check inside tables to see if it has all its fields.
function tableExists($tablename) {
	$SQLQuery = "SHOW TABLES";
	$Result = mysql_query($SQLQuery);
	while($Row=mysql_fetch_row($Result)){
		if($Row[0]==$tablename){
			return true;
		}
	}
	return false;
}

function createTableGames(){
	$SQLCreateTableGames = "CREATE TABLE games (
		gameID SMALLINT NOT NULL AUTO_INCREMENT PRIMARY KEY,
		whitePlayer MEDIUMINT NOT NULL,
		blackPlayer MEDIUMINT NOT NULL,
		gameMessage ENUM('playerInvited', 'inviteDeclined', 'draw', 'playerResigned', 'checkMate') NULL,
		messageFrom ENUM('black', 'white') NULL,
		dateCreated DATETIME NOT NULL,
		lastMove DATETIME NOT NULL
	);";
	$Result = mysql_query($SQLCreateTableGames);
        return $Result;
}

function createTableHistory(){
	$SQLCreateTableHistory = "CREATE TABLE history (
		timeOfMove DATETIME NOT NULL,
		gameID SMALLINT NOT NULL,
		curPiece ENUM('pawn', 'bishop', 'knight', 'rook', 'queen', 'king') NOT NULL,
		curColor ENUM('white', 'black') NOT NULL,
		fromRow SMALLINT NOT NULL,
		fromCol SMALLINT NOT NULL,
		toRow SMALLINT NOT NULL,
		toCol SMALLINT NOT NULL,
		replaced ENUM('pawn', 'bishop', 'knight', 'rook', 'queen', 'king') NULL,
		promotedTo ENUM('pawn', 'bishop', 'knight', 'rook', 'queen', 'king') NULL,
		isInCheck BOOL NOT NULL,
		PRIMARY KEY(timeOfMove, gameID)
	);";
	$Result = mysql_query($SQLCreateTableHistory);
        return $Result;
}

function createTableMessages() {
	$SQLCreateTableMessages = "CREATE TABLE messages (
		msgID INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
		gameID SMALLINT NOT NULL,
		msgType ENUM('undo', 'draw') NOT NULL,
		msgStatus ENUM('request', 'approved', 'denied') NOT NULL,
		destination ENUM('black', 'white') NOT NULL
	);";
	$Result = mysql_query($SQLCreateTableMessages);
        return $Result;
}

function createTablePieces(){
	$SQLCreateTablePieces = "CREATE TABLE pieces (
		gameID SMALLINT NOT NULL,
		color ENUM('white','black') NOT NULL,
		piece ENUM('pawn','rook','knight','bishop','queen','king') NOT NULL,
		col SMALLINT NOT NULL,
		row SMALLINT NOT NULL
	);";
	$Result = mysql_query($SQLCreateTablePieces);
        return $Result;
}

function createTablePlayers(){
	$SQLCreateTablePlayers = "CREATE TABLE players (
		playerID INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
		password CHAR(16) NOT NULL,
		firstName CHAR(20) NOT NULL,
		lastName CHAR(20) NOT NULL,
		nick CHAR(20) NOT NULL UNIQUE,
		lastAccess DATETIME
	);";
	$Result = mysql_query($SQLCreateTablePlayers);
        return $Result;
}

function tablePlayersHasLastAccessField() {
	$SQLUpdateTablePlayers = "EXPLAIN players;";
	$Result = mysql_query($SQLUpdateTablePlayers);
	while($Row=mysql_fetch_row($Result)){
		if($Row[0]=="lastAccess"){
			return true;
		}
	}
	return false;
        return $Result;
}

function addLastAccessFieldToPlayersTable() {
	$SQLUpdateTablePlayers = "ALTER TABLE 'players' ADD 'lastAccess' DATETIME;";
	$Result = mysql_query($SQLUpdateTablePlayers);
        return $Result;
}

function createTablePreferences() {
	$SQLCreateTablePreferences = "CREATE TABLE preferences (
		playerID INT NOT NULL,
		preference CHAR(20) NOT NULL,
		value CHAR(50) NULL,
		PRIMARY KEY(playerID, preference)
	);";
	$Result = mysql_query($SQLCreateTablePreferences);
        return $Result;
}

function createTableCommunication() {
	$SQLCreateTableCommunication = "CREATE TABLE communication (
	  commID smallint(6) NOT NULL auto_increment,
	  gameID smallint(6) default NULL,
	  fromID mediumint(9) default NULL,
	  toID mediumint(9) default NULL,
	  title varchar(255) default NULL,
	  text longtext,
	  postDate datetime NOT NULL default '0000-00-00 00:00:00',
	  expireDate datetime default '0000-00-00 00:00:00',
	  ack tinyint(4) default '0',
	  commType smallint(6) default '0',
	  PRIMARY KEY  (commID)
	);";
	$Result = mysql_query($SQLCreateTableCommunication);
        return $Result;
}

function insertSampleFieldIntoCommunications() {
	$SQLInsertIntoCommunication = "INSERT INTO communication
	(gameID,fromID,toID,title,text,postDate,expireDate,ack,commType)
	VALUES (NULL,NULL,NULL,'Database Upgrade tSuccessfull','If you see this message
	then the communication table was created successfully... this will allow players
	and admins to communicate with each other by posting
	messages.',NOW(),'0000-00-00 00:00:00','0','0');";
	$Result = mysql_query($SQLInsertIntoCommunication);
        return $Result;
}

function writeLogFile($message) {
	if (! $logfile = fopen("install.log", "a+") ) {
		echo "ERROR! Couldn't open log file!";
		exit(0);
	}
	fwrite($logfile, $message);
	fclose($logfile);
}

//This function just show the error message when creating the tables.
//ToDo: it must accept internationalization.
function showMessage($message){
   if ($message==1) {
      echo "Table created successfully.<br>";
   } else {
      echo "There was a <b><u>problem</u></b> creating the table and it was not created.<br>";
   }
}

//This function just show the error message when a table already exists and
//we are not going to create it.
//ToDo: Internationalization.
//ToDo: The probing algoritm must check inside tables to see if it has all its fields.
function showProbingMessage($message){
   if ($message==1) {
      echo "Table already exists. Nothing done.<br>";
   } else {
      echo "Table does not exist, the installer will try to create it.<br>";
   }
}

//This function must log in the mysql server using the $user/$password info
//and create the database named $DBname. Obviously, it won't be called if the
//user does not have direct access to the MySQL server, as will happen in most of the
//free web hosting providers.
function createDB($user,$password,$server,$DBname){
   $dbh=mysql_connect ($server, $user, $password)
           or die ('WebChess cannot connect to the database.
              Please check the database settings you provided.<br>');
   $query="create database ".$DBname;
   $result=mysql_query($query);
   mysql_query("quit");
   return $result;
}

//This function creates the tables within the database.
//ToDo: be able to write the install.log file.
//Until this is done, the $logMsg .= ... lines are commented.
function createTables($user,$password,$server,$DBname){
   $dbh=mysql_connect ($server, $user, $password)
           or die ('WebChess cannot connect to the database.
              Please check the database settings you provided.<br>');
   mysql_select_db ($DBname);

   //$logMsg .= "Probing for table games..\n";
   echo "Probing for table games..<br>";
   if(!tableExists("games")) {
   	//$logMsg .= "Creating table games..\n";
   	echo "Creating table games..<br>";
	$result=createTableGames();
        showMessage($result);
   }  else {
      showProbingMessage(true);
   }
   //$logMsg .= "Probing for table history..\n";
   echo "Probing for table history..<br>";
   if(!tableExists("history")) {
	//$logMsg .= "Creating table history..\n";
   	echo "Creating table history..<br>";
	$result=createTableHistory();
        showMessage($result);
   }  else showProbingMessage(true);
   //$logMsg .= "Probing for table messages..\n";
   echo "Probing for table messages..<br>";
   if(!tableExists("messages")) {
	//$logMsg .= "Creating table messages..\n";
   	echo "Creating table messages..<br>";
	$result=createTableMessages();
        showMessage($result);
   }  else showProbingMessage(true);
   //$logMsg .= "Probing for table pieces..\n";
   echo "Probing for table pieces..<br>";
   if(!tableExists("pieces")) {
	//$logMsg .= "Creating table pieces..\n";
   	echo "Creating table pieces..<br>";
	$result=createTablePieces();
        showMessage($result);
   } else showProbingMessage(true);
   // ToDo: consider checking for fields named "pCol" and "pRow" in "pieces" table (n8chessnet) or updating to pCol and pRow
   //$logMsg .= "Probing for table players..\n";
   echo "Probing for table players..<br>";
   if(!tableExists("players")) {
	//$logMsg .= "Creating table players..\n";
   	echo "Creating table players..<br>";
	$result=createTablePlayers();
        showMessage($result);
   } else {
	//$logMsg .= "Table players exists. Checking if table players has field lastAccess..\n";
        echo "Table players exists. Checking if table players has the lastAccess field..<br>";
	// Check if field "lastAccess" exists..
	if(!tablePlayersHasLastAccessField()) {
		// if false: update by calling addLastAccessFieldToPlayersTable()
		//$logMsg .= "Adding lastAccess field..\n";
                echo "Adding lastAccess field..<br>";
		addLastAccessFieldToPlayersTable();
	} else echo "Field lastAccess exists. Nothing done.<br>";
   }
   //$logMsg .= "Probing for table preferences..\n";
   echo "Probing for table preferences..<br>";
   if(!tableExists("preferences")) {
	//$logMsg .= "Creating table preferences..\n";
   	echo "Creating table preferences..<br>";
	$result=createTablePreferences();
        showMessage($result);
   } else showProbingMessage(true);
   //$logMsg .= "Probing for table communication..\n";
   echo "Probing for table communication..<br>";
   if(!tableExists("communication")) {
	//$logMsg .= "Creating table communication..\n";
   	echo "Creating table communication..<br>";
	$result=createTableCommunication();
        showMessage($result);
	//$logMsg .= "Inserting message to communication table..\n";
   	echo "Inserting message to communication table....<br>";
	$result=insertSampleFieldIntoCommunications();
        if ($result==1){
           echo "message inserted correctly.";
        } else echo "<b>ERROR</b>! The field message was not inserted correctly!";
   } else {
      showProbingMessage(true);
   }

   //ToDo: Make logfile work properly.
   //Without the proper permision, php won't be able to write any file.
   //In many free web hosting providers it won't be possible to allow proper
   //write permision, so it is not advisable to use this. It is needed a workaround.
   //Following code comented until this workaround is found.
   //echo ereg_replace("\n","<br />",$logMsg);
   //writeLogFile($logMsg);

   mysql_query("quit");
}

################################################################################
################################################################################
################################################################################
?>
   <html>
   <head>
      <title>Installing WebChess</title>
</head><body>
<h1>WebChess install</h1>
<?
/* 
 * All mention to $logMsg has been commented out. Now the installer makes things
 * differently. Now it will show the result in the screen, because some times 
 * php won't have write-permissions and it will be problematic for the novice 
 * administrator to handle it.
 * It is possible, however, to have both ways: Show the info in the screen and then
 * write it to a log file. rigao (who is writing this) does rather be programing
 * something else in his available time, but feel free to code it yourself.
 */
/*$logMsg = "";
if(file_exists("install.log")) {
	// Enter this condition if file exists..
	echo "ERRROR: File \"install.log\" already exists!<br />";
	echo "  This probably means that Webchess is already installed.<br />";
	echo "  For security reasons, please remove the file first if you wish<br />";
	echo "  to proceed with install<br />";
	$logMsg.= "ERRROR: File \"install.log\" already exists!\n";
	$logMsg.= "  This probably means that Webchess is already installed.\n";
	$logMsg.= "  For security reasons, please remove the file first if you wish\n";
	$logMsg.= "  to proceed with install";
	writeLogFile($logMsg);
	exit(0);
}*/

/*
 * This installer will flow through this switch. It will start in the default,
 * then it will go to case 1, 2, 3 and finish. Each case has its own form which
 * will keep the values which need to be send to the next form and will change the
 * $_POST['confirm'] variable to access the correct case.
 *
 * The cases roughtly follow the steps shown in the installer. However, normally
 * the operations of each step will be made in the next case (so, the operations
 * which belong to step 1 will be made at the beginning of case 2).
 */
switch($_POST['confirm']){
   //Step 1 of the installation procedure: Setup the database. The beginning of
   //case 2 has code of step 1 too.
   case 1:
      //Presentation of the installer.
      ?>
      <h2>Step 1: Provide a username with database-creation rights to create the
                 database which will store all WebChess data.</h2>

      <p>If you have direct access to the MySQL server: enter the server name,
          user credentials with database-creation rights and name of the
          database that WebChess will create in the corresponding fields.</p>

      <p>If you do not have direct acess to the MySQL server (such as when using
          a hosting service): create the database manually using hosting
          service-provided database creation tools. Then enter the server name
          and the name of the database that you created in the corresponding
          fields, leaving the username and password fields blank.  Make sure to
          click the 'I don't have access to the MySQL server...' checkbox.</p>

      <? // This form will be sent to case 2, to end step 1 and to start step 2. ?>
         <form action='install.php' method='POST' name='step1'><table>
            <tr><td>Server:</td><td><input type="text" name="server"/></td></tr>
            <tr><td>User:</td><td><input type="text" name="user"/></td></tr>
            <tr><td>Password:</td><td><input type="password" name="pass"/></td></tr>
            <tr><td>Database name:</td><td><input type="text" name="DBname"/></td></tr>
            <tr><td colspan="2"><input type="checkbox" name="skip" value="skip"/>I don't have access to the
               MySQL server so I've created the database myself with this name.</td></tr>
            <tr><td colspan="2"><input type='hidden' name='confirm' value='2' />
            <input type='submit' value='Continue' /></td></tr>
         </table></form>      
      <?
      break;

/******************************************************************************/

   //This case features last part of the step 1 and the presentation of the Step 2
   // of the installation procedure.
   case 2:
      //We make the installation procedure from step 1.
      //If the database is not created yet, we will create it.
      if ($_POST['skip']=='skip'){
         echo "We skiped the database creation. <br>";
      } else {
         echo "Trying to create the database...<br>";
         $result=createDB($_POST['user'],$_POST['pass'],$_POST['server'],$_POST['DBname']);
         if ($result==true) {
            echo "Database created successfully.<br>";
         } else {
            //This message will only show up if we are able to login the server
            //but the database is not created successfully.
            echo "Could not create the database. You must create it yourself.<br>";
         }
      }

      //We start step 2 with its presentation. It will be completed in case 3.
      ?>
      <h2>Step 2: Provide a username with table-creation rights to create the
                  tables within the database.</h2>

      <p>If the last step was successful, you should now have a database named
          '<? echo $_POST['DBname']; ?>' which WebChess will use to store its
          data. In order to do so, you must create the database tables.</p>

      <p>Enter a user with create-table rights. You may re-use the same one as
          in step 1 or input a different one.</p>

      <? //This form will be sent to case 3, to end step 2 and to start step 3. ?>
         <form action='install.php' method='POST' name='step2'><table>
            <tr><td colspan="2">
                  <input type="hidden" name="server" value="<? echo $_POST['server']; ?>"/></td></tr>
            <tr><td>User:</td><td><input type="text" name="user"/></td></tr>
            <tr><td>Password:</td><td><input type="password" name="pass"/></td></tr>
            <tr><td colspan="2">
                  <input type="hidden" name="DBname" value="<? echo $_POST['DBname']; ?>"/></td></tr>
            <tr><td colspan="2">
		<?php if ($_POST['user'] != '') { ?>
                  <input type="checkbox" name="reuse" value="true"/>Use the same
          user as in step 1.
		<?php } ?>
                  <input type="hidden" name="user_last" value="<? echo $_POST['user']; ?>"/>
                  <input type="hidden" name="pass_last" value="<? echo $_POST['pass']; ?>"/>
               </td></tr>
            <tr><td colspan="2"><input type='hidden' name='confirm' value='3' />
            <input type='submit' value='Continue' /></td></tr>
         </table></form>
      <?
      break;

/******************************************************************************/

   //This case features last part of the step 2 and the presentation of the Step 3
   // of the installation procedure.
   case 3:
      //We make the installation procedure from step 2.
      //Little code to handle if there is a new user to create the tables.
      if ($_POST['reuse']=='true')
      {
         $user=$_POST['user_last'];
         $pass=$_POST['pass_last'];
      } else {
         $user=$_POST['user'];
         $pass=$_POST['pass'];
      }
      $server=$_POST['server'];
      $DBname=$_POST['DBname'];
      //Once we know the user which will create the tables, we call the function
      //which will create them.
      createTables($user,$pass,$server,$DBname);

      // We start step 3 with this presentation. This step 3 is breaked into two
      // substeps. The first one will generate config.php, while the second one
      // will setup the user which will use WebChess to access MySQL.

      // Step 3.1:
      ?>
         <h2>Step 3: Configure your WebChess installation.</h2>

         <p>Next, we will configure the WebChess server and set up the MySQL
             user that WebChess will use to  access the database.  For security
             reasons, it is recommended to chose a user which has neither
             database nor table creation rights.</p>

         <p>Fill the username and password fields to create a new user with
             limited rights.  If you choose you may use the same credentials as
             in the previous steps, but it is highly discouraged to do so and
             then <b>only at your own risk</b>.</p>

         <p>Click the 'Generate config.php' button.  This will download a
             config.php file containing your configuration information. To make
             sure your hosting service did not add any javascript to the end of
             the file (which would break WebChess), verify that the last line
             contains the code: '? >'.</p>

         <?
            //This form will generate the config.php file and put it to download.
            //It is possible that the hosting provider will add some javascript code
            //at the end of the file for tracking reasons. Then it must be deleted
            //by the user before he uploads it. This needs to be very clear in the
            //installer and in the installer FAQ.
         ?>
         <form action='makeConfig.php' method='POST' name='generateConfigForm' target="_blank"><table>
            <tr><td colspan="2"><b><u>Database Settings:</u></b>
                  <input type="hidden" name="server" value="<? echo $_POST['server']; ?>"/></td></tr>
            <tr><td>User:</td><td><input type="text" name="user"/></td></tr>
            <tr><td>Password:</td><td><input type="password" name="pass"/></td></tr>
            <tr><td colspan="2">
                  <input type="hidden" name="DBname" value="<? echo $_POST['DBname']; ?>"/></td></tr>
            <tr><td colspan="2">
                  <input type="checkbox" name="reuse" value="true"/>Use the same
                      user as in step 2.
                  <input type="hidden" name="user_last" value="<? echo $user; ?>"/>
                  <input type="hidden" name="pass_last" value="<? echo $pass; ?>"/>
               </td></tr>
            <tr><td colspan="2"><b><u>Server Settings:</u></b></td></tr>
            <tr><td>Time before session expires (seconds):</td><td><input type="text" name="timeout"/> (ex: 900)</td></tr>
            <tr><td>Time before a game expires (days):</td><td><input type="text" name="expire"/> (ex: 14)</td></tr>
            <tr><td>Minimum time interval for auto-reload (seconds):</td><td><input type="text" name="autoreload"/> (ex: 5)</td></tr>
            <tr><td>Use e-mail notification:</td><td><input type="checkbox" name="mail_not" value="1"/></td></tr>
            <tr><td>E-mail adress:</td><td><input type="text" name="mail_adr"/> (ex: WebChess@example.com)</td></tr>
            <tr><td>Main Page adress:</td><td><input type="text" name="url"/> (ex: http://webchess.sourceforge.net)</td></tr>
            <tr><td>Maximum active users:</td><td><input type="text" name="maxUsers"/> (ex: 50)</td></tr>
            <tr><td>Maximum active games:</td><td><input type="text" name="maxGames"/> (ex: 50)</td></tr>
            <tr><td>Nick changes allowed:</td><td><input type="checkbox" name="changeNick" value="1"/></td></tr>
            <tr><td>New users allowed:</td><td><input type="checkbox" name="newUsers" value="1"/></td></tr>
            <tr><td>Square size of the board (pixels):</td><td><input type="text" name="size"/>(ex: 50)</td></tr>
            <tr><td>Image extension:</td><td><select name="imageExtension" size="1">
               <option value="gif">gif<br>
               <option value="png">png<br>
                  </select>
               </td></tr>
            <tr><td colspan="2"><input type='hidden' name='confirm' value='finish' />
            <input type='submit' value='Generate config.php' /></td></tr>
         </table></form>

         <? //This form is just to end the installation procedure. ?>
         <p>After the config.php is downloaded, upload it to your server and
                   click the 'Finish' button to end the installation.</p>

         <form action='install.php' method='POST' name='finish'>
            <input type='hidden' name='confirm' value='finish' />
            <input type='submit' value='Finish' />
         </form>
      <?
      
      break;

/******************************************************************************/

   case finish:
      ?>
         <h2>The installation process has finished.</h2>

         <p>For secury reasons it is recommended that you now delete install.php
             and makeConfig.php from your web server. While we tried to make
             sure there is no way to exploit it, it is possible that we may have
             missed something, therefore it is better to delete it once the
             installation is done.</p>

         <p>Remember that WebChess is free software released under the GPLv3
             license, therefore you <b>must</b> provide a link to the source
             code (even if you didn't change anything) if you upload the
             application to a public server.</p>

         <p>Once any problems spotted during the installation process are
             solved, go to the <a href='index.php'>login page</a> and create
             your first user!</p>

         <p><i>Thank you for playing WebChess!</i></p>

      <?
      break;

/******************************************************************************/

   //Welcome page.
   default:
      //The begining of the installation process.
      ?>
      <p>WebChess is a web application based on PHP and MySQL and released under
             the GPLv3 license. Since it stores all of its information in a
             MySQL database, you must ensure that your hosting service is MySQL-
             capable in order for WebChess to function properly (nowadays, most
             are). If you are installing on your own server, make sure to have a
             fully functional MySQL server installed.

      <p>In order to install WebChess we will follow a 3-step procedure:</p>

      <ul><li>Step 1: Provide a username with database-creation rights to create
                 the database which will store all WebChess data.</li>
             <li>Step 2: Provide a username with table-creation rights to create
                 the tables within the database.</li>
             <li>Step 3: Configure your WebChess installation</li></ul>

      <p>Make sure you have backed up your databases to make sure your data is
             not lost.</p>

      <form action="install.php" method='POST'>
      <input type="checkbox" name="confirm" value="1" /> I'm ready to proceed!
      <br />
      <input type="submit" value="Install Databases" />
      </form>
      <?
      break;
}
?>
</body>
</html>
 	  	 
