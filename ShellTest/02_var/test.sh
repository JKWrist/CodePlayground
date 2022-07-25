#!/bin/bash

globalVar1="hello"

function test()
{
  globalVar2="world"
  local localVar="junze"
  echo $localVar
}

#调用函数
test

echo $globalVar1 $globalVar2 $localVar

export environVar="this is in environ"

#调用子脚本
./subScript.sh

#验证子进程修改环境变量之后父进程没有改变
echo "main environVar" $environVar

#删除变量
unset globalVar1
echo "globalVar1 = " $globalVar1