#! /bin/sh
start_sh_name=start.sh
manage_name=managePlugin
daemon_name=pluginDaemon
dpiPlugin_name=dpiPlugin

vasdocker_monitor_name=vasdocker_monitor
vasdocker_name=vasdocker
bvas_monitor_name=bvasPlugin_monitor
bvas_name=bvasPlugin

kill_process()
{
	pid=$(ps | grep "$1" | grep -v grep | awk -F' ' '{print $1}')
	if [ "$pid" != "" ]; then
		echo "$1 pid is exist $pid"
		kill -9 "$pid"
	fi
}

kill_start_sh()
{
	killall $start_sh_name
}

kill_pluginDaemon()
{
	#pluginDaemon
	kill_process $daemon_name

	#vasdocker_monitor
	kill_process $vasdocker_monitor_name

	#vasdocker
	kill_process $vasdocker_name

	#dpiPlugin
	kill_process $dpiPlugin_name
}

kill_managePlugin()
{
	kill_process $manage_name
}

kill_bvas_plugin()
{
	#bvasPlugin_monitor
	kill_process $bvas_monitor_name

	#bvasPlugin
	kill_process $bvas_name
}

kill_ubus_process()
{
	#ubus
	kill_process ubus

	#ahsapd
	kill_process ahsapd

	#ahsapd_logsrv
	kill_process ahsapd_logsrv
}

drop_caches()
{
	echo 3 > /proc/sys/vm/drop_caches
}

echo "-------------- start ./stop.sh --------------"
case "$1" in
all)
	kill_start_sh
	kill_pluginDaemon
	kill_managePlugin
	kill_bvas_plugin
	kill_ubus_process
    ;;
aos)
	kill_start_sh
	kill_pluginDaemon
	kill_managePlugin
    ;;
bvas)
	kill_start_sh
	kill_pluginDaemon
	kill_bvas_plugin
    ;;
kill_aos_and_update_image)
	kill_start_sh
	kill_pluginDaemon
	kill_managePlugin
	drop_caches
    ;;
kill_bvas_and_update_image)
	kill_start_sh
	kill_pluginDaemon
	kill_bvas_plugin
	drop_caches
    ;;
-h)
	echo "kill aos && bvas && ubus"
	echo "     example: './stop.sh all'"
	echo ""
	echo "kill aos"
	echo "     example: './stop.sh aos'"
	echo ""
	echo "kill bvas"
	echo "     example: './stop.sh bvas'"
	echo ""
	echo "Upgrade firmware kill aos and drop_caches"
	echo "     example: './stop.sh kill_aos_and_update_image'"
	echo ""
	echo "Upgrade firmware kill bvas and drop_caches"
	echo "     example: './stop.sh kill_bvas_and_update_image'"
	;;
?)
	echo "there is unrecognized parameter."
	;;
esac
echo "-------------- end  ./stop.sh --------------"