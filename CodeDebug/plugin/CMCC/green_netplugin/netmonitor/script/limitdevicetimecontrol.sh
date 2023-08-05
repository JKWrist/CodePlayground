#!/bin/sh
EXEPATH=$(pwd) 
if [ "$#" = 0 ]; then
echo ".......1:./limitdevicetimecontrol.sh \$1(mac_address) \$2(time_start) \$3(time_stop) \$4(weekdays) \$5(nonblock(0)|block(1))"
else 
echo $EXEPATH
cd $EXEPATH/

if [ "$5" = "block" ]; then
echo "add black list $1 start_time $2 stop_time $3 weekdays is $4"
iptables -w -I self_control -m mac --mac-source $1 -m time --timestart $2 --timestop $3 --weekdays $4  --kerneltz -j DROP
ip6tables -w -I self_control6 -m mac --mac-source $1 -m time --timestart $2 --timestop $3 --weekdays $4 --kerneltz -j DROP
elif [ "$5" = "nonblock" ]; then
echo "del black list $1 start_time $2 stop_time $3 weekdays is $4"
iptables -w  -D self_control -m mac --mac-source $1 -m time --timestart $2 --timestop $3 --weekdays $4 --kerneltz -j DROP
ip6tables -w  -D self_control6 -m mac --mac-source $1 -m time --timestart $2 --timestop $3 --weekdays $4 --kerneltz  -j DROP
fi

if [ "$5" = "1" ]; then
echo "add black list $1 start_time $2 stop_time $3 weekdays is $4"
iptables -w  -I self_control -m mac --mac-source $1 -m time --timestart $2 --timestop $3 --weekdays $4 --kerneltz -j DROP
ip6tables -w  -I self_control6 -m mac --mac-source $1 -m time --timestart $2 --timestop $3 --weekdays $4 --kerneltz  -j DROP
elif [ "$5" = "0" ]; then
echo "del black list $1 start_time $2 stop_time $3 weekdays is $4"
iptables -w  -D self_control -m mac --mac-source $1 -m time --timestart $2 --timestop $3 --weekdays $4 --kerneltz  -j DROP
ip6tables -w  -D self_control6 -m mac --mac-source $1 -m time --timestart $2 --timestop $3 --weekdays $4 --kerneltz  -j DROP
fi

#echo -e \\n
#echo \"$1\"
fi
