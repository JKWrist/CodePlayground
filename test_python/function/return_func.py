#!/usr/bin/env python3

#闭包， 函数里可以再定义函数

def func(count):
	def fn():
		nonlocal count
		count -= 1
		if count < 0:
			return
		return count
	return fn

a = func(5)
b = func(2)

print("b", b())
print("a", a())
print("a", a())
print("b", b())
print("a", a())
print("b", b())