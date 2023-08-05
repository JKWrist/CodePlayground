#!/bin/sh
EXEPATH=$(pwd) 
if [ "$#" = 0 ]; then
echo ".......1:./singlemacbindurl.sh \$1(mac_address) \$2(malicious_url) \$3(nonblock(0)|block(1))"
else 
echo $EXEPATH
cd $EXEPATH/

if [ "$3" = "block" ]; then
echo "disable mac_address $1 malicious_url is $2"
iptables -w -I self_control -m mac --mac-source $1 -m string --string $2 --algo kmp -j DROP
ip6tables -w -I self_control6 -m mac --mac-source $1 -m string --string $2 --algo kmp -j DROP
elif [ "$3" = "nonblock" ]; then
echo "enable mac_address $1 malicious_url is $2"
iptables -w -D self_control -m mac --mac-source $1 -m string --string $2 --algo kmp -j DROP
ip6tables -w -D self_control6 -m mac --mac-source $1 -m string --string $2 --algo kmp -j DROP
fi

if [ "$3" = "1" ]; then
echo "disable mac_address $1 malicious_url is $2"
iptables -w -I self_control -m mac --mac-source $1 -m string --string $2 --algo kmp -j DROP
ip6tables -w -I self_control6 -m mac --mac-source $1 -m string --string $2 --algo kmp -j DROP
elif [ "$3" = "0" ]; then
echo "enable mac_address $1 malicious_url is $2"
iptables -w -D self_control -m mac --mac-source $1 -m string --string $2 --algo kmp -j DROP
ip6tables -w -D self_control6 -m mac --mac-source $1 -m string --string $2 --algo kmp -j DROP
fi

#echo -e \\n
#echo \"$1\"
fi
