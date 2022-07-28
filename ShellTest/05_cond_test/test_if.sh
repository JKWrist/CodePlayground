#!/bin/bash
echo "Is it morning? Please answer yes or no!"
#读取用户输入的一个变量
read YES_OR_NO
if [ "$YES_OR_NO" = "yes" ]
then
    echo "Good morning"
elif [ "$YES_OR_NO" = "no" ] ; then
    echo "Good afternoon"
else
    echo "Not recognized"
    :
fi
