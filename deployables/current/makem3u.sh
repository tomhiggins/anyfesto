rm /var/www/html/stream.m3u
addy="http://ChangeToIpOrOnoin/content/Radio/"
for file in /home/pi/content/Radio/*mp3
do echo ""$addy"$(basename "$file")">>/var/www/html/stream.m3u
done
