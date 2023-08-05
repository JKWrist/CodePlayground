#!bin/sh
i=0
flash get_wlband_num
num=$?
while [ "$i" != "$num" ]
do
        sta_file=/proc/net/rtl8852ae/wlan$i
        if [ -d "$sta_file" ]; then
                ln -snf $sta_file /var/wlan$i
		if [ "$i" == "0" ]; then
			mib set WLAN_MBSSIB_TBL.0.is_ax_support 1
			mib commit cs
		else
			mib set WLAN1_MBSSIB_TBL.0.is_ax_support 1
			mib commit cs
		fi
        fi

        sta2_file=/proc/wlan$i
        if [ -d "$sta2_file" ]; then
                ln -snf $sta2_file /var/wlan$i
		if [ "$i" == "0" ]; then
			mib set WLAN_MBSSIB_TBL.0.is_ax_support 0
			mib commit cs
		else
			mib set WLAN1_MBSSIB_TBL.0.is_ax_support 0
			mib commit cs
		fi
        fi
	i=$(($i+1))
done

