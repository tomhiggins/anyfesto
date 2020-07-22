July 21st 2020
The CHIP is really really, sadly, not looking well. Production has been dead for years. Upside,... the number of SBOCs is massive and only spreading 
up and out. Most will solidly work with a Debain build out, so that is one I am shooting to document this year 

The Chromebook install works well enough in testing, I use it every now and again. If there is time I want to lock down the build as part of the Debian branch. 

AnyfesTor has become the build out to make a version you can run on an already existing Network. I am looking at making the discovery methods easier on the nonTor side, ie the existing net, and then having the Tor hooks in place if you flip a switch. 

AS to the Tor side...I have a running AnyfesTor up and going for the last couple of months. Not all the services are available but it is moving along.
Some folks will want to get the hidden urls out and some will want them narrow banded, both are viable. 

I have been updating the part...Kiwix, Kolbiri, etc etc all have had massive upgrades and some hammering is going on to catch up 

And so it goes. My oldest install has been running now for 2 years solid. The Tor one has only been up for a few months. 

Please let me know your thoughts and ideas to make this better for you and me and all. Be well, share, love, grow. 



July 19th 2019
Things that need doing to get this refreshed and ready for the next phase
  - update to raspian buster
  - bug squash
My focus for the next round comes form things people have asked me to include
   - make an Anyfesto install be able to attach to an existing network. There will not be two versions but raher two modes that
     the install can be in. Mode Classic, the island in the sun stand alone captive portal Anyfest box. Mode the second, connected to an already
     existing network with lots of broadcast to make it discoverable..or not... such that Anyfesto spreads to where you need it rather than forcing
     folks to come to it.  Dealers choices, change at will with a quick script run. 
     - make the configs easier to set up and maintain


August 18th 2018
Promising news on getting one of the original features back in the default build. Having an FM station in my pocket was one of the 
things that was a key part of the first ideas for the Anyfesto Box. On the original PIs pifm worked a charm, yes it was noisy
but getting the signal out in some cases is a dirty business. Filters an the like could be added of course. With the newer PIs 
came problems with bit banging and timing issues on the new chips... so sadly I put the FM code in the Optional section. 
Some new code I have seen claims to get around these issues. I am going to try and get some time to see if I can get it working on
the PI3 and the PI0W. If it works out then  pop up stations ahoy. 
Here is the link to the code https://github.com/somu1795/fm_transmitter and here to a video that uses it and adds a nice
filter to the build. https://www.youtube.com/watch?v=gcPjkBDdURI

April 11th 2018
After finally getting settled into my new digs in early March..my apt burnt to the ground. Thankfully the code was kept warm 
and safe here and in other places. The test hardware and Anyfesto Boxes that were being worked on, 4 Pi 0w's, 3 CHIPs, 2 Pi 3's,
were lost to the flames. Also my desktop and the tangle of cables, power units, batteries and sd cards....clothes and food..you 
get the gist. I got out with the clothes on my back and my go-bag. 
Thanks to the kindness of friends and droogies I have regained some of what was lost. Because of them I can say that less than a 
month after the flames I have enough pieces to start rebuilding some testing units.

Right before the fire I had set up the first node of a local Anyfesto network here in my new town. No meshing or the like just yet but that is one of the things I would love to tackle this year. These will be to shake down what is already in place, work on things like making the setup keep less logs/data that could be used to track a user, and in general get the core of things rock solid.

If you are running a build please post up your testing reports. What works, what failed on setup, what is being logged that should not, how you moded it for your own needs. 

Until next report, keep on sharing.   


January 19th 2018
Another year and here we are. More life in the way of deving, a move across the states took me away from dev work but I did
have a chance to try some new things out on the road. My Pi0W Anyfesto has been a trusty companion; I have not been without
good listening or reading material :)-

Some thoughts....
Anyfestoeer yeyeto2788  did up a translation of the landing page into Spanish. Amazingly great work. It got me thinking that
Anyfesto needs an easy way for folks to customize the steups they make. Everyone is going to have a  unique purpose so it  
stands to reason they will need unique presentations.  We could easily make a bash script for this..but I want to make it 
easier for folks who are not of the First Church Of Bash (all praises) .  I am open to ideas.

Things I think should be configurable….
-Hostname
-IP range
-SSID
-Title for use on premade landing pages
-Ability to edit the landing page
-Curated playlists for the VLC streaming service as well as the autogenerated one. 

