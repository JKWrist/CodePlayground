#!/bin/sh

set +x

ROUTER=""
MODEL=""

BASEDIR="$(cd "$(dirname "$0")"; pwd -P)"

FW_INTEGRATION_FILE_PATH="/usr/bin/vasdocker.tar.gz"
RUNNING_DIR="/tmp"
PID_NAME="/tmp/vasdocker -c /tmp/vasdocker.conf"
EXE_NAME="vasdocker"
PLUGIN_TAR="vasdocker.tar.gz"

env > ${RUNNING_DIR}/env_info
export PATH=/userfs/bin:/usr/sbin:/bin:/usr/bin:/sbin

trap ignore_sighup SIGHUP
ignore_sighup()
{ 
	true;
}

init_param()
{
	PLUGIN_DIR="/tmp"
	return 0
}

system_init()
{
	ulimit -HS -s 8192
	LD_LIBRARY_PATH=${RUNNING_DIR}
	cp $FW_INTEGRATION_FILE_PATH $PLUGIN_DIR
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
	pid=`ps | grep "/tmp/vasdocker -c /tmp/vasdocker.conf" | grep -v grep | awk -F' ' '{print $1}'`
	if [ "$pid" !=  "" ]
	then
		#echo "target pid is exist "$pid""
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
	local runtar="${RUNNING_DIR}/${PLUGIN_TAR}"

	if [ -e "${exefile}" ];then
		chmod u+x "${exefile}"
		LD_LIBRARY_PATH=. ${PID_NAME} > /tmp/acc.log  2>&1 &
		#LD_LIBRARY_PATH=.:/lib ${PID_NAME} > /tmp/acc.log  2>&1 &
		return
	fi

	if [ -f "${runtar}" ];then
		tar zxvf "${runtar}" -C "${RUNNING_DIR}"
		if [ "$?" = "0" ];then
			chmod u+x "${exefile}"
			LD_LIBRARY_PATH=. ${PID_NAME} >/dev/null 2>&1 &
			#LD_LIBRARY_PATH=.:/lib  ${PID_NAME} >/dev/null 2>&1 &
			#echo startup $(date) > ${TIME_RECORD_FILE}

			# ${runtar} is not needed any more.
			rm "${runtar}"
			return
		fi
	fi

}

check_acc()
{
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
