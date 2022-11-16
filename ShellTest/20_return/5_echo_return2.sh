#!/bin/bash
Dir=~/.ssh
function display()
{
    files=`ls $Dir`
    echo $files
}
echo `display`
  
function filetype()
{
    echo `file $Dir/$1`  #输出待检测文件的类型
}
  
for file in `display`    #调用display函数，对其返回值做遍历
do
    filetype $file       #检测文件类型并输出
done