#!/bin/sh  
VLC_PORT=8088
VLC_USER=vlc
VLC_IP="$(ip addr | grep 'state UP' -A2 | tail -n1 | awk '{print $2}' | cut -f1 -d'/')"
VLC_PASWD=changeme
find /home/pi/content/Radio -name '*.mp3'>/home/pi/content/playlist.m3u
chmod a+rwx /home/pi/content/playlist.m3u
cvlc -I http --http-password $VLC_PASWD --http-host $VLC_IP --http-port $VLC_PORT --sout-keep --sout='#duplicate{dst=rtp{mux=ts,dst=127.0.0.1:8086},dst=gather:std{access=http,mux=mpeg1,dst=:8085},dst=display,select="novideo"}' -LZ /home/pi/content/playlist.m3u &
