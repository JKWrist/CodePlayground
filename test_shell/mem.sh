#!/bin/sh
set +x


while :
do
	cat /proc/meminfo
	# cat /proc/slabinfo
	free

	sleep 5
done