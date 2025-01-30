#!/usr/bin/env python3

# 一次只能播放一首音乐

class MusicPlayer(object):
	instance = None
	init_flag = False
	def __new__(cls, *args, ** kwargs):
		if cls.instance is None:
			cls.instance = super().__new__(cls)
		return cls.instance
	
	def __init__(self):
		#初始化动作只做一次
		if MusicPlayer.init_flag is False:
			MusicPlayer.init_flag = True
			print("初始化播放器")
		else:
			return

		
		
m1 = MusicPlayer()
print(m1)
m2 = MusicPlayer()
print(m2)