#!/bin/sh

#开启网桥防火墙：
if [ "$1" = 1 ]; then
#wificonf -f /etc/sysctl.conf set net.bridge.bridge-nf-call-iptables 1
echo 1 > /proc/sys/net/bridge/bridge-nf-call-iptables
#wificonf -f /etc/sysctl.conf set net.bridge.bridge-nf-call-ip6tables 1
echo 1 > /proc/sys/net/bridge/bridge-nf-call-ip6tables
#uci set system.@system[0].greenpluginfirewall=1; uci commit system
fi
#关闭网桥防火墙：
if [ "$1" = 0 ]; then
#wificonf -f /etc/sysctl.conf set net.bridge.bridge-nf-call-iptables 0
echo 0 > /proc/sys/net/bridge/bridge-nf-call-iptables
#wificonf -f /etc/sysctl.conf set net.bridge.bridge-nf-call-ip6tables 0
echo 0 > /proc/sys/net/bridge/bridge-nf-call-ip6tables
#uci set system.@system[0].greenpluginfirewall=0; uci commit system
fi
