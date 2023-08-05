#!/bin/sh

check_result()
{
  #echo input params:$1
  if [ $1 -ne 0 ];then
    killall -9 curlTest
    killall -9 verifyTest
    exit $1
  fi
}
echo "memery check Test Start..."
killall -9 curlTest > /dev/null 2>&1
killall -9 verifyTest > /dev/null 2>&1

./curlTest 2 &
./verifyTest 2 &

sleep 5

trap 'killall -9 curlTest & killall -9 verifyTest' 1 2 3 15
echo "test start" > BvasPluginMemTest.log 2>&1
while true
do   
CurlTest_PID=$(ps | grep "curlTest" |grep -v "grep"|grep -v "/bin/sh"  |awk '{print $1}')
echo ============================  >> BvasPluginMemTest.log 2>&1
date >> BvasPluginMemTest.log 2>&1
echo 'CurlTest_PID: '$CurlTest_PID  >> BvasPluginMemTest.log 2>&1

CurlTest_mem=$(cat /proc/$CurlTest_PID/status | grep VmRSS)
check_result $?

CurlTest_VmSize=$(cat /proc/$CurlTest_PID/status | grep VmSize)

echo CurlTest_mem=$CurlTest_mem  >> BvasPluginMemTest.log 2>&1
echo CurlTest_VmSize=$CurlTest_VmSize  >> BvasPluginMemTest.log 2>&1

#sleep 5

VerifyTest_PID=$(ps | grep "verifyTest" |grep -v "grep"|grep -v "/bin/sh"  |awk '{print $1}')
echo ============================ >> BvasPluginMemTest.log 2>&1
echo 'VerifyTest_PID: '$VerifyTest_PID >> BvasPluginMemTest.log 2>&1

VerifyTest_mem=$(cat /proc/$VerifyTest_PID/status | grep VmRSS)
check_result $?

VerifyTest_VmSize=$(cat /proc/$VerifyTest_PID/status | grep VmSize)
echo VerifyTest_mem=$VerifyTest_mem >> BvasPluginMemTest.log 2>&1
echo VerifyTest_VmSize=$VerifyTest_VmSize >> BvasPluginMemTest.log 2>&1

echo +++++++++++++++++++++++++++++++
echo CurlTest_mem=$CurlTest_mem
echo VerifyTest_mem=$VerifyTest_mem
sleep 5

done