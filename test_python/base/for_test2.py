#!/usr/bin/env python3

# 100以内的质数

l = []
for i in range(2, 100):
	is_prime = True
	for j in range(2, i):
#		print(f"i = {i} j= {j}")
		if 0 == i % j:
			is_prime = False
	if is_prime:
		l.append(i)
		
print(f"l = {l}")