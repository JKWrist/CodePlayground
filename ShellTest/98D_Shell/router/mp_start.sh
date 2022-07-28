#!/bin/sh

echo === Start MP Mode ===

LANIP=${1:-192.168.1.1}
NETMASK=${2:-255.255.255.0}

NAX_MPDAEMON=/bin/11N_UDPserver
AX_MPDAEMON=/bin/AX_UDPserver

# set MP mode for halbb_dm/halrf_dm config
iwpriv wlan0 mp_set_drv_mode 1
iwpriv wlan1 mp_set_drv_mode 1

#kill hostapd_cli and hostapd
killall hostapd_cli > /dev/null 2>&1
killall hostapd > /dev/null 2>&1

#killall udhcpc
killall udhcpc > /dev/null 2>&1

#killall 11N_UDPserver
killall 11N_UDPserver > /dev/null 2>&1

#killall AX_UDPserver
killall AX_UDPserver > /dev/null 2>&1

sleep 1

#UP wlan interface
ifconfig wlan0 up
sleep 1

ifconfig wlan1 up
sleep 1

iwpriv wlan0 mp_start
sleep 1

iwpriv wlan1 mp_start
sleep 1

#config br0 IP
#echo ====LANIP=$LANIP NETMASK=$NETMASK ====
#ifconfig br0 $LANIP netmask $NETMASK

#start udpserver
if [ -f "$NAX_MPDAEMON" ]; then
        $NAX_MPDAEMON &
fi

if [ -f "$AX_MPDAEMON" ]; then
        $AX_MPDAEMON &
fi
