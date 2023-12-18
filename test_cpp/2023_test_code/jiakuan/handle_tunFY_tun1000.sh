#!/bin/sh
set -x

debug="y"

check_bvas_running()
{
	pid=`ps | grep 'bvasPlugin' | grep -v grep | awk -F' ' '{print $1}'`
	# pid="1"
	if [ "$pid" !=  "" ];then
		if [ $debug = "y" ];then
			echo "target pid is exist "$pid""
		fi
		return 0
	else
		if [ $debug = "y" ];then
			echo "target pid is not exist"
		fi
		return 1
	fi
}

initialization()
{
	close_tunFY=0
	close_tun1000=0

	ifconfig|grep HWaddr|grep -v tun|awk '{print $1}' | xargs -I {} ip a show dev {} |grep -w inet|awk '{print $2}'|awk -F '/' '{print $1" "$2}'  > /tmp/up_ip.txt
	lines=$(cat /tmp/up_ip.txt | wc -l)

	tunFY_ip=`ifconfig tunFY|sed -n 's/^.*inet[[:space:]]addr://p' | sed -e 's/[[:space:]].*//'`
	tunFY_mask_len=`ip addr show tunFY|grep -w inet|awk '{print $2}'|awk -F '/' '{print $2}'`

	tun1000_ip=`ifconfig tun1000|sed -n 's/^.*inet[[:space:]]addr://p' | sed -e 's/[[:space:]].*//'`
	tun1000_mask_len=`ip addr show tun1000|grep -w inet|awk '{print $2}'|awk -F '/' '{print $2}'`

	if [ $debug = "y" ];then
		echo "---------------"
		echo "tunFY_ip = $tunFY_ip"
		echo "tunFY_mask_len = $tunFY_mask_len"
		echo "---------------"
		echo "tun1000_ip = $tun1000_ip"
		echo "tun1000_mask_len = $tun1000_mask_len"
		echo "---------------"
	fi
}

#ip和掩码做与计算。如果结果相同，则证明两个ip在同一个网段
calc_ip_net()
{
	local sip="$1"
	local snetmask="$2"

	local ip_filed_1=$(echo "$sip" |cut -d. -f1)
	local ip_filed_2=$(echo "$sip" |cut -d. -f2)
	local ip_filed_3=$(echo "$sip" |cut -d. -f3)
	local ip_filed_4=$(echo "$sip" |cut -d. -f4)

	local netmask_filed_1=$(echo "$snetmask" |cut -d. -f1)
	local netmask_filed_2=$(echo "$snetmask" |cut -d. -f2)
	local netmask_filed_3=$(echo "$snetmask" |cut -d. -f3)
	local netmask_filed_4=$(echo "$snetmask" |cut -d. -f4)

	local tmpret1=$(($ip_filed_1&$netmask_filed_1))
	local tmpret2=$(($ip_filed_2&$netmask_filed_2))
	local tmpret3=$(($ip_filed_3&$netmask_filed_3))
	local tmpret4=$(($ip_filed_4&$netmask_filed_4))

	echo "$tmpret1.$tmpret2.$tmpret3.$tmpret4"
}

cal_wide_range_mask()
{
	if [ $1 < $2 ]; then
		local mask_length=$1
	else
		local mask_length=$2
	fi

	local mask=""
	i=1
	while [ "$i" -le 4 ]; do
		if [ $mask_length -ge 8 ]; then
			mask=${mask}"255."
			mask_length=$((mask_length-8))
		else
			num=$((256 - 2**(8-mask_length)))
			mask=${mask}"$num."
			mask_length=0
		fi
		i=$(($i+1))
	done
	mask=${mask%?}
	echo $mask
}

cal_same_network()
{
	local sip1="$1"
	local mask_len1="$2"
	local sip2="$3"
	local mask_len2="$4"

	local netmask=$(cal_wide_range_mask "$mask_len1" "$mask_len2")

	local tmp_sip1=$(calc_ip_net "$sip1" "$netmask")
	local tmp_sip2=$(calc_ip_net "$sip2" "$netmask")

	if [ $tmp_sip1 = $tmp_sip2 ];then
		echo 0
	else
		echo 1
	fi
}

cal_if_interface_disable()
{
	while [ "$lines" -ge 1 ]; do
		echo "Line: $lines"
		local tmp_ip=`sed -n "${lines}p" /tmp/up_ip.txt | awk '{print $1}'`
		local tmp_mask_len=`sed -n "${lines}p" /tmp/up_ip.txt | awk '{print $2}'`

		if [ $debug = "y" ];then
			echo "---------------"
			echo "tmp_ip = $tmp_ip"
			echo "tmp_mask_len = $tmp_mask_len"
			echo "---------------"
		fi

		if [ ! -z $tmp_ip ];then
			#tunFY
			if [ ! -z $tunFY_ip ];then
				close_tunFY=$(cal_same_network "$ip_tmp" "$mask_len_tmp" "$ip_tunFY" "$mask_len_tunFY")
			fi

			#tun1000
			if [ ! -z $tun1000_ip ];then
				close_tun1000=$(cal_same_network "$ip_tmp" "$mask_len_tmp" "$ip_tun1000" "$mask_len_tun1000")
			fi
		fi
		lines=$(($lines-1))
	done
}

check_interface()
{
	initialization
	cal_if_interface_disable
	handle_interface
}

handle_interface()
{
	if [ ! -z $tunFY_ip ] && [ $close_tunFY -eq 0 ];then
		ifconfig tunFY down
	fi

	if [ ! -z $tun1000_ip ] && [ $close_tun1000 -eq 0 ];then
		ifconfig tun1000 down
	fi
}

while :
do
	check_bvas_running
	if [ "$?" = "1" ];then
		sleep 60
	else
		check_interface
		sleep 10
	fi
done
