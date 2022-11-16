#!/bin/bash
function mytest()
{
    echo "mytest function"
    echo "argv[1] = $1"
 
    if [ $1 = "1" ] ;then
        return 1
    else
        return 0
    fi
}

echo "mytest 1"
mytest 1
echo $?

echo "mytest 0"
mytest 0
echo $?

if mytest 1 ; then
    echo "mytest 1"
fi

if mytest 0 ; then
    echo "mytest 0"
fi

echo "end"