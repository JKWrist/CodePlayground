debug='n'
file=/var/app/cmcc_netplug/plugin.conf

if [ $debug == 'n' ];then
	Pronv=`flash get RTL_LINK_AREA`
	str=`sed -n 's#.*pronvCode\":\"##p' $file | sed -n 's#\".*##p'`
	if [ ! -z $str ] && [ -z $Pronv ];then
		flash set RTL_LINK_AREA $str
	fi
else
	str=`sed -n 's#.*pronvCode\":\"##p' $file | sed -n 's#\".*##p'`
	echo "-------- received if6_pronvCode ------"
	echo $str
	echo "-------- if6_pronvCode end ------"
fi
