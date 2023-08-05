#!/bin/sh

set +x

ROUTER=""
MODEL=""

RUNNING_DIR="/tmp/netmonitor"
PID_FILE="/var/run/netmonitor.pid"
PID_NAME="/tmp/netmonitor/netmonitor"
EXE_NAME="netmonitor"

if [ -d "/tmp/netmonitor/lib" ];then
	if [ "$(ls /tmp/netmonitor/lib)" ];then	
		if [ -f "/tmp/netmonitor/lib/SLB" ];then
		export LD_LIBRARY_PATH=/tmp/netmonitor/lib:$LD_LIBRARY_PATH
	else
		export LD_LIBRARY_PATH=/tmp/netmonitor/lib:$LD_LIBRARY_PATH
		export LD_LIBRARY_PATH=/tmp/:$LD_LIBRARY_PATH
	fi
	fi
fi

trap ignore_sighup SIGHUP
ignore_sighup()
{ 
	true;
}

init_param()
{
	PLUGIN_DIR="/tmp/netmonitor"
	return 0
}

system_init()
{
	ulimit -HS -s 8192
}

check_dir()
{
	if [ ! -d "${RUNNING_DIR}" ];then
		mkdir -p "${RUNNING_DIR}" >/dev/null 2>&1
		[ "$?" != "0" ] && return 1
	fi

	return 0
}

check_running()
{
	pid=`ps | grep -w "${PID_NAME}" | grep -v grep | awk -F' ' '{print $1}'`
	if [ "$pid" !=  "" ]
	then
		echo "target pid is exist "$pid""
		return 0
	fi


	if [ "$pid" =  "" ]
	then
		echo "target pid is not exist "
		return 1
	fi

}

start_acc()
{
	local exefile="${RUNNING_DIR}/${EXE_NAME}"

	if [ -e "${exefile}" ];then
		chmod u+x "${exefile}"
		cd ${RUNNING_DIR}
		${PID_NAME} >/dev/null 2>&1 &
		return
	fi

}

check_acc() {
	cd $RUNNING_DIR

	check_running
	[ "$?" = "0" ] && return
	start_acc
	return
}

init_param
[ "$?" != "0" ] && exit 1

system_init
check_dir
[ "$?" != "0" ] && exit 1

while :
do
	check_acc
	sleep 60
	check_running
	set +x
	exec 2>/dev/null || true
	if [ "$?" = "0" ];then
		sleep 60
	else
		sleep 5
	fi
done
