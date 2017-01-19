#!/bin/bash
sudo apt-get -y install ircd-hybrid
cd ~
cd configs
wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/current/ircd.conf
wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/current/ircd.motd 
sudo chown root:root *
sudo chmod a+rx *
sudo mv -f ircd.conf /etc/ircd-hybrid/ircd.conf 
sudo mv -f ircd.motd /etc/ircd-hybrid/ircd.motd    

sudo apt-get -y install npm
cd ~
git clone https://github.com/prawnsalad/KiwiIRC.git
cd KiwiIRC
npm install
wget https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/current/kiwiconfig.js
cp kiwiconfig.js config.js  
sudo chmod a+rx config.js
./kiwi build
./kiwi start
