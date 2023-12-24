#!/bin/sh
set -x

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
	local mask_length=0
	if [ $1 -le $2 ]; then
		mask_length=$1
	else
		mask_length=$2
	fi

	local mask=""
	local i=1
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

sip1="$1"
mask_len1="$2"
sip2="$3"
mask_len2="$4"

netmask=`cal_wide_range_mask "$mask_len1" "$mask_len2"`

tmp_sip1=`calc_ip_net "$sip1" "$netmask"`
tmp_sip2=`calc_ip_net "$sip2" "$netmask"`

if [ $tmp_sip1 = $tmp_sip2 ];then
	echo 1
else
	echo 0
fi
