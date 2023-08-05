#!/bin/bash -x

function mytest5()
{
    grep "123" test.txt | awk -F: '{print $2}' | while read line ;do
    if [ $line = "yxb" ]; then
        echo "0"
        return 0
    fi
    done
    return 1
}

result=$(mytest5)
 
if [ -z $result ]; then
    echo "no yxb. result is empyt"
else
    echo "have yxb, result is $result"
fi