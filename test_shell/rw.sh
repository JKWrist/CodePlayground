while :
do
	set +x
    echo "11112222" > /tmp/1.txt /dev/null
    
    if [ "$?" = "0" ];then
		echo "write ok" >/tmp/res.txt
		cat /tmp/1.txt > /dev/null
        if [ "$?" = "0" ];then
			echo "read ok" >/tmp/res.txt
		else
			echo "read error" >/tmp/res.txt
			break
		fi
    else
		echo "write error" >/tmp/res.txt
        break
    fi
	rm /tmp/1.txt
	sleep 1
done