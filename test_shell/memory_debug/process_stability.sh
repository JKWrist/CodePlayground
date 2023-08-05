#! /bin/sh
 
COUNTER=1
while [ "$COUNTER" -lt 1000000 ]; do
	echo "------- start ----------"
	ps|grep vas
	ps|grep aos
	ps|grep boa
	free
#	brctl show
#	cat /proc/net/sockstat
#	dmesg
	sleep 1
	echo "------- end  -----------"
	COUNTER=$(($COUNTER+1))
done