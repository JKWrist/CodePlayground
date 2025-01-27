#!/usr/bin/env python3

# 元组在函数中会作为函数返回值来使用

def func(a, b):
	return a, b, a+b, a-b, a*b #返回的是元组类型

print(func(1,2))