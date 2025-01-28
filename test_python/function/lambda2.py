#!/usr/bin/env python3

def map_list(fn, l):
	result = []
	for item in l:
		i = fn(item)
		result.append(i)
	return result
	
l = [1, 2, 3, 4]

#def f(x):
#	return x * 2
#
#l = map_list(f, l)

#l = map_list(lambda x : x ** 2, l)

#l = map_list(lambda x : str(x), l)

l = map_list(str, l)
print(l)