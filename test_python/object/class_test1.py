#!/usr/bin/env python3

class Person:
	def __init__(self, _name, _weight):
		self.name = _name
		self.weight = _weight
	def __str__(self):
		return "%s的体重是 %.2f" % (self.name, self.weight)
	def run(self):
		print("开跑")
		self.weight -= 0.5
	def eat(self):
		print("开吃")
		self.weight += 1

p1 = Person("小明", 80)
print(p1)
p1.eat()
print(p1)
p1.run()
print(p1)
p1.run()
print(p1)

p2 = Person("小美", 50)
print(p2)
p2.eat()
print(p2)
p2.run()
print(p2)
p2.run()
print(p2)