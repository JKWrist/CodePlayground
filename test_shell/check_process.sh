#!/bin/sh
set +x
debug="y"

pid=`ps | grep $1 | grep -v grep | grep -v check_process | awk -F' ' '{print $1}'`

if [ "$pid" !=  "" ];then
	if [ $debug = "y" ];then
		echo "target pid is exist "$pid""
	fi
	echo 1
else
	if [ $debug = "y" ];then
		echo "target pid is not exist"
	fi
	echo 0
fi
