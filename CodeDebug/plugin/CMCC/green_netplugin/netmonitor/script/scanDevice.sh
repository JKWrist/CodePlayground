#!/bin/sh
IF=$1
cat /proc/net/arp | grep $IF | awk '{print $1 " " $3 " " $4}' | awk '!a[$2]++ || !a[$3]++' > /tmp/arpout_gw.txt
