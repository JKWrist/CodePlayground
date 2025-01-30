#!/usr/bin/env python3

class MusicPlayer(object):
	
	#重写 new方法
	def __new__(cls, *args, **kwargs):
		# 1 创建对象时， new方法会被自动调用
		print("创建对象 分配空间")
		
		# 2 为对象分配空间
		print(dir(super()))
		instance = super().__new__(cls)
		
		# 3 返回对象的引用
		return instance

	def __init__(self):
		print("播放器初始化")
		
m1 = MusicPlayer()
print(m1)