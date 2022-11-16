#!/bin/bash

g_var=

function mytest2()
{
    echo "mytest2"
    echo "args $1"
    g_var=$1
    return 0
}

mytest2 1

echo "g_var=$g_var"