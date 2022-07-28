#!/bin/sh
eval `mib get OP_MODE`

MATCH_FILE=/var/dnsmasq.conf
if [ $OP_MODE -eq 1 ]; then
	MATCH_FILE=/var/resolv.conf
fi

PIDFILE=/var/run/udhcpd.pid
DHCPV4_CONN_TIME="/tmp/dhcpv4_conn_timestamp.$interface"
if [ $1 = 'bound' ] && [ "${ip:0:8}" != "169.254." ]; then
	cat /proc/uptime > $DHCPV4_CONN_TIME
fi

if [ $1 = 'bound' ] || [ $1 = 'renew' ]; then
	/var/udhcpc/udhcpc.$interface
	if [ "$ip" ]; then
		/bin/updateddctrl $interface 1
		/bin/ethctl route add		
#		if [ -f /var/run/udhcpd.pid ]; then
#			PID=`cat $PIDFILE`
#			echo "Kick dhcrelay to sync interface-2"
#			kill -17 $PID
#		fi
		
		if [ $1 = 'renew' ] && [ -f /var/run/systemd.pid ]; then
			if [ "$dns" ]; then
				for i in $dns
				do
					if [ $i = '0.0.0.0' ] || [ $i = '255.255.255.255' ]; then
						continue
					fi
				
					dns_ip=`echo $i`
					grep $dns_ip $MATCH_FILE > /dev/null
					if [ $? -ne 0 ]; then
						PID=`cat /var/run/systemd.pid`
						kill -SIGUSR1 $PID
						break
					fi
				done
			fi	
		fi
	fi
elif [ $1 = 'deconfig' ]; then
	/etc/scripts/udhcpc.deconfig
	if [ -f $DHCPV4_CONN_TIME ]; then
		rm $DHCPV4_CONN_TIME
	fi
elif [ $1 = 'nak' ]; then
	echo "dhcp nak event occurs"
fi
