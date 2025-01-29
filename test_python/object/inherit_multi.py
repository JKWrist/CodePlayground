#!/usr/bin/env python3

class A:
	def test(self):
		print("test A")
	def demo(self):  #self 必须要写
			print("demo A")

class B:
	def test(self):
		print("test B")
	def demo(self):  #self 必须要写
		print("demo B")

class C(B, A):
	"""多继承，让子类同时有多个父类的属性和方法"""
	pass

# 父类之间存在同名函数的时候应该避免多继承

c1 = C()
c1.demo()
c1.test()

# 确定 C 类方法的调用顺序
print(C.__mro__)
print(dir(c1))