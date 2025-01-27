#!/usr/bin/env python3


l2 = []
#找出 100 以内所有 7 的倍数以及包含 7 的数，将他们显示在一个列表中
for i in range(1,101):
	a = i % 10
	b = i // 10
	print(b, a)
	if 0 == i % 7 or 7 == a or 7 == b:
		l2.append(i)

print(f"满足条件的值有{l2}")