#!/usr/bin/env python3

l = list(range(101)) #将元组强制转化成列表

#range(101) 0 - 100

print(l)

for item in l:
	print(item)
	
	
l2 = [1,2,3,4,5]
for item in l2:
	item += 2
	print(item * 2)

print(l2)

for item in (1,2,3,4,5): #元组
	item += 2
	print(item)

for item in "Python":
	print(item)
	
for item in range(5):
	print(item)