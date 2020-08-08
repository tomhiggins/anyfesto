rm /var/www/html/stream.m3u
ip="$(ip addr | grep 'state UP' -A2 | tail -n1 | awk '{print $2}' | cut -f1 -d'/')" 
addy="http://$ip/content/Radio/"
for file in /home/pi/content/Radio/*mp3
do echo ""$addy"$(basename "$file")">>/var/www/html/stream.m3u
done
