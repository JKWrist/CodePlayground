#
# cat test.sh
#!/bin/sh
# Mount UBIFS Partition
# ex,
# /bin/sh /etc/scripts/mount_ubifs.sh 1 apps /opt/upt/apps


if [ $# != 3 ]; then
        echo "mount_UBIFS.sh can't Start."
        echo "Ex,\n /bin/sh /etc/scripts/mount_ubifs.sh apps apps /opt/upt/apps"
        echo "mount_ubifs.sh <MTD_NAME> <UBI_VOLUME_NAME> <Mount point>"
    exit 1
fi

MTD_NAME=$1
UBI_NAME=$2
UBI_MOUNT_DIR=$3
UBI_COMPR=zlib
RETRY_CNT=3

MTD_NUM=-1

do_getNewUBINum(){
ubinum=`ubinfo | grep "Count of UBI devices" | awk -F: '{print $2}' | sed 's/^[ \t]*//'`
echo "do_getNewUBINum: ubinum = $ubinum"
if [ $ubinum -eq 0 ];then
NewUBINUM=0
else
NewUBINUM=${ubinum}
fi
echo "New UBI_DEV_NUM: $NewUBINUM "
}


do_getMTDNum(){
MTD_Device=`cat /proc/mtd | grep "\"$MTD_NAME\"" | awk -F: '{print $1}'`
echo "$MTD_Device"
if [ "$MTD_Device" == "" ] ; then
  echo "Not found MTD $MTD_NAME!"
  exit 1;
fi
MTD_NUM=`echo ${MTD_Device}|awk -F"mtd" '{ print $2}'`
echo "Using mtd${MTD_NUM} to mount UBI_Volume ${UBI_NAME}"
}

do_retry_mount(){
counter=0
while [ $counter -lt ${RETRY_CNT} ]; do
        mount -t ubifs ubi${NewUBINUM}:${UBI_NAME} ${UBI_MOUNT_DIR} -o sync -o compr=${UBI_COMPR}
        if [ $? -eq 0 ] ;then
        break
        fi
        let counter=counter+1
done

}

do_getMTDNum

do_getNewUBINum


# Attach mtd to UBI - UBI will detect that the MTD device is
# empty and automatically format it. This command will also crede
if [ -e /dev/mtd${MTD_NUM} ]; then
ubiattach /dev/ubi_ctrl -m ${MTD_NUM}
sleep 1
else
  echo "ubiattach failed! Maybe /dev/mtd${MTD_NUM} not found!"
  echo "UBIFS: Give up UBI_Vol_NAME ${UBI_NAME}, Device: /dev/ubi${MTD_NUM}...... "
  exit 1
fi

if [ ! -e /dev/ubi${NewUBINUM} ]; then
  echo "Not generate /dev/ubi${NewUBINUM}! ubiattach failed..."
  echo "Please flash_eraseall /dev/mtd${MTD_NUM} and try again!"
  echo "Caution: This action will erase the old data on mtd${MTD_NUM}...."
  exit 1
fi

if [ ! -d ${UBI_MOUNT_DIR} ]; then
      mkdir -p ${UBI_MOUNT_DIR}
fi


do_retry_mount

if [ $counter -ge ${RETRY_CNT} ] ;then
      echo "UBIFS: Mount Volume \"${UBI_NAME}\" Failed!"
      echo -n "Creating UBI Volume [${UBI_NAME}]"
      ubimkvol -m  /dev/ubi${NewUBINUM} -N ${UBI_NAME}
	  if [ $? -gt 0 ]; then
	   echo "ubimkvol failed...."
	   exit 1
	  fi 
else
# mount successfully
  exit 0
fi


do_retry_mount


if [ $counter -ge ${RETRY_CNT} ] ;then
      echo "UBIFS: Mount Volume \"${UBI_NAME}\" Failed, again!!!!"
      echo "UBIFS: Give up UBI_Vol_NAME ${UBI_NAME}, Device: /dev/ubi${NewUBINUM}...... "
fi

