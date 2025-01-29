#!/usr/bin/env python3

class Person:
	def run(self, speed):
		print(speed)
	def eat(self, food):
		print(food)
	def drink(self, what):
		print(what)
		

p1 = Person()
p1.run(20)

print(p1)
print("%x" % id(p1))

p2 = Person()
p2.run(40)
print(p2)
print("%x" % id(p2))

# 引用的概念
p3 = p2
print("%x" % id(p3))