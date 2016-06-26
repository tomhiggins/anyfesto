#!/bin/bash

# Anyfesto Install Script for the CHIP
# CC 2016 by tomwsmf

# Upgrae your base install
sudo apt-get -y update
sudo apt-get -y upgrade
sudo apt-get -y install locales
sudo locale-gen en_US en_US.UTF-8

# Start installing the services
sudo apt-get -y install vlc
sudo adduser --no-create-home --shell /bin/false --disabled-password vlc
sudo usermod -G audio,chip vlc
sudo apt-get -y install lighttpd
sudo /etc/init.d/lighttpd stop
sudo update-rc.d lighttpd remove
sudo apt-get -y install dnsmasq 
sudo /etc/init.d/dnsmasq  stop
sudo update-rc.d dnsmasq remove 
sudo apt-get -y  install hostapd
sudo /etc/init.d/hostapd  stop
sudo update-rc.d hostapd remove 
sudo apt-get -y install git
sudo apt-get -y install perl sox libsox-fmt-all libav-tools
sudo rm /bin/sh
sudo ln /bin/bash /bin/sh
sudo chmod a+rw /bin/sh
mkdir /home/chip/content
mkdir /home/chip/content/Radio
sudo usermod -d /home/chip/content/Radio vlc

# Install and Config Piratebox Base
cd ~
wget  http://downloads.piratebox.de/piratebox-ws_current.tar.gz
tar xzf piratebox-ws_current.tar.gz
cd piratebox
sudo mkdir -p  /opt
sudo cp -rv  piratebox /opt
cd /opt/piratebox
sudo sed 's:DROOPY_USE_USER="no":DROOPY_USE_USER="yes":' -i  /opt/piratebox/conf/piratebox.conf
sudo ln -s /opt/piratebox/init.d/piratebox /etc/init.d/piratebox
sudo update-rc.d piratebox  defaults 
sudo ln -s /home/chip/content /opt/piratebox/share

# Change the defaults in /opt/piratebox/conf/piratebox.conf   
sudo sed 's:HOST="piratebox.lan":HOST="anyfestochip.lan":' -i /opt/piratebox/conf/piratebox.conf
sudo sed 's:INTERFACE="wlan0":INTERFACE="wlan1":' -i /opt/piratebox/conf/piratebox.conf
sudo sed 's:DNSMASQ_INTERFACE="wlan0":DNSMASQ_INTERFACE="wlan1":' -i /opt/piratebox/conf/piratebox.conf
sudo sed 's:NET=192.168.77:NET=10.11.99:' -i /opt/piratebox/conf/piratebox.conf
      
# Setup hostapd configs in /opt/piratebox/conf/hostapd.conf       
sudo echo "interface=wlan1" >/opt/piratebox/conf/hostapd.conf
sudo echo "driver=nl80211" >>/opt/piratebox/conf/hostapd.conf
sudo echo "ssid=AnyfestoCHIPCommunityNetworking" >>/opt/piratebox/conf/hostapd.conf
sudo echo "channel=1" >>/opt/piratebox/conf/hostapd.conf
sudo echo "ctrl_interface=/var/run/hostapd" >>/opt/piratebox/conf/hostapd.conf
      
# Setup hostapd configs in /etc/default/hostapd                  
sudo echo 'DAEMON_CONF="/opt/piratebox/conf/hostapd.conf"' >/opt/default/hostapd

# Setup allowed hosts for vlc servers in  /usr/share/vlc/lua/http/.hosts
sudo echo "::1" > /usr/share/vlc/lua/http/.hosts
sudo echo "127.0.0.1" >> /usr/share/vlc/lua/http/.hosts
sudo echo "fc00::/7" >> /usr/share/vlc/lua/http/.hosts
sudo echo "fec0::/10" >> /usr/share/vlc/lua/http/.hosts
sudo echo "10.0.0.0/8" >> /usr/share/vlc/lua/http/.hosts
sudo echo "192.0.0.0/8" >> /usr/share/vlc/lua/http/.hosts

# Setuo vlc server and put in a default file for streaming
sudo mkdir /etc/vlc 
cd /usr/share/vlc/lua/http/ 
sudo mv .hosts /etc/vlc 
sudo ln -s /etc/vlc/.hosts .hosts
cd /home/chip/content/Radio
wget https://archive.org/download/Old_Radio_Public_Service_Announcements/OldRadio_Pub--Jack_Benny_Tolerance1.mp3  -O welcome.mp3

# Create /etc/vlc/start.sh
sudo echo "#!/bin/sh  " > /etc/vlc/start.sh                        #Add the follwing and save   
sudo echo "sudo service hostapd start" >> /etc/vlc/start.sh
sudo echo "VLC_PORT=8088" >> /etc/vlc/start.sh
sudo echo "VLC_USER=vlc" >> /etc/vlc/start.sh
sudo echo "VLC_IP=10.11.99.1" >> /etc/vlc/start.sh
sudo echo "VLC_PASWD=changeme" >> /etc/vlc/start.sh    
sudo echo "sudo -u vlc cvlc -vvv -I http --http-password $VLC_PASWD  --http-host $VLC_IP --http-port $VLC_PORT  --sout-keep --sout='#duplicate{dst=rtp{mux=ts,dst=10.11.99.1:8086},dst=gather:std{access=http,mux=mpeg1,dst=:8085},dst=display,select="novideo"}'  -LZ /home/chip/content/*/./*.mp3" >> /etc/vlc/start.sh        
    
sudo chmod a+rx /etc/vlc/start.sh  
sudo sed 's:exit 0:/etc/vlc/start.sh \&\nexit 0:' -i /etc/rc.local



# Get default web pages and clean up the piratebox install
sudo rm /opt/piratebox/www/index.html
sudo wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/AnyfestoCHiP-index.html -O /opt/piratebox/www/index.html
sudo wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/anyfestochiplogosm.jpg -O /opt/piratebox/www/logo.jpg
sudo rm /opt/piratebox/www/favicon.ico
sudo rm /opt/piratebox/www/Shared/HEADER.txt
sudo rm /opt/piratebox/www/Shared/README.txt

sudo /etc/init.d/piratebox start

sudo sync 
sudo reboot

