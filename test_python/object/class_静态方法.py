#!/usr/bin/env python3

class Dog(object):
	# 不访问实例属性，也不访问类属性
	@staticmethod
	def run():
		print("小狗要跑")
	
d1 = Dog()
Dog.run()

print(dir(d1))