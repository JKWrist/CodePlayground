#!/usr/bin/env python3

import datetime

def timer(t, start, end):
	t_start = datetime.datetime.now()
	print(t_start)
	if start:
		start()
		while True:
			t_end = datetime.datetime.now()
			delta_t = (t_end - t_start).seconds
			if delta_t > t :
				break
	if end:
		end()

def start():
	print("稍等两秒钟")

def end():
	input("请输入数字")
	
timer(2, start, end)
	
	