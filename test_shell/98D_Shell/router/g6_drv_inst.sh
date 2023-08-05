#!/bin/sh

rtl8852ae_drv_cfg()
{
        drv_cfg_file=/proc/net/rtl8852ae/drv_cfg
        key=$1

        value=$(grep $key $drv_cfg_file)
        if [ "$value" == "" ]; then
                value=0
        else
                value=$(echo $value | sed "s/${key}\ *=\ *//")
        fi

        echo $value
}

if [ -f /etc/conf/8852ae_98d.ko ]; then
#        modprobe rg
        insmod /etc/conf/8852ae_98d.ko \
        	rtw_phy_file_path=/etc/conf/ \
        	rtw_ht_enable=2 \
        	rtw_vht_enable=2 \
        	rtw_he_enable=2 \
        	rtw_drv_log_level=2 \
        	

        if [ -f /proc/net/rtl8852ae/drv_cfg ]; then
        	echo "Getting parameters from driver's configuration..."
        	persist_if=$(rtl8852ae_drv_cfg CONFIG_RTW_PERSIST_IF)
        	client_mode=$(rtl8852ae_drv_cfg CONFIG_RTW_CLIENT_MODE_SUPPORT)
        	if_num=$(rtl8852ae_drv_cfg CONFIG_IFACE_NUMBER)
        else
        	echo "Use default values"
        	persist_if=0
        	client_mode=0
        	if_num=1
        fi

	vap_start_num=0
	vap_suffix=-vap
	client_suffix=-vxd

       	ap_num=$(expr ${if_num} - ${client_mode})
        vap_num=$(expr ${ap_num} - 1)

        #echo "persist_if = ${persist_if}"
        #echo "client_mode = ${client_mode}"
        #echo "ap_num = ${ap_num}"
        #echo "vap_num = ${vap_num}"

        if [ $persist_if -ne 0 -a $vap_num -gt 0 ]; then
        	echo Driver support dwelling interface and VAP

                wlan_mac=$(flash get WLAN_MAC_ADDR | sed 's/.*=//')
                wlan_mac_d=$( printf '%d' 0x$wlan_mac )

                wlan_if_list=$(cd /proc/net/rtl8852ae; find -type d -maxdepth 1 | sed -e s@[./]@@g )

		for w_if in $wlan_if_list; do
                       	vap_idx=${vap_start_num}
                       	echo "Creating $vap_num VAP(s) of $w_if ..."
                       	while [ $vap_idx -lt $vap_num ]; do
                       		vap_if=${w_if}${vap_suffix}${vap_idx}
                               	iw $w_if interface add $vap_if type managed && \
                               	wlan_mac_d=$( expr $wlan_mac_d + 1 )
                               	wlan_mac_h=$( printf '%012X' $wlan_mac_d )
                               	ifconfig $vap_if hw ether $wlan_mac_h
                               	echo $vap_if = $wlan_mac_h
                               	vap_idx=`expr $vap_idx + 1`
                        done
                        if [ $client_mode -ne 0 ]; then
                        	client_if=${w_if}${client_suffix}
                               	iw $w_if interface add $client_if type managed && \
                               	wlan_mac_d=$( expr $wlan_mac_d + 1 )
                               	wlan_mac_h=$( printf '%012X' $wlan_mac_d )
                               	ifconfig $client_if hw ether $wlan_mac_h
                               	echo $client_if = $wlan_mac_h
                        fi
                done
        else
        	echo "Driver support ${vap_num} AP interface(s) but not persist"
        fi
fi

