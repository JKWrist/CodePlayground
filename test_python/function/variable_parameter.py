#!/usr/bin/env python3

def get_sum(*args):
	print(args)
	sum = 0
	for i in args:
		sum += i
		return sum
sum = get_sum(1,2,True,"asdas",5,6)
print(sum)


def f1(a, b, *args):
	print(a)
	print(b)
	print(args)
	
f1(1, 2, True, 5,6)


def f2(a, b, *args, c, d):
	print(a)
	print(b)
	print(args)
	print(c)
	print(d)
f2(1, 2, True, c = 5, d = 6)
