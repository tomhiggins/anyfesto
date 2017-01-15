#!/bin/bash

# Anyfesto Install Script for the CHIP
# CC 2017 by tomwsmf

# Install the Basic Packages and Infrastructure
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
sudo apt-get -y install git
sudo apt-get -y install perl sox libsox-fmt-all libav-tools
sudo rm /bin/sh
sudo ln /bin/bash /bin/sh
sudo chmod a+rw /bin/sh

# Setup the Directories and lighttpd 
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
#Setup Network and Captive Portal 
#

sudo echo 'INTERFACES="wlan1"' >/etc/default/isc-dhcp-server

sudo echo "ddns-update-style none;" >/etc/dhcp/dhcpd.conf
sudo echo "log-facility local7;" >>/etc/dhcp/dhcpd.conf
sudo echo "authoritative;" >>/etc/dhcp/dhcpd.conf
sudo echo "subnet 10.11.99.0 netmask 255.255.255.0 {" >>/etc/dhcp/dhcpd.conf
sudo echo "range 10.11.99.20 10.11.99.200;" >>/etc/dhcp/dhcpd.conf
sudo echo "option broadcast-address 10.11.99.255;" >>/etc/dhcp/dhcpd.conf
sudo echo "option routers 10.11.99.1;" >>/etc/dhcp/dhcpd.conf
sudo echo "default-lease-time 600;" >>/etc/dhcp/dhcpd.conf
sudo echo "max-lease-time 7200;" >>/etc/dhcp/dhcpd.conf
sudo echo "option domain-name "local";" >>/etc/dhcp/dhcpd.conf
sudo echo "option domain-name-servers 10.11.99.1, 10.11.99.1;" >>/etc/dhcp/dhcpd.conf
sudo echo "}" >>/etc/dhcp/dhcpd.conf
sudo echo " " >>/etc/dhcp/dhcpd.conf

sudo echo "address=/#/10.11.99.1" >/etc/dnsmasq.conf
sudo echo "interface=wlan1" >>/etc/dnsmasq.conf
sudo echo "source-directory /etc/network/interfaces.d" > /etc/network/interfaces 
sudo echo "auto wlan1" >> /etc/network/interfaces 
sudo echo "iface wlan1 inet static" >> /etc/network/interfaces 
sudo echo "address 10.11.99.1" >> /etc/network/interfaces 
sudo echo "netmask 255.255.255.0" >> /etc/network/interfaces 
sudo echo "gateway 10.11.99.1" >> /etc/network/interfaces 

sudo echo "interface=wlan1" >/etc/hostapd/hostapd.conf 
sudo echo "driver=nl80211" >>/etc/hostapd/hostapd.conf 
sudo echo "ssid=AnyfestoCHIPCommunityNetworking" >>/etc/hostapd/hostapd.conf 
sudo echo "channel=1" >>/etc/hostapd/hostapd.conf 
sudo echo "ctrl_interface=/var/run/hostapd" >>/etc/hostapd/hostapd.conf 

sudo echo 'DAEMON_CONF="/etc/hostapd/hostapd.conf"' >/etc/default/hostapd

sudo echo "AnyfestoCHIP" >/etc/hostname 

#Setup Audio Streaming using VLC
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

sudo sync 
sudo reboot
#
