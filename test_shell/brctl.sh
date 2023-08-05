#!/bin/sh

interval=1

while true
	do
		brctl show
		ls -al /var/skip_ahsapd_restart_wifi
		sleep ${interval}
	done
