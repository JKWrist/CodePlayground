#!/bin/sh
#reltek RTL8198D
echo "" > /tmp/deviceMac.txt &&  ifconfig | grep br0 | awk '{print $5}' > /tmp/deviceMac.txt
