#!/bin/sh -x
debug="n"

initialize()
{
	close_tunFY=0
	close_tun1000=0

    ifconfig|grep HWaddr|grep -v tun|awk '{print $1}' | xargs -I {} ip a show dev {} |grep -w inet|awk '{print $2}'|awk -F '/' '{print $1" "$2}'  > /tmp/up_ip.txt
    lines=$(cat /tmp/up_ip.txt | wc -l)
    echo "Line: $lines"

	ip_tunFY=`ifconfig tunFY|sed -n 's/^.*inet[[:space:]]addr://p' | sed -e 's/[[:space:]].*//'`
	mask_len_tunFY=`ip addr show tunFY|grep -w inet|awk '{print $2}'|awk -F '/' '{print $2}'`

	ip_tunFY=`ifconfig tun1000|sed -n 's/^.*inet[[:space:]]addr://p' | sed -e 's/[[:space:]].*//'`
	mask_len_tunFY=`ip addr show tun1000|grep -w inet|awk '{print $2}'|awk -F '/' '{print $2}'`
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
		mask_length=$1
	else
		mask_length=$2
	else

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

cal_interface_disable()
{
	while [ "$lines" -ge 1 ]; do
		echo "Line: $lines"
		ip_tmp=`sed -n "${lines}p" /tmp/up_ip.txt | awk '{print $1}'`
		mask_len_tmp=`sed -n "${lines}p" /tmp/up_ip.txt | awk '{print $2}'`

		if [ ! -z $ip_tmp ];then
			if [ ! -z $ip_tunFY ];then
				close_tunFY=$(cal_same_network "$ip_tmp" "$mask_len_tmp" "$ip_tunFY" "$mask_len_tunFY")
			fi

			if [ ! -z $ip_tun1000 ];then
				close_tun1000=$(cal_same_network "$ip_tmp" "$mask_len_tmp" "$ip_tun1000" "$mask_len_tun1000")
			fi
		fi
		lines=$(($lines-1))
	done
}

echo_var()
{
	echo "------------------------------"
	echo "ip_tunFY = $ip_tunFY"
	echo "ip_tun1000 = $ip_tun1000"
	echo "------------------------------"
	echo "mask_len_tunFY = $mask_len_tunFY"
	echo "mask_len_tun1000 = $mask_len_tun1000"
	echo "------------------------------"
}

handle_tun_tx()
{
	if [ ! -z $ip_tunFY ] && [ $close_tunFY = 0 ];then
		ifconfig tunFY down
	fi
}

handle_tun_1000()
{
	if [ ! -z $ip_tun1000 ] && [ $close_tun1000 = 0 ];then
		ifconfig tun1000 down
	fi
}

main()
{
	initialize
	cal_interface_disable

	if [ $debug = "y" ];then
		echo_var
	fi
	handle_tun_tx
	handle_tun_1000
}

main