#!/bin/sh +x

debug="n"

#ip和掩码做与计算。如果结果相同，则证明两个ip在同一个网段
calc_ip_net()
{
	local sip="$1"
	local snetmask="$2"

	local ipFIELD1=$(echo "$sip" |cut -d. -f1)
	local ipFIELD2=$(echo "$sip" |cut -d. -f2)
	local ipFIELD3=$(echo "$sip" |cut -d. -f3)
	local ipFIELD4=$(echo "$sip" |cut -d. -f4)

	local netmaskFIELD1=$(echo "$snetmask" |cut -d. -f1)
	local netmaskFIELD2=$(echo "$snetmask" |cut -d. -f2)
	local netmaskFIELD3=$(echo "$snetmask" |cut -d. -f3)
	local netmaskFIELD4=$(echo "$snetmask" |cut -d. -f4)

	local tmpret1=$(($ipFIELD1&$netmaskFIELD1))
	local tmpret2=$(($ipFIELD2&$netmaskFIELD2))
	local tmpret3=$(($ipFIELD3&$netmaskFIELD3))
	local tmpret4=$(($ipFIELD4&$netmaskFIELD4))

	echo "$tmpret1.$tmpret2.$tmpret3.$tmpret4"
}

release_init()
{
	if_nas0=`ifconfig nas0`
	if_br=`ifconfig br0`
	if_br_0=`ifconfig br0:0`
	if_ppp0=`ifconfig ppp0`
	if_tun_tx=`ifconfig tunTX`
	if_tun_1000=`ifconfig tun1000`

	mask_nas0=`echo $if_nas0| sed -n 's/.*Mask://p' | sed -e 's/[[:space:]].*//'`
	mask_br=`echo $if_br| sed -n 's/.*Mask://p' | sed -e 's/[[:space:]].*//'`
	mask_br_0=`echo $if_br_0| sed -n 's/.*Mask://p' | sed -e 's/[[:space:]].*//'`
	mask_ppp0=`echo $if_ppp0| sed -n 's/.*Mask://p' | sed -e 's/[[:space:]].*//'`
	mask_tun_tx=`echo $if_tun_tx| sed -n 's/.*Mask://p' | sed -e 's/[[:space:]].*//'`
	mask_tun_1000=`echo $if_tun_1000| sed -n 's/.*Mask://p' | sed -e 's/[[:space:]].*//'`

	ip_nas0=`echo $if_nas0|sed -n '1s/^.*inet[[:space:]]addr://p' | sed -e 's/[[:space:]].*//'`
	ip_br=`echo $if_br|sed -n '1s/^.*inet[[:space:]]addr://p' | sed -e 's/[[:space:]].*//'`
	ip_br_0=`echo $if_br_0|sed -n '1s/^.*inet[[:space:]]addr://p' | sed -e 's/[[:space:]].*//'`
	ip_ppp0=`echo $if_ppp0|sed -n '1s/^.*inet[[:space:]]addr://p' | sed -e 's/[[:space:]].*//'`
	ip_tun_tx=`echo $if_tun_tx|sed -n '1s/^.*inet[[:space:]]addr://p' | sed -e 's/[[:space:]].*//'`
	ip_tun_1000=`echo $if_tun_1000|sed -n '1s/^.*inet[[:space:]]addr://p' | sed -e 's/[[:space:]].*//'`

	# bvas_pid=$(ps | grep bvasPlugin | grep -v grep | grep -v monit| awk '{print $1}')
}

debug_init()
{
	mask_nas0=255.255.255.0
	mask_br=255.255.255.0
	mask_br_0=255.255.255.0
	mask_ppp0=255.255.0.0
	mask_tun_tx=255.255.0.0
	mask_tun_1000=255.255.255.0

	ip_nas0=192.168.1.0
	ip_br=192.168.1.0
	ip_br_0=192.168.2.0
	ip_ppp0=192.168.2.0
	ip_tun_tx=192.168.1.0
	ip_tun_1000=192.168.1.0

	# bvas_pid=1101
}

cal_mask_digits()
{
	local digit=0
	local tmpmask=$(echo "$1" | awk -F "." '{print $1" "$2" "$3" "$4}')
	for num in $tmpmask;do
		while [ $num != 0 ];do
			num=$(($num/2));
			digit=$(($digit+1))
		done
	done
	echo $digit
}

cal_same_network()
{
	local sip1="$1"
	local netmask1="$2"
	local sip2="$3"
	local netmask2="$4"

	local netmask_len1=$(cal_mask_digits "$netmask1")
	local netmask_len2=$(cal_mask_digits "$netmask2")

	if [ $netmask_len1 -le $netmask_len2 ];then
		local tmp_sip1=$(calc_ip_net "$sip1" "$netmask1")
		local tmp_sip2=$(calc_ip_net "$sip2" "$netmask1")
	else
		local tmp_sip1=$(calc_ip_net "$sip1" "$netmask_len2")
		local tmp_sip2=$(calc_ip_net "$sip2" "$netmask_len2")
	fi

	if [ $tmp_sip1 = $tmp_sip2 ];then
		echo 0
	else
		echo 1
	fi
}

