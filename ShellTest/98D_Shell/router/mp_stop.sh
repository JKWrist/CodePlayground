#!/bin/sh

echo === Stop MP Mode ===

eval `mib get WIFI_TEST`
if [ $WIFI_TEST -eq 1 ]; then
	mib set WIFI_TEST 0
	mib commit cs now
fi

reboot
