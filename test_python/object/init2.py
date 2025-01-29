#!/usr/bin/env python3


class Cat:
	def __init__(self, new_name):
		print("这是一个初始化方法")
		self.name = new_name
		self.age  = 1
		
c1 = Cat("c1")
print(c1.name)

c2 = Cat("c2")
print(c2.name)

