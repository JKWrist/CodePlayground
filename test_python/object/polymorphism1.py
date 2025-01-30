#!/usr/bin/env python3

# 多态最重要的就是重写父类的方法

class Dog(object):
	def __init__(self, name):
		self.name = name
	def game(self):
		print("%s 去玩飞盘" % self.name)

class GodDog(Dog):
	def game(self):
		print("%s 去表演" % self.name)
		
class Person(object):
	def __init__(self, name):
		self.name = name
	def paly_with_dog(self, dog):
		print("%s 在和 %s 玩耍" % (self.name, dog.name))
		dog.game()

# 创建出来的对象叫做类的实例
# 创建对象的工作叫做实例化
# 对象的属性叫做实例属性
# 对象调用的方法叫做实例方法

p1 = Person("小明")
d1 = Dog("小白")
d2 = GodDog("神犬")

p1.paly_with_dog(d2)