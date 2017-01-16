#!/bin/bash

# Anyfesto Install Script for the CHIP
# CC 2017 by tomwsmf

# Install the Basic Packages and Infrastructure

echo "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"
echo "Starting the AnyfestoCHIP Install...."
echo "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"
echo "Installing the Basic Packages and Infrastructure."
echo "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"
sudo apt-get -y update
sudo apt-get -y upgrade
sudo apt-get -y install locales
sudo locale-gen en_US en_US.UTF-8
sudo apt-get -y install vlc
sudo adduser --no-create-home --shell /bin/false --disabled-password vlc
sudo usermod -G audio,chip vlc
sudo apt-get -y install lighttpd
sudo apt-get -y install dnsmasq
sudo apt-get -y install isc-dhcp-server
sudo apt-get -y install hostapd
sudo apt-get -y install git zip unzip
sudo apt-get -y install perl sox libsox-fmt-all libav-tools
sudo rm /bin/sh
sudo ln /bin/bash /bin/sh
sudo chmod a+rw /bin/sh

# Setup the Directories and lighttpd 
echo "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"
echo "Setting Up the Directories and Lighttp Web Server"
echo "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"
mkdir /home/chip/content
mkdir /home/chip/content/Radio
sudo usermod -d /home/chip/content/Radio vlc
sudo ln -s /home/chip/content /var/www/html/content   
cd /var/www/html
sudo rm index*.html
sudo wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/AnyfestoCHiP-index.html -O index.html
sudo wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/anyfestochiplogosm.jpg -O logo.jpg
cd ~
wget https://github.com/twbs/bootstrap/releases/download/v3.3.7/bootstrap-3.3.7-dist.zip
unzip bootstrap-3.3.7-dist.zip 
sudo cp -r bootstrap-3.3.7-dist/* /var/www/html/
cd /var/www/html/css
sudo wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/carousel.css
cd /var/www/html/js
sudo wget https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js
cd ~
sudo echo 'server.dir-listing = "enable"'  >> /etc/lighttpd/lighttpd.conf

#
Setup Network and Captive Portal 
echo "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"
echo "Setting Up The Network, Access Point and Captive Portal"
echo "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"

cd ~
wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/current/dhcpd.conf 
wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/current/dnsmasq.conf
wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/current/hostapd
wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/current/hostapd.conf
wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/current/interfaces
wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/current/isc-dhcp-server
wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/current/start.sh

sudo mv -f dhcp.conf /etc/dhcp/dhcpd.conf
sudo mv -f dnsmasq.con /etc/dnsmasq.conf
sudo mv -f hostapd /etc/default/hostapd
sudo mv -f hostapd.conf /etc/hostapd/hostapd.conf 
sudo mv -f interfaces /etc/network/interfaces 
sudo mv -f isc-dhcp-server /etc/default/isc-dhcp-server

#Setup Audio Streaming using VLC
echo "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"
echo "Setting Up the Audio Streaming Service"
echo "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"

sudo echo "::1" > /usr/share/vlc/lua/http/.hosts
sudo echo "127.0.0.1" >> /usr/share/vlc/lua/http/.hosts
sudo echo "fc00::/7" >> /usr/share/vlc/lua/http/.hosts
sudo echo "fec0::/10" >> /usr/share/vlc/lua/http/.hosts
sudo echo "10.0.0.0/8" >> /usr/share/vlc/lua/http/.hosts
sudo echo "192.0.0.0/8" >> /usr/share/vlc/lua/http/.hosts

sudo mkdir /etc/vlc 
cd /usr/share/vlc/lua/http/ 
sudo mv .hosts /etc/vlc 
sudo ln -s /etc/vlc/.hosts .hosts
cd /home/chip/content/Radio
wget https://archive.org/download/Old_Radio_Public_Service_Announcements/OldRadio_Pub--Jack_Benny_Tolerance1.mp3  -O welcome.mp3
sudo mv -f ~/start.sh /etc/vlc/start.sh  
sudo chmod a+rx /etc/vlc/start.sh  

    
sudo sed 's:exit 0:/etc/vlc/start.sh \&\nexit 0:' -i /etc/rc.local

echo "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"
echo "Installation Complete...Preparing To Reboot"
echo "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"
sudo echo "AnyfestoCHIP" >/etc/hostname 
sudo sync 
sudo reboot
#
