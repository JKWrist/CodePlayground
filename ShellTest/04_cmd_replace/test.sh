#!/bin/bash
#dateTime='date' #反引号，并不是单引号，这就是需要实际去写shell的原因

#dateTime=`date`

dateTime=$(date)
echo "dateTime is " $dateTime

#获取当前脚本所在路径，在这个路径touch一个1.txt
curPath=$(cd `dirname $0`;pwd) #会fork出一个子进程来
touch $curPath/1.txt

VAR=45
VAR2=2
echo $(($VAR+3))
echo $[$VAR+3]
echo $[VAR+3]

echo $[VAR*VAR2]
echo $[$VAR*$VAR2]

echo $[8#10+11] #将10以8进制来解析