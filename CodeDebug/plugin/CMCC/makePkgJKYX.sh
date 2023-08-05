#!/bin/bash

#删除之前的包
ls|grep -E "cmhy-JKYX_*"|xargs rm
#压缩前大小
var1=$(du -b -s |awk -F " " '{print $1}')

#初次打包
tar -zPcf "cmhy.tar.gz" ./bvas ./accctrlPkginfo.list --exclude=makePkgJKYX.sh
#压缩包大小
var2=$(du -b -s ./cmhy.tar.gz |awk -F " " '{print $1}')
#压缩比
var3=$(echo "scale=1;$var1 / $var2" | bc)

echo $var1 $var2 $var3

#输入版本号 等待30秒
read -t 30 -p "请输入版本号:" version
if  [ ! -n "$version" ] ;then
    echo "未输入!"
    exit
else
    echo "您输入的版本号为: $version"
fi
#当前时间 对应的秒时间戳
current=`date "+%Y-%m-%d %H:%M:%S"`
timeStamp=`date -d "$current" +%s`
#将current转换为时间戳，精确到秒
time=$(((timeStamp*1000+10#`date "+%N"`/1000000)/1000))
#文件名
name="cmhy-JKYX_"$version"_"$var3".tar.gz"
#读取旧数据
oname=$(cat accctrlPkginfo.list |grep pkgname |awk -F "=" '{print $2}')
otime=$(cat accctrlPkginfo.list |grep timestamp |awk -F "=" '{print $2}')
oversion=$(cat accctrlPkginfo.list |grep version |awk -F "=" '{print $2}')
#替换
sed -i "s/$oname/$name/" accctrlPkginfo.list
sed -i "s/$otime/$time/" accctrlPkginfo.list
sed -i "s/$oversion/$version/" accctrlPkginfo.list
#删除临时包重新打包
rm -f cmhy.tar.gz
tar -zPcvf $name ./bvas ./accctrlPkginfo.list  --exclude=makePkgJKYX.sh
#输出
echo "打包时间: $current"
echo "版本号: $version 压缩比: $var3 "