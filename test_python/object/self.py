#!/usr/bin/env python3

class Person:
	def run(self, speed):
		print("%s" % speed, self.name)
	def eat(self, food):
		print(food)
	def drink(self, what):
		print(what)
		
		
p1 = Person()
p1.name = "Xiaobai"
p1.run(20)
print(dir(p1))