#!/bin/sh

mknod /dev/usblp0 c 180 0
chmod 777 /dev/usblp0
cd /dev; ln -s /proc/self/fd fd

ps > /tmp/test_cupsd_ps
grep "cupsd" /tmp/test_cupsd_ps
if [ $? -eq "0" ];then
cancel -a
fi
rm /tmp/test_cupsd_ps
killall cupsd
cupsd

uri0=`lpinfo -v`
uri=`echo ${uri0} | sed -n 's/^direct //gp'`

if [ x$uri = 'x' ]; then
	echo "no printer connected"
	exit 1

echo "====="
echo "there are some printers are suppport for this driver:"

lpinfo -m

echo"====="
echo "please input the ppd file name for the connected printer"

read  ppd
ppd=/home/configure/Recorder/$ppd

if [ -f $ppd ];then
lpadmin -p printer -v ${uri} -P ${ppd}
cupsenable printer
cupsaccept printer
	echo "add printer success"
else
	echo "no that ppd file"
	echo "add printer failure"
fi
exit 0
