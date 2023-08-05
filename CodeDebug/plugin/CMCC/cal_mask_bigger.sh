#!/bin/sh +x
mask_br_0=255.255.255.0
mask_ppp0=255.255.0.0
mask_test=255.0.0.0
mask_test1=128.0.0.0

cal_mask_digits()
{
	local digit=0
	local tmpmask=$(echo "$1" | awk -F "." '{print $1" "$2" "$3" "$4}')
	for num in $tmpmask; do
		while [ $num != 0 ];do
			num=$(($num/2));
			digit=$(($digit+1))
		done
	done
	return $digit
}

cal_which_mask_bigger()
{
	# echo "$1"
	# echo "$2"

	local mask1_field1=$(echo "$1" | awk -F "." '{print $1}')
	local mask1_field2=$(echo "$1" | awk -F "." '{print $2}')
	local mask1_field3=$(echo "$1" | awk -F "." '{print $3}')
	local mask1_field4=$(echo "$1" | awk -F "." '{print $4}')

	local mask2_field1=$(echo "$2" | awk -F "." '{print $1}')
	local mask2_field2=$(echo "$2" | awk -F "." '{print $2}')
	local mask2_field3=$(echo "$2" | awk -F "." '{print $3}')
	local mask2_field4=$(echo "$2" | awk -F "." '{print $4}')

	if [ $mask1_field1 < $mask2_field1 ]; then
		echo "$1"
	elif [ $mask1_field1 > $mask2_field1 ]; then
		echo "$2"
	else
		if [ $mask1_field2 < $mask2_field2 ]; then
			echo "$1"
		elif [ $mask1_field2 > $mask2_field2 ]; then
			echo "$2"
		else
			if [ $mask1_field3 < $mask2_field3 ]; then
				echo "$1"
			elif [ $mask1_field3 > $mask2_field3 ]; then
				echo "$2"
			else
				if [ $mask1_field4 < $mask2_field4 ]; then
					echo "$1"
				elif [ $mask1_field4 > $mask2_field4 ]; then
					echo "$2"
				else
					echo "$1"
				fi
			fi
		fi
	fi
}

cal_wide_range_mask()
{
	local mask1_field1=$(echo "$1" | awk -F "." '{print $1}')
	local mask1_field2=$(echo "$1" | awk -F "." '{print $2}')
	local mask1_field3=$(echo "$1" | awk -F "." '{print $3}')
	local mask1_field4=$(echo "$1" | awk -F "." '{print $4}')

	local mask2_field1=$(echo "$2" | awk -F "." '{print $1}')
	local mask2_field2=$(echo "$2" | awk -F "." '{print $2}')
	local mask2_field3=$(echo "$2" | awk -F "." '{print $3}')
	local mask2_field4=$(echo "$2" | awk -F "." '{print $4}')

	tmp1=$(($mask1_field1<<24+$mask1_field2<<16+$mask1_field3<<8+$mask1_field4))
	tmp2=$(($mask2_field1<<24+$mask2_field2<<16+$mask2_field3<<8+$mask2_field4))
	echo $tmp1
	echo $tmp2

	tmp3=$(($mask1_field1*256*256*256+$mask1_field2*256*256+$mask1_field3*256+$mask1_field4))
	tmp4=$(($mask2_field1*256*256*256+$mask2_field2*256*256+$mask2_field3*256+$mask2_field4))
	echo $tmp3
	echo $tmp4

	if [ $tmp1 < $tmp2 ]; then
		echo "$1"
	elif [ $tmp1 > $tmp2 ]; then
		echo "$2"
	else
		echo "$1"
	fi
}

# cal_mask_digits $mask_br_0
# echo $?

# cal_mask_digits $mask_ppp0
# echo $?

# cal_mask_digits $mask_test
# echo $?

# cal_mask_digits $mask_test1
# echo $?

# cal_which_mask_bigger $mask_test $mask_test1

cal_wide_range_mask $mask_test $mask_test1