Another thought, adding more streaming types to cover more streaming apps. I would love if the streams played right in a web 
browser but also in the more popular apps.  
Ok that is it for now. I will have more actual work once I get an Internet setup in my new apt.


November 4th 2017
I have been running a AnyfestoPI on a PIW0 for a few months now nearly everyday. Stable as a rock, everything works from the 
install setup instructions on first boot. Yes even the audio player on the web page works. I have made several installs on PI0Ws 
for various purposes and they are all working from the setup up instructions. One is kept in a school kids backpack and the reports
are all good. 

Thanks to commenters there are a couple of issues that I am trying to find time to squash. Some browser requests are  not 
redirecting to the landing web page. I am looking to see if LibraryBox/PirateBox installs are having this issue. I think it
might be something on the client's side and dns caching, but so far no proof yea or nea. More as that happens. 

I have also started playing around with the idea of using Chromebooks as an install base for Anhyfesto. I was able to get
my Chromebooks bios to allow booting into USB/SD devices so it should be possible to build on top of a base Debian much
as we are currently doing on the PI and CHIPs.

Again, finding time to do this is the real sticking point.  More as it happens.


May 20th 2017
PI bug squash ongoing. Aiming to make one script fit all PI needs rather than having multiple varriants to maintain.
USBstorage setup next on the list. 


March 20th 2017

The PI port is done (mostly) and needs testing. Much thanks to LMC on the NextThing Forum for fixing and recoding for the PI.
Kick the tires, post up bug reports. 
Needs work, the various Wifi setups for the PI and how Hostapd does and does not work with them. Onward. 


January 31st 2017

The CHIP install is now complete, tested and verified. Please grab a CHIP and give it a try. 
All the issues with boot time starting of the new features has been fixed. 

Next Up.... Move all these fixes over to the PI install and then work out a unified solution to mounting 
and preparing USB storage for use with Anyfesto. 

Once that is in place I will work up the inclusion of KALite, a local version of the amazing Khan Academy complete 
with the ability of students to keep track of their leaning progress. 

Thanks for all the feedback and ideas, keep on that as it helps me stay ontop of this project. 




January 22nd 2017

Good news, if you are using the CHIP then Anyfesto has been getting near daily updates with new services, obvious fixes and 
a few typos corrected. The automatic base install scripts are working well enough to produce a working device and the manual
install guide is covering all manner of services and CHIP foibles to make your install go smoother.

Not so good news, I have been so hunkered down on the CHIP that the PI side of the house has gotten bupkis. For that I will 
make amends, soon....thats the plan.

Is there any good news for the PIs? Much of the work done for the CHIP will easy to slide on over to the PI, so there is that.

Whats working on the CHIP and soon on the PI?

 () AP and Captive Portal no longer using PirateBox/Library Box. This will make things a bit less bumpy for upgrades and updates.
 () Bootstrap is installed for the main landing web page. Those so inclined to work up their own pages will have Bootstrap to 
    work with.
 () Speaking of the main landing web page, the one the Captive Portal will be redirecting everyone to....I have set up a nice 
    simple layout that scales well to mobile, links to many of the features (text chat, wikimedia, file section) are in place 
    and spots for the features planned are in place.
 () An audio player on the main landing page feed by an m3u playlist and javascript
 () IRC with a Web Frontend via HybridIRC and KiwiIRC
 () Wikimedia Server via Kiwix and wikimedia zims
 () Mumble voice chat server is running, I just need to finalize the steps and configs
 () Portable Khan Academy via KA-Lite is coming along but still needs some config work

USB Storage is still something I am deciding on. Given that i want this to be able to be run by non tech folks I am working up a 
script that allows folks to insert a blank USB storage device and it will format it, set up directories and even give the option
to auto populate things like KA-lite data, Project Gutenberg, Wikimedia zims, etc etc. Also add in the automount stuffs for good
measure.

I am shooting to wrap up this phase of work on the CHIP side in the next week or so. I will make an announcement that it should
be all clear to install and know it wont change drastically in 12 hours.

I will then start the slide over to the PI side. When I am done with that I will also send up an announcement.

As always follow along over at https://github.com/tomhiggins/anyfesto/ and send any corrections, feedback and typos...oh the
typos... my way here or there.

And if you have been , thanks for following this project.

-tom
https://cdn.hackaday.io/images/4313181485154480170.jpg
"...which one is the current build?"
