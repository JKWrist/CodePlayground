#!/usr/bin/env python3

def f(name, age=0):
	print(f"name = {name} age = {age}")

f("xiaoming", 18)
f("xiaohong", 12)
f("xiaobai")

def f1(a, b=0, c=3):
	print(a, b, c)

f1(1, 2, 3)

f1(1, 6)

f1(a=1, c=66, b=8)

#关键词参数
#f1(4, c=66, 8)
f1(4, c=66, b=8)