#!/usr/bin/env python3

def f1(a, b, c):
	print(a, b, c, sep = '-')
l = [1,2,2]
f1(*l)

def f2(*args):
	print(args, sep = '-')
l2 = [1,2,2,7,8,8,9]
f2(*l2)


def f3(**kargs):
	print(kargs)
l3 = {'a' : 1, 'b' : 2, 'c' : 3}
f3(**l3)