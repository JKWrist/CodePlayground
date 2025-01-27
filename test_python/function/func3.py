#!/usr/bin/env python3

def get_max(a:int, b:int):
#	v = a
#	if a < b:
#		v = b
	
	#表达式 if 条件 else 表达式2
	v = b if b > a else a
	return v

print(get_max(6,7))