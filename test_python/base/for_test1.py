#!/usr/bin/env python3

#100 -1000 的水仙花数

for i in range(100,1000):
	a = i//100
	b = i // 10 % 10
	c = i % 10
	if i == a**3 + b**3 + c**3:
		print(i)
#		break