#!/usr/bin/env python3

class Cat:
	def __init__(self, new_name):
		self.name = new_name
		print("%s 来了" % self.name)
	def __del__(self):
		print("%s 走了" % self.name)

c1 = Cat("Tom")
print("-" * 50)


