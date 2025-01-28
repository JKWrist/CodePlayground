#!/usr/bin/env python3

def func1(i):
	if i <= 1:
		return 1
	else:
		return func1(i-1) * i

#print(func1(1000))
#print(func1(100))

def func2(num):
	result = 1
	for i in range(1, num+1):
		result *= i
	return result
	
print(func2(3))