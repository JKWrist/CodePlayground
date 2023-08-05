#!/bin/bash -x
if  (( 3 < 5 ));then
	echo "A"
else 
	echo "B"
fi
#output:A
if  [ 3 -lt 3 ] ;then
	echo "A"
else 
	echo "B"
fi


A=1
B=2
if [ A == B ];then
	echo "B"=$B
else 
	echo "A="$A
fi

#output:B