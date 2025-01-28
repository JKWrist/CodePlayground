#!/usr/bin/env python3

# 使用lambda实现匿名函数
# Python目前对匿名函数支持有限

def f(x):
	return x * 2

a = lambda x: x * 2
print(type(a))


print(a(2))
print(f(2))