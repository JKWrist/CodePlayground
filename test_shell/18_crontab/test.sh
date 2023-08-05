#!/bin/bash
#获取当前路径
curPath=$(cd `dirname $0`;pwd)
date >> "$curPath/date.txt"
