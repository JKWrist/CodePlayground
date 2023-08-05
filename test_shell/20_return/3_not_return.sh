#!/bin/bash
 
function mytest3()
{
    grep "123" test.txt | awk -F: '{print $2}' | while read line ;do
    echo "$line"
    if [ $line = "yxb" ]; then
        return 0
    fi
    done
    echo "mytest3 here "
    return 1
}

g_var=
 
function mytest4()
{
    grep "123" test.txt | awk -F: '{print $2}' | while read line ;do
    echo "$line"
    if [ $line = "yxb" ]; then
        g_var=0
        echo "g_var=0"
        return 0
    fi
    done
    echo "mytest4 here "
    return 1
}

mytest3
echo $?

mytest4
echo "g_var=$g_var"