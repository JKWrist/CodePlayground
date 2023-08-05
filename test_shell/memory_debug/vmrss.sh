#!/bin/sh

interval=5
progress=bvasPlugin

while true
	do
		#dns
		pid=`ps |grep ${progress} |grep -v grep | awk '{print $1}'`
		echo "${progress} pid = ${pid}"			#>> /tmp/proc_memlog.txt

		DATE=`date '+%Y-%m-%d-%H:%M:%S'`
		echo $DATE 								#>> /tmp/proc_memlog.txt
		cat /proc/${pid}/status|grep -e VmRSS  	#>> /tmp/proc_memlog.txt
		cat /proc/${pid}/status|grep -e VmSize  #>> /tmp/proc_memlog.txt
		echo $blank 							#>> /tmp/proc_memlog.txt
		
		mem=$(grep "VmRSS" /proc/$pid/status | awk '{print $2}')
#		if [ $mem -gt $max_mem ]; then
		
		ps|grep vas
		ps|grep aos
		ps|grep boa
		ps|grep ${progress}
		free
		echo $blank

#		brctl show

		cat /proc/net/sockstat
		echo $blank

		sleep $interval
		
		cd /tmp
		tftp -pl smart.log 192.168.10.66
	done

#max_pid=0
#max_mem=0

#for pid in $(ls /proc | grep "^[0-9]*$"); do
#	mem=$(grep "VmRSS" /proc/$pid/status | awk '{print $2}')
#	cat /proc/$pid/status |grep "Name:"
#	cat /proc/$pid/status |grep "Name:"
#	if [ $mem -gt $max_mem ]; then
#		max_mem=$mem
#		max_pid=$pid
#	fi
#done
#
#echo "Max memory usage: PID=$max_pid, VmRSS=$max_mem KB"
