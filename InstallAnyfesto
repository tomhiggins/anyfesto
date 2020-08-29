Anyfesto Install on a RaspberryPi

===========================================================================================
The Quick Method
===========================================================================================
-Get a Pi set up with a fresh install of Raspberry PI OS Lite
-SSH in
-Cut and paste the following line into the Command Line and hit enter...

wget --no-check-certificate  https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/current/pi/PIInstall.sh
bash PIInstall.sh

-Jump down to the After The Reboot section

===========================================================================================
The Detailed Method
=======================================================================================
Here is a current list of RaspberryPis you might use...

   Raspberry Pi 4 Model B 4gb - https://www.adafruit.com/product/4296 - $55.00
   Raspberry Pi 3 Model B - https://www.adafruit.com/products/3055 - $39.95
   Raspberry Pi 0 W - https://www.adafruit.com/products/3400 - $10.00
   Or
   Raspberry Pi OG or 2 a or b  - https://www.adafruit.com/category/105 
   Raspberry Pi Zero v1.3 - https://www.adafruit.com/products/2885 - $ 5.00
   Tiny USB OTG Adapter - https://www.adafruit.com/products/2910 - $ 2.95
   Smallest WIFI USB - https://www.adafruit.com/products/814 - $11.95

Here are some items you will need....
   16GB or Bigger Micro SD card - Many Sources - $ 5.00 - upward
      (the bigger the GB the more content you can store on the SD)
   5V 2.4A Power  and 6' MicroUSB Cable - https://www.adafruit.com/products/1995 - $ 7.95 
    (note that the new PIs use USB C)
 
Here are some items you might need....
LIon Battery 3.7V 2500mAh - https://www.adafruit.com/products/328 - $29.50
   PowerBoost 1000 Charger 5V -https://www.adafruit.com/products/2465 - $19.95
   USB Storage (optional)   - Many Sources - $ 5.00 - upward


Hardware Setup
---------------------------------------------------------------------------------------------------------------
   Wifi -
       PI0W/PI3/PI4 - Wifi is built in, you are ready to proceed
       PI0 -          Connect the OTG USB adapter to the OTG UB port on the PIZero
                      Connect the USB Wifi dongle to the OTG USB adapter
       PI1/2/A/B-     Connect the USB Wifi dongle to the USB adapter


Software Setup
---------------------------------------------------------------------------------------------------------------
   Operating System - 
    From another computer...
    Download Raspberry PI OS Lite https://www.raspberrypi.org/downloads/raspberry-pi-os/
    Install Raspberry On SD Card https://www.raspberrypi.org/documentation/installation/installing-images/README.md
    Insert the SD Card into the SD slot on the PI

There are several options to get into your PI

    1. Boot with a Monitor, Keyboard and Ethernet connection to your lan 
    2. Boots up with SSH enabled so that you can shell in via an ethernet and then set up your wifi net 
     connection.
    3. If you can/do not have an ethernet dongle or keyboard/monitor the go with the Headless Install. 
    You can find a detailed step by step walk though at https://raspberrytips.com/raspberry-pi-wifi-setup/
 

