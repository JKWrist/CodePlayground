#!/bin/sh

single_progress()
{
    interval=2
    progress=smartdns

    pid=`ps |grep ${progress} |grep -v grep | awk '{print $1}'`
    echo $pid

    while true
    do
        DATE=`date '+%Y-%m-%d-%H:%M:%S'`
        echo $DATE >> /tmp/proc_memlog.txt
        cat /proc/$pid/status|grep -e VmRSS  >> /tmp/proc_memlog.txt
        cat /proc/$pid/status|grep -e VmSize  >> /tmp/proc_memlog.txt
        echo $blank >> /tmp/proc_memlog.txt
        sleep $interval
    done
}

sort_vmrss()
{
    sort_file=./tmp_mem.txt
    rm -f $sort_file
    # 获取所有进程的PID
    pids=$(ls /proc | grep -E "^[0-9]+$")

    # 遍历所有进程，获取其VmRSS大小并排序
    for pid in $pids; do
        if [ -f "/proc/$pid/status" ]; then
            # 从status文件中提取VmRSS大小
            vmrss=$(grep -i "VmRSS:" "/proc/$pid/status" | awk '{print $2}')
            p_name=$(grep -i "Name:" "/proc/$pid/status" | awk '{print $2}')
            if [ ! -z "$vmrss" ]; then
                # 将PID和VmRSS大小存入数组
                # arr[$pid]=$vmrss
                echo $vmrss $p_name >> $sort_file
            fi
        fi
    done

    # # 对数组按照VmRSS大小进行排序
    # sorted=$(for pid in "${!arr[@]}"; do echo "$pid ${arr[$pid]}"; done | sort -k2rn)

    # # 输出排序结果
    # echo "PID      VmRSS"
    # echo "$sorted"
    sort -n $sort_file
}

sort_vmrss