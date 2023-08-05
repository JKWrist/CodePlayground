#!/bin/sh
while true
do
	cat /proc/meminfo
	cat /proc/slabinfo
	ps

	smartdns_pid=$(ps | grep smartdns | grep -v grep | awk '{print $1}')
	cat /proc/$smartdns_pid/status

	cmhi_socks5_pid=$(ps | grep cmhi_socks5 | grep -v grep | awk '{print $1}')
	cat /proc/$cmhi_socks5_pid/status
	
	bvasPlugin_pid=$(ps | grep bvasPlugin | grep -v grep | grep -v bvasPlugin_mon | awk '{print $1}')
	cat /proc/$bvasPlugin_pid/status

	sleep 30
done