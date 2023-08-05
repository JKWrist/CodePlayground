#!/bin/sh

check_result()
{
  #echo input params:$1
  if [ $1 -ne 0 ];then
    echo "test failed, please read the BvasPluginTest.log to find out why!!"
    exit $1
  fi
}

echo "cmd test start, please wait...."

./cmdTest > BvasPluginTest.log 2>&1
check_result $?

echo "cmd test done, SUCCESS!"

echo "curl test start, please wait...."

./curlTest >> BvasPluginTest.log 2>&1
check_result $?

echo "curl test done, SUCCESS!"

echo "dns test start, please wait...."

./dnsTest >> BvasPluginTest.log 2>&1
check_result $?

echo "dns test done, SUCCESS!"

echo "libsec2_router.so test start, please wait...."

./verifyTest >> BvasPluginTest.log 2>&1
check_result $?

echo "libsec2_router.so test done, SUCCESS!"

echo "All test scripts run to completion!"