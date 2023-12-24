#!/bin/sh
set +x

hsan_table()
{
	cat /proc/hsan/cfe/lrn/lrn_dump
}

hsan_conntrack()
{
	cat /proc/net/nf_conntrack
}

while :
do
	hsan_table
	hsan_conntrack
	
	iptables -nvL self_control
	ip6tables -nvL self_control
	
	sleep 2
done