cal_tmp_val()
{
	tmp_nas0_tx=$(cal_same_network "$ip_nas0" "$mask_nas0" "$ip_tun_tx" "$mask_tun_tx")
	tmp_br_tx=$(cal_same_network "$ip_br" "$mask_br" "$ip_tun_tx" "$mask_tun_tx")
	tmp_br_0_tx=$(cal_same_network "$ip_br_0" "$mask_br_0" "$ip_tun_tx" "$mask_tun_tx")
	tmp_ppp0_tx=$(cal_same_network "$ip_ppp0" "$mask_ppp0" "$ip_tun_tx" "$mask_tun_tx")

	tmp_nas0_1000=$(cal_same_network "$ip_nas0" "$mask_nas0" "$ip_tun_1000" "$mask_tun_1000")
	tmp_br_1000=$(cal_same_network "$ip_br" "$mask_br" "$ip_tun_1000" "$mask_tun_1000")
	tmp_br_0_1000=$(cal_same_network "$ip_br_0" "$mask_br_0" "$ip_tun_1000" "$mask_tun_1000")
	tmp_ppp0_1000=$(cal_same_network "$ip_ppp0" "$mask_ppp0" "$ip_tun_1000" "$mask_tun_1000")
}

echo_var()
{
	echo "------------------------------"
	echo "mask_nas0 = $mask_nas0"
	echo "mask_br = $mask_br"
	echo "mask_br_0 = $mask_br_0"
	echo "mask_ppp0 = $mask_ppp0"
	echo "mask_tun_tx = $mask_tun_tx"
	echo "mask_tun_1000 = $mask_tun_1000"
	echo "------------------------------"
	echo "ip_nas0 = $ip_nas0"
	echo "ip_br = $ip_br"
	echo "ip_br_0 = $ip_br_0"
	echo "ip_ppp0 = $ip_ppp0"
	echo "ip_tun_tx = $ip_tun_tx"
	echo "ip_tun_1000 = $ip_tun_1000"
	echo "------------------------------"
	echo "tmp_nas0_tx = $tmp_nas0_tx"
	echo "tmp_br_tx = $tmp_br_tx"
	echo "tmp_br_0_tx = $tmp_br_0_tx"
	echo "tmp_ppp0_tx = $tmp_ppp0_tx"
	echo "------------------------------"
	echo "tmp_nas0_1000 = $tmp_nas0_1000"
	echo "tmp_br_1000 = $tmp_br_1000"
	echo "tmp_br_0_1000 = $tmp_br_0_1000"
	echo "tmp_ppp0_1000 = $tmp_ppp0_1000"
	echo "------------------------------"
	# echo "bvas_pid = $bvas_pid"
}

# choose time to close tunTX or tun1000
tun_tx()
{
	if [ $debug = "y" ];then
		local exist="tun_tx"
	else
		local exist=`ifconfig|grep tunTX|awk '{print $1}'`
	fi

	if [ $debug = "y" ];then
		echo "is tunTX exist = $exist"
	fi

	if [ ! -z $exist ];then
		if [ ! -z $ip_tun_tx ];then
			if [ $tmp_nas0_tx = 0 ] || [ $tmp_br_tx = 0 ] || [ $tmp_br_0_tx = 0 ]|| [ $tmp_ppp0_tx = 0 ];then
				if [ $debug = "y" ];then
					echo "ifconfig tunTX down"
				else
					ifconfig tunTX down
				fi
			fi
		fi
	fi
}

tun_1000()
{
	if [ $debug = "y" ];then
		local exist="tun_1000"
	else
		local exist=`ifconfig|grep tun1000|awk '{print $1}'`
	fi

	if [ $debug = "y" ];then
		echo "is tun1000 exist = $exist"
	fi

	if [ ! -z $exist ];then
		if [ ! -z $ip_tun_1000 ];then
			if [ $tmp_nas0_1000 = 0 ] || [ $tmp_br_1000 = 0 ] || [ $tmp_br_0_1000 = 0 ] || [ $tmp_ppp0_1000 = 0 ];then
				if [ $debug = "y" ];then
					echo "ifconfig tun1000 down"
				else
					ifconfig tun1000 down
				fi
			fi
		fi
	fi
}

bvas_alive()
{
	if [ ! -z $bvas_pid ];then
		return 1
	else
		return 0
	fi
}

main()
{
	if [ $debug = "y" ];then
		debug_init
	else
		release_init
	fi

	cal_tmp_val

	if [ $debug = "y" ];then
		echo_var
	fi

	tun_tx
	tun_1000
}

main