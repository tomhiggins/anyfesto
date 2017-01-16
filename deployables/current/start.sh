#!/bin/sh  
ifup wlan1
VLC_PORT=8088
VLC_USER=vlc
VLC_IP=10.11.99.1
VLC_PASWD=changeme
sudo -u vlc cvlc -vvv -I http --http-password $VLC_PASWD  --http-host $VLC_IP -$
