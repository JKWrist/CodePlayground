#!/bin/sh
#
lineNumTmp="/var/config/lineNumTmp"
SWAP_TARGET_FILE="/var/config/config_hs.xml"
SWAP_TEMP_FILE="/var/config/config_hs_temp.xml"
SWAP_HS_DONE="/tmp/syc_flash_hs_done.txt"

show_usage(){
	echo "$0 Usage:"
	echo "  -Turn <hs/cs> xmlfile    Change xmlfile format"
	echo "	-Swap wlan hs"	 	 Swap wlan hs mib
}

deleteFirstDirStr(){
i=1
dir_num=0
cat $1 | while read line
do
        dirStr_tmp=`echo "${line}" | grep "<\/Dir>"`

        if [ "$dirStr_tmp" == "</Dir>" ];then
                echo $i > $lineNumTmp
                break
        fi
        i=$(( $i+1 ))
done

if [ -f $lineNumTmp ];then
        dir_num=`cat $lineNumTmp`
        rm -f $lineNumTmp

        sed -i "${dir_num}d" $1
fi
}
replaceIpv6Addr(){
ipv6AddrStr="<Value Name=\"IPV6_LAN_IP_ADDR\" Value="
replaceStr="<Value Name=\"IPV6_LAN_IP_ADDR\" Value=\"fe80::1\"\/>"
ipv6AddrStr_tmp=""
wholeStr=""
exist_flag=0
i=1
cat $1 | while read line
do
	ipv6AddrStr_tmp=`echo "${line}" | grep "$ipv6AddrStr"`

	if [  "$ipv6AddrStr_tmp" ];then
		echo $i > $lineNumTmp
		break
	fi
        i=$(( $i+1 ))
done
if [ -f $lineNumTmp ];then
	line_num=`cat $lineNumTmp`
	rm -f $lineNumTmp

	cd /var/config
	sed -i "${line_num}c  $replaceStr" ab $1
	cd - > /dev/null	
fi
}
recover_hs_xml_conf(){

        RCVR_FILE=$1

        if [ ! -f $RCVR_FILE ];then
                echo "$RCVR_FILE file is not exist!"
                exit 0
        fi
#Change Config Header
        sed -i 's/<Config Name=\"ROOT\">/<Config_Information_File_HS>/g' $RCVR_FILE
        sed -i 's/<\/Config>/<\/Config_Information_File_HS>/g' $RCVR_FILE
#Delete Dir
        sed -i '/<Dir Name=\"HW_MIB_TABLE\">/d' $RCVR_FILE
        sed -i '/<\/Dir>/d' $RCVR_FILE
}
recover_cs_xml_conf(){

        RCVR_FILE=$1

        if [ ! -f $RCVR_FILE ];then
                echo "$RCVR_FILE file is not exist!"
                exit 0
        fi
#Change Config Header
        sed -i 's/<Config Name=\"ROOT\">/<Config_Information_File_8671>/g' $RCVR_FILE
        sed -i 's/<\/Config>/<\/Config_Information_File_8671>/g' $RCVR_FILE
#Delete First Dir
        sed -i '/<Dir Name=\"MIB_TABLE\">/d' $RCVR_FILE
#       sed -i '/<\/Dir>/d' $RCVR_FILE
        deleteFirstDirStr $RCVR_FILE
#Change Dir -> ChainName
        sed -i 's/Dir Name/chain chainName/g' $RCVR_FILE
        sed -i 's/<\/Dir>/<\/chain>/g' $RCVR_FILE
#replace ipv6addr
	replaceIpv6Addr $RCVR_FILE
}

swap_wlan_hs(){
	if [ ! -f $SWAP_TARGET_FILE ];then
		echo "$SWAP_TARGET_FILE is not exist!"
		exit 0
	fi

	if [ ! -f $SWAP_TEMP_FILE ];then
		touch $SWAP_TEMP_FILE
	fi	
#copy TARGET_FILE to TEMP_FILE
	cp -f $SWAP_TARGET_FILE $SWAP_TEMP_FILE
#Swap wlan mib in TEMP_FILE
	sed -i 's/_WLAN0_/_WLAN0-BAK_/g' $SWAP_TEMP_FILE
	sed -i 's/_WLAN1_/_WLAN0_/g' $SWAP_TEMP_FILE
	sed -i 's/_WLAN0-BAK_/_WLAN1_/g' $SWAP_TEMP_FILE
#check TEMP_FILE
	[ -f ${SWAP_TEMP_FILE} ] && /bin/flash xmlchk  $SWAP_TEMP_FILE
#save new setting to flash
	if [ "$?" = "0" ]; then
		cp -f $SWAP_TEMP_FILE $SWAP_TARGET_FILE
	else
		echo "check $SWAP_TEMP_FILE error"
		exit 0
	fi
#remove TEMP_FILE
	[ -f ${SWAP_TEMP_FILE} ] && rm ${SWAP_TEMP_FILE}
	echo "Swap wlan hs success, do reboot !"
#touch SWAP_HS_DONE
	touch $SWAP_HS_DONE
#exit
	exit 1
}

case "$1" in
  "-Turn")
        if [ $# -ne 3 ];then
                echo "---Cmd format error---"
                show_usage
                exit 0
        fi
        if [ "$2" == "hs" ];then
                recover_hs_xml_conf $3
        elif [ "$2" == "cs" ];then
                recover_cs_xml_conf $3
        fi
        exit 0
        ;;

  "-Swap")
	if [ $# -ne 3 ]; then 
		echo "---Cmd format error---"
		show_usage
		exit 0
	fi
	if [ $3 == "hs"  ];then
		swap_wlan_hs
	fi
	exit 0
	;;

  *)
        show_usage
        exit 1
        ;;
esac
