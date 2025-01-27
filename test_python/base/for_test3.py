#!/usr/bin/env python3

# 99乘法表

#print("hello", "word", "8", 9, sep = "-", end = "")
#print("hello", "word", "8", 9, sep = "-")
#print("hello", "word", "8", 9, sep = "-")

for i in range(1,10):
	for j in range(1,10):
		print(f"{i} * {j} = {i * j:2d} ", end = "  ")
	print("")
	