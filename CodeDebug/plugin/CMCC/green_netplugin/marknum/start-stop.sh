#!/bin/ash

[ ! -d "/tmp/mn/" ]&&{
	mkdir -p "/tmp/mn/"
}
[ ! -d "/tmp/marknum/" ]&&{
	mkdir -p "/tmp/marknum/"
}

SLEEP_INTERVAL=10
FILE_SIZE=10000

WIFIDOG_BIN="/tmp/marknum/wifidog"
DPI_BIN="/tmp/marknum/dpi"
DATAUPLOAD_BIN="/tmp/marknum/dataupload"

WIFIDOG_CONFIGFILE="/tmp/marknum/wifidog.conf"
DPI_CONFIGFILE="/tmp/marknum/dpi.conf"
DATAUPLOAD_CONFIGFILE="/tmp/marknum/dataupload.conf"

WIFIDOG_LOGFILE="/var/log/monitor_wifidog.log"
DPI_LOGFILE="/var/log/dpi.log"
DATAUPLOAD_LOGFILE="/var/log/dataupload.log"


MLog()
{
	if [ "$1" = "" ];  #一个等号，厂家的设备不支持 ==
	then
		return 1
	fi
	t=`date`
	msg="$t $1 $2"
	#echo "$msg"
	echo "$msg" >> "$2"
}



manage_log()
{
	max_size=$1
	log_file=$2
	if [ -z "$max_size" -o -z "$log_file" -o ! -f "$log_file" ];then
		return
	fi
	real_size=`ls -l $log_file | awk '{print $5}'`
	if [ -n "$real_size" -a $real_size -ge $max_size ];then
		echo "" > $log_file
	fi
}





create_dataupload_conf()
{
	echo "
	enable 1
	daemon 1
	appfile /var/log/dataupload.log
	cPlaceID 88888888888888
	#serverUrl http://manager.marknum.com/manager/data/queryServers.html
	serverUrl http://dev.marknum.com:8080/device/data/queryServers.do
	defaultServerUrl
	istime 0
	updatatimebegin
	updatatimeend
	uploadTimeSpan 120
	uploadLimit 0
	uploadOneFileTimeout 120
	limitValue 
	dataupsrc    DPI WIFIDOG MAC
	dataUploadinfoList   DPI,/tmp/hs_data,/tmp/mn/dpizip,,;WIFIDOG,/tmp/wdauth,/tmp/mn/dogzip,,;MAC,/tmp/wifideal,/tmp/mn/maczip,,;
	cleanThreadhold 95,80
	maxlogfile 512
	maxmnfile 2
	" > $DATAUPLOAD_CONFIGFILE
}

create_dpi_conf()
{
	echo "
	savepath /tmp/hs_data
	interface br0
	vidtype 1
	httppost 0
	" > $DPI_CONFIGFILE
}



