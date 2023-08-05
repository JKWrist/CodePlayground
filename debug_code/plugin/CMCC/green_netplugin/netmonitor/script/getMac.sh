#!/bin/sh

if [ "$#" = 0 ]; then
echo ".......1:./getMac.sh \$1(lan(0)|wan(1)) $2(ifname)"
else

if [ "$1" = "0" ]; then
echo "" > /tmp/deviceMac_gw.txt && ifconfig |grep $2|awk '{print $5}' > /tmp/deviceMac_gw.txt && echo "" >> /tmp/deviceMac_gw.txt
fi

if [ "$1" = "1" ]; then
echo "" > /tmp/wanMac_gw.txt && ifconfig |grep $2|awk '{print $5}' > /tmp/wanMac_gw.txt && echo "" >> /tmp/wanMac_gw.txt
fi

fi


