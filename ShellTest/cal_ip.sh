#!/bin/bash
  
IPPattern='^(\<([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\>\.){3}\<([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\>$'

function check_ip_valide()
{
	 IP="$1"
	 for special_ip in ${special_ips[@]}
	 do
			local ret=$(echo $IP | grep ${special_ip})
			if [ -n "$ret" ];then
				 return 1
			fi
	 done
	 if [[ "${IP}" =~ ${IPPattern} ]]; then
		  return 0
	 else
		  return 1
	 fi

}
function calc_ip_net()
{
	sip="$1"
	snetmask="$2"

	check_ip_valide "$sip"
	if [ $? -ne 0 ];then echo "";return 1;fi

	local ipFIELD1=$(echo "$sip" |cut -d. -f1)
	local ipFIELD2=$(echo "$sip" |cut -d. -f2)
	local ipFIELD3=$(echo "$sip" |cut -d. -f3)
	local ipFIELD4=$(echo "$sip" |cut -d. -f4)
			
	local netmaskFIELD1=$(echo "$snetmask" |cut -d. -f1)
	local netmaskFIELD2=$(echo "$snetmask" |cut -d. -f2)
	local netmaskFIELD3=$(echo "$snetmask" |cut -d. -f3)
	local netmaskFIELD4=$(echo "$snetmask" |cut -d. -f4)

	local tmpret1=$[$ipFIELD1&$netmaskFIELD1]
	local tmpret2=$[$ipFIELD2&$netmaskFIELD2]
	local tmpret3=$[$ipFIELD3&$netmaskFIELD3]
	local tmpret4=$[$ipFIELD4&$netmaskFIELD4]
	 
	echo "$tmpret1.$tmpret2.$tmpret3.$tmpret4"
}	
tmpip1=$(calc_ip_net "$1" "$3")
tmpip2=$(calc_ip_net "$2" "$3")

if [ "$tmpip1" != "$tmpip2" ];then
  echo "no"
else
  echo "same"
fi
