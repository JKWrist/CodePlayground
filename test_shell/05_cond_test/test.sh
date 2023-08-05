#!/bin/bash

if [ -f /bin/bash ]
then
    echo "/bin/bash is a file"
else
    echo "/bin/bash is not a file"
fi

if :
then
    echo "always true"
fi

if false
then
    : 
else
    echo "always false"
fi



var=1
var2=2

if [ $var -eq 1 ] && [ $var2 -eq 2 ] 
then
    echo "yes"
fi
