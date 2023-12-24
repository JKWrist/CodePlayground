#!/bin/sh
set +x

clean_hsan()
{
	conntrack -D
	echo 1 > /proc/hsan/cfe/lrn/lrn_flush
}

while :
do
	clean_hsan
	sleep 2
done