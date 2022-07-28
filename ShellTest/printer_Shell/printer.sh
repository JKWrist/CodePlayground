#!/bin/sh

if [ $# = 0 ]; then
	echo "usage: printer  file.ps"
	exit 0
fi

pdfname=`echo $1 | grep "\.pdf"`
rm -f /home/printer/var/spool/cups/* &>/dev/null

if [ x$pdfname = 'x' ]; then
lp -d printer -o media=a4 -o orientation-requested=3 $1
exit 0
fi

psname=`echo $1 | sed -n 's/pdf/ps/gp'`

if [ -f $psname ]; then
lp -d printer $psname -o media=a4 -o orientation-requested=3
exit 0
fi

pdftops -paper A4 $pdfname $psname
lpr -P printer $psname -o media=a4 -o orientation-requested=3 -r
rm $pdfname

while  [ 1 ];do
lpstat -p | grep "idle"
if [ $? -eq 0 ];then
exit 0
else
sleep 1
fi
done