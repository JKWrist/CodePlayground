#!/usr/bin/env python3

class A:
	def __init__(self):
		self.__num1 = 1
		self.num2   = 2 # 此处要写前面的 self
	def __test(self):
		print("父类私有方法__num1 : %d num2 : %d" % (self.__num1, self.num2))
	def test(self):
		print("父类公有方法")
		self.__test();

class B(A):
	def demo(self):
		print("子类方法")
		self.test()

b1 = B()
b1.demo()
#b1.func()
		