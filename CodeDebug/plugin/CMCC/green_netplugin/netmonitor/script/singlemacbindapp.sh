#!/bin/sh
EXEPATH=$(pwd) 
if [ "$#" = 0 ]; then
echo ".......1:./singlemacbindapp.sh \$1(mac_address) \$2(cmdString) \$3(nonblock(0)|block(1))"
else 
echo $EXEPATH
cd $EXEPATH/

if [ "$#" = 2 ]; then

if [ "$2" = "block" ]; then
echo "disable cmdString is $1"
iptables -w -I self_control -m string --hex-string "|$1|" --algo bm -j DROP
ip6tables -w -I self_control6 -m string --hex-string "|$1|" --algo bm -j DROP
elif [ "$2" = "nonblock" ]; then
echo "enable cmdString is $1"
iptables -w -D self_control -m string --hex-string "|$1|" --algo bm -j DROP
ip6tables -w  -D self_control6 -m string --hex-string "|$1|" --algo bm -j DROP
fi

if [ "$2" = "1" ]; then
echo "disable malicious_url is $1"
iptables -w -I self_control -m string --hex-string "|$1|" --algo bm -j DROP
ip6tables -w -I self_control6 -m string --hex-string "|$1|" --algo bm -j DROP
elif [ "$2" = "0" ]; then
echo "enable malicious_url is $1"
iptables -w -D self_control -m string --hex-string "|$1|" --algo bm -j DROP
ip6tables -w -D self_control6 -m string --hex-string "|$1|" --algo bm -j DROP
fi

elif [ "$#" = 3 ]; then
if [ "$3" = "block" ]; then
echo "disable mac_address $1 cmdString is $2"
iptables -w -I self_control -m mac --mac-source $1 -m string --hex-string "|$2|" --algo bm -j DROP
ip6tables -w -I self_control6 -m mac --mac-source $1 -m string --hex-string "|$2|" --algo bm -j DROP
elif [ "$3" = "nonblock" ]; then
echo "enable mac_address $1 cmdString is $2"
iptables -w -D self_control -m mac --mac-source $1 -m string --hex-string "|$2|" --algo bm -j DROP
ip6tables -w -D self_control6 -m mac --mac-source $1 -m string --hex-string "|$2|" --algo bm -j DROP
fi

if [ "$3" = "1" ]; then
echo "disable mac_address $1 malicious_url is $2"
iptables -w -I self_control -m mac --mac-source $1 -m string --hex-string "|$2|" --algo bm -j DROP
ip6tables -w -I self_control6 -m mac --mac-source $1 -m string --hex-string "|$2|" --algo bm -j DROP
elif [ "$3" = "0" ]; then
echo "enable mac_address $1 malicious_url is $2"
iptables -w -D self_control -m mac --mac-source $1 -m string --hex-string "|$2|" --algo bm -j DROP
ip6tables -w -D self_control6 -m mac --mac-source $1 -m string --hex-string "|$2|" --algo bm -j DROP
fi

fi



#echo -e \\n
#echo \"$1\"
fi
