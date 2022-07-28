#!/bin/sh

PRINTK_DISABLE=$(/bin/mib get "PRINTK_DISABLE" | awk -F'=' '{print $2}')

echo "diable printk= " $PRINTK_DISABLE " parameter is " $1
#omci
if [ "$PRINTK_DISABLE" == "1" ] && [ "$1" == "1" ] ; then
	echo 1 > /proc/sys/kernel/printk
fi

if [ "$PRINTK_DISABLE" == "1" ] && [ "$1" == "0" ] ; then
	echo 7 > /proc/sys/kernel/printk
fi

