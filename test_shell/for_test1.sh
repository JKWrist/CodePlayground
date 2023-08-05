#!/bin/bash

# for i in “file1” “file2” “file3”
# for i in /boot/*
# for i in /etc/*.conf
# for i in $(seq -w 10) --》等宽的01-10
# for i in {1…10}
# for i in $( ls )
# for I in $(< file)
# for i in “$@” --》取所有位置参数，可简写为for i
# 注意 : bash shell支持C式for循环

func1()
{
	j=$1
	for ((i=1; i<=j; i++)); do
		echo $i
	done
}

#产生十个随机数
func2()
{
	for i in {0..9}; do
		echo $RANDOM
	done
}

func3()
{
	for i in $(seq 10); do
		echo $RANDOM
	done
}

# 倒数五秒 : 
func4()
{
	for i in $(seq 5 -1 1); do
		echo -e "$i";sleep 1;
	done
}


# func2
# func3
func4