#!/usr/bin/env python3

a, b ,c = 1, 2, 3

a, b ,c = (4, 5, 6)

def f():
	return 7,8,9

print(a, b, c)
print(f(), type(f()))