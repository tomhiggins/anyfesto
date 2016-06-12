Test if festivle/flite is doable on the pi. If so hook into  the framework

VoIP using Mumble
------------------
sudo apt-get install mumble-server
sudo dpkg-reconfigure mumble-server
   Autostart:  Yes
   High Priority: No
   SuperUser: Set the admin password
sudo nano /etc/mumble-server.ini
    Find welcomeText and update to whatever you would like displayed when a user joins
    Find serverpassword and update if you would like a password for users, leave as is to  have no password for users.
sudo /etc/init.d/mumble-server restart  

# Add a link on the captive portal landing page  to poin to the server address and the clients. 

Clients for Linux/Win/Mac - https://wiki.mumble.info/wiki/Main_Page
Android - https://f-droid.org/repository/browse/?fdid=com.morlunk.mumbleclient
iOs - https://itunes.apple.com/dk/app/mumblefy/id858752232?mt=8
