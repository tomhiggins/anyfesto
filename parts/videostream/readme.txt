Anyfesto - Video Streaming

- Set up VLC (done)
 # sudo apt-get -y install vlc
 # sudo adduser --no-create-home --shell /bin/false --disabled-password vlc
 # sudo usermod -G audio,pi vlc
 # sudo usermod -d /media/usb vlc
 # sudo nano /usr/share/vlc/lua/http/.hosts
    ::1
    127.0.0.1
    fc00::/7
    fec0::/10
    10.0.0.0/8
    192.0.0.0/8
  # sudo mkdir /etc/vlc 
  # sudo cd /usr/share/vlc/lua/http/ 
  # sudo mv .hosts /etc/vlc 
  # sudo ln -s /etc/vlc/.hosts .hosts
  
- On Startup run as stream server, open a web based interface for admining, and also play to the 3.5mm audio jack (done)
  # sudo nano /etc/vlc/start.sh
    #!/bin/sh
    sudo service hostapd start
    sudo mount -o uid=pi,gid=pi /dev/sda1 /media/usb
    VLC_PORT=8088
    VLC_USER=vlc
    VLC_IP=192.168.77.1
    VLC_PASWD=goodhello
    sudo -u vlc cvlc -I http --http-password $VLC_PASWD  --http-host $VLC_IP --http-port $VLC_PORT  --sout='#duplicate{dst=standard{access=http,mux=ts,dst=:8085},dst=display}'  --loop  /home/pi/Radio/welcome.mp3
 # sudo chmod a+rx /etc/vlc/start.sh  
 # sudo nano /etc/rc.local
      /etc/vlc/start.sh &

- Avahi and landing page for discovery. (done)
