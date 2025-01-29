#!/usr/bin/env python3

# 方法重写

class Animal:
	def eat(self):
		print("吃---")
		
	def drink(self):
		print("喝---")
		
	def run(self):
		print("跑---")
		
	def sleep(self):
		print("睡---")
		
class Dog(Animal):
	def bark(self):
		print("汪汪叫")
		
d1 = Dog()
d1.eat()
d1.bark()

# 狗类是 动物类的子类， 动物类是狗类的父类， 狗类继承于动物类

# 狗类是 动物类的派生类， 动物类是狗类的基类， 狗类从动物类派生

# 基类和父类相同
# 派生和继承一样

class XiaoTianQuan(Dog):
	def fly(self):
		print("fly")
	def bark(self):
		print("神犬叫")

x1 = XiaoTianQuan()
x1.eat()
x1.bark()
x1.fly()