#!/bin/sh
EXEPATH=$(pwd) 
if [ "$#" = 0 ]; then
echo ".......1:./firewallcontrol.sh \$1(malicious_url) $2(nonblock(0)|block(1))"
else 
echo $EXEPATH
cd $EXEPATH/

if [ "$2" = "block" ]; then
echo "disable malicious $1"
iptables -w -I self_control -m string --string $1 --algo kmp  -j DROP
ip6tables -w -I self_control6 -m string --string $1 --algo kmp  -j DROP
elif [ "$2" = "nonblock" ]; then
echo "enable malicious $1"
iptables -w -D self_control -m string --string $1 --algo kmp  -j DROP
ip6tables -w -D self_control6 -m string --string $1 --algo kmp  -j DROP
fi

if [ "$2" = "1" ]; then
echo "disable malicious $1"
iptables -w -I self_control -m string --string $1 --algo kmp  -j DROP
ip6tables -w -I self_control6 -m string --string $1 --algo kmp  -j DROP
elif [ "$2" = "0" ]; then
echo "enable malicious $1"
iptables -w -D self_control -m string --string $1 --algo kmp  -j DROP
ip6tables -w -D self_control6 -m string --string $1 --algo kmp  -j DROP
fi
#echo -e \\n
#echo \"$1\"
fi
