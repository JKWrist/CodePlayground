#!/bin/sh
EXEPATH=$(pwd) 
if [ "$#" = 0 ]; then
echo ".......1:./addblacklist.sh \$1(mac_address) $2(nonblock(0)|block(1))"
else 
echo $EXEPATH
cd $EXEPATH/

if [ "$2" = "block" ]; then
echo "disable mac_address $1"
iptables -w -I self_control -m mac --mac-source $1 -j DROP
ip6tables -w -I self_control6 -m mac --mac-source $1 -j DROP
elif [ "$2" = "nonblock" ]; then
echo "enable mac_address $1"
iptables -w -D self_control -m mac --mac-source $1 -j DROP
ip6tables -w -D self_control6 -m mac --mac-source $1 -j DROP
fi

if [ "$2" = "1" ]; then
echo "disable mac_address $1"
iptables -w -I self_control -m mac --mac-source $1 -j DROP
ip6tables -w -I self_control6 -m mac --mac-source $1 -j DROP
elif [ "$2" = "0" ]; then
echo "enable mac_address $1"
iptables -w -D self_control -m mac --mac-source $1 -j DROP
ip6tables -w -D self_control6 -m mac --mac-source $1 -j DROP
fi
#echo -e \\n
#echo \"$1\"
fi
