#! /bin/sh
 
COUNTER=1
while [ "$COUNTER" -lt 1000000 ]; do
	echo "--- $COUNTER start add ---"
	iptables -w -N self_link
	iptables -w -I FORWARD -j self_link
	iptables -nvL -t filter | grep self_link
	echo "---  $COUNTER end add  ---"
	sleep 2
	echo "--- $COUNTER start delete ---"
	iptables -w -D FORWARD -j self_link
	iptables -w -X self_link
	iptables -nvL -t filter | grep self_link
	echo "---  $COUNTER end delete  ---"
	COUNTER=$(($COUNTER+1))
done