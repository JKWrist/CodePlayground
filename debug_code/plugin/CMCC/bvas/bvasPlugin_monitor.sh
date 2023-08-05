#!/bin/sh

set +x

ROUTER=""
MODEL=""

BASEDIR="$(cd "$(dirname "$0")"; pwd -P)"

RUNNING_DIR="/tmp/bvas"
PID_NAME="./bvasPlugin"
EXE_NAME="bvasPlugin"

trap ignore_sighup SIGHUP
ignore_sighup() { 
    true;
}


system_init() {
    ulimit -HS -s 8192
}

check_running() {

    pid=`ps | grep '\<bvasPlugin\>' | grep -v grep | awk -F' ' '{print $1}'`
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

start_acc() {
    
	local exefile="${RUNNING_DIR}/${EXE_NAME}"

    if [ -e "${exefile}" ];then
        chmod u+x "${exefile}"
	    cd ${RUNNING_DIR}
        LD_LIBRARY_PATH=./:./accctrl:./acc:./cmhi_acc:./netmonitor ${PID_NAME} >/dev/null 2>&1 &
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

system_init

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
