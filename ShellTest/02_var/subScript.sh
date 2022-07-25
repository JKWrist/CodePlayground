#!/bin/bash
echo "this is in sub script"
echo $globalVar1
echo "sub script end"

echo "sub environVar 1" $environVar

#子进程修改环境变量
export environVar="222222222222"
echo "sub environVar 2" $environVar