create_wifidog_conf()
{
	gateway_interface="br0"  #LAN侧接口名称
	gateway_eninterface=`route | grep default | awk '{print $8}'`  #获取外网接口名称，不论什么网络模式下【ppp,static,dhcp ...】都要保证正确
	while [ -z "$gateway_eninterface" ]; do
		sleep 5
		echo "getway eninterface zero"
		gateway_eninterface=`route | grep default | awk '{print $8}'`
	done

	gateway_id=`cat /sys/class/net/nas0/address |  sed 's/://g'`

	Iptables_WiFiDog_br_Internet="WiFiDog_"$gateway_interface"_Internet"
	Iptables_WiFiDog_br_Unknown="WiFiDog_"$gateway_interface"_Unknown"
	channelid="11000001"

	echo "
	GatewayID $gateway_id
	GatewayInterface $gateway_interface
	ExternalInterface $gateway_eninterface
	AuthServer {
			Hostname portal.marknum.com
			HTTPPort 8000
			sslport 8443
			sslavailable 1
			Path /wdsys/
			LoginScriptPathFragment login.do?
			PortalScriptPathFragment portal.do?
			PingScriptPathFragment ping.do?
			AuthScriptPathFragment auth.do?
			MsgScriptPathFragment gw_message.do?
			RoamScriptPathFragment roam.do?
			WhiteScriptPathFragment white.do?
			}
	Daemon 1
	GatewayPort 2060
	httpsgatewayPort 2043
	httpskey /tmp/marknum/wifidog.key
	httpscrt /tmp/marknum/wifidog.crt
	CheckInterval 120
	ClientTimeout 60
	HTTPDMaxConn 80
	TrustedMACList ${TrustedMAC}
	TrustedIPList ${TrustedIP}
	TrustedDOMAINList
	HtmlMessageFile /tmp/marknum/wifidog-msg.html

	nettype 0
	gateway
	netid 57f8f4bcabf4655fbf67946fc0f9f25b
	netkey hXfXdbepfdhTcVhhdhTcWgXfgRlWqVUfb55ffff44ffb58b5a644ffffab5a6fff
	AppFile /var/log/monitor_wifidog.log
	authdatapath /tmp/wdauth
	FirewallRuleSet global {
	FirewallRule allow to 114.114.114.114
	FirewallRule allow to 8.8.8.8
	}
	FirewallRuleSet validating-users {
		FirewallRule allow to 0.0.0.0/0
	}

	FirewallRuleSet known-users {
		FirewallRule allow to 0.0.0.0/0
	}

	FirewallRuleSet unknown-users {
		FirewallRule allow udp port 53
		FirewallRule allow tcp port 53
		FirewallRule allow udp port 67
		FirewallRule allow tcp port 67
	}

	FirewallRuleSet locked-users {
		FirewallRule block to 0.0.0.0/0
	}
	authvlanlist
	authsubnetlist
	conntype
	sendmode
	syncbatch 1

	checkua 0
	ualist
	snmpmode
	snmpquery snmpwalk\-c\\-\\
	checkmode
	syncssl 0
	pingerrtimes 3
	pingretfile /tmp/pingretfile
	snmpfile /tmp/snmp/snmp.log
	redirectmode 1
	authmode 0
	roammode 1
	whiteintervaltime 600
	roamintervaltime 600
	channelid $channelid
	version 20210101000000
	iptablesmask 0000/0xfff0000

	" > $WIFIDOG_CONFIGFILE
}

CheckProcess()
{
	if [ "$1" = "" ];
	then
		return 0
	fi

	PROCESS_NUM=`ps | grep "$1" | grep -v "grep" | wc -l`

	if [ $PROCESS_NUM -gt 0 ];
	then
		return 1
	else
		return 0
	fi
}

####################################################################################

#创建配置文件
create_wifidog_conf
create_dpi_conf
create_dataupload_conf
#启动插件
sleep 2
op_mode=`flash get OP_MODE | sed -r 's/.*=//'`
if [ "$op_mode" = "0" ]; then
	$WIFIDOG_BIN -c $WIFIDOG_CONFIGFILE >/dev/null 2>&1 &
	$DPI_BIN -c $DPI_CONFIGFILE >/dev/null  2>&1 &
	$DATAUPLOAD_BIN -i nas0 -c $DATAUPLOAD_CONFIGFILE >/dev/null 2>&1 &
fi
sleep 5

#监控插件
while [ 1 ]; do

	op_mode=`flash get OP_MODE | sed -r 's/.*=//'`
	if [ "$op_mode" = "0" ]; then

#wifidog
		CheckProcess "$WIFIDOG_BIN"
		ret=$?
		if [ $ret -eq 0 ]; then
			iptables -t filter -D  FORWARD -i $gateway_interface -j $Iptables_WiFiDog_br_Internet 2>&1 > /dev/null
			iptables -t nat -D  $Iptables_WiFiDog_br_Unknown -p tcp -m tcp --dport 80 -j REDIRECT --to-ports 2060 2>&1 > /dev/null
			sleep 10
			MLog "wifidog start  from  monitor+++ "
			$WIFIDOG_BIN -c $WIFIDOG_CONFIGFILE >/dev/null  2>&1 &
		fi

#dataupload
		CheckProcess "$DATAUPLOAD_BIN"
		ret=$?
		if [ $ret -eq 0 ]; then
			MLog "dataupload start dataupload from monitor+++"
			$DATAUPLOAD_BIN -i nas0 -c $DATAUPLOAD_CONFIGFILE >/dev/null 2>&1 &
		fi

#dpi
		CheckProcess "$DPI_BIN"
		ret=$?
		if [ $ret -eq 0 ]; then
			MLog "dpi start dataupload from monitor+++"
			$DPI_BIN -c $DPI_CONFIGFILE >/dev/null 2>&1 &
		fi

#管理日志大小
		manage_log $FILE_SIZE $WIFIDOG_LOGFILE
		manage_log $FILE_SIZE $DPI_LOGFILE
		manage_log $FILE_SIZE $DATAUPLOAD_LOGFILE

	fi

	sleep ${SLEEP_INTERVAL}
done



