#!/usr/bin/env python3

# 可变关键词参数, kwargs 需要在最后一个位置

def f(**kwargs):
#	print(kwargs)
	for k, v in kwargs.items():
		print(k, v)

f(a=1, b =2, c=3)


#=====================================
def f1(a, b, c, *args, d, **kwargs):
#	print(kwargs)
	print(a, b, c, d)
	print(args)
	for k, v in kwargs.items():
		print(k, v)
		
f1(7, 8, 9, 4,5,6, d = 78, j=7, q = 'hi', k='hello')
