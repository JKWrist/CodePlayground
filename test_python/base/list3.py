#!/usr/bin/env python3

#列表推导式

l1 = [1, 2, 3, 4, 5]

# [表达式 for 变量 in 列表]
l2 = [i*2 for i in l1]
print(l2)

l0 = []
for i in l1:
	l0.append(i*2)
print(l0)

# [表达式 for 变量 in 列表 if 筛选条件]
l3 = [i//2 for i in range(5) if 0 == i % 2]
print(l3)