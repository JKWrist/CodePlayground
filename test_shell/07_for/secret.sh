#!/bin/bash

echo "Please input passwd"
read try
errCount=1

while [ "$try" != "secret" ]
do
    if [ "$errCount" -ge 5 ]
    then
        echo "Error 5 times, exit"
    fi
    echo "Sorry , try again!"
    read try
done

if [ "$errCount" -lt 5 ]  #if 判断条件右侧 ] 前面是有空格的
    then
    echo "the password is right"
fi