#!/usr/bin/env python3

i = 22

def f():
	"""全局 global变量， 在函数内的使用"""
	global i
	i = 3

f()

print(f.__name__)
print(f.__doc__)
print(i)

