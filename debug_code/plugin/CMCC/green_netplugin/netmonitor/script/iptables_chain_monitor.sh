#!/bin/sh

if [ $1 -eq 4 ];then
        ip_table=iptables
elif [ $1 -eq 6 ];then
        ip_table=ip6tables
fi

chain=$2
set_position=$3
#echo ip_table=$ip_table
#echo chain=$chain

max_position=`$ip_table -w -vnL FORWARD | wc -l`
max_position=$(($max_position-2))
if [ $set_position -gt $max_position ]; then
        set_position=$(($max_position+1))
fi


array=`$ip_table -w -vnL FORWARD --line | grep "$chain" | awk '{print $1}'`
#echo array=$array
#echo set_position=$set_position
for var in $array
do
        if [ $var -ne $set_position ];then
                #echo var=$var
                $ip_table -w -D FORWARD -j $chain
        fi
done

array=`$ip_table -w -vnL FORWARD $set_position | grep "$chain" | wc -l`
if [ $array -eq 0 ];then
    $ip_table -w -I FORWARD $set_position -j $chain
fi
#$ip_table -N $chain; 