#!/usr/bin/env python3

# 前面加上俩个下划线就是私有成员变量

class Woman:
	def __init__(self, name):
		self.__name = name
		self.__age = 18
	def __secret(self):
		#对象的方法内部可以正常访问
		print("%s %d" % (self.__name, self.__age))

w1 = Woman("小芳")

# 'Woman' object has no attribute '__age'，私有属性在外面不能被直接访问
#print(w1.__age)

#私有方法在外面不能被直接访问
w1.__secret();

#w1._Woman__secret();