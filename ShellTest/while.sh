#! /bin/sh
 
COUNTER=1
while [ "$COUNTER" -lt 1000000 ]; do
	echo "------- start ----------"
	ifconfig
	sleep 1
	echo "------- end  -----------"
	COUNTER=$(($COUNTER+1))
done