Power up the PI
     (If you set this up to run headless check your network for a device called "raspberrypi" and ssh to it's IP)
     (Or run this from a linux cli on your network    sudo nmap -sS -p 22 10.11.25.0/24  and look for RaspberryPi
       Replace 10.11.25.0/24 with the local address space on your network.)

-Login (default user/password is pi/raspberry)

-If the GUI pops up close out to the Command Line (also called the CLI)

-From the Command Line type
sudo raspi-config
  In this order do the following....
       Update
       Change Password
       Localization Options
          Set Localization
          Set TimeZone 
          Set Keyboard Options
       Boot Options
           Desktop/CLI
             Set to Command Line
       Network Options
          Set Hostname to AnyfestoPI
       Interface Options
           SSH Enable
       Advanced Options
          Expand Filesystem
       Finish & Reboot
       
 -Log back into the PI but now with your new password      

===========================================================================================
Scripted Installation
===========================================================================================
-Cut and paste the following line into the Command Line and hit enter...

wget --no-check-certificate  https://raw.githubusercontent.com/tomhiggins/anyfesto/master/deployables/current/pi/PIInstall.sh
bash PIInstall.sh

===========================================================================================
After The Reboot
===========================================================================================

-Once it has rebooted you should now have a base Anyfesto Install. Congrats.  When you reboot it you should be able to see it from 
another Wifi connected device broadcasting a SSID with Anyfesto in it. Go ahead and connect, open up a web browser and 
attempt to go to a real or made up website. You will be redirected to the main webpage which will tell you about some
of the things you can do. 

-Add any  audio you want played and shared into /home/pi/content/Radio  Reboot and the new audio will be added to the
playlist

-Add any content you want to share into /home/pi/content

-To add USB drives, more packages, do administration or fix what needs fixing
head down to the Going Further section below 


----------------------------------------------------------------------------
Going Further
----------------------------------------------------------------------------
-To add more packages, do administration or fix what needs fixing reconnect to the PI by one of the methods listed 
 at the beginning of these instructions making sure to undo any changes made to the network config files. 

sudo sync
sudo reboot

----------------------------------------------------------------------------
Adding a USB Drive (vfat formatted, which is the default for most USB storage)
----------------------------------------------------------------------------
By adding a USB storage drive you can 

1) free up the onboard memory of your PI
2) quickly add/delete content from your Anyfesto install by moving the USB drive 
   to another computer

-Connect the USB drive to the USB port

sudo mkdir /media/drives
sudo mount /dev/sda1 /media/drives
sudo sh -c 'echo "/dev/sda1 /media/drives vfat uid=nobody,gid=nogroup,umask=0,noatime,rw,user 0 0" >> /etc/fstab'
sudo mount -a 
sudo mv /home/pi/content /media/drives
sudo rm -r /home/pi/content/
sudo ln -s /media/drives/content /home/pi


------------------------------------------------------------------------------
Optional - Install Additional Kiwix Zims
------------------------------------------------------------------------------

--You can find a full list of wikimedia files already in the ZIM format Kiwix  
uses at https://download.kiwix.org/zim/ . 
--Copy the url of the zim(s) you want on you Anyfesto install
       cd /home/pi/content/kiwix
--one at a time download the zim(s) you want
       sudo wget (url of zim you want to add)
--add it to the library.xml Kiwix uses as a catalog 
       kiwix-manage /home/pi/content/kiwix/library.xml add /home/pi/content/kiwix/(name of the zim file you downloaded)
       chmod a+rx *



------------------------------------------------------------------------------------------
Optional - Battery Powered
(from the PiFold project on Hackaday https://hackaday.io/project/9498-pifold)
------------------------------------------------------------------------------------------
    Connect the JST from the Battery to the JST connector on the Powerboost 1000
    If you want to hard wire this to the PiZero
        On the Powerboost solder a red wire to the (+) pad of the USB section and a black wire to the (-) pad
        tbf
    Else
        Get a USB cable that has a microUSB connector at one end
        Snip the other end and strip back the wires
        On the Powerboost solder the red wire to the (+) pad of the USB section and the black wire to the (-) pad
    (Optional) add an on/off switch to EN and GND pads on the Powerboost


------------------------------------------------------------------------------------------
Optional - Hostapd - some wifi dongles require a different version of hostapd
------------------------------------------------------------------------------------------

wget http://adafruit-download.s3.amazonaws.com/adafruit_hostapd_14128.zip
zip adafruit_hostapd_14128.zip
sudo mv /usr/sbin/hostapd /usr/sbin/hostapd.old
sudo mv hostapd /usr/sbin
sudo chmod 755 /usr/sbin/hostapd
sudo /etc/init.d/hostapd  stop







