debug='y'

if [ $debug == 'n' ];then
	Pronv=`flash get RTL_LINK_AREA`
	if [ ! -z $Pronv ];then
		str=`sed -n 's#.*pronvCode\":\"##p' /var/app/cmcc_netplug/plugin.conf | sed -n 's#\".*##p'`
		if [ ! -z $str ];then
			flash set RTL_LINK_AREA $str
		fi
	fi
else
	# cd /var/app/cmcc_netplug/
	str=`sed -n 's#.*pronvCode\":\"##p' plugin.conf | sed -n 's#\".*##p'`
	echo $str
	# cd -
fi
