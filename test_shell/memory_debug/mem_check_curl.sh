#!/bin/sh

check_result()
{
  #echo input params:$1
  if [ $1 -ne 0 ];then
	killall -9 curlTest
	exit $1
  fi
}

echo "memery check curl Test Start..."
killall -9 curlTest > /dev/null 2>&1

./curlTest 2 &

sleep 5

trap 'killall -9 curlTest' 1 2 3 15
echo "test start" > CurlMemTest.log 2>&1
while true
do   
CurlTest_PID=$(ps | grep "curlTest" |grep -v "grep"|grep -v "/bin/sh"  |awk '{print $1}')
echo ============================  >> CurlMemTest.log 2>&1
date >> CurlMemTest.log 2>&1
echo 'CurlTest_PID: '$CurlTest_PID  >> CurlMemTest.log 2>&1

CurlTest_mem=$(cat /proc/$CurlTest_PID/status | grep VmRSS)
check_result $?

CurlTest_VmSize=$(cat /proc/$CurlTest_PID/status | grep VmSize)

echo CurlTest_mem=$CurlTest_mem  >> CurlMemTest.log 2>&1
echo CurlTest_VmSize=$CurlTest_VmSize  >> CurlMemTest.log 2>&1

echo +++++++++++++++++++++++++++++++
echo CurlTest_mem=$CurlTest_mem
sleep 5

done