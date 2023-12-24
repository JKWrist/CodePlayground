#!/bin/sh
set -x

hsan_table()
{
	cat /proc/hsan/cfe/lrn/lrn_dump
	echo 1 > /proc/hsan/cfe/lrn/lrn_flush
	cat /proc/hsan/cfe/lrn/lrn_dump
}

hsan_conntrack()
{
	cat /proc/net/nf_conntrack
	conntrack -D
	cat /proc/net/nf_conntrack
}


while :
do
	cat /proc/hsan/cfe/lrn/enable
	hsan_table
	hsan_conntrack

	sleep 1

	iptables  -nvL|grep ali
	ip6tables -nvL|grep ali

	sleep 2
done