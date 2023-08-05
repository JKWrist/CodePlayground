#!/bin/sh
#检查命令是否执行成功
LOG_FILE="check_log.txt"
check_success(){
    ${cmd}
    if [ $? -ne 0 ]; then
        echo "###失败###  执行命令： $cmd"
		echo "###失败###  执行命令： $cmd" >> $LOG_FILE
    else
        echo "###成功###  执行命令： $cmd"
    fi
}
check_success_no_cmd(){
    if [ $? -ne 0 ]; then
        echo "###失败###  执行命令： $cmd_hint"
		echo "###失败###  执行命令： $cmd_hint" >> $LOG_FILE
    else
        echo "###成功###  执行命令： $cmd_hint"
    fi
}
check_in(){
	result=$(${strA} | grep $strB)
if [ -n "$result" ]
	then
		echo $strB"在"$AA"中"
	else
		echo $strB"不在"$AA"中"
		echo $strB"不在"$AA"中" >> $LOG_FILE
	fi
}
check_not_in(){
	result=$(${strA} | grep $strB)
if [ -n "$result" ]
	then
		echo $strB"依然在"$AA"中"
		echo $strB"依然在"$AA"中" >> $LOG_FILE
	else
		echo $strB"不在"$AA"中"	
	fi
}
current=`date "+%Y-%m-%d %H:%M:%S"`
echo "执行时间: "$current
echo " " >> $LOG_FILE
echo "执行时间: "$current >> $LOG_FILE
echo "一、 检查智能加速   "
#读取linux版本
linux_version=$(cat /proc/version)
#截断处理原始数据
linux_version_tmp=${linux_version#Linux version }
linux_version_raw=${linux_version_tmp%% *}
linux_version_num=${linux_version_raw%%-*}
#得到版本号，进行判断
echo "*** 1. 检查linux内核版本"
linux_version_target="2.6"
if [ `expr $linux_version_num \> $linux_version_target` -eq 0 ];then
    echo "linux内核版本为 $linux_version_num 低于2.6"
	echo "linux内核版本为 $linux_version_num 低于2.6" >> $LOG_FILE
else
    echo "linux内核版本检查完成,版本为$linux_version_num"
fi
echo " "
#检查tun
echo "***  2. 检查tun  ***"
if [ -e /dev/tun ] ; then
    echo "tun存在/dev/tun"
else
    if [ -e /dev/net/tun ] ; then
        echo "tun存在/dev/net/tun"
    else
        echo "tun不存在"
		echo "tun不存在" >> $LOG_FILE
    fi
fi
echo " "
#检查ipatables版本
echo "***  3. 检查ipatables版本  ***"
iptables_version=$(iptables -V)
iptables_version_num=${iptables_version#*v}
iptables_version_target="1.4.10"
if [ `expr $iptables_version_num \> $iptables_version_target` -eq 0 ];then
    echo "iptables版本为 $iptables_version_num 低于1.4.10"
	echo "iptables版本为 $iptables_version_num 低于1.4.10" >> $LOG_FILE
else
    echo "iptables版本检查完成，版本为$iptables_version_num"
fi
echo " "
#检查iptables是否支持-w参数
echo "***  4. 检查iptables是否支持-w参数  ***"
strA="iptables -h"
strB="wait"
result=$(${strA} | grep $strB)
if [ -n "$result" ]
then
    echo "iptables支持-w参数"
else
    echo "iptables可能不支持-w参数，下为详情"
 echo "iptables可能不支持-w参数，请查看运行详情" >> $LOG_FILE
    echo $strA
fi
echo " "
echo "***  5. 检查是否支持ip route命令  ***"
#默认检查是否有用户输入网卡名 是否存在br0或者br-lan，均不存在则提示用户输入
#获取输入参数 -网卡名
if [ -n "$1" ]
then
	#检查是否有参数输入
    netcard=$1
	echo "待检查的外网网卡为"$netcard
else
	#检查br0
	strA="ifconfig"
	strB="br0"
	result=$(${strA} | grep $strB)
	if [ -n "$result" ]
	then
		netcard="br0"
		echo "待检查的外网网卡为"$netcard
	else
		#无br0，检查br-lan
		strB="br-lan"
		result=$(${strA} | grep $strB)
		if [ -n "$result" ]
		then
			netcard="br-lan"
			echo "待检查的外网网卡为"$netcard
		else
			#均不存在则提示用户输入
			#输入网卡名称 等待30秒
			read -t 30 -p "网卡名:" netcard
			if  [ ! -n "$netcard" ] ;then
				echo "未输入!"
				exit
			else
				echo "待检查的外网网卡为"$netcard
			fi
		fi
	fi
fi
#获取信息，检查信息
netcard_info="ifconfig $netcard"
result=$(${netcard_info} | grep "fetching")
if [ -z "$result" ]
then
    echo "网卡$netcard存在"
    #截取ip地址
	netcard_info=$(ifconfig $netcard)
    netcard_info_tmp=${netcard_info#*inet addr:}
    netcard_info_ip=${netcard_info_tmp%% *}
    #echo $netcard_info_ip
    #截取IP前面地址，替换最后一位，从而获取网关地址
    netcard_info_ip_head=${netcard_info_ip%.*}
    netcard_info_gateway=$netcard_info_ip_head".1"
    #echo $netcard_info_gateway
    #检查ip route命令
    cmd="ip route add table 67 default via $netcard_info_gateway dev $netcard"
    check_success
    cmd="ip route show table 67"
    check_success

else
    echo "网卡$netcard不存在"
	echo "网卡$netcard不存在" >> $LOG_FILE
fi
echo " "
#检查ip rule命令
echo "***  6. 检查ip rule命令  ***"
cmd="ip rule add from 192.168.1.2 lookup 67"
check_success
cmd="ip rule"
check_success
echo " "
#检查ipset版本
echo "***  7. 检查ipset版本  ***"
ipset_version=$(ipset -V)
ipset_version_tmp=${ipset_version#*v}
ipset_version_num=${ipset_version_tmp%%,*}
ipset_version_target="6.2.0"
if [ `expr $ipset_version_num \> $ipset_version_target` -eq 0 ];then
    echo "ipset版本为 $ipset_version_num 低于6.2.0"
	echo "ipset版本为 $ipset_version_num 低于6.2.0" >> $LOG_FILE
else
    echo "ipset版本检查完成，版本为$ipset_version_num"
fi
cd /tmp
echo " "
#验证ipset相关
echo "***  8. 检查是否支持ipset  ***"
cmd="ipset create testset hash:net maxelem 200000"
check_success
cmd="ipset add testset 212.129.64.40"
check_success
cmd="ipset add testset 114.114.0.0/16"
check_success
cmd="ipset test testset 212.129.64.40"
check_success
ipset_test_result="ipset test testset 212.129.64.40"
result=$(${ipset_test_result} | grep "testset")
if [ -n "$result" ]
then
    echo "testset错误，请检查"
	echo "testset错误，请查看运行详情" >> $LOG_FILE
    echo $result
else
    echo "testset检查完成"
fi
cmd="iptables -t mangle -A PREROUTING -s 192.168.1.2 -m set --match-set testset dst -j DROP"
check_success
cmd="ipset save testset -f test"
check_success
sed -i "s:testset:testset1:" test
cmd="ipset restore -f test"
check_success
cmd="ipset destroy testset1"
check_success
cmd="ipset list"
check_success
cmd="iptables -t mangle -nvL PREROUTING"
check_success
echo " "
#验证tar相关命令
echo "***  9. 检查是否支持tar解压tar.gz文件  ***"
tar -czvf test.tar.gz test
cmd="tar -zxvf test.tar.gz"
check_success
echo " "
#检查是否支持修改tun的rp_filter字段
echo "***  10. 检查是否支持修改tun的rp_filter字段  ***"
cmd="echo 0 > /proc/sys/net/ipv4/conf/$netcard/rp_filter"
check_success
cmd="cat /proc/sys/net/ipv4/conf/$netcard/rp_filter"
check_success
echo " "
#检查是否支持ip address命令添加静态IP
echo "***  11. 检查是否支持ip address命令添加静态IP  ***"
cmd="ip address add 172.19.66.3/16 dev $netcard"
check_success
cmd="ip address show $netcard"
check_success
echo " "
#检查wget的支持情况
echo "***  12. 检查wget的参数支持情况  ***"
wget -h >& testb_wget.txt
strA="cat testb_wget.txt"
strB="timeout"
result=$(${strA} | grep $strB)
if [ -n "$result" ]
then
    echo "wget支持-T参数"
else
    echo "wget不支持-T参数或未识别到关键字"
	echo "wget不支持-T参数或未识别到关键字，请查看运行详情" >> $LOG_FILE
    wget_flag=1
fi
strB="continue"
wget_flag=0
result=$(${strA} | grep $strB)
if [ -n "$result" ]
then
    echo "wget支持-c参数"
else
    echo "wget不支持-c参数或未识别到关键字"
	echo "wget不支持-c参数或未识别到关键字，请查看运行详情" >> $LOG_FILE
    wget_flag=1
fi
strB="DIR"
result=$(${strA} | grep $strB)
if [ -n "$result" ]
then
    echo "wget支持-P参数"
else
    echo "wget不支持-P参数或未识别到关键字"
	echo "wget不支持-P参数或未识别到关键字，请查看运行详情" >> $LOG_FILE
    wget_flag=1
fi
if [ $wget_flag -eq 1 ]; then
    echo "wget详情"
    echo "$strA"
fi
echo " "
#检查iptables、ip6tables的 option支持情况
echo "***  13. 检查iptables、ip6tables的 option支持情况  ***"
cmd="iptables -t mangle -I PREROUTING -p tcp -m multiport --dports 8801,8802,1719,1720,5061,5062,5063,5064 -j MARK --set-mark 0x6"
iptables -t mangle -I PREROUTING -p tcp -m multiport --dport 8801,8802 -j MARK --set-mark 0x6

check_success
cmd="ip6tables -t nat -I PREROUTING -i br-lan -p udp --dport 53 -j REDIRECT --to-port 53530"
check_success
cmd="ip6tables -t nat -I PREROUTING -p udp --dport 53 -j DNAT --to-destination [fe80::1]:53530"
check_success
--dport 53
cmd="ip6tables -I INPUT -p udp -j REJECT"
check_success
cmd="ip6tables -I FORWARD -p udp --dport 53 -j REJECT"
check_success
#检查ipset 支持bitmap
cmd="ipset create testset1 bitmap:port range 5000-50000"
check_success
echo " "
#检查非易失目录是否存在
echo "***  14. 检查非易失目录是否存在  ***"
if [ -d /tmp/bvasPlug ] ; then
    echo "非易失目录存在"
else
    echo "非易失目录不存在/tmp/bvasPlug下，请核对"
	echo "非易失目录不存在/tmp/bvasPlug下，请核对" >> $LOG_FILE
fi
echo " "
#检查系统时间
echo "***  15. 检查系统时间  ***"
strA="date -R"
strB="+0800"
result=$(${strA} | grep $strB)
strA=$(date -R)
if [ -n "$result" ]
then
    echo "当前时区为东八区"
	echo "当前系统时间为： $strA 请核对是否和当前北京时间一致"
	echo "当前系统时间为： $strA 请核对是否和当前北京时间一致" >> $LOG_FILE
else
    echo "当前时区不是东八区"
	echo "当前系统时间为： $strA" >> $LOG_FILE
	echo "当前时区不是东八区" >> $LOG_FILE
fi
echo " "
echo " "
echo "二、 检查绿色上网"
#验证绿色上网管控
#iptables/ip6tables集成string、mac、time、set模块
echo "***  16. 检查iptables/ip6tables集成string、mac、time、set模块，time模块支持—kerneltz参数  ***"
#iptables/ip6tables集成string模块
echo "--- (1)检查iptables/ip6tables集成string模块 ---"
#管控百度首页（www.baidu.com）
echo "a) 管控百度首页（www.baidu.com）"
cmd="iptables -I FORWARD -m string --string ‘baidu.com’ --algo kmp -j DROP"
check_success
cmd="ip6tables -I FORWARD -m string --string ‘baidu.com’ --algo kmp -j DROP"
check_success
#管控新浪首页（www.sina.com.cn）
echo "b) 管控新浪首页（www.sina.com.cn）"
cmd="iptables -I FORWARD -m string --hex-string ‘|73696e612e636f6d|’ --algo bm -j DROP"
check_success
cmd="ip6tables -I FORWARD -m string --hex-string ‘|73696e612e636f6d|’ --algo bm -j DROP"
check_success
#iptables/ip6tables集成mac模块
echo "--- (2)iptables/ip6tables集成mac模块 ---"
cmd="iptables -I FORWARD -m mac --mac-source 00:01:02:AA:BB:CC -j DROP"
check_success
cmd="ip6tables -I FORWARD -m mac --mac-source 00:01:02:AA:BB:CC -j DROP"
check_success
#iptables/ip6tables集成time模块
#echo "--- (3)iptables/ip6tables集成time模块 ---"
#cmd="iptables -I FORWARD -m mac --mac-source 00:01:02:AA:BB:CC -m time --timestart 16:00:00 --timestop 16:59:59 --weekdays Mon,Tus,Wed,Thu,Fri --kerneltz -j DROP"
#check_success
#cmd="ip6tables -I FORWARD -m mac --mac-source 00:01:02:AA:BB:CC -m time --timestart 16:00:00 --timestop 16:59:59 --weekdays Mon,Tus,Wed,Thu,Fri --kerneltz -j DROP"
#check_success
#iptables/ip6tables集成set模块
echo "--- (4)iptables/ip6tables集成set模块 ---"
#ipset基础命令:
echo "a) ipset基础命令"
cmd="ipset create self_control hash:net"
check_success
cmd="ipset create blacklist hash:net maxelem 1000000"
check_success
cmd="ipset list"
check_success
#ipset支持白名单:
echo "b) ipset支持白名单"
cmd="iptables -N white_list"
check_success
cmd="iptables -I FORWARD -j white_list"
check_success
cmd="ipset create whitelist hash:net maxelem 1000000"
check_success
cmd="ipset add whitelist 36.152.44.90"
check_success
cmd="ipset add whitelist 36.152.44.91"
check_success
cmd="ipset add whitelist 36.152.44.95"
check_success
cmd="ipset add whitelist 36.152.44.96"
check_success
cmd="iptables -I white_list -i br0 -m mac --mac-source BC:4C:C4:99:1D:62 -p tcp -m set --match-set whitelist dst -j ACCEPT"
check_success
cmd="iptables -A white_list -i br0 -m mac --mac-source BC:4C:C4:99:1D:62 -p tcp -j DROP"
check_success
#ipset支持黑名单:
echo "c) ipset支持黑名单"
cmd="iptables -N self_control"
check_success
cmd="iptables -I FORWARD -j self_control"
check_success
cmd="ipset create white_list hash:ip,port maxelem 1000000"
check_success
cmd="ipset add white_list 36.152.44.90,443"
check_success
cmd="ipset add white_list 36.152.44.91,443"
check_success
cmd="ipset add white_list 36.152.44.95,443"
check_success
cmd="ipset add white_list 36.152.44.96,443"
check_success
cmd="iptables -I self_control -m set --match-set white_list src -j DROP"
check_success
cmd="iptables -I self_control -m set --match-set white_list dst -j DROP"
check_success
cmd="iptables -A self_control -p udp -m mac --mac-source 5C:C5:D4:A5:A2:EE -j DROP"
check_success
echo " "
#检查基础命令支持情况
echo "***  17. 基础命令支持情况检查  ***"
echo "--- (1)awk相关支持 ---"
cmd="ipset create test_1 hash:net maxelem 1000000"
check_success
cmd="ipset create test_2 hash:net maxelem 1000000"
check_success
#检查test_1和test_2是否创建成功
AA="ipset list"
strA="ipset list"
strB="test_1"
check_in
strB="test_2"
check_in
cmd="iptables -I self_control -i br0 -p tcp -m set --match-set test_1 dst -j DROP"
check_success
cmd="iptables -I self_control -i br0 -p tcp -m set --match-set test_2 dst -j DROP"
check_success
#检查是否存在
AA="self_control"
strA="iptables -nvL self_control"
strB="test_1"
check_in
strB="test_2"
check_in
#检查awk支持
cmd_hint="awk相关"
iptables -vnL self_control --line | grep "test" | awk '{print $1}' | awk '{sum=sum" "$1} END{print sum}' | awk '{for(i=0;i<=NF-1;i++){tmp="echo "$(NF-i);system(tmp)}}' | awk '{cmd="iptables -D self_control "$1;system(cmd)}'
check_success_no_cmd
#检查awk内执行是否成功
strA="iptables -nvL self_control"
strB="test_1"
check_not_in
strB="test_2"
check_not_in
ipset list | grep "test_" | awk -F': ' '{cmd="ipset destroy "$2;system(cmd)}'
check_success_no_cmd
#检查awk内是否执行成功
AA="ipset list"
strA="ipset list"
strB="test_1"
check_not_in
strB="test_2"
check_not_in
#路由器集成bridge netfilter内核模块，且初始值为0
echo "***  18. 路由器集成bridge netfilter内核模块，且初始值为0  ***"
cmd="cat /proc/sys/net/bridge/bridge-nf-call-iptables"
check_success
cmd="cat /proc/sys/net/bridge/bridge-nf-call-ip6tables"
check_success
cmd="echo 1 > /proc/sys/net/bridge/bridge-nf-call-iptables"
check_success
cmd="echo 1 > /proc/sys/net/bridge/bridge-nf-call-ip6tables"
check_success
